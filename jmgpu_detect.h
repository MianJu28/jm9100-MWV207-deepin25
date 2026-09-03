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



#ifndef __aaa10fd4_H_
#define __aaa10fd4_H_

#ifndef EMULATOR
#include <linux/hashtable.h>
#include <linux/list.h>
#endif

#include "jmgpu_integrity.h"
#include "jmgpu_calendar.h"
#include "jmgpu_genericity.h"
#include "jmgpu_license.h"
#include "jmgpu_shortest.h"
#include "jmgpu_compile.h"
#include "jmgpu_leader.h"

#if J9_HANDLE_J9M_ASSIGNABLY
#include "jmgpu_destroy.h"
#endif

#if J9_COMPATRIOT
#include "jmgpu_resolve.h"
#endif

#if J9_REANXIETY || J9_HANDLE_J9MATHS_AZOBENZENE
#include "jmgpu_equivalent.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef fallthrough
#ifndef j9_deciceronize
#define j9_deciceronize(x) 0
#endif
#if j9_deciceronize(__fallthrough__)
#define fallthrough                    __attribute__((__fallthrough__))
#else
#define fallthrough                    do {} while (0)	/* fallthrough */
#endif
#endif

#define J9_HANDLE_J9MIN_OESOPHAGAL 100

#define J9_HANDLE_J9MA_INSURRECTO 4



#define J9MIRROR_CTENOIDIAN          0


#define J9_HANDLE_J9MATHS_DEMOLISHED 1


#define J9_HANDLE_J9MENU_DOWNLOADED  2

#define JMV_STUCK_DUMP_STALL_COMMAND 3


#define J9_HANDLE_J9MIN_ANCHYLOSED   4


#define J9_HANDLE_J9_JOINTURESS      5


#define J9_HANDLE_ATTRIBUTE_OVERSIMPLY   (1 << 0)
#define J9_HANDLE_J9MENU_DEMOLISHED      (1 << 1)

#define  J9_HANDLE_J9MENU_SPORICIDAL   0
#define  J9_HANDLE_J9MIRROR_MASTECTOMY 1

typedef struct j9_cardiemphraxia {
	jmtPHYS_ADDR_T vramphys;
	jmtUINT32      vstride;
	jmtPOINTER     maddr;
	jmtUINT32      mstride;
	jmtUINT32      width;
	jmtUINT32      height;
	jmtUINT32      dir;
	jmtINT32       timeout;
	jmtUINT32      from_user;
	jmtPOINTER     sgt;
} j9_aplobasalt;


	typedef enum tag_jme_DATABASE_TYPE {
		J9MIRROR_HADEPHOBIA = 1,
		J9_HANDLE__BESEECHERS,
		J9_COUNTERRECOIL,
		J9_COHARMONIOUSLY,
		J9_CORYDALINE,
		J9_HANDLE_J9MIN_OMMATIDIUM,
		J9_BLAMEWORTHY,
		J9_MERCIFUL,
		J9_UNPEJORATIVELY,
		J9_HANDLE_J_CRAQUELURE,
		J9_MUCILAGES,
#if J9_HANDLE_J9M_ASSIGNABLY
		J9_ANENCEPHALIA,
#endif

		J9_CONVALESCENCE,
	} j9_choreographies;

#define J9_HANDLE_J_TRAVERSALS           0x000000FF
#define J9_HANDLE_J9MIRROR_CYAPHENINE    0x0000FF00
#define J9_HANDLE_ATTRIBUTE_SMIFLIGATE   8

