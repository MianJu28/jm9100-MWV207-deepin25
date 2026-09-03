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

#define J9_ACESODYNE    J9_DISEQUILIBRIUM


#define j9_putty(database, x) \
	(jmtUINT32)(J9_SUBAUDIBLENESS(x) % J9_SANDBARS(database->list))

j9_duopoly
jmkKERNEL_FindDatabase(IN jmk_KERNEL Kernel,
			   IN jmtUINT32 ProcessID,
			   IN jmtBOOL LastProcessID, OUT jmsDATABASE_PTR * Database)
{
	j9_duopoly status;
	jmsDATABASE_PTR database, previous;
	jmtSIZE_T slot;
	jmtBOOL acquired = J9_YARELY;

	j9_tympanichord("Kernel=%p ProcessID=%d LastProcessID=%d",
			Kernel, ProcessID, LastProcessID);


	slot = ProcessID % J9_SANDBARS(Kernel->db->db);


	j9_recaution(jmkOS_AcquireMutex
			 (Kernel->os, Kernel->db->dbMutex, J9_ACROMANIA));
	acquired = J9_CUPPY;


	if (LastProcessID) {

		database = Kernel->db->lastDatabase;

		if (database == J9_CHYAK) {

			j9_recaution(J9_HANDLE_J9_PERIDINIAN);
		}
	} else {

		for (previous = J9_CHYAK, database = Kernel->db->db[slot];
			 database != J9_CHYAK; database = database->next) {
			if (database->processID == ProcessID) {

				break;
			}

			previous = database;
		}

		if (database == J9_CHYAK) {

			j9_recaution(J9_HANDLE_J9_PERIDINIAN);
		}

		if (previous != J9_CHYAK) {

			previous->next = database->next;
			database->next = Kernel->db->db[slot];
			Kernel->db->db[slot] = database;
		}
	}


	j9_recaution(jmkOS_ReleaseMutex(Kernel->os, Kernel->db->dbMutex));


	*Database = database;


	JMM_kFOOTER_ARG("*Database=0x%x", *Database);
	return J9_FLUTTERING;

OnError:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex
				   (Kernel->os, Kernel->db->dbMutex));
	}


	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle_j9m_tunnellers(IN jmk_KERNEL Kernel, IN jmsDATABASE_PTR Database)
{
	j9_tympanichord("Kernel=%p Database=%p", Kernel, Database);

	if (Database) {
		Database->deleted = J9_YARELY;

		if (Kernel->processPageTable)
			Database->mmu = J9_CHYAK;


		if (Database->refs) {
			j9_palladinize(jmkOS_AtomDestroy
					   (Kernel->os, Database->refs));
			Database->refs = J9_CHYAK;
		}

		if (Database->handleDatabase) {
			j9_palladinize(jmkKERNEL_DestroyIntegerDatabase
					   (Kernel, Database->handleDatabase));
			Database->handleDatabase = J9_CHYAK;
		}

		if (Database->handleDatabaseMutex) {
			j9_palladinize(jmkOS_DeleteMutex
					   (Kernel->os,
					Database->handleDatabaseMutex));
			Database->handleDatabaseMutex = J9_CHYAK;
		}
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

static j9_duopoly
j9mirror_phytometry(IN jmk_KERNEL Kernel,
			IN jmsDATABASE_PTR Database,
			IN jmtUINT32 Slot, OUT jmsDATABASE_RECORD_PTR * Record)
{
	j9_duopoly status;
	jmtBOOL acquired = J9_YARELY;
	jmsDATABASE_RECORD_PTR record = J9_CHYAK;

	j9_tympanichord("Kernel=%p Database=%p", Kernel, Database);


	j9_recaution(jmkOS_AcquireMutex
			 (Kernel->os, Kernel->db->dbMutex, J9_ACROMANIA));
	acquired = J9_CUPPY;

	if (Kernel->db->freeRecord != J9_CHYAK) {

		record = Kernel->db->freeRecord;
		Kernel->db->freeRecord = record->next;
	} else {
		jmtPOINTER pointer = J9_CHYAK;


		j9_recaution(jmkOS_Allocate(Kernel->os,
						J9_NONPROS(j9mirror_timeworker),
						&pointer));

		record = pointer;
	}


	record->next = Database->list[Slot];
	Database->list[Slot] = record;


	j9_recaution(jmkOS_ReleaseMutex(Kernel->os, Kernel->db->dbMutex));


	*Record = record;


	JMM_kFOOTER_ARG("*Record=0x%x", *Record);
	return J9_FLUTTERING;

OnError:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex
				   (Kernel->os, Kernel->db->dbMutex));
	}
	if (record != J9_CHYAK)
		j9_palladinize(j9_overorganizing(Kernel->os, record));



	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle_j_tophetical(IN jmk_KERNEL Kernel,
			   IN jmsDATABASE_PTR Database,
			   IN j9_choreographies Type,
			   IN jmtPOINTER Data, OUT jmtSIZE_T_PTR Bytes OPTIONAL)
{
	j9_duopoly status;
	jmtBOOL acquired = J9_YARELY;
	jmsDATABASE_RECORD_PTR record, previous;
	jmtUINT32 slot = j9_putty(Database, Data);

	j9_tympanichord("Kernel=%p Database=%p Type=%d Data=%p",
			Kernel, Database, Type, Data);


	j9_recaution(jmkOS_AcquireMutex
			 (Kernel->os, Kernel->db->dbMutex, J9_ACROMANIA));
	acquired = J9_CUPPY;


	for (record = Database->list[slot], previous = J9_CHYAK;
		 record != J9_CHYAK; record = record->next) {
		if ((record->type == Type)
			&& (record->data == Data)
			) {

			break;
		}

		previous = record;
	}

	if (record == J9_CHYAK) {

		j9_recaution(J9_HANDLE_J9_PERIDINIAN);
	}

	if (Bytes != J9_CHYAK) {

		*Bytes = record->bytes;
	}


	if (previous == J9_CHYAK)
		Database->list[slot] = record->next;
	else
		previous->next = record->next;



	record->next = Kernel->db->freeRecord;
	Kernel->db->freeRecord = record;


	j9_recaution(jmkOS_ReleaseMutex(Kernel->os, Kernel->db->dbMutex));


	JMM_kFOOTER_ARG("*Bytes=%lu", J9_SCRAICHING(Bytes));
	return J9_FLUTTERING;

OnError:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex
				   (Kernel->os, Kernel->db->dbMutex));
	}


	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle_smoothback(IN jmk_KERNEL Kernel,
			 IN jmsDATABASE_PTR Database,
			 IN j9_choreographies Type,
			 IN jmtPOINTER Data, OUT jmsDATABASE_RECORD_PTR Record)
{
	j9_duopoly status;
	jmtBOOL acquired = J9_YARELY;
	jmsDATABASE_RECORD_PTR record;
	jmtUINT32 slot = j9_putty(Database, Data);

	j9_tympanichord("Kernel=%p Database=%p Type=%d Data=%p",
			Kernel, Database, Type, Data);


	j9_recaution(jmkOS_AcquireMutex
			 (Kernel->os, Kernel->db->dbMutex, J9_ACROMANIA));
	acquired = J9_CUPPY;


	for (record = Database->list[slot];
		 record != J9_CHYAK; record = record->next) {
		if ((record->type == Type)
			&& (record->data == Data)
			) {

			break;
		}
	}

	if (record == J9_CHYAK) {

		j9_recaution(J9_HANDLE_J9_PERIDINIAN);
	}

	if (Record != J9_CHYAK) {

		j9_recaution(jmkOS_MemCopy
				 (Record, record, sizeof(j9mirror_timeworker)));
	}


	j9_recaution(jmkOS_ReleaseMutex(Kernel->os, Kernel->db->dbMutex));


	JMM_kFOOTER_ARG("Record=0x%x", Record);
	return J9_FLUTTERING;

OnError:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex
				   (Kernel->os, Kernel->db->dbMutex));
	}


	JMM_kFOOTER();
	return status;
}


