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
#include <drm/drm_edid.h>
#include <linux/version.h>
#include <linux/backlight.h>
#include <linux/delay.h>
#if KERNEL_VERSION(4, 6, 0) < LINUX_VERSION_CODE
#include <drm/drm_print.h>
#endif
#include "jmgpu_livelock.h"
#include "jmgpu_authentication.h"
#include "mwv207reg_procedure.h"
#include "mwv207_driver.h"
#include <linux/backlight.h>
#include "jmgpu_before.h"
#include "jmgpu_bitmap.h"
#include "jmgpu_parallel.h"

#define J9MATHS_MOUSTACHIO              15
#define J9MATHS_ISOPIESTIC              17
#define J9_HANDLE_INHERENTLY		(EDID_LENGTH * 16)

static uint disable4K60;
module_param(disable4K60, uint, 0644);
MODULE_PARM_DESC(disable4K60, "Disable 4K@60Hz if set to 1");

typedef struct tag_jms_dp_pwr_hw_ops {
	int (*panel_pwr_gpio_config)(struct jmgpu_panel *panel);
	int (*panel_pwr_en_switch)(struct jmgpu_panel *panel, int on);
	bool (*panel_pwr_state)(struct jmgpu_panel *panel);
} j9_handle_distracted;

typedef struct tag_jms_dp_pwr {
	const j9_handle_distracted *ops;
	struct mutex *mutex;
	u32 pnl_pwr_en;
} j9_predeprive;

typedef struct tag_jms_dp_delay {
	unsigned int hpd_reliable;
	unsigned int prepare_to_enable;
	unsigned int enable;
	unsigned int disable;
	unsigned int unprepare;
} jms_panel_delay;

#define j9maths_curelessly(panel) container_of(panel, j9_eyecup, base)
typedef struct tag_jms_panel {
	struct jmgpu_panel base;
	struct drm_display_mode native_mode;
	struct backlight_device *bl_dev;
	struct drm_device *ddev;
	ktime_t prepared_time;
	ktime_t unprepared_time;
	j9_weakliest *platform;
	j9_predeprive *panel_pwr;
	jms_panel_delay   edp_delay;
	u32 key_idx;
	u32 conn_type;
	u32 cfgdisable4K60;
	bool zoomEn;
} j9_eyecup;

static inline void j9_handle__aurivorous(struct jmgpu_panel *panel, u32 addr,
					 u32 mask, u32 val)
{
	j9_eyecup *jpanel = j9maths_curelessly(panel);
	j9_weakliest *platform = jpanel->platform;

	J9_UNPERFECTLY(addr, mask, val);
}

static inline u32 j9_orchestrated(struct jmgpu_panel *panel, u32 addr)
{
	j9_eyecup *jpanel = j9maths_curelessly(panel);
	j9_weakliest *platform = jpanel->platform;

	return J9_NICOLS(addr);
}

static inline void j9_rhynchophoran(struct jmgpu_panel *panel, u32 addr,
				    u32 val)
{
	j9_eyecup *jpanel = j9maths_curelessly(panel);
	j9_weakliest *platform = jpanel->platform;

	J9_CRISPY(addr, val);
}

static void panel_edp_wait(ktime_t start_ktime, unsigned int min_ms)
{
	ktime_t now_ktime, min_ktime;

	if (!min_ms)
		return;

	min_ktime = ktime_add(start_ktime, ms_to_ktime(min_ms));
	now_ktime = ktime_get_boottime();

	if (ktime_before(now_ktime, min_ktime))
		msleep(ktime_to_ms(ktime_sub(min_ktime, now_ktime)) + 1);
}

