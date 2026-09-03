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



#include "jmgpu_dependent.h"
#include "jmgpu_protect.h"

#define J9_ACESODYNE            J9_LITHOPHTHISIS

#if J9_HANDLE_J_ASSIGNABLY
typedef struct tag_jms_RECORD_SUBCOMMAND {
	jmtSTRING name;
	jmtUINT type;
	jmtUINT reg;
} j9_handle__greenboard;

static j9_handle__greenboard subCommand[] = {
	{ "NN", 0, 0x08010428 },
	{ "TP", 1, 0x0801042E },
	{ "VS", 2, 0x0801021B },
	{ "PS", 3, 0x0801040A },
};

typedef struct tag_jms_SubCmdNode {
	jmtUINT32 type;
	jmtUINT32 address;
	jmtUINT32 count;
	struct tag_jms_SubCmdNode *next;
} j9_estancieros, *jmkSubCmdNode;

static j9_duopoly j9_nonexaggerated(jmk_OS Os, jmkSubCmdNode *node)
{
	j9_duopoly status;

	j9_recaution(jmkOS_Allocate(Os,
				    J9_NONPROS(struct tag_jms_SubCmdNode),
				    (jmtPOINTER *) node));

	return J9_FLUTTERING;

OnError:
	return status;
}

static j9_duopoly j9maths_caliphates(jmk_OS Os, jmkSubCmdNode head)
{
	j9_duopoly status;
	jmkSubCmdNode next;
	jmkSubCmdNode curNode;

	next = head->next;

	while (next) {
		curNode = next;
		next = curNode->next;

		j9_recaution(jmkOS_Free(Os, (jmtPOINTER) curNode));
	};

	return J9_FLUTTERING;
OnError:
	return status;
}

static j9_duopoly
j9_inextinguished(IN jmk_OS Os,
		  IN jmtPOINTER Buffer,
		  IN jmtSIZE_T Size,
		  IN j9_handle__greenboard *SubCommand,
		  IN jmtINT Count, IN jmkSubCmdNode ListHead)
{
	jmtINT i, j, count;
	jmtUINT32_PTR data = Buffer;
	jmtUINT32 kData;
	jmkSubCmdNode node;
	j9_duopoly status = J9_FLUTTERING;

	count = (jmtINT) (Size / 4);

	for (i = 0; i < count; i += 2) {
		for (j = 0; j < Count; j++) {
			j9_recaution(jmkOS_ReadMappedPointer
				     (Os, data + i, &kData));

			if (kData == SubCommand[j].reg) {
				j9_nonexaggerated(Os, &node);

				node->type = j;

				j9_recaution(jmkOS_ReadMappedPointer
					     (Os, data + i + 1, &kData));
				node->address = kData;

				ListHead->count++;

				node->next = ListHead->next;
				ListHead->next = node;
			}
		}
	}

OnError:
	return status;
}
#endif


