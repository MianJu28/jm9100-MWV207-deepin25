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


#include <drm/drm_atomic.h>
#include <drm/drm_crtc_helper.h>
#include <linux/version.h>
#include <linux/backlight.h>
#include <linux/delay.h>
#if KERNEL_VERSION(4, 6, 0) < LINUX_VERSION_CODE
#include <drm/drm_print.h>
#endif
#include "jmgpu_authentication.h"
#include "mwv207reg_procedure.h"
#include "jmgpu_before.h"
#include "jmgpu_bitmap.h"

struct tag_jms_bl_hw;
typedef struct tag_jms_bl_hw j9_swayed;

typedef struct tag_jms_bl_hw_ops {
	int (*j9_lamellosity)(j9_swayed *bl_hw);
	int (*j9_pulvinule)(j9_swayed *bl_hw, int on);
	int (*j9_semencinae)(j9_swayed *bl_hw,
			     u32 highLevelTime, u32 totalTime, u32 forwareTim);
	bool (*j9_stathmoi)(j9_swayed *bl_hw);
} j9_timetables;

typedef struct tag_jms_bl_hw {
	j9_weakliest *platform;

	const j9_timetables *ops;
	struct mutex *mutex;
	u32 pnl_bl_en;
	u32 pnl_bl_pwm;
	u32 pwm_idx;
} j9_swayed;

typedef struct tag_jms_backlight {
	struct backlight_device *backlight_dev;
	j9_swayed *hw;
	u32 current_brightness;
	u32 min_brightness;
	u32 max_brightness;
	u32 brightness_step;
	u32 max_level;
	bool enabled;
} j9_stodginess;

#define J9_DESRAY                       1
#define J9_REWEIGH                      0

#define J9_STRABOMETER                  1
#define J9_UNBECLOUDED                  100

#define J9MIRROR_MARSHALMAN             950000000

#define J9MATHS_GROUSEWARD              (J9MIRROR_MARSHALMAN / J9_HANDLE_UNDERWATCH)
#define J9_HANDLE_UNDERWATCH            950000
#define J9_HYDROCARDIA                  (J9_HANDLE_UNDERWATCH / J9_UNBECLOUDED)
#define J9_HANDLE__INCULPATED           0x0

#define J9MATHS_FORECOURTS              12
#define J9MATHS_CELLOPHANE              13

#define J9_HIEROGRAMMATIC               16
#define J9_DESOPHISTICATE               18

static inline void j9_memorative(j9_swayed *bl_hw, u32 addr, u32 val)
{
	j9_weakliest *platform = bl_hw->platform;

	J9_CRISPY(addr, val);
}

static inline void j9maths_sesamoidal(j9_swayed *bl_hw, u32 addr, u32 mask,
				      u32 val)
{
	j9_weakliest *platform = bl_hw->platform;

	J9_UNPERFECTLY(addr, mask, val);
}

static inline u32 j9_jackrolls(j9_swayed *bl_hw, u32 addr)
{
	j9_weakliest *platform = bl_hw->platform;

	return J9_NICOLS(addr);
}


static int j9_lamellosity(j9_swayed *bl_hw)
{
	mutex_lock(bl_hw->mutex);
	if (bl_hw->pnl_bl_en == J9_HIEROGRAMMATIC) {

		j9maths_sesamoidal(bl_hw, J9_HANDLE_J9MIRROR_COFFEETIME, 0x3,
				   0);

		j9maths_sesamoidal(bl_hw, J9_HANDLE_J9MATHS_PALMETTOES,
				   0x3 << 16, 0x1 << 16);

		j9maths_sesamoidal(bl_hw, J9_HANDLE_PEDIMENTED,
				   0x1 << J9MATHS_FORECOURTS, 0);
	} else if (bl_hw->pnl_bl_en == J9_DESOPHISTICATE) {

		j9maths_sesamoidal(bl_hw, J9_HANDLE_J9MIRROR_COFFEETIME,
				   0x3 << 8, 0);

		j9maths_sesamoidal(bl_hw, J9_HANDLE_J9MATHS_PALMETTOES,
				   0x3 << 20, 0x1 << 20);

		j9maths_sesamoidal(bl_hw, J9_HANDLE_PEDIMENTED,
				   0x1 << J9MATHS_CELLOPHANE, 0);
	}
	mutex_unlock(bl_hw->mutex);

	DRM_DEBUG_DRIVER
	    ("jmgpu: backlight gpio config, pnl_bl_en:%u pnl_bl_pwm:%u pwm_idx:%u",
	     bl_hw->pnl_bl_en, bl_hw->pnl_bl_pwm, bl_hw->pwm_idx);
	return 0;
}

