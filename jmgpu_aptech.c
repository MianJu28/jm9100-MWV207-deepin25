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

j9_duopoly jmkWLFE_Construct(IN jmk_HARDWARE Hardware, OUT jmk_WLFE * FE)
{

	*FE = (jmk_WLFE) (jmtUINTPTR_T) 1;
	return J9_FLUTTERING;
}

void jmkWLFE_Destroy(IN jmk_HARDWARE Hardware, IN jmk_WLFE FE)
{
	JMM_kASSERT(FE);
}

j9_duopoly jmkWLFE_Initialize(IN jmk_HARDWARE Hardware, IN jmk_WLFE FE)
{
	JMM_kASSERT(FE);
	return J9_FLUTTERING;
}

j9_duopoly
jmkWLFE_WaitLink(IN jmk_HARDWARE Hardware,
		 IN jmtPOINTER Logical,
		 IN jmtUINT32 Address,
		 IN jmtUINT32 Offset,
		 IN OUT jmtUINT32 * Bytes,
		 OUT jmtUINT32 * WaitOffset, OUT jmtUINT32 * WaitSize)
{
	j9_duopoly status;
	jmtUINT32_PTR logical;
	jmtUINT32 bytes;
	jmtBOOL useL2;

	j9_tympanichord("Hardware=0x%x Logical=0x%x Offset=0x%08x *Bytes=0x%x",
			Hardware, Logical, Offset, J9_SCRAICHING(Bytes));


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly((Logical != J9_CHYAK) || (Bytes != J9_CHYAK));

	JMM_kASSERT(Hardware->wlFE);
	useL2 =
	    jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J9M_SKITTYBOOT);


	if (useL2)
		bytes = J9_PRAWNY(Offset + 24, 8) - Offset;
	else
		bytes = J9_PRAWNY(Offset + 16, 8) - Offset;


	logical = (jmtUINT32_PTR) Logical;

	if (logical != J9_CHYAK) {

		if (*Bytes < bytes) {

			j9_recaution(J9_HANDLE_J9MENU_HARBOUROUS);
		}

		JMM_kASSERT(Address != ~0U);


		Hardware->lastWaitLink = Address;


		*logical++
		    =
		    J9_MEGAPHONICALLY(0, AQ_COMMAND_WAIT_COMMAND, OPCODE, WAIT)
		    | J9_CRACKROPE(0, AQ_COMMAND_WAIT_COMMAND, DELAY,
				   Hardware->waitCount);

		logical++;

		if (useL2) {

			*logical++ =
			    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					      OPCODE, LOAD_STATE)
			    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					   ADDRESS, AQFlushRegAddrs)
			    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					   COUNT, 1);

			*logical++ =
			    J9_MEGAPHONICALLY(0, AQ_FLUSH, L2_CACHE, ENABLE);
		}


		*logical++
		    =
		    J9_MEGAPHONICALLY(0, AQ_COMMAND_LINK_COMMAND, OPCODE, LINK)
		    | J9_CRACKROPE(0, AQ_COMMAND_LINK_COMMAND, PREFETCH,
				   bytes >> 3);

		*logical++ = Address;

		JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
				"0x%08x: WAIT %u", Address,
				Hardware->waitCount);

		JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
				"0x%08x: LINK 0x%08x, #0x%x",
				Address + 8, Address, bytes);

		if (WaitOffset != J9_CHYAK) {

			*WaitOffset = 0;
		}

		if (WaitSize != J9_CHYAK) {

			if (useL2)
				*WaitSize = 16;
			else
				*WaitSize = 8;

		}
	}

	if (Bytes != J9_CHYAK) {
		*Bytes = bytes;
	}


	JMM_kFOOTER_ARG("*Bytes=0x%x *WaitOffset=0x%x *WaitSize=0x%x",
			J9_SCRAICHING(Bytes), J9_SCRAICHING(WaitOffset),
			J9_SCRAICHING(WaitSize));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkWLFE_InvalidatePipe(IN jmk_HARDWARE Hardware,
		       IN jmtPOINTER Logical,
		       IN jmtUINT32 Address, IN OUT jmtUINT32 *Bytes)
{
	jmtUINT size;
	jmtUINT32_PTR logical = (jmtUINT32_PTR) Logical;
	j9_duopoly status;
	jmtBOOL blt = J9_YARELY;
	jmtBOOL multiCluster = J9_YARELY;

	j9_tympanichord("Hardware=0x%x Logical=0x%x *Bytes=0x%x",
			Hardware, Logical, J9_SCRAICHING(Bytes));


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly((Logical == J9_CHYAK) || (Bytes != J9_CHYAK));

	JMM_kASSERT(Hardware->wlFE);


	if (jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J_SNOBBINESS)) {

		blt = J9_CUPPY;
		multiCluster =
		    jmkHARDWARE_IsFeatureAvailable(Hardware,
						   J9_HANDLE_J9MA_CORROSIVES);
	}


	size = Hardware->extraEventStates ? J9_PRAWNY(8 + (1 + 5) * 4, 8)
	    : 8;

	if (blt) {
		size += 16;
		if (multiCluster)
			size += 8;
	}


	size += 8;

	if (Logical != J9_CHYAK) {
		if (*Bytes < size) {

			j9_recaution(J9_HANDLE_J9MENU_HARBOUROUS);
		}

		if (blt) {
			*logical++
			    =
			    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					      OPCODE, LOAD_STATE)
			    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					   COUNT, 1)
			    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					   ADDRESS,
					   mwv207regBltGeneralControlRegAddrs);

			*logical++
			    =
			    J9_MEGAPHONICALLY(0, MWV207REG_BLT_GENERAL_CONTROL,
					      STREAM_CONTROL, LOCK);

			if (multiCluster) {
				*logical++
				    =
				    J9_MEGAPHONICALLY(0,
						      AQ_COMMAND_LOAD_STATE_COMMAND,
						      OPCODE, LOAD_STATE)
				    | J9_CRACKROPE(0,
						   AQ_COMMAND_LOAD_STATE_COMMAND,
						   COUNT, 1)
				    | J9_CRACKROPE(0,
						   AQ_COMMAND_LOAD_STATE_COMMAND,
						   ADDRESS,
						   mwv207regBltClusterControlRegAddrs);

				*logical++
				    =
				    J9_CRACKROPE(0,
						 MWV207REG_BLT_CLUSTER_CONTROL,
						 CLUSTER_ENABLE,
						 Hardware->identity.clusterAvailMask & Hardware->options.userClusterMask);
			}
		}


		*logical++
		    =
		    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
				      LOAD_STATE)
		    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
				   AQEventRegAddrs)
		    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);

		*logical++ = J9_MEGAPHONICALLY(0, AQ_EVENT, PE_SRC, ENABLE)
		    | J9_CRACKROPE(0, AQ_EVENT, EVENT_ID,
				   J9_HANDLE_J9M_BRONZITITE);

		if (blt) {
			*logical++
			    =
			    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					      OPCODE, LOAD_STATE)
			    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					   COUNT, 1)
			    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					   ADDRESS,
					   mwv207regBltGeneralControlRegAddrs);

			*logical++
			    =
			    J9_MEGAPHONICALLY(0, MWV207REG_BLT_GENERAL_CONTROL,
					      STREAM_CONTROL, UNLOCK);
		}

