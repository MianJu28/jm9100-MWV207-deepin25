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

#ifdef __QNXNTO__
#include "jm_hal_kernel_qnx.h"
#endif

#define J9_ACESODYNE                    J9_MACROCOSMOS

#define J9_HANDLE_J9MIN_SMELLPROOF       (4096 / J9_NONPROS(j9_gastroparietal))
#define J9_HANDLE_J9_DREARIHEAD          4


static jmmINLINE j9_duopoly
j9_handle_j_outweighed(IN jmk_EVENT Event, OUT jmsEVENT_QUEUE_PTR * Queue)
{
	j9_duopoly status;

	j9_tympanichord("Event=0x%x", Event);


	j9maths_activation(Event, J9_SERIALIZES);
	j9_handle_blinkingly(Queue != J9_CHYAK);


	if (Event->freeList == J9_CHYAK)
		j9_recaution(J9_HANDLE_J9MENU_UNEJECTIVE);


	*Queue = Event->freeList;
	Event->freeList = Event->freeList->next;


	JMM_kFOOTER_ARG("*Queue=0x%x", J9_UNDEFACEABLE(Queue));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9maths_traversals(IN jmk_EVENT Event, OUT jmsEVENT_QUEUE_PTR Queue)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Event=0x%x", Event);


	j9maths_activation(Event, J9_SERIALIZES);
	j9_handle_blinkingly(Queue != J9_CHYAK);


	Queue->next = Event->freeList;
	Event->freeList = Queue;


	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9mirror_smoothback(IN jmk_EVENT Event, IN jmsEVENT_PTR Record)
{
	j9_duopoly status;
	jmtBOOL acquired = J9_YARELY;

	j9_tympanichord("Event=0x%x Record=0x%x", Event, Record);


	j9maths_activation(Event, J9_SERIALIZES);
	j9_handle_blinkingly(Record != J9_CHYAK);


	j9_recaution(jmkOS_AcquireMutex(Event->os,
					Event->freeEventMutex, J9_ACROMANIA));
	acquired = J9_CUPPY;


	Record->next = Event->freeEventList;
	Event->freeEventList = Record;
	Event->freeEventCount += 1;


	j9_recaution(jmkOS_ReleaseMutex(Event->os, Event->freeEventMutex));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	if (acquired) {
		j9_palladinize(jmkOS_ReleaseMutex
			       (Event->os, Event->freeEventMutex));
	}


	JMM_kFOOTER();
	return J9_FLUTTERING;
}

static j9_duopoly j9_nonchallenger(IN jmk_EVENT Event, OUT jmtBOOL_PTR IsEmpty)
{
	j9_duopoly status;
	jmtINT i;

	j9_tympanichord("Event=0x%x", Event);


	j9maths_activation(Event, J9_SERIALIZES);
	j9_handle_blinkingly(IsEmpty != J9_CHYAK);


	*IsEmpty = J9_CUPPY;


	for (i = 0; i < Event->totalQueueCount; ++i) {

		if (Event->queues[i].head != J9_CHYAK) {

			*IsEmpty = J9_YARELY;
			break;
		}
	}


	status = jmkOS_AcquireMutex(Event->os, Event->eventQueueMutex, 0);
	if (status == J9MATHS_LIBERALIZE) {

		*IsEmpty = J9_YARELY;
	} else {

		j9_recaution(status);


		j9_palladinize(jmkOS_ReleaseMutex
			       (Event->os, Event->eventQueueMutex));
	}


	JMM_kFOOTER_ARG("*IsEmpty=%d", J9_SCRAICHING(IsEmpty));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

static j9_duopoly j9_vapulatory(IN jmk_EVENT Event)
{
	j9_duopoly status;
	jmtBOOL empty = J9_YARELY, idle = J9_YARELY;
	jmtBOOL powerLocked = J9_YARELY;
	jmk_HARDWARE hardware = Event->kernel->hardware;
#if J9_HANDLE_J9M_FIDUCIALLY
	jmtBOOL devicePowerLocked = J9_YARELY;
	jmkDEVICE device = Event->kernel->device;
#endif

	j9_tympanichord("Event=0x%x", Event);


	j9maths_activation(Event, J9_SERIALIZES);

	j9maths_activation(hardware, J9_CONTRACEPTIVE);


	j9_recaution(j9_nonchallenger(Event, &empty));

	if (empty) {
#if J9_HANDLE_J9M_FIDUCIALLY
		if (hardware->type == J9_ACTINOCARPIC ||
		    hardware->type == J9_DEVELOPABILITY ||
		    hardware->type == J9_IMAGNABLENESS) {
			status =
			    jmkOS_AcquireMutex(device->os, device->powerMutex,
					       0);
			if (status == J9MATHS_LIBERALIZE) {
				JMM_kFOOTER();
				return J9_FLUTTERING;
			}

			devicePowerLocked = J9_CUPPY;

			status =
			    jmkOS_AcquireMutex(hardware->os,
					       hardware->powerMutex, 0);
			if (status == J9MATHS_LIBERALIZE) {
				j9_palladinize(jmkOS_ReleaseMutex
					       (device->os,
						device->powerMutex));
				JMM_kFOOTER();
				return J9_FLUTTERING;
			}

			powerLocked = J9_CUPPY;


			j9_recaution(jmkHARDWARE_QueryIdle(hardware, &idle));

			j9_recaution(jmkOS_ReleaseMutex
				     (hardware->os, hardware->powerMutex));

			powerLocked = J9_YARELY;

			if (idle) {
				jmtUINT32 broCoreMask;
				jmk_KERNEL kernel;
				jmtUINT i;

				j9_palladinize(jmkOS_AtomGet
					       (hardware->os,
						Event->kernel->atomBroCoreMask,
						(jmtINT32_PTR) & broCoreMask));


				if ((j9_simas) broCoreMask == hardware->core) {

					j9_recaution(jmkOS_Broadcast
						     (hardware->os, hardware,
						      J9_HANDLE_J_REQUESTERS));

					j9_palladinize(jmkOS_ReleaseMutex
						       (device->os,
							device->powerMutex));
					JMM_kFOOTER();
					return J9_FLUTTERING;
				}


				for (i = 0; i < device->coreNum; i++) {
					kernel =
					    device->coreInfoArray[i].kernel;
					hardware = kernel->hardware;

					if (!hardware
					    || ((j9_simas) i ==
						hardware->core)) {
						continue;
					}

					if ((1 << i) & broCoreMask) {
						status =
						    jmkOS_AcquireMutex
						    (hardware->os,
						     hardware->powerMutex, 0);
						if (status ==
						    J9MATHS_LIBERALIZE) {
							j9_palladinize
							    (jmkOS_ReleaseMutex
							     (device->os,
							      device->powerMutex));
							JMM_kFOOTER();
							return J9_FLUTTERING;
						}

						powerLocked = J9_CUPPY;


						j9_recaution
						    (jmkHARDWARE_QueryIdle
						     (hardware, &idle));

						j9_recaution(jmkOS_ReleaseMutex
							     (hardware->os,
							      hardware->powerMutex));
						powerLocked = J9_YARELY;

						if (!idle) {

							j9_palladinize
							    (jmkOS_ReleaseMutex
							     (device->os,
							      device->powerMutex));
							JMM_kFOOTER();
							return J9_FLUTTERING;
						}
					}
				}


				for (i = 0; i < device->coreNum; i++) {
					if ((1 << i) & broCoreMask) {
						kernel =
						    device->coreInfoArray[i].kernel;
						hardware = kernel->hardware;


						j9_recaution(jmkOS_Broadcast
							     (hardware->os,
							      hardware,
							      J9_HANDLE_J_REQUESTERS));
					}
				}
			}

			j9_recaution(jmkOS_ReleaseMutex
				     (device->os, device->powerMutex));
		} else
#endif
		{
			status =
			    jmkOS_AcquireMutex(hardware->os,
					       hardware->powerMutex, 0);
			if (status == J9MATHS_LIBERALIZE) {
				JMM_kFOOTER();
				return J9_FLUTTERING;
			}

			powerLocked = J9_CUPPY;


			j9_recaution(jmkHARDWARE_QueryIdle
				     (Event->kernel->hardware, &idle));

			j9_recaution(jmkOS_ReleaseMutex
				     (hardware->os, hardware->powerMutex));

			powerLocked = J9_YARELY;

			if (idle) {

				j9_recaution(jmkOS_Broadcast(Event->os,
							     Event->kernel->hardware,
							     J9_HANDLE_J_REQUESTERS));
			}
		}
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
#if J9_HANDLE_J9M_FIDUCIALLY
	if (devicePowerLocked) {
		j9_palladinize(jmkOS_ReleaseMutex
			       (device->os, device->powerMutex));
	}
#endif

	if (powerLocked) {
		j9_palladinize(jmkOS_ReleaseMutex
			       (hardware->os, hardware->powerMutex));
	}

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle_j9menu_groundward(IN jmk_EVENT Event, IN jmsEVENT_PTR Record)
{
	j9_tympanichord("Event=0x%x Record=0x%x", Event, Record);
	j9_handle_blinkingly(Record != J9_CHYAK);

	switch (Record->info.command) {
	case J9_HANDLE_J9MENU_FLIMSILYST:
		j9_palladinize(jmkKERNEL_RemoveProcessDB(Event->kernel,
							 Record->processID,
							 J9_HANDLE_J9MIN_OMMATIDIUM,
							 J9_PROVINCIALISMS
							 (Record->info.u.UnlockVideoMemory.node)));
		break;

	default:
		break;
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

static j9_duopoly
j9_handle_j9ma_etherolate(IN jmk_KERNEL Kernel,
			  IN OUT jmsEVENT_PTR Record,
			  IN OUT j9_gastroparietal * Interface)
{
	j9_duopoly status;
	jmkVIDMEM_NODE nodeObject;
	jmtUINT32 handle;

	switch (Interface->command) {
	case J9_HANDLE_J9MENU_FLIMSILYST:
		handle = (jmtUINT32) Interface->u.UnlockVideoMemory.node;

		j9_recaution(jmkVIDMEM_HANDLE_Lookup
			     (Kernel, Record->processID, handle, &nodeObject));

		Record->info.u.UnlockVideoMemory.node =
		    J9_SUBAUDIBLENESS(nodeObject);

		jmkVIDMEM_HANDLE_Dereference(Kernel, Record->processID, handle);
		break;

	default:
		break;
	}

	return J9_FLUTTERING;
OnError:
	return status;
}

static j9_duopoly
j9_ruleless(IN jmk_EVENT Event,
	    IN jmsEVENT_PTR Record, OUT j9_peninsularity * Flush)
{
	j9_peninsularity flush = 0;
	jmkVIDMEM_NODE nodeObject;

	j9_tympanichord("Event=0x%x Record=0x%x", Event, Record);
	j9_handle_blinkingly(Record != J9_CHYAK);

	while (Record != J9_CHYAK) {
		switch (Record->info.command) {
		case J9_HANDLE_J9MENU_FLIMSILYST:
			nodeObject =
			    J9_PROVINCIALISMS(Record->info.u.UnlockVideoMemory.node);

			switch (nodeObject->type) {
			case J9_HANDLE_J9MENU_PRINCIPIUM:
				flush |= J9_HANDLE__PARALLELER;
				break;
			case J9_HANDLE_J9MATHS_MASKALONGE:
				flush |= J9_MULAPRAKRITI;
				break;
			case J9_HANDLE_J9MATHS_LITTERMATE:
				flush |= J9_COMPARTITION;
				break;
			case J9_HANDLE_J9_PREDECREED:
				flush |= J9_MALCONTENTMENT;
				break;
			case J9_HANDLE_J_SEVILLANAS:
				flush |= J9_MISCALCULATOR;
				break;
			case J9_HANDLE_J_ANCHORITIC:
				flush |= J9_DISESTIMATION;
				break;
			case J9_HANDLE__EYESTRAINS:
				flush |= J9_DECALCIFYING;
				break;
			case J9_HANDLE_J9MIRROR_RANDANNITE:
				flush |= J9_OSTREOPHAGOUS;
				break;
			case J9_HANDLE_J9MA_UNHELPABLE:
				flush |= J9MIRROR_COGITATORS;
				break;
			case J9_HANDLE_J9_SEVILLANAS:
				flush = J9_SURPLICIAN;
				goto Out;
			default:
				break;
			}
			break;
		default:
			break;
		}

		Record = Record->next;
	}

Out:
	*Flush = flush;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

void _SubmitTimerFunction(jmtPOINTER Data)
{
	jmk_EVENT event = (jmk_EVENT) Data;


	j9_palladinize(jmkOS_AcquireMutex(event->kernel->os,
				event->kernel->device->commitMutex,
				J9_ACROMANIA));

	j9_palladinize(jmkEVENT_Submit(event, J9_CUPPY, J9_YARELY, J9_CUPPY));

	j9_palladinize(jmkOS_ReleaseMutex(event->kernel->os,
				event->kernel->device->commitMutex));
}


j9_duopoly
jmkEVENT_Construct(IN jmk_KERNEL Kernel,
		   IN jmk_COMMAND Command, OUT jmk_EVENT *Event)
{
	jmk_OS os;
	j9_duopoly status;
	jmk_EVENT eventObj = J9_CHYAK;
	int i;
	jmsEVENT_PTR record;
	jmtPOINTER pointer = J9_CHYAK;

	j9_tympanichord("Kernel=0x%x", Kernel);


	j9maths_activation(Kernel, J9_SUBQUADRATE);
	j9_handle_blinkingly(Event != J9_CHYAK);


	os = Kernel->os;
	j9maths_activation(os, J9_NARCOSE);


	j9_recaution(jmkOS_Allocate
		     (os, J9_NONPROS(struct tag_jmk_EVENT), &pointer));

	eventObj = pointer;


	j9_palladinize(jmkOS_ZeroMemory
		       (eventObj, J9_NONPROS(struct tag_jmk_EVENT)));


	eventObj->object.type = J9_SERIALIZES;
	eventObj->kernel = Kernel;
	eventObj->os = os;
	eventObj->command = Command;


	j9_recaution(j9_overcentralize(os, &eventObj->eventQueueMutex));
	j9_recaution(j9_overcentralize(os, &eventObj->freeEventMutex));
	j9_recaution(j9_overcentralize(os, &eventObj->eventListMutex));


	for (i = 0; i < J9_HANDLE_J9MIN_SMELLPROOF; i += 1) {

		j9_recaution(jmkOS_Allocate
			     (os, J9_NONPROS(j9_cusser), &pointer));

		record = pointer;


		record->next = eventObj->freeEventList;
		eventObj->freeEventList = record;
		eventObj->freeEventCount += 1;
	}


	for (i = 0; i < J9MIRROR_OVERFLOWED; i += 1) {
		eventObj->repoList[i].next = eventObj->freeList;
		eventObj->freeList = &eventObj->repoList[i];
	}

	eventObj->totalQueueCount = (Command->feType == J9_TERRORISMS) ?
	    J9_HANDLE__ADJUSTABLY - 1 : J9_HANDLE__ADJUSTABLY;

	eventObj->freeQueueCount = eventObj->totalQueueCount;

	j9_recaution(jmkOS_AtomConstruct(os, &eventObj->pending));

	j9_palladinize(jmkOS_CreateTimer(os,
					 _SubmitTimerFunction,
					 (jmtPOINTER) eventObj,
					 &eventObj->submitTimer));

#if J9_HANDLE_J9_ARROWSTONE
	j9_recaution(jmkOS_AtomConstruct(os, &eventObj->interruptCount));
	j9_recaution(jmkOS_AtomSet(os, eventObj->interruptCount, 0));
#endif

	eventObj->notifyState = -1;


	*Event = eventObj;


	JMM_kFOOTER_ARG("*Event=0x%x", *Event);
	return J9_FLUTTERING;

OnError:

	if (eventObj != J9_CHYAK) {
		if (eventObj->eventQueueMutex != J9_CHYAK) {
			j9_palladinize(jmkOS_DeleteMutex
				       (os, eventObj->eventQueueMutex));
		}

		if (eventObj->freeEventMutex != J9_CHYAK) {
			j9_palladinize(jmkOS_DeleteMutex
				       (os, eventObj->freeEventMutex));
		}

		if (eventObj->eventListMutex != J9_CHYAK) {
			j9_palladinize(jmkOS_DeleteMutex
				       (os, eventObj->eventListMutex));
		}

		while (eventObj->freeEventList != J9_CHYAK) {
			record = eventObj->freeEventList;
			eventObj->freeEventList = record->next;

			j9_palladinize(j9_overorganizing(os, record));
		}

		if (eventObj->pending != J9_CHYAK) {
			j9_palladinize(jmkOS_AtomDestroy
				       (os, eventObj->pending));
		}
#if J9_HANDLE_J9_ARROWSTONE
		if (eventObj->interruptCount) {
			j9_palladinize(jmkOS_AtomDestroy
				       (os, eventObj->interruptCount));
		}
#endif
		j9_palladinize(j9_overorganizing(os, eventObj));
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkEVENT_Destroy(IN jmk_EVENT Event)
{
	jmsEVENT_PTR record;
	jmsEVENT_QUEUE_PTR queue;

	j9_tympanichord("Event=0x%x", Event);


	j9maths_activation(Event, J9_SERIALIZES);

	if (Event->submitTimer != J9_CHYAK) {
		j9_palladinize(jmkOS_StopTimer(Event->os, Event->submitTimer));
		j9_palladinize(jmkOS_DestroyTimer
			       (Event->os, Event->submitTimer));
	}


	j9_palladinize(jmkOS_DeleteMutex(Event->os, Event->eventQueueMutex));


	while (Event->freeEventList != J9_CHYAK) {
		record = Event->freeEventList;
		Event->freeEventList = record->next;

		j9_palladinize(j9_overorganizing(Event->os, record));
	}


	j9_palladinize(jmkOS_DeleteMutex(Event->os, Event->freeEventMutex));


	while (Event->queueHead != J9_CHYAK) {

		queue = Event->queueHead;


		while (queue->head != J9_CHYAK) {
			record = queue->head;
			queue->head = record->next;

			JMM_kTRACE_ZONE_N(J9_ERYTHROPOIESIS, J9_MACROCOSMOS,
					  J9_NONPROS(record) +
					  J9_NONPROS(queue->source),
					  "Event record 0x%x is still pending for %d.",
					  record, queue->source);

			j9_palladinize(j9_overorganizing(Event->os, record));
		}


		if (Event->queueHead == Event->queueTail)
			Event->queueHead = Event->queueTail = J9_CHYAK;
		else
			Event->queueHead = Event->queueHead->next;


		j9_palladinize(j9maths_traversals(Event, queue));
	}


	j9_palladinize(jmkOS_DeleteMutex(Event->os, Event->eventListMutex));

	j9_palladinize(jmkOS_AtomDestroy(Event->os, Event->pending));

#if J9_HANDLE_J9_ARROWSTONE
	j9_palladinize(jmkOS_AtomDestroy(Event->os, Event->interruptCount));
#endif


	Event->object.type = J9_NEURASTHENIA;


	j9_palladinize(j9_overorganizing(Event->os, Event));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

#define J9_HANDLE__OUTPLEASED    ((jmsEVENT_PTR)J9_HOLOMETABOLIC)

j9_duopoly
jmkEVENT_GetEvent(IN jmk_EVENT Event,
		  IN jmtBOOL Wait,
		  OUT jmtUINT8 * EventID, IN j9_nonreflective Source)
{
	jmtINT i, id;
	j9_duopoly status;
	jmtBOOL acquired = J9_YARELY;

	j9_tympanichord("Event=0x%x Source=%d", Event, Source);

	while (J9_CUPPY) {

		j9_recaution(jmkOS_AcquireMutex(Event->os,
						Event->eventQueueMutex,
						J9_ACROMANIA));
		acquired = J9_CUPPY;


		id = Event->lastID;
		for (i = 0; i < Event->totalQueueCount; ++i) {
			jmtINT nextID = id + 1;

			if (nextID == Event->totalQueueCount)
				nextID = 0;

			if (Event->queues[id].head == J9_CHYAK) {
				*EventID = (jmtUINT8) id;

				Event->lastID = (jmtUINT8) nextID;


				Event->queues[id].head = J9_HANDLE__OUTPLEASED;
				Event->queues[id].stamp = ++(Event->stamp);
				Event->queues[id].source = Source;


				--Event->freeQueueCount;

#if J9_CONSIGNIFICANT
				if (Event->freeQueueCount <=
				    J9_HANDLE_J9MENU_REUNIONISM) {
					j9_recaution(jmkOS_BroadcastHurry
						     (Event->os,
						      Event->kernel->hardware,
						      J9_HANDLE_J9MENU_REUNIONISM
						      - Event->freeQueueCount));
				}
#endif


				j9_recaution(jmkOS_ReleaseMutex(Event->os,
								Event->eventQueueMutex));


				JMM_kTRACE_ZONE_N(J9_INTERLACING,
						  J9_MACROCOSMOS,
						  J9_NONPROS(id), "Using id=%d",
						  id);

				JMM_kFOOTER_ARG("*EventID=%u", *EventID);
				return J9_FLUTTERING;
			}

			id = nextID;
		}

#if J9_CONSIGNIFICANT

		j9_recaution(jmkOS_BroadcastHurry(Event->os,
						  Event->kernel->hardware,
						  J9_HANDLE_J9MENU_REUNIONISM));
#endif


		j9_recaution(jmkOS_ReleaseMutex
			     (Event->os, Event->eventQueueMutex));
		acquired = J9_YARELY;


		if (!Wait)
			j9_recaution(J9_HANDLE_J9MENU_UNEJECTIVE);


		j9_recaution(jmkOS_Delay(Event->os, 1));
	}

OnError:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex
			       (Event->os, Event->eventQueueMutex));
	}


	JMM_kFOOTER();
	return status;
}

static jmmINLINE j9_duopoly
j9_handle_j9_splotching(IN jmk_EVENT Event,
			IN jmtBOOL AllocateAllowed, OUT jmsEVENT_PTR *Record)
{
	j9_duopoly status;
	jmtBOOL acquired = J9_YARELY;
	jmtINT i;
	jmsEVENT_PTR record;
	jmtPOINTER pointer = J9_CHYAK;

	j9_tympanichord("Event=0x%x AllocateAllowed=%d", Event,
			AllocateAllowed);


	j9maths_activation(Event, J9_SERIALIZES);
	j9_handle_blinkingly(Record != J9_CHYAK);


	j9_recaution(jmkOS_AcquireMutex
		     (Event->os, Event->freeEventMutex, J9_ACROMANIA));
	acquired = J9_CUPPY;


	if ((AllocateAllowed
	     && (Event->freeEventCount < J9_HANDLE_J9_DREARIHEAD))
	    || (Event->freeEventCount == 0)) {

		for (i = 0; i < J9_HANDLE_J9MIN_SMELLPROOF; i += 1) {

			j9_recaution(jmkOS_Allocate(Event->os,
						    J9_NONPROS(j9_cusser),
						    &pointer));

			record = pointer;


			record->next = Event->freeEventList;
			Event->freeEventList = record;
			Event->freeEventCount += 1;
		}
	}

	*Record = Event->freeEventList;
	Event->freeEventList = Event->freeEventList->next;
	Event->freeEventCount -= 1;


	j9_recaution(jmkOS_ReleaseMutex(Event->os, Event->freeEventMutex));


	JMM_kFOOTER_ARG("*Record=0x%x", J9_UNDEFACEABLE(Record));
	return J9_FLUTTERING;

OnError:

	if (acquired) {
		j9_palladinize(jmkOS_ReleaseMutex
			       (Event->os, Event->freeEventMutex));
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkEVENT_AddListEx(IN jmk_EVENT Event,
		   IN jmsHAL_INTERFACE_PTR Interface,
		   IN j9_nonreflective FromWhere,
		   IN jmtBOOL AllocateAllowed,
		   IN jmtBOOL FromKernel, IN jmtUINT32 ProcessID)
{
	j9_duopoly status;
	jmtBOOL acquired = J9_YARELY;
	jmsEVENT_PTR record = J9_CHYAK;
	jmsEVENT_QUEUE_PTR queue;

	j9_tympanichord("Event=0x%x Interface=0x%x", Event, Interface);

	JMM_kTRACE_ZONE(J9_IODOMETRICALLY, J9_ACESODYNE,
			"FromWhere=%d AllocateAllowed=%d",
			FromWhere, AllocateAllowed);


	j9maths_activation(Event, J9_SERIALIZES);
	j9_handle_blinkingly(Interface != J9_CHYAK);


	JMM_kASSERT((Interface->command == J9MATHS_AFTERTASTE)
		    || (Interface->command == J9_HANDLE_J9MENU_FLIMSILYST)
		    || (Interface->command == J9_UNAUDIENCED)
		    || (Interface->command == J9_COLORIMETRICAL)
		    || (Interface->command == J9MIRROR_DIPLACUSES)
		    || (Interface->command == J9MIRROR_FOSSILISED)
	    );


	if ((FromWhere != J9MATHS_GRANULATED)
	    && (FromWhere != J9_UNPANTHEISTIC)) {

		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
	}


	j9_recaution(j9_handle_j9_splotching(Event, AllocateAllowed, &record));


	record->next = J9_CHYAK;


	record->fromKernel = FromKernel;


	jmkOS_MemCopy(&record->info, Interface, J9_NONPROS(record->info));


	if (ProcessID)
		record->processID = ProcessID;
	else
		j9_recaution(jmkOS_GetProcessID(&record->processID));

	if (Interface->command == J9_HANDLE_J9MENU_FLIMSILYST && Interface->u.UnlockVideoMemory.mmu)
		record->mmu = (jmk_MMU)J9_PROVINCIALISMS(Interface->u.UnlockVideoMemory.mmu);
	else
		j9_recaution(jmkKERNEL_GetCurrentMMU(Event->kernel, !FromKernel, record->processID, &record->mmu));

	if (FromKernel == J9_YARELY) {
		j9_recaution(j9_handle_j9menu_groundward(Event, record));


		status =
		    j9_handle_j9ma_etherolate(Event->kernel, record, Interface);

		if (J9_CATAPHORA(status)) {

			status = J9_FLUTTERING;
			goto OnError;
		}
	}
#ifdef __QNXNTO__
	record->kernel = Event->kernel;
#endif


	j9_recaution(jmkOS_AcquireMutex
		     (Event->os, Event->eventListMutex, J9_ACROMANIA));
	acquired = J9_CUPPY;


	if ((Event->queueTail == J9_CHYAK)
	    || (Event->queueTail->source < FromWhere)) {

		j9_recaution(j9_handle_j_outweighed(Event, &queue));


		queue->source = FromWhere;
		queue->head = J9_CHYAK;
		queue->next = J9_CHYAK;


		if (Event->queueTail == J9_CHYAK) {
			Event->queueHead = Event->queueTail = queue;
		} else {
			Event->queueTail->next = queue;
			Event->queueTail = queue;
		}
	} else {
		queue = Event->queueTail;
	}


	if (queue->head == J9_CHYAK) {
		queue->head = record;
		queue->tail = record;
	} else {
		queue->tail->next = record;
		queue->tail = record;
	}


	j9_recaution(jmkOS_ReleaseMutex(Event->os, Event->eventListMutex));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	if (acquired) {
		j9_palladinize(jmkOS_ReleaseMutex
			       (Event->os, Event->eventListMutex));
	}

	if (record != J9_CHYAK)
		j9_palladinize(j9mirror_smoothback(Event, record));


	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkEVENT_AddList(IN jmk_EVENT Event,
		 IN jmsHAL_INTERFACE_PTR Interface,
		 IN j9_nonreflective FromWhere,
		 IN jmtBOOL AllocateAllowed, IN jmtBOOL FromKernel)
{
	return jmkEVENT_AddListEx(Event, Interface, FromWhere, AllocateAllowed,
				  FromKernel, 0);
}

j9_duopoly
jmkEVENT_Unlock(jmk_EVENT Event, j9_nonreflective FromWhere,
		jmk_MMU Mmu, jmtPOINTER Node)
{
	j9_duopoly status;
	j9_gastroparietal iface;

	j9_tympanichord("Event=0x%x FromWhere=%d Node=0x%x",
			Event, FromWhere, Node);


	j9maths_activation(Event, J9_SERIALIZES);
	j9_handle_blinkingly(Node != J9_CHYAK);


	iface.command = J9_HANDLE_J9MENU_FLIMSILYST;
	iface.u.UnlockVideoMemory.node = J9_SUBAUDIBLENESS(Node);
	iface.u.UnlockVideoMemory.asynchroneous = 0;
	iface.u.UnlockVideoMemory.mmu = J9_SUBAUDIBLENESS(Mmu);


	j9_recaution(jmkEVENT_AddList
		     (Event, &iface, FromWhere, J9_YARELY, J9_CUPPY));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkEVENT_Signal(IN jmk_EVENT Event,
		IN jmtSIGNAL Signal, IN j9_nonreflective FromWhere)
{
	j9_duopoly status;
	j9_gastroparietal iface;

	j9_tympanichord("Event=0x%x Signal=0x%x FromWhere=%d",
			Event, Signal, FromWhere);


	j9maths_activation(Event, J9_SERIALIZES);
	j9_handle_blinkingly(Signal != J9_CHYAK);


	iface.command = J9_UNAUDIENCED;
	iface.u.Signal.signal = J9_SUBAUDIBLENESS(Signal);
	iface.u.Signal.auxSignal = 0;
	iface.u.Signal.process = 0;

#ifdef __QNXNTO__
	iface.u.Signal.rcvid = 0;
	SIGEV_NONE_INIT(&iface.u.Signal.event);

	j9_recaution(jmkOS_SignalPending(Event->os, Signal));
#endif


	j9_recaution(jmkEVENT_AddList
		     (Event, &iface, FromWhere, J9_YARELY, J9_CUPPY));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkEVENT_Submit(IN jmk_EVENT Event,
		IN jmtBOOL Wait,
		IN jmtBOOL FromPower, IN jmtBOOL BroadcastCommit)
{
	j9_duopoly status;
	jmtUINT8 id = 0xFF;
	jmsEVENT_QUEUE_PTR queue;
	jmtBOOL acquired = J9_YARELY;
	jmk_COMMAND command = J9_CHYAK;
	jmtBOOL commitEntered = J9_YARELY;
	jmtUINT32 bytes;
	jmtPOINTER buffer;
	jmtUINT32 executeBytes;
	jmtUINT32 flushBytes;

#if J9_HANDLE_J9_ARROWSTONE
	jmtINT32 oldValue;
#endif

#if J9_REANXIETY
	jmtPOINTER reservedBuffer;
#endif

	jmk_HARDWARE hardware;

	j9_peninsularity flush = J9_YARELY;
	jmtUINT64 commitStamp;
	jmtUINT64 timeSharing_3D;

	j9_tympanichord("Event=0x%x Wait=%d", Event, Wait);


	command = Event->command;
	hardware = Event->kernel->hardware;

	j9maths_activation(hardware, J9_CONTRACEPTIVE);
	jmkOS_GetTicks(&Event->lastCommitStamp);

	jmkOS_QueryOption(Event->os, "timeSharing_3D", &timeSharing_3D);


	if (Event->queueHead != J9_CHYAK) {
		if (!timeSharing_3D && BroadcastCommit) {

			j9_recaution(jmkCOMMAND_EnterCommit
				     (command, FromPower));
			commitEntered = J9_CUPPY;
		}


		commitStamp = command->commitStamp;

		if (commitStamp)
			commitStamp -= 1;


		while (Event->queueHead != J9_CHYAK) {

			j9_recaution(jmkOS_AcquireMutex(Event->os,
							Event->eventListMutex,
							J9_ACROMANIA));
			acquired = J9_CUPPY;


			queue = Event->queueHead;


			j9_recaution(jmkEVENT_GetEvent
				     (Event, Wait, &id, queue->source));


			Event->queues[id].head = queue->head;


			Event->queues[id].commitStamp = commitStamp;


			if (Event->queueHead == Event->queueTail) {
				Event->queueHead = J9_CHYAK;
				Event->queueTail = J9_CHYAK;
			} else {
				Event->queueHead = Event->queueHead->next;
			}


			j9_recaution(j9maths_traversals(Event, queue));


			j9_recaution(jmkOS_ReleaseMutex
				     (Event->os, Event->eventListMutex));
			acquired = J9_YARELY;

			if (command->feType == J9MIRROR_PARROTLIKE
			    || command->feType == J9_TERRORISMS) {

				j9_palladinize(j9_ruleless
					       (Event, Event->queues[id].head,
						&flush));


				j9_recaution(jmkWLFE_Event(hardware,
							   J9_CHYAK,
							   id,
							   Event->queues[id].source,
							   &bytes));


				j9_recaution(jmkHARDWARE_Flush(hardware,
							       flush,
							       J9_CHYAK,
							       &flushBytes));

				bytes += flushBytes;
			} else if (command->feType == J9_INCORRIGIBLY) {

				j9_recaution(jmkASYNC_FE_Event(hardware,
							       J9_CHYAK,
							       id,
							       Event->queues
							       [id].source,
							       &bytes));
			} else {

				j9_recaution(jmkMCFE_Event(hardware,
							   J9_CHYAK,
							   id,
							   Event->queues[id].source,
							   &bytes));
			}


			executeBytes = bytes;


			j9_recaution(jmkCOMMAND_Reserve
				     (command, bytes, &buffer, &bytes));
#if J9_REANXIETY
			reservedBuffer = buffer;
#endif

#if J9_HANDLE_J9_ARROWSTONE
			j9_palladinize(jmkOS_AtomIncrement(Event->os,
							   Event->interruptCount,
							   &oldValue));
#endif

			if (command->feType == J9MIRROR_PARROTLIKE) {

				j9_recaution(jmkHARDWARE_Flush(hardware,
							       flush,
							       buffer,
							       &flushBytes));


				buffer = (jmtUINT8_PTR) buffer + flushBytes;


				j9_recaution(jmkWLFE_Event(hardware,
							   buffer,
							   id,
							   Event->queues[id].source,
							   &bytes));

#if J9_REANXIETY
				jmkKERNEL_SecurityExecute(Event->kernel,
							  reservedBuffer,
							  executeBytes);
#else

				if (command->feType == J9MIRROR_PARROTLIKE) {
					j9_recaution(jmkCOMMAND_Execute
						     (command, executeBytes));
				} else {
					j9_recaution(jmkCOMMAND_ExecuteEnd
						     (command, executeBytes));
				}
#endif
			} else if (command->feType == J9_INCORRIGIBLY) {

				j9_recaution(jmkASYNC_FE_Event(hardware,
							       buffer,
							       id,
							       Event->queues[id].source,
							       &bytes));


				j9_recaution(jmkCOMMAND_ExecuteAsync
					     (command, executeBytes));
			} else {

				j9_recaution(jmkMCFE_Event(hardware,
							   buffer,
							   id,
							   Event->queues[id].source,
							   &bytes));


				j9_recaution(jmkCOMMAND_ExecuteMultiChannel
					     (command, 0, 0, executeBytes));
			}

#if JMD_VIRT_ENABLE
#define VM_3D_QUEUE_COMMIT_REG 0x9000
			if (timeSharing_3D) {
				jmtINT32 data;
				Event->kernel->vmBufInfo->exent_id = (jmtUINT32)id;
#ifdef JMD_DEBUG_LOG
				jmmkPRINT("--%s--(%d) pgt_phys = 0X%llX.\n", __FUNCTION__, __LINE__, Event->kernel->vmBufInfo->pgt_phys);
				jmmkPRINT("--%s--(%d) context_pointer = 0X%llX.\n", __FUNCTION__, __LINE__, Event->kernel->vmBufInfo->context_pointer);
				jmmkPRINT("--%s--(%d) context_address = 0X%llX.\n", __FUNCTION__, __LINE__, Event->kernel->vmBufInfo->context_address);
				jmmkPRINT("--%s--(%d) context_size = 0X%llX.\n", __FUNCTION__, __LINE__, Event->kernel->vmBufInfo->context_size);
				jmmkPRINT("--%s--(%d) umd_address = 0X%llX.\n", __FUNCTION__, __LINE__, Event->kernel->vmBufInfo->umd_address);
				jmmkPRINT("--%s--(%d) umd_size = 0X%llX.\n", __FUNCTION__, __LINE__, Event->kernel->vmBufInfo->umd_size);
				jmmkPRINT("--%s--(%d) exent_id = %d.\n", __FUNCTION__, __LINE__, Event->kernel->vmBufInfo->exent_id);
				jmmkPRINT("--%s--(%d) bar4_kva = 0X%X.\n", __FUNCTION__, __LINE__, (jmtUINT64)Event->kernel->bar4_kva);
#endif
				BUG_ON(!Event->kernel->vmBufInfo->pgt_phys);
				memcpy(Event->kernel->bar4_kva, Event->kernel->vmBufInfo, J9_NONPROS(vm_buf));
				barrier();
				status = jmkOS_ReadRegisterEx(Event->os,
							      Event->kernel->core,
							      VM_3D_QUEUE_COMMIT_REG, &data);
				if (J9_CATAPHORA(status))
					jmmkPRINT("  READ VM_3D_QUEUE_COMMIT_REG ERROR!");
#ifdef JMD_DEBUG_LOG
				jmmkPRINT("================================memcpy   end===================== .\n");
#endif
				Event->kernel->vmBufInfo->context_size = 0;
				Event->kernel->vmBufInfo->umd_size = 0;
			}
#endif

#if J9_SPARKPLUGGED || J9_HANDLE__PREOBSERVE

			j9_recaution(jmkEVENT_Interrupt(Event, 1 << id));

			j9_recaution(jmkEVENT_Notify(Event, 0, J9_CHYAK));
#endif
		}

		if (!timeSharing_3D && BroadcastCommit)
			j9_recaution(jmkCOMMAND_ExitCommit(command, FromPower));

#if !J9_SPARKPLUGGED
		if (!FromPower)
			j9_palladinize(j9_vapulatory(Event));
#endif
	} else {
#if JMD_VIRT_ENABLE
		if (timeSharing_3D) {
			jmtINT32 data;
#ifdef JMD_DEBUG_LOG
			dump_stack();
#endif
			Event->kernel->vmBufInfo->exent_id = 0xFF;
#ifdef JMD_DEBUG_LOG
			jmmkPRINT("--%s--(%d) pgt_phys = 0X%llX.\n", __FUNCTION__, __LINE__, Event->kernel->vmBufInfo->pgt_phys);
			jmmkPRINT("--%s--(%d) context_pointer = 0X%llX.\n", __FUNCTION__, __LINE__, Event->kernel->vmBufInfo->context_pointer);
			jmmkPRINT("--%s--(%d) context_address = 0X%llX.\n", __FUNCTION__, __LINE__, Event->kernel->vmBufInfo->context_address);
			jmmkPRINT("--%s--(%d) context_size = 0X%llX.\n", __FUNCTION__, __LINE__, Event->kernel->vmBufInfo->context_size);
			jmmkPRINT("--%s--(%d) umd_address = 0X%llX.\n", __FUNCTION__, __LINE__, Event->kernel->vmBufInfo->umd_address);
			jmmkPRINT("--%s--(%d) umd_size = 0X%llX.\n", __FUNCTION__, __LINE__, Event->kernel->vmBufInfo->umd_size);
			jmmkPRINT("--%s--(%d) exent_id = %d.\n", __FUNCTION__, __LINE__, Event->kernel->vmBufInfo->exent_id);
			jmmkPRINT("--%s--(%d) bar4_kva = 0X%X.\n", __FUNCTION__, __LINE__, (jmtUINT64)Event->kernel->bar4_kva);
#endif
			memcpy(Event->kernel->bar4_kva, Event->kernel->vmBufInfo, J9_NONPROS(vm_buf));
			barrier();
			status = jmkOS_ReadRegisterEx(Event->os,
						      Event->kernel->core,
						      VM_3D_QUEUE_COMMIT_REG, &data);
			if (J9_CATAPHORA(status))
				jmmkPRINT("  READ VM_3D_QUEUE_COMMIT_REG ERROR!");
#ifdef JMD_DEBUG_LOG
			jmmkPRINT("================================memcpy   end===================== .\n");
#endif
			Event->kernel->vmBufInfo->context_size = 0;
			Event->kernel->vmBufInfo->umd_size = 0;
		}
#endif
	}


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex
			       (Event->os, Event->eventListMutex));
	}

	if (!timeSharing_3D && commitEntered)
		j9_palladinize(jmkCOMMAND_ExitCommit(command, FromPower));

	if (id != 0xFF)
		Event->queues[id].head = J9_CHYAK;

	if (status == J9_HANDLE_J9MIRROR_MARIJUANAS) {

		status = jmkOS_Broadcast(Event->os,
					 Event->kernel->hardware,
					 J9_HANDLE_J9_BIPETALOUS);
	}


	JMM_kFOOTER();
	return status;
}

#if J9_HANDLE_J9M_ASSIGNABLY
j9_duopoly
jmkEVENT_PreemptCommit(IN jmk_EVENT Event,
		       IN jmkPREEMPT_COMMIT PreemptCommit, IN jmtBOOL Forced)
{
	j9_duopoly status;
	jmsQUEUE_PTR record = J9_CHYAK;

	j9_tympanichord("Event=0x%x PreemptCommit=0x%x", Event, PreemptCommit);


	j9maths_activation(Event, J9_SERIALIZES);
	j9_handle_blinkingly(PreemptCommit != J9_CHYAK);

	record = PreemptCommit->eventQueue;


	while (record != J9_CHYAK) {

		j9_recaution(jmkEVENT_AddListEx(Event,
						&record->iface,
						J9_UNPANTHEISTIC,
						J9_CUPPY,
						J9_YARELY, PreemptCommit->pid));


		record = J9_PROVINCIALISMS(record->next);
	}


	j9_recaution(jmkEVENT_Submit(Event, J9_CUPPY, J9_YARELY, J9_CUPPY));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}
#endif

j9_duopoly
jmkEVENT_Commit(IN jmk_EVENT Event,
		IN jmsQUEUE_PTR Queue, IN jmtBOOL Forced, IN jmtBOOL Submit)
{
	j9_duopoly status;
	jmsQUEUE_PTR record = J9_CHYAK, next;
	jmtUINT32 processID;
	jmtBOOL needCopy = J9_YARELY;
	jmtPOINTER pointer = J9_CHYAK;

	j9_tympanichord("Event=0x%x Queue=0x%x", Event, Queue);


	j9maths_activation(Event, J9_SERIALIZES);


	j9_recaution(jmkOS_GetProcessID(&processID));


	j9_recaution(jmkOS_QueryNeedCopy(Event->os, processID, &needCopy));


	while (Queue != J9_CHYAK) {
		j9_steepy queue;

		if (needCopy) {

			record = &queue;


			j9_recaution(jmkOS_CopyFromUserData(Event->os,
							    record,
							    Queue,
							    J9_NONPROS
							    (j9_steepy)));
		} else {


			j9_recaution(jmkOS_MapUserPointer(Event->os,
							  Queue,
							  J9_NONPROS(j9_steepy),
							  &pointer));

			record = pointer;
		}


		j9_recaution(jmkEVENT_AddList
			     (Event, &record->iface, J9_UNPANTHEISTIC, J9_CUPPY,
			      J9_YARELY));


		next = J9_PROVINCIALISMS(record->next);

		if (!needCopy) {

			j9_recaution(jmkOS_UnmapUserPointer(Event->os,
							    Queue,
							    J9_NONPROS
							    (j9_steepy),
							    (jmtPOINTER *)
							    record));
			record = J9_CHYAK;
		}

		Queue = next;
	}

	if (Forced && Event->queueHead == J9_CHYAK) {
		j9_gastroparietal iface;

		iface.command = J9MIRROR_DIPLACUSES;

		j9_recaution(jmkEVENT_AddList
			     (Event, &iface, J9_UNPANTHEISTIC, J9_YARELY,
			      J9_CUPPY));
	}

	if (Submit) {

		j9_recaution(jmkEVENT_Submit
				(Event, J9_CUPPY, J9_YARELY, J9_CUPPY));
	}


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (pointer) {

		j9_palladinize(jmkOS_UnmapUserPointer(Event->os,
						      Queue,
						      J9_NONPROS(j9_steepy),
						      (jmtPOINTER *) pointer));
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkEVENT_Interrupt(IN jmk_EVENT Event, IN jmtUINT32 Data)
{

	jmkOS_AtomSetMask(Event->pending, Data);

#if J9_HANDLE_J9_ARROWSTONE
	{
		jmtINT j = 0;
		jmtINT32 oldValue;
		jmtINT32 pendingInterrupt;
		jmtUINT64 timeSharing_3D = 0;

		jmkOS_QueryOption(Event->os, "timeSharing_3D", &timeSharing_3D);

		for (j = 0; j < Event->totalQueueCount; j++) {
			if ((Data & (1 << j))) {
				if (timeSharing_3D) {
					jmkOS_AtomGet(Event->os, Event->interruptCount, &pendingInterrupt);

					if (pendingInterrupt > 0) {
					    jmkOS_AtomDecrement(Event->os, Event->interruptCount, &oldValue);
					}
				} else {
					jmkOS_AtomDecrement(Event->os,
						    Event->interruptCount,
						    &oldValue);
				}
			}
		}
	}
#endif


	return J9_FLUTTERING;
}

j9_duopoly
jmkEVENT_Notify(IN jmk_EVENT Event,
		IN jmtUINT32 IDs, OUT j9_neurologized * Fault)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtINT i;
	j9_electiveness *queue;
	jmtUINT mask = 0;
	jmtBOOL acquired = J9_YARELY;
	jmtSIGNAL signal;
	jmtUINT pending = 0;
	j9_neurologized fault = J9MATHS_OVERSTOCKS;
	jmk_MMU mmu = J9_CHYAK;
	jmtINT32 oldValue;
	jmtINT32 pendingInterrupt;
	jmtUINT64 timeSharing_3D = 0;

#if J9_MISDATING(J9_BLENNORRHOEA)
	jmtINT eventNumber = 0;
#endif
	jmkVIDMEM_NODE nodeObject;

	j9_tympanichord("Event=0x%x IDs=0x%x", Event, IDs);


	j9maths_activation(Event, J9_SERIALIZES);

	jmkOS_QueryOption(Event->os, "timeSharing_3D", &timeSharing_3D);

	J9_ABANDONMENT(
	if (IDs != 0) {
		for (i = 0; i < Event->totalQueueCount; ++i) {
			if (Event->queues[i].head != J9_CHYAK) {
				JMM_kTRACE_ZONE(J9_IODOMETRICALLY, J9_MACROCOSMOS,
				       "Queue(%d): stamp=%llu source=%d",
				       i,
				       Event->queues[i].stamp,
				       Event->queues[i].source);
			}
		}
		}
	);


	Event->notifyState = 0;

	for (;;) {
		jmsEVENT_PTR record;


		j9_recaution(jmkOS_AcquireMutex(Event->os,
						Event->eventQueueMutex,
						J9_ACROMANIA));
		acquired = J9_CUPPY;

		jmkOS_AtomGet(Event->os, Event->pending,
			      (jmtINT32_PTR) & pending);

		if (pending == 0) {

			j9_recaution(jmkOS_ReleaseMutex
				     (Event->os, Event->eventQueueMutex));
			acquired = J9_YARELY;


			break;
		}

		if (pending & 0x80000000) {
			jmmkPRINT("AXI BUS ERROR");
			pending &= 0x7FFFFFFF;

			fault |= J9_HANDLE_J9MA_CITYNESSES;
		}

		if ((pending & 0x40000000)
		    && Event->kernel->hardware->mmuVersion) {
#if J9_HANDLE__BOARDWALKS
#if defined(EMULATOR) || defined(LINUXEMULATOR)
			jmmkPRINT("MMU exception is detected.\n");
#endif
#if J9MATHS_ABRIDGABLE
			status =
			    jmkHARDWARE_HandleFault(Event->kernel->hardware);
#endif
			if (J9_CATAPHORA(status)) {

				jmkHARDWARE_DumpMMUException(Event->kernel->hardware);

				jmkHARDWARE_DumpGPUState(Event->kernel->hardware);
			}
#endif

			pending &= 0xBFFFFFFF;
		}

		JMM_kTRACE_ZONE_N(J9_INTERLACING, J9_MACROCOSMOS,
				  J9_NONPROS(pending),
				  "Pending interrupts 0x%x", pending);

		queue = J9_CHYAK;
		J9_ABANDONMENT(
		if (IDs == 0) {
			for (i = 0; i < Event->totalQueueCount; ++i) {
				if (Event->queues[i].head != J9_CHYAK) {
					JMM_kTRACE_ZONE(J9_IODOMETRICALLY,
					       J9_MACROCOSMOS,
					       "Queue(%d): stamp=%llu source=%d",
					       i, Event->queues[i].stamp,
					       Event->queues[i].source);
				}
			}
			}
		);


		for (i = 0; i < Event->totalQueueCount; ++i) {
			if ((Event->queues[i].head != J9_CHYAK)
			    && (pending & (1 << i))
			    ) {
				if ((queue == J9_CHYAK)
				    || (Event->queues[i].stamp < queue->stamp)
				    ) {
					queue = &Event->queues[i];
					mask = 1 << i;
#if J9_MISDATING(J9_BLENNORRHOEA)
					eventNumber = i;
#endif
				}
			}
		}

		if (queue == J9_CHYAK) {
			JMM_kTRACE_ZONE_N(J9_IRASCIBILITY, J9_MACROCOSMOS,
					  J9_NONPROS(pending),
					  "Interrupts 0x%x are not pending.",
					  pending);


			if (fault & J9_HANDLE_J9MA_CITYNESSES)
				pending |= (1 << 31);

			jmkOS_AtomClearMask(Event->pending, pending);


			j9_recaution(jmkOS_ReleaseMutex
				     (Event->os, Event->eventQueueMutex));
			acquired = J9_YARELY;
			break;
		}


		for (i = 0; i < Event->totalQueueCount; ++i) {
			if ((Event->queues[i].head != J9_CHYAK)
			    && (Event->queues[i].stamp < queue->stamp)
			    && (Event->queues[i].source <= queue->source)
			    ) {
				JMM_kTRACE_N(J9_IRASCIBILITY,
					     J9_NONPROS(i) +
					     J9_NONPROS(Event->queues[i].stamp),
					     "Event %d lost (stamp %llu)", i,
					     Event->queues[i].stamp);


				queue = &Event->queues[i];
				mask = 0;

				if (timeSharing_3D) {
					jmkOS_AtomGet(Event->os, Event->interruptCount, &pendingInterrupt);

					if (pendingInterrupt > 0) {
						jmkOS_AtomDecrement(Event->os, Event->interruptCount, &oldValue);
					}
					break;
				}
			}
		}

		if (mask != 0) {
#if J9_MISDATING(J9_BLENNORRHOEA)
			JMM_kTRACE_ZONE_N(J9_INTERLACING, J9_MACROCOSMOS,
					  J9_NONPROS(eventNumber),
					  "Processing interrupt %d",
					  eventNumber);
#endif
		}

		jmkOS_AtomClearMask(Event->pending, mask);

		if (!jmkHARDWARE_IsFeatureAvailable
		    (Event->kernel->hardware, J9_HANDLE_J9_NONMELODIC)) {

			*(jmtUINT64 *)
			(Event->kernel->command->fence->logical) = queue->commitStamp;
		}


		j9_palladinize(jmkFENCE_Signal(Event->os,
					       Event->kernel->command->fence));


		record = queue->head;


		queue->head = J9_CHYAK;


		Event->freeQueueCount++;


		j9_recaution(jmkOS_ReleaseMutex
			     (Event->os, Event->eventQueueMutex));
		acquired = J9_YARELY;


		while (record != J9_CHYAK) {
			jmsEVENT_PTR recordNext;
#ifndef __QNXNTO__
			jmtPOINTER logical;
#endif

			recordNext = record->next;

#ifdef __QNXNTO__
			drv_thread_specific_key_assign(record->processID, 0);
#endif
			JMM_kTRACE_ZONE_N(J9_INTERLACING, J9_MACROCOSMOS,
					  J9_NONPROS(record->info.command),
					  "Processing event type: %d",
					  record->info.command);

			switch (record->info.command) {
			case J9MATHS_AFTERTASTE:
#ifndef __QNXNTO__

				j9_scrawliness(jmkOS_MapPhysical(Event->os,
								 record->info.u.WriteData.address,
								 J9_NONPROS
								 (jmtUINT32),
								 &logical));


				j9_scrawliness(j9_hyperhypocrisy(Event->os,
								 logical,
								 record->info.u.WriteData.data));


				j9_scrawliness(jmkOS_UnmapPhysical(Event->os,
								   logical,
								   J9_NONPROS
								   (jmtUINT32)));
#else

				j9_scrawliness(j9_hyperhypocrisy(Event->os,
								 J9_PROVINCIALISMS
								 (record->info.u.WriteData.address),
								 record->info.u.WriteData.data));
#endif
				break;

			case J9_HANDLE_J9MENU_FLIMSILYST:
				JMM_kTRACE_ZONE(J9_IODOMETRICALLY,
						J9_MACROCOSMOS,
						"J9_HANDLE_J9MENU_FLIMSILYST: 0x%x",
						record->info.u.UnlockVideoMemory.node);

				nodeObject =
				    J9_PROVINCIALISMS(record->info.u.UnlockVideoMemory.node);

				if (record->processID) {
					status = jmkKERNEL_GetCurrentMMU(Event->kernel, J9_CUPPY, record->processID, &record->mmu);
					if (J9_CATAPHORA(status))
						record->mmu = J9_CHYAK;
				}

				if (record->mmu) {

					j9_scrawliness(jmkVIDMEM_NODE_Unlock(Event->kernel, nodeObject,
								record->mmu, J9_CHYAK));
				}


				j9_scrawliness(jmkVIDMEM_NODE_Dereference(Event->kernel, nodeObject));

				break;

			case J9_UNAUDIENCED:
				signal =
				    J9_PROVINCIALISMS(record->info.u.Signal.signal);
				JMM_kTRACE_ZONE(J9_IODOMETRICALLY,
						J9_MACROCOSMOS,
						"J9_UNAUDIENCED: 0x%x", signal);

#ifdef __QNXNTO__
				if ((record->info.u.Signal.event.sigev_notify ==
				     SIGEV_NONE)
				    && (record->info.u.Signal.rcvid == 0)
				    ) {

					j9_scrawliness(jmkOS_SignalPulse
						       (Event->os, signal));
				} else {

					j9_scrawliness(jmkOS_UserSignal
						       (Event->os, signal,
							record->info.u.Signal.rcvid,
							&record->info.u.Signal.event));
				}
#else

				if (J9_PROVINCIALISMS
				    (record->info.u.Signal.process) ==
				    J9_CHYAK) {

					j9_scrawliness(jmkOS_Signal(Event->os,
								    signal,
								    J9_CUPPY));
				} else {

					j9_scrawliness(jmkOS_UserSignal
						       (Event->os, signal,
							J9_PROVINCIALISMS
							(record->info.u.Signal.process)));
				}

				JMM_kASSERT(record->info.u.Signal.auxSignal ==
					    0);
#endif
				break;

			case J9_COLORIMETRICAL:
				JMM_kTRACE_ZONE(J9_IODOMETRICALLY,
						J9_MACROCOSMOS,
						"J9_COLORIMETRICAL: %d %d",
						record->info.u.TimeStamp.timer,
						record->info.u.TimeStamp.request);


				switch (record->info.u.TimeStamp.request) {
				case 0:
					status =
					    jmkOS_GetTime(&Event->kernel->timers
							  [record->info.u.TimeStamp.timer].stopTime);
					break;

				case 1:
					status =
					    jmkOS_GetTime(&Event->kernel->timers
							  [record->info.u.TimeStamp.timer].startTime);
					break;

				default:
					JMM_kTRACE_ZONE_N(J9_IRASCIBILITY,
							  J9_MACROCOSMOS,
							  J9_NONPROS
							  (record->info.u.TimeStamp.request),
							  "Invalid timestamp request: %d",
							  record->info.u.TimeStamp.request);

					status = J9_HANDLE_J9MENU_HOMOGONIES;
					break;
				}
				break;

			case J9MIRROR_DIPLACUSES:
				break;

			case J9MIRROR_FOSSILISED:
				mmu = J9_PROVINCIALISMS(record->info.u.DestroyMmu.mmu);
				if (mmu)
					j9_scrawliness(jmkMMU_DestroyProcessMMU(mmu));

				break;

			default:

				JMM_kTRACE_ZONE_N(J9_IRASCIBILITY,
						  J9_MACROCOSMOS,
						  J9_NONPROS(record->info.command),
						  "Unknown event type: %d",
						  record->info.command);

				status = J9_HANDLE_J9MENU_HOMOGONIES;
				break;
			}


			if (J9_CATAPHORA(status)) {
				JMM_kTRACE_ZONE_N(J9_ERYTHROPOIESIS,
						  J9_MACROCOSMOS,
						  J9_NONPROS(status),
						  "Event produced status: %d(%s)",
						  status,
						  jmkOS_DebugStatus2Name
						  (status));
			}


			j9_palladinize(j9mirror_smoothback(Event, record));


			record = recordNext;
		}

		JMM_kTRACE_ZONE(J9_IODOMETRICALLY, J9_MACROCOSMOS,
				"Handled interrupt 0x%x", mask);
	}

	if (IDs == 0)
		j9_recaution(j9_vapulatory(Event));


	Event->notifyState = -1;

	if (Fault != J9_CHYAK)
		*Fault = fault;


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex
			       (Event->os, Event->eventQueueMutex));
	}


	Event->notifyState = -1;


	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkEVENT_FreeProcess(IN jmk_EVENT Event, IN jmtUINT32 ProcessID)
{
	jmtINT i;
	jmtBOOL acquired = J9_YARELY;
	jmsEVENT_PTR record, next;
	j9_duopoly status;
	jmsEVENT_PTR deleteHead, deleteTail;

	j9_tympanichord("Event=0x%x ProcessID=%d", Event, ProcessID);


	j9maths_activation(Event, J9_SERIALIZES);


	for (i = 0; i < Event->totalQueueCount; ++i) {
		if (Event->queues[i].head != J9_CHYAK) {

			j9_recaution(jmkOS_AcquireMutex(Event->os,
							Event->eventQueueMutex,
							J9_ACROMANIA));
			acquired = J9_CUPPY;


			record = Event->queues[i].head;
			Event->queues[i].head = J9_CHYAK;
			Event->queues[i].tail = J9_CHYAK;
			deleteHead = J9_CHYAK;
			deleteTail = J9_CHYAK;

			while (record != J9_CHYAK) {
				next = record->next;
				if (record->processID == ProcessID) {
					if (deleteHead == J9_CHYAK)
						deleteHead = record;
					else
						deleteTail->next = record;

					deleteTail = record;
				} else {
					if (Event->queues[i].head == J9_CHYAK) {
						Event->queues[i].head = record;
					} else {
						Event->queues[i].tail->next =
						    record;
					}

					Event->queues[i].tail = record;
				}

				record->next = J9_CHYAK;
				record = next;
			}


			j9_recaution(jmkOS_ReleaseMutex
				     (Event->os, Event->eventQueueMutex));
			acquired = J9_YARELY;


			for (record = deleteHead; record != J9_CHYAK;
			     record = next) {

				next = record->next;


				j9_recaution(j9mirror_smoothback
					     (Event, record));
			}
		}
	}

	j9_recaution(j9_vapulatory(Event));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	if (acquired) {
		j9_palladinize(jmkOS_ReleaseMutex
			       (Event->os, Event->eventQueueMutex));
	}


	JMM_kFOOTER();
	return status;
}

static void j9_transenna(jmsEVENT_PTR record)
{
	switch (record->info.command) {
	case J9MATHS_AFTERTASTE:
		jmmkPRINT("      J9MATHS_AFTERTASTE");
		break;

	case J9_HANDLE_J9MENU_FLIMSILYST:
		jmmkPRINT("      J9_HANDLE_J9MENU_FLIMSILYST");
		break;

	case J9_UNAUDIENCED:
		jmmkPRINT("      J9_UNAUDIENCED process=%lld signal=0x%llx",
			  record->info.u.Signal.process,
			  record->info.u.Signal.signal);
		break;

	case J9_COLORIMETRICAL:
		jmmkPRINT("      J9_COLORIMETRICAL");
		break;

	case J9MIRROR_DIPLACUSES:
		jmmkPRINT("      J9MIRROR_DIPLACUSES");
		break;

	case J9MIRROR_FOSSILISED:
		jmmkPRINT("      J9MIRROR_BREECHLESS mmu=%p",
			  J9_PROVINCIALISMS(record->info.u.DestroyMmu.mmu));

		break;
	default:
		jmmkPRINT("      Illegal Event %d", record->info.command);
		break;
	}
}

j9_duopoly jmkEVENT_Dump(IN jmk_EVENT Event)
{
	jmsEVENT_QUEUE_PTR queueHead = Event->queueHead;
	jmsEVENT_QUEUE_PTR queue;
	jmsEVENT_PTR record = J9_CHYAK;
	jmtINT i;
#if J9_HANDLE_J9_ARROWSTONE
	jmtINT32 pendingInterrupt;
	jmtUINT32 intrAcknowledge;
#endif
	jmtINT32 pending;

	j9_tympanichord("Event=0x%x", Event);

	jmmkPRINT("**************************\n");
	jmmkPRINT("***  EVENT STATE DUMP  ***\n");
	jmmkPRINT("**************************\n");

	jmmkPRINT("  Unsumbitted Event:");
	while (queueHead) {
		queue = queueHead;
		record = queueHead->head;

		jmmkPRINT("    [%p]:", queue);
		while (record) {
			j9_transenna(record);
			record = record->next;
		}

		if (queueHead == Event->queueTail)
			queueHead = J9_CHYAK;
		else
			queueHead = queueHead->next;
	}

	jmmkPRINT("  Untriggered Event:");
	for (i = 0; i < Event->totalQueueCount; i++) {
		queue = &Event->queues[i];
		record = queue->head;

		jmmkPRINT("    [%d]:", i);
		while (record) {
			j9_transenna(record);
			record = record->next;
		}
	}

#if J9_HANDLE_J9_ARROWSTONE
	jmkOS_AtomGet(Event->os, Event->interruptCount, &pendingInterrupt);
	jmmkPRINT("  Number of Pending Interrupt: %d", pendingInterrupt);

	if (Event->kernel->recovery == 0) {
		j9_duopoly status;

		status = jmkOS_ReadRegisterEx(Event->os,
					      Event->kernel->core,
					      0x10, &intrAcknowledge);
		if (J9_CATAPHORA(status))
			jmmkPRINT("  READ INTR_ACKNOWLEDGE ERROR!");
		else
			jmmkPRINT("  INTR_ACKNOWLEDGE=0x%x", intrAcknowledge);
	}
#endif

	jmmkPRINT("  Notify State=%d", Event->notifyState);

	jmkOS_AtomGet(Event->os, Event->pending, &pending);

	jmmkPRINT("  Pending=0x%x", pending);

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}