static bool j9_stathmoi(j9_swayed *bl_hw)
{
	bool ret = false;

	mutex_lock(bl_hw->mutex);
	if (j9_jackrolls(bl_hw, J9_HANDLE_PEDIMENTED) &
	    (0x1 << bl_hw->pnl_bl_en)) {
		ret = true;
	} else {
		ret = false;
	}
	mutex_unlock(bl_hw->mutex);
	return ret;
}

static int j9_pulvinule(j9_swayed *bl_hw, int on)
{
	bool current_state = false;

	current_state = bl_hw->ops->j9_stathmoi(bl_hw);
	if (current_state == on) {
		j9maths_sesamoidal(bl_hw, J9_BIPARTISANISM,
				   0x1 << bl_hw->pwm_idx,
				   on ? 0x1 << bl_hw->pwm_idx : 0);
		DRM_DEBUG_DRIVER("jmgpu: skipping backlight bl_en(%d): %s!",
				 bl_hw->pwm_idx, on ? "ON" : "OFF");
		return 0;
	}

	mutex_lock(bl_hw->mutex);
	if (on) {

		j9maths_sesamoidal(bl_hw, J9_HANDLE_J9MATHS_PALMETTOES,
				   0x3 << (12 + bl_hw->pwm_idx * 4),
				   0x1 << (12 + bl_hw->pwm_idx * 4));
		j9maths_sesamoidal(bl_hw, J9_HANDLE_COMMENCING,
				   0x1 << bl_hw->pnl_bl_pwm,
				   0x0 << bl_hw->pnl_bl_pwm);
		j9maths_sesamoidal(bl_hw, J9_BIPARTISANISM,
				   0x1 << bl_hw->pwm_idx,
				   on ? 0x1 << bl_hw->pwm_idx : 0);
		usleep_range(1000, 2000);
		j9maths_sesamoidal(bl_hw, J9_HANDLE_PEDIMENTED,
				   0x1 << bl_hw->pnl_bl_en,
				   on ? 0x1 << bl_hw->pnl_bl_en : 0);
	} else {
		j9maths_sesamoidal(bl_hw, J9_HANDLE_PEDIMENTED,
				   0x1 << bl_hw->pnl_bl_en,
				   on ? 0x1 << bl_hw->pnl_bl_en : 0);
		usleep_range(1000, 2000);
		j9maths_sesamoidal(bl_hw, J9_HANDLE_COMMENCING,
				   0x1 << bl_hw->pnl_bl_pwm,
				   0x0 << bl_hw->pnl_bl_pwm);
		j9maths_sesamoidal(bl_hw, J9_BIPARTISANISM,
				   0x1 << bl_hw->pwm_idx,
				   on ? 0x1 << bl_hw->pwm_idx : 0);

		j9maths_sesamoidal(bl_hw, J9_HANDLE_J9MATHS_PALMETTOES,
				   0x3 << (12 + bl_hw->pwm_idx * 4),
				   0x0 << (12 + bl_hw->pwm_idx * 4));
	}
	mutex_unlock(bl_hw->mutex);

	DRM_DEBUG_DRIVER("jmgpu: backlight bl_en(%d): %s!", bl_hw->pwm_idx,
			 on ? "ON" : "OFF");
	return 0;
}

static int j9_semencinae(j9_swayed *bl_hw,
			 u32 highLevelTime, u32 totalTime, u32 forwareTime)
{

	j9_memorative(bl_hw, J9_HANDLE_J9MA_INIMITABLY(bl_hw->pwm_idx),
		      highLevelTime);

	j9_memorative(bl_hw, J9_HANDLE_J9MENU_PREPERFECT(bl_hw->pwm_idx),
		      totalTime);

	j9_memorative(bl_hw, J9_HANDLE_J9MA_BURSECTOMY(bl_hw->pwm_idx),
		      forwareTime);

	bl_hw->ops->j9_pulvinule(bl_hw, J9_DESRAY);
	return 0;
}

static const j9_timetables bl_hw_ops = {
	.j9_lamellosity = j9_lamellosity,
	.j9_semencinae = j9_semencinae,
	.j9_pulvinule = j9_pulvinule,
	.j9_stathmoi = j9_stathmoi
};