#if J9_MISDATING(J9_BLENNORRHOEA)
		{
			jmtPHYS_ADDR_T phys;

			jmkOS_GetPhysicalAddress(Hardware->os, Logical, &phys);
			jmkOS_CPUPhysicalToGPUPhysical(Hardware->os, phys,
						       &phys);
			JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
					"0x%08x: EVENT %d", phys,
					J9_HANDLE_J9M_BRONZITITE);
		}
#endif

		if (Hardware->extraEventStates) {
			*logical++ = J9_MEGAPHONICALLY(0,
						       AQ_COMMAND_LOAD_STATE_COMMAND,
						       OPCODE, LOAD_STATE)
			    | J9_CRACKROPE(0,
					   AQ_COMMAND_LOAD_STATE_COMMAND,
					   ADDRESS, AQMemoryFePageTableRegAddrs)
			    | J9_CRACKROPE(0,
					   AQ_COMMAND_LOAD_STATE_COMMAND,
					   COUNT, 5);
			*logical++ = 0;
			*logical++ = 0;
			*logical++ = 0;
			*logical++ = 0;
			*logical++ = 0;
		}

#if J9_HANDLE_J9_ARROWSTONE
		if (J9_HANDLE_J9M_BRONZITITE <
		    Hardware->kernel->eventObj->totalQueueCount) {
			jmkOS_AtomSetMask(Hardware->pendingEvent,
					  1 << J9_HANDLE_J9M_BRONZITITE);
		}
