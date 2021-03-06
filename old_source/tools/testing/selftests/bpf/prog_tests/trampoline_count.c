// SPDX-License-Identifier: GPL-2.0-only
#define _GNU_SOURCE
#include <sched.h>
#include <sys/prctl.h>
#include <test_progs.h>

#define MAX_TRAMP_PROGS 38

struct inst {
	struct bpf_object *obj;
	struct bpf_link   *link_fentry;
	struct bpf_link   *link_fexit;
};

static int test_task_rename(void)
{
	int fd, duration = 0, err;
	char buf[] = "test_overhead";

	fd = open("/proc/self/comm", O_WRONLY|O_TRUNC);
	if (CHECK(fd < 0, "open /proc", "err %d", errno))
		return -1;
	err = write(fd, buf, sizeof(buf));
	if (err < 0) {
		CHECK(err < 0, "task rename", "err %d", errno);
		close(fd);
		return -1;
	}
	close(fd);
	return 0;
}

static struct bpf_link *load(struct bpf_object *obj, const char *name)
{
	struct bpf_program *prog;
	int duration = 0;

	prog = bpf_object__find_program_by_name(obj, name);
	if (CHECK(!prog, "find_probe", "prog '%s' not found\n", name))
		return ERR_PTR(-EINVAL);
	return bpf_program__attach_trace(prog);
}

/* TODO: use different target function to run in concurrent mode */
void serial_test_trampoline_count(void)
{
	const char *fentry_name = "prog1";
	const char *fexit_name = "prog2";
	const char *object = "test_trampoline_count.o";
	struct inst inst[MAX_TRAMP_PROGS] = {};
	int err, i = 0, duration = 0;
	struct bpf_object *obj;
	struct bpf_link *link;
	char comm[16] = {};

	/* attach 'allowed' trampoline programs */
	for (i = 0; i < MAX_TRAMP_PROGS; i++) {
		obj = bpf_object__open_file(object, NULL);
		if (!ASSERT_OK_PTR(obj, "obj_open_file")) {
			obj = NULL;
			goto cleanup;
		}

		err = bpf_object__load(obj);
		if (CHECK(err, "obj_load", "err %d\n", err))
			goto cleanup;
		inst[i].obj = obj;
		obj = NULL;

		if (rand() % 2) {
			link = load(inst[i].obj, fentry_name);
			if (!ASSERT_OK_PTR(link, "attach_prog")) {
				link = NULL;
				goto cleanup;
			}
			inst[i].link_fentry = link;
		} else {
			link = load(inst[i].obj, fexit_name);
			if (!ASSERT_OK_PTR(link, "attach_prog")) {
				link = NULL;
				goto cleanup;
			}
			inst[i].link_fexit = link;
		}
	}

	/* and try 1 extra.. */
	obj = bpf_object__open_file(object, NULL);
	if (!ASSERT_OK_PTR(obj, "obj_open_file")) {
		obj = NULL;
		goto cleanup;
	}

	err = bpf_object__load(obj);
	if (CHECK(err, "obj_load", "err %d\n", err))
		goto cleanup_extra;

	/* ..that needs to fail */
	link = load(obj, fentry_name);
	err = libbpf_get_error(link);
	if (!ASSERT_ERR_PTR(link, "cannot attach over the limit")) {
		bpf_link__destroy(link);
		goto cleanup_extra;
	}

	/* with E2BIG error */
	ASSERT_EQ(err, -E2BIG, "proper error check");
	ASSERT_EQ(link, NULL, "ptr_is_null");

	/* and finaly execute the probe */
	if (CHECK_FAIL(prctl(PR_GET_NAME, comm, 0L, 0L, 0L)))
		goto cleanup_extra;
	CHECK_FAIL(test_task_rename());
	CHECK_FAIL(prctl(PR_SET_NAME, comm, 0L, 0L, 0L));

cleanup_extra:
	bpf_object__close(obj);
cleanup:
	if (i >= MAX_TRAMP_PROGS)
		i = MAX_TRAMP_PROGS - 1;
	for (; i >= 0; i--) {
		bpf_link__destroy(inst[i].link_fentry);
		bpf_link__destroy(inst[i].link_fexit);
		bpf_object__close(inst[i].obj);
	}
}
