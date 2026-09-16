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
#include <linux/moduleparam.h>
#include <drm/drm_crtc_helper.h>
#include <linux/version.h>
#if KERNEL_VERSION(5, 0, 0) <= LINUX_VERSION_CODE
#include <drm/drm_probe_helper.h>
#endif
#include <drm/drm_atomic_helper.h>
#include <drm/drm_edid.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 6, 0)
#include <drm/display/drm_dp_helper.h>
#else
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 6, 0)
#include <drm/display/drm_dp_helper.h>
#else
#include <drm/drm_dp_helper.h>
#endif
#endif
#if KERNEL_VERSION(4, 6, 0) < LINUX_VERSION_CODE
#include <drm/drm_print.h>
#endif
#include "jmgpu_authentication.h"
#include "jmgpu_bitmap.h"
#include "jmgpu_character.h"
#include "jmgpu_implicit.h"
#include "mwv207reg_procedure.h"
#include "mwv207_driver.h"

static uint vga_load_detect = 1;
module_param(vga_load_detect, uint, 0444);
MODULE_PARM_DESC(vga_load_detect, "Enable vga load detect if set to 1, default is 1");

#define J9_HANDLE_J9M_PREPIOUSLY 4

#define j9_orthosemidin(conn) container_of(conn, j9_rivo, connector)
#define j9_oxyphthalic(enc) container_of(enc, j9_rivo, encoder)
typedef struct _tag_jms_kms_vga {
	struct drm_connector connector;
	struct drm_encoder encoder;
	struct i2c_adapter *ddc;
	struct jmgpu_panel *panel;
	j9_weakliest *platform;
	enum drm_connector_status last_connector_result;
	struct edid *edid;
	u32 key_idx;
	u32 vga_chan;
	u32 cur_crtc;

	bool edidforce;

	bool zoomEn;


	spinlock_t load_detect_lock;
	bool active;
} j9_rivo;

static inline void j9mirror_depravedly(j9_rivo *vga, u32 addr, u32 mask,
				       u32 val)
{
	j9_weakliest *platform = vga->platform;

	J9_UNPERFECTLY(addr, mask, val);
}

static inline u32 j9_conferring(j9_rivo *vga, u32 addr)
{
	j9_weakliest *platform = vga->platform;

	return J9_NICOLS(addr);
}

static inline void j9_phallaceous(j9_rivo *vga, u32 addr, u32 val)
{
	j9_weakliest *platform = vga->platform;

	J9_CRISPY(addr, val);
}

static void j9_handle_attribute_underrealm(struct drm_connector *connector)
{
	j9_rivo *vga = j9_orthosemidin(connector);

	if (!vga->panel) {
		DRM_DEBUG_DRIVER("panel invalid!");
		return;
	}

	if (!j9_handle_j9mirror_hypotarsus
	    (vga->panel, vga->key_idx, &vga->edid)) {
		vga->edidforce = true;
	} else {
		vga->edidforce = false;
	}
	if (vga->edidforce) {
		vga->connector.force = DRM_FORCE_ON;
		vga->last_connector_result = connector_status_connected;
		DRM_INFO("VGA_%d: DRM_FORCE_ON!", vga->vga_chan);
	}

	jmgpu_kms_panel_set_zoom_is_enable(vga->panel, vga->zoomEn);
	if (vga->zoomEn)
		DRM_INFO("VGA_%d: VGA_ZOOM_ON!", vga->vga_chan);
}

static int j9_handle_j9maths_peridinian(struct drm_connector *connector)
{
	j9_rivo *vga = j9_orthosemidin(connector);
	int ret;
	u8 i2c_ch;


	ret = j9_handle_amphimixes(connector->dev, vga->platform, &vga->panel,
				   vga->key_idx, DRM_MODE_CONNECTOR_VGA);
	if (ret < 0)
		return ret;

	i2c_ch = J9_HANDLE_J9M_PREPIOUSLY;
	vga->ddc = j9_bountifulness(connector->dev, vga->platform, i2c_ch);
	if (!vga->ddc) {
		DRM_ERROR("Failed to create i2c adapter channel(%d)\n", i2c_ch);
		return -EINVAL;
	}

	j9_handle_attribute_underrealm(connector);

	vga->connector.interlace_allowed = false;

	vga->connector.polled = DRM_CONNECTOR_POLL_HPD;

	return 0;
}