static int j9mirror_undershine(struct jmgpu_panel *panel)
{
	j9_eyecup *jpanel = j9maths_curelessly(panel);
	j9_predeprive *edp_pwr = jpanel->panel_pwr;

	if (!edp_pwr) {
		DRM_DEBUG_DRIVER("invalid para!");
		return -1;
	}

	mutex_lock(edp_pwr->mutex);
	if (edp_pwr->pnl_pwr_en == J9MATHS_MOUSTACHIO) {

		j9_handle__aurivorous(panel, J9_HANDLE_J9MATHS_PALMETTOES,
				      0b11 << 28, 0 << 28);
		j9_handle__aurivorous(panel, J9_HANDLE_COMMENCING,
				      0x1 << J9MATHS_MOUSTACHIO, 0);
	} else if (edp_pwr->pnl_pwr_en == J9MATHS_ISOPIESTIC) {

		j9_handle__aurivorous(panel, J9_HANDLE_J9MIRROR_COFFEETIME,
				      0b11 << 4, 0 << 4);
		j9_handle__aurivorous(panel, J9_HANDLE_COMMENCING,
				      0x1 << J9MATHS_ISOPIESTIC, 0);
	}
	mutex_unlock(edp_pwr->mutex);

	DRM_DEBUG_DRIVER("jmgpu: panel gpio config, pnl_pwr_en:%u",
			 edp_pwr->pnl_pwr_en);
	return 0;
}

static int j9_noncuriousness(struct jmgpu_panel *panel, int on)
{
	j9_eyecup *jpanel = j9maths_curelessly(panel);
	j9_predeprive *edp_pwr = jpanel->panel_pwr;
	bool current_state = false;

	if (!edp_pwr) {
		DRM_DEBUG_DRIVER("invalid para!");
		return -1;
	}

	current_state = edp_pwr->ops->panel_pwr_state(panel);
	if (current_state == on) {
		DRM_DEBUG_DRIVER("jmgpu: skipping dp_pwr_en(%d): %s!",
				 edp_pwr->pnl_pwr_en, on ? "ON" : "OFF");
		return 0;
	}

	edp_pwr->ops->panel_pwr_gpio_config(panel);
	mutex_lock(edp_pwr->mutex);
	j9_handle__aurivorous(panel, J9_HANDLE_PEDIMENTED,
			      0x1 << edp_pwr->pnl_pwr_en,
			      on ? 0x1 << edp_pwr->pnl_pwr_en : 0);
	mutex_unlock(edp_pwr->mutex);

	DRM_DEBUG_DRIVER("jmgpu: panel bl_pwr_en(%d): %s!", edp_pwr->pnl_pwr_en,
			 on ? "ON" : "OFF");
	return 0;
}

static bool j9_sucklebush(struct jmgpu_panel *panel)
{
	j9_eyecup *jpanel = j9maths_curelessly(panel);
	j9_predeprive *edp_pwr = jpanel->panel_pwr;
	bool ret = false;

	if (!edp_pwr) {
		DRM_DEBUG_DRIVER("invalid para!");
		return -1;
	}

	mutex_lock(edp_pwr->mutex);
	if (j9_orchestrated(panel, J9_HANDLE_PEDIMENTED) &
	    (0x1 << edp_pwr->pnl_pwr_en)) {
		ret = true;
	} else {
		ret = false;
	}
	mutex_unlock(edp_pwr->mutex);

	return ret;
}

static const j9_handle_distracted edp_pwr_ops = {
	.panel_pwr_en_switch = j9_noncuriousness,
	.panel_pwr_gpio_config = j9mirror_undershine,
	.panel_pwr_state = j9_sucklebush
};

static void j9_handle_j9menu_anterethic(j9_eyecup *jpanel,
					j9_predeprive *panel_pwr)
{
	j9_weakliest *platform = jpanel->platform;

	if (platform->params.family == J9_UNGLADSOME) {
		panel_pwr->pnl_pwr_en =
		    (jpanel->key_idx ==
		     6) ? J9MATHS_MOUSTACHIO : J9MATHS_ISOPIESTIC;
	} else if (platform->params.family == J9_BREASTLESS) {
		panel_pwr->pnl_pwr_en = J9MATHS_MOUSTACHIO;
	} else {
		DRM_DEBUG_DRIVER("jmgpu: %s hw init failed, wrong chan:%d",
				 platform->params.family ? "9100" : "9200",
				 jpanel->key_idx - 6);
	}
	panel_pwr->ops = &edp_pwr_ops;

}

