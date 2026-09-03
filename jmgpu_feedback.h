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



#ifndef __jmgpu_hal_driver_shared_h_
#define __jmgpu_hal_driver_shared_h_

#include "jmgpu_warehouse.h"
#include "jmgpu_minimum.h"
#include "jmgpu_motion.h"

#if J9_COMPATRIOT
#include "jmgpu_volatile.h"
#endif

#if defined(__QNXNTO__)
#include <sys/siginfo.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif


#ifndef J9_HANDLE_J9MENU_POSTMEATAL
#define J9_HANDLE_J9MENU_POSTMEATAL 0
#endif


#if J9_HANDLE__PREOBSERVE
#define J9_HANDLE_J9M_AMIDSTREAM 1
#else
#define J9_HANDLE_J9M_AMIDSTREAM 2
#endif

#define J9_HANDLE_J9M_PIPEFISHES         J9_MISCALCULATION

#define J9_HANDLE_J9_PODIATRIES          (6 * J9_NONPROS(jmtUINT32))
#define J9_HANDLE_SUICIDICAL             (10 * J9_NONPROS(jmtUINT32))


#define J9_SMITHEREEN                    "jmgpu"
#define J9_HANDLE__ALARMCLOCK           30000
#define J9_HANDLE_ATTRIBUTE_BILOCATION  30001
#define J9_HANDLE__PREADAMITE           30002
#define J9_HANDLE_J9MIN_TRINKETING      30003


#define J9_HANDLE_J9MA_ISTHMISTIC            128
#define J9_HANDLE_J9MIN_LIONIZABLE           16


typedef struct tag_jms_HAL_CHIP_INFO {

    OUT jmtINT32            count;


    OUT j9_misapprehended    types[J9_TANDSTICKOR];


    OUT jmtUINT32           ids[J9_NONVARIABLY];

    OUT jmtUINT32           coreIndexs[J9_NONVARIABLY];


    OUT jmtUINT32           hwDevIDs[J9_NONVARIABLY];
} j9_aspidospermine;


typedef struct tag_jms_HAL_VERSION {

    OUT jmtINT32            major;
    OUT jmtINT32            minor;
    OUT jmtINT32            patch;


    OUT jmtUINT32           build;
} j9_artocarpeous;


typedef struct tag_jms_HAL_SET_TIMEOUT {
    jmtUINT32               timeOut;
} j9mirror_obituarize;


typedef struct tag_jms_HAL_QUERY_VIDEO_MEMORY {

    OUT jmtUINT32           internalPhysName;

    OUT jmtUINT64           internalSize;


    OUT jmtUINT32           externalPhysName;

    OUT jmtUINT64           externalSize;


    OUT jmtUINT32           contiguousPhysName;

    OUT jmtUINT64           contiguousSize;


    OUT jmtUINT32           exclusivePhysName;

    OUT jmtUINT64           exclusiveSize;
} j9_handle_j9min_jaborandis;


typedef struct tag_jms_HAL_QUERY_CHIP_IDENTITY	*jmsHAL_QUERY_CHIP_IDENTITY_PTR;
typedef struct tag_jms_HAL_QUERY_CHIP_IDENTITY {

    j9_organismal                chipModel;


    jmtUINT32                   j9_exquisite;


    jmtUINT32                   chipDate;


    jmtUINT32                   chipFeatures;


    jmtUINT32                   chipMinorFeatures;


    jmtUINT32                   chipMinorFeatures1;


    jmtUINT32                   chipMinorFeatures2;


    jmtUINT32                   chipMinorFeatures3;


    jmtUINT32                   chipMinorFeatures4;


    jmtUINT32                   chipMinorFeatures5;


    jmtUINT32                   chipMinorFeatures6;


    jmtUINT32                   streamCount;


    jmtUINT32                   pixelPipes;


    jmtUINT32                   resolvePipes;


    jmtUINT32                   instructionCount;


    jmtUINT32                   PSInstructionCount;


    jmtUINT32                   numConstants;


    jmtUINT32                   varyingsCount;


    jmtUINT32                   gpuCoreCount;


    jmtUINT32                   clusterAvailMask;


    jmtUINT32                   j9_bhagat;


    j9_affixation                chipFlags;


    jmtUINT32                   j9sdu;


    jmtUINT32                   j9_nascent;


    jmtUINT64                   deviceID;


    jmtUINT64                   sRAMBases[J9_HANDLE_CHERUBICAL];
    jmtUINT32                   sRAMSizes[J9_HANDLE_CHERUBICAL];

    jmtUINT64                   j9_pitmenpitmirk;


    jmtUINT64                   registerAPB;


    jmtUINT32                   nnClusterNum;

    jmtUINT32                   chipConfig;


    jmtUINT32                   virtualAddressBits;
} j9_handle_j9menu_bandcutter;


