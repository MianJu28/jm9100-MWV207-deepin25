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


#ifndef __066e2523_H_
#define __066e2523_H_
#include "jmgpu_integrity.h"
#ifdef __cplusplus
extern "C" {
#endif

#define J9_OBSOLESCING           1
#define J9MATHS_ANTISTATIC       1
#define J9_HYGROBLEPHARIC        1
#define J9_UNSYNCHRONISED        1
#define J9_HANDLE_FRITHSTOOL     0
#define J9MATHS_PROMULGING       1
#define J9_HANDLE_OUTPLEASED     0
#define J9_OSTEODERMIS           0
#define J9_CHITTERLINGS          0
#define J9_ALEMBICATED           1

	typedef struct tag_jms_FUNCTION_EXECUTION *jmsFUNCTION_EXECUTION_PTR;

	typedef enum {
		J9_HANDLE_J9MIN_CLOCKWORKS,
		J9_HANDLE_J9MATHS_PREBENDATE,
#if J9_OBSOLESCING
		J9_HANDLE_J9_ATTRIBUTE_TETRAMETER,
#else
#if J9_OSTEODERMIS
		J9_HANDLE_J_ATTRIBUTE_ACETYLIZER,
#endif
#if J9_ALEMBICATED
		J9_HANDLE_J9_ATTRIBUTE_SUPERCIVIL,
#endif
#if J9MATHS_PROMULGING
		J9_HANDLE_J9MENU_ATTRIBUTE_PREDECLINE,
#endif
#endif

		J9_HANDLE_J9MIN_ENDOCRITIC
	} jmeFUNCTION_EXECUTION;

	typedef struct {

		jmkVIDMEM_NODE bufVidMem;


		jmtSIZE_T bufVidMemBytes;


		jmtUINT32 address;


		jmtPOINTER logical;


		jmtSIZE_T bytes;
	} jmsFUNCTION_EXECUTION_DATA, *jmsFUNCTION_EXECUTION_DATA_PTR;

	typedef struct {
		j9_duopoly(*validate) (IN jmsFUNCTION_EXECUTION_PTR Execution);
		j9_duopoly(*init) (IN jmsFUNCTION_EXECUTION_PTR Execution);
		j9_duopoly(*execute) (IN jmsFUNCTION_EXECUTION_PTR Execution);
		j9_duopoly(*release) (IN jmsFUNCTION_EXECUTION_PTR Execution);
	} jmsFUNCTION_API, *jmsFUNCTION_API_PTR;

	typedef struct tag_jms_FUNCTION_COMMAND {

		jmkVIDMEM_NODE funcVidMem;


		jmtSIZE_T funcVidMemBytes;


		jmtUINT32 address;


		jmtPOINTER logical;


		jmtPHYS_ADDR_T physical;


		jmtUINT32 bytes;


		jmtUINT32 endAddress;


		jmtUINT8_PTR endLogical;


		jmtPHYS_ADDR_T endPhysical;


		jmtUINT32 channelId;


		jmtUINT32 dataCount;
		jmsFUNCTION_EXECUTION_DATA_PTR data;
#if J9_HANDLE_FRITHSTOOL
		jmtPOINTER golden;
		jmtPOINTER outlogical;
		jmtUINT32 outSize;
#endif
	} j9_handle_acetylizer, *jmsFUNCTION_COMMAND_PTR;

	typedef struct tag_jms_FUNCTION_EXECUTION {
		jmtPOINTER hardware;


		jmtCHAR funcName[16];


		jmeFUNCTION_EXECUTION funcId;


		jmtUINT8 funcCmdCount;


		jmsFUNCTION_COMMAND_PTR funcCmd;


		jmsFUNCTION_API funcExecution;


		jmtBOOL valid;


		jmtBOOL inited;
	} j9_handle_j_supercivil;

	j9_duopoly jmkFUNCTION_Construct(IN jmtPOINTER Hardware);
	j9_duopoly jmkFUNCTION_Destroy(IN jmtPOINTER Hardware);
	j9_duopoly jmkFUNCTION_CheckCHIPID(IN jmsFUNCTION_EXECUTION_PTR
					   Execution);
	j9_duopoly jmkFUNCTION_Validate(IN jmsFUNCTION_EXECUTION_PTR Execution,
					IN OUT jmtBOOL_PTR Valid);
	j9_duopoly jmkFUNCTION_Init(IN jmsFUNCTION_EXECUTION_PTR Execution);
	j9_duopoly jmkFUNCTION_Execute(IN jmsFUNCTION_EXECUTION_PTR Execution);
	j9_duopoly jmkFUNCTION_Release(IN jmsFUNCTION_EXECUTION_PTR Execution);
	void jmkFUNCTION_Dump(IN jmsFUNCTION_EXECUTION_PTR Execution);
#ifdef __cplusplus
}
#endif
#endif