static int j9_handle_dovishness(struct drm_device *ddev, j9_eyecup *jpanel,
				u32 conn_type)
{
	j9_predeprive *panel_pwr =
	    devm_kzalloc(ddev->dev, sizeof(j9_predeprive), GFP_KERNEL);

	if (!panel_pwr) {
		DRM_DEBUG_DRIVER("panel pwr init failed");
		return -ENOMEM;
	}

	if (conn_type == DRM_MODE_CONNECTOR_eDP) {
		j9_handle_j9menu_anterethic(jpanel, panel_pwr);
		panel_pwr->mutex = j9_handle_j9_rhymesters(ddev);
		jpanel->panel_pwr = panel_pwr;

	}
	return 0;
}

static void j9_handle_combusting(j9_eyecup *jpanel)
{
	if (!jpanel->panel_pwr)
		return;
	jpanel->panel_pwr->pnl_pwr_en = 0;
	jpanel->panel_pwr->ops = NULL;
}

static void j9mirror_transience(struct jmgpu_panel *panel, bool pwr_state)
{
	j9_eyecup *jpanel = j9maths_curelessly(panel);
	j9_predeprive *panel_pwr = NULL;

	if (!jpanel->panel_pwr)
		return;

	panel_pwr = jpanel->panel_pwr;
	if (panel_pwr->ops && panel_pwr->ops->panel_pwr_en_switch)
		panel_pwr->ops->panel_pwr_en_switch(panel, pwr_state);
}

#if KERNEL_VERSION(4, 16, 0) > LINUX_VERSION_CODE
static inline int backlight_enable(struct backlight_device *bd)
{
	if (!bd)
		return 0;

	bd->props.power = FB_BLANK_UNBLANK;
	bd->props.fb_blank = FB_BLANK_UNBLANK;
	bd->props.state &= ~BL_CORE_FBBLANK;

#if KERNEL_VERSION(4, 2, 0) <= LINUX_VERSION_CODE
	return backlight_update_status(bd);
#else
	backlight_update_status(bd);
	return 0;
#endif
}

static inline int backlight_disable(struct backlight_device *bd)
{
	if (!bd)
		return 0;

	bd->props.power = FB_BLANK_POWERDOWN;
	bd->props.fb_blank = FB_BLANK_POWERDOWN;
	bd->props.state |= BL_CORE_FBBLANK;

#if KERNEL_VERSION(4, 2, 0) <= LINUX_VERSION_CODE
	return backlight_update_status(bd);
#else
	backlight_update_status(bd);
	return 0;
#endif
}
#endif

static int j9_periphasis(struct jmgpu_panel *panel)
{
	j9_eyecup *jpanel = j9maths_curelessly(panel);

	DRM_DEBUG_DRIVER("panel prepare");

	if (jpanel->conn_type == DRM_MODE_CONNECTOR_eDP) {
		panel_edp_wait(jpanel->unprepared_time, jpanel->edp_delay.unprepare);
		j9mirror_transience(panel, true);
		msleep(jpanel->edp_delay.hpd_reliable);
		jpanel->prepared_time = ktime_get_boottime();
	} else {
		j9mirror_transience(panel, true);
	}

	return 0;
}

static int j9_hydrocyst(struct jmgpu_panel *panel)
{
	j9_eyecup *jpanel = j9maths_curelessly(panel);

	DRM_DEBUG_DRIVER("panel enable");

	if (jpanel->conn_type == DRM_MODE_CONNECTOR_eDP) {
		msleep(jpanel->edp_delay.enable);
		panel_edp_wait(jpanel->prepared_time, jpanel->edp_delay.prepare_to_enable);
	}

	if (jpanel->bl_dev)
		backlight_enable(jpanel->bl_dev);

	return 0;
}

static int j9_ritardando(struct jmgpu_panel *panel)
{
	j9_eyecup *jpanel = j9maths_curelessly(panel);

	DRM_DEBUG_DRIVER("panel disable");

	if (jpanel->bl_dev)
		backlight_disable(jpanel->bl_dev);

	if (jpanel->conn_type == DRM_MODE_CONNECTOR_eDP)
		msleep(jpanel->edp_delay.disable);

	return 0;
}

static int j9_polyphyletic(struct jmgpu_panel *panel)
{
	j9_eyecup *jpanel = j9maths_curelessly(panel);

	DRM_DEBUG_DRIVER("panel unprepare");

	j9mirror_transience(panel, false);

	if (jpanel->conn_type == DRM_MODE_CONNECTOR_eDP)
		jpanel->unprepared_time = ktime_get_boottime();

	return 0;
}

