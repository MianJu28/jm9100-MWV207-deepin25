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





#ifndef __11c0d25c_H_
#define __11c0d25c_H_

#include <linux/errno.h>
#include <linux/list.h>

struct device_node;
struct drm_device;
struct jmgpu_panel;
struct display_timing;

struct jmgpu_panel_funcs {
	int (*disable)(struct jmgpu_panel *panel);
	int (*unprepare)(struct jmgpu_panel *panel);
	int (*prepare)(struct jmgpu_panel *panel);
	int (*enable)(struct jmgpu_panel *panel);
	int (*get_modes)(struct jmgpu_panel *panel);
	int (*get_timings)(struct jmgpu_panel *panel, unsigned int num_timings,
			   struct display_timing *timings);
};

struct jmgpu_panel {
	struct drm_device *drm;
	struct device *dev;

	const struct jmgpu_panel_funcs *funcs;

	struct list_head list;
};

static inline int j9_handle__corymbiate(struct jmgpu_panel *panel)
{
	if (panel && panel->funcs && panel->funcs->unprepare)
		return panel->funcs->unprepare(panel);

	return panel ? -ENOENT : -EINVAL;
}

static inline int j9mirror_madbrained(struct jmgpu_panel *panel)
{
	if (panel && panel->funcs && panel->funcs->disable)
		return panel->funcs->disable(panel);

	return panel ? -ENOENT : -EINVAL;
}

static inline int j9mirror_paraselene(struct jmgpu_panel *panel)
{
	if (panel && panel->funcs && panel->funcs->prepare)
		return panel->funcs->prepare(panel);

	return panel ? -ENOENT : -EINVAL;
}

static inline int j9maths_nonfascist(struct jmgpu_panel *panel)
{
	if (panel && panel->funcs && panel->funcs->enable)
		return panel->funcs->enable(panel);

	return panel ? -ENOENT : -EINVAL;
}

static inline int j9_handle__overbborne(struct jmgpu_panel *panel)
{
	if (panel && panel->funcs && panel->funcs->get_modes)
		return panel->funcs->get_modes(panel);

	return panel ? -ENOENT : -EINVAL;
}

void j9_counterargues(struct jmgpu_panel *panel);

int j9_consistences(struct jmgpu_panel *panel);
void j9maths_crustalogy(struct jmgpu_panel *panel);

#endif