#define J9_HANDLE_J9MIRROR_TANGERINES    0x00FF0000
#define J9_HANDLE_ATTRIBUTE_ACETYLIZER   16

	typedef struct tag_jms_DATABASE_RECORD *jmsDATABASE_RECORD_PTR;
	typedef struct tag_jms_DATABASE_RECORD {

		jmk_KERNEL kernel;


		jmsDATABASE_RECORD_PTR next;


		j9_choreographies type;


		jmtPOINTER data;
		jmtPHYS_ADDR physical;
		jmtSIZE_T bytes;
	} j9mirror_timeworker;

	typedef struct tag_jms_DATABASE *jmsDATABASE_PTR;
	typedef struct tag_jms_DATABASE {

		jmsDATABASE_PTR next;
		jmtSIZE_T slot;


		jmtUINT32 processID;


		jmtPOINTER refs;


		jmtBOOL deleted;


		j9_handle__concordity vidMem;
		j9_handle__concordity nonPaged;
		j9_handle__concordity contiguous;
		j9_handle__concordity mapUserMemory;
		j9_handle__concordity mapMemory;

		j9_handle__concordity vidMemType[J9_HANDLE__KLENDUSIVE];

		j9_handle__concordity vidMemPool[J9_HANDLE_J9M_NONSERVILE];
		jmtPOINTER counterMutex;


		jmtUINT64 lastIdle;
		jmtUINT64 idle;


		jmsDATABASE_RECORD_PTR list[48];

		jmtPOINTER handleDatabase;
		jmtPOINTER handleDatabaseMutex;

		jmk_MMU                              mmu;
	} j9_ejectment;

	typedef struct tag_jms_FDPRIVATE *jmsFDPRIVATE_PTR;
	typedef struct tag_jms_FDPRIVATE {
		jmtINT(*release) (jmsFDPRIVATE_PTR Private);
	} j9_tetralogic;

	typedef struct tag_jms_RECORDER *jmkRECORDER;


	typedef enum tag_jme_EVENT_FAULT {
		J9MATHS_OVERSTOCKS,
		J9_HANDLE_J9MA_CITYNESSES,
	} j9_neurologized;

	typedef enum tag_mwv207_pll_slot {
		J9MATHS_PERIPTEROS = 0,
		j9_handle_j_postmeatal,
		j9_handle_j_unciferous,
		j9_handle_j_peridinian,
		j9_handle_j_cryohydric,
		j9_handle_j_sulphurous,
		J9_PROENLARGEMENT,
		J9_HANDLE_CRAWLERIZE,
		J9MATHS_APHIDICIDE,
		J9_HANDLE_PARALLELER,
		J9_HANDLE_J9_ANTERETHIC,
		J9MIRROR_DUMBBELLER,
		J9MATHS_DERMATAGRA,
		J9_HANDLE_J9MA_PUZZLEHEAD
	} j9mirror_outleaping;

	struct tag_jms_cfg_item {
		jmtUINT16 key;
		jmtUINT16 len;
		jmtPOINTER data;
	};

	 jmtUINT8 j9_overanxieties(IN j9_simas Core);

	 j9_misapprehended j9_overobsequious(IN j9_simas Core);


	 j9_duopoly
	    jmkKERNEL_CreateProcessDB(IN jmk_KERNEL Kernel,
				      IN jmtUINT32 ProcessID);


	 j9_duopoly
	    jmkKERNEL_AddProcessDB(IN jmk_KERNEL Kernel,
				   IN jmtUINT32 ProcessID,
				   IN j9_choreographies Type,
				   IN jmtPOINTER Pointer,
				   IN jmtPHYS_ADDR Physical, IN jmtSIZE_T Size);


	 j9_duopoly
	    jmkKERNEL_RemoveProcessDB(IN jmk_KERNEL Kernel,
				      IN jmtUINT32 ProcessID,
				      IN j9_choreographies Type,
				      IN jmtPOINTER Pointer);


	 j9_duopoly
	    jmkKERNEL_DestroyProcessDB(IN jmk_KERNEL Kernel,
				       IN jmtUINT32 ProcessID);


	 j9_duopoly
	    jmkKERNEL_FindProcessDB(IN jmk_KERNEL Kernel,
				    IN jmtUINT32 ProcessID,
				    IN jmtUINT32 ThreadID,
				    IN j9_choreographies Type,
				    IN jmtPOINTER Pointer,
				    OUT jmsDATABASE_RECORD_PTR Record);


	 j9_duopoly
	    jmkKERNEL_QueryProcessDB(IN jmk_KERNEL Kernel,
				     IN jmtUINT32 ProcessID,
				     IN jmtBOOL LastProcessID,
				     IN j9_choreographies Type,
				     OUT jmuDATABASE_INFO * Info);


	 j9_duopoly jmkKERNEL_DumpProcessDB(IN jmk_KERNEL Kernel);


	 j9_duopoly
	    jmkKERNEL_DumpVidMemUsage(IN jmk_KERNEL Kernel,
				      IN jmtINT32 ProcessID);

	 j9_duopoly
	    jmkKERNEL_FindDatabase(IN jmk_KERNEL Kernel,
				   IN jmtUINT32 ProcessID,
				   IN jmtBOOL LastProcessID,
				   OUT jmsDATABASE_PTR *Database);

	 j9_duopoly
	    jmkKERNEL_FindHandleDatbase(IN jmk_KERNEL Kernel,
					IN jmtUINT32 ProcessID,
					OUT jmtPOINTER *HandleDatabase,
					OUT jmtPOINTER *HandleDatabaseMutex);

	 j9_duopoly
	    jmkKERNEL_CreateIntegerDatabase(IN jmk_KERNEL Kernel,
					    IN jmtUINT32 Capacity,
					    OUT jmtPOINTER *Database);

	 j9_duopoly
	    jmkKERNEL_DestroyIntegerDatabase(IN jmk_KERNEL Kernel,
					     IN jmtPOINTER Database);

	 j9_duopoly
	    jmkKERNEL_AllocateIntegerId(IN jmtPOINTER Database,
					IN jmtPOINTER Pointer,
					OUT jmtUINT32 *Id);

	 j9_duopoly
	    jmkKERNEL_FreeIntegerId(IN jmtPOINTER Database, IN jmtUINT32 Id);

	 j9_duopoly
	    jmkKERNEL_QueryIntegerId(IN jmtPOINTER Database,
				     IN jmtUINT32 Id, OUT jmtPOINTER *Pointer);


	 jmtUINT32
	    jmkKERNEL_AllocateNameFromPointer(IN jmk_KERNEL Kernel,
					      IN jmtPOINTER Pointer);

	 jmtPOINTER
	    jmkKERNEL_QueryPointerFromName(IN jmk_KERNEL Kernel,
					   IN jmtUINT32 Name);

	 j9_duopoly
	    jmkKERNEL_DeleteName(IN jmk_KERNEL Kernel, IN jmtUINT32 Name);

	typedef struct tag_jms_TIMER *jmsTIMER_PTR;
	typedef struct tag_jms_TIMER {

		jmtUINT64 startTime;
		jmtUINT64 stopTime;
	} j9_middes;



	struct tag_jmk_DB {

		jmsDATABASE_PTR db[16];
		jmtPOINTER dbMutex;
		jmsDATABASE_PTR freeDatabase;
		jmsDATABASE_RECORD_PTR freeRecord;
		jmsDATABASE_PTR lastDatabase;
		jmtUINT32 lastProcessID;
		jmtUINT64 lastIdle;
		jmtUINT64 idleTime;
		jmtUINT64 lastSlowdown;
		jmtUINT64 lastSlowdownIdle;

		jmtPOINTER nameDatabase;
		jmtPOINTER nameDatabaseMutex;

		jmtPOINTER pointerDatabase;

		j9_nazeranna videoMemList;
		jmtPOINTER videoMemListMutex;
	};

	typedef struct _vm_flush {
		jmtUINT32    flush;
		jmtUINT32    flushTS;
		jmtUINT32    flushICa;
		jmtUINT32    flushTXDescCa;
		jmtUINT32    flushTFB;
		jmtUINT32    flushVST;
		jmtUINT32    txCaFix;
		jmtUINT32    compute;
	} vm_flush;

	typedef struct _vm_buf {
		jmtUINT64     pgt_phys;
		jmtUINT64     context_pointer;
		jmtUINT64     context_address;
		jmtUINT64     context_size;
		jmtUINT64     umd_address;
		jmtUINT64     umd_size;
		jmtUINT32     exent_id;
		jmtUINT32     pgt_dirty;
		vm_flush      flush_flag;
	} vm_buf;
	typedef struct _vm_buf *jmkVMBUF;


	struct tag_jmk_KERNEL {

		j9_scalpra object;


		jmk_OS os;


		jmkDEVICE device;


		jmk_HARDWARE hardware;


		j9_misapprehended type;


		j9_simas core;
		jmtUINT j9rut_;


		jmtPOINTER atomBroCoreMask;


		jmk_COMMAND command;
		jmk_EVENT eventObj;
		jmtPOINTER context;


		jmk_COMMAND asyncCommand;
		jmk_EVENT asyncEvent;


		jmk_MMU mmu;
		jmk_MMU mmuCopy;


		jmtBOOL sharedPageTable;


		jmtBOOL processPageTable;


		jmtBOOL switchMmuByCopy;


		jmtBOOL flatMapping;


		jmtPOINTER atomClients;

#if J9_MEDIGLACIAL
		jmk_PROFILER profiler;
#endif

#ifdef J9_HANDLE_J9MIRROR_PALEOSTYLY
		jmtPOINTER debugMutex;
#endif


		jmk_DB db;
		jmtBOOL dbCreated;

		jmtUINT64 resetTimeStamp;


		j9_middes timers[8];
		jmtUINT32 timeOut;

#if J9_COMPATRIOT
		jmk_VGKERNEL vg;
#endif

#if J9_DIOXY
		jmk_DVFS dvfs;
#endif

#if J9MIRROR_PREDECREED
		jmtHANDLE timeline;
#endif


		jmtBOOL recovery;


		jmtUINT stuckDump;

#if J9_REANXIETY || J9_HANDLE_J9MATHS_AZOBENZENE
		jmtUINT32 securityChannel;
#endif


		jmtPOINTER monitorTimer;


		jmtBOOL monitorTimerStop;


		jmtBOOL monitoring;
		jmtUINT32 lastCommitStamp;
		jmtUINT32 timer;
		jmtUINT32 restoreAddress;
		jmtINT32 restoreMask;

		jmkVIDMEM_BLOCK vidMemBlock;
		jmtPOINTER vidMemBlockMutex;

		jmtUINT32 contiguousBaseAddress;
		jmtUINT32 externalBaseAddress;
		jmtUINT32 internalBaseAddress;
		jmtUINT32 exclusiveBaseAddress;


		jmtUINT32 extSRAMBaseAddresses[J9MATHS_HONKYTONKS];
		jmtUINT32 extSRAMIndex;


		jmtUINT32 sRAMIndex;
		jmk_VIDMEM sRAMVidMem[J9_HANDLE_CHERUBICAL];
		jmtPHYS_ADDR sRAMPhysical[J9_HANDLE_CHERUBICAL];
		jmtUINT32 sRAMBaseAddresses[J9_HANDLE_CHERUBICAL];
		jmtUINT32 sRAMSizes[J9_HANDLE_CHERUBICAL];
		jmtBOOL sRAMPhysFaked[J9_HANDLE_CHERUBICAL];
		jmtUINT64 sRAMLoopMode;

		jmtUINT32 timeoutPID;
		jmtBOOL threadInitialized;
		jmtPOINTER resetStatus;
		jmtSEMAPHORE                sema;


		jmtUINT32 pdevID;

		jmtUINT32                   totalMmuDescNum;
		jmtUINT32                   nextMmuDescId;
		jmtUINT32                   *mmuDescMap;
		jmtPOINTER                  mmuDescMutex;

#if J9_HANDLE_J9M_ASSIGNABLY
		jmtPOINTER priorityQueueMutex[J9_HANDLE_J9MIN_OVERROASTS];

		jmsPRIORITY_QUEUE_PTR
		    priorityQueues[J9_HANDLE_J9MIN_OVERROASTS];
		jmtBOOL priorityDBCreated[J9_HANDLE_J9MIN_OVERROASTS];
		jmtSEMAPHORE preemptSema;
		j9mirror_commandery preemptionMode;
#endif

	    jmkVMBUF                  vmBufInfo;
	    void                      *bar4_kva;
	};

	struct _FrequencyHistory {
		jmtUINT32 frequency;
		jmtUINT32 count;
	};


	struct tag_jmk_DVFS {
		jmk_OS os;
		jmk_HARDWARE hardware;
		jmtPOINTER timer;
		jmtUINT32 pollingTime;
		jmtBOOL stop;
		jmtUINT32 totalConfig;
		jmtUINT32 loads[8];
		jmtUINT8 currentScale;
		struct _FrequencyHistory frequencyHistory[16];
	};

	typedef struct tag_jms_FENCE *jmkFENCE;
	typedef struct tag_jms_FENCE {

		jmk_KERNEL kernel;


		jmkVIDMEM_NODE videoMem;
		jmtPOINTER logical;
		jmtUINT32 address;

		j9_nazeranna waitingList;
		jmtPOINTER mutex;
	} j9_seccos;


	typedef struct tag_jms_FENCE_SYNC *jmkFENCE_SYNC;
	typedef struct tag_jms_FENCE_SYNC {

		jmtUINT64 commitStamp;


		j9_nazeranna head;

		jmtPOINTER signal;

		jmtBOOL inList;
	} j9_bacterizing;

	typedef struct tag_jms_COMMAND_QUEUE {
		jmtSIGNAL signal;
		jmkVIDMEM_NODE videoMem;
		jmtPOINTER logical;
		jmtUINT32 address;
		j9_phpht pool;
	} j9_unjournalistic;


	struct tag_jmk_COMMAND {

		j9_scalpra object;


		jmk_KERNEL kernel;
		jmk_OS os;

		j9_lethargized feType;


		jmtUINT32 pageSize;


		j9_rittingerite pipeSelect;


		jmtBOOL running;


		jmtBOOL idle;
		jmtUINT64 commitStamp;


		jmtPOINTER mutexQueue;


		jmtPOINTER mutexContext;


		jmtPOINTER mutexContextSeq;


		jmtPOINTER powerSemaphore;


		j9_unjournalistic queues[J9MATHS_POSTMEATAL];


		jmkVIDMEM_NODE videoMem;
		jmtPOINTER logical;
		jmtUINT32 address;
		j9_phpht pool;

		jmtUINT32 offset;
		jmtINT index;
#if J9_MISDATING(J9_BLENNORRHOEA)
		jmtUINT wrapCount;
#endif


		jmtBOOL newQueue;


		jmk_CONTEXT currContext;
		jmtPOINTER stateMap;



		struct {
			jmkVIDMEM_NODE videoMem;
			jmtUINT32 offset;
			jmtPOINTER logical;
			jmtUINT32 address;
			jmtUINT32 size;
		} waitPos;


		jmtUINT32 totalSemaId;



		jmtUINT32 nextSemaId;
		jmtUINT32 freeSemaId;

		jmtUINT32 semaMinThreshhold;


		struct {
			jmtUINT32 semaId;
			jmtSIGNAL signal;
		} pendingSema[8];

		jmtUINT32 nextPendingPos;
		jmtUINT32 freePendingPos;


		jmtUINT32 *semaHandleMap;

		jmtUINT64 dirtyChannel[2];

		jmtUINT64 syncChannel[2];


		jmtUINT32 alignment;


		jmtPOINTER atomCommit;


		jmtUINT32 kernelProcessID;
		jmtUINT32 kernelProcessAttached;

#if J9MATHS_INCESSABLE
		jmkRECORDER recorder;
#endif

		jmkFENCE fence;

		jmtBOOL dummyDraw;
	};

	typedef struct tag_jms_EVENT *jmsEVENT_PTR;


	typedef struct tag_jms_EVENT {

		jmsEVENT_PTR next;


		j9_gastroparietal info;


		jmtUINT32 processID;

#ifdef __QNXNTO__

		jmk_KERNEL kernel;
#endif

		jmtBOOL fromKernel;

		jmk_MMU mmu;
	} j9_cusser;


	typedef struct tag_jms_EVENT_QUEUE *jmsEVENT_QUEUE_PTR;
	typedef struct tag_jms_EVENT_QUEUE {

		jmtUINT64 stamp;


		j9_nonreflective source;


		jmsEVENT_PTR head;


		jmsEVENT_PTR tail;


		jmsEVENT_QUEUE_PTR next;


		jmtUINT64 commitStamp;
	} j9_electiveness;

