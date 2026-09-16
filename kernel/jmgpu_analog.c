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
#include <drm/drm_crtc.h>
#include <drm/drm_crtc_helper.h>
#include <drm/drm_property.h>
#include <linux/version.h>
#if KERNEL_VERSION(5, 0, 0) <= LINUX_VERSION_CODE
#include <drm/drm_probe_helper.h>
#endif
#include <drm/drm_atomic_helper.h>
#if KERNEL_VERSION(4, 6, 0) < LINUX_VERSION_CODE
#include <drm/drm_print.h>
#endif
#include "jmgpu_analog.h"
#include "jmgpu_nemyry.h"
#include <drm/drm_modes.h>
#include <drm/drm_edid.h>

typedef enum tag_jms_vds_config_type {
	JMV_VDS_CONN_NONE,
	JMV_VDS_CONN_EDID,
	JMV_VDS_CONN_MODELINE,
	JMV_VDS_CONN_STANDARD_RANGE,
	JMV_VDS_CONN_UNKNOWN
} jms_vds_config_type;

typedef struct tag_jms_vds_modeline {
	uint16_t hsize;
	uint16_t vsize;
	uint16_t fresh;
} jms_vds_modeline;

typedef struct tag_jms_vds_config {
	jms_vds_config_type type;
	union {
		char edid[512];
		struct {
			jms_vds_modeline modes[16];
			size_t mode_num;
		};
		struct {
			int min_width;
			int min_height;
			int max_width;
			int max_height;
		};
	};
} jms_vds_config;

static struct drm_property *jmvds_prop;

#define conn_to_jms_vconn(conn) container_of(conn, jms_vconn, connector)
#define enc_to_jms_vconn(enc) container_of(enc, jms_vconn, encoder)
typedef struct _tag_jms_kms_vconn {
	struct drm_connector connector;
	struct drm_encoder encoder;
	j9_weakliest *platform;
	enum drm_connector_status last_connector_result;
	struct edid *edid;
	u32 key_idx;
	u32 vconn_chan;
	struct drm_property_blob *jmvds_blob;
	bool enabled;
} jms_vconn;


static int j9_handle_attribute_biaxiality(struct drm_connector *connector)
{
	jms_vconn *vconn = conn_to_jms_vconn(connector);


	vconn->connector.interlace_allowed = false;

	vconn->connector.polled = DRM_CONNECTOR_POLL_HPD;

	return 0;
}

static void j9_handle_j9_attribute_magazinish(struct drm_connector *connector)
{

}

static void j9_handle_j9m_magazinish(struct drm_connector *conn)
{
	drm_connector_unregister(conn);
	drm_connector_cleanup(conn);
}

static int j9_handle_j9menu_biaxiality(struct drm_connector *conn,
				       struct drm_modeset_acquire_ctx *ctx,
				       bool force)
{
	jms_vconn *vconn = conn_to_jms_vconn(conn);

	if (conn->force == DRM_FORCE_OFF)
		return connector_status_disconnected;

	if ((conn->force == DRM_FORCE_ON) ||
	    (conn->force == DRM_FORCE_ON_DIGITAL)) {
		return connector_status_connected;
	}

	vconn->last_connector_result = vconn->enabled ?
					       connector_status_connected :
					       connector_status_disconnected;

	return vconn->last_connector_result;
}

static s32 j9_handle_j9min_biaxiality(struct drm_connector *conn)
{
	s32 i = 0;
	s32 count = 0;
	jms_vconn *vconn = conn_to_jms_vconn(conn);
	jms_vds_config *conf = (jms_vds_config *)vconn->jmvds_blob->data;

	if (!conf) {
		DRM_ERROR("conn conf should not be NULL at get mode!");
		goto ERR_OUT;
	}

	switch (conf->type) {
	case JMV_VDS_CONN_EDID:
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 16, 0)
		drm_mode_connector_update_edid_property(
			conn, (struct edid *)conf->edid);
#else
		drm_connector_update_edid_property(conn,
						   (struct edid *)conf->edid);
#endif
		count = drm_add_edid_modes(conn, (struct edid *)conf->edid);
		break;
	case JMV_VDS_CONN_STANDARD_RANGE:
		count = drm_add_modes_noedid(conn, conf->max_width,
					     conf->max_height);
		break;
	case JMV_VDS_CONN_MODELINE:
		for (i = 0; i < conf->mode_num; i++) {
			jms_vds_modeline *modeline;
			struct drm_display_mode *mode = NULL;
			modeline = &conf->modes[i];
			mode = drm_mode_find_dmt(conn->dev, modeline->hsize, modeline->vsize, modeline->fresh, false);
			if (mode == NULL) {
				DRM_ERROR("failed to find mode\n");
				continue;
			}
			drm_mode_probed_add(conn, mode);
		}
		count = conf->mode_num;
		break;
	default:
		DRM_DEBUG_DRIVER("unknown conn config type %d!", conf->type);
		goto ERR_OUT;
	}
	return count;

