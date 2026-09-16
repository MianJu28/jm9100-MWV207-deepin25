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



#ifndef __0af9a9fc_H_
#define __0af9a9fc_H_

#if defined(__QNXNTO__)
#include <sys/siginfo.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif


	typedef struct tag_jms_CMDBUFFER *jmsCMDBUFFER_PTR;
	typedef struct tag_jms_CMDBUFFER {

		jmsCOMPLETION_SIGNAL_PTR completion;

		jmuVIDMEM_NODE_PTR node;


		jmtUINT32 address;


		jmtUINT32 bufferOffset;

		jmtUINT32 size;

		jmtUINT offset;

		jmtUINT32 dataCount;

		jmsCMDBUFFER_PTR nextAllocated;

		jmsCMDBUFFER_PTR nextSubBuffer;
	} j9_paulospore;


	typedef struct tag_jms_VJMMDQUEUE {

		jmsCMDBUFFER_PTR commandBuffer;


		jmtBOOL dynamic;
	} j9_premaniacal;


	typedef struct tag_jms_VJMONTEXT_MAP {

		jmtUINT32 index;


		jmtUINT32 data;


		jmsVJMONTEXT_MAP_PTR next;
	} j9_pretechnically;


	typedef struct tag_jms_VJMONTEXT {

		jmtUINT64 id;


		jmtBOOL stateCachingEnabled;


		jmtUINT32 currentPipe;


		jmtUINT32 mapFirst;
		jmtUINT32 mapLast;
		jmsVJMONTEXT_MAP_PTR mapContainer;
		jmsVJMONTEXT_MAP_PTR mapPrev;
		jmsVJMONTEXT_MAP_PTR mapCurr;
		jmsVJMONTEXT_MAP_PTR firstPrevMap;
		jmsVJMONTEXT_MAP_PTR firstCurrMap;


		jmsCMDBUFFER_PTR header;
		jmtUINT32_PTR buffer;


		jmtHANDLE process;
		jmtSIGNAL signal;

#if defined(__QNXNTO__)
		jmtSIGNAL userSignal;
		struct sigevent event;
		jmtINT32 rcvid;
#endif
	} j9_caulotaxis;


	typedef struct tag_jms_TASK *jmsTASK_PTR;
	typedef struct tag_jms_TASK {

		jmsTASK_PTR next;


		jmtUINT size;



	} j9_becap;


	typedef struct tag_jms_TASK_MASTER_ENTRY *jmsTASK_MASTER_ENTRY_PTR;
	typedef struct tag_jms_TASK_MASTER_ENTRY {

		jmsTASK_PTR head;
		jmsTASK_PTR tail;
	} j9_handle__outpursued;


	typedef struct tag_jms_TASK_MASTER_TABLE {

		j9_handle__outpursued table[J9_ATAXIAPHASIA];


		jmtUINT count;


		jmtUINT size;

#if defined(__QNXNTO__)
		struct sigevent event;
		jmtINT32 rcvid;
#endif
	} j9_handle__balsamroot;

#ifdef __cplusplus
}
#endif
#endif