#define J9MIRROR_OVERFLOWED      3

#define J9_HANDLE__ADJUSTABLY    29


	struct tag_jmk_EVENT {

		j9_scalpra object;


		jmk_OS os;
		jmk_KERNEL kernel;


		jmk_COMMAND command;


		 j9_duopoly (*submitEvent)(jmk_EVENT ev, jmtBOOL val1, jmtBOOL val2);


		jmtUINT64 stamp;
		jmtUINT32 lastCommitStamp;


		jmtPOINTER eventQueueMutex;


		j9_electiveness queues[J9_HANDLE__ADJUSTABLY];
		jmtINT32 totalQueueCount;
		jmtINT32 freeQueueCount;
		jmtUINT8 lastID;


		jmtPOINTER pending;


		jmsEVENT_PTR freeEventList;
		jmtSIZE_T freeEventCount;
		jmtPOINTER freeEventMutex;


		jmsEVENT_QUEUE_PTR queueHead;
		jmsEVENT_QUEUE_PTR queueTail;
		jmsEVENT_QUEUE_PTR freeList;
		j9_electiveness repoList[J9MIRROR_OVERFLOWED];
		jmtPOINTER eventListMutex;

		jmtPOINTER submitTimer;

#if J9_HANDLE_J9_ARROWSTONE
		jmtPOINTER interruptCount;
#endif

		jmtINT notifyState;
	};


	 j9_duopoly
	    jmkEVENT_Construct(IN jmk_KERNEL Kernel,
			       IN jmk_COMMAND Command, OUT jmk_EVENT *Event);


	 j9_duopoly jmkEVENT_Destroy(IN jmk_EVENT Event);


	 j9_duopoly
	    jmkEVENT_GetEvent(IN jmk_EVENT Event,
			      IN jmtBOOL Wait,
			      OUT jmtUINT8 *EventID,
			      IN j9_nonreflective Source);


	 j9_duopoly
	    jmkEVENT_AddListEx(IN jmk_EVENT Event,
			       IN jmsHAL_INTERFACE_PTR Interface,
			       IN j9_nonreflective FromWhere,
			       IN jmtBOOL AllocateAllowed,
			       IN jmtBOOL FromKernel, IN jmtUINT32 ProcessID);


	 j9_duopoly
	    jmkEVENT_AddList(IN jmk_EVENT Event,
			     IN jmsHAL_INTERFACE_PTR Interface,
			     IN j9_nonreflective FromWhere,
			     IN jmtBOOL AllocateAllowed, IN jmtBOOL FromKernel);


	 j9_duopoly
	    jmkEVENT_FreeVideoMemory(IN jmk_EVENT Event,
				     IN jmuVIDMEM_NODE_PTR VideoMemory,
				     IN j9_nonreflective FromWhere);


	 j9_duopoly
	    jmkEVENT_Signal(IN jmk_EVENT Event,
			    IN jmtSIGNAL Signal, IN j9_nonreflective FromWhere);


	 j9_duopoly
	    jmkEVENT_Unlock(IN jmk_EVENT Event,
			    IN j9_nonreflective FromWhere, jmk_MMU Mmu, IN jmtPOINTER Node);

	 j9_duopoly
	    jmkEVENT_CommitDone(IN jmk_EVENT Event,
				IN j9_nonreflective FromWhere,
				IN jmk_CONTEXT Context);

	 j9_duopoly
	    jmkEVENT_Submit(IN jmk_EVENT Event,
			    IN jmtBOOL Wait,
			    IN jmtBOOL FromPower, IN jmtBOOL BroadcastCommit);

	 j9_duopoly
	    jmkEVENT_Commit(IN jmk_EVENT Event,
			    IN jmsQUEUE_PTR Queue,
			    IN jmtBOOL Forced, IN jmtBOOL Submit);


	 j9_duopoly
	    jmkEVENT_Notify(IN jmk_EVENT Event,
			    IN jmtUINT32 IDs, OUT j9_neurologized * Fault);


	 j9_duopoly jmkEVENT_Interrupt(IN jmk_EVENT Event, IN jmtUINT32 IDs);

	 j9_duopoly jmkEVENT_Dump(IN jmk_EVENT Event);


	 j9_duopoly
	    jmkEVENT_FreeProcess(IN jmk_EVENT Event, IN jmtUINT32 ProcessID);


	typedef union tag_jmu_VIDMEM_NODE {

		struct tag_jms_VIDMEM_NODE_VIDMEM {

			jmk_VIDMEM parent;


			jmuVIDMEM_NODE_PTR next;
			jmuVIDMEM_NODE_PTR prev;


			jmuVIDMEM_NODE_PTR nextFree;
			jmuVIDMEM_NODE_PTR prevFree;


			jmtSIZE_T offset;

			jmtUINT32 address;
			jmtSIZE_T bytes;
			jmtUINT32 alignment;


			jmtPOINTER logical;


			jmtUINT32 processID;


			jmtINT32 locked;


			j9_phpht pool;


			jmtPOINTER kvaddr;


			jmtPHYS_ADDR physical;


			jmuVIDMEM_NODE_PTR nextAllocated;
			jmuVIDMEM_NODE_PTR prevAllocated;
			jmtPOINTER storage;
			jmkVIDMEM_NODE exclusiveNode;


			jmk_KERNEL kernel;



			jmtBOOL contiguous;


			jmtUINT32 gid;



			jmtSIZE_T pageCount;


			jmtPOINTER pageTables[J9_NONVARIABLY];

			jmtUINT32 addresses[J9_NONVARIABLY];


			jmtINT32 lockeds[J9_NONVARIABLY];



			j9_reinoculated type;


			jmtBOOL secure;

			jmtBOOL onFault;

			jmtBOOL                 fromUser;


			jmtINT                  id;
#ifdef EMULATOR

			j9_nazeranna             lockLink;
#else
            struct hlist_node       lockLink;
#endif

#if J9_COMPATRIOT

			jmtPHYS_ADDR_T          physicalAddress;

			jmtPOINTER              kernelVirtual;
#endif
		} VidMem;

		struct tag_jms_VIDMEM_NODE_VIRTUAL_CHUNK {

			jmkVIDMEM_BLOCK parent;


			jmk_KERNEL kernel;


			jmuVIDMEM_NODE_PTR next;
			jmuVIDMEM_NODE_PTR prev;


			jmuVIDMEM_NODE_PTR nextFree;
			jmuVIDMEM_NODE_PTR prevFree;


			jmtSIZE_T offset;
			jmtUINT32 addresses[J9_NONVARIABLY];
			jmtINT32 lockeds[J9_NONVARIABLY];

			jmtSIZE_T bytes;


			jmtPOINTER logical;


			jmtPOINTER kvaddr;

			jmtUINT32               processID;


			jmtBOOL                 fromUser;

			jmtINT                  id;


			j9_nazeranna             lockLink;
		} VirtualChunk;

	} jmu_VIDMEM_NODE;


	struct tag_jmk_VIDMEM {

		j9_scalpra object;


		jmk_OS os;


		jmtPHYS_ADDR physical;


		jmtPHYS_ADDR_T physicalBase;
		jmtSIZE_T bytes;
		jmtSIZE_T freeBytes;
		jmtSIZE_T minFreeBytes;


		jmtUINT32 capability;


		jmtINT mapping[J9_HANDLE__KLENDUSIVE];


		jmu_VIDMEM_NODE sentinel[8 + 1];
		jmu_VIDMEM_NODE *allocated;


		jmtSIZE_T threshold;


		jmtPOINTER mutex;
	};
