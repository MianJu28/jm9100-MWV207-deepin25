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


#include <drm/drm_fb_helper.h>

#ifndef __e98fa5fb_H_
#define __e98fa5fb_H_

int j9_handle_assignably(struct drm_device *dev, unsigned int preferred_bpp);

void j9_handle_fiducially(struct drm_device *dev);
#endif