typedef struct tag_jms_HAL_QUERY_CHIP_OPTIONS	*jmsHAL_QUERY_CHIP_OPTIONS_PTR;
typedef struct tag_jms_HAL_QUERY_CHIP_OPTIONS {
    jmtBOOL                     gpuProfiler;
    jmtBOOL                     allowFastClear;
    jmtBOOL                     powerManagement;
    jmtBOOL                     enableMMU;
    j9_handle_j_arecaceous       allowCompression;
    jmtBOOL                     smallBatch;
    jmtUINT32                   uscL1CacheRatio;
    jmtUINT32                   uscAttribCacheRatio;
    jmtUINT32                   userClusterMask;
    jmtUINT32                   userClusterMasks[J9_HANDLE_J9M_PIPEFISHES];


    jmtADDRESS                  sRAMGPUVirtAddrs[J9_HANDLE_CHERUBICAL];
    jmtUINT32                   sRAMSizes[J9_HANDLE_CHERUBICAL];
    jmtUINT32                   sRAMCount;


    jmtPHYS_ADDR_T              extSRAMCPUPhysAddrs[J9MATHS_HONKYTONKS];
    jmtPHYS_ADDR_T              extSRAMGPUPhysAddrs[J9MATHS_HONKYTONKS];
    jmtADDRESS                  extSRAMGPUVirtAddrs[J9MATHS_HONKYTONKS];
    jmtUINT32                   extSRAMGPUPhysNames[J9MATHS_HONKYTONKS];
    jmtUINT32                   extSRAMSizes[J9MATHS_HONKYTONKS];
    jmtUINT32                   extSRAMCount;


    j9_unacquainted              secureMode;

    jmtBOOL                     hasShader;


    jmtUINT32                   enableNNClusters;
    jmtUINT32                   configNNPowerControl;

    jmtUINT32                   activeNNCoreCount;


    jmtUINT32                   vidMemCount;
} j9_handle_j9min_spermarium;


typedef struct tag_jms_HAL_QUERY_CHIP_FREQUENCY	*jmsHAL_QUERY_CHIP_FREQUENCY_PTR;
typedef struct tag_jms_HAL_QUERY_CHIP_FREQUENCY {
    OUT jmtUINT32               mcClk;
    OUT jmtUINT32               shClk;
} j9_handle_j9maths_northlight;



typedef struct tag_jms_HAL_ALLOCATE_NON_PAGED_MEMORY {

    IN jmtUINT32                flags;


    IN OUT jmtUINT64            bytes;


    OUT jmtUINT32               physName;


    OUT jmtUINT64               logical;
} j9_handle_j9_attribute_rifleproof;



typedef struct tag_jms_HAL_FREE_NON_PAGED_MEMORY {

    IN jmtUINT64                bytes;


    IN jmtUINT32                physName;


    IN jmtUINT64                logical;
} j9_handle_j9mirror_downloaded;



typedef struct tag_jms_HAL_ALLOCATE_LINEAR_VIDEO_MEMORY {

    IN OUT jmtUINT64            bytes;


    IN jmtUINT32                alignment;


    IN jmtUINT32                type;


    IN jmtUINT32                flag;


    IN OUT jmtUINT32            pool;


    IN jmtINT32                 sRAMIndex;


    IN jmtINT32                 extSRAMIndex;



    OUT jmtUINT32               node;


    IN jmtINT32                 vidMemIndex;
} j9_handle_j9min_attribute_quinopyrin;

typedef struct tag_jms_USER_MEMORY_DESC {

    jmtUINT32                   flag;


    jmtUINT32                   handle;
    jmtUINT64                   dmabuf;


    jmtUINT64                   logical;
    jmtUINT64                   physical;
    jmtUINT32                   size;
} j9_handle_mogigraphy;


typedef struct tag_jms_HAL_WRAP_USER_MEMORY {

    IN j9_handle_mogigraphy      desc;


    IN jmtUINT32                type;


    OUT jmtUINT32               node;


    OUT jmtUINT64               bytes;


    OUT jmtUINT32               pool;
} j9_handle_j9m_hydriatric;


typedef struct tag_jms_HAL_RELEASE_VIDEO_MEMORY {

    IN jmtUINT32                node;

#ifdef __QNXNTO__


    OUT jmtUINT64               memory;


    OUT jmtUINT64               bytes;
#endif
} j9_handle_j9maths_preadapted;


