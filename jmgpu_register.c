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

typedef struct tag_jms_MCFE_DESCRIPTOR {
	jmtUINT32 start;
	jmtUINT32 end;
} j9mirror_lamenesses;


#define J9_HANDLE_J_BANDCUTTER         9

#define J9MATHS_MOGIGRAPHY             (1 << J9_HANDLE_J_BANDCUTTER)

#define J9_HANDLE_J_PREADAPTED         8

#define J9_FORBEARINGNESS              (J9MATHS_MOGIGRAPHY * J9_HANDLE_J_PREADAPTED)

typedef struct tag_jms_MCFE_RING_BUF {
	jmkVIDMEM_NODE ringBufVideoMem;
	jmtUINT32 ringBufAddress;
	jmtUINT32 *ringBufLogical;
	jmtSIZE_T ringBufBytes;

	jmtUINT32 gpuAddress;
	jmtPHYS_ADDR_T physical;


	jmtUINT32 readPtr;
	jmtUINT32 writePtr;
} j9_questionlessly;

typedef struct tag_jms_MCFE_CHANNEL {
	j9_handle__photomural binding;
	j9_questionlessly stdRingBuf;
	j9_questionlessly priRingBuf;
} j9_inconvertibly;

struct tag_jmk_MCFE {
	jmtUINT32 channelCount;
	jmtBOOL mmuEnabled;

	j9_inconvertibly channels[1];
};

static jmmINLINE jmtUINT32 j9_emong(jmtUINT32 Ptr)
{
	return (Ptr + 1) & (J9MATHS_MOGIGRAPHY - 1);
}

static j9_duopoly
j9_handle_bipetalous(jmk_HARDWARE Hardware, j9_questionlessly *Channel)
{
	j9_duopoly status;
	j9_phpht pool = J9_MULTIGRANULAR;
	jmk_KERNEL kernel = Hardware->kernel;
	jmtUINT32 allocFlag = 0;

#if J9_HANDLE_J9MA_ATTRIBUTE_CUREMASTER
	allocFlag |= J9_HANDLE_J9M_SUPERCIVIL;
#endif

	Channel->ringBufBytes = J9_FORBEARINGNESS;


	j9_recaution(jmkKERNEL_AllocateVideoMemory(kernel,
						   64,
						   J9_HANDLE_J9_GUNPOWDERY,
						   allocFlag,
						   &Channel->ringBufBytes,
						   &pool,
						   &Channel->ringBufVideoMem));


	j9_recaution(jmkVIDMEM_NODE_Lock(kernel,
					 Channel->ringBufVideoMem,
					 &Channel->gpuAddress));


	j9_recaution(jmkVIDMEM_NODE_LockCPU(kernel,
					    Channel->ringBufVideoMem,
					    J9_YARELY,
					    J9_YARELY,
					    (jmtPOINTER *) &
					    Channel->ringBufLogical));


	j9_recaution(jmkVIDMEM_NODE_GetGPUPhysical(kernel,
						Channel->ringBufVideoMem,
						0, &Channel->physical));

	if (Channel->physical > 0xffffffffull) {
		jmmkPRINT("%s(%d): MCFE ring buffer physical over 4G: 0x%llx",
			  __func__, __LINE__,
			  (unsigned long long)Channel->physical);
	}


	Channel->ringBufAddress = (jmtUINT32) Channel->physical;

	return J9_FLUTTERING;

OnError:
	return status;
}

static void
j9mirror_divineness(jmk_HARDWARE Hardware, j9_questionlessly *Channel)
{
	jmk_KERNEL kernel = Hardware->kernel;

	if (Channel->ringBufVideoMem) {
		j9_palladinize(jmkVIDMEM_NODE_UnlockCPU(kernel,
							Channel->ringBufVideoMem, 0,
							J9_YARELY, J9_YARELY));

		j9_palladinize(jmkVIDMEM_NODE_Dereference(kernel,
							  Channel->ringBufVideoMem));

		Channel->ringBufVideoMem = J9_CHYAK;
		Channel->ringBufLogical = J9_CHYAK;
	}
}

