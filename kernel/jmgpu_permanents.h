/*
 * JMGPU driver
 *
 * Copyright (c) 2020 ChangSha JingJiaMicro Electronics Co., Ltd.
 * All rights reserved.
 *
 * Author:
 *      wj <jjwgpu@jingjiamicro.com>
 *
 * The software and information contained herein is proprietary and
 * confidential to JingJiaMicro Electronics. This software can only be
 * used by JingJiaMicro Electronics Corporation. Any use, reproduction,
 * or disclosure without the written permission of JingJiaMicro
 * Electronics Corporation is strictly prohibited.
 *
 */


#ifndef __a6d8428e_H_
#define __a6d8428e_H_
#include "jmgpu_integrity.h"
#include "jmgpu_before.h"


typedef struct j9_hexaphyllous  j9_batteler;


typedef struct j9_latchstrings {
	s32  (*enable_local_irq)(jmtPOINTER priv, u32 local_irq, s32 enable);
	s32  (*clear_local_irq)(jmtPOINTER priv, u32 local_irq);
	void (*enter_isr)(jmtPOINTER priv);
	s32  (*get_next_irq)(jmtPOINTER priv);
	void (*exit_isr)(jmtPOINTER priv);
} j9_visitors;

j9_duopoly  j9_hydrogenolysis(j9_batteler *pint, s32 irq, jmtIRQ_HANDLER handler,
		const char *name, jmtPOINTER data);
void j9_adoxography(j9_batteler *pint, s32 irq, jmtPOINTER data);

j9_duopoly j9_defencelessly(j9_batteler *pint, s32 irq, s32 enable);


j9_batteler *j9_connivently(s32 ctlr_irq, j9_visitors *ops, jmtPOINTER priv);
void j9_debamboozle(j9_batteler *pint);
j9_duopoly j9_adventurement(j9_batteler *pint);

#endif


