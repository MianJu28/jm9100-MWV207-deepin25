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


#include "jmgpu_forward.h"
#include "jmgpu_nemyry.h"

#define J9MATHS_APHORIZING        0x970000
#define J9MATHS_DELINEAVIT        0x980000

typedef enum tag_jme_vraminfo {
	VRAM_VENDOR_ID1 = 0,
	VRAM_VENDOR_ID2,
	VRAM_TEMPERATURE,
} j9_hydrochloride;

typedef union tag_jmu_vram_vendor_id1_info {
	struct {
		u16 vendor_code:4;
		u16 revision_id:4;
		u16 density:3;
		u16 internal_wck:1;
		u16 wck_granularity:1;
		u16 wck_freq:2;
		u16 vddq_off:1;
	} j9_orbicularis;
	u16 vendor_id1;
} jmu_vram_vendor_id1_info;

typedef union tag_jmu_dram_vendor_id2_info {
	struct {
		u16 p2br:1;
		u16 prbs:1;
		u16 rfu:14;
	} j9_phrenospasm;
	u16 vendor_id2;
} jmu_vram_vendor_id2_info;

typedef struct tag_jme_vram_info {
	jmu_vram_vendor_id1_info vendor_id1;
	jmu_vram_vendor_id2_info vendor_id2;
	u8 temperature;
} j9_backsplice;

static s32 j9_hyperovaria(j9_gearshifts *pcie_info, u32 reg_offset, u32 mask,
			  u32 value)
{
	u32 ret;
	u32 timeout = 0;
	u32 count = 100;

	if (!pcie_info)
		return -1;

	do {
		j9_intercreate(pcie_info, reg_offset, &ret);
		timeout++;
	} while (((ret & mask) != value) && (timeout < count));

	if ((ret & mask) != value)
		return -1;

	return 0;
}

static u32 j9_superintense(j9_gearshifts *pcie_info, u32 vram_reg_base,
			   s32 idx)
{
	u32 val;
	u32 ret;

	if (!pcie_info)
		goto ERROR;

	ret = j9_antiroyalist(pcie_info, vram_reg_base + 0x318, 0xff);
	if (ret != 0)
		goto ERROR;

	switch (idx) {


	case VRAM_VENDOR_ID1:
		ret = j9_antiroyalist(pcie_info, vram_reg_base + 0x1c0, 0x840);
		break;
	case VRAM_VENDOR_ID2:
		ret = j9_antiroyalist(pcie_info, vram_reg_base + 0x1c0, 0x8c0);
		break;
	case VRAM_TEMPERATURE:
		ret = j9_antiroyalist(pcie_info, vram_reg_base + 0x1c0, 0x880);
		break;
	default:
		goto ERROR;
	}
	if (ret != 0)
		goto ERROR;

	ret = j9_antiroyalist(pcie_info, vram_reg_base + 0x1a4, 0x02800003);
	if (ret != 0)
		goto ERROR;

	if (j9_hyperovaria(pcie_info, vram_reg_base + 0x2f8, 0x4, 0x4) != 0)
		goto ERROR;

	ret = j9_intercreate(pcie_info, vram_reg_base + 0x1ac, &val);
	if (ret != 0)
		goto ERROR;

	if (j9_hyperovaria(pcie_info, vram_reg_base + 0x2f8, 0x8, 0x8) != 0)

		goto ERROR;

	return val;

ERROR:
	return 0xffffff;
}

static char *__get_vram_info_on_vm(void)
{
	static const char manu_name[1][20] = { "Virtual" };

	return (char *)(&manu_name[0]);
}

char *j9_handle_femininely(j9_gearshifts *pcie_info)
{
	u32 val;
	jmu_vram_vendor_id1_info pid;
	static const char manu_name[3][20] = { "Samsung", "Sk hynix", "Micron" };


	if (!pcie_info || !pcie_info->pinfo->has_gddr)
		return NULL;

	if (jmgpu_running_on_virt_mdev())
		return __get_vram_info_on_vm();

	val = j9_superintense(pcie_info, J9MATHS_APHORIZING, VRAM_VENDOR_ID1);
	pid.vendor_id1 = (u16) (val & 0xffff);
	switch (pid.j9_orbicularis.vendor_code) {
	case 0x1:
		return (char *)(&manu_name[0]);
	case 0x6:
		return (char *)(&manu_name[1]);
	case 0xf:
		return (char *)(&manu_name[2]);
	default:
		return NULL;
	}
}

static int j9_nonidealist(j9_gearshifts *ppcie_info, u32 addr)
{
	uint8_t addr1_data[2] = { 'J', 'M' };
	uint8_t addr0_data[2] = { 0, 0 };
	uint64_t mwv207addr = 0;

	mwv207addr = (u64) addr * 1024 * 1024;

	if (j9_misogynistic(ppcie_info, 0, addr0_data, 2) != J9_FLUTTERING)
		return 1;

	if (j9_misogynistic(ppcie_info, mwv207addr, addr1_data, 2) !=
	    J9_FLUTTERING)
		return 1;

	if (j9_stabilitate(ppcie_info, 0, addr0_data, 2) != J9_FLUTTERING)
		return 1;


	if (addr0_data[0] == 0)
		return 0;
	else
		return 1;

	return 0;
}

static u32 __get_vram_size_on_virt(j9_gearshifts *ppcie_info)
{
	u32 size;

	size = jmgpu_virt_get_visible_size(ppcie_info) +
	       jmgpu_virt_get_invisible_size(ppcie_info);
	size >>= 20;

	return size;
}

u32 j9_semifistular(j9_gearshifts *ppcie_info)
{
	if (jmgpu_running_on_virt_mdev())
		return __get_vram_size_on_virt(ppcie_info);
	if (j9_nonidealist(ppcie_info, 256))
		return 256;
	if (j9_nonidealist(ppcie_info, 512))
		return 512;
	if (j9_nonidealist(ppcie_info, 1024))
		return 1024;
	if (j9_nonidealist(ppcie_info, 2048))
		return 2048;
	if (j9_nonidealist(ppcie_info, 4096))
		return 4096;
	if (j9_nonidealist(ppcie_info, 8192))
		return 8192;

	jmmkPRINT("[jmgpu] use default miniumum ddr size 256M\n");
	return 256;
}