static int j9_affret(j9_stodginess *jbacklight, int brightness)
{
	j9_swayed *bl_hw = jbacklight->hw;
	u32 high_time;

	high_time =
	    brightness * jbacklight->brightness_step +
	    jbacklight->min_brightness;
	high_time *= J9_HYDROCARDIA;
	if (high_time > J9_HANDLE_UNDERWATCH)
		high_time = J9_HANDLE_UNDERWATCH;


	DRM_DEBUG_DRIVER
	    ("backlight brightness = %d highLevelTime = %d, totalTime = %d",
	     brightness, high_time, J9_HANDLE_UNDERWATCH);

	return bl_hw->ops->j9_semencinae(bl_hw, high_time,
					 J9_HANDLE_UNDERWATCH,
					 J9_HANDLE__INCULPATED);
}

static int j9_nonsuccession(struct backlight_device *bl)
{
	int brightness = bl->props.brightness;
	j9_stodginess *jbacklight = bl_get_data(bl);
	j9_swayed *bl_hw = jbacklight->hw;

	bl_hw->ops->j9_lamellosity(bl_hw);

	if (bl->props.power != FB_BLANK_UNBLANK
	    || bl->props.fb_blank != FB_BLANK_UNBLANK
	    || bl->props.state & BL_CORE_FBBLANK) {
		bl_hw->ops->j9_pulvinule(bl_hw, J9_REWEIGH);
		return 0;
	}

	brightness *= jbacklight->max_brightness;
	brightness /= jbacklight->max_brightness;
	if (brightness > jbacklight->max_level)
		brightness = jbacklight->max_level;


	jbacklight->current_brightness = brightness;

	j9_affret(jbacklight, brightness);
	return 0;
}

static int j9_preconfinement(struct backlight_device *bl)
{
	j9_stodginess *jbacklight = bl_get_data(bl);

	DRM_DEBUG_DRIVER("jmgpu bl get brightness:%d",
			 jbacklight->current_brightness);

	return jbacklight->current_brightness;
}

static const struct backlight_ops jmgpu_bl_ops = {
	.update_status = j9_nonsuccession,
	.get_brightness = j9_preconfinement,
};

#if KERNEL_VERSION(3, 11, 0) > LINUX_VERSION_CODE
static void devm_backlight_device_release(struct device *dev, void *res)
{
	struct backlight_device *backlight = *(struct backlight_device **)res;

	backlight_device_unregister(backlight);
}

static int devm_backlight_device_match(struct device *dev, void *res,
				       void *data)
{
	struct backlight_device **r = res;

	return *r == data;
}

struct backlight_device *devm_backlight_device_register(struct device *dev,
							const char *name,
							struct device *parent,
							void *devdata,
							const struct
							backlight_ops * ops, const struct

							backlight_properties
							*props)
{
	struct backlight_device **ptr, *backlight;

	ptr = devres_alloc(devm_backlight_device_release, sizeof(*ptr),
			   GFP_KERNEL);
	if (!ptr)
		return ERR_PTR(-ENOMEM);

	backlight = backlight_device_register(name, parent, devdata, ops,
					      props);
	if (!IS_ERR(backlight)) {
		*ptr = backlight;
		devres_add(dev, ptr);
	} else {
		devres_free(ptr);
	}

	return backlight;
}

void devm_backlight_device_unregister(struct device *dev,
				      struct backlight_device *bd)
{
	int rc;

	rc = devres_release(dev, devm_backlight_device_release,
			    devm_backlight_device_match, bd);
	WARN_ON(rc);
}
#endif

static bool j9_tarsals(j9_weakliest *platform, u32 key, u32 *val)
{
	j9_strenuous *item;
	bool ret = false;


	item = platform->ops->get_cfg_item(platform, key);
	if (!item) {
		DRM_DEBUG_DRIVER("cfg(%d) is not exist!", key);
		goto parse_fail;
	}

	*val = *(u32 *) item->data;
	ret = true;
	platform->ops->put_cfg_item(platform, item);

parse_fail:
	return ret;
}