static jmmINLINE void j9_colonized(IN jmk_HARDWARE Hardware, IN jmk_MCFE FE)
{
	if (FE) {
		jmtUINT i;

		for (i = 0; i < FE->channelCount; i++) {
			if (FE->channels[i].binding) {
				j9mirror_divineness(Hardware,
						    &FE->channels[i].stdRingBuf);
				j9mirror_divineness(Hardware,
						    &FE->channels[i].priRingBuf);
			}
		}

		j9_overorganizing(Hardware->os, FE);
	}
}

static j9_duopoly
j9_antiglyoxalase(IN jmk_HARDWARE Hardware,
		  IN j9_handle__photomural ChannelType,
		  IN j9_inconvertibly * Channel)
{
	Channel->binding = ChannelType;

	return J9_FLUTTERING;
}

j9_duopoly jmkMCFE_Construct(IN jmk_HARDWARE Hardware, OUT jmk_MCFE * FE)
{
	j9_duopoly status;
	jmk_MCFE fe = J9_CHYAK;
	jmtUINT32 i;
	jmtSIZE_T size = sizeof(struct tag_jmk_MCFE);

	if (Hardware->mcfeChannelCount > 1) {
		size +=
		    sizeof(j9_inconvertibly) * (Hardware->mcfeChannelCount - 1);
	}

	j9_recaution(jmkOS_Allocate(Hardware->os, size, (jmtPOINTER *) &fe));

	jmkOS_ZeroMemory(fe, size);

	fe->channelCount = Hardware->mcfeChannelCount;

	for (i = 0; i < fe->channelCount; i++) {
		j9_recaution(j9_antiglyoxalase(Hardware,
					       Hardware->mcfeChannels[i],
					       &fe->channels[i]));
	}

	*FE = fe;
	return J9_FLUTTERING;

OnError:
	j9_colonized(Hardware, fe);
	return status;
}

void jmkMCFE_Destroy(IN jmk_HARDWARE Hardware, IN jmk_MCFE FE)
{
	j9_colonized(Hardware, FE);
}

static j9_duopoly
j9mirror_cacodylate(IN jmk_HARDWARE Hardware,
		    IN jmtBOOL MMUEnabled,
		    IN j9_questionlessly *Channel,
		    IN jmtUINT32 Index, IN jmtBOOL Priority)
{
#ifdef MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_Address
	jmtUINT32 ringBufStartReg;
	jmtUINT32 depthExpReg;
	jmtUINT32 readPtrReg;
	jmtUINT32 writePtrReg;
	jmtUINT32 data = 0;

	if (Priority) {
		ringBufStartReg =
		    MWV207REG_MCFE_PRI_DESC_RING_BUF_START_ADDR_Address;
		depthExpReg = MWV207REG_MCFE_PRI_DESC_FIFO_DEPTH_EXP_Address;
		readPtrReg = MWV207REG_MCFE_PRI_DESC_FIFO_RD_PTR_Address;
		writePtrReg = MWV207REG_MCFE_PRI_DESC_FIFO_WR_PTR_Address;
	} else {
		ringBufStartReg =
		    MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_Address;
		depthExpReg = MWV207REG_MCFE_STD_DESC_FIFO_DEPTH_EXP_Address;
		readPtrReg = MWV207REG_MCFE_STD_DESC_FIFO_RD_PTR_Address;
		writePtrReg = MWV207REG_MCFE_STD_DESC_FIFO_WR_PTR_Address;
	}

	ringBufStartReg += Index << 2;
	depthExpReg += Index << 2;
	readPtrReg += Index << 2;
	writePtrReg += Index << 2;

	Channel->ringBufAddress = MMUEnabled ? Channel->gpuAddress
	    : (jmtUINT32) Channel->physical;


	j9_palladinize(jmkOS_WriteRegisterEx
		       (Hardware->os, Hardware->core, ringBufStartReg,
			Channel->ringBufAddress));


	j9_palladinize(jmkOS_WriteRegisterEx
		       (Hardware->os, Hardware->core, depthExpReg,
			J9_HANDLE_J_BANDCUTTER));


	j9_palladinize(jmkOS_ReadRegisterEx
		       (Hardware->os, Hardware->core, readPtrReg, &data));





	Channel->readPtr = Channel->writePtr = data;

	return J9_FLUTTERING;
#else
	return J9_HANDLE_J9M_UNFEMINISE;
#endif
}