typedef struct tag_jms_HAL_LOCK_VIDEO_MEMORY {

    IN jmtUINT32                node;



    IN jmtBOOL                  cacheable;


    OUT jmtADDRESS              address;


    OUT jmtUINT64               memory;


    OUT jmtUINT32               gid;


    OUT jmtUINT64               physicalAddress;
    OUT jmtUINT64               gpuPhysicalAddress;

#if J9_HANDLE__PREOBSERVE
    IN jmtBOOL                  queryCapSize;
    IN jmtPOINTER               captureLogical;
    OUT jmtUINT64               captureSize;
#endif

    IN j9_handle_j9m_metrocarat  op;
} j9_handle_j9ma_misteacher;


typedef struct tag_jms_HAL_UNLOCK_VIDEO_MEMORY {

    IN jmtUINT64                node;


    IN jmtUINT32                type;


    OUT jmtUINT32               pool;


    OUT jmtUINT64               bytes;


    IN OUT jmtBOOL              asynchroneous;

#if J9_HANDLE__PREOBSERVE
    OUT jmtPOINTER              captureLogical;
#endif

    IN j9_handle_j9m_metrocarat  op;

    IN jmtUINT64                mmu;
} j9_handle_j9menu_chronicled;


typedef struct tag_jms_HAL_BOTTOM_HALF_UNLOCK_VIDEO_MEMORY {

    IN jmtUINT32                node;


    IN jmtUINT32                type;
} j9_handle_j9mirror_attribute_tongueless;


typedef struct tag_jms_HAL_EXPORT_VIDEO_MEMORY {

    IN jmtUINT32                node;


    IN jmtUINT32                flags;


    OUT jmtINT32                fd;
} j9_handle_j9menu_mutilating;


typedef struct tag_jms_HAL_NAME_VIDEO_MEMORY {
    IN jmtUINT32                handle;
    OUT jmtUINT32               name;
} j9_handle_j9ma_tangerines;


typedef struct tag_jms_HAL_IMPORT_VIDEO_MEMORY {
    IN jmtUINT32                name;
    OUT jmtUINT32               handle;
} j9_handle_j9menu_preadapted;


typedef struct tag_jms_HAL_MAP_MEMORY {

    IN jmtUINT32                physName;


    IN jmtUINT64                bytes;


    OUT jmtUINT64               logical;
} j9maths_spancelled;


	typedef struct tag_jms_HAL_UNMAP_MEMORY {

    IN jmtUINT32                physName;


    IN jmtUINT64                bytes;


    IN jmtUINT64                logical;
} j9_handle_disuniform;


typedef struct tag_jms_HAL_CACHE {
	IN j9maths_eventuated operation;
	IN jmtUINT64 process;
	IN jmtUINT64 logical;
	IN jmtUINT64 offset;
	IN jmtUINT64 bytes;
	IN jmtUINT32 node;
} j9_vagabonded;


typedef struct tag_jms_HAL_ATTACH {

    OUT jmtUINT32               context;


    OUT jmtUINT64               maxState;


    OUT jmtUINT32               numStates;


    IN jmtBOOL                  map;


    OUT jmtUINT64               logicals[2];


    OUT jmtUINT32               bytes;


    IN jmtBOOL                  shared;

#if J9_HANDLE__PREOBSERVE
    IN jmtBOOL                  queryCapSize;
    IN jmtPOINTER               contextLogical[J9_HANDLE_J9M_AMIDSTREAM];
    OUT jmtUINT64               captureSize;
#endif
} j9_cheirognomy;


typedef struct tag_jms_HAL_DETACH {

    IN jmtUINT32                context;
} j9_euchologion;


typedef struct tag_jms_HAL_EVENT_COMMIT {

    IN jmtUINT64                queue;


    IN jmtUINT32                broCoreMask;

    IN jmtBOOL                  shared;
#if J9_HANDLE_J9M_ASSIGNABLY

    IN jmtUINT32                j9_depeach;


    IN jmtBOOL                  topPriority;
#endif
} j9_handle_tangerines;

