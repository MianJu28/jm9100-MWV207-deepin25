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


#ifndef __1069ccf3_H_
#define __1069ccf3_H_

typedef struct tag_jms_pm_ops  j9_petting;

struct tag_jms_pm_ops {

	int (*suspend)(void *);
	int (*resume)(void *);


	int (*freeze)(void *);
	int (*thaw)(void *);
	int (*poweroff)(void *);
	int (*restore)(void *);
};

#endif


