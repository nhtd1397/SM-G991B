/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __KQ_NAD_RESULT_H__
#define __KQ_NAD_RESULT_H__

#define KQ_NAD_RESULT_FORMAT_MAX_LEN	32

/* NAD Result Related Vars */
enum {
	KQ_NAD_PHASE_SMD_FIRST = 0,
	KQ_NAD_PHASE_SMD_SECOND,
	KQ_NAD_PHASE_ACAT_FIRST,
	KQ_NAD_PHASE_ACAT_SECOND,
#if IS_ENABLED(CONFIG_SEC_KQ_NAD_X)
	KQ_NAD_PHASE_EXTEND_FIRST,
	KQ_NAD_PHASE_EXTEND_SECOND,
#endif //IS_ENABLED(CONFIG_SEC_KQ_NAD_X)

	KQ_NAD_PHASE_END,
	KQ_NAD_PHASE_NONE = KQ_NAD_PHASE_END,
};

enum {
	KQ_NAD_RESULT_INFO_NAD_PASS = 0,
	KQ_NAD_RESULT_INFO_NAD_FAIL,

	KQ_NAD_RESULT_INFO_ACAT_PASS,
	KQ_NAD_RESULT_INFO_ACAT_FAIL,

	KQ_NAD_RESULT_INFO_NADX_PASS,
	KQ_NAD_RESULT_INFO_NADX_FAIL,

	KQ_NAD_RESULT_INFO_NAD_INFORM1,
	KQ_NAD_RESULT_INFO_NAD_INFORM2,
	KQ_NAD_RESULT_INFO_NAD_INFORM3,

	KQ_NAD_RESULT_INFO_SNAD_INFORM1,
	KQ_NAD_RESULT_INFO_SNAD_INFORM2,
	KQ_NAD_RESULT_INFO_SNAD_INFORM3,

	KQ_NAD_RESULT_INFO_FNS,
	KQ_NAD_RESULT_INFO_FN,

	KQ_NAD_RESULT_INFO_IT,
	KQ_NAD_RESULT_INFO_MT,
	KQ_NAD_RESULT_INFO_TN,
	KQ_NAD_RESULT_INFO_VER,

#if IS_ENABLED(CONFIG_SEC_KQ_NAD_VDD_CAL)
	KQ_NAD_RESULT_INFO_VDD_CAL0,
	KQ_NAD_RESULT_INFO_VDD_CAL1,
	KQ_NAD_RESULT_INFO_VDD_CAL2,
#endif //IS_ENABLED(CONFIG_SEC_KQ_NAD_VDD_CAL)

#if IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
	KQ_NAD_RESULT_INFO_CORRELATION_CL0,
	KQ_NAD_RESULT_INFO_CORRELATION_CL1,
	KQ_NAD_RESULT_INFO_CORRELATION_CL2,
	KQ_NAD_RESULT_INFO_CORRELATION_MIF,
	KQ_NAD_RESULT_INFO_CORRELATION_DSU,
	KQ_NAD_RESULT_INFO_CORRELATION_CP,
	KQ_NAD_RESULT_INFO_CORRELATION_G3D,
	KQ_NAD_RESULT_INFO_CORRELATION_SCI,
#endif //IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)

	KQ_NAD_RESULT_INFO_END,
};

struct kq_nad_result {
	char format[KQ_NAD_RESULT_FORMAT_MAX_LEN];
	int phase;
	int type;
};