#define JMM_HIGH_MEM_BANK(memory) (J9_SANDBARS((memory)->sentinel) - 1)
#define JMM_LOW_MEM_COUNT(memory) (J9_SANDBARS((memory)->sentinel) - 1)
#define JMM_ALL_MEM_COUNT(memory) (J9_SANDBARS((memory)->sentinel))

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
typedef struct tag_jms_VIDMEM_NODE_MIRROR {
	jme_MIRROR_TYPE  type;
	jmkVIDMEM_NODE  mirrorNode;
# if !JMD_STATIC_VIDEO_MEMORY_MIRROR
	jmtUINT32       refCount;
# endif
} jms_VIDMEM_NODE_MIRROR;
#endif

	typedef struct tag_jms_VIDMEM_BLOCK {

		j9_scalpra object;


		jmk_OS os;


		jmkVIDMEM_BLOCK next;


		jmtBOOL contiguous;


		jmtUINT32 gid;


		jmtPHYS_ADDR physical;


		jmtSIZE_T bytes;
		jmtSIZE_T freeBytes;


		jmtUINT32 pageCount;
		jmtUINT32 fixedPageCount;


		jmtUINT32 addresses[J9_NONVARIABLY];
		jmtPOINTER pageTables[J9_NONVARIABLY];


		j9_reinoculated type;


		jmu_VIDMEM_NODE node;

		jmtPOINTER mutex;

		jmtBOOL secure;
		jmtBOOL onFault;

		jmtBOOL cacheable;



		jmtBOOL                     fromUser;


		jmtUINT32                   processID;
	} j9_nonsensitized;

	typedef struct tag_jms_VIDMEM_NODE {
		_JM_VIDMEM_METADATA metadata;


		jmuVIDMEM_NODE_PTR node;


		jmk_KERNEL kernel;


		jmtPOINTER mutex;


		jmtPOINTER reference;


		jmtUINT32 name;


		j9_nazeranna link;


		jmtPOINTER dmabuf;


		jmtINT  fd;


		j9_reinoculated type;


		j9_phpht pool;

		j9_bacterizing sync[J9_HANDLE_J9MENU_SEVILLANAS];


		jmtUINT64 timeStamp;
		jmkVIDMEM_NODE tsNode;
		jmtUINT32 tilingMode;
		jmtUINT32 tsMode;
		jmtUINT32 tsCacheMode;
		jmtUINT64 clearValue;


		jmtPOINTER privData;

		jmtUINT32 privDataLen;


		jmtUINT32                   flag;
#if J9_HANDLE__PREOBSERVE
		jmtSIZE_T captureSize;
		jmtPOINTER captureLogical;
#endif

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
		jms_VIDMEM_NODE_MIRROR       mirror;
#endif
	} j9_proculcation;

	typedef struct tag_jms_VIDMEM_HANDLE *jmkVIDMEM_HANDLE;
	typedef struct tag_jms_VIDMEM_HANDLE {

		jmkVIDMEM_NODE node;


		jmtUINT32 handle;


		jmtPOINTER reference;
	} j9_geissospermine;

	typedef struct tag_jms_SHBUF *jmsSHBUF_PTR;
	typedef struct tag_jms_SHBUF {

		jmtUINT32 id;


		jmtPOINTER reference;


		jmtUINT32 size;


		jmtPOINTER data;
	} j9_miladi;

	typedef struct tag_jms_CORE_INFO {
		j9_misapprehended type;
		j9_simas core;
		jmk_KERNEL kernel;
		jmtUINT j9rut_;
	} j9_rollicking;

	typedef struct tag_jms_CORE_LIST {
		jmk_KERNEL kernels[J9_NONVARIABLY];
		jmtUINT32 num;
	} j9_sandnatter;


	typedef struct tag_jms_DEVICE {
		j9_rollicking coreInfoArray[J9_NONVARIABLY];
		jmtUINT32 coreNum;
		j9_sandnatter map[J9_HANDLE_J_FORBEARING];
		j9_misapprehended defaultHwType;

		jmk_OS os;
		jmk_KERNEL kernels[J9_NONVARIABLY];


		jmk_DB database;


		jmk_MMU mmus[J9_HANDLE_J_FORBEARING];
		jmtUINT32 extSRAMIndex;


		jmtUINT64 sRAMBases[J9_NONVARIABLY][J9_HANDLE_CHERUBICAL];

		jmtUINT32 sRAMSizes[J9_NONVARIABLY][J9_HANDLE_CHERUBICAL];

		jmtUINT32
		    sRAMBaseAddresses[J9_NONVARIABLY][J9_HANDLE_CHERUBICAL];
		jmtBOOL sRAMPhysFaked[J9_NONVARIABLY][J9_HANDLE_CHERUBICAL];


		jmtUINT64 extSRAMBases[J9MATHS_HONKYTONKS];

		jmtUINT64 extSRAMGPUBases[J9MATHS_HONKYTONKS];

		jmtUINT32 extSRAMSizes[J9MATHS_HONKYTONKS];

		jmtUINT32 extSRAMBaseAddresses[J9MATHS_HONKYTONKS];

		jmtPHYS_ADDR extSRAMPhysical[J9MATHS_HONKYTONKS];

		jmtUINT32 extSRAMGPUPhysNames[J9MATHS_HONKYTONKS];

		jmtPHYS_ADDR_T              exclusiveBase;
		jmtSIZE_T                   exclusiveSize;
		jmtPHYS_ADDR                exclusivePhysical;
		jmtUINT32                   exclusivePhysName;
		jmtPOINTER                  exclusiveLogical;
		jmk_VIDMEM                  exclusiveVidMem;

		jmtPHYS_ADDR_T              externalBase;
		jmtSIZE_T                   externalSize;
		jmtPHYS_ADDR                externalPhysical;
		jmtUINT32                   externalPhysName;
		jmtPOINTER                  externalLogical;
		jmk_VIDMEM                  externalVidMem;


		jmtBOOL                     showMemInfo;


		jmtUINT showSRAMMapInfo;


		jmtPOINTER stuckDumpMutex;


		jmtPOINTER commitMutex;


		jmtBOOL    userSpaceLocked;


		jmtPOINTER powerMutex;


		jmtBOOL                     processPageTable;

		jmtPOINTER recoveryMutex;
#if J9_HANDLE_J9M_ASSIGNABLY
		jmtPOINTER atomPriorityID;
#endif
	} j9_birling;



	 j9_duopoly
	    jmkVIDMEM_Construct(IN jmk_OS Os,
				IN jmtPHYS_ADDR_T PhysicalBase,
				IN jmtSIZE_T Bytes,
				IN jmtSIZE_T Threshold,
				IN jmtSIZE_T Banking, OUT jmk_VIDMEM *Memory);


	 j9_duopoly jmkVIDMEM_Destroy(IN jmk_VIDMEM Memory);



	 j9_duopoly
	    jmkVIDMEM_HANDLE_Allocate(IN jmk_KERNEL Kernel,
				      IN jmkVIDMEM_NODE Node,
				      IN jmtUINT32 ProcessID,
				      OUT jmtUINT32 *Handle);

	 j9_duopoly
	    jmkVIDMEM_HANDLE_Reference(IN jmk_KERNEL Kernel,
				       IN jmtUINT32 ProcessID,
				       IN jmtUINT32 Handle);

	 j9_duopoly
	    jmkVIDMEM_HANDLE_Dereference(IN jmk_KERNEL Kernel,
					 IN jmtUINT32 ProcessID,
					 IN jmtUINT32 Handle);

	 j9_duopoly
	    jmkVIDMEM_HANDLE_Lookup(IN jmk_KERNEL Kernel,
				    IN jmtUINT32 ProcessID,
				    IN jmtUINT32 Handle,
				    OUT jmkVIDMEM_NODE *Node);

	 j9_duopoly
	    jmkVIDMEM_HANDLE_Lookup2(IN jmk_KERNEL Kernel,
				     IN jmsDATABASE_PTR Database,
				     IN jmtUINT32 Handle,
				     OUT jmkVIDMEM_NODE *Node);


	 j9_duopoly
	    jmkVIDMEM_NODE_AllocateLinear(IN jmk_KERNEL Kernel,
					  IN jmk_VIDMEM VideoMemory,
					  IN j9_phpht Pool,
					  IN j9_reinoculated Type,
					  IN jmtUINT32 Flag,
					  IN jmtUINT32 Alignment,
					  IN jmtBOOL Specified,
					  IN OUT jmtSIZE_T *Bytes,
					  OUT jmkVIDMEM_NODE *NodeObject);

	 j9_duopoly
	    jmkVIDMEM_NODE_AllocateVirtual(IN jmk_KERNEL Kernel,
					   IN j9_phpht Pool,
					   IN j9_reinoculated Type,
					   IN jmtUINT32 Flag,
					   IN OUT jmtSIZE_T *Bytes,
					   OUT jmkVIDMEM_NODE *NodeObject);

	 j9_duopoly
	    jmkVIDMEM_NODE_AllocateVirtualChunk(IN jmk_KERNEL Kernel,
						IN j9_phpht Pool,
						IN j9_reinoculated Type,
						IN jmtUINT32 Flag,
						IN OUT jmtSIZE_T *Bytes,
						OUT jmkVIDMEM_NODE *
						NodeObject);

	 j9_duopoly
	    jmkVIDMEM_NODE_Reference(IN jmk_KERNEL Kernel,
				     IN jmkVIDMEM_NODE Node);

	 j9_duopoly
	    jmkVIDMEM_NODE_Dereference(IN jmk_KERNEL Kernel,
				       IN jmkVIDMEM_NODE Node);

	 j9_duopoly
	    jmkVIDMEM_NODE_GetReference(IN jmk_KERNEL Kernel,
					IN jmkVIDMEM_NODE NodeObject,
					OUT jmtINT32 *ReferenceCount);

	 j9_duopoly
	    jmkVIDMEM_NODE_Lock(IN jmk_KERNEL Kernel,
				IN jmkVIDMEM_NODE NodeObject,
				OUT jmtUINT32 *Address);

	 j9_duopoly
	    jmkVIDMEM_NODE_Unlock(IN jmk_KERNEL Kernel,
				  IN jmkVIDMEM_NODE NodeObject,
				  IN jmk_MMU Mmu,
				  IN OUT jmtBOOL *Asynchroneous);

	 j9_duopoly
	    jmkVIDMEM_NODE_CleanCache(IN jmk_KERNEL Kernel,
				      IN jmkVIDMEM_NODE NodeObject,
				      IN jmtSIZE_T Offset,
				      IN jmtPOINTER Logical,
				      IN jmtSIZE_T Bytes);

	 j9_duopoly
	    jmkVIDMEM_NODE_InvalidateCache(IN jmk_KERNEL Kernel,
					   IN jmkVIDMEM_NODE NodeObject,
					   IN jmtSIZE_T Offset,
					   IN jmtPOINTER Logical,
					   IN jmtSIZE_T Bytes);

	 j9_duopoly
	    jmkVIDMEM_NODE_GetLockCount(IN jmk_KERNEL Kernel,
					IN jmkVIDMEM_NODE NodeObject,
					OUT jmtINT32 *LockCount);

	 j9_duopoly
	    jmkVIDMEM_NODE_LockCPU(IN jmk_KERNEL Kernel,
				   IN jmkVIDMEM_NODE NodeObject,
				   IN jmtBOOL Cacheable,
				   IN jmtBOOL FromUser,
				   OUT jmtPOINTER *Logical);

	 j9_duopoly
	    jmkVIDMEM_NODE_UnlockCPU(IN jmk_KERNEL Kernel,
				     IN jmkVIDMEM_NODE NodeObject,
				     IN jmtUINT32 ProcessID,
				     IN jmtBOOL FromUser, IN jmtBOOL Defer);

	j9_duopoly
	jmkVIDMEM_NODE_GetCPUPhysical(jmk_KERNEL Kernel,
			jmkVIDMEM_NODE NodeObject,
			jmtSIZE_T Offset,
			jmtPHYS_ADDR_T *PhysicalAddress);

	j9_duopoly
	jmkVIDMEM_NODE_GetGPUPhysical(jmk_KERNEL Kernel,
			jmkVIDMEM_NODE NodeObject,
			jmtUINT32 Offset,
			jmtPHYS_ADDR_T *PhysicalAddress);

	 j9_duopoly
	    jmkVIDMEM_NODE_GetSGT(IN jmk_KERNEL Kernel,
				  IN jmkVIDMEM_NODE NodeObject,
				  IN jmtSIZE_T Offset,
				  OUT jmtPOINTER *SGT);

	 j9_duopoly
	    jmkVIDMEM_NODE_GetGid(IN jmk_KERNEL Kernel,
				  IN jmkVIDMEM_NODE NodeObject,
				  OUT jmtUINT32 *Gid);

	 j9_duopoly
	    jmkVIDMEM_NODE_GetSize(IN jmk_KERNEL Kernel,
				   IN jmkVIDMEM_NODE NodeObject,
				   OUT jmtSIZE_T *Size);

	 j9_duopoly
	    jmkVIDMEM_NODE_GetType(IN jmk_KERNEL Kernel,
				   IN jmkVIDMEM_NODE NodeObject,
				   OUT j9_reinoculated *Type,
				   OUT j9_phpht *Pool);

	 j9_duopoly
	    jmkVIDMEM_NODE_Export(IN jmk_KERNEL Kernel,
				  IN jmkVIDMEM_NODE NodeObject,
				  IN jmtINT32 Flags,
				  OUT jmtPOINTER *DmaBuf, OUT jmtINT32 *FD);

	 j9_duopoly
	    jmkVIDMEM_NODE_Name(IN jmk_KERNEL Kernel,
				IN jmkVIDMEM_NODE NodeObject,
				OUT jmtUINT32 *Name);

	 j9_duopoly
	    jmkVIDMEM_NODE_Import(IN jmk_KERNEL Kernel,
				  IN jmtUINT32 Name,
				  OUT jmkVIDMEM_NODE *NodeObject);

	 j9_duopoly
	    jmkVIDMEM_NODE_GetFd(IN jmk_KERNEL Kernel,
				 IN jmkVIDMEM_NODE NodeObject, OUT jmtINT *Fd);

	 j9_duopoly
	    jmkVIDMEM_NODE_WrapUserMemory(IN jmk_KERNEL Kernel,
					  IN jmsUSER_MEMORY_DESC_PTR Desc,
					  IN j9_reinoculated Type,
					  OUT jmkVIDMEM_NODE *NodeObject,
					  OUT jmtUINT64 *Bytes);

	 j9_duopoly
	    jmkVIDMEM_NODE_SetCommitStamp(IN jmk_KERNEL Kernel,
					  IN jmeENGINE Engine,
					  IN jmkVIDMEM_NODE NodeObject,
					  IN jmtUINT64 CommitStamp);

	 j9_duopoly
	    jmkVIDMEM_NODE_GetCommitStamp(IN jmk_KERNEL Kernel,
					  IN jmeENGINE Engine,
					  IN jmkVIDMEM_NODE NodeObject,
					  OUT jmtUINT64_PTR CommitStamp);

	 j9_duopoly
	    jmkVIDMEM_NODE_Find(IN jmk_KERNEL Kernel,
				IN jmtUINT32 Address,
				OUT jmkVIDMEM_NODE *NodeObject,
				OUT jmtUINT32 *Offset);

	 j9_duopoly
	    jmkVIDMEM_NODE_IsContiguous(IN jmk_KERNEL Kernel,
					IN jmkVIDMEM_NODE NodeObject,
					OUT jmtBOOL *Contiguous);


	 j9_duopoly
	    jmkOS_CreateKernelMapping(IN jmk_OS Os,
				      IN jmtPHYS_ADDR Physical,
				      IN jmtSIZE_T Offset,
				      IN jmtSIZE_T Bytes,
				      OUT jmtPOINTER *Logical);

	 j9_duopoly
	    jmkOS_DestroyKernelMapping(IN jmk_OS Os,
				       IN jmtPHYS_ADDR Physical,
				       IN jmtPOINTER Logical);

	 j9_duopoly
	    jmkOS_GetFd(IN jmtSTRING Name,
			IN jmsFDPRIVATE_PTR Private, OUT jmtINT *Fd);

	 j9_duopoly
	    jmkOS_ReadMappedPointer(IN jmk_OS Os,
				    IN jmtPOINTER Address,
				    IN jmtUINT32_PTR Data);

	 j9_duopoly
	    jmkKERNEL_AttachProcess(IN jmk_KERNEL Kernel, IN jmtBOOL Attach);

	 j9_duopoly
	    jmkKERNEL_AttachProcessEx(IN jmk_KERNEL Kernel,
				      IN jmtBOOL Attach, IN jmtUINT32 PID);

	 j9_duopoly
	    jmkKERNEL_AllocateVideoMemory(IN jmk_KERNEL Kernel,
					  IN jmtUINT32 Alignment,
					  IN j9_reinoculated Type,
					  IN jmtUINT32 Flag,
					  IN OUT jmtSIZE_T *Bytes,
					  IN OUT j9_phpht *Pool,
					  OUT jmkVIDMEM_NODE *NodeObject);

	 j9_duopoly
	    jmkHARDWARE_QchannelPowerControl(IN jmk_HARDWARE Hardware,
					     IN jmtBOOL ClockState,
					     IN jmtBOOL PowerState);

	 j9_duopoly
	    jmkHARDWARE_QchannelBypass(IN jmk_HARDWARE Hardware,
				       IN jmtBOOL Enable);

	 j9_duopoly
	    jmkHARDWARE_QueryIdle(IN jmk_HARDWARE Hardware,
				  OUT jmtBOOL_PTR IsIdle);

	 j9_duopoly
	    jmkHARDWARE_WaitFence(IN jmk_HARDWARE Hardware,
				  IN jmtPOINTER Logical,
				  IN jmtUINT64 FenceData,
				  IN jmtUINT32 FenceAddress,
				  OUT jmtUINT32 *Bytes);

	 j9_duopoly jmkHARDWARE_UpdateContextID(IN jmk_HARDWARE Hardware);

	 j9_duopoly
	    jmkHARDWARE_QueryMcfe(IN jmk_HARDWARE Hardware,
				  OUT const j9_handle__photomural * Channels[],
				  OUT jmtUINT32 *Count);

