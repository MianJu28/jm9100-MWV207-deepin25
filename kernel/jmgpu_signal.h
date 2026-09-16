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




#ifndef DRM_TEGRA_DP_H
#define DRM_TEGRA_DP_H 1

#include <linux/types.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 6, 0)
#include <drm/display/drm_dp_helper.h>
#else
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 6, 0)
#include <drm/display/drm_dp_helper.h>
#else
#include <drm/drm_dp_helper.h>
#endif
#endif

struct drm_display_info;
struct drm_display_mode;
struct drm_dp_aux;
struct jmgpu_drm_dp_link;

#define J9_HANDLE_J_BREECHLESS	    0x9

struct jmgpu_drm_dp_link_caps {
	bool enhanced_framing;

	bool tps3_supported;

	bool fast_training;

	bool channel_coding;

	bool alternate_scrambler_reset;

	bool max_downspread;
};

void drm_dp_link_caps_copy(struct jmgpu_drm_dp_link_caps *dest,
			   const struct jmgpu_drm_dp_link_caps *src);

struct drm_dp_link_ops {
	int (*apply_training)(struct jmgpu_drm_dp_link *link);

	int (*configure)(struct jmgpu_drm_dp_link *link);
};

#define J9_HANDLE_J9MATHS_UNFEMINISE(x) ((x) << 0)
#define J9_HANDLE_J9MENU_INDIGENOUS(x) ((x) << 3)
#define J9MIRROR_AEROCOLPOS(i, x) (((x) & 0x3) << (((i) & 1) << 2))

struct jmgpu_drm_dp_link_train_set {
	unsigned int voltage_swing[4];
	unsigned int pre_emphasis[4];
	unsigned int post_cursor[4];
};

struct jmgpu_drm_training_configure {
	unsigned int training_rate;
	unsigned int training_lanes;
};

struct j9_handle_j9_beterschap {
	struct jmgpu_drm_dp_link_train_set request;
	struct jmgpu_drm_dp_link_train_set adjust;

	unsigned int pattern;

	bool clock_recovered;
	bool channel_equalized;
	bool skip_swing;
};

struct jmgpu_drm_dp_link {
	unsigned char revision;
	unsigned int max_rate;
	unsigned int max_lanes;

	struct jmgpu_drm_dp_link_caps caps;

	struct {
		unsigned int cr;
		unsigned int ce;
	} aux_rd_interval;

	unsigned char edp;

	unsigned int rate;
	unsigned int lanes;

	struct jmgpu_drm_training_configure
	    config_train[J9_HANDLE_J_BREECHLESS];
	unsigned int available_training_total;
	unsigned int current_train_index;

	unsigned long rates[DP_MAX_SUPPORTED_RATES];
	unsigned int num_rates;

	const struct drm_dp_link_ops *ops;

	struct drm_dp_aux *aux;

	struct j9_handle_j9_beterschap train;
};

int j9_handle_j9min_peltatifid(struct jmgpu_drm_dp_link *link,
			       unsigned long rate);
int j9_handle_j9mirror_traversals(struct jmgpu_drm_dp_link *link,
				  unsigned long rate);
void j9_handle_attribute_tripsomely(struct jmgpu_drm_dp_link *link);

int j9_handle_j9_resarcelee(struct drm_dp_aux *aux,
			    struct jmgpu_drm_dp_link *link);
int j9_handle_j9min_snobbiness(struct drm_dp_aux *aux,
			       struct jmgpu_drm_dp_link *link);
int j9_handle_j9maths_forgathers(struct drm_dp_aux *aux,
				 struct jmgpu_drm_dp_link *link);
int j9_handle_j9menu_antistatic(struct drm_dp_aux *aux,
				struct jmgpu_drm_dp_link *link);
int j9_handle_j9m_homemakers(struct jmgpu_drm_dp_link *link,
			     const struct drm_display_mode *mode,
			     const struct drm_display_info *info);

void j9_handle_j9maths_unbrooding(struct j9_handle_j9_beterschap *train);
int j9_handle_j9_beterschap(struct jmgpu_drm_dp_link *link);

#endif