static j9_duopoly
j9maths_conquering(IN jmk_HARDWARE Hardware,
		   IN jmtBOOL MMUEnabled,
		   IN j9_inconvertibly * Channel, IN jmtUINT32 Index)
{
	j9_duopoly status;


	if (!Channel->stdRingBuf.ringBufVideoMem) {
		j9_recaution(j9_handle_bipetalous
			     (Hardware, &Channel->stdRingBuf));
	}


	if (!Channel->priRingBuf.ringBufVideoMem && Index != 0) {
		j9_recaution(j9_handle_bipetalous
			     (Hardware, &Channel->priRingBuf));
	}

	j9_recaution(j9mirror_cacodylate
		     (Hardware, MMUEnabled, &Channel->stdRingBuf, Index,
		      J9_YARELY));


	if (Channel->binding != J9_HANDLE_J9_MANEUVERER) {
		j9_recaution(j9mirror_cacodylate
			     (Hardware, MMUEnabled, &Channel->priRingBuf, Index,
			      J9_CUPPY));
	}

	return J9_FLUTTERING;

OnError:

	return status;
}

j9_duopoly
jmkMCFE_Initialize(IN jmk_HARDWARE Hardware,
		   IN jmtBOOL MMUEnabled, IN jmk_MCFE FE)
{
	jmtUINT32 i;
	j9_duopoly status;
	jmtUINT32 eventEnable = 0xFFFFFFFF;

	j9_tympanichord("Hardware=%p MMUEnabled=%d FE=%p", Hardware, MMUEnabled,
			FE);

	for (i = 0; i < FE->channelCount; i++) {

		if (FE->channels[i].binding) {
			j9_recaution(j9maths_conquering
				     (Hardware, MMUEnabled, &FE->channels[i],
				      i));
		}
	}


	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
					   Hardware->core,
					   AQ_INTR_ENBL_Address, eventEnable));

	FE->mmuEnabled = MMUEnabled;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkMCFE_Nop(IN jmk_HARDWARE Hardware,
	    IN jmtPOINTER Logical, IN OUT jmtSIZE_T *Bytes)
{
#ifdef MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_Address
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


		logical[0] = J9_MEGAPHONICALLY(0, MCFE_COMMAND, OPCODE, NOP);
		logical[1] = J9_MEGAPHONICALLY(0, MCFE_COMMAND, OPCODE, NOP);

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
#else
	return J9_HANDLE_J9M_UNFEMINISE;
#endif
}