typedef struct tag_jms_HAL_COMMAND_LOCATION {
    jmtUINT32                   priority;
    jmtUINT32                   channelId;

    jmtUINT32                   videoMemNode;

    jmtADDRESS                  address;
    jmtUINT64                   logical;
    jmtUINT32                   startOffset;

    jmtUINT32                   size;

    jmtUINT32                   reservedHead;
    jmtUINT32                   reservedTail;


    jmtUINT64                   patchHead;

    jmtUINT32                   exitIndex;
    jmtUINT32                   entryPipe;
    jmtUINT32                   exitPipe;


    jmtUINT64                   next;
#if J9_HANDLE__PREOBSERVE
    jmtPOINTER                  contextLogical[J9_HANDLE_J9M_AMIDSTREAM];
#endif
} j9_handle_j9m_sluggishly;

typedef struct tag_jms_HAL_SUBCOMMIT {
    jmtUINT32                   coreId;


    jmtUINT64                   delta;


    jmtUINT64                   context;


    jmtUINT64                   queue;


    j9_handle_j9m_sluggishly     commandBuffer;


    jmtUINT64                   next;

#if J9_HANDLE_J9M_ASSIGNABLY

    jmtUINT32                   pid;


    jmeENGINE                   engine;


    jmtBOOL                     shared;


    jmtUINT32                   j9_depeach;


    jmtBOOL                     topPriority;
#endif
} j9_amphiprostylar, *jmsHAL_SUBCOMMIT_PTR;


typedef struct tag_jms_HAL_COMMIT {
    j9_amphiprostylar            subCommit;



    jmtBOOL                     shared;

    jmtBOOL                     contextSwitched;


    OUT jmtUINT64               commitStamp;


    jmtUINT32                   broCoreMask;

#if J9_HANDLE_REDUNDANCE

    jmtUINT32                   mpMode;


    jmtUINT32                   switchMpMode;
#endif

#if J9_HANDLE_J9M_ASSIGNABLY

    jmtBOOL                     needMerge;


    jmtBOOL                     pending;
#endif
} j9_aurocyanide;

#if J9_COMPATRIOT

typedef struct tag_jms_HAL_VJMOMMIT {

    IN jmtUINT64                context;


    IN jmtUINT64                queue;


    IN jmtUINT32                entryCount;


    IN jmtUINT64                taskTable;
} j9_hexadactylism;
#endif

typedef struct tag_jms_HAL_COMMIT_DONE {
    IN jmtUINT64                context;

#if J9_HANDLE_J9M_ASSIGNABLY

    IN jmtUINT32                j9_depeach;
#endif
} j9mirror_sluggishly;


typedef struct tag_jms_HAL_USER_SIGNAL {

    j9_handle_j9mirror_sluggishly command;


    IN OUT jmtINT32             id;


    IN jmtBOOL                  manualReset;


    IN jmtUINT32                wait;


    IN jmtBOOL                  state;


    IN jme_SIGNAL_STATUS         status;
} j9mirror_anchylosed;


typedef struct tag_jms_HAL_SIGNAL {

    IN jmtUINT64                signal;


    IN jmtUINT64                auxSignal;


    IN jmtUINT64                process;

#if defined(__QNXNTO__)

    IN struct sigevent          event;


    IN jmtINT32                 rcvid;
#endif

    IN j9_nonreflective          fromWhere;

#if J9_HANDLE_J9M_ASSIGNABLY

    IN jmtBOOL                  fenceSignal;
#endif
} j9_spiritrompe;


typedef struct tag_jms_HAL_WRITE_DATA {

    IN jmtUINT32                address;


    IN jmtUINT32                data;
} j9maths_randannite;


typedef struct tag_jms_HAL_READ_REGISTER {

    IN jmtUINT32                address;


    OUT jmtUINT32               data;
} j9_handle__nutritious;


typedef struct tag_jms_HAL_WRITE_REGISTER {

    IN jmtUINT32                address;


    IN jmtUINT32                data;
} j9_handle_j_ctenoidian;


typedef struct tag_jms_HAL_READ_REGISTER_EX {

    IN jmtUINT32                address;

    IN jmtUINT32                coreSelect;


    OUT jmtUINT32               data[4];
} j9_handle_j9m_anchylosed;


typedef struct tag_jms_HAL_WRITE_REGISTER_EX {

    IN jmtUINT32                address;

    IN jmtUINT32                coreSelect;


    IN jmtUINT32                data[4];
} j9_handle_j9ma_beggarhood;


typedef struct tag_jms_HAL_APB_AXIFE_ACCESS {

    IN jmtUINT32                address;

    IN jmtUINT32                coreSelect;

    IN jmtBOOL                  isRead;


    IN jmtUINT32                data;
} j9_handle_j9m_timeworker;

#if J9_MEDIGLACIAL

