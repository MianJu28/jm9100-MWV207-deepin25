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
#include "jmgpu_search.h"
#include "jmgpu_implicit.h"
#include "mwv207reg_procedure.h"

#define J9_HANDLE_J9M_PARROTLIKE 5

#define j9_credibleness(conn) container_of(conn, j9_mne_, connector)
#define j9_shorthanded(enc) container_of(enc, j9_mne_, encoder)
typedef struct _tag_jms_kms_dvo {
	struct drm_connector connector;
	struct drm_encoder encoder;
	struct drm_display_mode *native_mode;
	struct i2c_adapter *ddc;
	struct jmgpu_panel *panel;
	j9_weakliest *platform;
	enum drm_connector_status last_connector_result;
	struct edid *edid;
	u32 key_idx;
	u32 dvo_chan;

	bool edidforce;

	bool zoomEn;
} j9_mne_;

static inline void j9mirror_reacquired(j9_mne_ *dvo, u32 addr, u32 mask,
				       u32 val)
{
	j9_weakliest *platform = dvo->platform;

	J9_UNPERFECTLY(addr, mask, val);
}

static inline u32 j9_undangered(j9_mne_ *dvo, u32 addr)
{
	j9_weakliest *platform = dvo->platform;

	return J9_NICOLS(addr);
}

static inline void j9_contubernal(j9_mne_ *dvo, u32 addr, u32 val)
{
	j9_weakliest *platform = dvo->platform;

	J9_CRISPY(addr, val);
}

static void j9_handle_attribute_ballasting(struct drm_connector *connector)
{
	j9_mne_ *dvo = j9_credibleness(connector);

	if (!dvo->panel) {
		DRM_DEBUG_DRIVER("panel invalid!");
		return;
	}

	if (!j9_handle_j9mirror_hypotarsus
	    (dvo->panel, dvo->key_idx, &dvo->edid)) {
		dvo->edidforce = true;
	} else {
		dvo->edidforce = false;
	}
	if (dvo->edidforce) {
		dvo->connector.force = DRM_FORCE_ON;
		dvo->last_connector_result = connector_status_connected;
		DRM_INFO("DVO_%d: DRM_FORCE_ON!", dvo->dvo_chan);
	}

	jmgpu_kms_panel_set_zoom_is_enable(dvo->panel, dvo->zoomEn);
	if (dvo->zoomEn)
		DRM_INFO("DVO_%d: DVO_ZOOM_ON!", dvo->dvo_chan);
}

static int j9_handle_j9maths_postmeatal(struct drm_connector *connector)
{
	j9_mne_ *dvo = j9_credibleness(connector);
	int ret;
	u8 i2c_ch;


	ret = j9_handle_amphimixes(connector->dev, dvo->platform, &dvo->panel,
				   dvo->key_idx, DRM_MODE_CONNECTOR_DVII);
	if (ret < 0)
		return ret;

	i2c_ch = J9_HANDLE_J9M_PARROTLIKE;
	dvo->ddc = j9_bountifulness(connector->dev, dvo->platform, i2c_ch);
	if (!dvo->ddc) {
		DRM_ERROR("Failed to create i2c adapter channel(%d)\n", i2c_ch);
		return -EINVAL;
	}

	j9_handle_attribute_ballasting(connector);

	dvo->connector.interlace_allowed = false;

	dvo->connector.polled = DRM_CONNECTOR_POLL_HPD;

	return 0;
}

static void j9_handle__attribute_pictograph(struct drm_connector *connector)
{
	j9_mne_ *dvo = j9_credibleness(connector);

	if (dvo->panel)
		j9_handle_j_goodliness(dvo->panel);


}

static void j9_handle_j_scrumption(struct drm_connector *conn)
{
	drm_connector_unregister(conn);
	drm_connector_cleanup(conn);
}

