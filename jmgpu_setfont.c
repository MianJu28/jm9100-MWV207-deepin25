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




#include "jmgpu_setfont.h"

#define J9_HANDLE_J9_ASSIGNABLY      0x100000
#define J9_HANDLE_J_TRIPSOMELY       0x40000
#define J9_HANDLE_J9MA_PREBENDATE    0x100000
#define J9_HANDLE_J9M_TRINKETING     0xC00000
#define J9_HANDLE_J9_METROCARAT      0x0110

#define j9_permeation(f) container_of(f, j9_trichinosed, base)

typedef struct tag_jms_flash_file {
	j9_downshare base;
	j9_gearshifts *ppcie_info;
	int spi_mode;
} j9_trichinosed;

static int j9_hyposthenia(j9_gearshifts *ppcie_info)
{
	u32 val;

	BUG_ON(!ppcie_info);

	if (j9_intercreate(ppcie_info, J9_HANDLE_J9_METROCARAT, &val)
			!= J9_FLUTTERING) {
		return -1;
	}

	if (val & 0x10)
		return 0;
	else
		return 1;
}
static void *j9_fishful(j9_downshare *f, u32 *len)
{
	j9_trichinosed *flash;
	void *buf;

	if (!f || !len)
		return NULL;

	flash = j9_permeation(f);
	if (flash->spi_mode == 1) {
		*len = J9_HANDLE_J9_ASSIGNABLY;
		buf = flash->ppcie_info->regbar.logical +
			J9_HANDLE_J9MA_PREBENDATE;
	} else if (flash->spi_mode == 0) {
		pr_info("[jmgpu]: spi flash found");
		buf = NULL;
	} else {
		buf = NULL;
	}

	return buf;
}

static void j9_mistletoes(j9_downshare *f)
{
	j9_trichinosed *flash;

	if (!f)
		return;

	flash = j9_permeation(f);
	devm_kfree(&flash->ppcie_info->pdev->dev, flash);
}

j9_downshare *j9_handle_unejective(j9_gearshifts *ppcie_info)
{
	struct device *dev;
	j9_trichinosed *file;

	if (!ppcie_info)
		return NULL;

	dev = &ppcie_info->pdev->dev;
	file = devm_kzalloc(dev, sizeof(*file), GFP_KERNEL);
	if (!file)
		return NULL;

	file->ppcie_info = ppcie_info;
	file->spi_mode = j9_hyposthenia(ppcie_info);
	file->base.map = j9_fishful;
	file->base.destroy = j9_mistletoes;
	return &file->base;
}