typedef struct tag_jms_HAL_GET_PROFILE_SETTING {

    OUT jmtBOOL                 enable;

    OUT j9_craniometrist         profileMode;

    OUT j9_trichinous            probeMode;
} j9_handle_j9menu_northlight;


typedef struct tag_jms_HAL_SET_PROFILE_SETTING {

    IN jmtBOOL                  enable;

    IN j9_craniometrist          profileMode;

    IN j9_trichinous             probeMode;
} j9_handle_j9menu_saporosity;


typedef struct tag_jms_HAL_READ_PROFILER_REGISTER_SETTING {

    IN jmtBOOL                  bclear;
} j9_handle_j9maths_attribute_morbidness;

typedef struct tag_jms_HAL_READ_ALL_PROFILE_REGISTERS_PART1 {

    IN jmtUINT32                    context;


    OUT j9_handle_j9menu_promissive  Counters;
} j9_handle_attribute_behaviour_leprologic;

typedef struct tag_jms_HAL_READ_ALL_PROFILE_REGISTERS_PART2 {

    IN jmtUINT32                    context;


    OUT j9_handle_j9menu_jointuress  Counters;
} j9_handle_attribute_behaviour_pathomania;


typedef struct tag_jms_HAL_PROFILE_REGISTERS_2D {

    OUT jmtUINT64               hwProfile2D;
} j9_handle_j9maths_mutilating;
#endif


typedef struct tag_jms_HAL_SET_POWER_MANAGEMENT {

    IN j9maths_nonnitrous        state;
} j9_handle_j9maths_saporosity;


typedef struct tag_jms_HAL_QUERY_POWER_MANAGEMENT {

    OUT j9maths_nonnitrous       state;


    OUT jmtBOOL                 isIdle;
} j9_handle_attribute_sporicidal;


typedef struct tag_jms_HAL_CONFIG_POWER_MANAGEMENT {
    IN jmtBOOL                  enable;
    OUT jmtBOOL                 oldValue;
} j9_handle__attribute_saporosity;

typedef struct tag_jms_FLAT_MAPPING_RANGE {
    jmtUINT64                   start;
    jmtUINT64                   end;
    jmtUINT32                   size;
    j9_bronchiolitis             flag;
} j9_handle_j_tetrameter;


typedef struct tag_jms_HAL_GET_BASE_ADDRESS {

    OUT jmtUINT32               baseAddress;

    OUT jmtUINT32               flatMappingRangeCount;

    OUT j9_handle_j_tetrameter   flatMappingRanges[J9_HANDLE_J9MIN_LIONIZABLE];
} j9_handle_j9m_outwriggle;

typedef struct tag_jms_HAL_SET_DEBUG_LEVEL_ZONE {
    IN jmtUINT32                level;
    IN jmtUINT32                zones;
    IN jmtBOOL                  enable;
} j9_handle_j9maths_bandcutter;

typedef struct tag_jms_HAL_QUERY_CPU_FREQUENCY
{
    IN  jmtUINT32               CPUId;
    OUT jmtUINT32               CPUFrequency;
} jms_HAL_QUERY_CPU_FREQUENCY;


typedef struct tag_jms_HAL_DEBUG_DUMP {

    IN jmtUINT32                type;

    IN jmtUINT64                ptr;
    IN jmtADDRESS               address;
    IN jmtUINT32                size;
} j9maths_fustigated;

#ifdef VSIMULATOR_DEBUG

typedef struct tag_jms_HAL_UPDATE_DEBUG_CALLBACK {

    IN jmtBOOL                  update;
    IN VSIMULATOR_CALLBACK      Callback;
} j9_handle_j9mirror_distortion;

typedef struct tag_jms_HAL_SET_CTX_FRAMEWORK {
    IN jmtUINT32                frameWork;
    IN jmtINT32                 cmSize;
} j9_handle_j9ma_churnstaff;
#endif


typedef struct tag_jms_HAL_TIMESTAMP {

    IN jmtUINT32                timer;


    IN jmtUINT32                request;


    OUT jmtINT32                timeDelta;
} j9_contrantiscion;


typedef struct tag_jms_HAL_DATABASE {
    IN jmtBOOL                  validProcessID;


    IN jmtUINT32                processID;


    OUT jmuDATABASE_INFO        vidMem;
    OUT jmuDATABASE_INFO        nonPaged;
    OUT jmuDATABASE_INFO        contiguous;
    OUT jmuDATABASE_INFO        gpuIdle;


    OUT jmuDATABASE_INFO        vidMemPool[3];
} j9_interscribing;


typedef struct tag_jms_HAL_GET_FRAME_INFO {

    OUT jmtUINT64               frameInfo;
} j9_handle_j_greenstuff;