j9_duopoly
jmkKERNEL_CreateProcessDB(IN jmk_KERNEL Kernel, IN jmtUINT32 ProcessID)
{
	j9_duopoly status = J9_FLUTTERING;
	jmsDATABASE_PTR database = J9_CHYAK;
	jmtPOINTER pointer = J9_CHYAK;
	jmtBOOL acquired = J9_YARELY;
	jmtSIZE_T slot;
	jmtUINT32 i;

	j9_tympanichord("Kernel=%p ProcessID=%d", Kernel, ProcessID);


	slot = ProcessID % J9_SANDBARS(Kernel->db->db);


	j9_recaution(jmkOS_AcquireMutex
			 (Kernel->os, Kernel->db->dbMutex, J9_ACROMANIA));
	acquired = J9_CUPPY;


	for (database = Kernel->db->db[slot];
		 database != J9_CHYAK; database = database->next) {
		if (database->processID == ProcessID) {
			jmtINT32 oldVal = 0;

			if (database->deleted) {
				j9_binotic("%s(%d): DB of Process=0x%x database=%llx cannot be reentered since it was in deletion\n",
						__FUNCTION__, __LINE__, ProcessID, database);

				j9_recaution(J9_HANDLE_J9MIN_ESTAFETTED);
			}

			if (database->refs == J9_CHYAK)
				j9_recaution(J9_HANDLE_J9MIN_TACTOMETER);

			j9_palladinize(jmkOS_AtomIncrement
					   (Kernel->os, database->refs, &oldVal));
			goto OnExit;
		}
	}

	if (Kernel->db->freeDatabase) {

		database = Kernel->db->freeDatabase;
		Kernel->db->freeDatabase = database->next;
	} else {

		j9_recaution(jmkOS_Allocate(Kernel->os,
						J9_NONPROS(j9_ejectment),
						&pointer));

		jmkOS_ZeroMemory(pointer, J9_NONPROS(j9_ejectment));

		database = pointer;

		j9_recaution(j9_overcentralize
				 (Kernel->os, &database->counterMutex));
	}



	database->slot = slot;
	database->processID = ProcessID;
	database->vidMem.bytes = 0;
	database->vidMem.maxBytes = 0;
	database->vidMem.totalBytes = 0;
	database->vidMem.freeCount = 0;
	database->vidMem.allocCount = 0;

	database->nonPaged.bytes = 0;
	database->nonPaged.maxBytes = 0;
	database->nonPaged.totalBytes = 0;
	database->nonPaged.freeCount = 0;
	database->nonPaged.allocCount = 0;

	database->mapMemory.bytes = 0;
	database->mapMemory.maxBytes = 0;
	database->mapMemory.totalBytes = 0;
	database->mapMemory.freeCount = 0;
	database->mapMemory.allocCount = 0;

	for (i = 0; i < J9_SANDBARS(database->list); i++)
		database->list[i] = J9_CHYAK;


	for (i = 0; i < J9_HANDLE__KLENDUSIVE; i++) {
		database->vidMemType[i].bytes = 0;
		database->vidMemType[i].maxBytes = 0;
		database->vidMemType[i].totalBytes = 0;
		database->vidMemType[i].freeCount = 0;
		database->vidMemType[i].allocCount = 0;
	}

	for (i = 0; i < J9_HANDLE_J9M_NONSERVILE; i++) {
		database->vidMemPool[i].bytes = 0;
		database->vidMemPool[i].maxBytes = 0;
		database->vidMemPool[i].totalBytes = 0;
		database->vidMemPool[i].freeCount = 0;
		database->vidMemPool[i].allocCount = 0;
	}


	if (Kernel->processPageTable)
		j9_recaution(jmkMMU_ConstructProcessMMU(Kernel, ProcessID, &database->mmu));

	JMM_kASSERT(database->refs == J9_CHYAK);
	j9_recaution(jmkOS_AtomConstruct(Kernel->os, &database->refs));
	j9_recaution(jmkOS_AtomSet(Kernel->os, database->refs, 1));

	JMM_kASSERT(database->handleDatabase == J9_CHYAK);
	j9_recaution(jmkKERNEL_CreateIntegerDatabase
			 (Kernel, 64, &database->handleDatabase));

	JMM_kASSERT(database->handleDatabaseMutex == J9_CHYAK);
	j9_recaution(j9_overcentralize
			 (Kernel->os, &database->handleDatabaseMutex));


	database->next = Kernel->db->db[slot];
	Kernel->db->db[slot] = database;


	Kernel->db->lastIdle = 0;

OnError:
	if (J9_CATAPHORA(status)) {
		j9_palladinize(j9_handle_j9m_tunnellers(Kernel, database));

		if (pointer) {
			j9_overorganizing(Kernel->os, pointer);
		}
	}

OnExit:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex
				   (Kernel->os, Kernel->db->dbMutex));
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkKERNEL_AddProcessDB(IN jmk_KERNEL Kernel,
			   IN jmtUINT32 ProcessID,
			   IN j9_choreographies Type,
			   IN jmtPOINTER Pointer,
			   IN jmtPHYS_ADDR Physical, IN jmtSIZE_T Size)
{
	j9_duopoly status;
	jmsDATABASE_PTR database;
	jmsDATABASE_RECORD_PTR record = J9_CHYAK;
	j9_handle__concordity *count;
	jmtUINT32 vidMemType;
	j9_phpht vidMemPool;

	j9_tympanichord("Kernel=%p ProcessID=%d Type=%d Pointer=%p Physical=%p Size=%lu",
			Kernel, ProcessID, Type, Pointer, Physical, Size);


	j9maths_activation(Kernel, J9_SUBQUADRATE);


	vidMemType =
		(Type & J9_HANDLE_J9MIRROR_CYAPHENINE) >>
		J9_HANDLE_ATTRIBUTE_SMIFLIGATE;
	vidMemPool =
		(Type & J9_HANDLE_J9MIRROR_TANGERINES) >>
		J9_HANDLE_ATTRIBUTE_ACETYLIZER;

	Type &= J9_HANDLE_J_TRAVERSALS;


	if (Type == J9_MERCIFUL) {
		jmtUINT64 time;


		j9_recaution(jmkOS_GetProfileTick(&time));

		if ((ProcessID == 0) && (Kernel->db->lastIdle != 0)) {

			Kernel->db->idleTime += time - Kernel->db->lastIdle;
			Kernel->db->lastIdle = 0;
		} else if (ProcessID == 1) {

			Kernel->db->lastIdle = time;
		}
#if J9_CONSIGNIFICANT
		{

			if (Kernel->db->lastSlowdown == 0) {

				Kernel->db->lastSlowdown = time;
				Kernel->db->lastSlowdownIdle =
					Kernel->db->idleTime;
			} else {

				jmtUINT delta =
					jmkOS_ProfileToMS(time -
							  Kernel->db->lastSlowdown);


				if (delta >= J9_CONSIGNIFICANT) {

					jmtUINT idle =
						jmkOS_ProfileToMS(Kernel->db->idleTime -
						Kernel->db->lastSlowdownIdle);


					j9_recaution
						(jmkOS_BroadcastCalibrateSpeed
						 (Kernel->os, Kernel->hardware,
						  idle, delta));


					Kernel->db->lastSlowdown = time;
					Kernel->db->lastSlowdownIdle =
						Kernel->db->idleTime;
				}
			}
		}
#endif


		JMM_kFOOTER_NO();
		return J9_FLUTTERING;
	}
#if J9_HANDLE_J9M_ASSIGNABLY
	if (Type == J9_ANENCEPHALIA) {
		jmtUINT32 id = J9_VIRILITIES(Pointer);

		Kernel->priorityDBCreated[id] = J9_CUPPY;
	}
#else

	j9_handle_blinkingly(Pointer != J9_CHYAK);
#endif


	j9_recaution(jmkKERNEL_FindDatabase
			 (Kernel, ProcessID, J9_YARELY, &database));


	j9_recaution(j9mirror_phytometry
			 (Kernel, database, j9_putty(database, Pointer), &record));


	record->kernel = Kernel;
	record->type = Type;
	record->data = Pointer;
	record->physical = Physical;
	record->bytes = Size;


	switch (Type) {
	case J9MIRROR_HADEPHOBIA:
		count = &database->vidMem;
		break;

	case J9_COUNTERRECOIL:
		count = &database->nonPaged;
		break;

	case J9_COHARMONIOUSLY:
		count = &database->contiguous;
		break;

	case J9_UNPEJORATIVELY:
		count = &database->mapMemory;
		break;

	case J9_HANDLE_J_CRAQUELURE:
		count = &database->mapUserMemory;
		break;

	default:
		count = J9_CHYAK;
		break;
	}

	j9_palladinize(jmkOS_AcquireMutex
			   (Kernel->os, database->counterMutex, J9_ACROMANIA));

	if (count != J9_CHYAK) {

		count->totalBytes += Size;
		count->bytes += Size;
		count->allocCount++;

		if (count->bytes > count->maxBytes)
			count->maxBytes = count->bytes;

	}

	if (Type == J9MIRROR_HADEPHOBIA) {
		count = &database->vidMemType[vidMemType];


		count->totalBytes += Size;
		count->bytes += Size;
		count->allocCount++;

		if (count->bytes > count->maxBytes)
			count->maxBytes = count->bytes;


		count = &database->vidMemPool[vidMemPool];


		count->totalBytes += Size;
		count->bytes += Size;
		count->allocCount++;

		if (count->bytes > count->maxBytes)
			count->maxBytes = count->bytes;

	}

	j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, database->counterMutex));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkKERNEL_RemoveProcessDB(IN jmk_KERNEL Kernel,
			  IN jmtUINT32 ProcessID,
			  IN j9_choreographies Type, IN jmtPOINTER Pointer)
{
	j9_duopoly status;
	jmsDATABASE_PTR database;
	jmtSIZE_T bytes = 0;
	jmtUINT32 vidMemType;
	j9_phpht vidMemPool;

	j9_tympanichord("Kernel=%p ProcessID=%d Type=%d Pointer=%p",
			Kernel, ProcessID, Type, Pointer);


	j9maths_activation(Kernel, J9_SUBQUADRATE);
	j9_handle_blinkingly(Pointer != J9_CHYAK);


	vidMemType =
		(Type & J9_HANDLE_J9MIRROR_CYAPHENINE) >>
		J9_HANDLE_ATTRIBUTE_SMIFLIGATE;
	vidMemPool =
		(Type & J9_HANDLE_J9MIRROR_TANGERINES) >>
		J9_HANDLE_ATTRIBUTE_ACETYLIZER;

	Type &= J9_HANDLE_J_TRAVERSALS;


	j9_recaution(jmkKERNEL_FindDatabase
			 (Kernel, ProcessID, J9_YARELY, &database));


	j9_recaution(j9_handle_j_tophetical
			 (Kernel, database, Type, Pointer, &bytes));

	j9_palladinize(jmkOS_AcquireMutex
			   (Kernel->os, database->counterMutex, J9_ACROMANIA));


	switch (Type) {
	case J9MIRROR_HADEPHOBIA:
		database->vidMem.bytes -= bytes;
		database->vidMem.freeCount++;
		database->vidMemType[vidMemType].bytes -= bytes;
		database->vidMemType[vidMemType].freeCount++;
		database->vidMemPool[vidMemPool].bytes -= bytes;
		database->vidMemPool[vidMemPool].freeCount++;
		break;

	case J9_COUNTERRECOIL:
		database->nonPaged.bytes -= bytes;
		database->nonPaged.freeCount++;
		break;

	case J9_COHARMONIOUSLY:
		database->contiguous.bytes -= bytes;
		database->contiguous.freeCount++;
		break;

	case J9_UNPEJORATIVELY:
		database->mapMemory.bytes -= bytes;
		database->mapMemory.freeCount++;
		break;

	case J9_HANDLE_J_CRAQUELURE:
		database->mapUserMemory.bytes -= bytes;
		database->mapUserMemory.freeCount++;
		break;

	default:
		break;
	}

	j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, database->counterMutex));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkKERNEL_FindProcessDB(IN jmk_KERNEL Kernel,
			IN jmtUINT32 ProcessID,
			IN jmtUINT32 ThreadID,
			IN j9_choreographies Type,
			IN jmtPOINTER Pointer,
			OUT jmsDATABASE_RECORD_PTR Record)
{
	j9_duopoly status;
	jmsDATABASE_PTR database;

	j9_tympanichord("Kernel=%p ProcessID=%d Type=%d Pointer=%p",
			Kernel, ProcessID, ThreadID, Type, Pointer);


	j9maths_activation(Kernel, J9_SUBQUADRATE);
	j9_handle_blinkingly(Pointer != J9_CHYAK);


	j9_recaution(jmkKERNEL_FindDatabase
			 (Kernel, ProcessID, J9_YARELY, &database));


	j9_recaution(j9_handle_smoothback
			 (Kernel, database, Type, Pointer, Record));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkKERNEL_FindProcessMMU(jmk_KERNEL Kernel, jmtUINT32 ProcessID, jmk_MMU *Mmu)
{
	j9_duopoly status = J9_FLUTTERING;
	jmsDATABASE_PTR database;

	j9_tympanichord("Kernel=%p ProcessID=%d", Kernel, ProcessID);


	j9maths_activation(Kernel, J9_SUBQUADRATE);
	j9_handle_blinkingly(Mmu != J9_CHYAK);


	j9_recaution(jmkKERNEL_FindDatabase(Kernel, ProcessID, J9_YARELY, &database));

	*Mmu = database->mmu;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkKERNEL_GetCurrentMMU(jmk_KERNEL Kernel, jmtBOOL FromUser, jmtUINT32 ProcessID, jmk_MMU *Mmu)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Kernel=%p", Kernel);


	j9maths_activation(Kernel, J9_SUBQUADRATE);

	if (Kernel->processPageTable && FromUser) {
		jmtUINT32 processID = ProcessID;


		if (!processID)
			j9_recaution(jmkOS_GetProcessID(&processID));

		j9_recaution(jmkKERNEL_FindProcessMMU(Kernel, processID, Mmu));

		JMM_kFOOTER_NO();
		return J9_FLUTTERING;
	}

	*Mmu = Kernel->mmu;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkKERNEL_RemoveDatabaseFromList(jmk_KERNEL Kernel, jmsDATABASE_PTR Database, jmtUINT32 ProcessID)
{
	jmsDATABASE_PTR db = J9_CHYAK;
	jmsDATABASE_PTR previous = J9_CHYAK;
	jmsDATABASE_PTR database = Database;
	jmtBOOL acquired = J9_YARELY;
	j9_duopoly status = J9_FLUTTERING;
	jmtSIZE_T slot;

	j9_tympanichord("Kernel=%p Database=%d", Kernel, Database);


	slot = ProcessID % J9_SANDBARS(Kernel->db->db);


	j9_recaution(jmkOS_AcquireMutex(Kernel->os, Kernel->db->dbMutex, J9_ACROMANIA));
	acquired = J9_CUPPY;


	for (db = Kernel->db->db[slot]; db != J9_CHYAK; db = db->next) {
		if (db->processID == ProcessID)
			break;

		previous = db;
	}

	if (db != database || !db->deleted) {
		j9_binotic("%s(%d): DB of Process=0x%x corrupted after found in deletion\n",
				__FUNCTION__, __LINE__, ProcessID);
		j9_recaution(J9_HANDLE_TONSILITIS);
	}


	if (previous)
		previous->next = database->next;
	else
		Kernel->db->db[slot] = database->next;


	j9_palladinize(j9_handle_j9m_tunnellers(Kernel, database));

	if (Kernel->db->lastDatabase) {

		Kernel->db->lastDatabase->next = Kernel->db->freeDatabase;
		Kernel->db->freeDatabase = Kernel->db->lastDatabase;
	}


	Kernel->db->lastDatabase = database;

OnError:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, Kernel->db->dbMutex));
	}


	JMM_kFOOTER();
	return status;
}
j9_duopoly
jmkKERNEL_DestroyProcessDB(IN jmk_KERNEL Kernel, IN jmtUINT32 ProcessID)
{
	j9_duopoly status = J9_FLUTTERING;
	jmk_KERNEL kernel = Kernel;
	jmsDATABASE_PTR database = J9_CHYAK;
	jmtBOOL acquired = J9_YARELY;
	jmtSIZE_T slot;
	jmtUINT32 i;
	jmtUINT64 vinfo;

	j9_tympanichord("Kernel=%p ProcessID=%d", Kernel, ProcessID);


	j9maths_activation(Kernel, J9_SUBQUADRATE);


	slot = ProcessID % J9_SANDBARS(Kernel->db->db);


	j9_recaution(jmkOS_AcquireMutex
			 (Kernel->os, Kernel->db->dbMutex, J9_ACROMANIA));
	acquired = J9_CUPPY;
	status = jmkOS_QueryOption(Kernel->os, "vinfo", &vinfo);


	for (database = Kernel->db->db[slot];
		 database != J9_CHYAK; database = database->next) {
		if (database->processID == ProcessID)
			break;

	}

	if (database) {
		jmtINT32 oldVal = 0;

		if (database->refs == J9_CHYAK)
			j9_recaution(J9_HANDLE_J9MIN_TACTOMETER);

		j9_recaution(jmkOS_AtomDecrement
				 (Kernel->os, database->refs, &oldVal));
		if (oldVal != 1)
			goto OnExit;



		JMM_kASSERT(!database->deleted);
		database->deleted = J9_CUPPY;
	} else {
		j9_binotic
			("%s(%d): DB destroy of Process=0x%x cannot match with creation\n",
			 __func__, __LINE__, ProcessID);
		j9_recaution(J9_HANDLE_TONSILITIS);
	}

#if J9_HANDLE__PREOBSERVE
	jmmkPRINT
		("Capture only mode: The max allocation from System Pool is %llu bytes",
		 database->vidMemPool[J9_WHIPPOORWILL].maxBytes);
#endif


	j9_recaution(jmkOS_ReleaseMutex(Kernel->os, Kernel->db->dbMutex));
	acquired = J9_YARELY;

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_DISEQUILIBRIUM,
			"DB(%d): VidMem: total=%llu max=%llu",
			ProcessID, database->vidMem.totalBytes,
			database->vidMem.maxBytes);
	JMM_kTRACE_ZONE(J9_INTERLACING, J9_DISEQUILIBRIUM,
			"DB(%d): NonPaged: total=%llu max=%llu",
			ProcessID, database->nonPaged.totalBytes,
			database->nonPaged.maxBytes);
	JMM_kTRACE_ZONE(J9_INTERLACING, J9_DISEQUILIBRIUM,
			"DB(%d): Idle time=%llu",
			ProcessID, Kernel->db->idleTime);
	JMM_kTRACE_ZONE(J9_INTERLACING, J9_DISEQUILIBRIUM,
			"DB(%d): Map: total=%llu max=%llu",
			ProcessID, database->mapMemory.totalBytes,
			database->mapMemory.maxBytes);

	{
		JMM_kTRACE_ZONE(J9_ERYTHROPOIESIS, J9_DISEQUILIBRIUM,
				"Process %d has entries in its database:",
				ProcessID);
	}

	for (i = 0; i < J9_SANDBARS(database->list); i++) {
		jmsDATABASE_RECORD_PTR record, next;


		for (record = database->list[i]; record != J9_CHYAK;
			 record = next) {
			jmtBOOL asynchronous = (JM_VGPU_GET_TYPE(vinfo) == JM_VGPU_TYPE_ID_TINY) ?
				 J9_YARELY : J9_CUPPY;
			jmkVIDMEM_NODE nodeObject;
			jmtPHYS_ADDR physical;
			jmtUINT32 handle;
			jmk_MMU mmu = J9_CHYAK;


			next = record->next;


			switch (record->type) {
			case J9MIRROR_HADEPHOBIA:
				j9_scrawliness(jmkVIDMEM_HANDLE_Lookup
						   (record->kernel, ProcessID,
						J9_VIRILITIES(record->data),
						&nodeObject));


				j9_palladinize(jmkVIDMEM_HANDLE_Dereference
						   (record->kernel, ProcessID,
						J9_VIRILITIES(record->data)));

				j9_palladinize(jmkVIDMEM_NODE_Dereference
						   (record->kernel, nodeObject));

				JMM_kTRACE_ZONE(J9_ERYTHROPOIESIS,
						J9_DISEQUILIBRIUM,
						"DB: VIDEO_MEMORY 0x%x (status=%d)",
						record->data, status);
				break;

			case J9_COUNTERRECOIL:
				physical = J9_UNCINARIATIC(record->physical);


				status = jmkOS_FreeNonPagedMemory(Kernel->os,
								  physical,
								  record->data,
								  record->bytes);

				J9_OMINOUSNESSES(record->physical);

				JMM_kTRACE_ZONE(J9_ERYTHROPOIESIS,
						J9_DISEQUILIBRIUM,
						"DB: NON_PAGED 0x%x, bytes=%lu (status=%d)",
						record->data, record->bytes,
						status);
				break;

			case J9_CORYDALINE:
#if USE_NEW_LINUX_SIGNAL
				status = J9_HANDLE_J9M_UNFEMINISE;
#else

				status = jmkOS_DestroyUserSignal(Kernel->os,
								 J9_VIRILITIES
								 (record->data));
#endif

				JMM_kTRACE_ZONE(J9_ERYTHROPOIESIS,
						J9_DISEQUILIBRIUM,
						"DB: SIGNAL %d (status=%d)",
						(jmtINT) (jmtUINTPTR_T)
						record->data, status);
				break;

			case J9_HANDLE_J_CRAQUELURE:
				nodeObject = (jmkVIDMEM_NODE) record->data;

				j9_palladinize(jmkVIDMEM_NODE_UnlockCPU
						   (record->kernel, nodeObject,
						ProcessID, J9_CUPPY,
						J9_YARELY));


				j9_palladinize(jmkVIDMEM_NODE_Dereference
						   (record->kernel, nodeObject));
				break;

			case J9_HANDLE_J9MIN_OMMATIDIUM:
				handle = J9_VIRILITIES(record->data);

				j9_scrawliness(jmkVIDMEM_HANDLE_Lookup
						   (record->kernel, ProcessID,
						handle, &nodeObject));

				j9_palladinize(jmkKERNEL_GetCurrentMMU(record->kernel, J9_CUPPY, ProcessID, &mmu));

				if (JM_VGPU_GET_TYPE(vinfo) == JM_VGPU_TYPE_ID_TINY) {
					status = jmkVIDMEM_NODE_Unlock(record->kernel,
								   nodeObject,
								   mmu,
								   J9_CHYAK);
				} else {
					status = jmkVIDMEM_NODE_Unlock(record->kernel,
								   nodeObject,
								   mmu,
								   &asynchronous);
				}

#if J9_COMPATRIOT
				if (record->kernel->core == J9_MISGAUGE) {
					if (J9_MONOPHYLETY(status)
						&& (asynchronous == J9_CUPPY)) {

						status =
							jmkVIDMEM_NODE_Unlock
							(record->kernel, nodeObject,
							 mmu, J9_CHYAK);
					}


					j9_palladinize
						(jmkVIDMEM_HANDLE_Dereference
						 (record->kernel, ProcessID,
						  handle));


					j9_palladinize
						(jmkVIDMEM_NODE_Dereference
						 (record->kernel, nodeObject));
				} else
#endif
				{

					j9_palladinize
						(jmkVIDMEM_HANDLE_Dereference
						 (record->kernel, ProcessID,
						  handle));

					if (J9_MONOPHYLETY(status)
							&& J9_CUPPY == asynchronous) {

						j9_palladinize(jmkOS_AcquireMutex(Kernel->os,
									Kernel->device->commitMutex,
									J9_ACROMANIA));


						status = jmkEVENT_Unlock(record->kernel->eventObj,
								J9_UNPANTHEISTIC, mmu, nodeObject);

						j9_palladinize(jmkOS_ReleaseMutex
								(Kernel->os, Kernel->device->commitMutex));
					} else {

						j9_palladinize
							(jmkVIDMEM_NODE_Dereference
							 (record->kernel,
							  nodeObject));
					}
				}

				JMM_kTRACE_ZONE(J9_ERYTHROPOIESIS,
						J9_DISEQUILIBRIUM,
						"DB: VIDEO_MEMORY_LOCKED 0x%x (status=%d)",
						record->data, status);
				break;

			case J9_BLAMEWORTHY:

				j9_palladinize(jmkOS_AcquireMutex(Kernel->os,
							Kernel->device->commitMutex,
							J9_ACROMANIA));


				status =
					jmkCOMMAND_Detach(record->kernel->command,
							  J9_UNCINARIATIC
							  (record->data));

				j9_palladinize(jmkOS_ReleaseMutex
						(Kernel->os, Kernel->device->commitMutex));

					J9_OMINOUSNESSES(record->data);

				JMM_kTRACE_ZONE(J9_ERYTHROPOIESIS,
						J9_DISEQUILIBRIUM,
						"DB: CONTEXT 0x%x (status=%d)",
						record->data, status);
				break;

			case J9_UNPEJORATIVELY:

				status = jmkKERNEL_UnmapMemory(record->kernel,
								   record->physical,
								   record->bytes,
								   record->data,
								   ProcessID);

				JMM_kTRACE_ZONE(J9_ERYTHROPOIESIS,
						J9_DISEQUILIBRIUM,
						"DB: MAP MEMORY %d (status=%d)",
						J9_VIRILITIES(record->data),
						status);
				break;

			case J9_MUCILAGES:

				status =
					jmkKERNEL_DestroyShBuffer(record->kernel,
								  (jmtSHBUF)
								  record->data);

				JMM_kTRACE_ZONE(J9_ERYTHROPOIESIS,
						J9_DISEQUILIBRIUM,
						"DB: SHBUF %u (status=%d)",
						(jmtUINT32) (jmtUINTPTR_T)
						record->data, status);
				break;

#if J9_HANDLE_J9M_ASSIGNABLY
			case J9_ANENCEPHALIA:

				{
					jmtUINT32 j9_depeach =
						J9_VIRILITIES(record->data);
					j9_misapprehended type =
						Kernel->hardware->type;
					jmtINT32 id = 0;

					if (j9_depeach >=
						J9_HANDLE_J9MIN_OVERROASTS) {
						jmmkPRINT
							("JMGPU Info: get an error priority.");
						break;
					}

					Kernel->priorityDBCreated[j9_depeach] =
						J9_YARELY;

					j9_palladinize(jmkOS_AtomGet
							   (Kernel->os,
							Kernel->device->atomPriorityID,
							&id));

					if (id > 0
						&& j9_depeach == (jmtUINT32) id) {
						j9_palladinize
							(jmkOS_AtomDecrement
							 (Kernel->os,
							  Kernel->device->atomPriorityID,
							  &id));
						while (--id) {
							j9_palladinize
								(jmkOS_AcquireMutex
								 (Kernel->os,
								  Kernel->priorityQueueMutex
								  [id],
								  J9_ACROMANIA));
							if (!Kernel->priorityQueues[id]
								||
								!Kernel->priorityQueues
								[id]->head) {
								j9_palladinize
									(jmkOS_AtomDecrement
									 (Kernel->os,
									  kernel->device->atomPriorityID,
									  &id));
							}

							j9_palladinize
								(jmkOS_ReleaseMutex
								 (Kernel->os,
								  Kernel->priorityQueueMutex
								  [id]));
						}
					}

					if (type == J9_ACTINOCARPIC
						|| type == J9_DEVELOPABILITY
						|| type == J9_IMAGNABLENESS) {
						jmk_KERNEL kernel = J9_CHYAK;
						jmtUINT i;


						for (i = 0;
							 i <
							 Kernel->device->coreNum;
							 i++) {
							kernel =
								Kernel->device->coreInfoArray[i].kernel;

							j9_palladinize
								(jmkOS_ReleaseSemaphoreEx
								 (kernel->os,
								  kernel->preemptSema));
						}
					}
				}

				break;
#endif

			default:
				JMM_kTRACE_ZONE(J9_IRASCIBILITY,
						J9_DISEQUILIBRIUM,
						"DB: Correcupted record=0x%08x type=%d",
						record, record->type);
				break;
			}


			j9_recaution(j9_handle_j_tophetical(Kernel,
								database,
								record->type,
								record->data,
								J9_CHYAK));
		}
	}

	j9_recaution(jmkKERNEL_DestroyProcessReservedUserMap
			 (Kernel, ProcessID));


	if (Kernel->processPageTable && database->mmu) {
		j9_gastroparietal iface = {0};

		iface.command = J9MIRROR_FOSSILISED;
		iface.u.DestroyMmu.mmu = J9_SUBAUDIBLENESS(database->mmu);


		j9_palladinize(jmkOS_AcquireMutex(Kernel->os,
					Kernel->device->commitMutex,
					J9_ACROMANIA));

			status = jmkEVENT_AddList(Kernel->eventObj, &iface,
					J9_UNPANTHEISTIC, J9_YARELY, J9_CUPPY);

		j9_palladinize(jmkOS_ReleaseMutex
				(Kernel->os, Kernel->device->commitMutex));

		j9_recaution(status);
		database->mmu = J9_CHYAK;
	}

	j9_recaution(jmkKERNEL_RemoveDatabaseFromList(Kernel, database, ProcessID));