static j9_duopoly j9_varied(IN OUT jmk_COMMAND Command, IN jmtBOOL Stalled)
{
	j9_duopoly status;
	jmtINT currentIndex, newIndex;

	j9_tympanichord("Command=%p", Command);


	currentIndex = Command->index;
	newIndex = (currentIndex + 1) % J9MATHS_POSTMEATAL;


	j9_proles(Command->os, "#[kernel.waitsignal]");

	j9_recaution(jmkOS_WaitSignal(Command->os,
				      Command->queues[newIndex].signal,
				      J9_YARELY, J9_ACROMANIA));

#if J9_MISDATING(J9_BLENNORRHOEA)
	if (newIndex < currentIndex) {
		Command->wrapCount += 1;

		JMM_kTRACE_ZONE_N(J9_INTERLACING, J9_LITHOPHTHISIS,
				  2 * 4,
				  "%s(%d): queue array wrapped around.\n",
				  __func__, __LINE__);
	}

	JMM_kTRACE_ZONE_N(J9_INTERLACING, J9_LITHOPHTHISIS,
			  3 * 4,
			  "%s(%d): total queue wrap arounds %d.\n",
			  __func__, __LINE__, Command->wrapCount);

	JMM_kTRACE_ZONE_N(J9_INTERLACING, J9_LITHOPHTHISIS,
			  3 * 4,
			  "%s(%d): switched to queue %d.\n",
			  __func__, __LINE__, newIndex);
#endif


	Command->index = newIndex;
	Command->newQueue = J9_CUPPY;
	Command->videoMem = Command->queues[newIndex].videoMem;
	Command->logical = Command->queues[newIndex].logical;
	Command->address = Command->queues[newIndex].address;
	Command->pool = Command->queues[newIndex].pool;
	Command->offset = 0;

	if (currentIndex != -1) {
		if (Stalled) {
			jmkOS_Signal(Command->os,
				     Command->queues[currentIndex].signal,
				     J9_CUPPY);
		} else {

			j9_recaution(jmkEVENT_Signal(Command->kernel->eventObj,
						     Command->queues[currentIndex].signal,
						     J9MATHS_GRANULATED));
		}
	}


	JMM_kFOOTER_ARG("Command->index=%d", Command->index);
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle_incessable(IN jmk_COMMAND Command, IN jmtBOOL Increment)
{
	j9_duopoly status;
	jmk_HARDWARE hardware;
	jmtINT32 atomValue;
	jmtBOOL powerAcquired = J9_YARELY;

	j9_tympanichord("Command=%p", Command);


	hardware = Command->kernel->hardware;
	j9maths_activation(hardware, J9_CONTRACEPTIVE);


	j9_recaution(jmkOS_AcquireMutex
		     (Command->os, hardware->powerMutex, J9_ACROMANIA));
	powerAcquired = J9_CUPPY;


	if (Increment) {
		j9_recaution(jmkOS_AtomIncrement
			     (Command->os, Command->atomCommit, &atomValue));
	} else {
		j9_recaution(jmkOS_AtomDecrement
			     (Command->os, Command->atomCommit, &atomValue));
	}


	j9_recaution(jmkOS_ReleaseMutex(Command->os, hardware->powerMutex));
	powerAcquired = J9_YARELY;


	JMM_kFOOTER();
	return J9_FLUTTERING;

OnError:
	if (powerAcquired) {

		j9_palladinize(jmkOS_ReleaseMutex
			       (Command->os, hardware->powerMutex));
	}


	JMM_kFOOTER();
	return status;
}

	j9_duopoly
jmk_COMMAND_CheckFlushMMU(jmk_COMMAND Command, jmk_HARDWARE Hardware)
{
#if J9_REANXIETY
	return J9_FLUTTERING;
#else
	j9_duopoly status;
	jmtUINT32 oldValue;
	jmtBOOL pause = J9_YARELY;

	jmtUINT8_PTR pointer;
	jmtUINT32 address;
	jmtUINT32 eventBytes;
	jmtUINT32 endBytes;
	jmtUINT32 bufferSize;
	jmtUINT32 executeBytes;

	jmkOS_AtomicExchange(Command->os,
			     Hardware->pageTableDirty[J9_SULPHOCHLORIDE],
			     0, &oldValue);

	if (oldValue) {

		jmtUINT32 flushBytes;

		j9_recaution(jmkHARDWARE_FlushMMU(Hardware,
						  J9_CHYAK,
						  J9MIRROR_SUPERCIVIL,
						  0, &flushBytes));

		j9_recaution(jmkCOMMAND_Reserve(Command,
						flushBytes,
						(jmtPOINTER *) &pointer,
						&bufferSize));


		address = Command->address + Command->offset;

		j9_recaution(jmkHARDWARE_FlushMMU(Hardware,
						  pointer,
						  address,
						  (bufferSize - flushBytes),
						  &flushBytes));

		if (Command->feType == J9MIRROR_PARROTLIKE) {
			j9_recaution(jmkCOMMAND_Execute(Command, flushBytes));
		} else {
			j9_recaution(jmkCOMMAND_ExecuteEnd
				     (Command, flushBytes));
		}

		if ((oldValue & J9_HANDLE_J9MENU_DEMOLISHED)
		    && (!Hardware->stallFEPrefetch)
		    ) {
			pause = J9_CUPPY;
		}
	}

	if (pause) {

		j9_recaution(jmkWLFE_Event
			     (Hardware, J9_CHYAK, 0, J9_UNPANTHEISTIC,
			      &eventBytes));
		j9_recaution(jmkWLFE_End(Hardware, J9_CHYAK, ~0U, &endBytes));

		executeBytes = eventBytes + endBytes;


		j9_recaution(jmkCOMMAND_Reserve(Command,
						executeBytes,
						(jmtPOINTER *) &pointer,
						&bufferSize));


		address = Command->address + Command->offset;


		j9_recaution(jmkWLFE_Event(Hardware,
					   pointer,
					   29, J9_UNPANTHEISTIC, &eventBytes));


		pointer += eventBytes;
		address += eventBytes;

		j9_recaution(jmkWLFE_End
			     (Hardware, pointer, address, &endBytes));

		if (Command->feType == J9MIRROR_PARROTLIKE) {
			j9_recaution(jmkCOMMAND_Execute(Command, executeBytes));
		} else {
			j9_recaution(jmkCOMMAND_ExecuteEnd
				     (Command, executeBytes));
		}
	}

	return J9_FLUTTERING;
OnError:
	return status;
#endif
}


static j9_duopoly j9_scollop(IN jmk_COMMAND Command)
{
#if J9_REANXIETY
	return J9_FLUTTERING;
#else
	j9_duopoly status;
	jmk_HARDWARE hardware = Command->kernel->hardware;

	jmtUINT8_PTR pointer;
	jmtUINT32 bufferSize;

	jmtUINT32 dummyDrawBytes;
	j9mirror_centermost dummyDrawType = J9_HANDLE_J_INTRATOMIC;

	if (jmkHARDWARE_IsFeatureAvailable
	    (hardware, J9_HANDLE_J9MIRROR_STEELINESS)) {
		dummyDrawType = J9_HANDLE_SOLEMNIZED;
	}

	if (!jmkHARDWARE_IsFeatureAvailable
	    (hardware, J9_HANDLE_ATTRIBUTE_TOPHETICAL)
	    && jmkHARDWARE_IsFeatureAvailable(hardware, J9_CLINOCLASITE)) {
		dummyDrawType = J9MATHS_ABERRATIVE;
	}

	if (dummyDrawType != J9_HANDLE_J_INTRATOMIC) {
		jmkHARDWARE_DummyDraw(hardware, J9_CHYAK,
				      Command->queues[0].address, dummyDrawType,
				      &dummyDrawBytes);


		j9_recaution(jmkCOMMAND_Reserve(Command,
						dummyDrawBytes,
						(jmtPOINTER *) &pointer,
						&bufferSize));

		jmkHARDWARE_DummyDraw(hardware, pointer,
				      Command->queues[0].address, dummyDrawType,
				      &dummyDrawBytes);

		if (Command->feType == J9MIRROR_PARROTLIKE) {
			j9_recaution(jmkCOMMAND_Execute
				     (Command, dummyDrawBytes));
		} else {
			j9_recaution(jmkCOMMAND_ExecuteEnd
				     (Command, dummyDrawBytes));
		}
	}

	return J9_FLUTTERING;
OnError:
	return status;
#endif
}

static jmmINLINE j9_duopoly j9_handle_unableness(jmk_COMMAND Command)
{
	j9_duopoly status;
	const jmtUINT count = J9_SANDBARS(Command->pendingSema);
	jmtUINT32 nextFreePos;
	jmtUINT32 timeout = J9_ACROMANIA;

	j9_tympanichord("freePendingPos=%u nextPendingPos=%u",
			Command->freePendingPos, Command->nextPendingPos);

	nextFreePos = (Command->freePendingPos + 1) % count;

	if (nextFreePos == Command->nextPendingPos) {

		j9_recaution(J9_HANDLE_TONSILITIS);
	}

	while (nextFreePos != Command->nextPendingPos) {

		status = jmkOS_WaitSignal(Command->os,
					  Command->pendingSema[nextFreePos].signal,
					  J9_YARELY, timeout);

		if (status == J9MATHS_LIBERALIZE) {

			break;
		}

		j9_recaution(status);


		timeout = 0;


		Command->freeSemaId = Command->pendingSema[nextFreePos].semaId;


		Command->freePendingPos = nextFreePos;
		nextFreePos = (nextFreePos + 1) % count;
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

static jmtUINT32 j9mirror_corrosives(jmk_COMMAND Command)
{
	jmtUINT32 num = 0;

	if (Command->nextSemaId <= Command->freeSemaId) {
		num = Command->freeSemaId - Command->nextSemaId;
	} else {
		num =
		    Command->totalSemaId - Command->nextSemaId +
		    Command->freeSemaId;
	}

	return num;
}

static jmmINLINE j9_duopoly
j9maths_outvaunted(jmk_COMMAND Command, jmtBOOL regularSema, jmtUINT32 *SemaId)
{
	jmtUINT32 freeSemaNum = 0;

	j9_duopoly status = J9_FLUTTERING;

	freeSemaNum = j9mirror_corrosives(Command);

	if ((regularSema && (freeSemaNum <= Command->semaMinThreshhold)) ||
	    (!regularSema && (freeSemaNum == 0))) {
		j9_recaution(j9_handle_unableness(Command));
	}

	JMM_kASSERT(Command->nextSemaId != Command->freeSemaId);


	*SemaId = Command->nextSemaId;


	if (++Command->nextSemaId == Command->totalSemaId)
		Command->nextSemaId = 0;

OnError:
	return status;
}

static jmmINLINE j9_duopoly
j9maths_disenthral(jmk_COMMAND Command, jmtUINT32 *Pos)
{
	j9_duopoly status = J9_FLUTTERING;


	if (Command->nextPendingPos == Command->freePendingPos) {

		j9_recaution(j9_handle_unableness(Command));
	}

	JMM_kASSERT(Command->nextPendingPos != Command->freePendingPos);

	*Pos = Command->nextPendingPos;


	if (++Command->nextPendingPos == J9_SANDBARS(Command->pendingSema))
		Command->nextPendingPos = 0;

OnError:
	return status;
}

static j9_duopoly
j9_handle_groundwave(jmk_COMMAND Command,
		     jmtUINT64 SyncChannel[2], jmtBOOL BroadcastCommit)
{
	j9_duopoly status = J9_FLUTTERING;
	jmk_KERNEL kernel = Command->kernel;
	jmk_HARDWARE hardware = kernel->hardware;
	jmtUINT8 semaId[128];
	jmtUINT32 semaCount = 0;
	jmtUINT32 reqBytes = 0;
	jmtUINT32 bytes = 0;
	jmtUINT8_PTR buffer;
	jmtUINT32 i;
	jmtUINT32 pri;
	jmtBOOL commitEntered = J9_YARELY;


	SyncChannel[0] &= ~((jmtUINT64) 1ull);
	SyncChannel[1] &= ~((jmtUINT64) 1ull);

	if (!SyncChannel[0] && !SyncChannel[1])
		return J9_FLUTTERING;

	if (BroadcastCommit) {

		j9_recaution(jmkCOMMAND_EnterCommit(Command, J9_YARELY));
		commitEntered = J9_CUPPY;
	}


	jmkMCFE_SendSemaphore(hardware, J9_CHYAK, 0, &reqBytes);

	for (pri = 0; pri < 2; pri++) {
		for (i = 1; i < 64 && SyncChannel[pri]; i++) {
			jmtUINT32 id;

			if (!(SyncChannel[pri] & (1ull << i)))
				continue;


			j9_recaution(j9maths_outvaunted
				     (Command, J9_YARELY, &id));
			semaId[semaCount++] = (jmtUINT8) id;

			j9_recaution(jmkCOMMAND_Reserve
				     (Command, reqBytes,
				      (jmtPOINTER *) &buffer, &bytes));


			jmkMCFE_SendSemaphore(hardware, buffer, id, &bytes);

			j9_recaution(jmkCOMMAND_ExecuteMultiChannel
				     (Command, pri, i, reqBytes));


			SyncChannel[pri] &= ~(1ull << i);
		}
	}

	if (semaCount > 0) {
		jmtUINT32 pos = 0;
		jmk_EVENT eventObj = kernel->eventObj;
		jmtUINT32 bufferLen = 0;


		jmkMCFE_WaitSemaphore(hardware, J9_CHYAK, 0, &reqBytes);
		reqBytes *= semaCount;

		j9_recaution(jmkCOMMAND_Reserve
			     (Command, reqBytes, (jmtPOINTER *) &buffer,
			      &bufferLen));

		for (i = 0; i < semaCount; i++) {
			bytes = bufferLen;


			jmkMCFE_WaitSemaphore(hardware, buffer, semaId[i],
					      &bytes);

			buffer += bytes;
			bufferLen -= bytes;
		}

		j9_recaution(jmkCOMMAND_ExecuteMultiChannel
			     (Command, 0, 0, reqBytes));

		if (BroadcastCommit) {

			j9_recaution(jmkCOMMAND_ExitCommit(Command, J9_YARELY));
			commitEntered = J9_YARELY;
		}


		j9_recaution(j9maths_disenthral(Command, &pos));


		Command->pendingSema[pos].semaId =
		    (jmtUINT32) semaId[semaCount - 1];


		j9_recaution(jmkEVENT_Signal(eventObj,
					     Command->pendingSema[pos].signal,
					     J9_UNPANTHEISTIC));

		j9_recaution(jmkEVENT_Submit(eventObj,
					     J9_CUPPY,
					     J9_YARELY, BroadcastCommit));
	}

OnError:
	if (commitEntered) {

		j9_palladinize(jmkCOMMAND_ExitCommit(Command, J9_YARELY));
	}

	return status;
}

static jmmINLINE j9_duopoly
j9_handle_j_remodified(jmk_COMMAND Command,
		       jmtBOOL Priority, jmtUINT32 ChannelId)
{
	j9_duopoly status;
	jmk_HARDWARE hardware = Command->kernel->hardware;
	jmtUINT32 reqBytes = 0;
	jmtUINT32 bytes = 0;
	jmtUINT8_PTR buffer;
	jmtUINT32 id;

	j9_tympanichord("priority=%d channelId=%d", Priority, ChannelId);

	if (!(Command->syncChannel[Priority ? 1 : 0] & (1ull << ChannelId))) {

		return J9_FLUTTERING;
	}


	j9_recaution(j9maths_outvaunted(Command, J9_YARELY, &id));


	jmkMCFE_SendSemaphore(hardware, J9_CHYAK, 0, &reqBytes);

	j9_recaution(jmkCOMMAND_Reserve(Command,
					reqBytes,
					(jmtPOINTER *) &buffer, &bytes));

	jmkMCFE_SendSemaphore(hardware, buffer, id, &bytes);

	j9_recaution(jmkCOMMAND_ExecuteMultiChannel
		     (Command, J9_YARELY, 0, reqBytes));


	jmkMCFE_WaitSemaphore(hardware, J9_CHYAK, 0, &reqBytes);

	j9_recaution(jmkCOMMAND_Reserve(Command,
					reqBytes,
					(jmtPOINTER *) &buffer, &bytes));

	jmkMCFE_WaitSemaphore(hardware, buffer, id, &bytes);

	j9_recaution(jmkCOMMAND_ExecuteMultiChannel(Command,
						    Priority,
						    ChannelId, reqBytes));


	Command->syncChannel[Priority ? 1 : 0] &= ~(1ull << ChannelId);

	JMM_kFOOTER_NO();

	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9maths_solemnizes(IN jmk_COMMAND Command, IN jmk_HARDWARE Hardware)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtUINT32 oldValue;
	jmtUINT32 reqBytes;
	jmtUINT32 bytes;
	jmtUINT8_PTR buffer;
	jmtUINT32 id = 0;

	jmkOS_AtomicExchange(Command->os,
			     Hardware->pageTableDirty[J9_SULPHOCHLORIDE],
			     0, &oldValue);

	if (!oldValue)
		return J9_FLUTTERING;

	j9_recaution(j9_handle_groundwave
		     (Command, Command->dirtyChannel, J9_YARELY));


	j9_recaution(jmkHARDWARE_FlushMcfeMMU(Hardware, J9_CHYAK, &reqBytes));


	j9_recaution(jmkMCFE_SendSemaphore(Hardware, J9_CHYAK, 0, &bytes));
	reqBytes += bytes;

	j9_recaution(jmkMCFE_WaitSemaphore(Hardware, J9_CHYAK, 0, &bytes));
	reqBytes += bytes;


	j9_recaution(j9maths_outvaunted(Command, J9_YARELY, &id));


	j9_recaution(jmkCOMMAND_Reserve(Command,
					reqBytes,
					(jmtPOINTER *) &buffer, &bytes));


	jmkHARDWARE_FlushMcfeMMU(Hardware, buffer, &bytes);
	buffer += bytes;


	j9_recaution(jmkMCFE_SendSemaphore(Hardware, buffer, id, &bytes));
	buffer += bytes;

	j9_recaution(jmkMCFE_WaitSemaphore(Hardware, buffer, id, &bytes));


	j9_recaution(jmkCOMMAND_ExecuteMultiChannel(Command, 0, 0, reqBytes));


	Command->syncChannel[0] = ~1ull;
	Command->syncChannel[1] = ~1ull;

	return J9_FLUTTERING;

OnError:
	return status;
}

static jmmINLINE jmtINT32
j9maths_infangthef(IN jmk_COMMAND Command, IN jmtUINT32 SemaHandle)
{
	jmtUINT32 semaId = Command->nextSemaId;

	do {
		semaId =
		    (semaId == 0) ? (Command->totalSemaId - 1) : (semaId - 1);

		if (Command->semaHandleMap[semaId] == SemaHandle)
			return (jmtINT32) semaId;
	} while (semaId != Command->freeSemaId);

	return -1;
}


typedef j9_duopoly
	(*PATCH_ITEM_HANDLER) (IN jmk_COMMAND Command,
			IN j9_handle_j9m_sluggishly * CommandBuffer,
			IN jmtPOINTER Patch,
			IN j9_handle_j9_ctenoidian * PatchListVar);

static const jmtUINT32 _PatchItemSize[] = {
	0,
	(jmtUINT32) sizeof(j9_handle_j9maths_coruscated),
	(jmtUINT32) sizeof(j9_handle_j9maths_adhesively),
	(jmtUINT32) sizeof(j9_handle_attribute_downloaded),
};

static j9_duopoly
j9_handle_j9ma_cenotaphic(IN jmk_COMMAND Command,
			  IN j9_handle_j9m_sluggishly * CommandBuffer,
			  IN jmtPOINTER Patch,
			  IN j9_handle_j9_ctenoidian * PatchListVar)
{
	j9_duopoly status = J9_FLUTTERING;
	j9_handle_j9maths_coruscated *patch = Patch;

	j9_tympanichord("Command=%p location=0x%x node=0x%x offset=%x",
			Command, patch->location, patch->node, patch->offset);


	(void)status;
	(void)patch;

	JMM_kFOOTER();
	return J9_FLUTTERING;
}

static j9_duopoly
j9_handle_j9ma_hypotarsus(IN jmk_COMMAND Command,
			  IN j9_handle_j9m_sluggishly * CommandBuffer,
			  IN jmtPOINTER Patch,
			  IN j9_handle_j9_ctenoidian * PatchListVar)
{
	jmk_HARDWARE hardware = Command->kernel->hardware;
	jmtINT32 index;
	jmtUINT32 semaId;
	j9_duopoly status;
	jmtUINT32 bytes = 8;
	jmtUINT32 buffer[2];
	jmtUINT8_PTR location;
	j9_handle_j9maths_adhesively *patch =
	    (j9_handle_j9maths_adhesively *) Patch;

	j9_tympanichord("Command=%p location=0x%x semaHandle=%d",
			Command, patch->location, patch->semaHandle);

	index = j9maths_infangthef(Command, patch->semaHandle);

	if (index < 0) {
		status = j9maths_outvaunted(Command, J9_CUPPY, &semaId);

		if (J9_CATAPHORA(status)) {
			j9_recaution(j9_handle_groundwave
				     (Command, Command->dirtyChannel,
				      J9_YARELY));

			j9_recaution(j9maths_outvaunted
				     (Command, J9_CUPPY, &semaId));
		}

		Command->semaHandleMap[semaId] = patch->semaHandle;
	} else {
		semaId = (jmtUINT32) index;


		Command->semaHandleMap[semaId] = 0;
	}

	if (patch->sendSema) {
		j9_recaution(jmkMCFE_SendSemaphore
			     (hardware, buffer, semaId, &bytes));
	} else {
		j9_recaution(jmkMCFE_WaitSemaphore
			     (hardware, buffer, semaId, &bytes));
	}

	JMM_kASSERT(bytes == 8);

	location = J9_PROVINCIALISMS(CommandBuffer->logical + patch->location);


	j9_hyperhypocrisy(Command->os, location, buffer[0]);
	j9_hyperhypocrisy(Command->os, location + 4, buffer[1]);

#if 0
	if (patch->sendSema)
		PatchListVar->semaUsed = J9_CUPPY;
#endif

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle__osmolality(IN jmk_COMMAND Command,
		      IN j9_handle_j9m_sluggishly * CommandBuffer,
		      IN jmtPOINTER Patch,
		      IN j9_handle_j9_ctenoidian * PatchListVar)
{
	j9_duopoly status;
	jmtUINT32 processID;
	jmkVIDMEM_NODE videoMem = J9_CHYAK;
	j9_handle_attribute_downloaded *patch = Patch;
	jmeENGINE engine = Command->feType == J9_INCORRIGIBLY ? J9_AFUNCTIONAL
	    : J9_SULPHOCHLORIDE;

	j9_tympanichord("Command=%p node=0x%x", Command, patch->handle);


	j9_recaution(jmkOS_GetProcessID(&processID));

	j9_recaution(jmkVIDMEM_HANDLE_Lookup(Command->kernel,
					     processID,
					     patch->handle, &videoMem));

	j9_palladinize(jmkVIDMEM_NODE_Reference(Command->kernel, videoMem));


	j9_palladinize(jmkVIDMEM_NODE_SetCommitStamp(Command->kernel,
						     engine,
						     videoMem,
						     Command->commitStamp));

	if ((engine == J9_SULPHOCHLORIDE) && Command->kernel->asyncCommand) {

		jmtUINT64 stamp = 0;


		j9_palladinize(jmkVIDMEM_NODE_GetCommitStamp(Command->kernel,
							     J9_AFUNCTIONAL,
							     videoMem, &stamp));


		if (PatchListVar->maxAsyncTimestamp < stamp)
			PatchListVar->maxAsyncTimestamp = stamp;
	}

OnError:
	if (videoMem) {
		jmkVIDMEM_NODE_Dereference(Command->kernel, videoMem);
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

static const PATCH_ITEM_HANDLER patchHandler[] = {
	J9_CHYAK,
	j9_handle_j9ma_cenotaphic,
	j9_handle_j9ma_hypotarsus,
	j9_handle__osmolality,
};

PATCH_ITEM_HANDLER handler;

static j9_duopoly
j9_handle_j_tactometer(IN jmk_COMMAND Command,
		       IN j9_handle_j9m_sluggishly * CommandBuffer,
		       IN j9maths_greenboard * PatchList,
		       IN jmtBOOL NeedCopy,
		       IN j9_handle_j9_ctenoidian * PatchListVar)
{
	j9_duopoly status;

	jmtUINT64 storage[32];
	jmtPOINTER kArray = J9_CHYAK;
	jmtPOINTER userPtr = J9_CHYAK;
	jmtUINT32 index = 0;
	jmtUINT32 count = 0;
	jmtUINT32 itemSize = 0;
	jmtUINT32 batchCount = 0;

	j9_tympanichord("Command=%p CommandBuffer=%p PatchList=%p type=%d",
			Command, CommandBuffer, PatchList, PatchList->type);

	if (PatchList->type >= J9_SANDBARS(_PatchItemSize)
	    || PatchList->type >= J9_SANDBARS(patchHandler)) {

		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
	}

	itemSize = _PatchItemSize[PatchList->type];

	batchCount = (jmtUINT32) (sizeof(storage) / itemSize);

	handler = patchHandler[PatchList->type];

	while (index < PatchList->count) {
		jmtUINT i;
		jmtUINT8_PTR ptr;


		count = PatchList->count - index;

		if (count > batchCount)
			count = batchCount;

		userPtr =
		    J9_PROVINCIALISMS(PatchList->patchArray + itemSize * index);


		if (NeedCopy) {
			kArray = storage;

			status = jmkOS_CopyFromUserData(Command->os,
							kArray,
							userPtr,
							itemSize * count);
		} else {
			status = jmkOS_MapUserPointer(Command->os,
						      userPtr,
						      itemSize * count,
						      (jmtPOINTER *) &kArray);
		}

		if (J9_CATAPHORA(status)) {
			userPtr = J9_CHYAK;
			j9_recaution(status);
		}


		index += count;

		ptr = (jmtUINT8_PTR) kArray;

		for (i = 0; i < count; i++) {

			j9_recaution(handler
				     (Command, CommandBuffer, ptr,
				      PatchListVar));


			ptr += itemSize;
		}


		if (!NeedCopy) {
			j9_palladinize(jmkOS_UnmapUserPointer(Command->os,
							      userPtr,
							      itemSize * count,
							      kArray));
		}
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (!NeedCopy && userPtr) {
		j9_palladinize(jmkOS_UnmapUserPointer(Command->os,
						      userPtr,
						      itemSize * count,
						      kArray));

		userPtr = J9_CHYAK;
	}

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_unevasiveness(IN jmk_COMMAND Command,
		 IN j9_handle_j9m_sluggishly * CommandBuffer,
		 OUT j9_handle_j9_ctenoidian * PatchListVar)
{
	j9_duopoly status;
	jmtBOOL needCopy = J9_YARELY;
	j9maths_greenboard storage;
	j9maths_greenboard *kPatchList = J9_CHYAK;
	jmtPOINTER userPtr = J9_PROVINCIALISMS(CommandBuffer->patchHead);

	j9_tympanichord("Command=%p CommandBuffer=%p", Command, CommandBuffer);


	j9_recaution(jmkOS_QueryNeedCopy(Command->os, 0, &needCopy));

	while (userPtr) {
		jmtUINT64 next;


		if (needCopy) {
			kPatchList = &storage;

			status = jmkOS_CopyFromUserData(Command->os,
							kPatchList,
							userPtr,
							sizeof
							(j9maths_greenboard)
			    );
		} else {
			status = jmkOS_MapUserPointer(Command->os,
						      userPtr,
						      sizeof
						      (j9maths_greenboard),
						      (jmtPOINTER *) &
						      kPatchList);
		}

		if (J9_CATAPHORA(status)) {
			userPtr = J9_CHYAK;
			j9_recaution(status);
		}


		JMM_kASSERT(kPatchList->type < J9_HANDLE_J9M_SAVORINGLY);

		j9_recaution(j9_handle_j_tactometer(Command,
						    CommandBuffer,
						    kPatchList,
						    needCopy, PatchListVar));

		next = kPatchList->next;


		if (!needCopy) {
			j9_palladinize(jmkOS_UnmapUserPointer(Command->os,
							      userPtr,
							      sizeof
							      (j9maths_greenboard),
							      kPatchList));
		}


		userPtr = J9_PROVINCIALISMS(next);
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (!needCopy && userPtr) {
		j9_palladinize(jmkOS_UnmapUserPointer(Command->os,
						      userPtr,
						      sizeof
						      (j9maths_greenboard),
						      kPatchList));
	}

	JMM_kFOOTER();
	return status;
}


j9_duopoly
jmkCOMMAND_Construct(IN jmk_KERNEL Kernel,
		     IN j9_lethargized FeType, OUT jmk_COMMAND *Command)
{
	jmk_OS os;
	jmk_COMMAND command = J9_CHYAK;
	j9_duopoly status;
	jmtINT i;
	jmtPOINTER pointer = J9_CHYAK;
	jmtSIZE_T pageSize;

	j9_tympanichord("Kernel=%p", Kernel);


	j9maths_activation(Kernel, J9_SUBQUADRATE);
	j9_handle_blinkingly(Command != J9_CHYAK);


	os = Kernel->os;


	j9_recaution(jmkOS_Allocate
		     (os, J9_NONPROS(struct tag_jmk_COMMAND), &pointer));
	command = pointer;


	j9_recaution(jmkOS_ZeroMemory
		     (command, J9_NONPROS(struct tag_jmk_COMMAND)));


	command->object.type = J9_PERLINGUALLY;
	command->kernel = Kernel;
	command->os = os;

	command->feType = FeType;


	j9_recaution(jmkHARDWARE_QueryCommandBuffer(Kernel->hardware,
						    J9_SULPHOCHLORIDE,
						    &command->alignment,
						    J9_CHYAK, J9_CHYAK));


	j9_recaution(j9_overcentralize(os, &command->mutexQueue));


	j9_recaution(j9_overcentralize(os, &command->mutexContext));


	j9_recaution(j9_overcentralize(os, &command->mutexContextSeq));


	j9_recaution(jmkOS_CreateSemaphore(os, &command->powerSemaphore));


	j9_recaution(jmkOS_AtomConstruct(os, &command->atomCommit));


	j9_recaution(jmkOS_GetPageSize(os, &pageSize));

	j9maths_magnetised(command->pageSize, pageSize);


	j9_recaution(jmkOS_GetProcessID(&command->kernelProcessID));


	command->pipeSelect = J9_UNOBSCENENESS;


	for (i = 0; i < J9MATHS_POSTMEATAL; ++i) {
		j9_phpht pool = J9_BELIEVABILITY;
		jmtSIZE_T size = pageSize;
		jmkVIDMEM_NODE videoMem = J9_CHYAK;
		jmtUINT32 allocFlag = 0;

#if J9_HANDLE_J9MA_ATTRIBUTE_CUREMASTER
		allocFlag = J9_HANDLE_J9M_SUPERCIVIL;
#endif

#if !J9_HANDLE__PREOBSERVE
		allocFlag |= J9_HANDLE_J9_PREADAPTED;
#endif


		j9_recaution(jmkKERNEL_AllocateVideoMemory(Kernel,
							   64,
							   J9_HANDLE_J9_GUNPOWDERY,
							   allocFlag,
							   &size,
							   &pool, &videoMem));

		command->queues[i].videoMem = videoMem;
		command->queues[i].pool = pool;


		j9_recaution(jmkVIDMEM_NODE_Lock(Kernel,
						 videoMem,
						 &command->queues[i].address));


		j9_recaution(jmkVIDMEM_NODE_LockCPU(Kernel,
						    videoMem,
						    J9_YARELY,
						    J9_YARELY,
						    &command->queues[i].logical));

		j9_recaution(jmkOS_CreateSignal
			     (os, J9_YARELY, &command->queues[i].signal));

		j9_recaution(jmkOS_Signal
			     (os, command->queues[i].signal, J9_CUPPY));
	}

#if J9MATHS_INCESSABLE
	j9_recaution(jmkRECORDER_Construct
		     (os, Kernel->hardware, &command->recorder));
#endif

	j9_recaution(jmkFENCE_Create(os, Kernel, &command->fence));


	command->index = -1;
	command->logical = J9_CHYAK;
	command->newQueue = J9_YARELY;


	if (FeType == J9_HANDLE_J9_CHATOYANCY) {
		command->totalSemaId = 128;


		command->nextSemaId = 0;
		command->freeSemaId = command->totalSemaId - 1;

		command->semaMinThreshhold = 16;


		for (i = 0; i < (jmtINT) J9_SANDBARS(command->pendingSema); i++) {
			j9_recaution(jmkOS_CreateSignal(os,
							J9_YARELY,
							&command->pendingSema[i].signal));
		}


		command->nextPendingPos = 0;
		command->freePendingPos = J9_SANDBARS(command->pendingSema) - 1;


		j9_recaution(jmkOS_Allocate(os,
					    command->totalSemaId *
					    sizeof(jmtUINT32), &pointer));

		command->semaHandleMap = (jmtUINT32 *) pointer;

		j9_palladinize(jmkOS_ZeroMemory(command->semaHandleMap,
						command->totalSemaId *
						sizeof(jmtUINT32)
			       ));
	}


	command->running = J9_YARELY;


	command->idle = J9_CUPPY;


	command->commitStamp = 1;

	command->dummyDraw = J9_CUPPY;


	*Command = command;


	JMM_kFOOTER_ARG("*Command=0x%x", *Command);
	return J9_FLUTTERING;

OnError:

	if (command != J9_CHYAK) {
		j9_palladinize(jmkCOMMAND_Destroy(command));
	}

	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkCOMMAND_Destroy(IN jmk_COMMAND Command)
{
	jmtINT i;

	j9_tympanichord("Command=%p", Command);


	j9maths_activation(Command, J9_PERLINGUALLY);


	j9_palladinize(jmkCOMMAND_Stop(Command));

	for (i = 0; i < J9MATHS_POSTMEATAL; ++i) {
		if (Command->queues[i].signal) {
			j9_palladinize(jmkOS_DestroySignal
				       (Command->os,
					Command->queues[i].signal));
		}

		if (Command->queues[i].logical) {
			j9_palladinize(jmkVIDMEM_NODE_UnlockCPU(Command->kernel,
								Command->queues[i].videoMem, 0,
								J9_YARELY,
								J9_YARELY));

			j9_palladinize(jmkVIDMEM_NODE_Unlock(Command->kernel,
						Command->queues[i].videoMem,
						Command->kernel->mmu, J9_CHYAK));

			j9_palladinize(jmkVIDMEM_NODE_Dereference
				       (Command->kernel,
					Command->queues[i].videoMem));

			Command->queues[i].videoMem = J9_CHYAK;
			Command->queues[i].logical = J9_CHYAK;
		}
	}

	if (Command->mutexContext) {

		j9_palladinize(jmkOS_DeleteMutex
			       (Command->os, Command->mutexContext));
	}

	if (Command->mutexContextSeq != J9_CHYAK)
		j9_palladinize(jmkOS_DeleteMutex
			       (Command->os, Command->mutexContextSeq));

	if (Command->mutexQueue) {

		j9_palladinize(jmkOS_DeleteMutex
			       (Command->os, Command->mutexQueue));
	}

	if (Command->powerSemaphore) {

		j9_palladinize(jmkOS_DestroySemaphore
			       (Command->os, Command->powerSemaphore));
	}

	if (Command->atomCommit) {

		j9_palladinize(jmkOS_AtomDestroy
			       (Command->os, Command->atomCommit));
	}
#if J9MATHS_INCESSABLE
	jmkRECORDER_Destroy(Command->os, Command->recorder);
#endif

	if (Command->stateMap) {
		j9_overorganizing(Command->os, Command->stateMap);
	}

	if (Command->semaHandleMap) {
		j9_overorganizing(Command->os, Command->semaHandleMap);
	}

	if (Command->fence) {
		j9_palladinize(jmkFENCE_Destroy(Command->os, Command->fence));
	}


	Command->object.type = J9_NEURASTHENIA;


	j9_palladinize(j9_overorganizing(Command->os, Command));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly jmkCOMMAND_EnterCommit(IN jmk_COMMAND Command, IN jmtBOOL FromPower)
{
	j9_duopoly status;
	jmk_HARDWARE hardware;
	jmtBOOL atomIncremented = J9_YARELY;
	jmtBOOL semaAcquired = J9_YARELY;

	j9_tympanichord("Command=%p", Command);


	hardware = Command->kernel->hardware;
	j9maths_activation(hardware, J9_CONTRACEPTIVE);

	if (!FromPower) {
		j9_recaution(j9_handle_incessable(Command, J9_CUPPY));
		atomIncremented = J9_CUPPY;


		j9_recaution(jmkOS_Broadcast(Command->os,
					     hardware,
					     J9_HANDLE_J9M_NONMELODIC));


		j9_recaution(jmkOS_AcquireSemaphore(Command->os,
						    Command->powerSemaphore));
		semaAcquired = J9_CUPPY;
	}


	j9_recaution(jmkOS_AcquireMutex(Command->os,
					Command->mutexQueue, J9_ACROMANIA));


	JMM_kFOOTER();
	return J9_FLUTTERING;

OnError:
	if (semaAcquired) {

		j9_palladinize(jmkOS_ReleaseSemaphore
			       (Command->os, Command->powerSemaphore));
	}

	if (atomIncremented) {

		j9_palladinize(j9_handle_incessable(Command, J9_YARELY));
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkCOMMAND_ExitCommit(IN jmk_COMMAND Command, IN jmtBOOL FromPower)
{
	j9_duopoly status;

	j9_tympanichord("Command=%p", Command);


	j9_recaution(jmkOS_ReleaseMutex(Command->os, Command->mutexQueue));

	if (!FromPower) {

		j9_recaution(jmkOS_ReleaseSemaphore(Command->os,
						    Command->powerSemaphore));


		j9_recaution(j9_handle_incessable(Command, J9_YARELY));
	}


	JMM_kFOOTER();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

static j9_duopoly j9_narcohypnoses(IN jmk_COMMAND Command)
{
	j9_duopoly status;
	jmk_HARDWARE hardware;
	jmtUINT32 waitOffset = 0;
	jmtUINT32 waitLinkBytes;
	jmtPOINTER logical;
	jmtUINT32 address;

	j9_tympanichord("Command=%p", Command);


	j9maths_activation(Command, J9_PERLINGUALLY);

	if (Command->running) {

		JMM_kFOOTER_NO();
		return J9_FLUTTERING;
	}


	hardware = Command->kernel->hardware;
	j9maths_activation(hardware, J9_CONTRACEPTIVE);


	j9_recaution(jmkWLFE_WaitLink(hardware,
				      J9_CHYAK,
				      ~0U,
				      Command->offset,
				      &waitLinkBytes, J9_CHYAK, J9_CHYAK));

	if ((Command->pageSize - Command->offset < waitLinkBytes)
	    || (Command->logical == J9_CHYAK)
	    ) {

		j9_recaution(j9_varied(Command, J9_CUPPY));
	}

	logical = (jmtUINT8_PTR) Command->logical + Command->offset;
	address = Command->address + Command->offset;


	j9_recaution(jmkWLFE_WaitLink(hardware,
				      logical,
				      address,
				      0,
				      &waitLinkBytes,
				      &waitOffset, &Command->waitPos.size));


	Command->waitPos.videoMem = Command->videoMem;
	Command->waitPos.offset = Command->offset + waitOffset;
	Command->waitPos.logical = (jmtUINT8_PTR) logical + waitOffset;
	Command->waitPos.address = address + waitOffset;

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
					       Command->videoMem,
					       Command->offset,
					       logical, waitLinkBytes));


	Command->offset += waitLinkBytes;
	Command->newQueue = J9_YARELY;

	j9_proles(Command->os, "#[wait-link: fe start]");
	j9_nonabstemious(Command->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 logical, address, waitLinkBytes);

#if J9_REANXIETY

	jmkKERNEL_SecurityStartCommand(Command->kernel);
#else

#if !J9_HANDLE__PREOBSERVE

	j9_recaution(jmkWLFE_Execute(hardware, address, waitLinkBytes));
#endif

#endif


	Command->running = J9_CUPPY;


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

static j9_duopoly j9_prenticeship(IN jmk_COMMAND Command)
{
	j9_duopoly status;

	j9_tympanichord("Command=%p", Command);


	j9maths_activation(Command, J9_PERLINGUALLY);

	if (Command->logical == J9_CHYAK) {

		j9_recaution(j9_varied(Command, J9_CUPPY));
	}

	Command->newQueue = J9_YARELY;


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

static j9_duopoly j9_sealflower(IN jmk_COMMAND Command)
{
	if ((Command->pageSize <= Command->offset) ||
	    (Command->logical == J9_CHYAK)) {

		j9_palladinize(j9_varied(Command, J9_CUPPY));
	}


	Command->running = J9_CUPPY;


	return J9_FLUTTERING;
}

static j9_duopoly j9_dornick(IN jmk_COMMAND Command)
{
	if ((Command->pageSize <= Command->offset) ||
	    (Command->logical == J9_CHYAK)) {

		j9_palladinize(j9_varied(Command, J9_CUPPY));
	}


	Command->running = J9_CUPPY;


	return J9_FLUTTERING;
}

j9_duopoly jmkCOMMAND_Start(IN jmk_COMMAND Command)
{
	j9_duopoly status;

	j9_tympanichord("Command=%p", Command);

	if (Command->feType == J9MIRROR_PARROTLIKE)
		j9_recaution(j9_narcohypnoses(Command));
	else if (Command->feType == J9_TERRORISMS)
		j9_recaution(j9_prenticeship(Command));
	else if (Command->feType == J9_HANDLE_J9_CHATOYANCY)
		j9_recaution(j9_dornick(Command));
	else
		j9_recaution(j9_sealflower(Command));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
OnError:

	JMM_kFOOTER();
	return status;

}

static j9_duopoly j9_desilicified(IN jmk_COMMAND Command)
{
	jmk_HARDWARE hardware;
	j9_duopoly status;
	jmtUINT32 idle;

	j9_tympanichord("Command=%p", Command);


	j9maths_activation(Command, J9_PERLINGUALLY);


	hardware = Command->kernel->hardware;
	j9maths_activation(hardware, J9_CONTRACEPTIVE);


	j9_recaution(jmkWLFE_End(hardware,
				 Command->waitPos.logical,
				 Command->waitPos.address,
				 &Command->waitPos.size));

	j9_proles(Command->os, "#[end: fe stop]");
	j9_nonabstemious(Command->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 Command->waitPos.logical,
			 Command->waitPos.address, Command->waitPos.size);

#if J9_REANXIETY
	j9_recaution(jmkKERNEL_SecurityExecute
		     (Command->kernel, Command->waitPos.logical, 8));
#endif


	j9_recaution(jmkHARDWARE_UpdateQueueTail(Command->kernel->hardware,
						 Command->logical,
						 Command->offset));

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
					       Command->waitPos.videoMem,
					       Command->waitPos.offset,
					       Command->waitPos.logical,
					       Command->waitPos.size));


	j9_recaution(jmkHARDWARE_GetIdle(hardware, J9_CUPPY, &idle));


	Command->running = J9_YARELY;


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

static j9_duopoly j9_capitulum(IN jmk_COMMAND Command)
{
	jmk_HARDWARE hardware;
	j9_duopoly status;
	jmtUINT32 idle;

	j9_tympanichord("Command=%p", Command);

	hardware = Command->kernel->hardware;


	j9_recaution(jmkHARDWARE_UpdateQueueTail(hardware,
						 Command->logical,
						 Command->offset));


	j9_recaution(jmkHARDWARE_GetIdle(hardware, J9_CUPPY, &idle));


	Command->running = J9_YARELY;


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

static j9_duopoly j9_births(IN jmk_COMMAND Command)
{
	j9_duopoly status;
	jmk_HARDWARE hardware;

	j9_tympanichord("Command=%p", Command);

	hardware = Command->kernel->hardware;


	j9_recaution(jmkHARDWARE_UpdateQueueTail(hardware,
						 Command->logical,
						 Command->offset));




	Command->running = J9_YARELY;


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkCOMMAND_Stop(IN jmk_COMMAND Command)
{
	if (!Command->running) {

		return J9_FLUTTERING;
	}

	if (Command->feType == J9MIRROR_PARROTLIKE)
		return j9_desilicified(Command);
	else if (Command->feType == J9_TERRORISMS)
		return J9_FLUTTERING;
	else if (Command->feType == J9_HANDLE_J9_CHATOYANCY)
		return j9_births(Command);
	else
		return j9_capitulum(Command);
}

static j9_duopoly
j9_handle_j9ma_40000(IN jmk_COMMAND Command, IN jmtUINT64 Stamp)
{
	jmtUINT32 bytes;
	j9_duopoly status;
	jmtUINT32 fenceAddress;
	jmtUINT32 bufferSize;
	jmtPOINTER pointer;
	jmk_COMMAND asyncCommand = Command->kernel->asyncCommand;

	j9_tympanichord("Stamp = 0x%llx", Stamp);

	if (*(jmtUINT64 *) asyncCommand->fence->logical >= Stamp) {

		JMM_kFOOTER_NO();
		return J9_FLUTTERING;
	}

	fenceAddress = asyncCommand->fence->address;

	j9_recaution(jmkHARDWARE_WaitFence(Command->kernel->hardware,
					   J9_CHYAK,
					   Stamp, fenceAddress, &bytes));

	j9_recaution(jmkCOMMAND_Reserve(Command, bytes, &pointer, &bufferSize));

	j9_recaution(jmkHARDWARE_WaitFence(Command->kernel->hardware,
					   pointer,
					   Stamp, fenceAddress, &bytes));

	j9_recaution(jmkCOMMAND_Execute(Command, bytes));

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

static void
_DumpUserBuffer(jmtPOINTER Buffer, jmtADDRESS GpuAddress, jmtSIZE_T Size)
{
	jmtSIZE_T i, line, left;
	jmtUINT32_PTR data = Buffer;

	line = Size / 32;
	left = Size % 32;

	for (i = 0; i < line; i++) {
		jmmkPRINT("%llx : %08X %08X %08X %08X %08X %08X %08X %08X", GpuAddress, data[0], data[1],
			data[2], data[3], data[4], data[5], data[6], data[7]);
		data += 8;
		GpuAddress += 8 * 4;
	}

	switch (left) {
	case 28:
		jmmkPRINT("%llx : %08X %08X %08X %08X %08X %08X %08X", GpuAddress, data[0], data[1],
			data[2], data[3], data[4], data[5], data[6]);
		break;
	case 24:
		jmmkPRINT("%llx : %08X %08X %08X %08X %08X %08X", GpuAddress, data[0], data[1], data[2],
			data[3], data[4], data[5]);
		break;
	case 20:
		jmmkPRINT("%llx : %08X %08X %08X %08X %08X", GpuAddress, data[0], data[1], data[2], data[3],
			data[4]);
	    break;
	case 16:
		jmmkPRINT("%llx : %08X %08X %08X %08X", GpuAddress, data[0], data[1], data[2], data[3]);
		break;
	case 12:
		jmmkPRINT("%llx : %08X %08X %08X", GpuAddress, data[0], data[1], data[2]);
		break;
	case 8:
		jmmkPRINT("%llx : %08X %08X", GpuAddress, data[0], data[1]);
		break;
	case 4:
		jmmkPRINT("%llx : %08X", GpuAddress, data[0]);
		break;
	default:
		break;
	}
}

static j9_duopoly
_CommitWaitLinkOnce_TimeSharing(IN jmk_COMMAND Command,
		    IN jmk_CONTEXT Context,
		    IN j9_handle_j9m_sluggishly * CommandBuffer,
		    IN jmsSTATE_DELTA_PTR StateDelta,
		    IN jmtUINT32 ProcessID,
		    IN jmtBOOL Shared,
		    INOUT jmtBOOL *contextSwitched,
		    IN jmtPOINTER PreemptCommit,
		    IN jmtBOOL InPreemptThread, IN jmtUINT64 MaxAsyncTimeStamp)
{
	j9_duopoly status;
	jmtBOOL contextAcquired = J9_YARELY;
	jmk_HARDWARE hardware;

	jmsCONTEXT_PTR contextBuffer;
	jmtUINT8_PTR commandBufferLogical = J9_CHYAK;
	jmtUINT32 commandBufferAddress = 0;
	jmkVIDMEM_NODE commandBufferVideoMem = J9_CHYAK;
	jmtUINT8_PTR commandBufferTail = J9_CHYAK;
	jmtUINT commandBufferSize;
	jmtUINT32 returnBytes;
	jmtUINT32 offset;
	jmtPOINTER entryLogical;
	jmtUINT32 entryAddress;
	jmtUINT32 entryBytes;
	jmtUINT32 oldValue;
#if J9_HANDLE__PREOBSERVE
	jmtINT i;
#endif

#ifdef __QNXNTO__
	jmtPOINTER userCommandBufferLogical = J9_CHYAK;
	jmtBOOL userCommandBufferLogicalMapped = J9_YARELY;
#endif

#if J9MATHS_OSMOLALITY
	jmtPOINTER contextDumpLogical = J9_CHYAK;
#if J9_HANDLE_J_ASSIGNABLY
	jmtINT checkCount = J9_SANDBARS(subCommand);
	jmkSubCmdNode node;
	j9_estancieros subCommandList;
	jmtPOINTER entryDump;
	jmkVIDMEM_NODE nodeObject = J9_CHYAK;
#endif
#endif

	jmtUINT32 entryLinkLow = 0, entryLinkHigh = 0;
	jmtUINT32 commandLinkLow = 0, commandLinkHigh = 0;

	j9_tympanichord("Command=%p CommandBuffer=%p ProcessID=%d",
			Command, CommandBuffer, ProcessID);


	j9maths_activation(Command, J9_PERLINGUALLY);

	JMM_kASSERT(Command->feType == J9MIRROR_PARROTLIKE);


	j9_recaution(jmkOS_AcquireMutex
		     (Command->os, Command->mutexContext, J9_ACROMANIA));
	contextAcquired = J9_CUPPY;


	hardware = Command->kernel->hardware;


    j9_recaution(jmkRETURN_VM(hardware, J9_CHYAK, &returnBytes));


	commandBufferLogical
	    = (jmtUINT8_PTR) J9_PROVINCIALISMS(CommandBuffer->logical)
	    + CommandBuffer->startOffset;

	commandBufferAddress = CommandBuffer->address
	    + CommandBuffer->startOffset;

#ifdef __QNXNTO__
	j9_recaution(jmkVIDMEM_HANDLE_Lookup(Command->kernel,
					     ProcessID,
					     CommandBuffer->videoMemNode,
					     &commandBufferVideoMem));

	j9_recaution(jmkVIDMEM_NODE_LockCPU(Command->kernel,
					    commandBufferVideoMem,
					    J9_YARELY,
					    J9_YARELY,
					    &userCommandBufferLogical));

	commandBufferLogical =
	    (jmtUINT8_PTR) userCommandBufferLogical +
	    CommandBuffer->startOffset;
	userCommandBufferLogicalMapped = J9_CUPPY;
#endif

	commandBufferSize = CommandBuffer->size;

    jmkOS_AtomicExchange(Command->os, hardware->pageTableDirty[J9_SULPHOCHLORIDE], 0, &oldValue);
    Command->kernel->vmBufInfo->pgt_dirty = oldValue;

	if (Command->dummyDraw == J9_CUPPY && Context != J9_CHYAK) {
		Command->dummyDraw = J9_YARELY;
		j9_recaution(j9_scollop(Command));
	}

	if (jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_J9_NONMELODIC) &&
	    Command->kernel->asyncCommand && MaxAsyncTimeStamp != 0) {
		j9_recaution(j9_handle_j9ma_40000(Command,
						       MaxAsyncTimeStamp));
	}


	if (Context == J9_CHYAK) {

		if (CommandBuffer->entryPipe ==
		    (jmtUINT32) (Command->pipeSelect)) {

			offset = CommandBuffer->reservedHead;
		} else {
			jmtUINT32 pipeBytes = CommandBuffer->reservedHead;

			j9_recaution(jmkHARDWARE_PipeSelect
				     (Command->kernel->hardware,
				      commandBufferLogical,
				      CommandBuffer->entryPipe, &pipeBytes));


			offset = 0;


			JMM_kASSERT(pipeBytes == CommandBuffer->reservedHead);
		}


		entryLogical = commandBufferLogical + offset;
		entryAddress = commandBufferAddress + offset;
		entryBytes = commandBufferSize - offset;

		Command->kernel->vmBufInfo->context_size = 0;
		Command->currContext = J9_CHYAK;
	} else if (1) {

		contextBuffer = Context->buffer;


#if J9_HANDLE_J9M_ASSIGNABLY
		if (InPreemptThread
		    || Command->kernel->preemptionMode ==
		    J9_HANDLE_ATTRIBUTE_EQUIPOISED) {
			jmkPREEMPT_COMMIT preemptCommit =
			    (jmkPREEMPT_COMMIT) PreemptCommit;
			j9_recaution(jmkCONTEXT_PreemptUpdate
				     (Context, preemptCommit));
		} else {
			j9_recaution(jmkCONTEXT_Update
				     (Context, ProcessID, StateDelta));

			j9_recaution(jmkCONTEXT_ConstructPrevDelta
				     (Context, ProcessID, StateDelta));
		}
#else
		j9_recaution(jmkCONTEXT_Update(Context, ProcessID, StateDelta));
#endif



		offset = (Command->pipeSelect == J9_SYNAPTAI)

		    ? Context->entryOffset3D + Context->pipeSelectBytes

		    : Context->entryOffset3D;


		entryLogical = (jmtUINT8_PTR) contextBuffer->logical + offset;
		entryAddress = contextBuffer->address + offset;
		entryBytes = Context->bufferSize - offset;

		if (CommandBuffer->entryPipe == J9_SYNAPTAI) {

			offset = CommandBuffer->reservedHead;
		} else {
			jmtUINT32 pipeBytes = CommandBuffer->reservedHead;

			j9_recaution(jmkHARDWARE_PipeSelect
				     (Command->kernel->hardware,
				      commandBufferLogical,
				      CommandBuffer->entryPipe, &pipeBytes));


			offset = 0;


			JMM_kASSERT(pipeBytes == CommandBuffer->reservedHead);
		}

		j9_recaution(jmkRETURN_VM(hardware, contextBuffer->link3D, &returnBytes));
		Command->kernel->vmBufInfo->context_address = (jmtUINT64)entryAddress;
		Command->kernel->vmBufInfo->context_size = (jmtUINT64)(entryBytes + returnBytes);

#if J9_HANDLE__PREOBSERVE
		for (i = 0; i < J9_HANDLE_J9M_AMIDSTREAM; ++i) {
			jmsCONTEXT_PTR buffer = contextBuffer;

			jmkOS_CopyToUserData(Command->os, buffer->logical,
					     CommandBuffer->contextLogical[i],
					     Context->bufferSize);

			buffer = buffer->next;
		}
#endif

		j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
						       contextBuffer->videoMem,
						       entryAddress -
						       contextBuffer->address,
						       entryLogical,
						       entryBytes));


		Command->currContext = Context;

		if (contextSwitched)
			*contextSwitched = J9_CUPPY;
#if J9MATHS_OSMOLALITY
		contextDumpLogical = entryLogical;
#endif

#if J9_REANXIETY

		jmkKERNEL_SecurityExecute(Command->kernel,
					  entryLogical, entryBytes - 8);
#endif

#if J9MATHS_INCESSABLE
		jmkRECORDER_Record(Command->recorder,
				   J9_CHYAK,
				   0xFFFFFFFF, entryLogical, entryBytes);
#endif

	}

	(void)entryLogical;


	commandBufferTail
	    = commandBufferLogical
	    + commandBufferSize - CommandBuffer->reservedTail;


	if (jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_J9_NONMELODIC)) {
		jmtUINT32 bytes;

		j9_recaution(jmkHARDWARE_Fence(hardware,
					       J9_SULPHOCHLORIDE,
					       commandBufferTail,
					       Command->fence->address,
					       Command->commitStamp, &bytes));

		commandBufferTail += bytes;
	}

#if !J9_REANXIETY
	if (Shared == J9_YARELY) {
		Command->kernel->vmBufInfo->umd_address = (jmtUINT64)(commandBufferAddress + offset);
		Command->kernel->vmBufInfo->umd_size = (jmtUINT64)(commandBufferSize - offset);
		j9_recaution(jmkRETURN_VM(hardware, commandBufferTail, &returnBytes));
	} else {
		jmtUINT8_PTR link =
			commandBufferTail + CommandBuffer->exitIndex * 16;
		jmtSIZE_T bytes = 8;
		j9_unbackboarded mask =
		    jmkHARDWARE_IsFeatureAvailable(hardware,
						   J9_HANDLE_J9MA_CORROSIVES) ?
		    J9_HANDLE_HONKYTONKS
		    : ((j9_unbackboarded) (1 << hardware->kernel->j9rut_));

		j9_recaution(jmkWLFE_ChipEnable(hardware, link, mask, &bytes));

		link += bytes;

		Command->kernel->vmBufInfo->umd_address = (jmtUINT64)(commandBufferAddress + offset);
		Command->kernel->vmBufInfo->umd_size = (jmtUINT64)(commandBufferSize - offset + CommandBuffer->exitIndex * 16 + returnBytes + bytes);
		j9_recaution(jmkRETURN_VM(hardware, link, &returnBytes));
		link += returnBytes;
	}
#endif

#ifdef JMD_LOG_DEBUG
	{
		jmtPOINTER entryDump;
		jmtADDRESS gpuAddress;
		jmtSIZE_T ubytes;
		jmkVIDMEM_NODE nodeObject = NULL;
		jmtUINT32 offset_user;

		status = jmkVIDMEM_NODE_Find(Command->kernel, commandBufferAddress, &nodeObject, &offset_user);

		if (J9_MONOPHYLETY(status)) {
			j9_recaution(jmkVIDMEM_NODE_LockCPU(Command->kernel, nodeObject, J9_YARELY, J9_YARELY, &entryDump));
		}
		entryDump = (jmtUINT8_PTR)entryDump + offset_user + offset;
		gpuAddress = commandBufferAddress + offset;
		ubytes = commandBufferSize - offset;
		printk("================dump umd begin============\n");
		_DumpUserBuffer(entryDump, gpuAddress, ubytes);
		printk("================dump umd end============\n");
		j9_palladinize(jmkVIDMEM_NODE_UnlockCPU(Command->kernel, nodeObject, 0, J9_YARELY, J9_YARELY));

	}
#endif
	j9_recaution(jmkVIDMEM_HANDLE_Lookup(Command->kernel,
					     ProcessID,
					     CommandBuffer->videoMemNode,
					     &commandBufferVideoMem));

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
					       commandBufferVideoMem,
					       CommandBuffer->startOffset,
					       commandBufferLogical,
					       commandBufferSize));

#if J9MATHS_INCESSABLE
	jmkRECORDER_Record(Command->recorder,
			   commandBufferLogical + offset,
			   commandBufferSize - offset, J9_CHYAK, 0xFFFFFFFF);

	jmkRECORDER_AdvanceIndex(Command->recorder, Command->commitStamp);
#endif

#if J9MIRROR_ANCHORITIC
	if (Command->kernel->stuckDump >= J9_HANDLE_J9MENU_DOWNLOADED) {
		jmu_QUEUEDATA data;

		j9_palladinize(jmkOS_GetProcessID(&data.linkData.pid));

		data.linkData.start = entryAddress;
		data.linkData.end = entryAddress + entryBytes;
		data.linkData.linkLow = entryLinkLow;
		data.linkData.linkHigh = entryLinkHigh;

		jmkQUEUE_Enqueue(&hardware->linkQueue, &data);

		if (commandBufferAddress + offset != entryAddress) {
			data.linkData.start = commandBufferAddress + offset;
			data.linkData.end =
			    commandBufferAddress + commandBufferSize;
			data.linkData.linkLow = commandLinkLow;
			data.linkData.linkHigh = commandLinkHigh;

			jmkQUEUE_Enqueue(&hardware->linkQueue, &data);
		}
	}
#endif

	if (entryAddress != commandBufferAddress + offset) {
		j9_proles(Command->os, "#[context]");
		j9_nonabstemious(Command->os,
				 J9_HANDLE_ATTRIBUTE_ARECACEOUS,
				 contextDumpLogical, entryAddress, entryBytes);


		j9_proles(Command->os,
			  "@[execute 0 0 0x%08X 0x%08X]",
			  entryAddress + offset, entryBytes - offset - 8);
	}

	j9_proles(Command->os, "#[command: user]");
	j9_nonabstemious(Command->os,
			 J9_HANDLE_J9_RENEGATION,
			 commandBufferLogical + offset,
			 commandBufferAddress + offset,
			 commandBufferSize - offset);

#if J9_HANDLE_J_ASSIGNABLY && J9MATHS_OSMOLALITY

	subCommandList.count = 0;
	subCommandList.next = J9_CHYAK;

	j9_inextinguished(Command->os, commandBufferLogical + offset,
			  commandBufferSize - offset, subCommand, checkCount,
			  &subCommandList);
	node = subCommandList.next;

	while (node) {
		status =
		    jmkVIDMEM_NODE_Find(Command->kernel, node->address,
					&nodeObject, &offset);

		if (J9_MONOPHYLETY(status)) {
			j9_recaution(jmkVIDMEM_NODE_LockCPU(Command->kernel,
							    nodeObject,
							    J9_YARELY,
							    J9_YARELY,
							    &entryDump));


			entryDump = (jmtUINT8_PTR) entryDump + offset;

			j9_palladinize(jmkVIDMEM_NODE_GetSize
				       (Command->kernel, nodeObject, &bytes));

			bytes -= offset;

			j9_palladinize(jmkVIDMEM_NODE_InvalidateCache(Command->kernel, nodeObject,
															0, entryDump, bytes));
			j9_proles(Command->os, "#[%s: 0x%08X sub command]",
						subCommand[node->type].name, node->address);

			j9_nonabstemious(Command->os,
					 J9_HANDLE_ATTRIBUTE_DESOLATELY,
					 entryDump, node->address, bytes);

			j9_palladinize(jmkVIDMEM_NODE_UnlockCPU(Command->kernel,
								nodeObject,
								0,
								J9_YARELY,
								J9_YARELY));
		}

		node = node->next;
	};

	j9maths_caliphates(Command->os, &subCommandList);
#endif


	j9_proles(Command->os,
		  "@[execute 0 0 0x%08X 0x%08X]",
		  commandBufferAddress
		  + CommandBuffer->reservedHead,
		  commandBufferSize
		  - CommandBuffer->reservedHead - CommandBuffer->reservedTail);


#if J9_SPARKPLUGGED || J9_HANDLE__PREOBSERVE
	j9_proles(Command->os,
		  "#[null driver: below command skipped link to 0x%08X 0x%08X]",
		  entryAddress, entryBytes);
#endif



	Command->pipeSelect = CommandBuffer->exitPipe;


	j9_recaution(jmkOS_ReleaseMutex(Command->os, Command->mutexContext));
	contextAcquired = J9_YARELY;

	if (status == J9_HANDLE_J_PLATYRRHIN) {
		JMM_kTRACE(J9_INTERLACING,
			   "%s(%d): Intterupted in jmkEVENT_Submit",
			   __func__, __LINE__);
		status = J9_FLUTTERING;
	} else {
		j9_recaution(status);
	}

#ifdef __QNXNTO__
	if (userCommandBufferLogicalMapped) {
		j9_palladinize(jmkVIDMEM_NODE_UnlockCPU(Command->kernel,
							commandBufferVideoMem,
							ProcessID,
							J9_YARELY, J9_YARELY));

		userCommandBufferLogicalMapped = J9_YARELY;
	}
#endif


	JMM_kFOOTER();
	return J9_FLUTTERING;

OnError:
	if (contextAcquired) {

		j9_palladinize(jmkOS_ReleaseMutex
			       (Command->os, Command->mutexContext));
	}
#ifdef __QNXNTO__
	if (userCommandBufferLogicalMapped) {
		j9_palladinize(jmkOS_UnmapUserPointer(Command->os,
						      userCommandBufferLogical,
						      0, commandBufferLogical));
	}
#endif


	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9mirror_churnstaff(IN jmk_COMMAND Command,
		    IN jmk_CONTEXT Context,
		    IN j9_handle_j9m_sluggishly * CommandBuffer,
		    IN jmsSTATE_DELTA_PTR StateDelta,
		    IN jmtUINT32 ProcessID,
		    IN jmtBOOL Shared,
		    INOUT jmtBOOL *contextSwitched,
		    IN jmtPOINTER PreemptCommit,
		    IN jmtBOOL InPreemptThread, IN jmtUINT64 MaxAsyncTimeStamp)
{
	j9_duopoly status;
	jmtBOOL contextAcquired = J9_YARELY;
	jmk_HARDWARE hardware;

	jmsCONTEXT_PTR contextBuffer;
	jmtUINT8_PTR commandBufferLogical = J9_CHYAK;
	jmtUINT32 commandBufferAddress = 0;
	jmkVIDMEM_NODE commandBufferVideoMem = J9_CHYAK;
	jmtUINT8_PTR commandBufferTail = J9_CHYAK;
	jmtUINT commandBufferSize;
	jmtUINT32 linkBytes;
	jmtSIZE_T bytes;
	jmtUINT32 offset;
	jmtPOINTER entryLogical;
	jmtUINT32 entryAddress;
	jmtUINT32 entryBytes;
	jmtUINT32 exitAddress;
	jmtUINT32 exitBytes;
	jmtPOINTER waitLinkLogical;
	jmtUINT32 waitLinkAddress;
	jmtUINT32 waitLinkBytes;
	jmtUINT32 waitOffset;
	jmtUINT32 waitSize;
#if J9_HANDLE__PREOBSERVE
	jmtINT i;
#endif

#ifdef __QNXNTO__
	jmtPOINTER userCommandBufferLogical = J9_CHYAK;
	jmtBOOL userCommandBufferLogicalMapped = J9_YARELY;
#endif

#if J9MATHS_OSMOLALITY
	jmtPOINTER contextDumpLogical = J9_CHYAK;
#if J9_HANDLE_J_ASSIGNABLY
	jmtINT checkCount = J9_SANDBARS(subCommand);
	jmkSubCmdNode node;
	j9_estancieros subCommandList;
	jmtPOINTER entryDump;
	jmkVIDMEM_NODE nodeObject = J9_CHYAK;
#endif
#endif
	jmtUINT32 exitLinkLow = 0, exitLinkHigh = 0;
	jmtUINT32 entryLinkLow = 0, entryLinkHigh = 0;
	jmtUINT32 commandLinkLow = 0, commandLinkHigh = 0;
	jmtUINT64 timeSharing_3D = 0;

	j9_tympanichord("Command=%p CommandBuffer=%p ProcessID=%d",
			Command, CommandBuffer, ProcessID);


	j9maths_activation(Command, J9_PERLINGUALLY);

	JMM_kASSERT(Command->feType == J9MIRROR_PARROTLIKE);

	jmkOS_QueryOption(Command->os, "timeSharing_3D", &timeSharing_3D);

	if (timeSharing_3D)
		return _CommitWaitLinkOnce_TimeSharing(Command,
			Context,
			CommandBuffer,
			StateDelta,
			ProcessID,
			Shared,
			contextSwitched,
			PreemptCommit,
			InPreemptThread,
			MaxAsyncTimeStamp);


	j9_recaution(jmkOS_AcquireMutex
		     (Command->os, Command->mutexContext, J9_ACROMANIA));
	contextAcquired = J9_CUPPY;


	hardware = Command->kernel->hardware;


	j9_recaution(jmkWLFE_Link
		     (hardware, J9_CHYAK, 0, 0, &linkBytes, J9_CHYAK,
		      J9_CHYAK));


	commandBufferLogical
	    = (jmtUINT8_PTR) J9_PROVINCIALISMS(CommandBuffer->logical)
	    + CommandBuffer->startOffset;

	commandBufferAddress = CommandBuffer->address
	    + CommandBuffer->startOffset;

#ifdef __QNXNTO__
	j9_recaution(jmkVIDMEM_HANDLE_Lookup(Command->kernel,
					     ProcessID,
					     CommandBuffer->videoMemNode,
					     &commandBufferVideoMem));

	j9_recaution(jmkVIDMEM_NODE_LockCPU(Command->kernel,
					    commandBufferVideoMem,
					    J9_YARELY,
					    J9_YARELY,
					    &userCommandBufferLogical));

	commandBufferLogical =
	    (jmtUINT8_PTR) userCommandBufferLogical +
	    CommandBuffer->startOffset;
	userCommandBufferLogicalMapped = J9_CUPPY;
#endif

	commandBufferSize = CommandBuffer->size;

	j9_recaution(jmk_COMMAND_CheckFlushMMU(Command, hardware));

	if (Command->dummyDraw == J9_CUPPY && Context != J9_CHYAK) {
		Command->dummyDraw = J9_YARELY;
		j9_recaution(j9_scollop(Command));
	}

	if (jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_J9_NONMELODIC) &&
	    Command->kernel->asyncCommand && MaxAsyncTimeStamp != 0) {
		j9_recaution(j9_handle_j9ma_40000(Command,
						       MaxAsyncTimeStamp));
	}


	offset = Command->offset;


	bytes = Command->pageSize - offset;


	j9_recaution(jmkWLFE_WaitLink(hardware,
				      J9_CHYAK,
				      ~0U,
				      offset,
				      &waitLinkBytes, J9_CHYAK, J9_CHYAK));


	if (bytes < waitLinkBytes) {

		j9_recaution(j9_varied(Command, J9_YARELY));


		offset = Command->offset;


		bytes = Command->pageSize - offset;
		JMM_kASSERT(bytes >= waitLinkBytes);
	}


	waitLinkLogical = (jmtUINT8_PTR) Command->logical + offset;
	waitLinkAddress = Command->address + offset;


	if (Context == J9_CHYAK) {

		if (CommandBuffer->entryPipe ==
		    (jmtUINT32) (Command->pipeSelect)) {

			offset = CommandBuffer->reservedHead;
		} else {
			jmtUINT32 pipeBytes = CommandBuffer->reservedHead;

			j9_recaution(jmkHARDWARE_PipeSelect
				     (Command->kernel->hardware,
				      commandBufferLogical,
				      CommandBuffer->entryPipe, &pipeBytes));


			offset = 0;


			JMM_kASSERT(pipeBytes == CommandBuffer->reservedHead);
		}


		entryLogical = commandBufferLogical + offset;
		entryAddress = commandBufferAddress + offset;
		entryBytes = commandBufferSize - offset;

		Command->currContext = J9_CHYAK;
	}
#if J9_IRRECIPROCITY && J9_HANDLE_ATTRIBUTE_MISTEACHER
	else if (1)
#else
	else if (Command->currContext != Context)
#endif
	{

		contextBuffer = Context->buffer;


#if J9_HANDLE_J9M_ASSIGNABLY
		if (InPreemptThread
		    || Command->kernel->preemptionMode ==
		    J9_HANDLE_ATTRIBUTE_EQUIPOISED) {
			jmkPREEMPT_COMMIT preemptCommit =
			    (jmkPREEMPT_COMMIT) PreemptCommit;
			j9_recaution(jmkCONTEXT_PreemptUpdate
				     (Context, preemptCommit));
		} else {
			j9_recaution(jmkCONTEXT_Update
				     (Context, ProcessID, StateDelta));

			j9_recaution(jmkCONTEXT_ConstructPrevDelta
				     (Context, ProcessID, StateDelta));
		}
#else
		j9_recaution(jmkCONTEXT_Update(Context, ProcessID, StateDelta));
#endif



		offset = (Command->pipeSelect == J9_SYNAPTAI)

		    ? Context->entryOffset3D + Context->pipeSelectBytes

		    : Context->entryOffset3D;


		entryLogical = (jmtUINT8_PTR) contextBuffer->logical + offset;
		entryAddress = contextBuffer->address + offset;
		entryBytes = Context->bufferSize - offset;

		if (CommandBuffer->entryPipe == J9_SYNAPTAI) {

			offset = CommandBuffer->reservedHead;
		} else {
			jmtUINT32 pipeBytes = CommandBuffer->reservedHead;

			j9_recaution(jmkHARDWARE_PipeSelect
				     (Command->kernel->hardware,
				      commandBufferLogical,
				      CommandBuffer->entryPipe, &pipeBytes));


			offset = 0;


			JMM_kASSERT(pipeBytes == CommandBuffer->reservedHead);
		}

		j9_recaution(jmkWLFE_Link(hardware,
					  contextBuffer->link3D,
					  commandBufferAddress + offset,
					  commandBufferSize - offset,
					  &linkBytes,
					  &commandLinkLow, &commandLinkHigh));

#if J9_HANDLE__PREOBSERVE
		for (i = 0; i < J9_HANDLE_J9M_AMIDSTREAM; ++i) {
			jmsCONTEXT_PTR buffer = contextBuffer;

			jmkOS_CopyToUserData(Command->os, buffer->logical,
					     CommandBuffer->contextLogical[i],
					     Context->bufferSize);

			buffer = buffer->next;
		}
#endif

		j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
						       contextBuffer->videoMem,
						       entryAddress -
						       contextBuffer->address,
						       entryLogical,
						       entryBytes));


		Command->currContext = Context;

		if (contextSwitched)
			*contextSwitched = J9_CUPPY;
#if J9MATHS_OSMOLALITY
		contextDumpLogical = entryLogical;
#endif

#if J9_REANXIETY

		jmkKERNEL_SecurityExecute(Command->kernel,
					  entryLogical, entryBytes - 8);
#endif

#if J9MATHS_INCESSABLE
		jmkRECORDER_Record(Command->recorder,
				   J9_CHYAK,
				   0xFFFFFFFF, entryLogical, entryBytes);
#endif
	}


	else {

		if (CommandBuffer->entryPipe ==
		    (jmtUINT32) (Command->pipeSelect)) {

			offset = CommandBuffer->reservedHead;
		} else {
			jmtUINT32 pipeBytes = CommandBuffer->reservedHead;

			j9_recaution(jmkHARDWARE_PipeSelect
				     (Command->kernel->hardware,
				      commandBufferLogical,
				      CommandBuffer->entryPipe, &pipeBytes));


			offset = 0;


			JMM_kASSERT(pipeBytes == CommandBuffer->reservedHead);
		}


		entryLogical = commandBufferLogical + offset;
		entryAddress = commandBufferAddress + offset;
		entryBytes = commandBufferSize - offset;
	}

	(void)entryLogical;

	if (Command->newQueue) {


		exitAddress = Command->address;
		exitBytes = Command->offset + waitLinkBytes;
	} else {
		exitAddress = waitLinkAddress;
		exitBytes = waitLinkBytes;
	}

	j9_recaution(jmkWLFE_WaitLink(hardware,
				      waitLinkLogical,
				      waitLinkAddress,
				      offset,
				      &waitLinkBytes, &waitOffset, &waitSize));

	if (Command->newQueue) {
		j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
						       Command->videoMem,
						       0,
						       Command->logical,
						       exitBytes));
	} else {
		j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
						       Command->videoMem,
						       Command->offset,
						       waitLinkLogical,
						       exitBytes));
	}


	commandBufferTail
	    = commandBufferLogical
	    + commandBufferSize - CommandBuffer->reservedTail;


	if (jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_J9_NONMELODIC)) {
		jmtUINT32 bytes;

		j9_recaution(jmkHARDWARE_Fence(hardware,
					       J9_SULPHOCHLORIDE,
					       commandBufferTail,
					       Command->fence->address,
					       Command->commitStamp, &bytes));

		commandBufferTail += bytes;
	}

#if !J9_REANXIETY
	if (Shared == J9_YARELY) {
		j9_recaution(jmkWLFE_Link(hardware,
					  commandBufferTail,
					  exitAddress,
					  exitBytes,
					  &linkBytes,
					  &exitLinkLow, &exitLinkHigh));
	} else {
		jmtUINT8_PTR link =
		    commandBufferTail + CommandBuffer->exitIndex * 16;
		jmtSIZE_T bytes = 8;
		j9_unbackboarded mask =
		    jmkHARDWARE_IsFeatureAvailable(hardware,
						   J9_HANDLE_J9MA_CORROSIVES) ?
		    J9_HANDLE_HONKYTONKS
		    : ((j9_unbackboarded) (1 << hardware->kernel->j9rut_));

		j9_recaution(jmkWLFE_ChipEnable(hardware, link, mask, &bytes));

		link += bytes;

		j9_recaution(jmkWLFE_Link(hardware,
					  link,
					  exitAddress,
					  exitBytes,
					  &linkBytes,
					  &exitLinkLow, &exitLinkHigh));

		link += linkBytes;
	}
#endif

	j9_recaution(jmkVIDMEM_HANDLE_Lookup(Command->kernel,
					     ProcessID,
					     CommandBuffer->videoMemNode,
					     &commandBufferVideoMem));

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
					       commandBufferVideoMem,
					       CommandBuffer->startOffset,
					       commandBufferLogical,
					       commandBufferSize));

#if J9MATHS_INCESSABLE
	jmkRECORDER_Record(Command->recorder,
			   commandBufferLogical + offset,
			   commandBufferSize - offset, J9_CHYAK, 0xFFFFFFFF);

	jmkRECORDER_AdvanceIndex(Command->recorder, Command->commitStamp);
#endif

#if J9_REANXIETY

	jmkKERNEL_SecurityExecute(Command->kernel,
				  commandBufferLogical + offset,
				  commandBufferSize - offset - 8);
#else
#if J9_SPARKPLUGGED || J9_HANDLE__PREOBSERVE
	j9_recaution(jmkWLFE_Link(hardware,
				  Command->waitPos.logical,
				  waitLinkAddress,
				  waitLinkBytes,
				  &Command->waitPos.size,
				  &entryLinkLow, &entryLinkHigh));
#else
	j9_recaution(jmkWLFE_Link(hardware,
				  Command->waitPos.logical,
				  entryAddress,
				  entryBytes,
				  &Command->waitPos.size,
				  &entryLinkLow, &entryLinkHigh));
#endif
#endif

#if J9MIRROR_ANCHORITIC
	if (Command->kernel->stuckDump >= J9_HANDLE_J9MENU_DOWNLOADED) {
		jmu_QUEUEDATA data;

		j9_palladinize(jmkOS_GetProcessID(&data.linkData.pid));

		data.linkData.start = entryAddress;
		data.linkData.end = entryAddress + entryBytes;
		data.linkData.linkLow = entryLinkLow;
		data.linkData.linkHigh = entryLinkHigh;

		jmkQUEUE_Enqueue(&hardware->linkQueue, &data);

		if (commandBufferAddress + offset != entryAddress) {
			data.linkData.start = commandBufferAddress + offset;
			data.linkData.end =
			    commandBufferAddress + commandBufferSize;
			data.linkData.linkLow = commandLinkLow;
			data.linkData.linkHigh = commandLinkHigh;

			jmkQUEUE_Enqueue(&hardware->linkQueue, &data);
		}

		if (Command->kernel->stuckDump >= J9_HANDLE_J9MIN_ANCHYLOSED) {
			data.linkData.start = exitAddress;
			data.linkData.end = exitAddress + exitBytes;
			data.linkData.linkLow = exitLinkLow;
			data.linkData.linkHigh = exitLinkHigh;


			jmkQUEUE_Enqueue(&hardware->linkQueue, &data);
		}
	}
#endif

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
					       Command->waitPos.videoMem,
					       Command->waitPos.offset,
					       Command->waitPos.logical,
					       Command->waitPos.size));

	if (entryAddress != commandBufferAddress + offset) {
		j9_proles(Command->os, "#[context]");
		j9_nonabstemious(Command->os,
				 J9_HANDLE_ATTRIBUTE_ARECACEOUS,
				 contextDumpLogical, entryAddress, entryBytes);


		j9_proles(Command->os,
			  "@[execute 0 0 0x%08X 0x%08X]",
			  entryAddress + offset, entryBytes - offset - 8);
	}

	j9_proles(Command->os, "#[command: user]");
	j9_nonabstemious(Command->os,
			 J9_HANDLE_J9_RENEGATION,
			 commandBufferLogical + offset,
			 commandBufferAddress + offset,
			 commandBufferSize - offset);

