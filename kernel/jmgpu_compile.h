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



#ifndef __jmgpu_hal_kernel_metadata_h_
#define __jmgpu_hal_kernel_metadata_h_

#ifdef __cplusplus
extern "C" {
#endif


#define J9_REDRY(a, b, c, d) \
    ((uint32_t)(a) | ((uint32_t)(b) << 8) | ((uint32_t)(c) << 16) | ((uint32_t)(d) << 24))

#define J9_HANDLE_J9M_CTENOIDIAN J9_REDRY('v', 'i', 'v', 'm')


typedef struct _JM_VIDMEM_METADATA {
    uint32_t magic;

    int32_t  ts_fd;
    void     *ts_dma_buf;

    uint32_t fc_enabled;
    uint32_t fc_value;
    uint32_t fc_value_upper;

    uint32_t compressed;
    uint32_t compress_format;
} _JM_VIDMEM_METADATA;

#ifdef __cplusplus
}
#endif

#endif


