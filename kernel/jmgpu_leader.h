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



#ifndef _jmgpu_hal_kenrel_mmu_h_
#define _jmgpu_hal_kenrel_mmu_h_

#ifndef EMULATOR
#include <linux/hash.h>
#include <linux/list.h>
#endif

#if defined(EMULATOR) && defined(_WIN32) && !defined(VSIMULATOR_DEBUG)
# include "jmDefines.h"
# if defined(JMD_VIRTUAL_ADDRESS_WIDTH) && (JMD_VIRTUAL_ADDRESS_WIDTH == 40)
#  define JMD_ENABLE_40BIT_VA        1
# endif
#endif

#ifndef JMD_ENABLE_40BIT_VA
# define JMD_ENABLE_40BIT_VA         0
#endif
#define JMD_4G_VA_FM_SIZE            0x40000000

#ifndef JMD_DEBUG_MMU_SWITCH
#define JMD_DEBUG_MMU_SWITCH         0
#endif

#ifndef JMD_MMU_DESC_SIZE
#define JMD_MMU_DESC_SIZE            (1 << 16)
#endif


#if J9_HANDLE__CONFICIENT

# define J9MATHS_ANTHRAMINE       24
# define JMD_MMU_VA_BITS          32

#else

# define J9MATHS_ANTHRAMINE       22
# define JMD_MMU_VA_BITS          32
#endif

#if JMD_ENABLE_40BIT_VA
# undef J9MATHS_ANTHRAMINE
# undef JMD_MMU_VA_BITS
# define J9MATHS_ANTHRAMINE       30
# define JMD_MMU_VA_BITS          40
#endif

#define J9_HANDLE__OVERFLOWED        12
#define J9_HANDLE_J_PODIATRIES       16
#define J9_HANDLE__PREPROMISE        20
#define J9_HANDLE_J_METROCARAT       24

#define J9_ETHYLTHIOETHER            (JMD_MMU_VA_BITS - J9MATHS_ANTHRAMINE)
#define J9_HANDLE_INDURATION         J9_HANDLE__OVERFLOWED
#define J9_HANDLE_CLOCKWORKS         (JMD_MMU_VA_BITS - J9_ETHYLTHIOETHER - J9_HANDLE_INDURATION)
#define J9_HANDLE__ENRAVISHED        J9_HANDLE_J_PODIATRIES
#define J9_HANDLE__EVENTUATED        (JMD_MMU_VA_BITS - J9_ETHYLTHIOETHER - J9_HANDLE__ENRAVISHED)
#define J9_HANDLE_REDOUBTING         J9_HANDLE__PREPROMISE
#define J9_HANDLE_OVERFLOWED         (JMD_MMU_VA_BITS - J9_ETHYLTHIOETHER - J9_HANDLE_REDOUBTING)
#define J9_HANDLE__PREDECREED        J9_HANDLE_J_METROCARAT

#if JMD_ENABLE_40BIT_VA
# define J9_HANDLE__DAMFOOLISH    (JMD_MMU_VA_BITS - J9_ETHYLTHIOETHER - J9_HANDLE__PREDECREED)
#else
# define J9_HANDLE__DAMFOOLISH    4
#endif

#if defined(EMULATOR) && JMD_ENABLE_40BIT_VA
# define J9_HANDLE_J_MAGNETISED   40
#else
# define J9_HANDLE_J_MAGNETISED   (1 << J9_ETHYLTHIOETHER)
#endif
#define J9_TRICHOBACTERIA            (J9_HANDLE_J_MAGNETISED << 2)
#define J9_HANDLE_J9MA_PIPEFISHES    (1 << J9_HANDLE_CLOCKWORKS)
#define J9_HANDLE_OVERSCREAM         (J9_HANDLE_J9MA_PIPEFISHES << 2)
#define J9_HANDLE_PREPROMISE         (1 << J9_HANDLE__OVERFLOWED)
#define J9_HANDLE_J9MIN_ARECACEOUS   (1 << J9_HANDLE__EVENTUATED)
#define J9_HANDLE__CLOCKWORKS        (J9_HANDLE_J9MIN_ARECACEOUS << 2)
#define J9_HANDLE__EMMENOLOGY        (1 << J9_HANDLE_J_PODIATRIES)
#define J9_HANDLE_J9MA_ARROWSTONE    (1 << J9_HANDLE_OVERFLOWED)
#define J9_HANDLE_NONNITROUS         (J9_HANDLE_J9MA_ARROWSTONE << 2)
#define J9_HANDLE_DAMFOOLISH         (1 << J9_HANDLE__PREPROMISE)
#define J9_HANDLE_J9MIN_DESOLATELY   (1 << J9_HANDLE__DAMFOOLISH)
#define J9_HANDLE__EPIZOOLOGY        (J9_HANDLE_J9MIN_DESOLATELY << 2)
#define J9_HANDLE__ARTFULNESS        (1 << J9_HANDLE_J_METROCARAT)