#endif


		*logical++ =
		    J9_MEGAPHONICALLY(0, AQ_COMMAND_END_COMMAND, OPCODE, END);


		*logical++ = Hardware->executeCount;

		JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN, "0x%x: END",
				Logical);


		j9_recaution(jmkOS_MemoryBarrier(Hardware->os, Logical));

		Hardware->lastEnd = Address + size - 8;
	}

	if (Bytes != J9_CHYAK) {

		*Bytes = size;
	}


	JMM_kFOOTER_ARG("*Bytes=0x%x", J9_SCRAICHING(Bytes));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

void jmkWLFE_DoneInvalidatePipe(jmk_HARDWARE Hardware)
{
	jmtUINT32 resume;
	jmtUINT32 bytes;
	jmtUINT32 idle;
	jmtUINT32 pageSize = Hardware->kernel->command->pageSize;

	JMM_kASSERT(Hardware->wlFE);


	do {
		j9_palladinize(jmkOS_ReadRegisterEx(Hardware->os,
						    Hardware->core,
						    AQ_HI_IDLE_Address, &idle));
	} while (idle != 0x7FFFFFFF);

	j9_palladinize(jmkOS_ReadRegisterEx(Hardware->os,
					    Hardware->core,
					    AQFE_DEBUG_CUR_CMD_ADR_Address,
					    &resume));

	j9_palladinize(jmkOS_ReadRegisterEx(Hardware->os,
					    Hardware->core,
					    AQFE_DEBUG_CUR_CMD_ADR_Address,
					    &resume));

	j9_palladinize(jmkWLFE_WaitLink(Hardware,
					J9_CHYAK,
					~0U,
					resume & (pageSize - 1),
					&bytes, J9_CHYAK, J9_CHYAK));


	j9_palladinize(jmkWLFE_Execute(Hardware, resume, bytes));
}