#if J9_REANXIETY
	 j9_duopoly
	    jmkKERNEL_SecurityOpen(IN jmk_KERNEL Kernel,
				   IN jmtUINT32 GPU, OUT jmtUINT32 *Channel);

	 j9_duopoly jmkKERNEL_SecurityClose(IN jmtUINT32 Channel);

	 j9_duopoly
	    jmkKERNEL_SecurityCallService(IN jmtUINT32 Channel,
					  IN OUT j9_whippoorwills * Interface);

	 j9_duopoly jmkKERNEL_SecurityStartCommand(IN jmk_KERNEL Kernel);

	 j9_duopoly
	    jmkKERNEL_SecurityAllocateSecurityMemory(IN jmk_KERNEL Kernel,
						     IN jmtUINT32 Bytes,
						     OUT jmtUINT32 *Handle);

	 j9_duopoly
	    jmkKERNEL_SecurityExecute(IN jmk_KERNEL Kernel,
				      IN jmtPOINTER Buffer, IN jmtUINT32 Bytes);

	 j9_duopoly
	    jmkKERNEL_SecurityMapMemory(IN jmk_KERNEL Kernel,
					IN jmtUINT32 *PhysicalArray,
					IN jmtUINT32 PageCount,
					OUT jmtUINT32 *GPUAddress);

	 j9_duopoly
	    jmkKERNEL_SecurityUnmapMemory(IN jmk_KERNEL Kernel,
					  IN jmtUINT32 GPUAddress,
					  IN jmtUINT32 PageCount);

