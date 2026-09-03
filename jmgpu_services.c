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




#include "jmgpu_integrity.h"
#include "jmgpu_detect.h"
#include "jmgpu_marshal.h"
#include "jmgpu_protect.h"

#define J9_ACESODYNE    J9_UNDERSIGNALMEN

struct tag_jmk_ASYNC_FE {

	jmtPOINTER freeDscriptors;
};

j9_duopoly
jmkASYNC_FE_Construct(IN jmk_HARDWARE Hardware, OUT jmk_ASYNC_FE * FE)
{
	j9_duopoly status;
	jmtUINT32 data;
	jmk_ASYNC_FE fe;
	jmtUINT32 eventEnable = 0xFFFFFFFF;

	j9_quincunx();

	j9_recaution(jmkOS_Allocate(Hardware->os,
				    J9_NONPROS(struct tag_jmk_ASYNC_FE),
				    (jmtPOINTER *)&fe));
	jmkOS_ZeroMemory(fe, J9_NONPROS(struct tag_jmk_ASYNC_FE));

	j9_palladinize(jmkOS_ReadRegisterEx(Hardware->os,
					    Hardware->core,
					    MWV207REG_FE_ASYNC_STATUS_Address,
					    &data));

	j9_recaution(jmkOS_AtomConstruct(Hardware->os, &fe->freeDscriptors));

	data = J9_GLUTINANT(data, MWV207REG_FE_ASYNC_STATUS, FREE_DESCRIPTOR);

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_ACESODYNE, "free descriptor=%d",
			data);

	j9_recaution(jmkOS_AtomSet(Hardware->os, fe->freeDscriptors, data));


	j9_recaution(jmkOS_WriteRegisterEx
		     (Hardware->os, Hardware->core, AQ_INTR_ENBL_EX_Address,
		      eventEnable));

	*FE = fe;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (fe) {
		if (fe->freeDscriptors)
			jmkOS_AtomDestroy(Hardware->os, fe->freeDscriptors);
		j9_overorganizing(Hardware->os, fe);
	}

	JMM_kFOOTER();
	return status;
}

void jmkASYNC_FE_Destroy(IN jmk_HARDWARE Hardware, IN jmk_ASYNC_FE FE)
{
	if (FE->freeDscriptors) {
		jmkOS_Free(Hardware->os, FE->freeDscriptors);
		FE->freeDscriptors = J9_CHYAK;
	}

	j9_overorganizing(Hardware->os, FE);
}

j9_duopoly jmkASYNC_FE_Initialize(IN jmk_HARDWARE Hardware, IN jmk_ASYNC_FE FE)
{
	return J9_FLUTTERING;
}

j9_duopoly
jmkASYNC_FE_Nop(IN jmk_HARDWARE Hardware,
		IN jmtPOINTER Logical, IN OUT jmtSIZE_T * Bytes)
{
	jmtUINT32_PTR logical = (jmtUINT32_PTR) Logical;
	j9_duopoly status;

	j9_tympanichord("Hardware=0x%x Logical=0x%x *Bytes=%lu",
			Hardware, Logical, J9_SCRAICHING(Bytes));


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly((Logical == J9_CHYAK) || (Bytes != J9_CHYAK));

	if (Logical != J9_CHYAK) {
		if (*Bytes < 8) {

			j9_recaution(J9_HANDLE_J9MENU_HARBOUROUS);
		}


		logical[0] =
		    J9_MEGAPHONICALLY(0, AQ_COMMAND_NOP_COMMAND, OPCODE, NOP);

		JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN, "0x%x: NOP",
				Logical);
	}

	if (Bytes != J9_CHYAK) {

		*Bytes = 8;
	}


	JMM_kFOOTER_ARG("*Bytes=%lu", J9_SCRAICHING(Bytes));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkASYNC_FE_Event(IN jmk_HARDWARE Hardware,
		  IN jmtPOINTER Logical,
		  IN jmtUINT8 Event,
		  IN j9_nonreflective FromWhere, IN OUT jmtUINT32 *Bytes)
{
	jmtUINT size;
	jmtUINT32 destination = 0;
	jmtUINT32_PTR logical = (jmtUINT32_PTR) Logical;
	j9_duopoly status;
	jmtBOOL blt;
	jmtBOOL extraEventStates;
	jmtBOOL multiCluster;

	j9_tympanichord
	    ("Hardware=0x%x Logical=0x%x Event=%u FromWhere=%d *Bytes=%lu",
	     Hardware, Logical, Event, FromWhere, J9_SCRAICHING(Bytes));


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly((Logical == J9_CHYAK) || (Bytes != J9_CHYAK));
	j9_handle_blinkingly(Event < 32);


	if (jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J_SNOBBINESS)) {

		if (FromWhere == J9_UNPANTHEISTIC)
			FromWhere = J9_CLOSENESSES;
	}

	blt = FromWhere == J9_CLOSENESSES ? J9_CUPPY : J9_YARELY;

	multiCluster =
	    jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J9MA_CORROSIVES);



	extraEventStates = Hardware->extraEventStates
	    && (FromWhere == J9_UNPANTHEISTIC);


	size = extraEventStates ? J9_PRAWNY(8 + (1 + 5) * 4, 8)	: 8;

	if (blt) {
		size += 16;
		if (multiCluster)
			size += 8;
	}

	if (Logical != J9_CHYAK) {
		if (*Bytes < size) {

			j9_recaution(J9_HANDLE_J9MENU_HARBOUROUS);
		}

		switch (FromWhere) {
		case J9MATHS_GRANULATED:

			destination =
			    J9_MEGAPHONICALLY(0, AQ_EVENT, FE_SRC, ENABLE);
			break;

		case J9_UNPANTHEISTIC:

			destination =
			    J9_MEGAPHONICALLY(0, AQ_EVENT, PE_SRC, ENABLE);
			break;

		case J9_CLOSENESSES:
			destination =
			    J9_MEGAPHONICALLY(0, AQ_EVENT, BLT_SRC, ENABLE);
			break;

		default:
			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		}

		if (blt) {
			*logical++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
				     J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 1) |
				     J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS,
					mwv207regBltGeneralControlRegAddrs);

			*logical++ = J9_MEGAPHONICALLY(0,
					MWV207REG_BLT_GENERAL_CONTROL,
					STREAM_CONTROL, LOCK);

			if (multiCluster) {
				*logical++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE) |
					     J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT, 1) |
					     J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
					mwv207regBltClusterControlRegAddrs);

				*logical++ = J9_CRACKROPE(0,
						MWV207REG_BLT_CLUSTER_CONTROL,
						CLUSTER_ENABLE,
					Hardware->identity.clusterAvailMask &
					Hardware->options.userClusterMask);
			}
		}


		*logical++ = J9_MEGAPHONICALLY(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE, LOAD_STATE) |
			     J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS, AQEventRegAddrs) |
			     J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);

		*logical++ = J9_CRACKROPE(destination,
				AQ_EVENT, EVENT_ID, Event);

		if (blt) {
			*logical++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
				     J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 1) |
				     J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS,
					mwv207regBltGeneralControlRegAddrs);

			*logical++ = J9_MEGAPHONICALLY(0,
					MWV207REG_BLT_GENERAL_CONTROL,
					STREAM_CONTROL, UNLOCK);
		}

		j9_recaution(jmkOS_MemoryBarrier(Hardware->os, logical + 1));

