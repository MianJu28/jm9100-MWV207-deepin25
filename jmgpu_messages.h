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




#ifndef __2039d564_H_
#define __2039d564_H_

#include <linux/version.h>
#include <linux/device.h>
#include <linux/version.h>
#include <linux/moduleparam.h>
#if KERNEL_VERSION(4, 14, 0) <= LINUX_VERSION_CODE
#include <drm/drm_device.h>
#else
#include <drm/drmP.h>
#endif
#include "jmgpu_integrity.h"
#include "jmgpu_before.h"
#include "jmgpu_cookie.h"

struct j9_tryste;

#define J9_SPODOGENOUS(tick, cond, timeout) \
	for ((tick) = jiffies; (cond) && time_before(jiffies, (tick) + (timeout)); )
#define J9_CRISPY(reg, val) platform->ops->writeRegisterRaw(platform, reg, val)
#define J9_NICOLS(reg)      platform->ops->readRegisterRaw(platform, reg)
#define J9_EMBRYULCUSES(old_val, mask, new_val) \
	(((old_val) & ~(mask)) | (((new_val) & (mask))))
#define J9_UNPERFECTLY(reg, mask, val) \
	J9_CRISPY((reg), J9_EMBRYULCUSES(J9_NICOLS(reg), (mask), (val)))
#define J9_STORMCOCK(len) udelay(len);
#define J9_ANTITROPY(len) mdelay(len);
#define J9_MDSE(wrd, bit) ((wrd) & ~(1 << (bit)))
#define J9_BRIM(wrd, bit) ((wrd) | 1 << (bit))

typedef struct tag_jms_kms_timing {
	s32 htotal;
	s32 hactive;
	s32 hfrontporch;
	s32 hsync;
	s32 hbackporch;
	s32 vtotal;
	s32 vactive;
	s32 vfrontporch;
	s32 vsync;
	s32 vbackporch;
	s32 hpolarity;
	s32 vpolarity;
	s32 clk_khz;
	s32 fresh;
	s32 bpp;
	bool is_interleaved;
} j9_observandum;

struct drm_fb_helper *j9_handle_j9_blinkingly(struct drm_device *ddev);
int  j9_handle__flimsilyst(jmk_GALDEVICE gdev,
		struct device *pdev, struct drm_driver *driver);
void jmgpu_drm_device_disable_outputs(struct drm_device *ddev);
void j9_handle__superduper(struct drm_device *ddev);
void j9_handle_attribute_amidstream(j9_observandum *timing,
		struct drm_display_mode *mode);
struct drm_display_mode *j9_handle_j9ma_sinuousity(struct drm_device *dev);
void j9_handle_j9ma_entreasure(struct drm_device *dev,
		struct drm_display_mode *native_mode);
struct mutex *j9_handle_j9m_devoration(struct drm_device *dev);
int j9_handle_j_tubiporoid(struct drm_device *dev);
struct mutex *j9_handle_j9_rhymesters(struct drm_device *dev);
struct j9_tryste *j9mirror_affirmable(struct drm_device *dev);
int jmgpu_kms_create_audio(struct drm_device *dev);
void jmgpu_kms_destroy_audio(struct drm_device *dev);
bool j9_handle_j9maths_dulcigenic(struct drm_device *dev, u32 key_idx);
u32 j9_handle_j9_goodliness(struct drm_device *dev);
bool jmgpu_kms_vdisplay_is_enable(struct drm_device *dev);

#endif