ERR_OUT:
	return drm_add_modes_noedid(conn, 4096, 2160);
}

#if KERNEL_VERSION(4, 11, 0) >= LINUX_VERSION_CODE
static enum drm_connector_status
j9_handle_j9_magazinish(struct drm_connector *conn, bool force)
{
	return j9_handle_j9menu_biaxiality(conn, NULL, force);
}
#endif

static enum drm_mode_status
j9_handle_j_magazinish(struct drm_connector *connector,
		       struct drm_display_mode *mode)
{
	jms_vconn *vconn = conn_to_jms_vconn(connector);
	jms_vds_config *conf = (jms_vds_config *)vconn->jmvds_blob->data;

	if (mode->hdisplay > JMD_VIRT_MAX_WIDTH) {
		return MODE_HSYNC_WIDE;
	}
	if (mode->vdisplay > JMD_VIRT_MAX_HEIGHT) {
		return MODE_VSYNC_WIDE;
	}
	if (conf->type == JMV_VDS_CONN_STANDARD_RANGE) {
		if (mode->hdisplay < conf->min_width) {
			return MODE_HSYNC_NARROW;
		}
		if (mode->vdisplay < conf->min_height) {
			return MODE_VSYNC_NARROW;
		}
	}

	if ((mode->hdisplay * 4 % 64) != 0)
		return MODE_BAD_WIDTH;

	if (mode->clock > 594000)
		return MODE_CLOCK_HIGH;

	return MODE_OK;
}

#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 13, 0))
static bool drm_property_replace_blob(struct drm_property_blob **blob,
					struct drm_property_blob *new_blob)
{
	struct drm_property_blob *old_blob = *blob;

	if (old_blob == new_blob)
		return false;

	drm_property_unreference_blob(old_blob);
	if (new_blob)
		drm_property_reference_blob(new_blob);
	*blob = new_blob;
	return true;
}
#endif

static int j9_handle__attribute_biaxiality(struct drm_connector *connector,
					   struct drm_connector_state *state,
					   struct drm_property *property,
					   uint64_t val)
{
	struct drm_property_blob *blob;
	struct drm_device *dev = connector->dev;
	jms_vconn *vconn = conn_to_jms_vconn(connector);

	if (property == jmvds_prop) {
		DRM_INFO("JMVDS PROP!");
		blob = drm_property_lookup_blob(dev, val);
		if (!blob) {
			DRM_ERROR("invalid blob_id");
			return -EINVAL;
		}
		drm_property_replace_blob(&vconn->jmvds_blob, blob);
		if (((jms_vds_config *)(vconn->jmvds_blob->data))->type ==
		    JMV_VDS_CONN_NONE) {
			vconn->enabled = false;
		} else {
			vconn->enabled = true;
		}
	} else {
		DRM_ERROR("%s, not jmvds prop!", property->name);
		return -EINVAL;
	}
	return 0;
}

static int j9_handle__attribute_magazinish(struct drm_connector *connector,
					   const struct drm_connector_state *state,
					   struct drm_property *property,
					   uint64_t *val)
{
	jms_vconn *vconn = conn_to_jms_vconn(connector);
	if (property == jmvds_prop) {
		*val = vconn->jmvds_blob->base.id;
		DRM_DEBUG_DRIVER("%s JMVDS PROP id=%lld! \n", __func__, *val);
	}
	return 0;
}

static const struct drm_connector_helper_funcs jmgpu_vconn_connector_helper_funcs = {
	.get_modes = j9_handle_j9min_biaxiality,
	.mode_valid = j9_handle_j_magazinish,
#if KERNEL_VERSION(4, 11, 0) < LINUX_VERSION_CODE
	.detect_ctx = j9_handle_j9menu_biaxiality
#endif
};

static const struct drm_connector_funcs jmgpu_connector_vconn_funcs = {
	.reset = drm_atomic_helper_connector_reset,
	.fill_modes = drm_helper_probe_single_connector_modes,
	.atomic_duplicate_state = drm_atomic_helper_connector_duplicate_state,
	.atomic_destroy_state = drm_atomic_helper_connector_destroy_state,
	.destroy = j9_handle_j9m_magazinish,
#if KERNEL_VERSION(4, 11, 0) >= LINUX_VERSION_CODE
	.detect = j9_handle_j9_magazinish,
	.dpms = drm_atomic_helper_connector_dpms,
	.set_property = drm_atomic_helper_connector_set_property,
#endif
	.atomic_set_property = j9_handle__attribute_biaxiality,
	.atomic_get_property = j9_handle__attribute_magazinish,
	.late_register = j9_handle_attribute_biaxiality,
	.early_unregister = j9_handle_j9_attribute_magazinish,
};

