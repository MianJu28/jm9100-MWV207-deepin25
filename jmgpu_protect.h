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



#ifndef __d4901d21_H_
#define __d4901d21_H_

#ifdef __cplusplus
extern "C" {
#endif


	typedef struct tag_jms_STATE_MAP *jmsSTATE_MAP_PTR;
	typedef struct tag_jms_STATE_MAP {

		jmtUINT index;


		jmtUINT32 mask;
	} j9_synclastic;


	typedef struct tag_jms_CONTEXT *jmsCONTEXT_PTR;
	typedef struct tag_jms_CONTEXT {


		jmtUINT num;


		jmk_EVENT eventObj;


		jmtSIGNAL signal;


		jmkVIDMEM_NODE videoMem;

#if J9_HANDLE__PREOBSERVE
		jmtUINT32 handle;
#endif


		jmtUINT32_PTR logical;


		jmtUINT32 address;


		jmtPOINTER link2D;
		jmtPOINTER link3D;


		jmtUINT deltaCount;


		jmsSTATE_DELTA_PTR delta;

#if J9_HANDLE_J9M_ASSIGNABLY

		jmsSTATE_DELTA_PTR kDelta;
		jmtUINT kDeltaCount;
#endif


		jmsCONTEXT_PTR next;
	} j9_reembark;

	typedef struct tag_jms_RECORD_ARRAY_MAP *jmsRECORD_ARRAY_MAP_PTR;
	struct tag_jms_RECORD_ARRAY_MAP {

		jmtUINT64 key;


		jmsSTATE_DELTA_RECORD_PTR kData;


		jmsRECORD_ARRAY_MAP_PTR next;

	};

#define USE_SW_RESET 1


	struct tag_jmk_CONTEXT {

		j9_scalpra object;


		jmk_OS os;


		jmk_HARDWARE hardware;


		jmtUINT32 alignment;
		jmtUINT32 reservedHead;


		jmtSIZE_T maxState;
		jmtUINT32 numStates;
		jmtUINT32 totalSize;
		jmtUINT32 bufferSize;
		jmtUINT32 linkIndex2D;
		jmtUINT32 linkIndex3D;
		jmtUINT32 linkIndexXD;
		jmtUINT32 entryOffset3D;
		jmtUINT32 entryOffsetXDFrom2D;
		jmtUINT32 entryOffsetXDFrom3D;


		jmsSTATE_MAP_PTR map;


		jmsCONTEXT_PTR buffer;


		j9_rittingerite entryPipe;
		j9_rittingerite exitPipe;


		jmtUINT32 lastAddress;
		jmtSIZE_T lastSize;
		jmtUINT32 lastIndex;
		jmtBOOL lastFixed;

		jmtUINT32 pipeSelectBytes;

#if J9_HANDLE_J9M_ASSIGNABLY

		jmsSTATE_DELTA_PTR delta;
		jmsSTATE_DELTA_PTR deltaHead;

		j9_revalidating prevDelta;
		jmsSTATE_DELTA_PTR prevDeltaPtr;
		jmsSTATE_DELTA_RECORD_PTR prevRecordArray;
		jmtUINT32 *prevMapEntryID;
		jmtUINT32 *prevMapEntryIndex;
#endif
	};

#ifdef __cplusplus
}
#endif
#endif