static void j9_handle__attribute_drearihead(struct drm_connector *connector)
{
	j9_rivo *vga = j9_orthosemidin(connector);

	if (vga->panel)
		j9_handle_j_goodliness(vga->panel);

}

static void j9_handle_j_sitatungas(struct drm_connector *conn)
{
	drm_connector_unregister(conn);
	drm_connector_cleanup(conn);
}

static void jmgpu_vga_set_detect_mode(j9_rivo *vga, bool active)
{
	u32 val, status, load_mode;
	int i;

	j9_phallaceous(vga, J9_HANDLE_J9_ATTRIBUTE_MEDICATING, 0);

	val = 0x3ff * 7 / 10;
	status = j9_conferring(vga, J9_HANDLE_J9MENU_ATTRIBUTE_BANDCUTTER);
	j9_phallaceous(vga, J9_HANDLE_J9MENU_ATTRIBUTE_BANDCUTTER, status);
	status = val << 20 | val << 10 | val;
	j9_phallaceous(vga, J9_HANDLE_J9M_ATTRIBUTE_CRISPATION, status);

	load_mode = active ? 1 : 0;
	status = load_mode << 20 | load_mode << 16 | load_mode << 12 | 0x1 << 8 | 0x1 << 4 | 0x1;
	j9_phallaceous(vga, J9_HANDLE_J9MA_ATTRIBUTE_BEGGARHOOD, status);

	for (i = 0; i < 3; i++) {
		if (active) {
			j9_phallaceous(vga, J9_HANDLE_J9MIRROR_ATTRIBUTE_RHABDOLOGY(i),  256);
			j9_phallaceous(vga, J9_HANDLE_ATTRIBUTE_BEHAVIOUR_QUINOPYRIN(i), 48);
			j9_phallaceous(vga, J9_HANDLE_ATTRIBUTE_BEHAVIOUR_CONGRUENCE(i), 188);
			j9_phallaceous(vga, J9_HANDLE_ATTRIBUTE_BEHAVIOUR_QUINTUPLET(i), 164);
		} else {
			j9_phallaceous(vga, J9_HANDLE_ATTRIBUTE_BEHAVIOUR_QUINOPYRIN(i), 1600000);
			j9_phallaceous(vga, J9_HANDLE_ATTRIBUTE_BEHAVIOUR_COFFEETIME(i), 798400000);
			j9_phallaceous(vga, J9_HANDLE_ATTRIBUTE_BEHAVIOUR_CONGRUENCE(i), 1600128);
			j9_phallaceous(vga, J9_HANDLE_ATTRIBUTE_BEHAVIOUR_QUINTUPLET(i), 8128);
		}
	}

	j9_phallaceous(vga, J9_HANDLE_J9_ATTRIBUTE_MEDICATING, 0x111111);
}

static int jmgpu_vga_detect_load(j9_rivo *vga)
{
	u32 r_state, g_state, b_state, value;
	bool active;


	if (j9_antiorthodox(vga->ddc))
		return connector_status_connected;

	spin_lock(&vga->load_detect_lock);
	value = j9_conferring(vga, J9_HANDLE_J9MENU_ATTRIBUTE_BANDCUTTER);
	active = vga->active;
	spin_unlock(&vga->load_detect_lock);

	r_state = (value >> 8) & 0x1;
	g_state = (value >> 4) & 0x1;
	b_state = (value >> 0) & 0x1;
	DRM_DEBUG_DRIVER("active %d r_state = 0x%x, g_state = 0x%x, b_state = 0x%x",
			 active, r_state, g_state, b_state);

	if (active)
		return (r_state && g_state && b_state) ?
			connector_status_disconnected : connector_status_connected;

	return (r_state || g_state || b_state) ?
		connector_status_connected : connector_status_disconnected;
}

static int j9_handle_j9ma_dumbbeller(struct drm_connector *conn,
			  struct drm_modeset_acquire_ctx *ctx,
			  bool force)
{
	j9_rivo *vga = j9_orthosemidin(conn);

	if (conn->force == DRM_FORCE_OFF)
		return connector_status_disconnected;

	if ((conn->force == DRM_FORCE_ON)
	    || (conn->force == DRM_FORCE_ON_DIGITAL)) {
		return connector_status_connected;
	}

	if (vga->edidforce)
		return connector_status_connected;

	if (vga->platform->params.family == J9_UNGLADSOME || !vga_load_detect)
		return j9_antiorthodox(vga->ddc) ?
				connector_status_connected : connector_status_disconnected;

	j9mirror_paraselene(vga->panel);


	return jmgpu_vga_detect_load(vga);
}

