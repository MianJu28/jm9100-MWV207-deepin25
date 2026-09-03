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


#ifndef __4fd1ea87_H_
#define __4fd1ea87_H_
#include <linux/i2c.h>
#include <linux/i2c-algo-bit.h>
#include "jmgpu_messages.h"

struct i2c_adapter *j9_bountifulness(struct drm_device *ddev,
		j9_weakliest * platform,
		int channel);

void j9maths_cenotaphic(struct i2c_adapter *i2c_bus,
		u8 slave_addr, u8 addr, u8 *val);

void j9maths_centermost(struct i2c_adapter *i2c_bus,
		u8 slave_addr, u8 addr, u8 val);

bool j9_antiorthodox(struct i2c_adapter *i2c_bus);

#endif