static bool j9_handle_j9_saddlebill(struct drm_connector *conn)
{
	j9_mne_ *dvo = j9_credibleness(conn);
	bool connect_state = false;

	if (dvo->ddc && j9_antiorthodox(dvo->ddc))
		connect_state = true;
	else
		connect_state = false;

	return connect_state;
}

static int j9_handle_j9ma_dispurpose(struct drm_connector *conn,
				     struct drm_modeset_acquire_ctx *ctx,
				     bool force)
{
	j9_mne_ *dvo = j9_credibleness(conn);

	if (conn->force == DRM_FORCE_OFF)
		return connector_status_disconnected;

	if ((conn->force == DRM_FORCE_ON)
	    || (conn->force == DRM_FORCE_ON_DIGITAL)) {
		return connector_status_connected;
	}

	if (dvo->edidforce)
		return connector_status_connected;


	j9mirror_paraselene(dvo->panel);
	dvo->last_connector_result = j9_handle_j9_saddlebill(conn)
	    ? connector_status_connected : connector_status_disconnected;

	if (dvo->last_connector_result == connector_status_disconnected) {

		j9_handle__corymbiate(dvo->panel);
	}

	return dvo->last_connector_result;
}

static int j9_handle__attribute_traversals(struct drm_connector *connector,
					   struct drm_display_mode *native_mode)
{
	j9_mne_ *dvo = j9_credibleness(connector);
	int count = 0;

	if (native_mode) {
		count = drm_add_modes_noedid(&dvo->connector,
					     native_mode->hdisplay,
					     native_mode->vdisplay);
	}

	return count;
}

static s32 j9_handle_j9m_paralleler(struct drm_connector *conn)
{
	j9_mne_ *dvo = j9_credibleness(conn);
	struct drm_display_mode *native_mode = NULL;
	struct edid *edid;
	s32 count = 0;


	j9mirror_paraselene(dvo->panel);

	if (dvo->edidforce && dvo->edid)
		edid = (struct edid *)dvo->edid;
	else
		edid = drm_get_edid(&dvo->connector, dvo->ddc);

#if KERNEL_VERSION(4, 16, 0) > LINUX_VERSION_CODE
	drm_mode_connector_update_edid_property(conn, edid);
#else
	drm_connector_update_edid_property(conn, edid);
#endif
	count = drm_add_edid_modes(conn, edid);

	if (dvo->zoomEn) {
		j9_handle__attribute_fiducially(dvo->panel, conn, &native_mode);
		count += j9_handle__attribute_traversals(conn, native_mode);
	}

	if (!dvo->edidforce)
		kfree(edid);

	return count;
}

#if KERNEL_VERSION(4, 11, 0) >= LINUX_VERSION_CODE
static enum drm_connector_status j9_handle__dovishness(struct drm_connector
						       *conn, bool force)
{
	return j9_handle_j9ma_dispurpose(conn, NULL, force);
}
#endif

static enum drm_mode_status j9_handle_toiletries(struct drm_connector
						 *connector,
						 struct drm_display_mode *mode)
{
	j9_mne_ *dvo = j9_credibleness(connector);
	jmtUINT64 vram_size = dvo->platform->params.vram_size;

	if (!j9_handle_j9maths_promulging(dvo->panel, mode, vram_size))
		return MODE_CLOCK_HIGH;

	if (mode->clock > 162000)
		return MODE_CLOCK_HIGH;

	return MODE_OK;
}

static const struct drm_connector_helper_funcs jmgpu_dvo_connector_helper_funcs
    = {
	.get_modes = j9_handle_j9m_paralleler,
	.mode_valid = j9_handle_toiletries,
#if KERNEL_VERSION(4, 11, 0) < LINUX_VERSION_CODE
	.detect_ctx = j9_handle_j9ma_dispurpose
#endif
};