static struct kq_nad_result kq_nad_result_nad_pass[] = {
	{ KQ_NAD_STR_NAD_PASS, KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_NAD_PASS },
	{ "NAD1(0x%x)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM1 },
	{ "NAD2(0x%x)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM2 },
	{ "NAD3(0x%x)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM3 },
	{ "SNAD1(0x%x)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM1 },
	{ "SNAD2(0x%x)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM2 },
	{ "SNAD3(0x%x)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM3 },
#if IS_ENABLED(CONFIG_SEC_KQ_NAD_VDD_CAL)
	{ "VDD0(0x%x)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_VDD_CAL0 },
	{ "VDD1(0x%x)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_VDD_CAL1 },
	{ "VDD2(0x%x)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_VDD_CAL2 },
#endif //IS_ENABLED(CONFIG_SEC_KQ_NAD_VDD_CAL)
#if IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
	{ "CO1(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL0 },
	{ "CO2(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL1 },
	{ "CO3(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL2 },
	{ "CO4(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_MIF },
	{ "CO5(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_DSU },
	{ "CO6(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CP },
	{ "CO7(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_G3D },
	{ "CO8(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_SCI },
#endif //IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
};

static struct kq_nad_result kq_nad_result_nad_fail[] = {
	{ KQ_NAD_STR_NAD_FAIL, KQ_NAD_RESULT_INFO_NAD_FAIL },
	{ "NAD1(0x%x)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM1 },
	{ "NAD2(0x%x)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM2 },
	{ "NAD3(0x%x)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM3 },
	{ "SNAD1(0x%x)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM1 },
	{ "SNAD2(0x%x)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM2 },
	{ "SNAD3(0x%x)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM3 },
	{ "FNS(%s_%s_%d_%s)", KQ_NAD_PHASE_SMD_SECOND, KQ_NAD_RESULT_INFO_FNS },
	{ "FN(%s_%s_%d_%s)", KQ_NAD_PHASE_SMD_FIRST, KQ_NAD_RESULT_INFO_FN },
#if IS_ENABLED(CONFIG_SEC_KQ_NAD_VDD_CAL)
	{ "VDD0(0x%x)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_VDD_CAL0 },
	{ "VDD1(0x%x)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_VDD_CAL1 },
	{ "VDD2(0x%x)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_VDD_CAL2 },
#endif //IS_ENABLED(CONFIG_SEC_KQ_NAD_VDD_CAL)
#if IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
	{ "CO1(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL0 },
	{ "CO2(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL1 },
	{ "CO3(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL2 },
	{ "CO4(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_MIF },
	{ "CO5(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_DSU },
	{ "CO6(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CP },
	{ "CO7(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_G3D },
	{ "CO8(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_SCI },
#endif //IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
};

static struct kq_nad_result kq_nad_result_acat_pass[] = {
	{ KQ_NAD_STR_ACAT_PASS, KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ACAT_PASS },
	{ "NAD1(0x%x)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM1 },
	{ "NAD2(0x%x)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM2 },
	{ "NAD3(0x%x)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM3 },
	{ "SNAD1(0x%x)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM1 },
	{ "SNAD2(0x%x)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM2 },
	{ "SNAD3(0x%x)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM3 },
#if IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
	{ "CO1(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL0 },
	{ "CO2(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL1 },
	{ "CO3(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL2 },
	{ "CO4(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_MIF },
	{ "CO5(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_DSU },
	{ "CO6(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CP },
	{ "CO7(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_G3D },
	{ "CO8(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_SCI },
#endif //IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
};

static struct kq_nad_result kq_nad_result_acat_fail[] = {
	{ KQ_NAD_STR_ACAT_FAIL, KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_ACAT_FAIL },
	{ "NAD1(0x%x)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM1 },
	{ "NAD2(0x%x)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM2 },
	{ "NAD3(0x%x)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM3 },
	{ "SNAD1(0x%x)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM1 },
	{ "SNAD2(0x%x)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM2 },
	{ "SNAD3(0x%x)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM3 },
	{ "FNS(%s_%s_%d_%s)", KQ_NAD_PHASE_ACAT_SECOND, KQ_NAD_RESULT_INFO_FNS },
	{ "FN(%s_%s_%d_%s)", KQ_NAD_PHASE_ACAT_FIRST, KQ_NAD_RESULT_INFO_FN },
#if IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
	{ "CO1(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL0 },
	{ "CO2(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL1 },
	{ "CO3(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL2 },
	{ "CO4(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_MIF },
	{ "CO5(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_DSU },
	{ "CO6(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CP },
	{ "CO7(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_G3D },
	{ "CO8(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_SCI },
#endif //IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
};

#if IS_ENABLED(CONFIG_SEC_KQ_NAD_X)
static struct kq_nad_result kq_nad_result_nadx_pass[] = {
	{ KQ_NAD_STR_NADX_PASS, KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_NADX_PASS },
	{ "NAD1(0x%x)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM1 },
	{ "NAD2(0x%x)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM2 },
	{ "NAD3(0x%x)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM3 },
	{ "SNAD1(0x%x)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM1 },
	{ "SNAD2(0x%x)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM2 },
	{ "SNAD3(0x%x)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM3 },
	{ "IT(%d)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_IT },
	{ "MT(%d)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_MT },
#if IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
	{ "CO1(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL0 },
	{ "CO2(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL1 },
	{ "CO3(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL2 },
	{ "CO4(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_MIF },
	{ "CO5(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_DSU },
	{ "CO6(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CP },
	{ "CO7(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_G3D },
	{ "CO8(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_SCI },
#endif //IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
};

static struct kq_nad_result kq_nad_result_nadx_fail[] = {
	{ KQ_NAD_STR_NADX_FAIL, KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_NADX_FAIL },
	{ "NAD1(0x%x)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM1 },
	{ "NAD2(0x%x)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM2 },
	{ "NAD3(0x%x)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_NAD_INFORM3 },
	{ "SNAD1(0x%x)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM1 },
	{ "SNAD2(0x%x)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM2 },
	{ "SNAD3(0x%x)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_SNAD_INFORM3 },
	{ "FNS(%s_%s_%d_%s)", KQ_NAD_PHASE_EXTEND_SECOND, KQ_NAD_RESULT_INFO_FNS },
	{ "FN(%s_%s_%d_%s)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_FN },
	{ "IT(%d)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_IT },
	{ "MT(%d)", KQ_NAD_PHASE_EXTEND_FIRST, KQ_NAD_RESULT_INFO_MT },
#if IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
	{ "CO1(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL0 },
	{ "CO2(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL1 },
	{ "CO3(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CL2 },
	{ "CO4(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_MIF },
	{ "CO5(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_DSU },
	{ "CO6(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_CP },
	{ "CO7(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_G3D },
	{ "CO8(%s)", KQ_NAD_PHASE_NONE, KQ_NAD_RESULT_INFO_CORRELATION_SCI },
#endif //IS_ENABLED(CONFIG_SEC_KQ_CORRELATION_RESULT)
};
#endif //IS_ENABLED(CONFIG_SEC_KQ_NAD_X)

#endif	//__KQ_NAD_RESULT_H__