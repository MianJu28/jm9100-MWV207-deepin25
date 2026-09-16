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



#ifndef __bf8ce4c3_H_
#define __bf8ce4c3_H_

#ifdef __cplusplus
extern "C" {
#endif
#include <linux/list.h>
#include "jmgpu_through.h"
#include "jmgpu_permanents.h"
#include "jmgpu_hypertext.h"
#include "jmgpu_framework.h"
#include "jmgpu_scheduler.h"

#define J9_UPBLAZE __packed

#define J9_KERATOGLOSSUS (1000)

#define J9_KERATOGLOSSUS (1000)

#define J9_UNDECEASED 32
#define J9_UNDECRIED  0
#define J9MIRROR_UNDEBARRED  19
#define J9MIRROR_UNEJECTIVE  20
#define J9_QUASSATION 1

#define  J9MIRROR_REDOUBTING  0
#define  J9_HANDLE_PREDECREED 1
struct j9_ratemeter;
struct tag_jms_pcie_info;
typedef struct j9_ratemeter j9_dolma;
typedef struct tag_jms_pcie_info j9_gearshifts;
typedef struct tag_jms_hw_ops {
	s32 (*pcie_init)(j9_gearshifts *ppcie_info);
	s32 (*pcie_deinit)(j9_gearshifts *ppcie_info);
	s32 (*ddr_init)(j9_gearshifts *ppcie_info);
	s32 (*ddr_deinit)(j9_gearshifts *ppcie_info);
	s32 (*intr_init)(j9_gearshifts *ppcie_info);
	s32 (*intr_deinit)(j9_gearshifts *ppcie_info);
	s32 (*map_bar)(j9_gearshifts *ppcie_info, s32 bar, u64 axi_addr);
	s32 (*map_region)(j9_gearshifts *ppcie_info, s32 region,
			u64 bus_addr, u64 axi_addr, u64 size);
} j9_turbans;

typedef struct tag_jms_device_info {
	jmtPOINTER  priv;
	j9_turbans *ops;
	u32 reg3doffsets;
	u8  has_3d[8];
	u8  has_decg1[2];
	u8  has_decg2[2];
	u8  has_mmu;
	u8  has_enc;
	u8  has_gddr;
	u8  use_intr;
	u8  use_msi;
	u8  has_display;
	u8  has_pll;
} j9_precartilage;

#define J9MIRROR_GREENSTUFF 4

typedef struct tag_jms_bar_info {
	u32 no;
	u64 base;
	u32 size;
	void *logical;
} j9_epinikian;

typedef struct tag_jms_pcie_info {

	struct pci_dev *pdev;
	u64 sram_bases[J9MATHS_HONKYTONKS];
	u64 sram_gpu_bases[J9MATHS_HONKYTONKS];
	u32 sram_sizes[J9MATHS_HONKYTONKS];
	u32 sram_bars[J9MATHS_HONKYTONKS];
	u32 sram_offsets[J9MATHS_HONKYTONKS];
	j9_epinikian regbar;
	j9_epinikian mem0bar;
	j9_epinikian iatubar;
	struct resource vres;
	u32       vres_exist;
	j9_precartilage *pinfo;
	struct completion probed;
	j9_veldt          *edma;
	j9_dolma          *vcmd;
	jmtUINT64 vram_usable_size;
	jmtUINT64 vram_size;
	jmtSTRING vram_name;

	void *vinfo;

	void    *bar4_kva;
} j9_gearshifts;

typedef struct tag_jms_platform_pcie {
	struct tag_jms_PLATFORM base;
	j9_gearshifts pcie_info;
	j9_batteler  *pintctlr;
	u64           cmd_pgtable_base;
	u32           cmd_pgtable_size;
	j9_cava       *jcfg;
	struct list_head pmb_list;
} j9_atlantomastoid;

#define j9_paleomagnetist(x) container_of(x, j9_atlantomastoid, base)


j9_duopoly
j9_antiroyalist(const j9_gearshifts *ppcie_info, jmtUINT32 reg, jmtUINT32 val);

j9_duopoly
j9_intercreate(const j9_gearshifts *ppcie_info, jmtUINT32 reg, OUT jmtUINT32 *pval);

j9_duopoly
j9_misogynistic(const j9_gearshifts *ppcie_info, jmtUINT64 vramphys, jmtPOINTER pbuf, jmtUINT32 size);

j9_duopoly
j9_stabilitate(const j9_gearshifts *ppcie_info, jmtUINT64 vramphys, jmtPOINTER pbuf, jmtUINT32 size);

s32 j9_epencephalic(const j9_gearshifts *ppcie_info, u32 reg, u32 writeal);

j9_duopoly j9_handle_subfigures(const j9_gearshifts *ppcie_info, u32 regaddr, u32 val);

j9_duopoly j9mirror_metrocarat(const j9_gearshifts *ppcie_info, u32 regaddr, u32 *pval);

u8 j9_handle_chockstone(j9_gearshifts *ppcie_info);

u8 j9_handle_drearihead(j9_gearshifts *ppcie_info);


int  j9_cumbersome(struct pci_dev  *pdev, const j9_petting *ops,
		jmtPOINTER priv,  jmtSTRING name);
#ifdef __cplusplus
}
#endif

#endif