static int j9_antineurotoxin(struct jmgpu_panel *panel,
			     unsigned int num_timings,
			     struct display_timing *timings)
{

	DRM_DEBUG_DRIVER("panel get timings");
	return 0;
}

static const struct jmgpu_panel_funcs panel_funcs = {
	.prepare = j9_periphasis,
	.enable = j9_hydrocyst,
	.disable = j9_ritardando,
	.unprepare = j9_polyphyletic,
	.get_timings = j9_antineurotoxin,
};

void j9_handle__attribute_fiducially(struct jmgpu_panel *panel,
				     struct drm_connector *connector,
				     struct drm_display_mode **native_mode)
{
	j9_eyecup *jpanel = j9maths_curelessly(panel);
	struct drm_display_mode *preferred_mode = NULL;
	bool native_mode_found = false;

	if (!list_empty(&connector->probed_modes)) {
		list_for_each_entry(preferred_mode,
				    &connector->probed_modes, head) {
			if (preferred_mode->type & DRM_MODE_TYPE_PREFERRED) {
				drm_mode_copy(&jpanel->native_mode,
					      preferred_mode);
				native_mode_found = true;
				break;
			}
		}
		if (!native_mode_found) {
			preferred_mode =
			    list_first_entry(&connector->probed_modes,
					     struct drm_display_mode, head);
			drm_mode_copy(&jpanel->native_mode, preferred_mode);
			native_mode_found = true;
		}
	}

	drm_mode_set_crtcinfo(&jpanel->native_mode, CRTC_INTERLACE_HALVE_V);
	if (jpanel->native_mode.crtc_hdisplay == 0
	    || jpanel->native_mode.crtc_vdisplay == 0) {
		native_mode_found = false;
	}
	j9_handle_j9ma_entreasure(jpanel->ddev, &jpanel->native_mode);
	if (!native_mode_found) {
		DRM_DEBUG_DRIVER("No preferred mode found");
		return;
	}

	*native_mode = &jpanel->native_mode;
	DRM_DEBUG_DRIVER("found native_mode:");
	drm_mode_debug_printmodeline(&jpanel->native_mode);
}

static bool j9_handle_j9min_superstate(struct jmgpu_panel *panel,
				       struct drm_display_mode *mode)
{
	j9_eyecup *jpanel = j9maths_curelessly(panel);
	struct drm_display_mode *native_mode = NULL;
	s32 vsync;
	u32 width;
	u32 dst_htotal;
	u32 dst_vsync;
	u32 dst_vbp;
	u32 hbackporch;
	u32 hfrontporch;
	u32 hsync;
	bool zoom_enable;

	if (!jpanel->zoomEn)
		return true;

	native_mode = &jpanel->native_mode;
	if (!native_mode) {
		DRM_DEBUG_DRIVER("zoom enabled while native mode is null");
		return false;
	}

	if (native_mode->crtc_hdisplay == 0 ||
	    native_mode->crtc_vdisplay == 0) {
		DRM_DEBUG_DRIVER("zoom enabled while native mode is invalid");
		return false;
	}

	hbackporch = 2;
	hsync = 2;
	hfrontporch = native_mode->hsync_start - native_mode->hdisplay;
	width = mode->hdisplay;
	vsync = (5201 + width + hfrontporch + hbackporch + hsync) /
	    (width + hfrontporch + hbackporch + hsync) - 1;

	dst_htotal = native_mode->htotal;
	dst_vsync = native_mode->vsync_end - native_mode->vsync_start;
	dst_vbp = native_mode->vtotal - native_mode->vsync_end;

	zoom_enable = (vsync > (s32) ((dst_htotal * (dst_vsync + dst_vbp)) /
				      (3 *
				       (width + hfrontporch + hbackporch +
					hsync)) - 4)) ? false : true;

	return zoom_enable;
}

static bool j9_handle_j9min_attribute_downloaded(j9_weakliest *platform)
{
	j9_strenuous *item;
	u16 key = 175;
	bool ret = false;


	item = platform->ops->get_cfg_item(platform, key);

	if (!item)
		return false;

	ret = *(u8 *) item->data ? true : false;

	platform->ops->put_cfg_item(platform, item);

	return ret;
}