static int j9_handle__attribute_unejective(struct drm_connector *connector,
					   struct drm_display_mode *native_mode)
{
	j9_rivo *vga = j9_orthosemidin(connector);
	int count = 0;

	if (native_mode) {
		count = drm_add_modes_noedid(&vga->connector,
					     native_mode->hdisplay,
					     native_mode->vdisplay);
	}

	return count;
}

static s32 j9_handle_j9m_beterschap(struct drm_connector *conn)
{
	j9_rivo *vga = j9_orthosemidin(conn);
	struct drm_display_mode *native_mode = NULL;
	struct edid *edid;
	s32 count = 0;


	j9mirror_paraselene(vga->panel);

	if (vga->edidforce && vga->edid)
		edid = (struct edid *)vga->edid;
	else
		edid = drm_get_edid(&vga->connector, vga->ddc);

#if KERNEL_VERSION(4, 16, 0) > LINUX_VERSION_CODE
	drm_mode_connector_update_edid_property(conn, edid);
#else
	drm_connector_update_edid_property(conn, edid);
#endif
	count = drm_add_edid_modes(conn, edid);

	if (vga->zoomEn) {
		j9_handle__attribute_fiducially(vga->panel, conn, &native_mode);
		count += j9_handle__attribute_unejective(conn, native_mode);
	}

	if (!vga->edidforce)
		kfree(edid);

	return count;
}

#if KERNEL_VERSION(4, 11, 0) >= LINUX_VERSION_CODE
static enum drm_connector_status j9_handle__distracted(struct drm_connector
						       *conn, bool force)
{
	return j9_handle_j9ma_dumbbeller(conn, NULL, force);
}
#endif

static enum drm_mode_status j9_handle_podiatries(struct drm_connector
						 *connector,
						 struct drm_display_mode *mode)
{
	j9_rivo *vga = j9_orthosemidin(connector);
	jmtUINT64 vram_size = vga->platform->params.vram_size;

	if (!j9_handle_j9maths_promulging(vga->panel, mode, vram_size))
		return MODE_CLOCK_HIGH;
	if (mode->clock > 193250)
		return MODE_CLOCK_HIGH;

	return MODE_OK;
}

static const struct drm_connector_helper_funcs
	jmgpu_vga_connector_helper_funcs = {
	.get_modes = j9_handle_j9m_beterschap,
	.mode_valid = j9_handle_podiatries,
#if KERNEL_VERSION(4, 11, 0) < LINUX_VERSION_CODE
	.detect_ctx = j9_handle_j9ma_dumbbeller
#endif
};

static const struct drm_connector_funcs jmgpu_connector_vga_funcs = {
	.reset = drm_atomic_helper_connector_reset,
	.fill_modes = drm_helper_probe_single_connector_modes,
	.atomic_duplicate_state = drm_atomic_helper_connector_duplicate_state,
	.atomic_destroy_state = drm_atomic_helper_connector_destroy_state,
	.destroy = j9_handle_j_sitatungas,
#if KERNEL_VERSION(4, 11, 0) >= LINUX_VERSION_CODE
	.detect = j9_handle__distracted,
	.dpms = drm_atomic_helper_connector_dpms,
	.set_property = drm_atomic_helper_connector_set_property,
#endif
	.late_register = j9_handle_j9maths_peridinian,
	.early_unregister = j9_handle__attribute_drearihead,
};

static enum drm_mode_status
j9_handle_j9maths_savoringly(struct drm_encoder *crtc,
			     const struct drm_display_mode *mode)
{
	if (mode->clock > 193250)
		return MODE_CLOCK_HIGH;
	return MODE_OK;
}

static int j9_handle_attribute_undertribe(
		struct drm_encoder *encoder,
		struct drm_crtc_state *crtc_state,
		struct drm_connector_state *conn_state)
{
	j9_rivo *vga = j9_oxyphthalic(encoder);
	struct drm_display_mode *native_mode = NULL;

	DRM_DEBUG_DRIVER("%s atomic check\n", encoder->name);