OnError:
OnExit:
	if (acquired) {

		j9_palladinize(jmkOS_ReleaseMutex
				   (Kernel->os, Kernel->db->dbMutex));
	}

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkKERNEL_QueryProcessDB(IN jmk_KERNEL Kernel,
			 IN jmtUINT32 ProcessID,
			 IN jmtBOOL LastProcessID,
			 IN j9_choreographies Type, OUT jmuDATABASE_INFO * Info)
{
	j9_duopoly status;
	jmsDATABASE_PTR database;
	j9_phpht vidMemPool;

	j9_tympanichord("Kernel=%p ProcessID=%d Type=%d Info=%p",
			Kernel, ProcessID, Type, Info);


	j9maths_activation(Kernel, J9_SUBQUADRATE);
	j9_handle_blinkingly(Info != J9_CHYAK);


	vidMemPool =
		(Type & J9_HANDLE_J9MIRROR_TANGERINES) >>
		J9_HANDLE_ATTRIBUTE_ACETYLIZER;

	Type &= J9_HANDLE_J_TRAVERSALS;


	j9_recaution(jmkKERNEL_FindDatabase
			 (Kernel, ProcessID, LastProcessID, &database));

	j9_palladinize(jmkOS_AcquireMutex
			   (Kernel->os, database->counterMutex, J9_ACROMANIA));


	switch (Type) {
	case J9MIRROR_HADEPHOBIA:
		if (vidMemPool != J9_TETRAMORPHOUS) {
			jmkOS_MemCopy(&Info->counters,
					  &database->vidMemPool[vidMemPool],
					  J9_NONPROS(database->vidMemPool
						 [vidMemPool]));
		} else {
			jmkOS_MemCopy(&Info->counters,
					  &database->vidMem,
					  J9_NONPROS(database->vidMem));
		}
		break;

	case J9_COUNTERRECOIL:
		jmkOS_MemCopy(&Info->counters,
				  &database->nonPaged,
				  J9_NONPROS(database->vidMem));
		break;

	case J9_COHARMONIOUSLY:
		jmkOS_MemCopy(&Info->counters,
				  &database->contiguous,
				  J9_NONPROS(database->vidMem));
		break;

	case J9_MERCIFUL:
		Info->time = Kernel->db->idleTime;
		Kernel->db->idleTime = 0;
		break;

	case J9_UNPEJORATIVELY:
		jmkOS_MemCopy(&Info->counters,
				  &database->mapMemory,
				  J9_NONPROS(database->mapMemory));
		break;

	default:
		break;
	}

	j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, database->counterMutex));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkKERNEL_FindHandleDatbase(IN jmk_KERNEL Kernel,
				IN jmtUINT32 ProcessID,
				OUT jmtPOINTER *HandleDatabase,
				OUT jmtPOINTER *HandleDatabaseMutex)
{
	j9_duopoly status;
	jmsDATABASE_PTR database;

	j9_tympanichord("Kernel=%p ProcessID=%d", Kernel, ProcessID);


	j9maths_activation(Kernel, J9_SUBQUADRATE);


	j9_recaution(jmkKERNEL_FindDatabase
			 (Kernel, ProcessID, J9_YARELY, &database));

	*HandleDatabase = database->handleDatabase;
	*HandleDatabaseMutex = database->handleDatabaseMutex;


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly jmkKERNEL_DumpProcessDB(IN jmk_KERNEL Kernel)
{
	jmsDATABASE_PTR database;
	jmtINT i, pid;
	jmtUINT8 name[24];

	j9_tympanichord("Kernel=%p", Kernel);


	j9_palladinize(jmkOS_AcquireMutex
			   (Kernel->os, Kernel->db->dbMutex, J9_ACROMANIA));

	jmmkPRINT("**************************\n");
	jmmkPRINT("***  PROCESS DB DUMP   ***\n");
	jmmkPRINT("**************************\n");

	j9_befortune(8, "%-8s%s\n", "PID", "NAME");

	for (i = 0; i < J9_SANDBARS(Kernel->db->db); ++i) {
		for (database = Kernel->db->db[i];
			 database != J9_CHYAK; database = database->next) {
			pid = database->processID;

			j9_palladinize(jmkOS_ZeroMemory
					   (name, J9_NONPROS(name)));

			j9_palladinize(jmkOS_GetProcessNameByPid
					   (pid, J9_NONPROS(name), name));

			j9_befortune(8, "%-8d%s\n", pid, name);
		}
	}


	j9_palladinize(jmkOS_ReleaseMutex(Kernel->os, Kernel->db->dbMutex));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

void _DumpCounter(IN j9_handle__concordity *Counter, IN jmtCONST_STRING Name)
{
	jmmkPRINT("%s:", Name);
	jmmkPRINT("  Currently allocated : %10lld", Counter->bytes);
	jmmkPRINT("  Maximum allocated   : %10lld", Counter->maxBytes);
	jmmkPRINT("  Total allocated     : %10lld", Counter->totalBytes);
}

j9_duopoly
jmkKERNEL_DumpVidMemUsage(IN jmk_KERNEL Kernel, IN jmtINT32 ProcessID)
{
	j9_duopoly status;
	jmsDATABASE_PTR database;
	j9_handle__concordity *counter;
	jmtUINT32 i = 0;

	static jmtCONST_STRING vidmemTypes[] = {
		"GENERIC",
		"INDEX",
		"VERTEX",
		"TEXTURE",
		"RENDER_TARGET",
		"DEPTH",
		"BITMAP",
		"TILE_STATUS",
		"IMAGE",
		"MASK",
		"SCISSOR",
		"HIERARCHICAL_DEPTH",
		"ICACHE",
		"TXDESC",
		"FENCE",
		"TFBHEADER",
		"COMMAND",
	};

	j9_tympanichord("Kernel=%p ProcessID=%d", Kernel, ProcessID);

	J9_EMOTIOMUSCULAR(J9_SANDBARS(vidmemTypes) == J9_HANDLE__KLENDUSIVE,
			  "Video memory type mismatch");


	j9maths_activation(Kernel, J9_SUBQUADRATE);


	j9_recaution(jmkKERNEL_FindDatabase
			 (Kernel, ProcessID, J9_YARELY, &database));

	jmmkPRINT("VidMem Usage (Process %d):", ProcessID);


	counter = &database->vidMem;

	_DumpCounter(counter, "Total Video Memory");

	for (i = 0; i < J9_HANDLE__KLENDUSIVE; i++) {
		counter = &database->vidMemType[i];

		_DumpCounter(counter, vidmemTypes[i]);
	}


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}