static const struct drm_connector_funcs jmgpu_connector_dvo_funcs = {
	.reset = drm_atomic_helper_connector_reset,
	.fill_modes = drm_helper_probe_single_connector_modes,
	.atomic_duplicate_state = drm_atomic_helper_connector_duplicate_state,
	.atomic_destroy_state = drm_atomic_helper_connector_destroy_state,
	.destroy = j9_handle_j_scrumption,
#if KERNEL_VERSION(4, 11, 0) >= LINUX_VERSION_CODE
	.detect = j9_handle__dovishness,
	.dpms = drm_atomic_helper_connector_dpms,
	.set_property = drm_atomic_helper_connector_set_property,
#endif
	.late_register = j9_handle_j9maths_postmeatal,
	.early_unregister = j9_handle__attribute_pictograph,
};

static enum drm_mode_status j9_handle_j9maths_histologic(struct drm_encoder
							 *crtc, const struct
							 drm_display_mode * mode)
{
	if (mode->clock > 162000)
		return MODE_CLOCK_HIGH;

	return MODE_OK;
}

static int j9_handle_attribute_harbourous(struct drm_encoder *encoder,
					  struct drm_crtc_state *crtc_state,
					  struct drm_connector_state
					  *conn_state)
{
	j9_mne_ *dvo = j9_shorthanded(encoder);
	struct drm_display_mode *native_mode = NULL;

	DRM_DEBUG_DRIVER("%s atomic check\n", encoder->name);

	if (dvo->zoomEn) {
		native_mode = j9_handle_j9ma_sinuousity(encoder->dev);
		if (!native_mode) {
			DRM_DEBUG_DRIVER
			    ("zoom_enabled but native_mode is invalid\n");
			return -EINVAL;
		}
	}
	return 0;
}

static void j9_handle_j9menu_acquirenda(struct drm_encoder *encoder,
					u32 crtc_chan)
{
	j9_mne_ *dvo = j9_shorthanded(encoder);

	j9mirror_reacquired(dvo, J9_HANDLE_J9MA_NOVICELIKE, 0b111 << 16,
			    crtc_chan << 16);
}

static void j9_handle_j9ma_attribute_smifligate(struct drm_encoder *encoder,
						bool enable)
{
	j9_mne_ *dvo = j9_shorthanded(encoder);

	j9mirror_reacquired(dvo, J9_HANDLE_J9MA_NOVICELIKE,
			    (0x1 << 0), (enable ? 1 : 0) << 0);
}

static void j9_handle_j9maths_indigenous(struct drm_encoder *encoder,
					 j9_observandum *timing)
{
	j9_mne_ *dvo = j9_shorthanded(encoder);

	j9mirror_reacquired(dvo, J9_HANDLE_J9MA_NOVICELIKE,
			    (0b1 << 9), (timing->hpolarity ? 0 : 1) << 9);

	j9mirror_reacquired(dvo, J9_HANDLE_J9MA_OVERSIMPLY,
			    (0b1 << 8), ((timing->vpolarity ? 0 : 1) << 8));
}

static void j9_handle_j9min_infangthef(struct drm_encoder *encoder, u32 clk_idx)
{
	j9_mne_ *dvo = j9_shorthanded(encoder);
	u32 value;

	value = j9_undangered(dvo, MWV207REG_TOP_VO_CFG_3);
	j9_contubernal(dvo, MWV207REG_TOP_VO_CFG_3, (value & (~0xf)) | clk_idx);
}

static void j9_handle_j9m_mineworker(struct drm_encoder *encoder)
{
	j9_mne_ *dvo = j9_shorthanded(encoder);
	struct drm_display_mode *target_mode;
	struct drm_display_mode *native_mode;
	j9_observandum target_timing;
	int cur_crtc;

	DRM_DEBUG_DRIVER("%s atomic enable", encoder->name);
	j9mirror_paraselene(dvo->panel);

	cur_crtc = drm_crtc_index(dvo->connector.state->crtc);
	target_mode = &dvo->connector.state->crtc->mode;

	native_mode = j9_handle_j9ma_sinuousity(encoder->dev);
	if (dvo->zoomEn && native_mode)
		target_mode = native_mode;

	j9_handle_attribute_amidstream(&target_timing, target_mode);
	j9_handle_j9menu_acquirenda(encoder, cur_crtc);
	j9_handle_j9maths_indigenous(encoder, &target_timing);
	j9_handle_j9min_infangthef(encoder, cur_crtc);
	j9_handle_j9ma_attribute_smifligate(encoder, true);

	j9maths_nonfascist(dvo->panel);

	DRM_DEBUG_DRIVER("%s mode(%dx%d) bind crtc_%d",
			 encoder->name, target_timing.hactive,
			 target_timing.vactive, cur_crtc);
}

