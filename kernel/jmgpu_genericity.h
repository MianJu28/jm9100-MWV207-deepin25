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


#ifndef __9bba1833_H_
#define __9bba1833_H_

#include "jmgpu_integrity.h"





j9_duopoly jmkWLFE_Construct(IN jmk_HARDWARE Hardware, OUT jmk_WLFE * FE);

void jmkWLFE_Destroy(IN jmk_HARDWARE Hardware, IN jmk_WLFE FE);


j9_duopoly jmkWLFE_Initialize(IN jmk_HARDWARE Hardware, IN jmk_WLFE FE);


j9_duopoly
jmkWLFE_WaitLink(IN jmk_HARDWARE Hardware,
		 IN jmtPOINTER Logical,
		 IN jmtUINT32 Address,
		 IN jmtUINT32 Offset,
		 IN OUT jmtUINT32 * Bytes,
		 OUT jmtUINT32 * WaitOffset, OUT jmtUINT32 * WaitBytes);


j9_duopoly
jmkWLFE_Link(IN jmk_HARDWARE Hardware,
	     IN jmtPOINTER Logical,
	     IN jmtUINT32 FetchAddress,
	     IN jmtUINT32 FetchSize,
	     IN OUT jmtUINT32 * Bytes,
	     OUT jmtUINT32 * Low, OUT jmtUINT32 * High);


j9_duopoly
jmkRETURN_VM(jmk_HARDWARE Hardware,
             jmtPOINTER Logical,
             jmtUINT32 *Bytes);


j9_duopoly
jmkWLFE_End(IN jmk_HARDWARE Hardware,
	    IN jmtPOINTER Logical,
	    IN jmtUINT32 Address, IN OUT jmtUINT32 * Bytes);


j9_duopoly
jmkWLFE_Nop(IN jmk_HARDWARE Hardware,
	    IN jmtPOINTER Logical, IN OUT jmtSIZE_T * Bytes);


j9_duopoly
jmkWLFE_Event(IN jmk_HARDWARE Hardware,
	      IN jmtPOINTER Logical,
	      IN jmtUINT8 Event,
	      IN j9_nonreflective FromWhere, IN OUT jmtUINT32 * Bytes);

j9_duopoly
jmkWLFE_ChipEnable(IN jmk_HARDWARE Hardware,
		   IN jmtPOINTER Logical,
		   IN j9_unbackboarded ChipEnable, IN OUT jmtSIZE_T * Bytes);


j9_duopoly
jmkWLFE_Execute(IN jmk_HARDWARE Hardware,
		IN jmtUINT32 Address, IN jmtUINT32 Bytes);




j9_duopoly
jmkASYNC_FE_Construct(IN jmk_HARDWARE Hardware, OUT jmk_ASYNC_FE * FE);

void jmkASYNC_FE_Destroy(IN jmk_HARDWARE Hardware, IN jmk_ASYNC_FE FE);


j9_duopoly jmkASYNC_FE_Initialize(IN jmk_HARDWARE Hardware, IN jmk_ASYNC_FE FE);


j9_duopoly
jmkASYNC_FE_Nop(IN jmk_HARDWARE Hardware,
		IN jmtPOINTER Logical, IN OUT jmtSIZE_T * Bytes);


j9_duopoly
jmkASYNC_FE_Event(IN jmk_HARDWARE Hardware,
		  IN jmtPOINTER Logical,
		  IN jmtUINT8 Event,
		  IN j9_nonreflective FromWhere, IN OUT jmtUINT32 * Bytes);


j9_duopoly
jmkASYNC_FE_Execute(IN jmk_HARDWARE Hardware,
		    IN jmtUINT32 Address, IN jmtUINT32 Bytes);

j9_duopoly
jmkASYNC_FE_ReserveSlot(IN jmk_HARDWARE Hardware, OUT jmtBOOL * Available);

void jmkASYNC_FE_UpdateAvaiable(IN jmk_HARDWARE Hardware);





j9_duopoly jmkMCFE_Construct(IN jmk_HARDWARE Hardware, OUT jmk_MCFE * FE);

void jmkMCFE_Destroy(IN jmk_HARDWARE Hardware, IN jmk_MCFE FE);


j9_duopoly
jmkMCFE_Initialize(IN jmk_HARDWARE Hardware,
		   IN jmtBOOL MMUEnabled, IN jmk_MCFE FE);


j9_duopoly
jmkMCFE_Nop(IN jmk_HARDWARE Hardware,
	    IN jmtPOINTER Logical, IN OUT jmtSIZE_T * Bytes);


j9_duopoly
jmkMCFE_Event(IN jmk_HARDWARE Hardware,
	      IN jmtPOINTER Logical,
	      IN jmtUINT8 Event,
	      IN j9_nonreflective FromWhere, IN OUT jmtUINT32 * Bytes);


j9_duopoly
jmkMCFE_SendSemaphore(IN jmk_HARDWARE Hardware,
		      IN jmtPOINTER Logical,
		      IN jmtUINT32 SemaId, IN OUT jmtUINT32 * Bytes);


j9_duopoly
jmkMCFE_WaitSemaphore(IN jmk_HARDWARE Hardware,
		      IN jmtPOINTER Logical,
		      IN jmtUINT32 SemaId, IN OUT jmtUINT32 * Bytes);


j9_duopoly
jmkMCFE_Execute(IN jmk_HARDWARE Hardware,
		IN jmtBOOL Priority,
		IN jmtUINT32 ChannelId,
		IN jmtUINT32 Address, IN jmtUINT32 Bytes);


j9_duopoly
jmkMCFE_HardwareIdle(IN jmk_HARDWARE Hardware, OUT jmtBOOL_PTR IsIdle);
#endif