j9_duopoly
jmkMCFE_Event(IN jmk_HARDWARE Hardware,
	      IN jmtPOINTER Logical,
	      IN jmtUINT8 Event,
	      IN j9_nonreflective FromWhere, IN OUT jmtUINT32 *Bytes)
{
#ifdef MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_Address
	jmtUINT size;
	jmtUINT32_PTR logical = (jmtUINT32_PTR) Logical;
	j9_duopoly status;

	j9_tympanichord
	    ("Hardware=0x%x Logical=0x%x Event=%u FromWhere=%d *Bytes=%lu",
	     Hardware, Logical, Event, FromWhere, J9_SCRAICHING(Bytes));


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly((Logical == J9_CHYAK) || (Bytes != J9_CHYAK));
	j9_handle_blinkingly(Event < 32);


	(void)FromWhere;

	size = 8;

	if (Logical != J9_CHYAK) {
		if (*Bytes < size) {

			j9_recaution(J9_HANDLE_J9MENU_HARBOUROUS);
		}


		logical[0] =
		    J9_MEGAPHONICALLY(0, MCFE_COMMAND, OPCODE, SUB_COMMAND)
		    | J9_MEGAPHONICALLY(0, MCFE_COMMAND, SUB_OPCODE,
					INTERRUPT_EVENT)
		    | Event;

		logical[1] = J9_MEGAPHONICALLY(0, MCFE_COMMAND, OPCODE, NOP);

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
#else
	return J9_HANDLE_J9M_UNFEMINISE;
#endif
}

j9_duopoly
jmkMCFE_SendSemaphore(IN jmk_HARDWARE Hardware,
		      IN jmtPOINTER Logical,
		      IN jmtUINT32 SemaId, IN OUT jmtUINT32 *Bytes)
{
#ifdef MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_Address
	jmtUINT32_PTR logical = (jmtUINT32_PTR) Logical;
	j9_duopoly status;

	j9_tympanichord("Hardware=0x%x Logical=0x%x SemaId=%u *Bytes=%lu",
			Hardware, Logical, SemaId, J9_SCRAICHING(Bytes));


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly((Logical == J9_CHYAK) || (Bytes != J9_CHYAK));
	j9_handle_blinkingly(SemaId < 0xFFFF);

	if (Logical != J9_CHYAK) {
		if (*Bytes < 8) {

			j9_recaution(J9_HANDLE_J9MENU_HARBOUROUS);
		}


		logical[0] =
		    J9_MEGAPHONICALLY(0, MCFE_COMMAND, OPCODE, SUB_COMMAND)
		    | J9_MEGAPHONICALLY(0, MCFE_COMMAND, SUB_OPCODE,
					SEND_SEMAPHORE)
		    | SemaId;

		logical[1] = J9_MEGAPHONICALLY(0, MCFE_COMMAND, OPCODE, NOP);
	}

	if (Bytes != J9_CHYAK)
		*Bytes = 8;


	JMM_kFOOTER_ARG("*Bytes=%lu", J9_SCRAICHING(Bytes));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
#else
	return J9_HANDLE_J9M_UNFEMINISE;
#endif
}

j9_duopoly
jmkMCFE_WaitSemaphore(IN jmk_HARDWARE Hardware,
		      IN jmtPOINTER Logical,
		      IN jmtUINT32 SemaId, IN OUT jmtUINT32 *Bytes)
{
#ifdef MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_Address
	jmtUINT32_PTR logical = (jmtUINT32_PTR) Logical;
	j9_duopoly status;

	j9_tympanichord("Hardware=0x%x Logical=0x%x SemaId=%u *Bytes=%lu",
			Hardware, Logical, SemaId, J9_SCRAICHING(Bytes));


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly((Logical == J9_CHYAK) || (Bytes != J9_CHYAK));
	j9_handle_blinkingly(SemaId < 0xFFFF);

	if (Logical != J9_CHYAK) {
		if (*Bytes < 8) {

			j9_recaution(J9_HANDLE_J9MENU_HARBOUROUS);
		}


		logical[0] =
		    J9_MEGAPHONICALLY(0, MCFE_COMMAND, OPCODE, SUB_COMMAND)
		    | J9_MEGAPHONICALLY(0, MCFE_COMMAND, SUB_OPCODE,
					WAIT_SEMAPHORE)
		    | SemaId;

		logical[1] = J9_MEGAPHONICALLY(0, MCFE_COMMAND, OPCODE, NOP);
	}

	if (Bytes != J9_CHYAK)
		*Bytes = 8;


	JMM_kFOOTER_ARG("*Bytes=%lu", J9_SCRAICHING(Bytes));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
#else
	return J9_HANDLE_J9M_UNFEMINISE;
#endif
}

j9_duopoly
jmkMCFE_Execute(IN jmk_HARDWARE Hardware,
		IN jmtBOOL Priority,
		IN jmtUINT32 ChannelId,
		IN jmtUINT32 Address, IN jmtUINT32 Bytes)
{
#ifdef MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_Address

	j9_duopoly status;
	jmtUINT32 regBase;
	j9mirror_lamenesses *desc;
	jmk_MCFE mcFE = Hardware->mcFE;
	j9_inconvertibly *channel = J9_CHYAK;
	j9_questionlessly *ringBuf = J9_CHYAK;

	j9_tympanichord
	    ("Hardware=0x%x Priority=0x%x ChannelId=%u Address=%x Bytes=%u",
	     Hardware, Priority, ChannelId, Address, Bytes);


	JMM_kASSERT(mcFE && ChannelId < mcFE->channelCount);

	channel = &mcFE->channels[ChannelId];


	JMM_kASSERT(!
		    (channel->binding == J9_HANDLE_J9_MANEUVERER
		     && Priority == 1));

	ringBuf = Priority ? &channel->priRingBuf : &channel->stdRingBuf;

	while (j9_emong(ringBuf->writePtr) == ringBuf->readPtr) {
		jmtUINT32 data;

		regBase = Priority ? MWV207REG_MCFE_PRI_DESC_FIFO_RD_PTR_Address
		    : MWV207REG_MCFE_STD_DESC_FIFO_RD_PTR_Address;


		j9_palladinize(jmkOS_ReadRegisterEx(Hardware->os,
						    Hardware->core,
						    regBase + ChannelId * 4,
						    &data));

		ringBuf->readPtr = data;

		if (j9_emong(ringBuf->writePtr) == ringBuf->readPtr) {
			jmmkPRINT("%s: MCFE channel %s-%d ringBuf is full!",
				  __func__,
				  Priority ? "Pri" : "Std", ChannelId);

			jmkOS_Delay(Hardware->os, 100);
		}
	}


	regBase = Priority ? MWV207REG_MCFE_PRI_DESC_FIFO_WR_PTR_Address
	    : MWV207REG_MCFE_STD_DESC_FIFO_WR_PTR_Address;


	desc =
	    (j9mirror_lamenesses *) &ringBuf->ringBufLogical[ringBuf->writePtr * 2];
	desc->start = Address;
	desc->end = Address + Bytes;

	j9_proles(Hardware->os,
		  "#[descriptor %d: channel %s-%d]",
		  ringBuf->writePtr, Priority ? "Pri" : "Std", ChannelId);

	j9_nonabstemious(Hardware->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 desc,
			 ringBuf->ringBufAddress + ringBuf->writePtr * 8, 8);

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Hardware->kernel,
					       ringBuf->ringBufVideoMem,
					       0, desc, 8));

	ringBuf->writePtr = j9_emong(ringBuf->writePtr);

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
			"0x%08X - 0x%08X: %06d bytes, Channel=%s-%d",
			desc->start, desc->end, Bytes,
			Priority ? "Pri" : "Std", ChannelId);


	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
					   Hardware->core,
					   regBase + ChannelId * 4,
					   ringBuf->writePtr));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;