#if JMD_ENABLE_40BIT_VA
# define JMD_MMU_VA_MASK          ((1ULL << JMD_MMU_VA_BITS) - 1)
# define J9_AMPHIBOLOGICAL        (~((1ULL << J9MATHS_ANTHRAMINE) - 1) & JMD_MMU_VA_MASK)

# define J9_HANDLE_ENDOCRITIC                                                                    \
     (((~0ULL << J9_HANDLE__OVERFLOWED) ^ J9_AMPHIBOLOGICAL) & JMD_MMU_VA_MASK)
# define J9_HANDLE__NONNITROUS                                                                   \
     (((~((1ULL << J9_HANDLE_J_PODIATRIES) - 1)) ^ J9_AMPHIBOLOGICAL) & JMD_MMU_VA_MASK)
# define J9_HANDLE_EVENTUATED                                                                    \
     (((~((1ULL << J9_HANDLE__PREPROMISE) - 1)) ^ J9_AMPHIBOLOGICAL) & JMD_MMU_VA_MASK)
# define J9_HANDLE__INDURATION                                                                   \
     (((~((1ULL << J9_HANDLE_J_METROCARAT) - 1)) ^ J9_AMPHIBOLOGICAL) & JMD_MMU_VA_MASK)
#else
# define J9_AMPHIBOLOGICAL        (~((1U << J9MATHS_ANTHRAMINE) - 1))
# define J9_HANDLE_ENDOCRITIC     ((~0U << J9_HANDLE__OVERFLOWED) ^ J9_AMPHIBOLOGICAL)
# define J9_HANDLE__NONNITROUS    ((~((1U << J9_HANDLE_J_PODIATRIES) - 1)) ^ J9_AMPHIBOLOGICAL)
# define J9_HANDLE_EVENTUATED     ((~((1U << J9_HANDLE__PREPROMISE) - 1)) ^ J9_AMPHIBOLOGICAL)
# define J9_HANDLE__INDURATION    0x0F000000
#endif

#define J9_HANDLE_EPIZOOLOGY         (J9_HANDLE_PREPROMISE - 1)
#define J9_HANDLE__REDOUBTING        (J9_HANDLE__EMMENOLOGY - 1)
#define J9_HANDLE_EMMENOLOGY         (J9_HANDLE_DAMFOOLISH - 1)
#define J9_HANDLE__SCREWSTOCK        (J9_HANDLE__ARTFULNESS - 1)


#define J9_HANDLE_J_PREBENDATE       (JMD_MMU_VA_BITS - J9_ETHYLTHIOETHER - J9_HANDLE_CLOCKWORKS)
#define J9_HANDLE_J_SUBFIGURES       ((1U << J9_HANDLE_J_PREBENDATE) - 1)
#define J9_HANDLE_J9_INSURRECTO      (JMD_MMU_VA_BITS - J9_ETHYLTHIOETHER - J9_HANDLE__EVENTUATED)
#define J9_HANDLE_J9_PREBENDATE      ((1U << J9_HANDLE_J9_INSURRECTO) - 1)
#define J9_HANDLE_J_TRINKETING       (JMD_MMU_VA_BITS - J9_ETHYLTHIOETHER - J9_HANDLE_OVERFLOWED)
#define J9_HANDLE_J_INSURRECTO       ((1U << J9_HANDLE_J_TRINKETING) - 1)
#define J9_HANDLE_J9_ACTIVATION      (JMD_MMU_VA_BITS - J9_ETHYLTHIOETHER)
#define J9_HANDLE_J9_TRINKETING      ((1U << J9_HANDLE_J9_ACTIVATION) - 1)

