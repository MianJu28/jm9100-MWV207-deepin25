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



#include <linux/err.h>
#include <drm/drm_crtc.h>
#include "jmgpu_authentication.h"

static DEFINE_MUTEX(panel_lock);
static LIST_HEAD(panel_list);


void j9_counterargues(struct jmgpu_panel *panel)
{
    INIT_LIST_HEAD(&panel->list);
}

int j9_consistences(struct jmgpu_panel *panel)
{
    mutex_lock(&panel_lock);
    list_add_tail(&panel->list, &panel_list);
    mutex_unlock(&panel_lock);

    return 0;
}

void j9maths_crustalogy(struct jmgpu_panel *panel)
{
    mutex_lock(&panel_lock);
    list_del_init(&panel->list);
    mutex_unlock(&panel_lock);
}