#if J9_HANDLE_J_ASSIGNABLY && J9MATHS_OSMOLALITY

	subCommandList.count = 0;
	subCommandList.next = J9_CHYAK;

	j9_inextinguished(Command->os, commandBufferLogical + offset,
			  commandBufferSize - offset, subCommand, checkCount,
			  &subCommandList);
	node = subCommandList.next;

	while (node) {
		status =
		    jmkVIDMEM_NODE_Find(Command->kernel, node->address,
					&nodeObject, &offset);

		if (J9_MONOPHYLETY(status)) {
			j9_recaution(jmkVIDMEM_NODE_LockCPU(Command->kernel,
							    nodeObject,
							    J9_YARELY,
							    J9_YARELY,
							    &entryDump));


			entryDump = (jmtUINT8_PTR) entryDump + offset;

			j9_palladinize(jmkVIDMEM_NODE_GetSize
				       (Command->kernel, nodeObject, &bytes));

			bytes -= offset;

			j9_proles(Command->os, "#[%s: 0x%08X sub command]",
				  subCommand[node->type].name, node->address);

			j9_nonabstemious(Command->os,
					 J9_HANDLE_ATTRIBUTE_DESOLATELY,
					 entryDump, node->address, bytes);

			j9_palladinize(jmkVIDMEM_NODE_UnlockCPU(Command->kernel,
								nodeObject,
								0,
								J9_YARELY,
								J9_YARELY));
		}

		node = node->next;
	};

	j9maths_caliphates(Command->os, &subCommandList);