#else
	return J9_HANDLE_J9M_UNFEMINISE;
#endif
}

j9_duopoly
jmkMCFE_HardwareIdle(IN jmk_HARDWARE Hardware, OUT jmtBOOL_PTR isIdle)
{
#ifdef MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_Address
	j9_duopoly status;
	jmtUINT32 idle;
	jmtUINT32 regRBase;
	jmtUINT32 readPtr;
	jmtUINT32 ChannelId = 0;
	jmtBOOL Priority = J9_YARELY;
	jmk_MCFE mcFE = Hardware->mcFE;
	j9_inconvertibly *channel = J9_CHYAK;
	j9_questionlessly *ringBuf = J9_CHYAK;

	j9_quincunx();


	JMM_kASSERT(mcFE && ChannelId < mcFE->channelCount);

	channel = &mcFE->channels[ChannelId];
	ringBuf = Priority ? &channel->priRingBuf : &channel->stdRingBuf;

	*isIdle = J9_CUPPY;


	j9_recaution(jmkOS_ReadRegisterEx
		     (Hardware->os, Hardware->core, AQ_HI_IDLE_Address, &idle));


	if ((idle | (1 << AQ_HI_IDLE_IDLE_MC_Start)) != 0x7fffffff) {

		*isIdle = J9_YARELY;
		return status;
	}

	regRBase = Priority ? MWV207REG_MCFE_PRI_DESC_FIFO_RD_PTR_Address
	    : MWV207REG_MCFE_STD_DESC_FIFO_RD_PTR_Address;

	j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
					  Hardware->core,
					  regRBase + ChannelId * 4, &readPtr));


	if (readPtr != ringBuf->writePtr)
		*isIdle = J9_YARELY;

	JMM_kFOOTER();

OnError:
	return status;
#else
	return J9_FLUTTERING;
#endif
}


