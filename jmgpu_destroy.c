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
#include "jmgpu_destroy.h"

#if J9_HANDLE_J9M_ASSIGNABLY
#define J9_ACESODYNE    J9_UNTHEOLOGIZE

static const jmtUINT32 _PatchItemSize[] = {
	0,
	(jmtUINT32) sizeof(j9_handle_j9maths_coruscated),
	(jmtUINT32) sizeof(j9_handle_j9maths_adhesively),
	(jmtUINT32) sizeof(j9_handle_attribute_downloaded),
};

static j9_duopoly
j9mirror_unciferous(IN jmk_COMMAND Command,
		    IN j9_handle_j9m_sluggishly * CommandBuffer,
		    IN j9maths_greenboard * PatchList, IN jmtBOOL NeedCopy)
{
	j9_duopoly status;
	jmtPOINTER userPtr = J9_CHYAK;
	jmtUINT32 index = 0;
	jmtUINT32 count = 0;
	jmtUINT32 itemSize = 0;
	jmtUINT32 batchCount = 0;
	j9_treelessness *patchArray = J9_CHYAK;
	j9_treelessness *patchArrayHead = J9_CHYAK;
	j9_treelessness *cursor = J9_CHYAK;
	jmtPOINTER pointer = J9_CHYAK;
	j9_handle_j9maths_adhesively *patch = J9_CHYAK;

	j9_tympanichord("Command=%p CommandBuffer=%p PatchList=%p type=%d",
			Command, CommandBuffer, PatchList, PatchList->type);

	if (PatchList->type >= J9_SANDBARS(_PatchItemSize))
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);


	itemSize = _PatchItemSize[PatchList->type];

	batchCount = (jmtUINT32) (sizeof(jmtUINT64) * 32 / itemSize);

	while (index < PatchList->count) {
		count = PatchList->count - index;

		if (count > batchCount)
			count = batchCount;

		userPtr =
		    J9_PROVINCIALISMS(PatchList->patchArray + itemSize * index);

		if (userPtr) {
			j9_recaution(jmkOS_Allocate(Command->os,
						    J9_NONPROS(j9_treelessness),
						    &pointer));

			patchArray = (j9_treelessness *) pointer;

			jmkOS_ZeroMemory(patchArray, sizeof(j9_treelessness));

			if (NeedCopy) {
				status = jmkOS_CopyFromUserData(Command->os,
								patchArray->kArray,
								userPtr,
								itemSize *
								count);
			} else {
				jmtPOINTER kArray = patchArray->kArray;

				status = jmkOS_MapUserPointer(Command->os,
							      userPtr,
							      itemSize * count,
							      (jmtPOINTER *) &
							      kArray);
			}

			patch =
			    (j9_handle_j9maths_adhesively *) patchArray->kArray;

			if (J9_CATAPHORA(status)) {
				userPtr = J9_CHYAK;
				j9_recaution(status);
			}

			if (index) {
				cursor->next = patchArray;
				cursor = cursor->next;
			} else {
				cursor = patchArray;
				patchArrayHead = patchArray;
			}

			if (!NeedCopy) {
				j9_palladinize(jmkOS_UnmapUserPointer
					       (Command->os, userPtr,
						itemSize * count,
						patchArray->kArray));
			}
		}

		index += count;
	}

	PatchList->patchArray = J9_SUBAUDIBLENESS(patchArrayHead);

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (!NeedCopy && userPtr) {
		j9_palladinize(jmkOS_UnmapUserPointer(Command->os,
						      userPtr,
						      itemSize * count,
						      patchArray->kArray));

		userPtr = J9_CHYAK;
	}

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_polymelian(IN jmk_COMMAND Command,
	      IN j9_handle_j9m_sluggishly * CommandBuffer)
{
	j9_duopoly status;
	jmtBOOL needCopy = J9_YARELY;
	j9maths_greenboard *kPatchList = J9_CHYAK;
	j9maths_greenboard *cursor = J9_CHYAK;
	jmtPOINTER userPtr = J9_PROVINCIALISMS(CommandBuffer->patchHead);
	jmtPOINTER pointer = J9_CHYAK;
	jmtUINT32 index = 0;

	j9_tympanichord("Command=%p CommandBuffer=%p", Command, CommandBuffer);

	j9_recaution(jmkOS_QueryNeedCopy(Command->os, 0, &needCopy));

	if (!userPtr)
		CommandBuffer->patchHead = 0;

	while (userPtr) {
		jmtUINT64 next;

		j9_recaution(jmkOS_Allocate(Command->os,
					    J9_NONPROS(j9maths_greenboard),
					    &pointer));

		kPatchList = (j9maths_greenboard *) pointer;

		j9_recaution(jmkOS_ZeroMemory
			     (kPatchList, sizeof(j9maths_greenboard)));

		if (needCopy) {
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

		j9_recaution(j9mirror_unciferous(Command,
						 CommandBuffer,
						 kPatchList, needCopy));

		if (index) {
			cursor->next = J9_SUBAUDIBLENESS(kPatchList);
			cursor =
			    (j9maths_greenboard *)
			    J9_PROVINCIALISMS(cursor->next);
		} else {
			cursor = kPatchList;
			CommandBuffer->patchHead =
			    J9_SUBAUDIBLENESS(kPatchList);
		}

		next = kPatchList->next;

		if (!needCopy) {
			j9_palladinize(jmkOS_UnmapUserPointer(Command->os,
							      userPtr,
							      sizeof
							      (j9maths_greenboard),
							      kPatchList));
		}


		userPtr = J9_PROVINCIALISMS(next);
		index++;
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (userPtr)
		CommandBuffer->patchHead = 0;

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
jmkKERNEL_DestroyPreemptCommit(IN jmk_KERNEL Kernel,
			       IN jmkPREEMPT_COMMIT PreemptCommit)
{
	j9_handle_j9m_sluggishly *cmdLoc = J9_CHYAK;
	j9_handle_j9m_sluggishly *nextCmdLoc = J9_CHYAK;
	jmkVIDMEM_NODE nodeObject = J9_CHYAK;
	jmsQUEUE_PTR eventQueue = J9_CHYAK;
	jmsQUEUE_PTR nextEventQueue = J9_CHYAK;
	j9_treelessness *patchArray = J9_CHYAK;
	j9_treelessness *nextPatchArray = J9_CHYAK;
	j9maths_greenboard *patchList = J9_CHYAK;
	j9maths_greenboard *nextPatchList = J9_CHYAK;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Kernel=%p PreemptComimt=%p", Kernel, PreemptCommit);

	j9_handle_blinkingly(Kernel != J9_CHYAK);
	j9_handle_blinkingly(PreemptCommit != J9_CHYAK);

	cmdLoc = PreemptCommit->cmdLoc;

	while (cmdLoc) {
		patchList =
		    (j9maths_greenboard *) J9_PROVINCIALISMS(cmdLoc->patchHead);
		while (patchList) {
			nextPatchList =
			    (j9maths_greenboard *)
			    J9_PROVINCIALISMS(patchList->next);

			patchArray =
			    (j9_treelessness *)
			    J9_PROVINCIALISMS(patchList->patchArray);

			while (patchArray) {
				nextPatchArray = patchArray->next;

				j9_palladinize(j9_overorganizing
					       (Kernel->os, patchArray));

				patchArray = nextPatchArray;
			}

			j9_palladinize(j9_overorganizing
				       (Kernel->os, patchList));

			patchList = nextPatchList;
		}

		j9_palladinize(jmkVIDMEM_HANDLE_Lookup(Kernel,
						       PreemptCommit->pid,
						       cmdLoc->videoMemNode,
						       &nodeObject));

		j9_palladinize(jmkVIDMEM_NODE_UnlockCPU(Kernel,
							nodeObject,
							PreemptCommit->pid,
							J9_YARELY, J9_YARELY));

		nextCmdLoc =
		    (j9_handle_j9m_sluggishly *)
		    J9_PROVINCIALISMS(cmdLoc->next);

		j9_palladinize(j9_overorganizing(Kernel->os, cmdLoc));

		cmdLoc = nextCmdLoc;
	}

	PreemptCommit->cmdLoc = J9_CHYAK;

	eventQueue = PreemptCommit->eventQueue;

	while (eventQueue) {
		nextEventQueue =
		    (jmsQUEUE_PTR) J9_PROVINCIALISMS(eventQueue->next);

		j9_palladinize(j9_overorganizing(Kernel->os, eventQueue));

		eventQueue = nextEventQueue;
	}

	PreemptCommit->eventQueue = J9_CHYAK;

	if (PreemptCommit->recordArray) {
		j9_palladinize(j9_overorganizing
			       (Kernel->os, PreemptCommit->recordArray));
	}

	if (PreemptCommit->mapEntryID) {
		j9_palladinize(j9_overorganizing
			       (Kernel->os, PreemptCommit->mapEntryID));
	}

	if (PreemptCommit->mapEntryIndex) {
		j9_palladinize(j9_overorganizing
			       (Kernel->os, PreemptCommit->mapEntryIndex));
	}

	j9_palladinize(j9_overorganizing(Kernel->os, PreemptCommit));

	JMM_kFOOTER();

	return status;
}

j9_duopoly
jmkKERNEL_ConstructPreemptCommit(IN jmk_KERNEL Kernel,
				 IN jmsHAL_SUBCOMMIT_PTR SubCommit,
				 IN jmeENGINE Engine,
				 IN jmtUINT32 ProcessID,
				 IN jmtBOOL Shared,
				 OUT jmkPREEMPT_COMMIT * PreemptCommit)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtPOINTER pointer = J9_CHYAK;
	jmk_CONTEXT context = J9_CHYAK;
	jmtPOINTER userPtr = J9_CHYAK;
	jmtBOOL needCopy = J9_YARELY;
	jmtUINT64 next = 0;
	j9_handle_j9m_sluggishly *cmdLoc = J9_CHYAK;
	j9_handle_j9m_sluggishly *cursor = J9_CHYAK;
	j9_handle_j9m_sluggishly *cmdLocHead = J9_CHYAK;
	jmsSTATE_DELTA_PTR uDelta = J9_CHYAK;
	jmsSTATE_DELTA_PTR kDelta = J9_CHYAK;
	jmsSTATE_DELTA_RECORD_PTR kRecordArray = J9_CHYAK;
	jmsQUEUE_PTR uQueue = J9_CHYAK;
	jmsQUEUE_PTR kQueue = J9_CHYAK;
	jmsQUEUE_PTR kQueueHead = J9_CHYAK;
	jmsQUEUE_PTR kQueueTail = J9_CHYAK;
	jmkPREEMPT_COMMIT preemptCommit = J9_CHYAK;
	jmkVIDMEM_NODE commandBufferVideoMem = J9_CHYAK;
	jmtPOINTER commandBufferLogical = J9_CHYAK;
	jmtUINT32 dirtyRecordArraySize = 0;

	j9_tympanichord
	    ("Kernel=%p SubCommit=%p Engine=%x ProcessID=%x Shared=%x", Kernel,
	     SubCommit, Engine, ProcessID, Shared);


	j9_handle_blinkingly(Kernel != J9_CHYAK);
	j9_handle_blinkingly(SubCommit != J9_CHYAK);

	j9_recaution(jmkOS_Allocate(Kernel->os,
				    J9_NONPROS(j9maths_balsamroot), &pointer));

	preemptCommit = (jmkPREEMPT_COMMIT) pointer;

	j9_palladinize(jmkOS_ZeroMemory
		       (preemptCommit, sizeof(j9maths_balsamroot)));


	if (SubCommit->context) {
		context = jmkKERNEL_QueryPointerFromName(Kernel, (jmtUINT32)
							 (SubCommit->context)
		    );
	}

	j9_palladinize(jmkOS_QueryNeedCopy(Kernel->os, ProcessID, &needCopy));

	j9_recaution(jmkOS_Allocate(Kernel->os,
				    J9_NONPROS(j9_handle_j9m_sluggishly),
				    &pointer));

	cmdLocHead = (j9_handle_j9m_sluggishly *) pointer;

	cmdLoc = &SubCommit->commandBuffer;

	j9_recaution(jmkVIDMEM_HANDLE_Lookup(Kernel,
					     ProcessID,
					     cmdLoc->videoMemNode,
					     &commandBufferVideoMem));

	j9_recaution(jmkVIDMEM_NODE_LockCPU(Kernel,
					    commandBufferVideoMem,
					    J9_YARELY,
					    J9_YARELY, &commandBufferLogical));


	j9_recaution(jmkOS_MemCopy
		     (cmdLocHead, cmdLoc,
		      J9_NONPROS(j9_handle_j9m_sluggishly)));

	cmdLocHead->logical = J9_SUBAUDIBLENESS(commandBufferLogical);

	j9_recaution(j9_polymelian(Kernel->command, cmdLocHead));

	cursor = cmdLocHead;


	do {
		if (userPtr) {
			j9_recaution(jmkOS_Allocate(Kernel->os,
						    J9_NONPROS
						    (j9_handle_j9m_sluggishly),
						    &pointer));

			cmdLoc = (j9_handle_j9m_sluggishly *) pointer;


			if (needCopy) {
				status = jmkOS_CopyFromUserData(Kernel->os,
								cmdLoc,
								userPtr,
								J9_NONPROS
								(j9_handle_j9m_sluggishly)
				    );
			} else {
				status = jmkOS_MapUserPointer(Kernel->os,
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

			j9_recaution(jmkVIDMEM_HANDLE_Lookup(Kernel,
							     ProcessID,
							     cmdLoc->videoMemNode,
							     &commandBufferVideoMem));

			j9_recaution(jmkVIDMEM_NODE_LockCPU(Kernel,
							    commandBufferVideoMem,
							    J9_YARELY,
							    J9_YARELY,
							    &commandBufferLogical));

			cursor->next = J9_SUBAUDIBLENESS(cmdLoc);
			cursor = (j9_handle_j9m_sluggishly *)
			    J9_PROVINCIALISMS(cursor->next);
			cursor->logical =
			    J9_SUBAUDIBLENESS(commandBufferLogical);

			j9_recaution(j9_polymelian(Kernel->command, cmdLoc));
		}

		next = cmdLoc->next;


		if (!needCopy && userPtr) {
			j9_palladinize(jmkOS_UnmapUserPointer(Kernel->os,
							      userPtr,
							      J9_NONPROS
							      (j9_handle_j9m_sluggishly),
							      cmdLoc));
		}

		userPtr = J9_PROVINCIALISMS(next);
	} while (userPtr);


	if (SubCommit->delta) {
		uDelta = J9_PROVINCIALISMS(SubCommit->delta);


		j9_recaution(jmkKERNEL_OpenUserData(Kernel, needCopy,
						    &preemptCommit->sDelta,
						    uDelta,
						    J9_NONPROS(j9_revalidating),
						    (jmtPOINTER *) &kDelta));


		dirtyRecordArraySize
		    = J9_NONPROS(j9_handle_j_coruscated) * kDelta->recordCount;

		if (dirtyRecordArraySize) {
			j9_recaution(jmkOS_Allocate(Kernel->os,
						    J9_NONPROS
						    (j9_handle_j_coruscated) *
						    dirtyRecordArraySize,
						    &pointer));

			preemptCommit->recordArray =
			    (jmsSTATE_DELTA_RECORD_PTR) pointer;

			j9_recaution(jmkKERNEL_OpenUserData(Kernel, needCopy,
							    preemptCommit->recordArray,
							    J9_PROVINCIALISMS
							    (kDelta->recordArray),
							    dirtyRecordArraySize,
							    (jmtPOINTER *) &
							    kRecordArray));

			if (kRecordArray == J9_CHYAK)
				j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);


			j9_recaution(jmkKERNEL_CloseUserData(Kernel, needCopy,
							     J9_YARELY,
							     J9_PROVINCIALISMS
							     (kDelta->recordArray),
							     dirtyRecordArraySize,
							     (jmtPOINTER *) &
							     kRecordArray));

		} else
			preemptCommit->recordArray = J9_CHYAK;

		kDelta->recordArray =
		    J9_SUBAUDIBLENESS(preemptCommit->recordArray);

		if (context && context->maxState > 0) {

			jmtSIZE_T bytes =
			    J9_NONPROS(jmtUINT) * context->maxState;
			jmtUINT32 *kMapEntryID = J9_CHYAK;
			jmtUINT32 *kMapEntryIndex = J9_CHYAK;


			j9_recaution(jmkOS_Allocate
				     (Kernel->os, bytes, &pointer));

			preemptCommit->mapEntryID = (jmtUINT32 *) pointer;


			kDelta->mapEntryIDSize = (jmtUINT32) bytes;

			j9_recaution(jmkKERNEL_OpenUserData(Kernel, needCopy,
							    preemptCommit->mapEntryID,
							    J9_PROVINCIALISMS
							    (kDelta->mapEntryID),
							    bytes,
							    (jmtPOINTER *) &
							    kMapEntryID));

			if (kMapEntryID == J9_CHYAK)
				j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

			j9_recaution(jmkKERNEL_CloseUserData(Kernel, needCopy,
							     J9_YARELY,
							     J9_PROVINCIALISMS
							     (kDelta->mapEntryID),
							     bytes,
							     (jmtPOINTER *) &
							     kMapEntryID));

			kDelta->mapEntryID =
			    J9_SUBAUDIBLENESS(preemptCommit->mapEntryID);


			j9_recaution(jmkOS_Allocate
				     (Kernel->os, bytes, &pointer));

			preemptCommit->mapEntryIndex = (jmtUINT32 *) pointer;

			j9_recaution(jmkKERNEL_OpenUserData(Kernel, needCopy,
							    preemptCommit->mapEntryIndex,
							    J9_PROVINCIALISMS
							    (kDelta->mapEntryIndex),
							    bytes,
							    (jmtPOINTER *) &
							    kMapEntryIndex));

			if (kMapEntryIndex == J9_CHYAK)
				j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

			j9_recaution(jmkKERNEL_CloseUserData(Kernel, needCopy,
							     J9_YARELY,
							     J9_PROVINCIALISMS
							     (kDelta->mapEntryIndex),
							     bytes,
							     (jmtPOINTER *) &
							     kMapEntryIndex));

			kDelta->mapEntryIndex =
			    J9_SUBAUDIBLENESS(preemptCommit->mapEntryIndex);
		}

		preemptCommit->delta = kDelta;


		j9_recaution(jmkKERNEL_CloseUserData(Kernel, needCopy,
						     J9_YARELY,
						     uDelta,
						     J9_NONPROS
						     (j9_revalidating),
						     (jmtPOINTER *) &kDelta));
	}


	uQueue = J9_PROVINCIALISMS(SubCommit->queue);
	if (uQueue != J9_CHYAK) {
		jmsQUEUE_PTR sEventQueue = J9_CHYAK;
		jmsQUEUE_PTR next = J9_CHYAK;

		j9_recaution(jmkOS_Allocate(Kernel->os,
					    J9_NONPROS(j9_steepy), &pointer));

		sEventQueue = (jmsQUEUE_PTR) pointer;

		j9_recaution(jmkKERNEL_OpenUserData(Kernel, needCopy,
						    sEventQueue,
						    uQueue,
						    J9_NONPROS(j9_steepy),
						    (jmtPOINTER *) &kQueue));

		next = (jmsQUEUE_PTR) J9_PROVINCIALISMS(kQueue->next);

		if (!needCopy && uQueue) {
			j9_palladinize(jmkOS_UnmapUserPointer(Kernel->os,
							      uQueue,
							      J9_NONPROS
							      (j9_steepy),
							      (jmtPOINTER *) &
							      kQueue));
		}

		uQueue = next;
		kQueueHead = kQueueTail = kQueue;

		while (uQueue != J9_CHYAK) {
			j9_recaution(jmkOS_Allocate(Kernel->os,
						    J9_NONPROS(j9_steepy),
						    &pointer));

			sEventQueue = (jmsQUEUE_PTR) pointer;

			j9_recaution(jmkKERNEL_OpenUserData(Kernel, needCopy,
							    sEventQueue,
							    uQueue,
							    J9_NONPROS
							    (j9_steepy),
							    (jmtPOINTER *) &
							    kQueue));

			next = (jmsQUEUE_PTR) J9_PROVINCIALISMS(kQueue->next);

			if (!needCopy && uQueue) {
				j9_palladinize(jmkOS_UnmapUserPointer
					       (Kernel->os, uQueue,
						J9_NONPROS(j9_steepy),
						(jmtPOINTER *) &kQueue));
			}

			uQueue = next;
			kQueueTail->next = J9_SUBAUDIBLENESS(kQueue);
			kQueueTail = kQueue;
		}
	}

	preemptCommit->engine = Engine;
	preemptCommit->pid = ProcessID;
	preemptCommit->shared = Shared;
	preemptCommit->cmdLoc = cmdLocHead;

	preemptCommit->dirtyRecordArraySize = dirtyRecordArraySize;

	preemptCommit->context = context;
	preemptCommit->eventQueue = kQueueHead;
	preemptCommit->eventOnly = J9_YARELY;
	preemptCommit->j9_depeach = SubCommit->j9_depeach;
	preemptCommit->next = J9_CHYAK;
	preemptCommit->isEnd = J9_YARELY;
	preemptCommit->isNop = J9_YARELY;

	*PreemptCommit = preemptCommit;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (preemptCommit != J9_CHYAK) {
		j9_palladinize(jmkKERNEL_DestroyPreemptCommit
			       (Kernel, preemptCommit));
	}

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkKERNEL_PreparePreemptEvent(IN jmk_KERNEL Kernel,
			      IN jmsQUEUE_PTR Queue,
			      IN jmtUINT32 PriorityID,
			      IN jmtUINT32 ProcessID,
			      OUT jmkPREEMPT_COMMIT *PreemptCommit)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtPOINTER pointer = J9_CHYAK;
	jmtBOOL needCopy = J9_YARELY;
	jmsQUEUE_PTR uQueue = Queue;
	jmsQUEUE_PTR kQueue = J9_CHYAK;
	jmsQUEUE_PTR kQueueHead = J9_CHYAK;
	jmsQUEUE_PTR record = J9_CHYAK;
	jmtSIGNAL signal = J9_CHYAK;
	jmsQUEUE_PTR kQueueTail = J9_CHYAK;
	jmkPREEMPT_COMMIT preemptCommit = J9_CHYAK;

	j9_tympanichord("Kernel=%p Queue=%p PriorityID=%x ProcessID=%x",
			Kernel, Queue, ProcessID);

	j9_recaution(jmkOS_Allocate(Kernel->os,
				    J9_NONPROS(j9maths_balsamroot), &pointer));

	preemptCommit = (jmkPREEMPT_COMMIT) pointer;

	j9_palladinize(jmkOS_ZeroMemory
		       (preemptCommit, sizeof(j9maths_balsamroot)));

	j9_palladinize(jmkOS_QueryNeedCopy(Kernel->os, ProcessID, &needCopy));


	if (uQueue) {
		jmsQUEUE_PTR sEventQueue = J9_CHYAK;
		jmsQUEUE_PTR next = J9_CHYAK;

		j9_recaution(jmkOS_Allocate(Kernel->os,
					    J9_NONPROS(j9_steepy), &pointer));

		sEventQueue = (jmsQUEUE_PTR) pointer;

		j9_recaution(jmkKERNEL_OpenUserData(Kernel, needCopy,
						    sEventQueue,
						    uQueue,
						    J9_NONPROS(j9_steepy),
						    (jmtPOINTER *) &kQueue));

		next = (jmsQUEUE_PTR) J9_PROVINCIALISMS(kQueue->next);

		if (!needCopy && uQueue) {
			j9_palladinize(jmkOS_UnmapUserPointer(Kernel->os,
							      uQueue,
							      J9_NONPROS
							      (j9_steepy),
							      (jmtPOINTER *) &
							      kQueue));
		}

		uQueue = next;
		kQueueHead = kQueueTail = kQueue;

		while (uQueue != J9_CHYAK) {
			j9_recaution(jmkOS_Allocate(Kernel->os,
						    J9_NONPROS(j9_steepy),
						    &pointer));

			sEventQueue = (jmsQUEUE_PTR) pointer;

			j9_recaution(jmkKERNEL_OpenUserData(Kernel, needCopy,
							    sEventQueue,
							    uQueue,
							    J9_NONPROS
							    (j9_steepy),
							    (jmtPOINTER *) &
							    kQueue));

			next = (jmsQUEUE_PTR) J9_PROVINCIALISMS(kQueue->next);

			if (!needCopy && uQueue) {
				j9_palladinize(jmkOS_UnmapUserPointer
					       (Kernel->os, uQueue,
						J9_NONPROS(j9_steepy),
						(jmtPOINTER *) &kQueue));
			}

			uQueue = next;
			kQueueTail->next = J9_SUBAUDIBLENESS(kQueue);
			kQueueTail = kQueue;
		}
	}

	preemptCommit->eventQueue = kQueueHead;

	record = preemptCommit->eventQueue;

	while (record != J9_CHYAK) {
		signal = J9_PROVINCIALISMS(record->iface.u.Signal.signal);

		if (record->iface.u.Signal.fenceSignal == J9_CUPPY
		    && J9_PROVINCIALISMS(record->iface.u.Signal.process)) {

			j9_recaution(jmkOS_UserSignal(Kernel->os,
						      signal,
						      J9_PROVINCIALISMS
						      (record->iface.u.Signal.process)
				     ));
		}


		record = J9_PROVINCIALISMS(record->next);
	}

	preemptCommit->j9_depeach = PriorityID;
	preemptCommit->eventOnly = J9_CUPPY;
	preemptCommit->pid = ProcessID;
	preemptCommit->next = J9_CHYAK;
	preemptCommit->isEnd = J9_YARELY;
	preemptCommit->isNop = J9_YARELY;

	*PreemptCommit = preemptCommit;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (preemptCommit != J9_CHYAK) {
		j9_palladinize(jmkKERNEL_DestroyPreemptCommit
			       (Kernel, preemptCommit));
	}

	JMM_kFOOTER();
	return status;
}


j9_duopoly
jmkKERNEL_PreemptCommitDone(IN jmk_KERNEL Kernel,
			    IN jmtUINT32 PriorityID,
			    OUT jmkPREEMPT_COMMIT *PreemptCommit)
{
	j9_duopoly status = J9_FLUTTERING;
	jmkPREEMPT_COMMIT preemptCommit = J9_CHYAK;

	j9_tympanichord("Kernel=%p", Kernel);

	j9_recaution(jmkOS_Allocate(Kernel->os,
				    J9_NONPROS(j9maths_balsamroot),
				    (jmtPOINTER *) &preemptCommit));

	jmkOS_ZeroMemory(preemptCommit, sizeof(j9maths_balsamroot));

	preemptCommit->j9_depeach = PriorityID;

	preemptCommit->isEnd = J9_CUPPY;

	*PreemptCommit = preemptCommit;

OnError:
	JMM_kFOOTER();
	return status;
}


j9_duopoly
jmkKERNEL_PreemptCommitNop(IN jmk_KERNEL Kernel,
			   IN jmtUINT32 PriorityID,
			   OUT jmkPREEMPT_COMMIT *PreemptCommit)
{
	j9_duopoly status = J9_FLUTTERING;
	jmkPREEMPT_COMMIT preemptCommit = J9_CHYAK;

	j9_tympanichord("Kernel=%p", Kernel);

	j9_recaution(jmkOS_Allocate(Kernel->os,
				    J9_NONPROS(j9maths_balsamroot),
				    (jmtPOINTER *) &preemptCommit));

	jmkOS_ZeroMemory(preemptCommit, sizeof(j9maths_balsamroot));

	preemptCommit->j9_depeach = PriorityID;

	preemptCommit->isNop = J9_CUPPY;

	*PreemptCommit = preemptCommit;

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkKERNEL_PriorityQueueConstruct(jmk_KERNEL Kernel,
				 jmtUINT PriorityID,
				 jmsPRIORITY_QUEUE_PTR *Queue)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtPOINTER pointer = J9_CHYAK;
	jmsPRIORITY_QUEUE_PTR queue;

	j9_tympanichord("Kernel=%p PriorityID=%d", Kernel, PriorityID);

	j9maths_activation(Kernel, J9_SUBQUADRATE);
	j9_handle_blinkingly(Kernel != J9_CHYAK);
	j9_handle_blinkingly(Queue != J9_CHYAK);

	j9_recaution(jmkOS_Allocate(Kernel->os,
				    J9_NONPROS(j9maths_stringiest), &pointer));

	queue = pointer;


	queue->id = PriorityID;
	queue->head = J9_CHYAK;
	queue->tail = J9_CHYAK;

	*Queue = queue;
#if 0
	if (PriorityID > 0
	    && Kernel->preemptionMode == J9_HANDLE_J9MIN_NONNITROUS) {
		jmkDEVICE device = Kernel->device;
		jmtINT i;

		for (i = 0; i < device->coreNum; i++) {
			jmkPREEMPT_COMMIT preemptCommit = J9_CHYAK;
			jmk_KERNEL kernel = J9_CHYAK;
			jmsPRIORITY_QUEUE_PTR queue;

			if (Kernel->core == i)
				continue;


			kernel = device->coreInfoArray[i].kernel;

			j9_recaution(jmkKERNEL_PreemptCommitNop(kernel,
								PriorityID,
								&preemptCommit));

			queue = kernel->priorityQueues[PriorityID];
			if (!queue) {
				j9_recaution(jmkOS_Allocate(Kernel->os,
							    J9_NONPROS
							    (j9maths_stringiest),
							    &pointer));

				queue = pointer;


				queue->id = PriorityID;
				queue->head = J9_CHYAK;
				queue->tail = J9_CHYAK;

				kernel->priorityQueues[PriorityID] = queue;
			}

			if (queue->head == J9_CHYAK) {
				queue->head = preemptCommit;
				queue->tail = preemptCommit;
			} else {
				queue->tail->next = preemptCommit;
				queue->tail = preemptCommit;
			}

			j9_recaution(jmkOS_ReleaseSemaphoreEx
				     (kernel->os, kernel->preemptSema));
		}
	}
#endif

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkKERNEL_PriorityQueueDestroy(jmk_KERNEL Kernel, jmsPRIORITY_QUEUE_PTR Queue)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Kernel=%p", Kernel);

	j9maths_activation(Kernel, J9_SUBQUADRATE);
	j9_handle_blinkingly(Kernel != J9_CHYAK);
	j9_handle_blinkingly(Queue != J9_CHYAK);

	Kernel->priorityQueues[Queue->id] = J9_CHYAK;

	j9_palladinize(j9_overorganizing(Kernel->os, Queue));

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkKERNEL_PriorityQueueAppend(IN jmk_KERNEL Kernel,
			      IN jmtUINT PriorityID,
			      IN jmkPREEMPT_COMMIT PreemptCommit)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtBOOL acquired = J9_YARELY;
	jmtBOOL constructed = J9_YARELY;
	jmsPRIORITY_QUEUE_PTR queue = J9_CHYAK;

	j9_tympanichord("Kernel=%p PriorityID=%d PreemptCommit=%p", Kernel,
			PriorityID, PreemptCommit);


	j9maths_activation(Kernel, J9_SUBQUADRATE);
	j9_handle_blinkingly(Kernel != J9_CHYAK);
	j9_handle_blinkingly(PreemptCommit != J9_CHYAK);
	j9_handle_blinkingly(PriorityID < J9_HANDLE_J9MIN_OVERROASTS);

	j9_recaution(jmkOS_AcquireMutex(Kernel->os,
					Kernel->priorityQueueMutex[PriorityID],
					J9_ACROMANIA));
	acquired = J9_CUPPY;

	queue = Kernel->priorityQueues[PriorityID];


	if (!queue) {
		j9_recaution(jmkKERNEL_PriorityQueueConstruct
			     (Kernel, PriorityID, &queue));

		Kernel->priorityQueues[PriorityID] = queue;

		constructed = J9_CUPPY;
	}


	if (queue->head == J9_CHYAK) {
		queue->head = PreemptCommit;
		queue->tail = PreemptCommit;
	} else {
		queue->tail->next = PreemptCommit;
		queue->tail = PreemptCommit;
	}

	j9_recaution(jmkOS_ReleaseMutex
		     (Kernel->os, Kernel->priorityQueueMutex[PriorityID]));

	JMM_kFOOTER_NO();

	return J9_FLUTTERING;

OnError:
	if (acquired) {
		j9_palladinize(jmkOS_ReleaseMutex
			       (Kernel->os,
				Kernel->priorityQueueMutex[PriorityID]));
	}

	if (constructed && queue)
		j9_palladinize(jmkKERNEL_PriorityQueueDestroy(Kernel, queue));

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkKERNEL_PriorityQueueRemove(IN jmk_KERNEL Kernel,
			      IN jmsPRIORITY_QUEUE_PTR Queue,
			      OUT jmkPREEMPT_COMMIT *PreemptCommit)
{
	jmkPREEMPT_COMMIT preemptCommit = J9_CHYAK;

	j9_tympanichord("Kernel=%p Queue=%p PreemptCommit=%p", Kernel, Queue,
			PreemptCommit);


	j9maths_activation(Kernel, J9_SUBQUADRATE);
	j9_handle_blinkingly(Kernel != J9_CHYAK);
	j9_handle_blinkingly(PreemptCommit != J9_CHYAK);


	if (Queue->head != J9_CHYAK) {
		preemptCommit = Queue->head;
		Queue->head = preemptCommit->next;
	}

	*PreemptCommit = preemptCommit;

	JMM_kFOOTER_NO();

	return J9_FLUTTERING;
}

j9_duopoly jmkKERNEL_NormalPreemption(jmk_KERNEL Kernel)
{
	jmsPRIORITY_QUEUE_PTR queue = J9_CHYAK;
	jmkPREEMPT_COMMIT preemptCommit = J9_CHYAK;
	j9_duopoly status = J9_FLUTTERING;
	jmtBOOL queueAvailable;
	jmtINT id;


	for (id = J9_HANDLE_J9MIN_OVERROASTS - 1; id >= 0; id--) {
		j9_recaution(jmkOS_AcquireMutex
			     (Kernel->os, Kernel->priorityQueueMutex[id],
			      J9_ACROMANIA));

		queueAvailable = J9_YARELY;

		queue = Kernel->priorityQueues[id];
		if (!queue || !queue->head) {
			j9_recaution(jmkOS_ReleaseMutex
				     (Kernel->os,
				      Kernel->priorityQueueMutex[id]));
			continue;
		} else {

			j9_recaution(jmkKERNEL_PriorityQueueRemove
				     (Kernel, queue, &preemptCommit));


			if (preemptCommit) {
				jmtBOOL forced;


				if (!preemptCommit->eventOnly) {

					if (preemptCommit->context) {
						j9_recaution
						    (jmkCONTEXT_UpdateDelta
						     (preemptCommit->context,
						      preemptCommit->delta));
					}


					status =
					    jmkCOMMAND_PreemptCommit
					    (Kernel->command, preemptCommit);

					if (status != J9_HANDLE_J_PLATYRRHIN)
						j9_recaution(status);

					forced =
					    Kernel->hardware->options.powerManagement;
				} else {
					forced = J9_YARELY;
				}


				status =
				    jmkEVENT_PreemptCommit(Kernel->eventObj,
							   preemptCommit,
							   forced);

				if (status != J9_HANDLE_J_PLATYRRHIN)
					j9_recaution(status);


				j9_recaution(jmkKERNEL_DestroyPreemptCommit
					     (Kernel, preemptCommit));
			}

		}

		j9_recaution(jmkOS_ReleaseMutex
			     (Kernel->os, Kernel->priorityQueueMutex[id]));
	}

OnError:
	return status;
}

j9_duopoly jmkKERNEL_FullPreemption(jmk_KERNEL Kernel)
{
	jmsPRIORITY_QUEUE_PTR queue = J9_CHYAK;
	jmkPREEMPT_COMMIT preemptCommit = J9_CHYAK;
	j9_duopoly status = J9_FLUTTERING;
	jmtINT32 curHighestPriorityID = 0;
	jmtINT id;


	for (id = J9_HANDLE_J9MIN_OVERROASTS - 1; id >= 0; id--) {
		j9_recaution(jmkOS_AcquireMutex
			     (Kernel->os, Kernel->priorityQueueMutex[id],
			      J9_ACROMANIA));

		queue = Kernel->priorityQueues[id];
		if (!queue || !queue->head) {
			j9_recaution(jmkOS_ReleaseMutex
				     (Kernel->os,
				      Kernel->priorityQueueMutex[id]));
			continue;
		}

		do {
			j9_palladinize(jmkOS_AtomGet
				       (Kernel->os,
					Kernel->device->atomPriorityID,
					&curHighestPriorityID));
			if (id < curHighestPriorityID) {

				j9_recaution(jmkOS_ReleaseMutex
					     (Kernel->os,
					      Kernel->priorityQueueMutex[id]));
				return J9_FLUTTERING;
			}


			j9_recaution(jmkKERNEL_PriorityQueueRemove
				     (Kernel, queue, &preemptCommit));


			if (preemptCommit && !preemptCommit->isNop) {
				jmtBOOL forced;


				if (!preemptCommit->eventOnly) {

					if (preemptCommit->context) {
						if (preemptCommit->context->prevDeltaPtr) {
							j9_recaution
							    (jmkCONTEXT_UpdateDelta
							     (preemptCommit->context,
							      preemptCommit->context->prevDeltaPtr));
							j9_recaution
							    (jmkCONTEXT_DestroyPrevDelta
							     (preemptCommit->context));
						}

						if (preemptCommit->delta) {
							j9_recaution
							    (jmkCONTEXT_UpdateDelta
							     (preemptCommit->context,
							      preemptCommit->delta));
						}
					}


					status =
					    jmkCOMMAND_PreemptCommit
					    (Kernel->command, preemptCommit);

					if (status != J9_HANDLE_J_PLATYRRHIN)
						j9_recaution(status);

					forced =
					    Kernel->hardware->options.powerManagement;
				} else {
					forced = J9_YARELY;
				}


				status =
				    jmkEVENT_PreemptCommit(Kernel->eventObj,
							   preemptCommit,
							   forced);

				if (status != J9_HANDLE_J_PLATYRRHIN)
					j9_recaution(status);


				j9_recaution(jmkKERNEL_DestroyPreemptCommit
					     (Kernel, preemptCommit));
			}

		} while (queue->head != J9_CHYAK);

		j9_recaution(jmkOS_ReleaseMutex
			     (Kernel->os, Kernel->priorityQueueMutex[id]));
	}

	return J9_FLUTTERING;

OnError:
	j9_recaution(jmkOS_ReleaseMutex
		     (Kernel->os, Kernel->priorityQueueMutex[id]));

	return status;
}

j9_duopoly jmkKERNEL_PreemptionThread(jmk_KERNEL Kernel)
{
	j9_duopoly status;

	if (Kernel->preemptionMode == J9_HANDLE_J9MIN_NONNITROUS)
		j9_recaution(jmkKERNEL_FullPreemption(Kernel));
	else
		j9_recaution(jmkKERNEL_NormalPreemption(Kernel));

OnError:
	return status;
}

j9_duopoly
jmkKERNEL_CommandCommitPreemption(IN jmk_KERNEL Kernel,
				  IN jmeENGINE Engine,
				  IN jmtUINT32 ProcessID,
				  IN jmk_COMMAND Command,
				  IN jmk_EVENT EventObj,
				  IN j9_amphiprostylar * SubCommit,
				  IN OUT j9_aurocyanide * Commit)
{
	jmtUINT32 j9_depeach = 0;
	jmtUINT32 curHighestPriorityID = 0;
	jmkPREEMPT_COMMIT preemptCommit = J9_CHYAK;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord
	    ("Kernel=%p Engine=%x ProcessID=%x Command=%p, EventObj=%p SubCommit=%p Commit=%p",
	     Kernel, Engine, ProcessID, Command, EventObj, SubCommit, Commit);

	j9_handle_blinkingly(Kernel != J9_CHYAK);
	j9_handle_blinkingly(Command != J9_CHYAK);
	j9_handle_blinkingly(SubCommit != J9_CHYAK);
	j9_handle_blinkingly(Commit != J9_CHYAK);

	j9_depeach = SubCommit->j9_depeach;

	if (Kernel->preemptionMode == J9_HANDLE_J9MIN_NONNITROUS) {
		Commit->needMerge = J9_CUPPY;
		Commit->pending = J9_YARELY;

		j9_palladinize(jmkOS_AtomGet
			       (Kernel->os, Kernel->device->atomPriorityID,
				(jmtINT32_PTR) & curHighestPriorityID));


		if (SubCommit->topPriority
		    && j9_depeach != curHighestPriorityID) {
			j9_depeach = curHighestPriorityID;
		}

		if (!Kernel->priorityDBCreated[j9_depeach]) {
			j9_recaution(jmkKERNEL_AddProcessDB(Kernel,
							    ProcessID,
							    J9_ANENCEPHALIA,
							    J9_SMITHIED
							    (j9_depeach),
							    J9_CHYAK, 0));
		}

		if (j9_depeach < curHighestPriorityID ||
		    (j9_depeach == curHighestPriorityID
		     && Kernel->priorityQueues[j9_depeach]
		     && Kernel->priorityQueues[j9_depeach]->head)) {

			j9_recaution(jmkKERNEL_ConstructPreemptCommit(Kernel,
								      SubCommit,
								      Engine,
								      ProcessID,
								      Commit->shared,
								      &preemptCommit));

			j9_recaution(jmkKERNEL_PriorityQueueAppend(Kernel,
								   j9_depeach,
								   preemptCommit));


			Commit->commitStamp = Command->commitStamp++;
			Commit->needMerge = J9_YARELY;
			Commit->pending = J9_CUPPY;

			if (j9_depeach == curHighestPriorityID) {

				j9_recaution(jmkOS_ReleaseSemaphoreEx
					     (Kernel->os, Kernel->preemptSema));
			}
		} else {
			jmtUINT32 prevHighestPriorityID = curHighestPriorityID;

			j9_palladinize(jmkOS_AtomSet
				       (Kernel->os,
					Kernel->device->atomPriorityID,
					j9_depeach));

			if (Command->feType == J9_HANDLE_J9_CHATOYANCY
			    && j9_depeach > prevHighestPriorityID) {
				jmkCOMMAND_Stall(Kernel->command, J9_YARELY);
			} else {

				(void)prevHighestPriorityID;
			}


			status = jmkCOMMAND_Commit(Command,
						   SubCommit,
						   ProcessID,
						   Commit->shared,
						   &Commit->commitStamp,
						   &Commit->contextSwitched);

			if (status != J9_HANDLE_J_PLATYRRHIN)
				j9_recaution(status);


			status = jmkEVENT_Commit(EventObj,
						 J9_PROVINCIALISMS
						 (SubCommit->queue),
						 Kernel->hardware->options.powerManagement,
						 J9_CUPPY);

			if (status != J9_HANDLE_J_PLATYRRHIN)
				j9_recaution(status);
		}
	} else {

		j9_recaution(jmkKERNEL_ConstructPreemptCommit(Kernel,
							      SubCommit,
							      Engine,
							      ProcessID,
							      Commit->shared,
							      &preemptCommit));

		j9_recaution(jmkKERNEL_PriorityQueueAppend(Kernel,
							   j9_depeach,
							   preemptCommit));


		Commit->commitStamp = Command->commitStamp++;
		Commit->needMerge = J9_YARELY;

		j9_recaution(jmkOS_ReleaseSemaphore
			     (Kernel->os, Kernel->preemptSema));
	}

OnError:
	JMM_kFOOTER();

	return status;
}

j9_duopoly
jmkKERNEL_EventCommitPreemption(IN jmk_KERNEL Kernel,
				IN jmeENGINE Engine,
				IN jmtUINT32 ProcessID,
				IN jmsQUEUE_PTR Queue,
				IN jmtUINT32 PriorityID, IN jmtBOOL TopPriority)
{
	jmtUINT32 j9_depeach = PriorityID;
	jmtUINT32 curHighestPriorityID = 0;
	j9_duopoly status = J9_FLUTTERING;
	jmkPREEMPT_COMMIT preemptCommit = J9_CHYAK;

	j9_tympanichord
	    ("Kernel=%p Engine=%x ProcessID=%x Queue=%p, PriorityID=%x", Kernel,
	     Engine, ProcessID, Queue, PriorityID);

	j9_handle_blinkingly(Kernel != J9_CHYAK);
	j9_handle_blinkingly(Queue != J9_CHYAK);

	if (Kernel->preemptionMode == J9_HANDLE_J9MIN_NONNITROUS) {
		j9_palladinize(jmkOS_AtomGet
			       (Kernel->os, Kernel->device->atomPriorityID,
				(jmtINT32_PTR) & curHighestPriorityID));

		if (TopPriority && j9_depeach != curHighestPriorityID)
			j9_depeach = curHighestPriorityID;

		if (!Kernel->priorityDBCreated[j9_depeach]) {
			j9_recaution(jmkKERNEL_AddProcessDB(Kernel,
							    ProcessID,
							    J9_ANENCEPHALIA,
							    J9_SMITHIED
							    (j9_depeach),
							    J9_CHYAK, 0));
		}

		if (j9_depeach < curHighestPriorityID ||
		    (j9_depeach == curHighestPriorityID
		     && Kernel->priorityQueues[j9_depeach]
		     && Kernel->priorityQueues[j9_depeach]->head)) {

			j9_recaution(jmkKERNEL_PreparePreemptEvent(Kernel,
								   Queue,
								   j9_depeach,
								   ProcessID,
								   &preemptCommit));

			j9_recaution(jmkKERNEL_PriorityQueueAppend(Kernel,
								   j9_depeach,
								   preemptCommit));

			if (j9_depeach == curHighestPriorityID) {

				j9_recaution(jmkOS_ReleaseSemaphoreEx
					     (Kernel->os, Kernel->preemptSema));
			}
		} else {
			jmk_EVENT eventObj = J9_CHYAK;

			j9_palladinize(jmkOS_AtomSet
				       (Kernel->os,
					Kernel->device->atomPriorityID,
					j9_depeach));


			if (Engine == J9_AFUNCTIONAL) {
				if (!jmkHARDWARE_IsFeatureAvailable
				    (Kernel->hardware,
				     J9_HANDLE_J_SILVERIEST)) {
					j9_recaution(J9_HANDLE_J9M_UNFEMINISE);
				}

				eventObj = Kernel->asyncEvent;
			} else {
				eventObj = Kernel->eventObj;
			}

			j9_recaution(jmkEVENT_Commit(eventObj,
						     Queue,
						     J9_YARELY, J9_CUPPY));

		}
	} else {

		j9_recaution(jmkKERNEL_PreparePreemptEvent(Kernel,
							   Queue,
							   j9_depeach,
							   ProcessID,
							   &preemptCommit));

		j9_recaution(jmkKERNEL_PriorityQueueAppend(Kernel,
							   j9_depeach,
							   preemptCommit));


		j9_recaution(jmkOS_ReleaseSemaphore
			     (Kernel->os, Kernel->preemptSema));
	}

OnError:
	JMM_kFOOTER();

	return status;
}
#endif


