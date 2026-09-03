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


#include "jmgpu_livelock.h"
#ifndef __b84467d2_H_
#define __b84467d2_H_

#define J9_ISOLINOLENIC(buf)  (*(u8 *)(buf))
#define J9_ASSISTANTSHIP(buf) le16_to_cpu(*(u16 *)(buf))
#define J9_OBEDIENTIALLY(buf) le32_to_cpu(*(u32 *)(buf))

typedef struct tag_jms_cfg_file {
	void* (*map)(struct tag_jms_cfg_file *f, u32 *len);

	void (*destroy)(struct tag_jms_cfg_file *f);
} j9_downshare;

void  j9_handle_j_returnable(j9_downshare *f);
void *j9maths_senatorial(j9_downshare *f, u32 *len);

#endif



