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


#ifndef __a7c3c723_H_
#define __a7c3c723_H_

#include "jmgpu_integrity.h"
#include <linux/mutex.h>


#define j9_overcentralize(Os, Mutex)										\
({														\
									\
	j9_duopoly _status = jmkOS_Allocate(Os, J9_NONPROS(struct mutex), Mutex);				\
														\
	if (J9_MONOPHYLETY(_status)) {										\
									\
		mutex_init(*(struct mutex **)Mutex);								\
}														\
														\
	_status;												\
})

#endif





