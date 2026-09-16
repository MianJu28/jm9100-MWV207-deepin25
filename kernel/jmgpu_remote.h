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



#ifndef __61f3fdfc_H_
#define __61f3fdfc_H_
#ifdef __FREERTOS__
#include "basetype.h"
#include "dev_common_freertos.h"
#elif defined(__linux__)
#include <linux/types.h>
#include <linux/pci.h>
#include "jmgpu_program.h"
#else

#endif
#include "jmgpu_pipeline.h"
#include "jmgpu_livelock.h"






struct SubsysDesc {
	int slice_index;
	int index;
	long base;
};

struct CoreDesc {
	int slice;
	int subsys;
	enum CoreType core_type;
	int offset;
	int iosize;
	int irq;
	int has_apb;
};


struct subsys_config {
	unsigned long base_addr;
	int irq;
	u32 subsys_type;
	u32 submodule_offset[HW_CORE_MAX];
	u16 submodule_iosize[HW_CORE_MAX];

	volatile u8 *submodule_hwregs[HW_CORE_MAX];
	u32         *submodule_regs_state[HW_CORE_MAX];
	int has_apbfilter[HW_CORE_MAX];
};


#define J9_BLARNEYS      31
#define J9_PIPPEN        29
#define J9_GRAVEDO       28
#define J9_CERVICAL      17
#define J9_GALATINE      26
#define J9_SERRULA       24
#define J9_UNDERPAINTING 20
#define J9_SOUCARS       18
#define J9_RETEAM        23
#define J9_VROOM         26
#define J9_SNODLY        23
#define J9_CACOON        24
#define J9_PRASINE       19
#define J9_EXSERT        22
#define J9_BIPOROUS      16
#define J9_UNPORTLY      31
#define J9_PLUMA         31
#define J9_ERMINES       26
#define J9_REDDER        29

#define J9MIRROR_ANTERETHIC 31
#define J9MIRROR_SEMESTRIAL 30

#define J9_ADEQUATELY    0
#define J9_WARFARING     1
#define J9_OUTRHYMED        2
#define J9_GALEAE        17
#define J9_HAZARDED         3
#define J9_CRULL         28
#define J9_MYSTERIZE     8
#define J9_NONMIGRATORY  12
#define J9_GINNERS       16

#define J9_PRESUBSCRIBER       1
#define J9_HANDLE_MECHITZOTH   (J9_PRESUBSCRIBER * 4)
#define J9_HANDLE__DELIQUESCE       2
#define J9_HANDLE_J9MA_OVERPEOPLE   (J9_PRESUBSCRIBER * 4)

#define J9_HANDLE_OVERKILLED        60
#define J9_HANDLE_J9M_DREARIHEAD    (J9_HANDLE_OVERKILLED * 4)
#define J9_UNINSTRUMENTAL          50
#define J9_HANDLE__MECHITZOTH      (J9_UNINSTRUMENTAL * 4)
#define J9MIRROR_FRITHSTOOL        54
#define J9_HANDLE_J9_AMIDSTREAM    (J9MIRROR_FRITHSTOOL * 4)
#define J9MIRROR_RUMINATING        56
#define J9_HANDLE_J9_TRAVERSALS    (J9MIRROR_RUMINATING * 4)
#define J9_MOSQUITOPROOF           23
#define J9_HANDLE_FOLKSINESS       (J9_MOSQUITOPROOF * 4)
#define J9MIRROR_KARYOLITIC         260
#define J9_HANDLE_J9_UNDERTRIBE     (J9MIRROR_KARYOLITIC * 4)


#define J9_PTERON              0x01
#define J9_FOPDOODLE           0x01
#define J9_SURREPTION          0x20
#define J9MIRROR_CONFICIENT    0x10
#define J9_SHANTIHS            0x100
#define J9_HANDLE_J_FIDUCIALLY 0x10
#define J9_CELIOCYESIS         0x100



#define J9MIRROR_ADJUSTABLY           60
#define J9_HANDLE_J9_HOMOGONIES       (J9MIRROR_ADJUSTABLY * 4)

#define J9_HANDLE_J_UNDEBARRED           100
#define J9_HANDLE_J9MIN_RECLIMBING       (J9_HANDLE_J_UNDEBARRED * 4)


#define J9MIRROR_OVERKILLED        309
#define J9_HANDLE_J9_COMMANDERY    (J9MIRROR_OVERKILLED * 4)


int j9_banderoling(j9_gearshifts *ppcie_info);
void j9_hydrosulphuryl(void);
int j9_pentadactylate(struct inode *inode, struct file *filp);
long j9_gnotobiotics(struct file *filp, unsigned int cmd, unsigned long arg);
int j9_allopathically(j9_gearshifts *ppcie_info);


#endif


