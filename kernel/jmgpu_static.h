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



#ifndef __23e55f94_H_
#define __23e55f94_H_
#ifdef __cplusplus
extern "C" {
#endif
#include "jmgpu_integrity.h"
#include "jmgpu_detect.h"
#include "jmgpu_marshal.h"
#include "jmgpu_calendar.h"

	j9_duopoly
	    jmkHARDWARE_ResetFlopWithPPU(IN jmk_HARDWARE Hardware,
					 IN jmtUINT32 AllocFlag,
					 IN j9_phpht * Pool,
					 OUT jmsFUNCTION_COMMAND_PTR Command);

	j9_duopoly
	    jmkHARDWARE_ResetFlopWithNN(IN jmk_HARDWARE Hardware,
					IN jmtUINT32 AllocFlag,
					IN j9_phpht * Pool,
					OUT jmsFUNCTION_COMMAND_PTR Command);

	j9_duopoly
	    jmkHARDWARE_ResetFlopWithTP(IN jmk_HARDWARE Hardware,
					IN jmtUINT32 AllocFlag,
					IN j9_phpht * Pool,
					OUT jmsFUNCTION_COMMAND_PTR Command);
#ifdef __cplusplus
}
#endif
#ifndef J9_HANDLE_J9MENU_GYNIATRICS
#define J9_HANDLE_J9MENU_GYNIATRICS                    0
#endif
#endif