#define J9_HANDLE_J9MIRROR_SPERMARIUM 6
#define J9_HANDLE_J9MATHS_FUSTIGATED  (~((1U << J9_HANDLE_J9MIRROR_SPERMARIUM) - 1))

#define J9_HANDLE_ENRAVISHED         0x00000001
#define J9_HANDLE_J_ACTIVATION       0x00000002
#define J9_HANDLE_ARTFULNESS         (0 << 2)
#define J9_HANDLE__ANCHORITIC        (1 << 2)
#define J9_HANDLE_SCREWSTOCK         (2 << 2)
#define J9_HANDLE__SEVILLANAS        (3 << 2)

#define J9_HANDLE_PLAYSCRIPT         0x00000001
#define J9_HANDLE_J_CIRCUITIES       0x00000002
#define J9_HANDLE_J_MONOSILANE       0x00000004

#define J9_NITROPRUSSIDE             (1 << 20)
#define J9_SEMIGLOBULARLY            20
#define JMD_4K_PAGE_SIZE             (1 << 12)

#define J9_FLAMIEST                  0x100000000
#define JMD_VA_RESERVED_SIZE         (16 << 20)


#define J9_CONCLUSIVENESS            (4 << 20)

#define J9_PRESUBSTITUTED            (4 << 10)

#define J9_EXPOUNDABLE(x)            ((x) & 0xF0)

#define J9_NONREMOVABLE(x)           (((x) & 0xFFFFFF00) >> 8)

#define J9MATHS_NONSERVILE           0


#define J9_ANDRODIOECISM             (128 << 10)

#define J9_HANDLE__SPAWNEATER        J9_PERFECTIONMENT

typedef enum _jme_MMU_TYPE {
    J9_SIMOLEONS   = (0 << 4),
    J9_UNCULTIVATE = (1 << 4),
    J9_DRIVEWAYS   = (2 << 4),
} j9_unaborted;

typedef struct _jms_MMU_STLB_CHUNK *jmsMMU_STLB_CHUNK_PTR;

typedef struct _jms_MMU_STLB_CHUNK {
    jmkVIDMEM_NODE        videoMem;
    jmtUINT32_PTR         logical;
    jmtSIZE_T             size;
    jmtPHYS_ADDR_T        physBase;
    jmtSIZE_T             pageCount;
    jmtUINT32             mtlbIndex;
    jmtUINT32             mtlbEntryNum;
    jmsMMU_STLB_CHUNK_PTR next;
} j9maths_tranquilly;

typedef struct _jms_FreeSpaceNode *jmsFreeSpaceNode_PTR;
typedef struct _jms_FreeSpaceNode {
    jmtUINT32 start;
    jmtUINT32 entries;
} j9_cheimatophobia;

#if J9_ERRONEOUSLY

# define j9_monarchistic(pageEntry, entryValue) \
        (*(jmtUINT32_PTR)(pageEntry) = J9_BALANCED((jmtUINT32)(entryValue)))

# define j9_peroxidized(pageEntry) \
        J9_BALANCED(*(jmtUINT32_PTR)(pageEntry))

#else

# define j9_monarchistic(pageEntry, entryValue) \
        (*(jmtUINT32_PTR)(pageEntry) = (jmtUINT32)(entryValue))

# define j9_peroxidized(pageEntry) \
        (*(jmtUINT32_PTR)(pageEntry))

#endif

typedef enum _jme_MMU_INIT_MODE {
    J9_HANDLE__TONSILITIS,
    J9_HANDLE__DEVORATION,
} j9_impartibilibly;

typedef struct _jms_ADDRESS_AREA *jmsADDRESS_AREA_PTR;
typedef struct _jms_ADDRESS_AREA {

    jmtSIZE_T                   stlbSize;
    jmkVIDMEM_NODE              stlbVideoMem;
    jmtUINT32_PTR               stlbLogical;
    jmtUINT32                   stlbEntries;

    jmtPHYS_ADDR_T              stlbPhysical;


    jmtUINT32                   heapList;
    jmtBOOL                     freeNodes;

    j9_fameworthy                areaType;

    jmtUINT32                   mappingStart;
    jmtUINT32                   mappingEnd;

    jmtUINT32_PTR               mapLogical;

    jmtUINT32                   usedIndex;
} j9_algebrization;