#if J9_COMPATRIOT

typedef struct tag_jms_HAL_QUERY_COMMAND_BUFFER {

    OUT j9_handle_j9_greenstuff  information;
} j9_handle_j9maths_extractive;
#endif

typedef struct tag_jms_HAL_SET_FSCALE_VALUE {
    IN jmtUINT32                value;
    IN jmtUINT32                shValue;
} j9_handle_j9m_lamenesses;

typedef struct tag_jms_HAL_GET_FSCALE_VALUE {
    OUT jmtUINT32               value;
    OUT jmtUINT32               minValue;
    OUT jmtUINT32               maxValue;
} j9_handle_j9m_obituarize;


typedef struct tag_jms_HAL_QUERY_RESET_TIME_STAMP {
    OUT jmtUINT64               timeStamp;
    OUT jmtUINT64               contextID;
} j9_handle_attribute_distortion;


typedef struct tag_jms_HAL_CREATE_NATIVE_FENCE {

    IN jmtUINT64                signal;


    OUT jmtINT32                fenceFD;

} j9_handle_j9menu_coruscated;


typedef struct tag_jms_HAL_WAIT_NATIVE_FENCE {

    IN jmtINT32                 fenceFD;


    IN jmtUINT32                timeout;
} j9_handle_j9ma_disuniform;


typedef struct tag_jms_HAL_SHBUF {
    j9_handle_j9_phytometry      command;


    IN OUT jmtUINT64            id;


    IN jmtUINT64                data;


    IN OUT jmtUINT32            bytes;
} j9_quarantine;


 typedef struct tag_jms_HAL_GET_GRAPHIC_BUFFER_FD {

    IN jmtUINT32                node[3];


    IN jmtUINT64                shBuf;


    IN jmtUINT64                signal;

    OUT jmtINT32                fd;
} j9_handle_j9mirror_sporicidal;

typedef struct tag_jms_HAL_VIDEO_MEMORY_METADATA {

    IN jmtUINT32                node;

    IN jmtUINT32                readback;

    INOUT jmtINT32              ts_fd;
    INOUT jmtUINT32             fc_enabled;
    INOUT jmtUINT32             fc_value;
    INOUT jmtUINT32             fc_value_upper;

    INOUT jmtUINT32             compressed;
    INOUT jmtUINT32             compress_format;
} j9_handle_j9mirror_commencing;

typedef struct tag_jms_HAL_VIDEO_MEMORY_PRIVDATA {

	IN jmtUINT32 node;
	IN jmtUINT32 readback;
	INOUT jmtUINT64 data;
	INOUT jmtUINT32 len;
} j9_handle_j9mirror_sticharion;


typedef struct tag_jms_HAL_GET_VIDEO_MEMORY_FD {
    IN jmtUINT32                handle;
    OUT jmtINT32                fd;
    IN jmtBOOL                  exported;
} j9_handle_j9menu_extractive;


typedef struct tag_jms_HAL_DESTROY_MMU {

    IN jmtUINT64                mmu;
    IN jmtUINT64                database;
    IN jmtUINT32                pid;
} j9mirror_outwriggle;


typedef struct tag_jms_HAL_WAIT_FENCE {
    IN jmtUINT32                handle;
    IN jmtUINT32                timeOut;
} j9maths_pasquiller;


typedef struct tag_jms_HAL_DEVICE_MUTEX {

    jmtBOOL                     isMutexLocked;
} j9_handle_misteacher;

#if J9_AMPELOPSIDIN

struct tag_jms_HAL_DEC200_TEST {
    j9_handle_j9m_monosilane     command;

    IN jmtUINT32                format;
    IN jmtUINT32                physBase;
    IN jmtUINT32                physTile;
    IN OUT jmtUINT32            flushDone;
} Dec200Test;
#endif

#if J9MATHS_CRYOHYDRIC

typedef struct tag_jms_HAL_DEC300_READ {
    jmtUINT32                   enable;
    jmtUINT32                   readId;
    jmtUINT32                   format;
    jmtUINT32                   strides[3];
    jmtUINT32                   is3D;
    jmtUINT32                   isMSAA;
    jmtUINT32                   clearValue;
    jmtUINT32                   isTPC;
    jmtUINT32                   isTPCCompressed;
    jmtUINT32                   surfAddrs[3];
    jmtUINT32                   tileAddrs[3];
} DEC300Read;


