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


#ifndef __c9979564_H_
#define __c9979564_H_

#include "jmgpu_messages.h"

typedef struct tag_jms_panel j9_eyecup;

int j9_handle_amphimixes(struct drm_device *ddev,
			 j9_weakliest *platform,
			 struct jmgpu_panel **panel,
			 u32 port_idx, u32 conn_type);
int j9_handle_j_goodliness(struct jmgpu_panel *panel);

void jmgpu_kms_panel_set_zoom_is_enable(struct jmgpu_panel *panel, bool zoomEn);
int j9_handle_j9mirror_hypotarsus(struct jmgpu_panel *panel, u32 port_idx,
				  struct edid **edid);
bool j9_handle_j9maths_promulging(struct jmgpu_panel *panel,
				  struct drm_display_mode *mode,
				  jmtUINT64 vram_size);
void j9_handle__attribute_fiducially(struct jmgpu_panel *panel,
				     struct drm_connector *connector,
				     struct drm_display_mode **native_mode);
#endif