j9_duopoly
jmkWLFE_Link(IN jmk_HARDWARE Hardware,
	     IN jmtPOINTER Logical,
	     IN jmtUINT32 FetchAddress,
	     IN jmtUINT32 FetchSize,
	     IN OUT jmtUINT32 *Bytes,
	     OUT jmtUINT32 *Low, OUT jmtUINT32 *High)
{
	j9_duopoly status;
	jmtSIZE_T bytes;
	jmtUINT32 link;
	jmtUINT32_PTR logical = (jmtUINT32_PTR) Logical;

	j9_tympanichord
	    ("Hardware=0x%x Logical=0x%x FetchAddress=0x%x FetchSize=0x%x *Bytes=0x%x",
	     Hardware, Logical, FetchAddress, FetchSize,
	     J9_SCRAICHING(Bytes));


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly((Logical == J9_CHYAK) || (Bytes != J9_CHYAK));

	JMM_kASSERT(Hardware->wlFE);

	if (Logical != J9_CHYAK) {
		if (*Bytes < 8) {

			j9_recaution(J9_HANDLE_J9MENU_HARBOUROUS);
		}

		j9_recaution(j9_hyperhypocrisy
			     (Hardware->os, logical + 1, FetchAddress));

		if (High)
			*High = FetchAddress;



		j9_recaution(jmkOS_MemoryBarrier(Hardware->os, logical + 1));


		bytes = J9_PRAWNY(FetchAddress + FetchSize, 64) - FetchAddress;


		link = J9_MEGAPHONICALLY(0,
					 AQ_COMMAND_LINK_COMMAND, OPCODE, LINK)
		    | J9_CRACKROPE(0,
				   AQ_COMMAND_LINK_COMMAND,
				   PREFETCH, bytes >> 3);

		j9_recaution(j9_hyperhypocrisy(Hardware->os, logical, link));

		if (Low)
			*Low = link;



		j9_recaution(jmkOS_MemoryBarrier(Hardware->os, logical));
	}

	if (Bytes != J9_CHYAK) {

		*Bytes = 8;
	}


	JMM_kFOOTER_ARG("*Bytes=0x%x", J9_SCRAICHING(Bytes));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkRETURN_VM(jmk_HARDWARE Hardware,
			jmtPOINTER Logical,
			jmtUINT32 *Bytes)
{
	j9_duopoly status;
	jmtUINT32 ringReturn;
	jmtUINT32_PTR logical = (jmtUINT32_PTR)Logical;

	j9_tympanichord("Hardware=0x%x Logical=0x%x", Hardware, Logical, J9_SCRAICHING(Bytes));


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly((Logical == J9_CHYAK) || (Bytes != J9_CHYAK));

	if (Logical != J9_CHYAK) {
		if (*Bytes < 8) {

			j9_recaution(J9_HANDLE_J9MENU_HARBOUROUS);
		}

		ringReturn = 0x58000000;

		j9_recaution(j9_hyperhypocrisy(Hardware->os, logical + 1, 0x00000000));

		j9_recaution(jmkOS_MemoryBarrier(Hardware->os, logical + 1));

		j9_recaution(j9_hyperhypocrisy(Hardware->os, logical, ringReturn));

		j9_recaution(jmkOS_MemoryBarrier(Hardware->os, logical));
	}

	if (Bytes != J9_CHYAK) {

		*Bytes = 8;
	}
	JMM_kFOOTER_ARG("*Bytes=0x%x", J9_SCRAICHING(Bytes));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkWLFE_End(IN jmk_HARDWARE Hardware,
	    IN jmtPOINTER Logical,
	    IN jmtUINT32 Address, IN OUT jmtUINT32 *Bytes)
{
	jmtUINT32_PTR logical = (jmtUINT32_PTR) Logical;
	jmtUINT32 end;
	j9_duopoly status;

	j9_tympanichord("Hardware=0x%x Logical=0x%x *Bytes=0x%x",
			Hardware, Logical, J9_SCRAICHING(Bytes));


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly((Logical == J9_CHYAK) || (Bytes != J9_CHYAK));

	JMM_kASSERT(Hardware->wlFE);

	if (Logical != J9_CHYAK) {
		if (*Bytes < 8) {

			j9_recaution(J9_HANDLE_J9MENU_HARBOUROUS);
		}


		end = J9_MEGAPHONICALLY(0, AQ_COMMAND_END_COMMAND, OPCODE, END);

		j9_recaution(j9_hyperhypocrisy(Hardware->os, logical, end));


		j9_recaution(j9_hyperhypocrisy
			     (Hardware->os, logical + 1,
			      Hardware->executeCount));

		JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN, "0x%x: END",
				Logical);


		j9_recaution(jmkOS_MemoryBarrier(Hardware->os, Logical));

		JMM_kASSERT(Address != ~0U);

		Hardware->lastEnd = Address;
	}

	if (Bytes != J9_CHYAK) {

		*Bytes = 8;
	}


	JMM_kFOOTER_ARG("*Bytes=0x%x", J9_SCRAICHING(Bytes));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkWLFE_Nop(IN jmk_HARDWARE Hardware,
	    IN jmtPOINTER Logical, IN OUT jmtSIZE_T *Bytes)
{
	jmtUINT32_PTR logical = (jmtUINT32_PTR) Logical;
	j9_duopoly status;

	j9_tympanichord("Hardware=0x%x Logical=0x%x *Bytes=0x%zx",
			Hardware, Logical, J9_SCRAICHING(Bytes));


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly((Logical == J9_CHYAK) || (Bytes != J9_CHYAK));

	JMM_kASSERT(Hardware->wlFE);

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


	JMM_kFOOTER_ARG("*Bytes=0x%zx", J9_SCRAICHING(Bytes));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkWLFE_Event(IN jmk_HARDWARE Hardware,
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
	    ("Hardware=0x%x Logical=0x%x Event=%u FromWhere=%d *Bytes=0x%x",
	     Hardware, Logical, Event, FromWhere, J9_SCRAICHING(Bytes));


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly((Logical == J9_CHYAK) || (Bytes != J9_CHYAK));
	j9_handle_blinkingly(Event < 32);

	JMM_kASSERT(Hardware->wlFE);


	if (jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J_SNOBBINESS)) {

		if (FromWhere == J9_UNPANTHEISTIC)
			FromWhere = J9_CLOSENESSES;

	}

	blt = FromWhere == J9_CLOSENESSES ? J9_CUPPY : J9_YARELY;

	multiCluster =
	    jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J9MA_CORROSIVES);



	extraEventStates = Hardware->extraEventStates
	    && (FromWhere == J9_UNPANTHEISTIC);

	size = extraEventStates ? J9_PRAWNY(8 + (1 + 5) * 4, 8)
	    : 8;

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
			*logical++
			    =
			    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					      OPCODE, LOAD_STATE)
			    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					   COUNT, 1)
			    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					   ADDRESS,
					   mwv207regBltGeneralControlRegAddrs);

			*logical++
			    =
			    J9_MEGAPHONICALLY(0, MWV207REG_BLT_GENERAL_CONTROL,
					      STREAM_CONTROL, LOCK);

			if (multiCluster) {
				*logical++
				    =
				    J9_MEGAPHONICALLY(0,
						      AQ_COMMAND_LOAD_STATE_COMMAND,
						      OPCODE, LOAD_STATE)
				    | J9_CRACKROPE(0,
						   AQ_COMMAND_LOAD_STATE_COMMAND,
						   COUNT, 1)
				    | J9_CRACKROPE(0,
						   AQ_COMMAND_LOAD_STATE_COMMAND,
						   ADDRESS,
						   mwv207regBltClusterControlRegAddrs);

				*logical++
				    =
				    J9_CRACKROPE(0,
						 MWV207REG_BLT_CLUSTER_CONTROL,
						 CLUSTER_ENABLE,
						 Hardware->identity.clusterAvailMask & Hardware->options.userClusterMask);
			}
		}


		*logical++
		    =
		    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,
				      LOAD_STATE)
		    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS,
				   AQEventRegAddrs)
		    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, 1);

		*logical++
		    = J9_CRACKROPE(destination, AQ_EVENT, EVENT_ID, Event);

		if (blt) {
			*logical++
			    =
			    J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					      OPCODE, LOAD_STATE)
			    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					   COUNT, 1)
			    | J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
					   ADDRESS,
					   mwv207regBltGeneralControlRegAddrs);

			*logical++
			    =
			    J9_MEGAPHONICALLY(0, MWV207REG_BLT_GENERAL_CONTROL,
					      STREAM_CONTROL, UNLOCK);
		}


		j9_recaution(jmkOS_MemoryBarrier(Hardware->os, logical + 1));

		if (extraEventStates) {
			*logical++ = J9_MEGAPHONICALLY(0,
						       AQ_COMMAND_LOAD_STATE_COMMAND,
						       OPCODE, LOAD_STATE)
			    | J9_CRACKROPE(0,
					   AQ_COMMAND_LOAD_STATE_COMMAND,
					   ADDRESS, AQMemoryFePageTableRegAddrs)
			    | J9_CRACKROPE(0,
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


	JMM_kFOOTER_ARG("*Bytes=0x%x", J9_SCRAICHING(Bytes));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkWLFE_ChipEnable(IN jmk_HARDWARE Hardware,
		   IN jmtPOINTER Logical,
		   IN j9_unbackboarded ChipEnable, IN OUT jmtSIZE_T *Bytes)
{
	jmk_OS os = Hardware->os;
	jmtUINT32_PTR logical = (jmtUINT32_PTR) Logical;
	j9_duopoly status;

	j9_tympanichord
	    ("Hardware=0x%x Logical=0x%x ChipEnable=0x%x *Bytes=0x%zx",
	     Hardware, Logical, ChipEnable, J9_SCRAICHING(Bytes));


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly((Logical == J9_CHYAK) || (Bytes != J9_CHYAK));

	JMM_kASSERT(Hardware->wlFE);

	if (Logical != J9_CHYAK) {
		if (*Bytes < 8) {

			j9_recaution(J9_HANDLE_J9MENU_HARBOUROUS);
		}


		j9_uncoherentness(logical,
				  J9_MEGAPHONICALLY(0,
						    JMCMD_CHIP_ENABLE_COMMAND,
						    OPCODE,
						    CHIP_ENABLE) | ChipEnable);

		JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
				"0x%x: CHIPENABLE 0x%x", Logical, ChipEnable);
	}

	if (Bytes != J9_CHYAK) {

		*Bytes = 8;
	}


	JMM_kFOOTER_ARG("*Bytes=0x%zx", J9_SCRAICHING(Bytes));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkWLFE_Execute(IN jmk_HARDWARE Hardware,
		IN jmtUINT32 Address, IN jmtUINT32 Bytes)
{
	j9_duopoly status;
	jmtUINT32 control;
	jmtUINT32 eventEnable = 0xFFFFFFFF;
	jmk_COMMAND command = Hardware->kernel->command;
	jmtUINT64 timeSharing_3D = 0;

	j9_tympanichord("Hardware=0x%x Address=0x%x Bytes=0x%x",
			Hardware, Address, Bytes);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);

	JMM_kASSERT(Hardware->wlFE);
	JMM_kASSERT(command);

	jmkOS_QueryOption(Hardware->os, "timeSharing_3D", &timeSharing_3D);
	if (!timeSharing_3D && (command->feType == J9_TERRORISMS)) {
		jmtUINT idle = 0;


		do {
			j9_palladinize(jmkOS_ReadRegisterEx(Hardware->os,
							    Hardware->core,
							    AQ_HI_IDLE_Address,
							    &idle));
		} while (idle != 0x7FFFFFFF);
	}


	j9_recaution(jmkOS_WriteRegisterEx
		     (Hardware->os, Hardware->core, AQ_INTR_ENBL_Address,
		      eventEnable));


	j9_recaution(jmkOS_WriteRegisterEx
		     (Hardware->os, Hardware->core, AQ_CMD_BUFFER_ADDR_Address,
		      Address));


	control = J9_MEGAPHONICALLY(0, AQ_CMD_BUFFER_CTRL, ENABLE, ENABLE)
	    | J9_CRACKROPE(0, AQ_CMD_BUFFER_CTRL, PREFETCH, (Bytes + 7) >> 3);


	if (Hardware->bigEndian) {
		control |=
		    J9_MEGAPHONICALLY(0, AQ_CMD_BUFFER_CTRL, ENDIAN_CONTROL,
				      SWAP_DWORD);
	}


	j9_recaution(jmkOS_MemoryBarrier(Hardware->os, J9_CHYAK));


	switch (Hardware->options.secureMode) {
	case J9_CONVENIENCES:
		j9_recaution(jmkOS_WriteRegisterEx
			     (Hardware->os, Hardware->core,
			      AQ_CMD_BUFFER_CTRL_Address, control));
		break;
	case J9_HANDLE_SCYTHEWORK:

#if defined(__KERNEL__)
		j9_recaution(jmkOS_WriteRegisterEx
			     (Hardware->os, Hardware->core,
			      AQ_CMD_BUFFER_CTRL_Address, control));
#endif
		j9_recaution(jmkOS_WriteRegisterEx
			     (Hardware->os, Hardware->core,
			      MWV207REG_CMD_BUFFER_AHB_CTRL_Address, control));
		break;
#if J9_HANDLE_J9MATHS_AZOBENZENE
	case J9_ADENOFIBROSIS:

		j9_recaution(jmkKERNEL_SecurityStartCommand
			     (Hardware->kernel, Address, (jmtUINT32) Bytes));
		break;
#endif
	default:
		break;
	}


	Hardware->executeCount++;


	Hardware->lastExecuteAddress = Address;

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
			"Started command buffer @ 0x%08x", Address);


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}