typedef struct tag_jms_HAL_DEC300_WRITE {
    jmtUINT32                   enable;
    jmtUINT32                   readId;
    jmtUINT32                   writeId;
    jmtUINT32                   format;
    jmtUINT32                   surfAddr;
    jmtUINT32                   tileAddr;
} DEC300Write;


typedef struct tag_jms_HAL_DEC300_FLUSH {
    IN jmtUINT8                 useless;
} DEC300Flush;


typedef struct tag_jms_HAL_DEC300_FLUSH_WAIT {
    IN jmtUINT32                done;
} DEC300FlushWait;
#endif

typedef struct tag_jms_HAL_SYNC_VIDEO_MEMORY {
	IN jmtUINT64 node;
	IN jmtUINT64 offset;
	IN jmtUINT64 bytes;
	IN jme_SYNC_MEMORY_DIRECTION dir;
} j9_handle_j9ma_cyaphenine;

typedef struct tag_jms_HAL_TRANSFER_RECT {
	jmtUINT32 node;
	jmtUINT32 offset;
	jmtUINT32 vstride;
	jmtUINT32 mstride;
	jmtUINT32 width;
	jmtUINT32 height;
	jmtUINT64 maddr;
	jmtUINT32 direction;
	jmtINT32 timeout;
} j9_handle__fustigated;

typedef struct tag_jms_HAL_QUERY_CFG {
	jmtUINT16 key;
	jmtUINT16 len;
	jmtUINT32 padding;
	jmtUINT64 data;
} j9_unletteredness;

typedef struct tag_jms_HAL_VIRT_INFO {
	OUT jmtUINT32 vmode;
	OUT jmtUINT32 vinfo;
} jms_HAL_VIRT_INFO;

typedef struct tag_jms_HAL_INTERFACE {

    j9_handle__presidente        command;


    j9_misapprehended            hardwareType;

#if JMD_ENABLE_MULTI_DEVICE_MANAGEMENT

    jmtUINT32                   devIndex;
#endif


    jmtUINT32                   coreIndex;


    j9_duopoly                   status;


    jmeENGINE                   engine;

	union {

		jmtBOOL ignoreTLS;


		jmtUINT32 pid;
	};


    IN jmtBOOL                  commitMutex;


    union _u {
        j9_aspidospermine                    ChipInfo;
        j9_artocarpeous                      Version;
        j9mirror_obituarize                  SetTimeOut;

        j9_handle_j9min_jaborandis           QueryVideoMemory;
        j9_handle_j9menu_bandcutter          QueryChipIdentity;
        j9_handle_j9min_spermarium           QueryChipOptions;
        j9_handle_j9maths_northlight         QueryChipFrequency;

        j9_handle_j9_attribute_rifleproof    AllocateNonPagedMemory;
        j9_handle_j9mirror_downloaded        FreeNonPagedMemory;

        j9_handle_j9min_attribute_quinopyrin AllocateLinearVideoMemory;
        j9_handle_j9m_hydriatric             WrapUserMemory;
        j9_handle_j9maths_preadapted         ReleaseVideoMemory;

        j9_handle_j9ma_misteacher               LockVideoMemory;
        j9_handle_j9menu_chronicled             UnlockVideoMemory;
        j9_handle_j9mirror_attribute_tongueless BottomHalfUnlockVideoMemory;

        j9_handle_j9menu_mutilating          ExportVideoMemory;
        j9_handle_j9ma_tangerines            NameVideoMemory;
        j9_handle_j9menu_preadapted          ImportVideoMemory;

        j9maths_spancelled                   MapMemory;
        j9_handle_disuniform                 UnmapMemory;

        j9_vagabonded                        Cache;

        j9_cheirognomy                       Attach;
        j9_euchologion                       Detach;

        j9_handle_tangerines                 Event;
        j9_aurocyanide                       Commit;
#if J9_COMPATRIOT
        j9_hexadactylism                     VGCommit;
#endif
        j9mirror_sluggishly                  CommitDone;

        j9mirror_anchylosed                  UserSignal;
        j9_spiritrompe                       Signal;

        j9maths_randannite                   WriteData;
        j9_handle__nutritious                ReadRegisterData;
        j9_handle_j_ctenoidian               WriteRegisterData;
        j9_handle_j9m_timeworker             APBAXIFEAccess;
        j9_handle_j9m_anchylosed             ReadRegisterDataEx;
        j9_handle_j9ma_beggarhood            WriteRegisterDataEx;
        j9_handle_j9maths_saporosity         SetPowerManagement;
        j9_handle_attribute_sporicidal       QueryPowerManagement;
        j9_handle__attribute_saporosity      ConfigPowerManagement;

        j9_handle_j9m_outwriggle             GetBaseAddress;

        j9_handle_j9maths_bandcutter         DebugLevelZone;

        jms_HAL_QUERY_CPU_FREQUENCY          QueryCPUFrequency;

        j9maths_fustigated                   DebugDump;
#ifdef VSIMULATOR_DEBUG
        j9_handle_j9mirror_distortion        UpdateDebugCallback;
        j9_handle_j9ma_churnstaff            ctxFrameWork;
#endif

        j9_contrantiscion                    TimeStamp;
        j9_interscribing                     Database;

        j9_handle_j_greenstuff               GetFrameInfo;

#if J9_COMPATRIOT
        j9_handle_j9maths_extractive         QueryCommandBuffer;
#endif




        j9_handle_j9m_lamenesses             SetFscaleValue;
        j9_handle_j9m_obituarize             GetFscaleValue;

        j9_handle_attribute_distortion       QueryResetTimeStamp;

        j9_handle_j9menu_coruscated          CreateNativeFence;
        j9_handle_j9ma_disuniform            WaitNativeFence;
        j9_quarantine                        ShBuf;
        j9_handle_j9mirror_sporicidal        GetGraphicBufferFd;
        j9_handle_j9mirror_commencing        SetVidMemMetadata;
		j9_handle_j9mirror_sticharion SetVidMemPrivdata;
        j9_handle_j9menu_extractive          GetVideoMemoryFd;

        j9mirror_outwriggle                  DestroyMmu;

        j9maths_pasquiller                   WaitFence;


        j9_handle_misteacher                 DeviceMutex;

#if J9_AMPELOPSIDIN
        j9mirror_granulated                  Dec200Test;
#endif

#if J9MATHS_CRYOHYDRIC
        j9mirror_exultantly                  DEC300Read;
        j9_handle_aphidicide                 DEC300Write;
        j9_handle_exultantly                 DEC300Flush;
        j9_handle_j9ma_fortemente            DEC300FlushWait;
#endif
		j9_handle_j9ma_cyaphenine SyncVideoMemory;
		j9_handle__fustigated TransferRect;
		j9_unletteredness QueryCfg;
		jms_HAL_VIRT_INFO VirtInfo;
	} u;
} j9_gastroparietal;

