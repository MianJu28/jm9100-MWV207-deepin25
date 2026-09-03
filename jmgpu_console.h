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


#ifndef __c2343d39_H_
#define __c2343d39_H_

#include "jmgpu_messages.h"
struct drm_plane *j9_handle_elementish(struct drm_device *ddev,
				       j9_weakliest * platform, u32 crtc_idx,
				       enum drm_plane_type type,
				       spinlock_t *lock);
int j9_handle__attribute_chalkstone(struct drm_plane *plane);

void jmgpu_plane_cursor_win_update(struct drm_plane *plane);

#endif


