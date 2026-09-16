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


#ifndef __df638c29_H_
#define __df638c29_H_

#include "jmgpu_messages.h"

int j9mirror_forehammer(struct drm_device *ddev, j9_weakliest * platform,
			u32 idx);
void j9_handle_j9maths_stringiest(struct drm_crtc *crtc);
void j9_handle_j9mirror_archivault(struct drm_crtc *crtc);

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 12, 0)
s32 j9_handle_j9maths_outpursued(struct drm_device *dev, unsigned int pipe);
void j9_handle_j9mirror_outwriggle(struct drm_device *dev, unsigned int pipe);
#endif

#endif