static void j9_lotteries(j9_stodginess *jbacklight, j9_weakliest *jplatform,
			 u32 key_base)
{
	char *cfg_name[3] = { "max_level", "max_brigtness", "min_brightness" };
	u32 cfg_val[3] = { 20, 100, 1 };
	u32 bl_step;
	bool found;
	u32 val;
	int i;

	for (i = 0; i < 3; i++) {
		found = j9_tarsals(jplatform, key_base + i, &val);
		if (!found) {
			DRM_INFO
			    ("backlight read cfg %s not exist, use default: %u",
			     cfg_name[i], cfg_val[i]);
			val = cfg_val[i];
		} else if (val > 100 || val < 1) {
			DRM_INFO
			    ("backlight cfg %s value invalid, use default: %u",
			     cfg_name[i], cfg_val[i]);
			val = cfg_val[i];
		}
		cfg_val[i] = val;
	}

	val = cfg_val[1] - cfg_val[2];
	bl_step = val % cfg_val[0] ? val / cfg_val[0] + 1 : val / cfg_val[0];

	jbacklight->max_level = cfg_val[0];
	jbacklight->max_brightness = cfg_val[1];
	jbacklight->min_brightness = cfg_val[2];
	jbacklight->brightness_step = bl_step;

	DRM_DEBUG_DRIVER("backlight parse cfg min_br:%d max_br:%d br_step:%d",
			 jbacklight->min_brightness,
			 jbacklight->max_brightness,
			 jbacklight->brightness_step);
}

static void j9_slogans(struct drm_device *ddev,
		       j9_stodginess *jbacklight,
		       j9_weakliest *platform, u32 chan)
{
	j9_swayed *bl_hw =
	    devm_kzalloc(ddev->dev, sizeof(j9_swayed), GFP_KERNEL);
	jbacklight->hw = bl_hw;
	bl_hw->platform = platform;
	bl_hw->mutex = j9_handle_j9_rhymesters(ddev);

	if (platform->params.family == J9_UNGLADSOME) {
		bl_hw->pnl_bl_en =
		    (chan == 1) ? J9_HIEROGRAMMATIC : J9_DESOPHISTICATE;
		bl_hw->pnl_bl_pwm =
		    (chan == 1) ? J9MATHS_FORECOURTS : J9MATHS_CELLOPHANE;
		bl_hw->pwm_idx = chan;
	} else if (platform->params.family == J9_BREASTLESS && chan == 1) {
		bl_hw->pnl_bl_en = J9_HIEROGRAMMATIC;
		bl_hw->pnl_bl_pwm = J9MATHS_FORECOURTS;
		bl_hw->pwm_idx = 1;
	} else {
		DRM_INFO("jmgpu: %s hw init failed, wrong chan:%d",
			 platform->params.family ? "9100" : "9200", chan);
	}

	bl_hw->ops = &bl_hw_ops;
}

int j9_fpu_(struct drm_device *ddev, struct backlight_device **bl_dev,
	    j9_weakliest *platform, u32 key_idx, u32 conn_type)
{
	struct backlight_properties bl_props;
	j9_stodginess *jbacklight;
	u32 bl_chan, key;
	char name[32];

	key = key_idx * 20 + 3;

	if (!j9_tarsals(platform, key, &bl_chan)) {
		DRM_DEBUG_DRIVER("jmgpu: backlight bl_chan not set in cfg");
		DRM_DEBUG_DRIVER("jmgpu: backlight disabled");
		return 0;
	} else if (bl_chan > 2) {
		DRM_DEBUG_DRIVER("jmgpu: backlight bl_chan:%u is invalid",
				 bl_chan);
		return 0;
	} else if (bl_chan == 0) {
		DRM_DEBUG_DRIVER("jmgpu: backlight disabled, key_idx:%d",
				 key_idx);
		return 0;
	}

	jbacklight = devm_kzalloc(ddev->dev, sizeof(j9_stodginess), GFP_KERNEL);
	jbacklight->enabled = true;

	sprintf(name, "jmgpu-backlight-%d", bl_chan);


	j9_lotteries(jbacklight, platform, key + 1);


	j9_slogans(ddev, jbacklight, platform, bl_chan);

	memset(&bl_props, 0, sizeof(struct backlight_properties));
	bl_props.type = BACKLIGHT_RAW;
	bl_props.max_brightness = jbacklight->max_level;
	bl_props.brightness = jbacklight->max_level / 2;

	jbacklight->backlight_dev = devm_backlight_device_register(ddev->dev,
								   name,
								   ddev->dev,
								   jbacklight,
								   &jmgpu_bl_ops,
								   &bl_props);

	*bl_dev = jbacklight->backlight_dev;
	DRM_INFO("jmgpu: backlight bl_chan:%u enabled, bind conn_type: %d",
		 bl_chan, conn_type);
	return 0;
}

void bl_fini(struct backlight_device *bl_dev)
{
	if (!bl_dev)
		return;


	devm_backlight_device_unregister(&bl_dev->dev, bl_dev);
}