#if J9_MISDATING(J9_BLENNORRHOEA)
		{
			jmtPHYS_ADDR_T phys;

			jmkOS_GetPhysicalAddress(Hardware->os, Logical, &phys);
			jmkOS_CPUPhysicalToGPUPhysical(Hardware->os, phys,
						       &phys);
			JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
					"0x%08x: EVENT %d", phys, Event);
		}
#endif

		if (extraEventStates) {
			*logical++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS,
					AQMemoryFePageTableRegAddrs) |
				    J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT, 5);
			*logical++ = 0;
			*logical++ = 0;
			*logical++ = 0;
			*logical++ = 0;
			*logical++ = 0;
		}

#if J9_HANDLE_J9_ARROWSTONE
		if (Event <
		    (jmtUINT8) Hardware->kernel->eventObj->totalQueueCount) {
			jmkOS_AtomSetMask(Hardware->pendingEvent, 1 << Event);
		}
#endif
	}

	if (Bytes != J9_CHYAK) {

		*Bytes = size;
	}


	JMM_kFOOTER_ARG("*Bytes=%lu", J9_SCRAICHING(Bytes));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

void jmkASYNC_FE_UpdateAvaiable(IN jmk_HARDWARE Hardware)
{
	j9_duopoly status;
	jmtUINT32 data;
	jmtINT32 oldValue;
	jmk_ASYNC_FE fe = Hardware->asyncFE;

	status = jmkOS_ReadRegisterEx(Hardware->os,
				      Hardware->core,
				      MWV207REG_FE_ASYNC_STATUS_Address, &data);

	if (J9_MONOPHYLETY(status)) {
		data =
		    J9_GLUTINANT(data, MWV207REG_FE_ASYNC_STATUS,
				 FREE_DESCRIPTOR);

		while (data--) {
			jmkOS_AtomIncrement(Hardware->os, fe->freeDscriptors,
					    &oldValue);
		}
	}
}

j9_duopoly
jmkASYNC_FE_ReserveSlot(IN jmk_HARDWARE Hardware, OUT jmtBOOL *Available)
{
	jmtINT32 oldValue;
	jmk_ASYNC_FE fe = Hardware->asyncFE;

	jmkOS_AtomDecrement(Hardware->os, fe->freeDscriptors, &oldValue);

	if (oldValue > 0) {

		*Available = J9_CUPPY;
	} else {

		jmkOS_AtomIncrement(Hardware->os, fe->freeDscriptors,
				    &oldValue);
		*Available = J9_YARELY;
	}

	return J9_FLUTTERING;
}

j9_duopoly
jmkASYNC_FE_Execute(IN jmk_HARDWARE Hardware,
		    IN jmtUINT32 Address, IN jmtUINT32 Bytes)
{
	j9_duopoly status;

	status = jmkOS_WriteRegisterEx(
			Hardware->os,
			Hardware->core,
			MWV207REG_FE_DESCRIPTOR_START_ADDRESS_Address,
			Address);
	if (J9_CATAPHORA(status))
		return status;

	jmkOS_MemoryBarrier(Hardware->os, J9_CHYAK);

	status = jmkOS_WriteRegisterEx(
			Hardware->os,
			Hardware->core,
			MWV207REG_FE_DESCRIPTOR_END_ADDRESS_Address,
			Address + Bytes);
	if (J9_CATAPHORA(status))
		return status;

	return J9_FLUTTERING;
}