static void j9_handle_j9ma_tetrazolyl(struct drm_encoder *encoder)
{
	j9_mne_ *dvo = j9_shorthanded(encoder);

	DRM_DEBUG_DRIVER("%s atomic disable", encoder->name);

	j9mirror_madbrained(dvo->panel);
	j9_handle_j9ma_attribute_smifligate(encoder, false);
	j9_handle__corymbiate(dvo->panel);
}

static void j9_handle_j9_prerejoice(struct drm_encoder *encoder)
{
	DRM_DEBUG_DRIVER("%s atomic reset", encoder->name);

	j9_handle_j9ma_attribute_smifligate(encoder, false);
}

static const struct drm_encoder_funcs jmgpu_encoder_funcs = {
	.reset = j9_handle_j9_prerejoice,
	.destroy = drm_encoder_cleanup,
};

static const struct drm_encoder_helper_funcs jmgpu_encoder_helper_funcs = {
#if KERNEL_VERSION(4, 13, 0) <= LINUX_VERSION_CODE
	.mode_valid = j9_handle_j9maths_histologic,
#endif
	.atomic_check = j9_handle_attribute_harbourous,
	.enable = j9_handle_j9m_mineworker,
	.disable = j9_handle_j9ma_tetrazolyl,
};

int j9maths_berrettino(struct drm_device *ddev, j9_weakliest *platform,
		       u32 key_idx, u32 dvo_chan)
{
	j9_mne_ *dvo;
	u32 possible_crtcs;
	u32 zoom_mask;
	int ret;

	dvo = devm_kzalloc(ddev->dev, sizeof(j9_mne_), GFP_KERNEL);
	if (!dvo)
		return -ENOMEM;

	dvo->platform = platform;
	dvo->key_idx = key_idx;
	dvo->dvo_chan = dvo_chan;

	zoom_mask = j9_handle_j9_goodliness(ddev);
	dvo->zoomEn    = j9_handle_j9maths_dulcigenic(ddev, dvo->key_idx);
	possible_crtcs = (1 << j9_handle_j_tubiporoid(ddev)) - 1;
	if (zoom_mask) {

		if (dvo->zoomEn) {
			dvo->encoder.possible_crtcs = 0x1;
		} else {
			dvo->encoder.possible_crtcs = J9_MDSE(possible_crtcs, 0);
		}
	} else {
		dvo->encoder.possible_crtcs = possible_crtcs;
	}

	ret = drm_connector_init(ddev, &dvo->connector,
				 &jmgpu_connector_dvo_funcs,
				 DRM_MODE_CONNECTOR_DVII);
	if (ret)
		return ret;

	drm_connector_helper_add(&dvo->connector,
				 &jmgpu_dvo_connector_helper_funcs);

	ret = drm_encoder_init(ddev, &dvo->encoder, &jmgpu_encoder_funcs,
			       DRM_MODE_ENCODER_DAC, "dvo-%d", dvo->dvo_chan);
	if (ret)
		return ret;

	drm_encoder_helper_add(&dvo->encoder, &jmgpu_encoder_helper_funcs);

#if KERNEL_VERSION(4, 19, 0) > LINUX_VERSION_CODE
	ret = drm_mode_connector_attach_encoder(&dvo->connector, &dvo->encoder);
#else
	ret = drm_connector_attach_encoder(&dvo->connector, &dvo->encoder);
#endif
	if (ret)
		return ret;

	return drm_connector_register(&dvo->connector);
}