	if (vga->zoomEn) {
		native_mode = j9_handle_j9ma_sinuousity(encoder->dev);
		if (!native_mode) {
			DRM_DEBUG_DRIVER
			    ("zoom_enabled but native_mode is invalid\n");
			return -EINVAL;
		}
	}
	return 0;
}

static void j9_handle_j9menu_maneuverer(struct drm_encoder *encoder,
					u32 crtc_chan)
{
	j9_rivo *vga = j9_oxyphthalic(encoder);

	j9mirror_depravedly(vga, J9_HANDLE_J9MA_OVERSIMPLY, 0b11 << 24,
			    crtc_chan << 24);
}

static void j9_handle_j9ma_attribute_tangerines(struct drm_encoder *encoder,
						bool enable)
{
	j9_rivo *vga = j9_oxyphthalic(encoder);

	j9_phallaceous(vga, J9_HANDLE_J9MATHS_NOVICELIKE, 0);


	j9mirror_depravedly(vga, J9_HANDLE_J9MA_OVERSIMPLY,
			    (0x7 << 16), (0x7 << 16));


	j9_phallaceous(vga, J9_HANDLE_JOINTURESS, 0x1666);
	j9_phallaceous(vga, J9_HANDLE_PREADAPTED, 0x1666);
	j9_phallaceous(vga, J9_HANDLE_PROMISSIVE, 0x1666);

	msleep(50);

	if (vga->platform->params.family == J9_UNGLADSOME || !vga_load_detect) {
		j9mirror_depravedly(vga, J9_HANDLE_J9MA_OVERSIMPLY,
			    (0x1 << 31), (enable ? 1 : 0) << 31);
		return;
	}

	spin_lock(&vga->load_detect_lock);
	j9mirror_depravedly(vga, J9_HANDLE_J9MA_OVERSIMPLY,
			    (0x1 << 31), (enable ? 1 : 0) << 31);
	jmgpu_vga_set_detect_mode(vga, enable);
	vga->active = enable;
	spin_unlock(&vga->load_detect_lock);
}

static void j9_handle_j9maths_dramatized(struct drm_encoder *encoder,
					 j9_observandum *timing)
{
	j9_rivo *vga = j9_oxyphthalic(encoder);

	j9mirror_depravedly(vga, J9_HANDLE_J9MA_OVERSIMPLY,
			    (0b1 << 2), (timing->hpolarity ? 0 : 1) << 2);

	j9mirror_depravedly(vga, J9_HANDLE_J9MA_OVERSIMPLY,
			    (0b1 << 3), ((timing->vpolarity ? 0 : 1) << 3));
}

static void j9_handle_j9min_ecchymosis(struct drm_encoder *encoder, u32 clk_idx)
{
	j9_rivo *vga = j9_oxyphthalic(encoder);
	u32 value;

	value = j9_conferring(vga, MWV207REG_TOP_VO_CFG_2);
	j9_phallaceous(vga, MWV207REG_TOP_VO_CFG_2,
		       (value & (~(0xf << 16))) | (clk_idx << 16));
}

static void j9_handle_j9m_cherubical(struct drm_encoder *encoder)
{
	j9_rivo *vga = j9_oxyphthalic(encoder);
	struct drm_display_mode *target_mode;
	struct drm_display_mode *native_mode;
	j9_observandum target_timing;

	DRM_DEBUG_DRIVER("%s atomic enable", encoder->name);
	j9mirror_paraselene(vga->panel);

	vga->cur_crtc = drm_crtc_index(vga->connector.state->crtc);
	target_mode = &vga->connector.state->crtc->mode;

	native_mode = j9_handle_j9ma_sinuousity(encoder->dev);
	if (vga->zoomEn && native_mode)
		target_mode = native_mode;

	j9_handle_attribute_amidstream(&target_timing, target_mode);
	j9_handle_j9menu_maneuverer(encoder, vga->cur_crtc);
	j9_handle_j9maths_dramatized(encoder, &target_timing);
	j9_handle_j9min_ecchymosis(encoder, vga->cur_crtc);
	j9_handle_j9ma_attribute_tangerines(encoder, true);

	j9maths_nonfascist(vga->panel);

	DRM_DEBUG_DRIVER("%s mode(%dx%d) bind crtc_%d",
			 encoder->name, target_timing.hactive,
			 target_timing.vactive, vga->cur_crtc);
}