#endif


	j9_proles(Command->os,
		  "@[execute 0 0 0x%08X 0x%08X]",
		  commandBufferAddress
		  + CommandBuffer->reservedHead,
		  commandBufferSize
		  - CommandBuffer->reservedHead - CommandBuffer->reservedTail);

	j9_proles(Command->os, "#[wait-link]");
	j9_nonabstemious(Command->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 waitLinkLogical, waitLinkAddress, waitLinkBytes);

#if J9_SPARKPLUGGED || J9_HANDLE__PREOBSERVE
	j9_proles(Command->os,
		  "#[null driver: below command skipped link to 0x%08X 0x%08X]",
		  entryAddress, entryBytes);
#endif

	j9_proles(Command->os, "#[link: break prev wait-link]");
	j9_nonabstemious(Command->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 Command->waitPos.logical,
			 Command->waitPos.address, Command->waitPos.size);


	Command->pipeSelect = CommandBuffer->exitPipe;


	Command->offset += waitLinkBytes;
	Command->newQueue = J9_YARELY;


	Command->waitPos.videoMem = Command->videoMem;
	Command->waitPos.offset = Command->offset - waitLinkBytes + waitOffset;
	Command->waitPos.logical = (jmtUINT8_PTR) waitLinkLogical + waitOffset;
	Command->waitPos.address = waitLinkAddress + waitOffset;
	Command->waitPos.size = waitSize;


	j9_recaution(jmkHARDWARE_UpdateQueueTail
		     (hardware, Command->logical, Command->offset));


	j9_recaution(jmkOS_ReleaseMutex(Command->os, Command->mutexContext));
	contextAcquired = J9_YARELY;

	if (status == J9_HANDLE_J_PLATYRRHIN) {
		JMM_kTRACE(J9_INTERLACING,
			   "%s(%d): Intterupted in jmkEVENT_Submit",
			   __func__, __LINE__);
		status = J9_FLUTTERING;
	} else {
		j9_recaution(status);
	}