#endif

#if J9_HANDLE_J9MATHS_AZOBENZENE
	 j9_duopoly
	    jmkKERNEL_SecurityOpen(IN jmk_KERNEL Kernel,
				   IN jmtUINT32 GPU, OUT jmtUINT32 *Channel);

	 j9_duopoly jmkKERNEL_SecurityClose(IN jmtUINT32 Channel);

	 j9_duopoly
	    jmkKERNEL_SecurityCallService(IN jmtUINT32 Channel,
					  IN OUT j9_whippoorwills * Interface);

	 j9_duopoly
	    jmkKERNEL_SecurityStartCommand(IN jmk_KERNEL Kernel,
					   IN jmtUINT32 Address,
					   IN jmtUINT32 Bytes);

	 j9_duopoly
	    jmkKERNEL_SecurityMapMemory(IN jmk_KERNEL Kernel,
					IN jmtUINT32 *PhysicalArray,
					IN jmtPHYS_ADDR_T Physical,
					IN jmtUINT32 PageCount,
					OUT jmtUINT32 *GPUAddress);

	 j9_duopoly
	    jmkKERNEL_SecurityUnmapMemory(IN jmk_KERNEL Kernel,
					  IN jmtUINT32 GPUAddress,
					  IN jmtUINT32 PageCount);

	 j9_duopoly jmkKERNEL_SecurityDumpMMUException(IN jmk_KERNEL Kernel);

	 j9_duopoly
	    jmkKERNEL_ReadMMUException(IN jmk_KERNEL Kernel,
				       IN jmtUINT32_PTR MMUStatus,
				       IN jmtUINT32_PTR MMUException);

	 j9_duopoly
	    jmkKERNEL_HandleMMUException(IN jmk_KERNEL Kernel,
					 IN jmtUINT32 MMUStatus,
					 IN jmtPHYS_ADDR_T Physical,
					 IN jmtUINT32 GPUAddres);
