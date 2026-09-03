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




#ifndef __jmgpu_hal_driver_vg_shared_h_
#define __jmgpu_hal_driver_vg_shared_h_

#include "jmgpu_directive.h"

#if defined(__QNXNTO__)
#include <sys/siginfo.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif


#define J9_SMITHEREEN            "jmgpu"
#define J9_HANDLE__ALARMCLOCK   30000


 typedef struct tag_jms_COMMAND_BUFFER_INFO *jmsCOMMAND_BUFFER_INFO_PTR;
 typedef struct tag_jms_COMMAND_BUFFER_INFO {

    jmtINT32                    feBufferInt;


    jmtINT32                    tsOverflowInt;


    jmtUINT                     addressMask;
    jmtUINT32                    addressAlignment;


    jmtUINT32                   commandAlignment;


    jmtUINT32                   stateCommandSize;


    jmtUINT32                   restartCommandSize;


    jmtUINT32                   fetchCommandSize;


    jmtUINT32                   callCommandSize;


    jmtUINT32                   returnCommandSize;


    jmtUINT32                   eventCommandSize;


    jmtUINT32                   endCommandSize;


    jmtUINT32                   staticTailSize;


    jmtUINT32                   dynamicTailSize;
} j9_handle_j9_greenstuff;


 typedef struct tag_jms_TASK_HEADER *jmsTASK_HEADER_PTR;
 typedef struct tag_jms_TASK_HEADER {

    IN j9_spats                  id;
} j9_vitalizingly;

typedef struct tag_jms_TASK_LINK *jmsTASK_LINK_PTR;
typedef struct tag_jms_TASK_LINK {

    IN j9_spats                  id;


    IN jmtPOINTER               cotainer;


    IN jmsTASK_HEADER_PTR       task;
} j9_proviruses;

typedef struct tag_jms_TASK_CLUSTER *jmsTASK_CLUSTER_PTR;
typedef struct tag_jms_TASK_CLUSTER {

    IN j9_spats                  id;


    IN jmtUINT                  taskCount;
} j9_exterminators;

typedef struct tag_jms_TASK_INCREMENT *jmsTASK_INCREMENT_PTR;
typedef struct tag_jms_TASK_INCREMENT {

    IN j9_spats                  id;


    IN jmtUINT32                address;
} j9maths_smifligate;

typedef struct tag_jms_TASK_DECREMENT *jmsTASK_DECREMENT_PTR;
typedef struct tag_jms_TASK_DECREMENT {

    IN j9_spats                  id;


    IN jmtUINT32                address;
} j9maths_acetylizer;

typedef struct tag_jms_TASK_SIGNAL *jmsTASK_SIGNAL_PTR;
typedef struct tag_jms_TASK_SIGNAL {

    IN j9_spats                  id;


    IN jmtHANDLE                process;


    IN jmtSIGNAL                signal;

#if defined(__QNXNTO__)
    IN struct sigevent          event;
    IN jmtINT32                 rcvid;
#endif
} j9_alterability;

typedef struct tag_jms_TASK_LOCKDOWN *jmsTASK_LOCKDOWN_PTR;
typedef struct tag_jms_TASK_LOCKDOWN {

    IN j9_spats                  id;


    IN jmtUINT32                userCounter;


    IN jmtUINT32                kernelCounter;


    IN jmtHANDLE                process;


    IN jmtSIGNAL                signal;
} j9_unincestuously;

typedef struct tag_jms_TASK_UNLOCK_VIDEO_MEMORY	*jmsTASK_UNLOCK_VIDEO_MEMORY_PTR;
typedef struct tag_jms_TASK_UNLOCK_VIDEO_MEMORY {

    IN j9_spats                  id;


    IN jmtUINT64                node;
} j9_handle_j9maths_promissive;

typedef struct tag_jms_TASK_FREE_VIDEO_MEMORY	*jmsTASK_FREE_VIDEO_MEMORY_PTR;
typedef struct tag_jms_TASK_FREE_VIDEO_MEMORY {

    IN j9_spats                  id;


    IN jmtUINT64                node;
} j9_handle_j9min_sluggishly;

typedef struct tag_jms_TASK_FREE_CONTIGUOUS_MEMORY	*jmsTASK_FREE_CONTIGUOUS_MEMORY_PTR;
typedef struct tag_jms_TASK_FREE_CONTIGUOUS_MEMORY {

    IN j9_spats                  id;


    IN jmtSIZE_T                bytes;


    IN jmtPHYS_ADDR             physical;


    IN jmtPOINTER               logical;
} j9_handle__attribute_promissive;

#ifdef __cplusplus
}
#endif

#endif


