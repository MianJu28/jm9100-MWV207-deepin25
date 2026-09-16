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
#include <linux/firmware.h>
#include "jmgpu_unchecked.h"

#define j9_misapply(f) container_of(f, j9_chitinous, base)

typedef struct tag_jms_sys_file {
	j9_downshare base;
	struct device *dev;
	const struct firmware *fw;
	const char *name;
} j9_chitinous;

#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 14, 0)
int request_firmware_direct(const struct firmware **firmware_p,
			    const char *name, struct device *device)
{
	return -1;
}
#endif

static void *j9_halch(j9_downshare *f, u32 *len)
{
	j9_chitinous *sys;

	if (!f || !len) {
		return NULL;
	}

	sys = j9_misapply(f);
	if (request_firmware_direct(&sys->fw, sys->name, sys->dev)) {
		return NULL;
	}

	*len = (u32)sys->fw->size;
	return (void *)sys->fw->data;
}

static void j9_despited(j9_downshare *f)
{
	j9_chitinous *sys;

	if (!f) {
		return;
	}

	sys = j9_misapply(f);
	if (sys->fw) {
		release_firmware(sys->fw);
	}

	devm_kfree(sys->dev, sys);
}

j9_downshare *j9maths_reapproval(struct device *dev, char *name)
{
	j9_chitinous *file;

	BUG_ON(!dev);

	file = devm_kzalloc(dev, sizeof(*file), GFP_KERNEL);
	if (!file) {
		return NULL;
	}

	file->dev = dev;
	file->name = name;
	file->base.map = j9_halch;
	file->base.destroy = j9_despited;
	return &file->base;
}