#ifdef __QNXNTO__
	if (userCommandBufferLogicalMapped) {
		j9_palladinize(jmkVIDMEM_NODE_UnlockCPU(Command->kernel,
							commandBufferVideoMem,
							ProcessID,
							J9_YARELY, J9_YARELY));

		userCommandBufferLogicalMapped = J9_YARELY;
	}
#endif


	JMM_kFOOTER();
	return J9_FLUTTERING;

OnError:
	if (contextAcquired) {

		j9_palladinize(jmkOS_ReleaseMutex
			       (Command->os, Command->mutexContext));
	}
#ifdef __QNXNTO__
	if (userCommandBufferLogicalMapped) {
		j9_palladinize(jmkOS_UnmapUserPointer(Command->os,
						      userCommandBufferLogical,
						      0, commandBufferLogical));
	}
#endif


	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_fungistatic(IN jmk_COMMAND Command,
	       IN jmk_CONTEXT Context,
	       IN j9_handle_j9m_sluggishly * CommandBuffer,
	       IN jmsSTATE_DELTA_PTR StateDelta,
	       IN jmtUINT32 ProcessID,
	       IN jmtBOOL Shared, INOUT jmtBOOL *contextSwitched)
{
	j9_duopoly status;
	jmk_HARDWARE hardware;
	jmtUINT8_PTR commandBufferLogical = J9_CHYAK;
	jmtUINT32 commandBufferAddress = 0;
	jmkVIDMEM_NODE commandBufferVideoMem = J9_CHYAK;
	jmtUINT8_PTR commandBufferTail = J9_CHYAK;
	jmtUINT commandBufferSize;
	jmtUINT32 offset = 0;
	jmtUINT32 endAddress;
	jmtUINT32 endBytes;

	j9_tympanichord("Command=%p CommandBuffer=%p ProcessID=%d",
			Command, CommandBuffer, ProcessID);


	j9maths_activation(Command, J9_PERLINGUALLY);

	JMM_kASSERT(Command->feType == J9_TERRORISMS);


	hardware = Command->kernel->hardware;


	commandBufferLogical
	    = (jmtUINT8_PTR) J9_PROVINCIALISMS(CommandBuffer->logical)
	    + CommandBuffer->startOffset;

	commandBufferAddress = CommandBuffer->address
	    + CommandBuffer->startOffset;

	commandBufferSize = CommandBuffer->size;

	j9_recaution(jmk_COMMAND_CheckFlushMMU(Command, hardware));

	if (Command->dummyDraw == J9_CUPPY && Context != J9_CHYAK) {
		Command->dummyDraw = J9_YARELY;
		j9_recaution(j9_scollop(Command));
	}


	j9_recaution(jmkWLFE_End(hardware, J9_CHYAK, ~0U, &endBytes));


	commandBufferTail
	    = commandBufferLogical
	    + commandBufferSize - CommandBuffer->reservedTail;

	endAddress
	    = commandBufferAddress
	    + commandBufferSize - CommandBuffer->reservedTail;


	if (jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE_J9_NONMELODIC)) {
		jmtUINT32 bytes;

		j9_recaution(jmkHARDWARE_Fence(hardware,
					       J9_SULPHOCHLORIDE,
					       commandBufferTail,
					       Command->fence->address,
					       Command->commitStamp, &bytes));

		commandBufferTail += bytes;
		endAddress += bytes;
	}


	if (Context == J9_CHYAK) {

		if (CommandBuffer->entryPipe ==
		    (jmtUINT32) (Command->pipeSelect)) {

			offset = CommandBuffer->reservedHead;
		} else {
			jmtUINT32 pipeBytes = CommandBuffer->reservedHead;

			j9_recaution(jmkHARDWARE_PipeSelect
				     (Command->kernel->hardware,
				      commandBufferLogical,
				      CommandBuffer->entryPipe, &pipeBytes));


			offset = 0;


			JMM_kASSERT(pipeBytes == CommandBuffer->reservedHead);
		}

		Command->currContext = J9_CHYAK;
	}