struct tag_jmk_MMU {

    j9_scalpra                   object;


    jmk_OS                       os;


    jmk_HARDWARE                 hardware;


    jmtPOINTER                  pageTableMutex;


    jmtSIZE_T                   mtlbSize;
    jmkVIDMEM_NODE              mtlbVideoMem;
    jmtUINT32_PTR               mtlbLogical;
    jmtUINT32                   mtlbEntries;

    jmtPHYS_ADDR_T              mtlbPhysical;


    j9_phpht                     pool;

    jmtPOINTER                  staticSTLB;
    jmtBOOL                     enabled;

    jmtSIZE_T                   safePageSize;
    jmkVIDMEM_NODE              safePageVideoMem;
    jmtPOINTER                  safePageLogical;
    jmtADDRESS                  safeAddress;

    jmtPHYS_ADDR_T              safePagePhysical;


    jmtUINT32                   gpuPhysicalRangeCount;
    j9_handle_j_tetrameter       gpuPhysicalRanges[J9_HANDLE_J9MIN_LIONIZABLE];


    jmtUINT32                   gpuAddressRangeCount;
    j9_handle_j_tetrameter       gpuAddressRanges[J9_HANDLE_J9MIN_LIONIZABLE];


    j9_nazeranna                 hardwareList;

    struct tag_jmk_QUEUE         recentFreedAddresses;

    j9_algebrization             dynamicArea1M;
    j9_algebrization             dynamicArea4K;
    j9_algebrization             dynamicLowArea1M;
    j9_algebrization             dynamicLowArea4K;
    j9_algebrization             secureArea;

    jmtBOOL                     dynamicAreaSetuped;

    jmtBOOL                     sRAMMapped;

    jmtADDRESS                  contiguousBaseAddress;
    jmtADDRESS                  externalBaseAddress;
    jmtADDRESS                  internalBaseAddress;
    jmtADDRESS                  exclusiveBaseAddress;

    j9_impartibilibly            initMode;
    jmtBOOL                     pageTableOver4G;


    jmtBOOL                     flatMapping;

    j9_unalliedly                flatMappingMode;


    jmtBOOL                     stlbAllocated[J9_HANDLE_J9MIN_DESOLATELY];


    jmtSIZE_T                   reserveRangeSize;
#ifdef EMULATOR
    j9_nazeranna                 nodeList;
#else
    struct  hlist_head          hash_table[256];
#endif
    jmtPOINTER                  nodeListMutex;

    jmtUINT32                   descIndex;
    jmtUINT32                   pid;
};

j9_duopoly
jmkMMU_GetPageEntry(jmk_MMU Mmu, j9_unalliedly PageType, jmtADDRESS Address,
		jmtUINT32_PTR *PageTable);

j9_duopoly
jmkMMU_SetupSRAM(jmk_MMU Mmu, jmk_HARDWARE Hardware, jmkDEVICE Device);

j9_duopoly
jmkMMU_SetupDynamicSpace(jmk_MMU Mmu);

void
jmkMMU_DumpRecentFreedAddress(jmk_MMU Mmu);

j9_duopoly
jmkMMU_DestroyProcessMMU(jmk_MMU Mmu);

j9_duopoly
jmkMMU_ConstructProcessMMU(jmk_KERNEL Kernel, jmtUINT32 ProcessID, jmk_MMU *Mmu);

j9_duopoly
jmkMMU_CopyDynamicAreas(jmk_KERNEL Kernel, jmk_MMU dstMMU);

j9_duopoly
jmkMMU_SwitchMtlb(jmk_MMU dstMMU, jmk_MMU srcMMU);

j9_duopoly
jmkMMU_AttachNode(jmk_MMU Mmu, jmuVIDMEM_NODE_PTR Node);

j9_duopoly
jmkMMU_DetachNode(jmk_MMU Mmu, jmuVIDMEM_NODE_PTR Node);

j9_duopoly
jmkMMU_DestroyMmuCopy(jmk_MMU Mmu);

j9_duopoly
jmkMMU_ConstructMmuCopy(jmk_KERNEL Kernel, jmk_MMU *MmuCopy);

#endif


