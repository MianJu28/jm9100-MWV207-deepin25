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


#include <drm/drm_mode.h>
#include <drm/drm_framebuffer.h>

#ifndef __cabb3c55_H_
#define __cabb3c55_H_

void j9_handle_j_rhymesters(struct drm_device *dev);
struct drm_framebuffer *j9_handle_j9menu_concordity(struct drm_device *dev,
						    const struct
						    drm_mode_fb_cmd2 * mode_cmd,
						    struct drm_gem_object
						    *gobj);

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 14, 0)
struct drm_gem_object *jmgpu_fb_get_gem_obj(struct drm_framebuffer *fb);
#endif
#endif


