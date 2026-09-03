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




#include <linux/delay.h>
#include "jmgpu_livelock.h"
#include "mwv207_update.h"
#include "mwv207_boolean.h"

#define j9_bryaceous(ppcie_info) ((j9_anthomyiid *)(ppcie_info)->pinfo->priv)

typedef struct j9_sulphocarbonic {
	j9maths_ingeminate *pmwv207_intctlr;
} j9_anthomyiid;

static s32 j9_handle__obituarize(j9_gearshifts *ppcie_info)
{
	j9_anthomyiid *pfpga;
	s32 ret;



	j9_antiroyalist(ppcie_info, 0x9B001C, 0xFFFFF);
	j9_antiroyalist(ppcie_info, 0x9B0020, 0xFFFFF);
	j9_antiroyalist(ppcie_info, 0x9B0024, 0xFFFFF);


	mdelay(10);


	ret = j9_epencephalic(ppcie_info, 0x990438, 0x789000);
	if (ret)
		return -EIO;

	pfpga = kzalloc(sizeof(*pfpga), GFP_KERNEL);
	if (!pfpga)
		return -1;

	ppcie_info->pinfo->priv = pfpga;

	return 0;
}

static s32 j9_handle_j9_commencing(j9_gearshifts *ppcie_info)
{
	if (ppcie_info->pinfo)
		kfree(ppcie_info->pinfo->priv);
	return 0;
}


static s32 j9_handle__outwriggle(j9_gearshifts *ppcie_info)
{
	j9_anthomyiid *pfpga = j9_bryaceous(ppcie_info);
	j9_atlantomastoid *pplatform =
		container_of(ppcie_info, j9_atlantomastoid, pcie_info);
	j9maths_ingeminate *pmwv207_intctlr;

	pmwv207_intctlr = j9mirror_promissive(ppcie_info,
					      ppcie_info->pdev->irq);
	if (!pmwv207_intctlr)
		return -1;

	pfpga->pmwv207_intctlr = pmwv207_intctlr;
	pplatform->pintctlr = pmwv207_intctlr->pintctlr;

	return 0;
}

static s32 j9_handle_j9_distortion(j9_gearshifts *ppcie_info)
{
	j9_anthomyiid *pfpga = j9_bryaceous(ppcie_info);

	if (pfpga)
		j9_handle_j_sporicidal(pfpga->pmwv207_intctlr);

	return 0;
}

static s32 j9_handle_obituarize(j9_gearshifts *ppcie_info)
{
	j9_antiroyalist(ppcie_info, J9_HANDLE_J9MIRROR_QUINOPYRIN,
			J9_UNEXPORTABLE);
	return 0;
}

j9_turbans mwv207_fpga_ops = {
	.pcie_init = j9_handle__obituarize,
	.pcie_deinit = j9_handle_j9_commencing,
	.ddr_init = j9_handle_obituarize,
	.intr_init = j9_handle__outwriggle,
	.intr_deinit = j9_handle_j9_distortion,
};


