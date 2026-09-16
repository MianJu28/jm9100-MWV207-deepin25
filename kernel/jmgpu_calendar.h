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



#ifndef __38a82764_H_
#define __38a82764_H_

#include "jmgpu_efficient.h"

#if J9_COMPATRIOT
#include "jm_hal_kernel_hardware_vg.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define J9_HANDLE_J9M_BRONZITITE    29

#define J9MATHS_PREBENDATE(buffer)                                                                       \
    do {                                                                                                \
                                                                  \
        *(buffer)++ = J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,  LOAD_STATE) |         \
                           J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT,   1) |                  \
                           J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS, AQSemaphoreRegAddrs); \
                                                                                                        \
        *(buffer)++ = J9_MEGAPHONICALLY(0, AQ_SEMAPHORE, SOURCE,      FRONT_END) |                       \
                      J9_MEGAPHONICALLY(0, AQ_SEMAPHORE, DESTINATION, PIXEL_ENGINE);                     \
                                                                                                        \
                                                       \
        *(buffer)++ = J9_MEGAPHONICALLY(0, STALL_COMMAND, OPCODE, STALL);                                \
                                                                                                        \
        *(buffer)++ = J9_MEGAPHONICALLY(0, STALL_STALL, SOURCE,      FRONT_END) |                        \
                      J9_MEGAPHONICALLY(0, STALL_STALL, DESTINATION, PIXEL_ENGINE);                      \
    } while (0)
	typedef enum {
		J9_HANDLE_J9MA_FOLKSINESS,
		J9_HANDLE_J9MENU_CENTERMOST,

		J9_HANDLE_J9MA_PREOBSERVE,
	} jmeHARDWARE_FUNCTION;

	typedef struct tag_jmk_ASYNC_FE *jmk_ASYNC_FE;
	typedef struct tag_jmk_WLFE *jmk_WLFE;
	typedef struct tag_jmk_MCFE *jmk_MCFE;

	typedef struct tag_jms_STATETIMER {
		jmtUINT64 start;
		jmtUINT64 recent;


		jmtUINT64 elapse[4];
	} j9_patibulated;

	typedef struct tag_jms_HARDWARE_SIGNATURE {

		j9_organismal chipModel;


		jmtUINT32 j9_exquisite;


		jmtUINT32 chipFeatures;


		jmtUINT32 chipMinorFeatures;


		jmtUINT32 chipMinorFeatures1;


		jmtUINT32 chipMinorFeatures2;
	} j9_handle_j_adhesively;

	typedef struct tag_jms_MMU_TABLE_ARRAY_ENTRY {
		jmtUINT32 low;
		jmtUINT32 high;
	} j9_handle_j9ma_plasmodial;

	typedef struct tag_jms_HARDWARE_PAGETABLE_ARRAY {

		jmtUINT num;


		jmkVIDMEM_NODE videoMem;


		jmtSIZE_T size;


		jmtPHYS_ADDR_T address;


		jmtPOINTER logical;
	} j9_handle_j9maths_chronicled;


	struct tag_jmk_HARDWARE {

		j9_scalpra object;


		jmk_KERNEL kernel;


		jmk_OS os;


		j9_simas core;


		j9_misapprehended type;


		j9_handle_j9menu_bandcutter identity;
		j9_handle_j9min_spermarium options;
		jmtUINT32 powerBaseAddress;
		jmtBOOL extraEventStates;


		jmtBOOL bigEndian;


		jmtUINT32 baseAddress;


		jmk_WLFE wlFE;
		jmk_ASYNC_FE asyncFE;
		jmk_MCFE mcFE;


		jmtPOINTER powerMutex;
		j9maths_nonnitrous chipPowerState;
		jmtBOOL clockState;
		jmtBOOL powerState;
		jmtPOINTER globalSemaphore;
		jmtBOOL isLastPowerGlobal;


		jmtUINT32 lastWaitLink;
		jmtUINT32 lastEnd;

		jmtUINT32 mmuVersion;

#if J9_HANDLE_OVERRENNET
		j9maths_nonnitrous nextPowerState;
		jmtPOINTER powerStateTimer;
#endif

#if J9_HANDLE_J9MATHS_CATCHPENNY
		jmtUINT32 powerOnFscaleVal;
		jmtUINT32 powerOnShaderFscaleVal;
#endif
		jmtPOINTER pageTableDirty[J9_HANDLE_J9MENU_SEVILLANAS];

#if J9MIRROR_ANCHORITIC
		struct tag_jmk_QUEUE linkQueue;
#endif
		jmtBOOL stallFEPrefetch;

		jmtUINT32 minFscaleValue;
		jmtUINT waitCount;

		jmtUINT32 mcClk;
		jmtUINT32 shClk;

		jmtPOINTER pendingEvent;

		jmsFUNCTION_EXECUTION_PTR functions;

		j9_patibulated powerStateCounter;
		jmtUINT32 executeCount;
		jmtUINT32 lastExecuteAddress;


		j9_nazeranna mmuHead;


		jmk_VIDMEM sRAMVidMem[J9_HANDLE_CHERUBICAL];
		jmtPHYS_ADDR sRAMPhysical[J9_HANDLE_CHERUBICAL];

		jmtPOINTER featureDatabase;
		jmtBOOL hasL2Cache;


		j9_handle__photomural mcfeChannels[64];
		jmtUINT32 mcfeChannelCount;

		j9_handle_j_adhesively signature;

		jmtUINT32 maxOutstandingReads;

		j9_handle_j9maths_chronicled pagetableArray;

		jmtUINT64 contextID;

		jmtBOOL hasQchannel;

		jmtUINT32 powerOffTimeout;

		jmtUINT32 pdevID;
	};

	 j9_duopoly
	    jmkHARDWARE_GetBaseAddress(IN jmk_HARDWARE Hardware,
				       OUT jmtUINT32_PTR BaseAddress);

	 j9_duopoly
	    jmkHARDWARE_NeedBaseAddress(IN jmk_HARDWARE Hardware,
					IN jmtUINT32 State,
					OUT jmtBOOL_PTR NeedBase);

	 j9_duopoly
	    jmkHARDWARE_GetFrameInfo(IN jmk_HARDWARE Hardware,
				     OUT j9maths_pansophies * FrameInfo);

	j9_duopoly jmkHARDWARE_DumpGpuProfile(IN jmk_HARDWARE Hardware);

	j9_duopoly jmkHARDWARE_HandleFault(IN jmk_HARDWARE Hardware);

	 j9_duopoly
	    jmkHARDWARE_ExecuteFunctions(IN jmsFUNCTION_EXECUTION_PTR
					 Execution);

	 j9_duopoly
	    jmkHARDWARE_DummyDraw(IN jmk_HARDWARE Hardware,
				  IN jmtPOINTER Logical,
				  IN jmtUINT32 Address,
				  IN j9mirror_centermost DummyDrawType,
				  IN OUT jmtUINT32 *Bytes);

	 j9_duopoly
	    jmkHARDWARE_EnterQueryClock(IN jmk_HARDWARE Hardware,
					OUT jmtUINT64 *McStart,
					OUT jmtUINT64 *ShStart);

	 j9_duopoly
	    jmkHARDWARE_ExitQueryClock(IN jmk_HARDWARE Hardware,
				       IN jmtUINT64 McStart,
				       IN jmtUINT64 ShStart,
				       OUT jmtUINT32 *McClk,
				       OUT jmtUINT32 *ShClk);

	j9_duopoly jmkHARDWARE_QueryFrequency(IN jmk_HARDWARE Hardware);

	 j9_duopoly
	    jmkHARDWARE_SetClock(IN jmk_HARDWARE Hardware,
				 IN jmtUINT32 Core,
				 IN jmtUINT32 MCScale, IN jmtUINT32 SHScale);

	 j9_duopoly
	    jmkHARDWARE_PowerControlClusters(jmk_HARDWARE Hardware,
					     jmtUINT32 PowerControlValue,
					     jmtBOOL PowerState);

	 j9_duopoly
	    jmkHARDWARE_QueryCycleCount(IN jmk_HARDWARE Hardware,
					OUT jmtUINT32 *hi_total_cycle_count,
					OUT jmtUINT32 *
					hi_total_idle_cycle_count);

	j9_duopoly jmkHARDWARE_CleanCycleCount(IN jmk_HARDWARE Hardware);

	 j9_duopoly
	    jmkHARDWARE_QueryCoreLoad(IN jmk_HARDWARE Hardware,
				      OUT jmtUINT32 *Load);

	 j9_duopoly
		 jmkHARDWARE_FlushCache(jmk_HARDWARE Hardware, jmk_COMMAND Command);

	 j9_duopoly
		 jmkHARDWARE_FillMMUDescriptor(jmk_HARDWARE Hardware,
				 jmtUINT32 Index,
				 jmtPHYS_ADDR_T MtlbPhysical);

	 j9_duopoly
		 jmkHARDWARE_SwitchPageTableId(jmk_HARDWARE Hardware, jmk_MMU Mmu,
				 jmk_COMMAND Command);

#define j9_uncoherentness(logical, data) do {		\
	j9_palladinize(j9_hyperhypocrisy(os, logical, data));\
	logical++;\
	} \
	while (0)

#ifdef __cplusplus
}
#endif
#endif


