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


#ifndef _JMGPU_VIDEO_INPUT_
#define _JMGPU_VIDEO_INPUT_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
typedef struct _hdmiRxInfo {
	int videoWidth;
	int videoHeight;
} hdmiRxInfo;

extern int jmgpuHdmiRxInit(int hdmiRxId);

extern int jmgpuHdmiRxGetInfo(int hdmiRxId, hdmiRxInfo *hRI);

extern int jmgpuHdmiRxGetCurrentAddr(int hdmiRxId,
		int *fdP,
		uint64_t *offsetP);

extern int jmgpuHdmiRxRelease(int hdmiRxId);

#ifdef __cplusplus
}
#endif
#endif