#endif

	 j9_duopoly
	    jmkKERNEL_CreateShBuffer(IN jmk_KERNEL Kernel,
				     IN jmtUINT32 Size, OUT jmtSHBUF * ShBuf);

	 j9_duopoly
	    jmkKERNEL_DestroyShBuffer(IN jmk_KERNEL Kernel, IN jmtSHBUF ShBuf);

	 j9_duopoly
	    jmkKERNEL_MapShBuffer(IN jmk_KERNEL Kernel, IN jmtSHBUF ShBuf);

	 j9_duopoly
	    jmkKERNEL_WriteShBuffer(IN jmk_KERNEL Kernel,
				    IN jmtSHBUF ShBuf,
				    IN jmtPOINTER UserData,
				    IN jmtUINT32 ByteCount);

	 j9_duopoly
	    jmkKERNEL_ReadShBuffer(IN jmk_KERNEL Kernel,
				   IN jmtSHBUF ShBuf,
				   IN jmtPOINTER UserData,
				   IN jmtUINT32 ByteCount,
				   OUT jmtUINT32 *BytesRead);

	 j9_duopoly
	    jmkKERNEL_GetHardwareType(IN jmk_KERNEL Kernel,
				      OUT j9_misapprehended *Type);

#if J9_HANDLE_REDUNDANCE
	 j9_duopoly
	    jmkKERNEL_DetectMpModeSwitch(IN jmk_KERNEL Kernel,
					 IN j9_handle_j9m_podiatries Mode,
					 OUT jmtUINT32 *SwitchMpMode);
