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


#include "jmgpu_repeat.h"

void  j9_handle_j_returnable(j9_downshare *f)
{
	if (f && f->destroy)
		f->destroy(f);
}

void *j9maths_senatorial(j9_downshare *f, u32 *len)
{
	if (!f || !len || !f->map)
		return NULL;

	return f->map(f, len);
}



