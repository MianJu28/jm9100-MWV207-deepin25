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





#ifndef __0f0d11f9_H_
#define __0f0d11f9_H_

#include "jmgpu_evaluate.h"
#include "jmgpu_livelock.h"


#undef J9OUI_
#ifdef HX280ENC_DEBUG
#ifdef __KERNEL__

#define J9OUI_(fmt, args...) pr_info("hmp4e: " fmt, ##args)
#else

#define J9OUI_(fmt, args...) printf(__FILE__ ":%d: " fmt, __LINE__, ##args)
#endif
#else
#define J9OUI_(fmt, args...)
#endif

#define IRQF_DISABLED 0x00000020

#define J9_EXILING 0x48320100
#define J9_TOUTING 0x80006000
#define J9_HANDLE__CHURNSTAFF 31
#define J9_HANDLE_J9_PREPROMISE 28

#define J9_HANDLE_J9MA_SPASMODIST 0x1000
#define J9_HANDLE_J_ARTFULNESS 0x200
#define J9_HANDLE_J9_DAMFOOLISH 0x100
#define J9_HANDLE_J9MATHS_PARAMEDICS 0x080
#define J9_HANDLE_J_ENRAVISHED 0x040
#define J9_HANDLE__QUASIORDER 0x020
#define J9_HANDLE_SIPHUNCLED 0x010
#define J9_QUINTUPLICATES 0x008
#define J9_HANDLE_J9_EMMENOLOGY 0x004
#define J9_PHYMATOSIS 0x001

#define J9_HANDLE_J9MIN_FORTEMENTE 21

#define J9_DISINTRICATE                                                        \
	(J9_HANDLE_J9MA_SPASMODIST | J9_HANDLE_J_ARTFULNESS |                  \
	 J9_HANDLE_J9_DAMFOOLISH | J9_HANDLE_J9MATHS_PARAMEDICS |              \
	 J9_HANDLE_J_ENRAVISHED | J9_HANDLE__QUASIORDER |                      \
	 J9_HANDLE_SIPHUNCLED | J9_QUINTUPLICATES | J9_HANDLE_J9_EMMENOLOGY)

#if KERNEL_VERSION(2, 6, 18) > LINUX_VERSION_CODE
static irqreturn_t j9_froggery(int irq, void *dev_id, struct pt_regs *regs);
#else
static irqreturn_t j9_froggery(int irq, void *dev_id);
#endif

long j9_pseudography(struct file *filp, unsigned int cmd, unsigned long arg);
int j9_radiostrontium(void);
int j9_railroaders(struct pci_dev *pdev);
int j9_predigesting(dtbnode *pnode, int useirq, int loop,
		    struct j9_aarrgh *penccore, struct pci_dev *pdev,
		    j9_weakliest *pplatform);
void j9_hepatocellular(j9_gearshifts *pcie_info);
u32 *jmgpu_enc_getRegAddr(u32 coreid, u32 regid);
u32 j9_handle_j9_lionizable(int sliceidx, int isreadBW);
int j9_radiostrontium(void);

#endif


