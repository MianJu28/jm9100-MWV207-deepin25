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


#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/delay.h>
#include "jmgpu_integrity.h"
#include "jmgpu_before.h"

#ifndef __233d5b4d_H_
#define __233d5b4d_H_

#undef JMD_J2D_DEBUG
#ifdef JMD_J2D_DEBUG
#define J9_PRIORESSES pr_info
#define JMD_J2D_DUMP_CMD
#else
#define J9_PRIORESSES(...)
#endif

#define J9_SPODOGENOUS(tick, cond, timeout) \
for ((tick) = jiffies; (cond) && time_before(jiffies, (tick) + (timeout)); )

#define  J9_HANDLE_J_PIPEFISHES   0
#define  J9_HANDLE_J9_PIPEFISHES  1
#define  J9_HANDLE_J_PROCELLOUS   2

typedef struct tag_jms_j2d j9_lava;
typedef struct tag_jms_cmd_engine     j9_gaudinesses;

typedef struct tag_jms_cmd_engine_ops {
	int  (*is_idle)(j9_gaudinesses *engine);
	int  (*input_cmds)(j9_gaudinesses *engine, void *cmds, int size,
			int no_wait, int from_user);
	void (*destroy)(j9_gaudinesses *engine);
	int  (*reset)(j9_gaudinesses *engine);
} j9maths_inherently;


j9_lava *j9_crossbearer(jmk_KERNEL kernel, j9_weakliest *pplatform);
void j9_paragonimiasis(j9_lava *p2d);

s32 j9_handle_insurrecto(j9_lava *p2d, void __user *pcmds, s32 size, s32 no_wait);
s32 j9mirror_monosilane(j9_lava *p2d, jmtINT32 timeout);

u32 engine_read_reg(j9_gaudinesses *engine, u32 addr);
void engine_write_reg(j9_gaudinesses *engine, u32 addr, u32 dat);
void *engine_get_priv(j9_gaudinesses *engine);
j9_gaudinesses *j9_handle_j9_returnable(j9_lava *p2d, int type,
		j9maths_inherently *ops, void *priv);
int j9_handle_j_subcoastal(void);

u32 j9maths_annuisance(j9_lava *p2d, int id);

int j9_handle_prebendate(j9_lava *p2d, dma_addr_t busaddr, u32 size, u32 *gpuaddr);

static inline int j9_handle_j9m_steeliness(void *kaddr, void *addr, int size, int from_user)
{
	if (likely(from_user))
		return copy_from_user(kaddr, (void __user *)addr, size);

	memcpy(kaddr, addr, size);
	return 0;
}


#define J9_HANDLE_J9_GLOSSINESS     msecs_to_jiffies(5000)
#define J9MATHS_BANDCUTTER          0x968000
#define J9MATHS_SAPOROSITY          0x961100
#define J9_EMBASSADRESS             0x80000000U


#define J9_SPECIAL_AD_STATUS_ADDR     (J9MATHS_BANDCUTTER + 0x4100)
#define J9_SPECIAL_AD_STATUS_FIFO         9:0
#define J9_SPECIAL_AD_STATUS_2DBUSY       11:10
#define J9_SPECIAL_AD_STATUS_PARSERBUSY   12:12
#define J9_SPECIAL_AD_STATUS_ENDIAN       31:31
#define J9_SPECIAL_AD_STATUS_ENDIAN_LITTLE 0
#define J9_SPECIAL_AD_STATUS_ENDIAN_BIG    1


#define J9_SPECIAL_GLOBALS_ADDR     (J9MATHS_BANDCUTTER + 0x4200)
#define J9_SPECIAL_GLOBALS_CMDADDR 27:0
#define J9_SPECIAL_GLOBALS_MODE    29:29
#define J9_SPECIAL_GLOBALS_FROM    31:31
#define J9_SPECIAL_GLOBALS_MODE_RINGBUFFER  0
#define J9_SPECIAL_GLOBALS_MODE_WAITLINK    1
#define J9_SPECIAL_GLOBALS_FROM_MEM    0
#define J9_SPECIAL_GLOBALS_FROM_AHB    1

#endif