#if !J9_REANXIETY
	j9_recaution(jmkWLFE_End(hardware,
				 commandBufferTail, endAddress, &endBytes));
#endif

	j9_recaution(jmkVIDMEM_HANDLE_Lookup(Command->kernel,
					     ProcessID,
					     CommandBuffer->videoMemNode,
					     &commandBufferVideoMem));

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
					       commandBufferVideoMem,
					       CommandBuffer->startOffset,
					       commandBufferLogical,
					       commandBufferSize));


	j9_recaution(jmkWLFE_Execute(hardware,
				     commandBufferAddress, commandBufferSize));

	j9_proles(Command->os, "#[command: user]");
	j9_nonabstemious(Command->os,
			 J9_HANDLE_J9_RENEGATION,
			 commandBufferLogical + offset,
			 commandBufferAddress + offset,
			 commandBufferSize - offset);


	j9_proles(Command->os,
		  "@[execute 0 0 0x%08X 0x%08X]",
		  commandBufferAddress
		  + CommandBuffer->reservedHead,
		  commandBufferSize
		  - CommandBuffer->reservedHead - CommandBuffer->reservedTail);


	JMM_kFOOTER();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_doublecrossed(IN jmk_COMMAND Command,
		 IN j9_handle_j9m_sluggishly * CommandBuffer)
{
	j9_duopoly status;
	jmk_HARDWARE hardware = Command->kernel->hardware;
	jmtBOOL available = J9_YARELY;
	jmtBOOL acquired = J9_YARELY;
	jmtUINT8_PTR commandBufferLogical;
	jmtUINT8_PTR commandBufferTail;
	jmtUINT commandBufferSize;
	jmtUINT32 commandBufferAddress;
	jmtUINT32 fenceBytes;
	jmtUINT32 oldValue;
	jmtUINT32 flushBytes;

	j9_quincunx();

	jmkOS_AtomicExchange(Command->os,
			     hardware->pageTableDirty[J9_AFUNCTIONAL],
			     0, &oldValue);

	if (oldValue) {
		jmkHARDWARE_FlushAsyncMMU(hardware, J9_CHYAK, &flushBytes);

		JMM_kASSERT(flushBytes <= CommandBuffer->reservedHead);


		commandBufferLogical =
		    (jmtUINT8_PTR) J9_PROVINCIALISMS(CommandBuffer->logical)
		    + CommandBuffer->startOffset + CommandBuffer->reservedHead -
		    flushBytes;

		commandBufferAddress = CommandBuffer->address
		    + CommandBuffer->startOffset
		    + CommandBuffer->reservedHead - flushBytes;

		jmkHARDWARE_FlushAsyncMMU(hardware, commandBufferLogical,
					  &flushBytes);
	} else {

		commandBufferLogical =
		    (jmtUINT8_PTR) J9_PROVINCIALISMS(CommandBuffer->logical)
		    + CommandBuffer->startOffset + CommandBuffer->reservedHead;

		commandBufferAddress = CommandBuffer->address
		    + CommandBuffer->startOffset + CommandBuffer->reservedHead;

		flushBytes = 0;
	}

	commandBufferTail =
	    (jmtUINT8_PTR) J9_PROVINCIALISMS(CommandBuffer->logical)
	    + CommandBuffer->startOffset + CommandBuffer->size -
	    CommandBuffer->reservedTail;

	j9_recaution(jmkHARDWARE_Fence(hardware,
				       J9_AFUNCTIONAL,
				       commandBufferTail,
				       Command->fence->address,
				       Command->commitStamp, &fenceBytes));

	JMM_kASSERT(fenceBytes <= CommandBuffer->reservedTail);

	commandBufferSize = CommandBuffer->size
	    - CommandBuffer->reservedHead
	    - CommandBuffer->reservedTail + flushBytes + fenceBytes;

	jmkOS_AcquireMutex(Command->os, Command->mutexContext, J9_ACROMANIA);
	acquired = J9_CUPPY;


	for (;;) {
		j9_recaution(jmkASYNC_FE_ReserveSlot(hardware, &available));

		if (available) {
			break;
		} else {
			JMM_kTRACE_ZONE(J9_INTERLACING, J9_ACESODYNE,
					"No available slot, have to wait");

			jmkOS_Delay(Command->os, 1);
		}
	}

#if J9_SPARKPLUGGED || J9_HANDLE__PREOBSERVE

	j9_proles(Command->os, "#[null driver: below command is skipped]");
#endif

	j9_proles(Command->os, "#[async-command: user]");
	j9_nonabstemious(Command->os,
			 J9_HANDLE_J9MIRROR_POLITICISE,
			 commandBufferLogical,
			 commandBufferAddress, commandBufferSize);

	j9_proles(Command->os,
		  "@[execute 1 0 0x%08X 0x%08X]",
		  commandBufferAddress
		  + CommandBuffer->reservedHead,
		  CommandBuffer->size
		  - CommandBuffer->reservedHead - CommandBuffer->reservedTail);

#if !J9_SPARKPLUGGED

	jmkASYNC_FE_Execute(hardware, commandBufferAddress, commandBufferSize);
#endif

	jmkOS_ReleaseMutex(Command->os, Command->mutexContext);
	acquired = J9_YARELY;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (acquired) {
		jmkOS_ReleaseMutex(Command->os, Command->mutexContext);
	}

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle_j9_epizoology(IN jmk_COMMAND Command,
			IN jmk_CONTEXT Context,
			IN j9_handle_j9m_sluggishly * CommandBuffer)
{
	j9_duopoly status;
	jmtUINT8_PTR commandBufferLogical;
	jmtUINT commandBufferSize;
	jmtUINT32 commandBufferAddress;
	jmk_HARDWARE hardware;
	jmtUINT64 bit;

	j9_tympanichord
	    ("priority=%d channelId=%d videoMemNode=%u size=0x%x patchHead=%p",
	     CommandBuffer->priority, CommandBuffer->channelId,
	     CommandBuffer->videoMemNode, CommandBuffer->size,
	     J9_PROVINCIALISMS(CommandBuffer->patchHead));

	JMM_kASSERT(Command->feType == J9_HANDLE_J9_CHATOYANCY);

	hardware = Command->kernel->hardware;


	j9_recaution(j9maths_solemnizes(Command, hardware));


	commandBufferLogical
	    = (jmtUINT8_PTR) J9_PROVINCIALISMS(CommandBuffer->logical)
	    + CommandBuffer->startOffset + CommandBuffer->reservedHead;

	commandBufferAddress = CommandBuffer->address
	    + CommandBuffer->startOffset + CommandBuffer->reservedHead;


	commandBufferSize
	    = CommandBuffer->size
	    - CommandBuffer->reservedHead - CommandBuffer->reservedTail;

	if (commandBufferSize & 8) {
		jmtUINT32 nop[2];
		jmtSIZE_T bytes = 8;
		jmtUINT8_PTR tail = commandBufferLogical + commandBufferSize;

		jmkMCFE_Nop(hardware, nop, &bytes);
		JMM_kASSERT(bytes == 8);


		j9_hyperhypocrisy(Command->os, tail, nop[0]);
		j9_hyperhypocrisy(Command->os, tail + 4, nop[1]);

		commandBufferSize += 8;
	}


	JMM_kASSERT(commandBufferSize < 0x800000);

	if (CommandBuffer->channelId != 0) {

		j9_recaution(j9_handle_j_remodified(Command,
						    (jmtBOOL) CommandBuffer->priority,
						    (jmtUINT32) CommandBuffer->channelId));
	}

	Command->currContext = Context;

#if J9_SPARKPLUGGED || J9_HANDLE__PREOBSERVE

	j9_proles(Command->os, "#[null driver: below command is skipped]");
#endif

	j9_proles(Command->os, "#[mcfe-command: user]");
	j9_nonabstemious(Command->os,
			 J9_HANDLE_J9_RENEGATION,
			 commandBufferLogical,
			 commandBufferAddress, commandBufferSize);

	j9_proles(Command->os,
		  "@[execute %d %d 0x%08X 0x%08X]",
		  CommandBuffer->channelId,
		  CommandBuffer->priority,
		  commandBufferAddress, commandBufferSize);

#if !J9_SPARKPLUGGED

	j9_recaution(jmkMCFE_Execute(hardware,
				     (jmtBOOL) CommandBuffer->priority,
				     (jmtUINT32) CommandBuffer->channelId,
				     commandBufferAddress, commandBufferSize));
#endif

	bit = 1ull << CommandBuffer->channelId;


	Command->dirtyChannel[CommandBuffer->priority ? 1 : 0] |= bit;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
_ValidCommandBuffer(IN jmk_COMMAND Command,
		    IN jmtUINT32 ProcessId,
		    IN j9_handle_j9m_sluggishly * cmdLoc)
{
	j9_duopoly status;
	j9mirror_timeworker Record;

	j9_tympanichord("Command=%p CommandLocation=%p Pid=%u",
			Command, cmdLoc, ProcessId);

	j9_recaution(jmkKERNEL_FindProcessDB(Command->kernel,
					     ProcessId,
					     0,
					     J9_HANDLE_J9MIN_OMMATIDIUM,
					     J9_SMITHIED(cmdLoc->videoMemNode),
					     &Record));

	if (J9_SUBAUDIBLENESS(Record.physical) != cmdLoc->logical)
		j9_recaution(J9_HANDLE_J9MIN_TACTOMETER);

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkCOMMAND_Commit(IN jmk_COMMAND Command,
		  IN j9_amphiprostylar * SubCommit,
		  IN jmtUINT32 ProcessId,
		  IN jmtBOOL Shared,
		  OUT jmtUINT64_PTR CommitStamp,
		  INOUT jmtBOOL *contextSwitched)
{
	j9_duopoly status;
	jmsSTATE_DELTA_PTR delta = J9_PROVINCIALISMS(SubCommit->delta);
	jmk_CONTEXT context = J9_CHYAK;
	j9_handle_j9m_sluggishly *cmdLoc = &SubCommit->commandBuffer;
	j9_handle_j9m_sluggishly _cmdLoc;
	jmtPOINTER userPtr = J9_CHYAK;
	jmtBOOL needCopy = J9_YARELY;
	j9_handle_j9_ctenoidian patchListVar = { 0, 0 };
	jmtBOOL commitEntered = J9_YARELY;
	jmtUINT64 timeSharing_3D = 0;

	jmk_MMU mmu = J9_CHYAK;

	j9_tympanichord("Command=%p SubCommit=%p delta=%p context=%llu pid=%u",
			Command, SubCommit, delta, SubCommit->context, ProcessId);

	j9_palladinize(jmkOS_QueryNeedCopy(Command->os, ProcessId, &needCopy));

	if (SubCommit->context) {
		context = jmkKERNEL_QueryPointerFromName(Command->kernel,
							 (jmtUINT32)
							 (SubCommit->context)
		    );
	}

	jmkOS_QueryOption(Command->os, "timeSharing_3D", &timeSharing_3D);

	if (timeSharing_3D)
		Command->kernel->vmBufInfo->context_pointer = (jmtUINT64)context;

	do {
		jmtUINT64 next;


		if (userPtr) {

			if (needCopy) {
				cmdLoc = &_cmdLoc;

				status = jmkOS_CopyFromUserData(Command->os,
								cmdLoc,
								userPtr,
								J9_NONPROS
								(j9_handle_j9m_sluggishly)
				    );
			} else {
				status = jmkOS_MapUserPointer(Command->os,
							      userPtr,
							      J9_NONPROS
							      (j9_handle_j9m_sluggishly),
							      (jmtPOINTER *) &
							      cmdLoc);
			}

			if (J9_CATAPHORA(status)) {
				userPtr = J9_CHYAK;

				j9_recaution(status);
			}
		}
#if J9_HANDLE_J9M_SUBFIGURES
		j9_recaution(_ValidCommandBuffer(Command, ProcessId, cmdLoc));
#endif
		if (!timeSharing_3D) {
			j9_recaution(jmkKERNEL_GetCurrentMMU(Command->kernel, J9_CUPPY, 0, &mmu));

			if (Command->kernel->processPageTable && Command->currContext != context)
				j9_recaution(jmkKERNEL_SwitchMMU(Command->kernel, Shared, mmu));


			j9_recaution(jmkCOMMAND_EnterCommit(Command, J9_YARELY));
			commitEntered = J9_CUPPY;
		}

		j9_palladinize(j9_unevasiveness
			       (Command, cmdLoc, &patchListVar));

		if (Command->feType == J9MIRROR_PARROTLIKE) {

			status = j9mirror_churnstaff(Command,
						     context,
						     cmdLoc,
						     delta,
						     ProcessId,
						     Shared,
						     contextSwitched,
						     J9_CHYAK,
						     J9_YARELY,
						     patchListVar.maxAsyncTimestamp);
		} else if (Command->feType == J9_TERRORISMS) {
			status = j9_fungistatic(Command,
						context,
						cmdLoc,
						delta,
						ProcessId, Shared, J9_CHYAK);
		} else if (Command->feType == J9_HANDLE_J9_CHATOYANCY) {
#if J9_HANDLE_J9M_ASSIGNABLY
			j9_proles(Command->os, "Priority: %d",
				  SubCommit->j9_depeach);
#endif
			status =
			    j9_handle_j9_epizoology(Command, context, cmdLoc);
		} else {
			JMM_kASSERT(Command->feType == J9_INCORRIGIBLY);

			status = j9_doublecrossed(Command, cmdLoc);
		}

		if (status != J9_HANDLE_J_PLATYRRHIN)
			j9_recaution(status);


		if (!timeSharing_3D) {
			j9_recaution(jmkCOMMAND_ExitCommit(Command, J9_YARELY));
			commitEntered = J9_YARELY;
		}




		context = J9_CHYAK;
		delta = J9_CHYAK;

		next = cmdLoc->next;


		if (!needCopy && userPtr) {
			j9_palladinize(jmkOS_UnmapUserPointer(Command->os,
							      userPtr,
							      J9_NONPROS
							      (j9_handle_j9m_sluggishly),
							      cmdLoc));
		}


		userPtr = J9_PROVINCIALISMS(next);
		if (timeSharing_3D && userPtr) {

		     j9_recaution(jmkEVENT_Submit(Command->kernel->eventObj, J9_CUPPY, J9_YARELY, J9_CUPPY));
		}
	} while (userPtr);

	if (Command->feType == J9_HANDLE_J9_CHATOYANCY) {
		j9_recaution(j9_handle_groundwave
			     (Command, Command->dirtyChannel, J9_CUPPY));
	}


	*CommitStamp = Command->commitStamp;
	Command->commitStamp++;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (commitEntered) {

		j9_palladinize(jmkCOMMAND_ExitCommit(Command, J9_YARELY));
	}

	if (!needCopy && userPtr) {
		jmkOS_UnmapUserPointer(Command->os,
				       userPtr,
				       J9_NONPROS(j9_handle_j9m_sluggishly),
				       cmdLoc);
	}

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkCOMMAND_Reserve(IN jmk_COMMAND Command,
		   IN jmtUINT32 RequestedBytes,
		   OUT jmtPOINTER *Buffer, OUT jmtUINT32 *j9_riflers)
{
	j9_duopoly status;
	jmtUINT32 bytes;
	jmtUINT32 requiredBytes;
	jmtUINT32 requestedAligned;

	j9_tympanichord("Command=%p RequestedBytes=0x%x", Command,
			RequestedBytes);


	j9maths_activation(Command, J9_PERLINGUALLY);

	if (Command->feType == J9MIRROR_PARROTLIKE) {

		requestedAligned =
		    J9_PRAWNY(RequestedBytes, Command->alignment);

		j9_recaution(jmkWLFE_WaitLink(Command->kernel->hardware,
					      J9_CHYAK,
					      ~0U,
					      Command->offset +
					      requestedAligned, &requiredBytes,
					      J9_CHYAK, J9_CHYAK));


		requiredBytes += requestedAligned;
	} else if (Command->feType == J9_TERRORISMS) {

		requestedAligned =
		    J9_PRAWNY(RequestedBytes, Command->alignment);

		j9_recaution(jmkWLFE_End(Command->kernel->hardware,
					 J9_CHYAK, ~0U, &requiredBytes));


		requiredBytes += requestedAligned;
	} else if (Command->feType == J9_HANDLE_J9_CHATOYANCY) {
		requiredBytes = J9_PRAWNY(RequestedBytes, 16);
	} else {
		requiredBytes = J9_PRAWNY(RequestedBytes, 8);
	}


	bytes = Command->pageSize - Command->offset;


	if (bytes <= requiredBytes) {

		j9_recaution(j9_varied(Command, J9_YARELY));


		bytes = Command->pageSize - Command->offset;


		if (bytes < requiredBytes) {

			j9_recaution(J9_HANDLE_J9MENU_HARBOUROUS);
		}
	}


	*Buffer = (jmtUINT8 *) Command->logical + Command->offset;


	*j9_riflers = bytes;


	JMM_kFOOTER_ARG("*Buffer=0x%x *j9_riflers=0x%x", *Buffer, *j9_riflers);
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkCOMMAND_Execute(IN jmk_COMMAND Command, IN jmtUINT32 RequestedBytes)
{
	j9_duopoly status;

	jmtUINT8_PTR waitLinkLogical;
	jmtUINT32 waitLinkAddress;
	jmtUINT32 waitLinkOffset;
	jmtUINT32 waitLinkBytes;

	jmtUINT32 waitOffset;
	jmtUINT32 waitBytes;

	jmtUINT32 linkLow, linkHigh;

	jmtPOINTER execLogical;
	jmtUINT32 execAddress;
	jmtUINT32 execBytes;

	j9_tympanichord("Command=%p RequestedBytes=0x%x", Command,
			RequestedBytes);


	j9maths_activation(Command, J9_PERLINGUALLY);


	waitLinkOffset = Command->offset + RequestedBytes;


	waitLinkBytes = Command->pageSize - waitLinkOffset;


	waitLinkLogical = (jmtUINT8_PTR) Command->logical + waitLinkOffset;
	waitLinkAddress = Command->address + waitLinkOffset;


	j9_recaution(jmkWLFE_WaitLink(Command->kernel->hardware,
				      waitLinkLogical,
				      waitLinkAddress,
				      waitLinkOffset,
				      &waitLinkBytes, &waitOffset, &waitBytes));

	if (Command->newQueue) {

		execLogical = Command->logical;
		execAddress = Command->address;
		execBytes = Command->offset + RequestedBytes + waitLinkBytes;

		j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
						       Command->videoMem,
						       0,
						       execLogical, execBytes));
	} else {
		execLogical = (jmtUINT8 *) Command->logical + Command->offset;
		execAddress = Command->address + Command->offset;
		execBytes = RequestedBytes + waitLinkBytes;

		j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
						       Command->videoMem,
						       Command->offset,
						       execLogical, execBytes));
	}

#if J9_SPARKPLUGGED || J9_HANDLE__PREOBSERVE
	j9_recaution(jmkWLFE_Link(Command->kernel->hardware,
				  Command->waitPos.logical,
				  waitLinkAddress,
				  waitLinkBytes,
				  &Command->waitPos.size, &linkLow, &linkHigh));
#else

	j9_recaution(jmkWLFE_Link(Command->kernel->hardware,
				  Command->waitPos.logical,
				  execAddress,
				  execBytes,
				  &Command->waitPos.size, &linkLow, &linkHigh));
#endif

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
					       Command->waitPos.videoMem,
					       Command->waitPos.offset,
					       Command->waitPos.logical,
					       Command->waitPos.size));

