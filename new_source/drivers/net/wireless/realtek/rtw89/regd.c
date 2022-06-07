// SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause
/* Copyright(c) 2019-2020  Realtek Corporation
 */

#include "debug.h"
#include "ps.h"

#define COUNTRY_REGD(_alpha2, _txpwr_regd_2g, _txpwr_regd_5g) \
	{.alpha2 = (_alpha2), \
	 .txpwr_regd[RTW89_BAND_2G] = (_txpwr_regd_2g), \
	 .txpwr_regd[RTW89_BAND_5G] = (_txpwr_regd_5g) \
	}

static const struct rtw89_regulatory rtw89_ww_regd =
	COUNTRY_REGD("00", RTW89_WW, RTW89_WW);

static const struct rtw89_regulatory rtw89_regd_map[] = {
	COUNTRY_REGD("AR", RTW89_MEXICO, RTW89_MEXICO),
	COUNTRY_REGD("BO", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("BR", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("CL", RTW89_CHILE, RTW89_CHILE),
	COUNTRY_REGD("CO", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("CR", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("EC", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("SV", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("GT", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("HN", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("MX", RTW89_MEXICO, RTW89_MEXICO),
	COUNTRY_REGD("NI", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("PA", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("PY", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("PE", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("US", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("UY", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("VE", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("PR", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("DO", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("AT", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("BE", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("CY", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("CZ", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("DK", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("EE", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("FI", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("FR", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("DE", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("GR", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("HU", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("IS", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("IE", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("IT", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("LV", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("LI", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("LT", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("LU", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("MT", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("MC", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("NL", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("NO", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("PL", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("PT", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("SK", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("SI", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("ES", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("SE", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("CH", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("GB", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("AL", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("AZ", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("BH", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("BA", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("BG", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("HR", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("EG", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("GH", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("IQ", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("IL", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("JO", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("KZ", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("KE", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("KW", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("KG", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("LB", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("LS", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("MK", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("MA", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("MZ", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("NA", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("NG", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("OM", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("QA", RTW89_QATAR, RTW89_QATAR),
	COUNTRY_REGD("RO", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("RU", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("SA", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("SN", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("RS", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("ME", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("ZA", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("TR", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("UA", RTW89_UKRAINE, RTW89_UKRAINE),
	COUNTRY_REGD("AE", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("YE", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("ZW", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("BD", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("KH", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("CN", RTW89_CN, RTW89_CN),
	COUNTRY_REGD("HK", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("IN", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("ID", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("KR", RTW89_KCC, RTW89_KCC),
	COUNTRY_REGD("MY", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("PK", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("PH", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("SG", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("LK", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("TW", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("TH", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("VN", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("AU", RTW89_ACMA, RTW89_ACMA),
	COUNTRY_REGD("NZ", RTW89_ACMA, RTW89_ACMA),
	COUNTRY_REGD("PG", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("CA", RTW89_IC, RTW89_IC),
	COUNTRY_REGD("JP", RTW89_MKK, RTW89_MKK),
	COUNTRY_REGD("JM", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("AN", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("TT", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("TN", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("AF", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("DZ", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("AS", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("AD", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("AO", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("AI", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("AQ", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("AG", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("AM", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("AW", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("BS", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("BB", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("BY", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("BZ", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("BJ", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("BM", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("BT", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("BW", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("BV", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("IO", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("VG", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("BN", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("BF", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("MM", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("BI", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("CM", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("CV", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("KY", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("CF", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("TD", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("CX", RTW89_ACMA, RTW89_ACMA),
	COUNTRY_REGD("CC", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("KM", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("CG", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("CD", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("CK", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("CI", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("DJ", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("DM", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("GQ", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("ER", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("ET", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("FK", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("FO", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("FJ", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("GF", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("PF", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("TF", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("GA", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("GM", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("GE", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("GI", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("GL", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("GD", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("GP", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("GU", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("GG", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("GN", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("GW", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("GY", RTW89_NCC, RTW89_NCC),
	COUNTRY_REGD("HT", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("HM", RTW89_ACMA, RTW89_ACMA),
	COUNTRY_REGD("VA", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("IM", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("JE", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("KI", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("LA", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("LR", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("LY", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("MO", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("MG", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("MW", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("MV", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("ML", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("MH", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("MQ", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("MR", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("MU", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("YT", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("FM", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("MD", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("MN", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("MS", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("NR", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("NP", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("NC", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("NE", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("NU", RTW89_ACMA, RTW89_ACMA),
	COUNTRY_REGD("NF", RTW89_ACMA, RTW89_ACMA),
	COUNTRY_REGD("MP", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("PW", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("RE", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("RW", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("SH", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("KN", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("LC", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("MF", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("SX", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("PM", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("VC", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("WS", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("SM", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("ST", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("SC", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("SL", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("SB", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("SO", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("GS", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("SR", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("SJ", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("SZ", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("TJ", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("TZ", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("TG", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("TK", RTW89_ACMA, RTW89_ACMA),
	COUNTRY_REGD("TO", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("TM", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("TC", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("TV", RTW89_ETSI, RTW89_NA),
	COUNTRY_REGD("UG", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("VI", RTW89_FCC, RTW89_FCC),
	COUNTRY_REGD("UZ", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("VU", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("WF", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("EH", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("ZM", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("IR", RTW89_ETSI, RTW89_ETSI),
	COUNTRY_REGD("PS", RTW89_ETSI, RTW89_ETSI),
};

static const struct rtw89_regulatory *rtw89_regd_find_reg_by_name(char *alpha2)
{
	u32 i;

	for (i = 0; i < ARRAY_SIZE(rtw89_regd_map); i++) {
		if (!memcmp(rtw89_regd_map[i].alpha2, alpha2, 2))
			return &rtw89_regd_map[i];
	}

	return &rtw89_ww_regd;
}

static bool rtw89_regd_is_ww(const struct rtw89_regulatory *regd)
{
	return regd == &rtw89_ww_regd;
}

int rtw89_regd_init(struct rtw89_dev *rtwdev,
		    void (*reg_notifier)(struct wiphy *wiphy,
					 struct regulatory_request *request))
{
	const struct rtw89_regulatory *chip_regd;
	struct wiphy *wiphy = rtwdev->hw->wiphy;
	int ret;

	if (!wiphy)
		return -EINVAL;

	chip_regd = rtw89_regd_find_reg_by_name(rtwdev->efuse.country_code);
	if (!rtw89_regd_is_ww(chip_regd)) {
		rtwdev->regd = chip_regd;
		/* Ignore country ie if there is a country domain programmed in chip */
		wiphy->regulatory_flags |= REGULATORY_COUNTRY_IE_IGNORE;
		wiphy->regulatory_flags |= REGULATORY_STRICT_REG;

		ret = regulatory_hint(rtwdev->hw->wiphy, rtwdev->regd->alpha2);
		if (ret)
			rtw89_warn(rtwdev, "failed to hint regulatory:%d\n", ret);

		rtw89_debug(rtwdev, RTW89_DBG_REGD,
			    "efuse country code %c%c, mapping to 2g txregd %d, 5g txregd %d\n",
			    rtwdev->efuse.country_code[0], rtwdev->efuse.country_code[1],
			    rtwdev->regd->txpwr_regd[RTW89_BAND_2G],
			    rtwdev->regd->txpwr_regd[RTW89_BAND_5G]);

		return 0;
	}
	rtw89_debug(rtwdev, RTW89_DBG_REGD,
		    "worldwide roaming chip, follow the setting of stack(%c%c), mapping to 2g txregd %d, 5g txregd %d\n",
		     rtwdev->regd->alpha2[0], rtwdev->regd->alpha2[1],
		     rtwdev->regd->txpwr_regd[RTW89_BAND_2G],
		     rtwdev->regd->txpwr_regd[RTW89_BAND_5G]);

	return 0;
}

static void rtw89_regd_notifier_apply(struct rtw89_dev *rtwdev,
				      struct wiphy *wiphy,
				      struct regulatory_request *request)
{
	rtwdev->regd = rtw89_regd_find_reg_by_name(request->alpha2);
	/* This notification might be set from the system of distros,
	 * and it does not expect the regulatory will be modified by
	 * connecting to an AP (i.e. country ie).
	 */
	if (request->initiator == NL80211_REGDOM_SET_BY_USER &&
	    !rtw89_regd_is_ww(rtwdev->regd))
		wiphy->regulatory_flags |= REGULATORY_COUNTRY_IE_IGNORE;
	else
		wiphy->regulatory_flags &= ~REGULATORY_COUNTRY_IE_IGNORE;
}

void rtw89_regd_notifier(struct wiphy *wiphy, struct regulatory_request *request)
{
	struct ieee80211_hw *hw = wiphy_to_ieee80211_hw(wiphy);
	struct rtw89_dev *rtwdev = hw->priv;

	mutex_lock(&rtwdev->mutex);
	rtw89_leave_ps_mode(rtwdev);

	if (wiphy->regd) {
		rtw89_debug(rtwdev, RTW89_DBG_REGD,
			    "There is a country domain programmed in chip, ignore notifications\n");
		goto exit;
	}
	rtw89_regd_notifier_apply(rtwdev, wiphy, request);
	rtw89_debug(rtwdev, RTW89_DBG_REGD,
		    "get alpha2 %c%c from initiator %d, mapping to 2g txregd %d, 5g txregd %d\n",
		    request->alpha2[0], request->alpha2[1], request->initiator,
		    rtwdev->regd->txpwr_regd[RTW89_BAND_2G],
		    rtwdev->regd->txpwr_regd[RTW89_BAND_5G]);

	rtw89_chip_set_txpwr(rtwdev);

exit:
	mutex_unlock(&rtwdev->mutex);
}