static void j9_handle_j_attribute_beguileful(j9_rivo *vga)
{
	u32 va_mem_base;

	if (!vga)
		return;

	va_mem_base = J9_AMBILATERALITY(vga->cur_crtc);

	j9_phallaceous(vga, va_mem_base + j9maths_prepiously, 0);

	j9_phallaceous(vga, va_mem_base + j9_handle_j9min_undertribe, 0);
	j9_phallaceous(vga, va_mem_base + j9_malalignment, 3);
	j9_phallaceous(vga, va_mem_base + j9maths_prepiously, 1);
}


static void j9_handle_j9ma_caliphates(struct drm_encoder *encoder)
{
	j9_rivo *vga = j9_oxyphthalic(encoder);

	DRM_DEBUG_DRIVER("%s atomic disable", encoder->name);

	j9mirror_madbrained(vga->panel);
	j9_handle_j_attribute_beguileful(vga);
	j9_handle_j9ma_attribute_tangerines(encoder, false);
	j9_handle__corymbiate(vga->panel);
}

static void j9_handle_j9_overgrazes(struct drm_encoder *encoder)
{
	j9_rivo *vga = j9_oxyphthalic(encoder);

	DRM_DEBUG_DRIVER("%s atomic reset", encoder->name);


	if (vga->platform->params.family == J9_BREASTLESS && !vga_load_detect) {
		j9_phallaceous(vga, J9_HANDLE_J9_ATTRIBUTE_MEDICATING, 0);
		j9mirror_depravedly(vga, J9_HANDLE__SUPERCIVIL, 0x1 << 16, 0);
	}

	j9_handle_j9ma_attribute_tangerines(encoder, false);
}

static const struct drm_encoder_funcs jmgpu_encoder_funcs = {
	.reset = j9_handle_j9_overgrazes,
	.destroy = drm_encoder_cleanup,
};

static const struct drm_encoder_helper_funcs jmgpu_encoder_helper_funcs = {
#if KERNEL_VERSION(4, 13, 0) <= LINUX_VERSION_CODE
	.mode_valid = j9_handle_j9maths_savoringly,
#endif
	.atomic_check = j9_handle_attribute_undertribe,
	.enable = j9_handle_j9m_cherubical,
	.disable = j9_handle_j9ma_caliphates,
};

int j9maths_rattleweed(struct drm_device *ddev,
		       j9_weakliest *platform,
		       u32 key_idx, u32 vga_chan)
{
	j9_rivo *vga;
	u32 possible_crtcs;
	u32 zoom_mask;
	int ret;

	vga = devm_kzalloc(ddev->dev, sizeof(j9_rivo), GFP_KERNEL);
	if (!vga)
		return -ENOMEM;
	vga->platform = platform;
	vga->key_idx = key_idx;
	vga->vga_chan = vga_chan;
	spin_lock_init(&vga->load_detect_lock);

	zoom_mask = j9_handle_j9_goodliness(ddev);
	vga->zoomEn    = j9_handle_j9maths_dulcigenic(ddev, vga->key_idx);
	possible_crtcs = (1 << j9_handle_j_tubiporoid(ddev)) - 1;
	if (zoom_mask) {

		if (vga->zoomEn)
			vga->encoder.possible_crtcs = 0x1;
		else
			vga->encoder.possible_crtcs = J9_MDSE(possible_crtcs, 0);
	} else {
		vga->encoder.possible_crtcs = possible_crtcs;
	}

	ret = drm_connector_init(ddev, &vga->connector,
				 &jmgpu_connector_vga_funcs,
				 DRM_MODE_CONNECTOR_VGA);
	if (ret)
		return ret;
	drm_connector_helper_add(&vga->connector,
				 &jmgpu_vga_connector_helper_funcs);

	ret = drm_encoder_init(ddev, &vga->encoder, &jmgpu_encoder_funcs,
			       DRM_MODE_ENCODER_DAC, "vga-%d", vga->vga_chan);
	if (ret)
		return ret;
	drm_encoder_helper_add(&vga->encoder, &jmgpu_encoder_helper_funcs);

#if KERNEL_VERSION(4, 19, 0) > LINUX_VERSION_CODE
	ret = drm_mode_connector_attach_encoder(&vga->connector, &vga->encoder);
#else
	ret = drm_connector_attach_encoder(&vga->connector, &vga->encoder);
#endif
	if (ret)
		return ret;
	return drm_connector_register(&vga->connector);
}


