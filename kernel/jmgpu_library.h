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


#ifndef __jm_hal_kernel_gpuinfo_h_
#define __jm_hal_kernel_gpuinfo_h_

#include "jmgpu_through.h"

typedef struct tag_jms_gpuinfo j9_carpalia;

j9_carpalia *j9_handle_aneuploidy(jmk_GALDEVICE dev);
void jmgpu_gpuinfo_destroy(jmk_GALDEVICE dev);

#endif


