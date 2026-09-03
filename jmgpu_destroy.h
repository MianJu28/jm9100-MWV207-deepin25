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


#ifndef __ec97c1b3_H_
#define __ec97c1b3_H_

#if J9_HANDLE_J9M_ASSIGNABLY
#define J9_HANDLE_J9MIN_OVERROASTS 3
#define J9_HANDLE_J9_MAGNETISED 29

typedef enum tag_jme_PREEMPTION_MODE {
	J9_HANDLE_J9MIN_NONNITROUS,
	J9_HANDLE_ATTRIBUTE_EQUIPOISED,
} j9mirror_commandery;

typedef struct tag_jms_PATCH_ARRAY {
	jmtUINT64 kArray[32];

	struct tag_jms_PATCH_ARRAY *next;
} j9_treelessness;


typedef struct tag_jms_PREEMPT_COMMIT *jmkPREEMPT_COMMIT;
typedef struct tag_jms_PREEMPT_COMMIT {

	jmtUINT32 j9_depeach;


	jmeENGINE engine;


	jmtUINT32 pid;


	jmtBOOL shared;


	j9_handle_j9m_sluggishly *cmdLoc;


	j9_revalidating sDelta;


	jmsSTATE_DELTA_PTR delta;


	jmsSTATE_DELTA_RECORD_PTR recordArray;


	jmsQUEUE_PTR eventQueue;


	jmtBOOL eventOnly;


	jmk_CONTEXT context;


	jmtUINT32 dirtyRecordArraySize;

	jmtUINT32 *mapEntryID;

	jmtUINT32 *mapEntryIndex;


	jmtBOOL isEnd;


	jmtBOOL isNop;

	jmkPREEMPT_COMMIT next;
} j9maths_balsamroot;


typedef struct tag_jms_PRIORITY_QUEUE *jmsPRIORITY_QUEUE_PTR;
typedef struct tag_jms_PRIORITY_QUEUE {

	jmtUINT32 id;


	jmkPREEMPT_COMMIT head;


	jmkPREEMPT_COMMIT tail;

	jmsPRIORITY_QUEUE_PTR next;
} j9maths_stringiest;


j9_duopoly
jmkKERNEL_ConstructPreemptCommit(IN jmk_KERNEL Kernel,
				 IN jmsHAL_SUBCOMMIT_PTR SubCommit,
				 IN jmeENGINE Engine,
				 IN jmtUINT32 ProcessID,
				 IN jmtBOOL Shared,
				 OUT jmkPREEMPT_COMMIT *PreemptCommit);


j9_duopoly
jmkKERNEL_PreparePreemptEvent(IN jmk_KERNEL Kernel,
			      IN jmsQUEUE_PTR Queue,
			      IN jmtUINT32 PriorityID,
			      IN jmtUINT32 ProcessID,
			      OUT jmkPREEMPT_COMMIT *PreemptCommit);


j9_duopoly
jmkKERNEL_PriorityQueueDestroy(jmk_KERNEL Kernel, jmsPRIORITY_QUEUE_PTR Queue);


j9_duopoly
jmkKERNEL_PriorityQueueAppend(IN jmk_KERNEL Kernel,
			      IN jmtUINT PriorityID,
			      IN jmkPREEMPT_COMMIT PreemptCommit);


j9_duopoly jmkKERNEL_PreemptionThread(jmk_KERNEL Kernel);


j9_duopoly
jmkKERNEL_CommandCommitPreemption(IN jmk_KERNEL Kernel,
				  IN jmeENGINE Engine,
				  IN jmtUINT32 ProcessId,
				  IN jmk_COMMAND Command,
				  IN jmk_EVENT EventObj,
				  IN j9_amphiprostylar * SubCommit,
				  IN OUT j9_aurocyanide * Commit);


j9_duopoly
jmkKERNEL_EventCommitPreemption(IN jmk_KERNEL Kernel,
				IN jmeENGINE Engine,
				IN jmtUINT32 ProcessID,
				IN jmsQUEUE_PTR Queue,
				IN jmtUINT32 PriorityID,
				IN jmtBOOL TopPriority);


j9_duopoly
jmkCOMMAND_PreemptCommit(IN jmk_COMMAND Command,
			 IN jmkPREEMPT_COMMIT PreemptCommit);


j9_duopoly
jmkCONTEXT_UpdateDelta(IN jmk_CONTEXT Context, IN jmsSTATE_DELTA_PTR Delta);


j9_duopoly jmkCONTEXT_DestroyPrevDelta(IN jmk_CONTEXT Context);


j9_duopoly
jmkCONTEXT_ConstructPrevDelta(IN jmk_CONTEXT Context,
			      IN jmtUINT32 ProcessID,
			      IN jmsSTATE_DELTA_PTR StateDelta);


j9_duopoly
jmkCONTEXT_PreemptUpdate(IN jmk_CONTEXT Context,
			 IN jmkPREEMPT_COMMIT PreemptCommit);


j9_duopoly
jmkEVENT_PreemptCommit(IN jmk_EVENT Event,
		       IN jmkPREEMPT_COMMIT PreemptCommit, IN jmtBOOL Forced);


j9_duopoly
jmkKERNEL_PreemptCommitDone(IN jmk_KERNEL Kernel,
			    IN jmtUINT32 PriorityID,
			    OUT jmkPREEMPT_COMMIT *PreemptCommit);
#endif

#endif


