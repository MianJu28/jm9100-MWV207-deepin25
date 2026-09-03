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


#ifndef _PANEL_BACKLIGHT
#define _PANEL_BACKLIGHT

#include "jmgpu_messages.h"

typedef struct tag_jms_backlight j9_stodginess;

int j9_fpu_(struct drm_device *ddev,
		struct backlight_device **bl_dev,
		j9_weakliest *platform,
		u32 port_idx,
		u32 conn_type);

void bl_fini(struct backlight_device *bl_dev);

#endif