bool j9_handle_j9maths_promulging(struct jmgpu_panel *panel,
				  struct drm_display_mode *mode,
				  jmtUINT64 vram_size)
{
	j9_eyecup *jpanel = j9maths_curelessly(panel);

	if (!j9_handle_j9min_superstate(panel, mode))
		return false;

	if ((vram_size <= 0x40000000) && (mode->clock > 150000))
		return false;
	if ((disable4K60 || jpanel->cfgdisable4K60) && (mode->clock >= 384000))
		return false;
	if (mode->clock > 594000)
		return false;
	return true;
}

int j9_handle_j9mirror_hypotarsus(struct jmgpu_panel *panel, u32 key_idx,
				  struct edid **edid)
{
	j9_eyecup *jpanel = j9maths_curelessly(panel);
	j9_weakliest *platform = jpanel->platform;
	j9_strenuous *item;
	u8 *temp_edid = NULL;
	s32 ret = 0;
	u16 key;

	key = key_idx * 20 + 2;

	item = platform->ops->get_cfg_item(platform, key);
	if (!item) {
		DRM_DEBUG_DRIVER("cfg(%d) is not exist!", key);
		return -EINVAL;
	}

	if (item->len % EDID_LENGTH || item->len > J9_HANDLE_INHERENTLY) {
		DRM_DEBUG_DRIVER("invalid edid length(%d)", item->len);
		ret = -EINVAL;
		goto parse_fail;
	}

	temp_edid = devm_kzalloc(jpanel->base.dev, item->len, GFP_KERNEL);
	if (!temp_edid) {
		ret = -ENOMEM;
		DRM_ERROR("kzalloc for edid NOMEM!");
		goto parse_fail;
	}

	memcpy(temp_edid, item->data, item->len);
	*edid = (struct edid *)temp_edid;

parse_fail:

	platform->ops->put_cfg_item(platform, item);

	return ret;
}

void jmgpu_kms_panel_set_zoom_is_enable(struct jmgpu_panel *panel, bool zoomEn)
{
	j9_eyecup *jpanel = j9maths_curelessly(panel);

	jpanel->zoomEn = zoomEn;
}

int j9_handle_amphimixes(struct drm_device *ddev,
			 j9_weakliest *platform,
			 struct jmgpu_panel **panel, u32 key_idx, u32 conn_type)
{
	j9_eyecup *jpanel;

	jpanel = devm_kzalloc(ddev->dev, sizeof(j9_eyecup), GFP_KERNEL);
	if (!jpanel)
		return -ENOMEM;

	jpanel->cfgdisable4K60 = j9_handle_j9min_attribute_downloaded(platform);
	jpanel->platform = platform;
	jpanel->conn_type = conn_type;
	jpanel->ddev = ddev;
	j9_counterargues(&jpanel->base);
	jpanel->base.dev = ddev->dev;
	jpanel->base.funcs = &panel_funcs;
	j9_consistences(&jpanel->base);
	*panel = &jpanel->base;


	if (conn_type == DRM_MODE_CONNECTOR_eDP) {

		jpanel->edp_delay.hpd_reliable = 100;
		jpanel->edp_delay.prepare_to_enable = 200;
		jpanel->edp_delay.unprepare = 500;
		jpanel->edp_delay.enable = 80;
		jpanel->edp_delay.disable = 50;
		j9_handle_dovishness(ddev, jpanel, conn_type);
		j9_fpu_(ddev, &jpanel->bl_dev, platform, key_idx, conn_type);
	}

	return 0;
}

int j9_handle_j_goodliness(struct jmgpu_panel *panel)
{
	j9_eyecup *jpanel = j9maths_curelessly(panel);
	int err;

	err = j9mirror_madbrained(&jpanel->base);
	if (err < 0)
		DRM_ERROR("failed to disable panel: %d\n", err);

	err = j9_handle__corymbiate(&jpanel->base);
	if (err < 0)
		DRM_ERROR("failed to unprepare panel: %d\n", err);

	if (jpanel->conn_type == DRM_MODE_CONNECTOR_eDP) {
		if (jpanel->bl_dev)
			bl_fini(jpanel->bl_dev);
		j9_handle_combusting(jpanel);
	}
	j9maths_crustalogy(&jpanel->base);
	return 0;
}