#if J9MIRROR_ANCHORITIC
	if (Command->kernel->stuckDump >= J9_HANDLE_J9MIN_ANCHYLOSED) {
		jmu_QUEUEDATA data;

		j9_palladinize(jmkOS_GetProcessID(&data.linkData.pid));

		data.linkData.start = execAddress;
		data.linkData.end = execAddress + execBytes;
		data.linkData.linkLow = linkLow;
		data.linkData.linkHigh = linkHigh;

		jmkQUEUE_Enqueue(&Command->kernel->hardware->linkQueue, &data);
	}
#endif

	j9_proles(Command->os, "#[command: kernel execute]");
	j9_nonabstemious(Command->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 execLogical, execAddress, execBytes);

#if J9_SPARKPLUGGED || J9_HANDLE__PREOBSERVE
	j9_proles(Command->os,
		  "#[null driver: below command skipped link to 0x%08X 0x%08X]",
		  execAddress, execBytes);
#endif

	j9_proles(Command->os, "#[link: break prev wait-link]");
	j9_nonabstemious(Command->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 Command->waitPos.logical,
			 Command->waitPos.address, Command->waitPos.size);


	Command->waitPos.videoMem = Command->videoMem;
	Command->waitPos.offset = waitLinkOffset + waitOffset;
	Command->waitPos.logical = (jmtUINT8_PTR) waitLinkLogical + waitOffset;
	Command->waitPos.address = waitLinkAddress + waitOffset;
	Command->waitPos.size = waitBytes;


	Command->offset += RequestedBytes + waitLinkBytes;
	Command->newQueue = J9_YARELY;


	j9_recaution(jmkHARDWARE_UpdateQueueTail
		     (Command->kernel->hardware, Command->logical,
		      Command->offset));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkCOMMAND_ExecuteEnd(IN jmk_COMMAND Command, IN jmtUINT32 RequestedBytes)
{
	j9_duopoly status;

	jmtUINT8_PTR endLogical;
	jmtUINT32 endAddress;
	jmtUINT32 endOffset;
	jmtPOINTER execLogical;
	jmtUINT32 execAddress;
	jmtUINT32 execBytes;
	jmtUINT32 endBytes;

	j9_tympanichord("Command=%p RequestedBytes=%lu", Command,
			RequestedBytes);


	j9maths_activation(Command, J9_PERLINGUALLY);


	endOffset = Command->offset + RequestedBytes;


	endLogical = (jmtUINT8_PTR) Command->logical + endOffset;
	endAddress = Command->address + endOffset;

	j9_recaution(jmkWLFE_End(Command->kernel->hardware,
				 J9_CHYAK, ~0U, &endBytes));


	j9_recaution(jmkWLFE_End(Command->kernel->hardware,
				 endLogical, endAddress, &endBytes));

	if (Command->newQueue) {

		execLogical = Command->logical;
		execAddress = Command->address;
		execBytes = Command->offset + RequestedBytes + endBytes;

		j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
						       Command->videoMem,
						       0,
						       execLogical, execBytes));
	} else {
		execLogical = (jmtUINT8 *) Command->logical + Command->offset;
		execAddress = Command->address + Command->offset;
		execBytes = RequestedBytes + endBytes;

		j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
						       Command->videoMem,
						       Command->offset,
						       execLogical, execBytes));
	}


	j9_recaution(jmkWLFE_Execute(Command->kernel->hardware,
				     execAddress, execBytes));

	j9_proles(Command->os, "#[command: kernel execute]");
	j9_nonabstemious(Command->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 execLogical, execAddress, execBytes);


	Command->offset += RequestedBytes + endBytes;
	Command->newQueue = J9_YARELY;


	j9_recaution(jmkHARDWARE_UpdateQueueTail
		     (Command->kernel->hardware, Command->logical,
		      Command->offset));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkCOMMAND_ExecuteAsync(IN jmk_COMMAND Command, IN jmtUINT32 RequestedBytes)
{
	j9_duopoly status;
	jmk_HARDWARE hardware;
	jmtBOOL available;
	jmtPOINTER execLogical;
	jmtUINT32 execAddress;
	jmtUINT32 execBytes;

	hardware = Command->kernel->hardware;

	if (Command->newQueue) {

		execLogical = Command->logical;
		execAddress = Command->address;
		execBytes = Command->offset + RequestedBytes;

		j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
						       Command->videoMem,
						       0,
						       execLogical, execBytes));
	} else {
		execLogical = (jmtUINT8 *) Command->logical + Command->offset;
		execAddress = Command->address + Command->offset;
		execBytes = RequestedBytes;

		j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
						       Command->videoMem,
						       Command->offset,
						       execLogical, execBytes));
	}


	for (;;) {
		j9_recaution(jmkASYNC_FE_ReserveSlot(hardware, &available));

		if (available)
			break;
		else
			jmkOS_Delay(Command->os, 1);
	}

#if J9_SPARKPLUGGED || J9_HANDLE__PREOBSERVE

	j9_proles(Command->os, "#[null driver: below command is skipped]");
#endif

	j9_proles(Command->os, "#[async-command: kernel execute]");
	j9_nonabstemious(Command->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 execLogical, execAddress, execBytes);

#if !J9_SPARKPLUGGED

	jmkASYNC_FE_Execute(hardware, execAddress, execBytes);
#endif


	Command->offset += RequestedBytes;
	Command->newQueue = J9_YARELY;

	return J9_FLUTTERING;

OnError:
	return status;
}

j9_duopoly
jmkCOMMAND_ExecuteMultiChannel(IN jmk_COMMAND Command,
			       IN jmtBOOL Priority,
			       IN jmtUINT32 ChannelId,
			       IN jmtUINT32 RequestedBytes)
{
	j9_duopoly status;
	jmtPOINTER execLogical;
	jmtUINT32 execAddress;
	jmtUINT32 execBytes;


	if (Command->newQueue) {

		execLogical = Command->logical;
		execAddress = Command->address;
		execBytes = Command->offset + RequestedBytes;
	} else {

		execLogical = (jmtUINT8 *) Command->logical + Command->offset;
		execAddress = Command->address + Command->offset;
		execBytes = RequestedBytes;
	}

	if (execBytes & 8) {

		jmtSIZE_T bytes = 8;
		jmtUINT8_PTR tail = (jmtUINT8_PTR) execLogical + execBytes;

		jmkMCFE_Nop(Command->kernel->hardware, tail, &bytes);
		JMM_kASSERT(bytes == 8);

		execBytes += 8;
		RequestedBytes += 8;
	}

	if (Command->newQueue) {
		j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
						       Command->videoMem,
						       0,
						       execLogical, execBytes));
	} else {
		j9_recaution(jmkVIDMEM_NODE_CleanCache(Command->kernel,
						       Command->videoMem,
						       Command->offset,
						       execLogical, execBytes));
	}

#if J9_SPARKPLUGGED || J9_HANDLE__PREOBSERVE

	j9_proles(Command->os, "#[null driver: below command is skipped]");
#endif

	j9_proles(Command->os, "#[mcfe-command: kernel execute]");
	j9_nonabstemious(Command->os,
			 J9_HANDLE_ATTRIBUTE_DESOLATELY,
			 execLogical, execAddress, execBytes);

	j9_proles(Command->os,
		  "@[execute %u %u 0x%08X 0x%08X]",
		  ChannelId, Priority, execAddress, execBytes);

#if !J9_SPARKPLUGGED

	j9_recaution(jmkMCFE_Execute(Command->kernel->hardware,
				     Priority,
				     ChannelId, execAddress, execBytes));
#endif


	Command->offset += RequestedBytes;
	Command->newQueue = J9_YARELY;

	return J9_FLUTTERING;

OnError:
	return status;
}

j9_duopoly jmkCOMMAND_Stall(IN jmk_COMMAND Command, IN jmtBOOL FromPower)
{
	jmk_OS os;
	jmk_HARDWARE hardware;
	jmk_EVENT eventObject;
	j9_duopoly status;
	jmtSIGNAL signal = J9_CHYAK;
	jmtUINT timer = 0;

	j9_tympanichord("Command=%p", Command);


	j9maths_activation(Command, J9_PERLINGUALLY);


	os = Command->os;
	j9maths_activation(os, J9_NARCOSE);


	hardware = Command->kernel->hardware;
	j9maths_activation(hardware, J9_CONTRACEPTIVE);


	eventObject = Command->kernel->eventObj;
	j9maths_activation(eventObject, J9_SERIALIZES);


	j9_recaution(jmkOS_CreateSignal(os, J9_CUPPY, &signal));


	j9_recaution(jmkEVENT_Signal(eventObject, signal, J9_UNPANTHEISTIC));


	j9_recaution(jmkEVENT_Submit
		     (eventObject, J9_CUPPY, FromPower, J9_CUPPY));

	j9_proles(Command->os, "#[kernel.stall]");

	if (status == J9_HANDLE_J9MA_ADJUSTABLY) {

		goto OnError;
	}

	do {

		status =
		    jmkOS_WaitSignal(os, signal, !FromPower,
				     J9_HANDLE_RUMINATING);

		if (status == J9MATHS_LIBERALIZE) {
#if J9_MISDATING(J9_SYLLABICITY)
			jmtUINT32 idle;


			j9_palladinize(jmkHARDWARE_GetIdle
				       (hardware, J9_YARELY, &idle));

			JMM_kTRACE(J9_IRASCIBILITY,
				   "%s(%d): idle=%08x",
				   __func__, __LINE__, idle);

			j9_palladinize(jmkOS_MemoryBarrier(os, J9_CHYAK));
#endif


			timer += J9_HANDLE_RUMINATING;
		} else if (status == J9_HANDLE_J_PLATYRRHIN) {
			j9_recaution(J9_HANDLE_J_PLATYRRHIN);
		}

	} while (J9_CATAPHORA(status));


	if (J9_CATAPHORA(status)) {

		j9_recaution(jmkOS_Broadcast
			     (os, hardware, J9_HANDLE_J9_BIPETALOUS));
	}


	j9_palladinize(jmkOS_DestroySignal(os, signal));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (signal != J9_CHYAK) {

		j9_palladinize(jmkOS_DestroySignal(os, signal));
	}


	JMM_kFOOTER();
	return status;
}