static enum drm_mode_status
j9_handle_attribute_magazinish(struct drm_encoder *crtc,
			       const struct drm_display_mode *mode)
{
	if (mode->clock > 594000)
		return MODE_CLOCK_HIGH;

	return MODE_OK;
}

static int
j9_handle_j_attribute_magazinish(struct drm_encoder *encoder,
				 struct drm_crtc_state *crtc_state,
				 struct drm_connector_state *conn_state)
{
	DRM_DEBUG_DRIVER("%s atomic check\n", encoder->name);

	return 0;
}

static void j9_handle_j9min_magazinish(struct drm_encoder *encoder)
{
	DRM_DEBUG_DRIVER("%s atomic enable", encoder->name);
}

static void j9_handle_j9menu_magazinish(struct drm_encoder *encoder)
{
	DRM_DEBUG_DRIVER("%s atomic disable", encoder->name);
}

static void j9_handle_j9ma_magazinish(struct drm_encoder *encoder)
{
	DRM_DEBUG_DRIVER("%s atomic reset", encoder->name);
}

static const struct drm_encoder_funcs jmgpu_encoder_funcs = {
	.reset = j9_handle_j9ma_magazinish,
	.destroy = drm_encoder_cleanup,
};

static const struct drm_encoder_helper_funcs jmgpu_encoder_helper_funcs = {
#if KERNEL_VERSION(4, 13, 0) <= LINUX_VERSION_CODE
	.mode_valid = j9_handle_attribute_magazinish,
#endif
	.atomic_check = j9_handle_j_attribute_magazinish,
	.enable = j9_handle_j9min_magazinish,
	.disable = j9_handle_j9menu_magazinish,
};

int j9_handle_magazinish_(struct drm_device *ddev, j9_weakliest *platform,
			 u32 key_idx, u32 vconn_chan)
{
	jms_vconn *vconn;
	jms_vds_config *conf;
	u32 possible_crtcs;
	int ret;

	vconn = devm_kzalloc(ddev->dev, sizeof(jms_vconn), GFP_KERNEL);
	if (!vconn)
		return -ENOMEM;

	vconn->platform = platform;
	vconn->key_idx = key_idx;
	vconn->vconn_chan = vconn_chan;

	possible_crtcs = (1 << j9_handle_j_tubiporoid(ddev)) - 1;
	vconn->encoder.possible_crtcs = possible_crtcs;

	ret = drm_connector_init(ddev, &vconn->connector,
				 &jmgpu_connector_vconn_funcs,
				 DRM_MODE_CONNECTOR_VIRTUAL);
	if (ret)
		return ret;

	vconn->enabled = true;


	if (!jmvds_prop) {

		jmvds_prop = drm_property_create(ddev, DRM_MODE_PROP_BLOB,
						 "JMVDS", 0);
		if (!jmvds_prop) {
			return -ENOMEM;
		}
	}

	vconn->jmvds_blob =
		drm_property_create_blob(ddev, sizeof(jms_vds_config), NULL);
	if (!vconn->jmvds_blob) {
		DRM_ERROR("jmvds create blob failed!");
		return PTR_ERR(vconn->jmvds_blob);
	}
	conf = (jms_vds_config *)vconn->jmvds_blob->data;
	conf->type = JMV_VDS_CONN_NONE;
	drm_object_attach_property(&vconn->connector.base, jmvds_prop,
				   vconn->jmvds_blob->base.id);

	drm_connector_helper_add(&vconn->connector,
				 &jmgpu_vconn_connector_helper_funcs);

	ret = drm_encoder_init(ddev, &vconn->encoder, &jmgpu_encoder_funcs,
			       DRM_MODE_ENCODER_VIRTUAL, "vconn-%d",
			       vconn->vconn_chan);
	if (ret)
		return ret;

	drm_encoder_helper_add(&vconn->encoder, &jmgpu_encoder_helper_funcs);

#if KERNEL_VERSION(4, 19, 0) > LINUX_VERSION_CODE
	ret = drm_mode_connector_attach_encoder(&vconn->connector,
						&vconn->encoder);
#else
	ret = drm_connector_attach_encoder(&vconn->connector, &vconn->encoder);
#endif
	if (ret)
		return ret;

	return drm_connector_register(&vconn->connector);
}