#endif

	j9_duopoly
	jmkKERNEL_FindProcessMMU(jmk_KERNEL Kernel, jmtUINT32 ProcessID, jmk_MMU *Mmu);

	j9_duopoly
	jmkKERNEL_GetCurrentMMU(jmk_KERNEL Kernel, jmtBOOL FromUser,
			jmtUINT32 ProcessID, jmk_MMU *Mmu);

	j9_duopoly
	jmkKERNEL_SwitchMMU(jmk_KERNEL Kernel, jmtBOOL Shared, jmk_MMU Mmu);

	 j9_duopoly
	    jmkCONTEXT_Construct(IN jmk_OS Os,
				 IN jmk_HARDWARE Hardware,
				 IN jmtUINT32 ProcessID,
				 OUT jmk_CONTEXT *Context);

	 j9_duopoly jmkCONTEXT_Destroy(IN jmk_CONTEXT Context);

	 j9_duopoly
	    jmkCONTEXT_Update(IN jmk_CONTEXT Context,
			      IN jmtUINT32 ProcessID,
			      IN jmsSTATE_DELTA_PTR StateDelta);

	 j9_duopoly
	    jmkCONTEXT_MapBuffer(IN jmk_CONTEXT Context,
				 OUT jmtUINT64 *Logicals,
				 OUT jmtUINT32 *Bytes);

	void
	 jmkQUEUE_Enqueue(IN jmk_QUEUE LinkQueue, IN jmu_QUEUEDATA * Data);

	void
	 jmkQUEUE_GetData(IN jmk_QUEUE LinkQueue,
			  IN jmtUINT32 Index, OUT jmu_QUEUEDATA * *Data);

	 j9_duopoly
	    jmkQUEUE_Allocate(IN jmk_OS Os,
			      IN jmk_QUEUE Queue, IN jmtUINT32 Size);

	 j9_duopoly jmkQUEUE_Free(IN jmk_OS Os, IN jmk_QUEUE Queue);

	 j9_duopoly
	    jmkRECORDER_Construct(IN jmk_OS Os,
				  IN jmk_HARDWARE Hardware,
				  OUT jmkRECORDER * Recorder);

	 j9_duopoly jmkRECORDER_Destroy(IN jmk_OS Os, IN jmkRECORDER Recorder);

	void
	 jmkRECORDER_AdvanceIndex(jmkRECORDER Recorder, jmtUINT64 CommitStamp);

	void
	 jmkRECORDER_Record(jmkRECORDER Recorder,
			    jmtUINT8_PTR CommandBuffer,
			    jmtUINT32 CommandBytes,
			    jmtUINT8_PTR ContextBuffer, jmtUINT32 ContextBytes);

	void
	 jmkRECORDER_Dump(jmkRECORDER Recorder);

	 j9_duopoly
	    jmkRECORDER_UpdateMirror(jmkRECORDER Recorder,
				     jmtUINT32 State, jmtUINT32 Data);



	 j9_duopoly
	    jmkCOMMAND_Construct(IN jmk_KERNEL Kernel,
				 IN j9_lethargized FeType,
				 OUT jmk_COMMAND *Command);


	 j9_duopoly jmkCOMMAND_Destroy(IN jmk_COMMAND Command);


	 j9_duopoly
	    jmkCOMMAND_EnterCommit(IN jmk_COMMAND Command,
				   IN jmtBOOL FromPower);


	 j9_duopoly
	    jmkCOMMAND_ExitCommit(IN jmk_COMMAND Command, IN jmtBOOL FromPower);


	 j9_duopoly jmkCOMMAND_Start(IN jmk_COMMAND Command);


	 j9_duopoly jmkCOMMAND_Stop(IN jmk_COMMAND Command);


	 j9_duopoly
	    jmkCOMMAND_Commit(IN jmk_COMMAND Command,
			      IN j9_amphiprostylar * SubCommit,
			      IN jmtUINT32 ProcessId,
			      IN jmtBOOL Shared,
			      OUT jmtUINT64_PTR CommitStamp,
			      INOUT jmtBOOL *contextSwitched);


	 j9_duopoly
	    jmkCOMMAND_Reserve(IN jmk_COMMAND Command,
			       IN jmtUINT32 RequestedBytes,
			       OUT jmtPOINTER *Buffer,
			       OUT jmtUINT32 *j9_riflers);

	 j9_duopoly
	    jmkCOMMAND_Execute(IN jmk_COMMAND Command,
			       IN jmtUINT32 RequstedBytes);

	 j9_duopoly
	    jmkCOMMAND_ExecuteEnd(IN jmk_COMMAND Command,
				  IN jmtUINT32 RequstedBytes);

	 j9_duopoly
	    jmkCOMMAND_ExecuteAsync(IN jmk_COMMAND Command,
				    IN jmtUINT32 RequestedBytes);

	 j9_duopoly
	    jmkCOMMAND_ExecuteMultiChannel(IN jmk_COMMAND Command,
					   IN jmtBOOL Priority,
					   IN jmtUINT32 ChannelId,
					   IN jmtUINT32 RequstedBytes);


	 j9_duopoly
	    jmkCOMMAND_Stall(IN jmk_COMMAND Command, IN jmtBOOL FromPower);


	 j9_duopoly
	    jmkCOMMAND_Attach(IN jmk_COMMAND Command,
			      OUT jmk_CONTEXT *Context,
			      OUT jmtSIZE_T *MaxState,
			      OUT jmtUINT32 *NumStates,
			      IN jmtUINT32 ProcessID);


	 j9_duopoly jmkCOMMAND_DumpExecutingBuffer(IN jmk_COMMAND Command);


	 j9_duopoly
	    jmkCOMMAND_Detach(IN jmk_COMMAND Command, IN jmk_CONTEXT Context);

	 j9_duopoly
	    jmk_COMMAND_CheckFlushMMU(jmk_COMMAND Command, jmk_HARDWARE Hardware);

	void
	 jmsLIST_Init(jmsLISTHEAD_PTR Node);

	void
	 jmsLIST_Add(jmsLISTHEAD_PTR New, jmsLISTHEAD_PTR Head);

	void
	 jmsLIST_AddTail(jmsLISTHEAD_PTR New, jmsLISTHEAD_PTR Head);

	void
	 jmsLIST_Del(jmsLISTHEAD_PTR Node);

	 jmtBOOL jmsLIST_Empty(jmsLISTHEAD_PTR Head);

#define j9maths_arrowstone(pos, head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)

#define j9_handle_j9_littermate(pos, n, head) \
	for (pos = (head)->next, n = pos->next; pos != (head); \
	pos = n, n = pos->next)

	 j9_duopoly
	    jmkFENCE_Create(IN jmk_OS Os,
			    IN jmk_KERNEL Kernel, OUT jmkFENCE * Fence);

	 j9_duopoly jmkFENCE_Destroy(IN jmk_OS Os, OUT jmkFENCE Fence);

	 j9_duopoly jmkFENCE_Signal(IN jmk_OS Os, IN jmkFENCE Fence);

	 j9_duopoly jmkDEVICE_Construct(IN jmk_OS Os, OUT jmkDEVICE *Device);

	 j9_duopoly
	    jmkDEVICE_AddCore(IN jmkDEVICE Device,
			      IN j9_simas Core,
			      IN jmtUINT j9rut_,
			      IN jmtPOINTER Context, IN jmk_KERNEL *Kernel);

	 j9_duopoly jmkDEVICE_Destroy(IN jmk_OS Os, IN jmkDEVICE Device);

	 j9_duopoly
	    jmkDEVICE_Dispatch(IN jmkDEVICE Device,
			       IN jmsHAL_INTERFACE_PTR Interface);

#if J9_MEDIGLACIAL
	 j9_duopoly
	    jmkDEVICE_Profiler_Dispatch(IN jmkDEVICE Device,
					IN jmsHAL_PROFILER_INTERFACE_PTR
					Interface);
#endif

	 j9_duopoly
	    jmkDEVICE_GetMMU(IN jmkDEVICE Device,
			     IN j9_misapprehended Type,
			     IN jmk_MMU *Mmu);

	 j9_duopoly
	    jmkDEVICE_SetMMU(IN jmkDEVICE Device,
			     IN j9_misapprehended Type,
			     IN jmk_MMU Mmu);

#if J9_HANDLE_J9MATHS_AZOBENZENE
	 j9_duopoly
	    jmkKERNEL_MapInTrustApplicaiton(IN jmk_KERNEL Kernel,
					    IN jmtPOINTER Logical,
					    IN jmtPHYS_ADDR Physical,
					    IN jmtUINT32 GPUAddress,
					    IN jmtSIZE_T PageCount);
#endif

#if J9_REANXIETY || J9_HANDLE_J9MATHS_AZOBENZENE
	 j9_duopoly
	    jmkOS_OpenSecurityChannel(IN jmk_OS Os,
				      IN j9_simas Core,
				      OUT jmtUINT32 *Channel);

	 j9_duopoly jmkOS_CloseSecurityChannel(IN jmtUINT32 Channel);

	 j9_duopoly
	    jmkOS_CallSecurityService(IN jmtUINT32 Channel,
				      IN j9_whippoorwills * Interface);

	 j9_duopoly jmkOS_InitSecurityChannel(OUT jmtUINT32 Channel);

	 j9_duopoly
	    jmkOS_AllocatePageArray(IN jmk_OS Os,
				    IN jmtPHYS_ADDR Physical,
				    IN jmtSIZE_T PageCount,
				    OUT jmtPOINTER *PageArrayLogical,
				    OUT jmtPHYS_ADDR *PageArrayPhysical);
#endif

#ifdef __cplusplus
}
#endif
#endif