#if J9_MEDIGLACIAL
typedef struct tag_jms_HAL_PROFILER_INTERFACE {

    j9_handle__presidente        command;


    j9_misapprehended            hardwareType;
#if JMD_ENABLE_MULTI_DEVICE_MANAGEMENT

    jmtUINT32                   devIndex;
#endif


    jmtUINT32                   coreIndex;


    j9_duopoly                   status;


    jmeENGINE                   engine;


    jmtBOOL                     ignoreTLS;


    IN jmtBOOL                  commitMutex;


    union profiler_u {
        j9_handle_j9menu_northlight              GetProfileSetting;
        j9_handle_j9menu_saporosity              SetProfileSetting;
        j9_handle_j9maths_attribute_morbidness   SetProfilerRegisterClear;
        j9_handle_attribute_behaviour_leprologic RegisterProfileData_part1;
        j9_handle_attribute_behaviour_pathomania RegisterProfileData_part2;
        j9_handle_j9maths_mutilating             RegisterProfileData2D;
    } u;
} j9_handle_j9min_mogigraphy;
#endif


typedef struct tag_jms_STATE_DELTA_RECORD *jmsSTATE_DELTA_RECORD_PTR;
typedef struct tag_jms_STATE_DELTA_RECORD {

    jmtUINT                     address;


    jmtUINT32                   mask;


    jmtUINT32                   data;
} j9_handle_j_coruscated;


typedef struct tag_jms_STATE_DELTA {

    jmtUINT                     num;

    jmtUINT                     id;


    jmtINT                      refCount;


    jmtUINT                     elementCount;


    jmtUINT                     recordCount;


    jmtUINT64                   recordArray;

    jmtUINT64                   mapEntryID;
    jmtUINT                     mapEntryIDSize;

    jmtUINT64                   mapEntryIndex;


    jmtUINT64                   prev;
    jmtUINT64                   next;
} j9_revalidating;

typedef struct tag_jms_QUEUE {

    jmtUINT64                   next;


    j9_gastroparietal            iface;
} j9_steepy;


typedef struct tag_jms_QUEUE_CHUNK {
	struct tag_jms_QUEUE_CHUNK *next;

    j9_steepy                    record[16];
} j9_pathognostic;

#ifdef __cplusplus
}
#endif

#endif