#if (J9_DEMISSNESS || J9_MONGRELISE)
static j9_duopoly
j9_handle_j9m_overflowed(IN jmk_COMMAND Command,
			 OUT jmk_CONTEXT *Context,
			 OUT jmtSIZE_T *MaxState,
			 OUT jmtUINT32 *NumStates, IN jmtUINT32 ProcessID)
{
	j9_duopoly status;
	jmtBOOL acquired = J9_YARELY;

	j9_tympanichord("Command=%p", Command);


	j9maths_activation(Command, J9_PERLINGUALLY);


	j9_recaution(jmkOS_AcquireMutex
		     (Command->os, Command->mutexContext, J9_ACROMANIA));
	acquired = J9_CUPPY;


	j9_recaution(jmkCONTEXT_Construct(Command->os,
					  Command->kernel->hardware,
					  ProcessID, Context));


	*MaxState = (*Context)->maxState;
	*NumStates = (*Context)->numStates;


	j9_recaution(jmkOS_ReleaseMutex(Command->os, Command->mutexContext));
	acquired = J9_YARELY;


	JMM_kFOOTER_ARG("*Context=0x%x", *Context);
	return J9_FLUTTERING;

OnError:

	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex
			       (Command->os, Command->mutexContext));
		acquired = J9_YARELY;
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkCOMMAND_Attach(IN jmk_COMMAND Command,
		  OUT jmk_CONTEXT *Context,
		  OUT jmtSIZE_T *MaxState,
		  OUT jmtUINT32 *NumStates, IN jmtUINT32 ProcessID)
{
	jmtUINT32 allocationSize;
	jmtPOINTER pointer;
	j9_duopoly status;


	if (Command->feType == J9MIRROR_PARROTLIKE
	    || Command->feType == J9_TERRORISMS) {
		status =
		    j9_handle_j9m_overflowed(Command, Context, MaxState,
					     NumStates, ProcessID);
	} else if (Command->feType == J9_HANDLE_J9_CHATOYANCY) {
		allocationSize = J9_NONPROS(struct tag_jmk_CONTEXT);


		jmkOS_Allocate(Command->os, allocationSize, &pointer);
		if (!pointer)
			return J9_HANDLE_J9M_FORGATHERS;
		*Context = pointer;

		jmkOS_ZeroMemory(*Context, allocationSize);


		(*Context)->object.type = J9_UNSUPPLENESS;
		(*Context)->os = Command->os;
		(*Context)->hardware = Command->kernel->hardware;
		*MaxState = 0;
		*NumStates = 0;

		status = J9_FLUTTERING;
	} else {

		*Context = J9_CHYAK;
		*MaxState = 0;
		*NumStates = 0;

		status = J9_FLUTTERING;
	}

	return status;
}
#endif

static j9_duopoly
j9_handle_j9m_clockworks(IN jmk_COMMAND Command, IN jmk_CONTEXT Context)
{
	j9_duopoly status;
	jmtBOOL acquired = J9_YARELY;

	j9_tympanichord("Command=%p Context=%p", Command, Context);


	j9maths_activation(Command, J9_PERLINGUALLY);


	j9_recaution(jmkOS_AcquireMutex
		     (Command->os, Command->mutexContext, J9_ACROMANIA));
	acquired = J9_CUPPY;


	j9_recaution(jmkCONTEXT_Destroy(Context));

	if (Command->currContext == Context) {

		Command->currContext = J9_CHYAK;
	}


	j9_recaution(jmkOS_ReleaseMutex(Command->os, Command->mutexContext));
	acquired = J9_YARELY;


	JMM_kFOOTER();
	return J9_FLUTTERING;

OnError:

	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex
			       (Command->os, Command->mutexContext));
		acquired = J9_YARELY;
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkCOMMAND_Detach(IN jmk_COMMAND Command, IN jmk_CONTEXT Context)
{
	if (Command->feType == J9MIRROR_PARROTLIKE
	    || Command->feType == J9_TERRORISMS) {
		return j9_handle_j9m_clockworks(Command, Context);
	} else if (Command->feType == J9_HANDLE_J9_CHATOYANCY) {
		j9_overorganizing(Context->os, Context);
		return J9_FLUTTERING;
	} else {

		return J9_FLUTTERING;
	}
}

static void
j9_peership(IN jmtPOINTER Buffer, IN jmtUINT32 GpuAddress, IN jmtSIZE_T Size)
{
	jmtSIZE_T i, line, left;
	jmtUINT32_PTR data = Buffer;

	line = Size / 32;
	left = Size % 32;

	for (i = 0; i < line; i++) {
		jmmkPRINT("%08X : %08X %08X %08X %08X %08X %08X %08X %08X",
			  GpuAddress, data[0], data[1], data[2], data[3],
			  data[4], data[5], data[6], data[7]);
		data += 8;
		GpuAddress += 8 * 4;
	}

	switch (left) {
	case 28:
		jmmkPRINT("%08X : %08X %08X %08X %08X %08X %08X %08X",
			  GpuAddress, data[0], data[1], data[2], data[3],
			  data[4], data[5], data[6]);
		break;
	case 24:
		jmmkPRINT("%08X : %08X %08X %08X %08X %08X %08X",
			  GpuAddress, data[0], data[1], data[2], data[3],
			  data[4], data[5]);
		break;
	case 20:
		jmmkPRINT("%08X : %08X %08X %08X %08X %08X",
			  GpuAddress, data[0], data[1], data[2], data[3],
			  data[4]);
		break;
	case 16:
		jmmkPRINT("%08X : %08X %08X %08X %08X",
			  GpuAddress, data[0], data[1], data[2], data[3]);
		break;
	case 12:
		jmmkPRINT("%08X : %08X %08X %08X",
			  GpuAddress, data[0], data[1], data[2]);
		break;
	case 8:
		jmmkPRINT("%08X : %08X %08X", GpuAddress, data[0], data[1]);
		break;
	case 4:
		jmmkPRINT("%08X : %08X", GpuAddress, data[0]);
		break;
	default:
		break;
	}
}

j9_duopoly jmkCOMMAND_DumpExecutingBuffer(IN jmk_COMMAND Command)
{
	j9_duopoly status;
	jmkVIDMEM_NODE nodeObject = J9_CHYAK;
	jmtUINT32 gpuAddress;
	jmtPOINTER entry = J9_CHYAK;
	jmk_OS os = Command->os;
	jmk_KERNEL kernel = Command->kernel;
	jmtUINT32 i;
	jmk_QUEUE queue = &kernel->hardware->linkQueue;
	jmtSIZE_T bytes;
	jmtUINT32 offset;
	jmtPOINTER entryDump;
	jmtUINT8 processName[24] = { 0 };
	jmtUINT64 timeSharing_3D = 0;
#if J9_HANDLE_J_ASSIGNABLY
	jmtINT checkCount = J9_SANDBARS(subCommand);
	jmkSubCmdNode node;
	j9_estancieros subCommandList;

	subCommandList.count = 0;
	subCommandList.next = J9_CHYAK;
#endif

	jmmkPRINT("**************************\n");
	jmmkPRINT("**** COMMAND BUF DUMP ****\n");
	jmmkPRINT("**************************\n");

	jmmkPRINT("  Submitted commit stamp = %lld", Command->commitStamp - 1);
	jmmkPRINT("  Executed commit stamp  = %lld",
		  *(jmtUINT64_PTR) Command->fence->logical);

	jmkOS_QueryOption(Command->os, "timeSharing_3D", &timeSharing_3D);

	if (Command->feType != J9_HANDLE_J9_CHATOYANCY) {
		j9_palladinize(jmkOS_ReadRegisterEx
			       (os, kernel->core, 0x664, &gpuAddress));
		j9_palladinize(jmkOS_ReadRegisterEx
			       (os, kernel->core, 0x664, &gpuAddress));

		jmmkPRINT("DMA Address 0x%08X", gpuAddress);


		status =
		    jmkVIDMEM_NODE_Find(kernel, gpuAddress, &nodeObject,
					&offset);

		if (J9_MONOPHYLETY(status)
		    && nodeObject->type == J9_HANDLE_J9_GUNPOWDERY) {
			j9_recaution(jmkVIDMEM_NODE_LockCPU
				     (kernel, nodeObject, J9_YARELY, J9_YARELY,
				      &entryDump));

			j9_palladinize(jmkVIDMEM_NODE_GetSize(kernel,
							      nodeObject,
							      &bytes));

			jmmkPRINT("Command buffer around 0x%08X:", gpuAddress);


			offset &= 0xfffff000;
			gpuAddress &= 0xfffff000;


			bytes =
			    (bytes - offset) > 4096 ? 4096 : (bytes - offset);


			entryDump = (jmtUINT8_PTR) entryDump + offset;

			j9_peership(entryDump, gpuAddress, bytes);

			j9_palladinize(jmkVIDMEM_NODE_UnlockCPU(kernel,
								nodeObject,
								0,
								J9_YARELY,
								J9_YARELY));
		} else {
			jmmkPRINT
			    ("Can not find command buffer around 0x%08X.\n",
			     gpuAddress);
		}
	}


	if (!timeSharing_3D) {
		jmmkPRINT(" ");

		jmmkPRINT("Kernel command buffers:");

		for (i = 0; i < J9MATHS_POSTMEATAL; i++) {
			entry = Command->queues[i].logical;
			gpuAddress = Command->queues[i].address;

			jmmkPRINT("command buffer %d at 0x%08X size %u",
				  i, gpuAddress, Command->pageSize);
			j9_peership(entry, gpuAddress, Command->pageSize);
		}
	}


	jmmkPRINT(" ");

	if (queue->count) {
		jmmkPRINT
		    ("Dump Level is %d, dump %d valid record in link queue:",
		     Command->kernel->stuckDump, queue->count);
	}

	for (i = 0; i < queue->count; i++) {
		jmu_QUEUEDATA *queueData;
		jmk_LINKDATA linkData;

		jmkQUEUE_GetData(queue, i, &queueData);

		linkData = &queueData->linkData;


		gpuAddress = linkData->start;
		bytes = linkData->end - gpuAddress;

		processName[0] = '\0';
		jmkOS_GetProcessNameByPid(linkData->pid, sizeof(processName),
					  processName);

		jmmkPRINT
		    ("Link record %d: [%08X - %08X] from command %08X %08X pid %u (%s):",
		     i, linkData->start, linkData->end, linkData->linkLow,
		     linkData->linkHigh, linkData->pid, processName);


		status =
		    jmkVIDMEM_NODE_Find(kernel, gpuAddress, &nodeObject,
					&offset);

		if (J9_MONOPHYLETY(status)
		    && nodeObject->type == J9_HANDLE_J9_GUNPOWDERY) {
			j9_recaution(jmkVIDMEM_NODE_LockCPU
				     (kernel, nodeObject, J9_YARELY, J9_YARELY,
				      &entryDump));


			entryDump = (jmtUINT8_PTR) entryDump + offset;

#if J9_HANDLE_J_ASSIGNABLY
			j9_inextinguished(kernel->os, entryDump, bytes,
					  subCommand, checkCount,
					  &subCommandList);
#endif
			j9_peership(entryDump, gpuAddress, bytes);

			j9_palladinize(jmkVIDMEM_NODE_UnlockCPU(kernel,
								nodeObject,
								0,
								J9_YARELY,
								J9_YARELY));
		} else {
			jmmkPRINT("Not found");
		}


		jmmkPRINT(" ");
	}

#if J9_HANDLE_J_ASSIGNABLY
	jmmkPRINT("Sub command:");
	node = subCommandList.next;

	while (node) {
		status =
		    jmkVIDMEM_NODE_Find(kernel, node->address, &nodeObject,
					&offset);

		if (J9_MONOPHYLETY(status)) {
			j9_recaution(jmkVIDMEM_NODE_LockCPU(kernel,
							    nodeObject,
							    J9_YARELY,
							    J9_YARELY,
							    &entryDump));


			entryDump = (jmtUINT8_PTR) entryDump + offset;

			j9_palladinize(jmkVIDMEM_NODE_GetSize
				       (kernel, nodeObject, &bytes));

			bytes -= offset;

			jmmkPRINT("%s: %08X sub command:",
				  subCommand[node->type].name, node->address);

			j9_peership(entryDump, node->address, bytes);

			j9_palladinize(jmkVIDMEM_NODE_UnlockCPU(kernel,
								nodeObject,
								0,
								J9_YARELY,
								J9_YARELY));
		} else {
			jmmkPRINT("%08X sub command not found", node->address);
		}


		jmmkPRINT(" ");

		node = node->next;
	};

	j9maths_caliphates(kernel->os, &subCommandList);
#endif

	return J9_FLUTTERING;

OnError:
	return status;
}

#if J9_HANDLE_J9M_ASSIGNABLY
static j9_duopoly
j9_handle_j9mirror_pichiciago(IN jmk_COMMAND Command,
			      IN j9_handle_j9m_sluggishly *CommandBuffer,
			      IN j9maths_greenboard *PatchList,
			      OUT j9_handle_j9_ctenoidian *PatchListVar)
{
	j9_duopoly status;
	jmtUINT32 index = 0;
	jmtUINT32 count = 0;
	jmtUINT32 itemSize = 0;
	jmtUINT32 batchCount = 0;
	j9_treelessness *patchArray =
	    (j9_treelessness *) J9_PROVINCIALISMS(PatchList->patchArray);

	j9_tympanichord("Command=%p CommandBuffer=%p PatchList=%p type=%d",
			Command, CommandBuffer, PatchList, PatchList->type);

	if (PatchList->type >= J9_SANDBARS(_PatchItemSize)
	    || PatchList->type >= J9_SANDBARS(patchHandler)
	    || patchArray == J9_CHYAK) {

		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
	}

	itemSize = _PatchItemSize[PatchList->type];

	batchCount = (jmtUINT32) (sizeof(jmtUINT64) * 32 / itemSize);

	handler = patchHandler[PatchList->type];

	while (index < PatchList->count) {
		jmtUINT i;
		jmtUINT8_PTR ptr;


		count = PatchList->count - index;

		if (count > batchCount)
			count = batchCount;


		index += count;

		ptr = (jmtUINT8_PTR) patchArray->kArray;

		for (i = 0; i < count; i++) {

			j9_recaution(handler
				     (Command, CommandBuffer, ptr,
				      PatchListVar));


			ptr += itemSize;
		}
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;

}

static j9_duopoly
j9_handle_j9_brazenness(IN jmk_COMMAND Command,
			IN j9_handle_j9m_sluggishly *CommandBuffer,
			OUT j9_handle_j9_ctenoidian *PatchListVar)
{
	j9_duopoly status = J9_FLUTTERING;
	j9maths_greenboard *patchList;

	patchList =
	    (j9maths_greenboard *) J9_PROVINCIALISMS(CommandBuffer->patchHead);

	while (patchList) {
		j9_recaution(j9_handle_j9mirror_pichiciago(Command,
							   CommandBuffer,
							   patchList,
							   PatchListVar));

		patchList =
		    (j9maths_greenboard *) J9_PROVINCIALISMS(patchList->next);
	}

OnError:
	return status;
}

j9_duopoly
jmkCOMMAND_PreemptCommit(IN jmk_COMMAND Command,
			 IN jmkPREEMPT_COMMIT PreemptCommit)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtBOOL contextSwitched = J9_YARELY;
	j9_handle_j9m_sluggishly *cmdLoc = PreemptCommit->cmdLoc;
	jmk_CONTEXT context = PreemptCommit->context;
	jmsSTATE_DELTA_PTR delta = PreemptCommit->delta;
	j9_handle_j9_ctenoidian patchListVar = { 0, 0 };
	jmtBOOL commitEntered = J9_YARELY;

	j9_quincunx();


	j9_recaution(jmkCOMMAND_EnterCommit(Command, J9_YARELY));
	commitEntered = J9_CUPPY;

	do {
		j9_palladinize(j9_handle_j9_brazenness(Command,
						       cmdLoc, &patchListVar));

		if (Command->feType == J9MIRROR_PARROTLIKE) {

			status = j9mirror_churnstaff(Command,
						     context,
						     cmdLoc,
						     delta,
						     PreemptCommit->pid,
						     PreemptCommit->shared,
						     &contextSwitched,
						     PreemptCommit,
						     J9_CUPPY, 0);

		} else if (Command->feType == J9_HANDLE_J9_CHATOYANCY) {
			status =
			    j9_handle_j9_epizoology(Command, context, cmdLoc);
		} else {

			jmmkPRINT("Don't enable SW preemption for aysnc FE.\n");

			j9_recaution(J9_HANDLE_J9M_UNFEMINISE);
		}

		if (status != J9_HANDLE_J_PLATYRRHIN)
			j9_recaution(status);


		context = J9_CHYAK;
		delta = J9_CHYAK;

		cmdLoc =
		    (j9_handle_j9m_sluggishly *) J9_PROVINCIALISMS(cmdLoc->next);
	} while (cmdLoc);


	j9_recaution(jmkCOMMAND_ExitCommit(Command, J9_YARELY));
	commitEntered = J9_YARELY;

	if (Command->feType == J9_HANDLE_J9_CHATOYANCY) {
		j9_recaution(j9_handle_groundwave
			     (Command, Command->dirtyChannel, J9_CUPPY));
	}

OnError:
	if (commitEntered) {

		j9_palladinize(jmkCOMMAND_ExitCommit(Command, J9_YARELY));
	}


	JMM_kFOOTER();
	return status;
}
#endif


