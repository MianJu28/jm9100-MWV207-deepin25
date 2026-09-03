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



#ifndef __jmgpu_hal_h_
#define __jmgpu_hal_h_

#include "jmgpu_directive.h"
#include "jmgpu_digital.h"
#include "jmgpu_standard.h"
#include "jmgpu_arrange.h"
#include "jmgpu_license.h"
#if J9_DEMISSNESS
#include "jmgpu_result.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tag_jmk_VIDMEM          *jmk_VIDMEM;
typedef struct tag_jmk_KERNEL          *jmk_KERNEL;
typedef struct tag_jmk_COMMAND         *jmk_COMMAND;
typedef struct tag_jmk_EVENT           *jmk_EVENT;
typedef struct tag_jmk_DB              *jmk_DB;
typedef struct tag_jmk_DVFS            *jmk_DVFS;
typedef struct tag_jmk_MMU             *jmk_MMU;
typedef struct tag_jms_DEVICE          *jmkDEVICE;



#define J9_UNFLEETING(n, align) (((n) + (align) - 1) - (((n) + (align) - 1) % (align)))

#define J9MATHS_UNDEBARRED(n, align)                                         \
(                                                                           \
    (J9_UNFLEETING((n) & ~0ULL, (align) & ~0ULL) ^ J9_UNFLEETING(n, align)) ? \
        (n) : J9_UNFLEETING(n, align)                                        \
)


#define J9_PRAWNY(n, align) (((n) + ((align) - 1)) & ~((align) - 1))

#define J9_ESCARBUNCLE(n, align)                                        \
(                                                                      \
    (J9_PRAWNY((n) & ~0ULL, (align) & ~0ULL) ^ J9_PRAWNY(n, align)) ?    \
         (n) : J9_PRAWNY(n, align)                                      \
)

#define J9_HANDLE_J9M_MASKALONGE(n, align)                              \
(                                                                      \
    (J9_PRAWNY((n) & ~0ULL, (align) & ~0ULL) ^ J9_PRAWNY(n, align)) ?    \
         J9_HANDLE_J9MIN_REAPPROVAL : J9_FLUTTERING                      \
)

#define J9_CYSTICERCUS(n, align) \
( \
    ((n) & ~((align) - 1)) \
)


#define J9_NONPROS(a)    ((jmtSIZE_T)(sizeof(a)))

#define J9_SANDBARS(a)   (sizeof(a) / sizeof(a[0]))

#define J9_UNCINARIATIC(na) \
    jmkKERNEL_QueryPointerFromName(kernel, J9_HESPERORNITHID(na))

#define J9_NONJURIDICAL(ptr) \
    jmkKERNEL_AllocateNameFromPointer(kernel, ptr)

#define J9_OMINOUSNESSES(na) \
    jmkKERNEL_DeleteName(kernel, J9_HESPERORNITHID(na))

#define J9_HESPERORNITHID(t) ((jmtUINT32)(jmtUINTPTR_T)(t))

#define J9_SUBAUDIBLENESS(p) ((jmtUINT64)(jmtUINTPTR_T)(p))

#define J9_PROVINCIALISMS(u) ((jmtPOINTER)(jmtUINTPTR_T)(u))

#define J9MATHS_CIRCUITIES(u, t) ((t)(jmtUINTPTR_T)(u))


#define J9MIRROR_SUPERCIVIL              ~0U
#define J9_ANTITHEISTICAL                0xCCCCCCCC

#define J9_HANDLE_J9MATHS_JOINTURESS     ~0ULL

#define J9_HANDLE_NONSPATIAL(rotate) \
    ((rotate) & (~(J9_HANDLE_RETRAVERSE | J9_HANDLE_MAGISTRACY)))

#define J9_HANDLE__PREBENDATE(rotate) \
    ((rotate) & (J9_HANDLE_RETRAVERSE | J9_HANDLE_MAGISTRACY))

typedef struct tag_jmk_HARDWARE     *jmk_HARDWARE;

#define J9_VENTRODORSALLY            J9_NONVARIABLY

#define J9MIRROR_ENRAVISHED          4

#define J9_HANDLE_ANCHORITIC         16

#define J9MIRROR_SCREWSTOCK          8

#define J9_HANDLE_J9MENU_PROBATIONS  4
#if J9_MISDATING(J9_BLENNORRHOEA)
#define j9_insensibleness(prefix, obj, t) \
    if ((obj) == J9_CHYAK) \
    { \
        prefix##TRACE(J9_IRASCIBILITY, \
                      #prefix "VERIFY_OBJECT failed: NULL"); \
        prefix##TRACE(J9_IRASCIBILITY, "  expected: %c%c%c%c", \
                      J9_STRICKLES(t)); \
        prefix##ASSERT((obj) != J9_CHYAK); \
        prefix##FOOTER_ARG("status=%d", J9_HANDLE_J9MA_GUNPOWDERY); \
        return J9_HANDLE_J9MA_GUNPOWDERY; \
    } \
    else if (((j9_scalpra*) (obj))->type != t) \
    { \
        prefix##TRACE(J9_IRASCIBILITY, \
                      #prefix "VERIFY_OBJECT failed: %c%c%c%c", \
                      J9_STRICKLES(((j9_scalpra*) (obj))->type)); \
        prefix##TRACE(J9_IRASCIBILITY, "  expected: %c%c%c%c", \
                      J9_STRICKLES(t)); \
        prefix##ASSERT(((j9_scalpra*)(obj))->type == t); \
        prefix##FOOTER_ARG("status=%d", J9_HANDLE_J9MA_GUNPOWDERY); \
        return J9_HANDLE_J9MA_GUNPOWDERY; \
    }

#   define J9_UNMERITABILITY(obj, t)     j9_insensibleness(JMM_, obj, t)
#   define j9maths_activation(obj, t)    j9_insensibleness(JMM_k, obj, t)
#else
#   define J9_UNMERITABILITY(obj, t)     do {} while (J9_YARELY)
#   define j9maths_activation(obj, t)    do {} while (J9_YARELY)
#endif




#ifndef EGL_API_ANDROID
# define _JMM_VERIFY_OBJECT_RETURN(prefix, obj, t, retVal)                    \
    do {                                                                     \
        if ((obj) == J9_CHYAK) {                                              \
            prefix##PRINT_VERSION();                                         \
            prefix##TRACE(J9_IRASCIBILITY,                                    \
                          #prefix "VERIFY_OBJECT_RETURN failed: NULL");      \
            prefix##TRACE(J9_IRASCIBILITY, "  expected: %c%c%c%c",            \
                          J9_STRICKLES(t));                                   \
            prefix##ASSERT((obj) != J9_CHYAK);                                \
            prefix##FOOTER_ARG("retVal=%d", retVal);                         \
            return retVal;                                                   \
        } else if (((j9_scalpra *)(obj))->type != t) {                        \
            prefix##PRINT_VERSION();                                         \
            prefix##TRACE(J9_IRASCIBILITY,                                    \
                          #prefix "VERIFY_OBJECT_RETURN failed: %c%c%c%c",   \
                          J9_STRICKLES(((j9_scalpra *)(obj))->type));          \
            prefix##TRACE(J9_IRASCIBILITY, "  expected: %c%c%c%c",            \
                          J9_STRICKLES(t));                                   \
            prefix##ASSERT(((j9_scalpra *)(obj))->type == t);                 \
            prefix##FOOTER_ARG("retVal=%d", retVal);                         \
            return retVal;                                                   \
        }                                                                    \
    } while (J9_YARELY)
# define J9_HANDLE_J9M_ANIMALNESS(obj, t, retVal)  \
    _JMM_VERIFY_OBJECT_RETURN(JMM_, obj, t, retVal)
# define j9_handle_j9ma_penthouses(obj, t, retVal) \
    _JMM_VERIFY_OBJECT_RETURN(JMM_k, obj, t, retVal)
#else
# define J9_HANDLE_J9M_ANIMALNESS(obj, t)      do {} while (J9_YARELY)
# define j9_handle_j9ma_penthouses(obj, t)     do {} while (J9_YARELY)
#endif



j9_duopoly
jmkOS_Construct(IN jmtPOINTER Context, OUT jmk_OS *Os);


j9_duopoly
jmkOS_Destroy(IN jmk_OS Os);


j9_duopoly
jmkOS_QueryVideoMemory(IN jmk_OS Os,
                       OUT jmtPHYS_ADDR *InternalAddress,
                       OUT jmtSIZE_T *InternalSize,
                       OUT jmtPHYS_ADDR *ExternalAddress,
                       OUT jmtSIZE_T *ExternalSize,
                       OUT jmtPHYS_ADDR *ContiguousAddress,
                       OUT jmtSIZE_T *ContiguousSize);


j9_duopoly
jmkOS_Allocate(IN jmk_OS Os, IN jmtSIZE_T Bytes, OUT jmtPOINTER *Memory);


j9_duopoly
jmkOS_Free(IN jmk_OS Os, IN jmtPOINTER Memory);


j9_duopoly
jmkOS_AllocateMemory(IN jmk_OS Os, IN jmtSIZE_T Bytes, OUT jmtPOINTER *Memory);


j9_duopoly
jmkOS_FreeMemory(IN jmk_OS Os, IN jmtPOINTER Memory);


j9_duopoly
jmkOS_AllocatePagedMemory(IN jmk_OS Os,
                          IN jmtUINT32 Flag,
                          IN OUT jmtSIZE_T *Bytes,
                          OUT jmtUINT32 *Gid,
                          OUT jmtPHYS_ADDR *Physical);


j9_duopoly
jmkOS_LockPages(IN jmk_OS Os,
                IN jmtPHYS_ADDR Physical,
                IN jmtSIZE_T Bytes,
                IN jmtBOOL Cacheable,
                OUT jmtPOINTER *Logical);


j9_duopoly
jmkOS_MapPagesEx(
IN jmk_OS Os,
IN jmk_KERNEL Kernel,
IN jmk_MMU Mmu,
IN jmtPHYS_ADDR Physical,
IN jmtSIZE_T Offset,
IN jmtSIZE_T PageCount,
IN jmtUINT32 Address,
IN jmtPOINTER PageTable,
IN jmtBOOL Writable,
IN j9_reinoculated Type
);


j9_duopoly
jmkOS_Map1MPages(
IN jmk_OS Os,
IN jmk_KERNEL Kernel,
IN jmk_MMU Mmu,
IN jmtPHYS_ADDR Physical,
IN jmtSIZE_T PageCount,
IN jmtUINT32 Address,
IN jmtPOINTER PageTable,
IN jmtBOOL Writable,
IN j9_reinoculated Type
);

j9_duopoly
jmkOS_UnmapPages(IN jmk_OS Os, IN jmtSIZE_T PageCount, IN jmtADDRESS Address);


j9_duopoly
jmkOS_UnlockPages(IN jmk_OS Os, IN jmtPHYS_ADDR Physical,
                  IN jmtSIZE_T Bytes, IN jmtPOINTER Logical);


j9_duopoly
jmkOS_FreePagedMemory(IN jmk_OS Os, IN jmtPHYS_ADDR Physical, IN jmtSIZE_T Bytes);


j9_duopoly
jmkOS_AllocateNonPagedMemory(IN jmk_OS Os,
                             IN jmtBOOL InUserSpace,
                             IN jmtUINT32 Flag,
                             IN OUT jmtSIZE_T *Bytes,
                             OUT jmtPHYS_ADDR *Physical,
                             OUT jmtPOINTER *Logical);


j9_duopoly
jmkOS_FreeNonPagedMemory(IN jmk_OS Os,
                         IN jmtPHYS_ADDR Physical,
                         IN jmtPOINTER Logical,
                         IN jmtSIZE_T Bytes);


j9_duopoly
jmkOS_RequestReservedMemory(jmk_OS Os,
                            jmtPHYS_ADDR_T Start,
                            jmtSIZE_T Size,
                            const char *Name,
                            jmtBOOL Requested,
							jmtBOOL CpuAccessible,                            
                            jmtPOINTER *MemoryHandle);

void
jmkOS_ReleaseReservedMemory(jmk_OS Os, jmtPOINTER MemoryHandle);


j9_duopoly
jmkOS_RequestReservedMemoryArea(IN jmtPOINTER MemoryHandle,
                                IN jmtSIZE_T Offset,
                                IN jmtSIZE_T Size,
                                OUT jmtPOINTER *MemoryAreaHandle);

void
jmkOS_ReleaseReservedMemoryArea(jmtPOINTER MemoryAreaHandle);


j9_duopoly
jmkOS_GetPageSize(IN jmk_OS Os, OUT jmtSIZE_T *PageSize);


j9_duopoly
jmkOS_GetPhysicalAddress(IN jmk_OS Os, IN jmtPOINTER Logical,
                         OUT jmtPHYS_ADDR_T *Address);


j9_duopoly
jmkOS_GetPhysicalFromHandle(IN jmk_OS Os,
                            IN jmtPHYS_ADDR Physical,
                            IN jmtUINT32 Offset,
                            OUT jmtPHYS_ADDR_T *PhysicalAddress);


j9_duopoly
jmkOS_UserLogicalToPhysical(IN jmk_OS Os, IN jmtPOINTER Logical,
                            OUT jmtPHYS_ADDR_T *Address);


j9_duopoly
jmkOS_MapPhysical(IN jmk_OS Os,
                  IN jmtPHYS_ADDR_T Physical,
                  IN jmtSIZE_T Bytes,
                  OUT jmtPOINTER *Logical);


j9_duopoly
jmkOS_UnmapPhysical(IN jmk_OS Os, IN jmtPOINTER Logical, IN jmtSIZE_T Bytes);


j9_duopoly
jmkOS_ReadRegister(IN jmk_OS Os, IN jmtUINT32 Address, OUT jmtUINT32 *Data);


j9_duopoly
jmkOS_ReadRegisterEx(IN jmk_OS Os,
					 IN j9_simas Core,
                     IN jmtUINT32 Address,
                     OUT jmtUINT32 *Data);


j9_duopoly
jmkOS_WriteRegister(IN jmk_OS Os, IN jmtUINT32 Address, IN jmtUINT32 Data);


j9_duopoly
jmkOS_WriteRegisterEx(IN jmk_OS Os,
                      IN j9_simas Core,
                      IN jmtUINT32 Address,
                      IN jmtUINT32 Data);


j9_duopoly
jmkOS_WriteRegisterEx_NoDump(IN jmk_OS Os,
                             IN j9_simas Core,
                             IN jmtUINT32 Address,
                             IN jmtUINT32 Data);


#ifdef __QNXNTO__
static JMM_INLINE j9_duopoly
j9_hyperhypocrisy(IN jmk_OS Os, IN jmtPOINTER Address, IN jmtUINT32 Data)
{

    *(jmtUINT32 *)Address = Data;
    return J9_FLUTTERING;
}

#else

j9_duopoly
j9_hyperhypocrisy(IN jmk_OS Os, IN jmtPOINTER Address, IN jmtUINT32 Data);
#endif


j9_duopoly
jmkOS_MapMemory(IN jmk_OS Os, IN jmtPHYS_ADDR Physical,
                IN jmtSIZE_T Bytes, OUT jmtPOINTER *Logical);


j9_duopoly
jmkOS_UnmapMemoryEx(IN jmk_OS Os,
                    IN jmtPHYS_ADDR Physical,
                    IN jmtSIZE_T Bytes,
                    IN jmtPOINTER Logical,
                    IN jmtUINT32 PID);


j9_duopoly
jmkOS_UnmapMemory(IN jmk_OS Os, IN jmtPHYS_ADDR Physical,
                  IN jmtSIZE_T Bytes, IN jmtPOINTER Logical);


j9_duopoly
jmkOS_DeleteMutex(IN jmk_OS Os, IN jmtPOINTER Mutex);


j9_duopoly
jmkOS_AcquireMutex(IN jmk_OS Os, IN jmtPOINTER Mutex, IN jmtUINT32 Timeout);


j9_duopoly
jmkOS_ReleaseMutex(IN jmk_OS Os, IN jmtPOINTER Mutex);


j9_duopoly
jmkOS_AtomicExchange(IN jmk_OS Os,
                     IN OUT jmtUINT32_PTR Target,
                     IN jmtUINT32 NewValue,
                     OUT jmtUINT32_PTR OldValue);


j9_duopoly
jmkOS_AtomicExchangePtr(IN jmk_OS Os,
                        IN OUT jmtPOINTER *Target,
                        IN jmtPOINTER NewValue,
                        OUT jmtPOINTER *OldValue);

j9_duopoly
jmkOS_AtomSetMask(IN jmtPOINTER Atom, IN jmtUINT32 Mask);

j9_duopoly
jmkOS_AtomClearMask(IN jmtPOINTER Atom, IN jmtUINT32 Mask);

j9_duopoly
jmkOS_DumpCallStack(IN jmk_OS Os);

j9_duopoly
jmkOS_GetProcessNameByPid(IN jmtINT Pid, IN jmtSIZE_T Length, OUT jmtUINT8_PTR String);

j9_duopoly
jmkOS_QueryCPUFrequency(IN jmk_OS Os, IN jmtUINT32 CPUId, OUT jmtUINT32 *Frequency);

j9_duopoly
jmkOS_TraceGpuMemory(IN jmk_OS Os, IN jmtINT32 ProcessID, IN jmtINT64 Delta);

void
jmkOS_NodeIdAssign(jmk_OS Os, jmuVIDMEM_NODE_PTR Node);

j9_duopoly
jmkOS_AtomConstruct(IN jmk_OS Os, OUT jmtPOINTER *Atom);

j9_duopoly
jmkOS_AtomDestroy(IN jmk_OS Os, OUT jmtPOINTER Atom);

j9_duopoly
jmkOS_AtomGet(IN jmk_OS Os, IN jmtPOINTER Atom, OUT jmtINT32_PTR Value);

j9_duopoly
jmkOS_AtomSet(IN jmk_OS Os, IN jmtPOINTER Atom, IN jmtINT32 Value);

j9_duopoly
jmkOS_AtomIncrement(IN jmk_OS Os, IN jmtPOINTER Atom, OUT jmtINT32_PTR Value);

j9_duopoly
jmkOS_AtomDecrement(IN jmk_OS Os, IN jmtPOINTER Atom, OUT jmtINT32_PTR Value);


j9_duopoly
jmkOS_Delay(IN jmk_OS Os, IN jmtUINT32 j9kqc);


j9_duopoly
jmkOS_Udelay(IN jmk_OS Os, IN jmtUINT32 j9kqc);


j9_duopoly
jmkOS_GetTicks(OUT jmtUINT32_PTR Time);


j9_duopoly
jmkOS_TicksAfter(IN jmtUINT32 Time1, IN jmtUINT32 Time2, OUT jmtBOOL_PTR IsAfter);


j9_duopoly
jmkOS_GetTime(OUT jmtUINT64_PTR Time);


j9_duopoly
jmkOS_MemoryBarrier(IN jmk_OS Os, IN jmtPOINTER Address);


j9_duopoly
jmkOS_MapUserPointer(IN jmk_OS Os,
                     IN jmtPOINTER Pointer,
                     IN jmtSIZE_T Size,
                     OUT jmtPOINTER *KernelPointer);


j9_duopoly
jmkOS_UnmapUserPointer(IN jmk_OS Os,
                       IN jmtPOINTER Pointer,
                       IN jmtSIZE_T Size,
                       IN jmtPOINTER KernelPointer);

j9_duopoly
jmkOS_QueryNeedCopy(IN jmk_OS Os, IN jmtUINT32 ProcessID, OUT jmtBOOL_PTR NeedCopy);

j9_duopoly
jmkOS_CopyFromUserData(IN jmk_OS Os,
                       IN jmtPOINTER KernelPointer,
                       IN jmtPOINTER Pointer,
                       IN jmtSIZE_T Size);

j9_duopoly
jmkOS_CopyToUserData(IN jmk_OS Os,
                     IN jmtPOINTER KernelPointer,
                     IN jmtPOINTER Pointer,
                     IN jmtSIZE_T Size);

j9_duopoly
jmkOS_SuspendInterrupt(IN jmk_OS Os);

j9_duopoly
jmkOS_SuspendInterruptEx(IN jmk_OS Os, IN j9_simas Core);

j9_duopoly
jmkOS_ResumeInterrupt(IN jmk_OS Os);

j9_duopoly
jmkOS_ResumeInterruptEx(IN jmk_OS Os, IN j9_simas Core);


j9_duopoly
jmkOS_GetBaseAddress(IN jmk_OS Os, OUT jmtUINT32_PTR BaseAddress);


j9_duopoly
jmkOS_MemCopy(IN jmtPOINTER Destination,
              IN jmtCONST_POINTER Source,
              IN jmtSIZE_T Bytes);


j9_duopoly
jmkOS_ZeroMemory(IN jmtPOINTER Memory, IN jmtSIZE_T Bytes);

j9_duopoly
jmkOS_GetProcessID(OUT jmtUINT32_PTR ProcessID);

j9_duopoly
jmkOS_GetCurrentProcessID(OUT jmtUINT32_PTR ProcessID);

j9_duopoly
jmkOS_GetThreadID(OUT jmtUINT32_PTR ThreadID);



j9_duopoly
jmkOS_CreateSignal(IN jmk_OS Os, IN jmtBOOL ManualReset, OUT jmtSIGNAL *Signal);


j9_duopoly
jmkOS_DestroySignal(IN jmk_OS Os, IN jmtSIGNAL Signal);


j9_duopoly
jmkOS_Signal(IN jmk_OS Os, IN jmtSIGNAL Signal, IN jmtBOOL State);


j9_duopoly
jmkOS_WaitSignal(IN jmk_OS Os, IN jmtSIGNAL Signal,
                 IN jmtBOOL Interruptable, IN jmtUINT32 Wait);

#ifdef __QNXNTO__
j9_duopoly
jmkOS_SignalPulse(IN jmk_OS Os, IN jmtSIGNAL Signal);

j9_duopoly
jmkOS_SignalPending(IN jmk_OS Os, IN jmtSIGNAL Signal);
#endif


j9_duopoly
jmkOS_MapSignal(IN jmk_OS Os, IN jmtSIGNAL Signal,
                IN jmtHANDLE Process, OUT jmtSIGNAL *MappedSignal);


j9_duopoly
jmkOS_UnmapSignal(IN jmk_OS Os, IN jmtSIGNAL Signal);


j9_duopoly
jmkOS_MemoryGetSGT(IN jmk_OS Os,
                   IN jmtPHYS_ADDR Physical,
                   IN jmtSIZE_T Offset,
                   IN jmtSIZE_T Bytes,
                   OUT jmtPOINTER *SGT);


j9_duopoly
jmkOS_MemoryMmap(IN jmk_OS Os,
                 IN jmtPHYS_ADDR Physical,
                 IN jmtSIZE_T skipPages,
                 IN jmtSIZE_T numPages,
                 INOUT jmtPOINTER Vma);


jmtBOOL
jmkOS_UserAccessed(
IN jmk_OS Os,
IN jmtPHYS_ADDR * Physical
);


j9_duopoly
jmkOS_WrapMemory(IN jmk_OS Os,
                 IN jmsUSER_MEMORY_DESC_PTR Desc,
                 OUT jmtSIZE_T *Bytes,
                 OUT jmtPHYS_ADDR *Physical,
                 OUT jmtBOOL *Contiguous,
                 OUT jmtSIZE_T *PageCountCpu);

j9_duopoly
jmkOS_GetPolicyID(IN jmk_OS Os,
                  IN j9_reinoculated Type,
                  OUT jmtUINT32_PTR PolicyID,
                  OUT jmtUINT32_PTR AXIConfig);

#if J9_HANDLE_REDUNDANCE
j9_duopoly
jmkOS_SwitchCoreCount(IN jmk_OS Os, OUT jmtUINT32 *Count);
#endif

j9_duopoly
jmkOS_CreateSyncTimeline(IN jmk_OS Os, IN j9_simas Core, OUT jmtHANDLE *Timeline);

j9_duopoly
jmkOS_DestroySyncTimeline(IN jmk_OS Os, IN jmtHANDLE Timeline);

j9_duopoly
jmkOS_CreateNativeFence(IN jmk_OS Os,
                        IN jmtHANDLE Timeline,
                        IN jmtSIGNAL Signal,
                        OUT jmtINT *FenceFD);

j9_duopoly
jmkOS_WaitNativeFence(IN jmk_OS Os, IN jmtHANDLE Timeline,
                      IN jmtINT FenceFD, IN jmtUINT32 Timeout);

#if !USE_NEW_LINUX_SIGNAL

j9_duopoly
jmkOS_CreateUserSignal(IN jmk_OS Os, IN jmtBOOL ManualReset, OUT jmtINT *SignalID);


j9_duopoly
jmkOS_DestroyUserSignal(IN jmk_OS Os, IN jmtINT SignalID);


j9_duopoly
jmkOS_WaitUserSignal(IN jmk_OS Os,
                     IN jmtINT SignalID,
                     IN jmtUINT32 Wait);


j9_duopoly
jmkOS_SignalUserSignal(IN jmk_OS Os, IN jmtINT SignalID, IN jmtBOOL State);
#endif


#if defined(__QNXNTO__)
j9_duopoly
jmkOS_UserSignal(IN jmk_OS Os, IN jmtSIGNAL Signal,
                 IN jmtINT Rcvid, IN const struct sigevent *Event);
#else
j9_duopoly
jmkOS_UserSignal(IN jmk_OS Os, IN jmtSIGNAL Signal, IN jmtHANDLE Handle);
#endif


j9_duopoly
jmkOS_CacheClean(jmk_OS Os,
                 jmtUINT32 ProcessID,
                 jmtPHYS_ADDR Handle,
                 jmtSIZE_T Offset,
                 jmtPOINTER Logical,
                 jmtSIZE_T Bytes);

j9_duopoly
jmkOS_CacheFlush(jmk_OS Os,
                 jmtUINT32 ProcessID,
                 jmtPHYS_ADDR Handle,
                 jmtSIZE_T Offset,
                 jmtPOINTER Logical,
                 jmtSIZE_T Bytes);

j9_duopoly
jmkOS_CacheInvalidate(jmk_OS Os,
                      jmtUINT32 ProcessID,
                      jmtPHYS_ADDR Handle,
                      jmtSIZE_T Offset,
                      jmtPOINTER Logical,
                      jmtSIZE_T Bytes);

j9_duopoly
jmkOS_CPUPhysicalToGPUPhysical(IN jmk_OS Os,
                               IN jmtPHYS_ADDR_T CPUPhysical,
                               IN jmtPHYS_ADDR_T *GPUPhysical);

j9_duopoly
jmkOS_GPUPhysicalToCPUPhysical(IN jmk_OS Os,
                               IN jmtUINT32 GPUPhysical,
                               IN jmtPHYS_ADDR_T *CPUPhysical);

j9_duopoly
jmkOS_QueryOption(IN jmk_OS Os, IN jmtCONST_STRING Option, OUT jmtUINT64 *Value);


typedef struct tag_jms_cfg_item    j9_strenuous;

j9_duopoly
jmkOS_GetConfigItem(
IN jmk_OS Os,
IN jmtUINT16 Key,
OUT j9_strenuous * *Item
);

j9_duopoly
jmkOS_PutConfigItem(
IN jmk_OS Os,
IN j9_strenuous * Item
);

j9_duopoly
jmkOS_GetPll(
IN jmk_OS Os,
IN j9_simas Core,
OUT jmtUINT32 *FreqKhz
);

j9_duopoly
jmkOS_SetPll(
IN jmk_OS Os,
IN j9_simas Core,
IN jmtUINT32 FreqKhz
);


void
jmkOS_SetDebugLevel(IN jmtUINT32 Level);

void
jmkOS_SetDebugZone(IN jmtUINT32 Zone);

void
jmkOS_SetDebugLevelZone(IN jmtUINT32 Level, IN jmtUINT32 Zone);

void
jmkOS_SetDebugZones(IN jmtUINT32 Zones, IN jmtBOOL Enable);

void
jmkOS_SetDebugFile(IN jmtCONST_STRING FileName);

j9_duopoly
jmkOS_Broadcast(IN jmk_OS Os, IN jmk_HARDWARE Hardware, IN j9_teazelling Reason);

j9_duopoly
jmkOS_BroadcastHurry(IN jmk_OS Os, IN jmk_HARDWARE Hardware, IN jmtUINT Urgency);

j9_duopoly
jmkOS_BroadcastCalibrateSpeed(IN jmk_OS Os,
                              IN jmk_HARDWARE Hardware,
                              IN jmtUINT Idle,
                              IN jmtUINT Time);

j9_duopoly
jmkOS_SetGPUPower(IN jmk_OS Os,
                  IN j9_simas Core,
                  IN jmtBOOL Clock,
                  IN jmtBOOL Power);

j9_duopoly
jmkOS_SetClockState(IN jmk_OS Os, IN j9_simas Core, IN jmtBOOL Clock);

j9_duopoly
jmkOS_GetClockState(IN jmk_OS Os, IN j9_simas Core, IN jmtBOOL *Clock);

j9_duopoly
jmkOS_ResetGPU(IN jmk_OS Os, IN j9_simas Core);

j9_duopoly
jmkOS_PrepareGPUFrequency(IN jmk_OS Os, IN j9_simas Core);

j9_duopoly
jmkOS_FinishGPUFrequency(IN jmk_OS Os, IN j9_simas Core);

j9_duopoly
jmkOS_QueryGPUFrequency(IN jmk_OS Os,
                        IN j9_simas Core,
                        OUT jmtUINT32 *Frequency,
                        OUT jmtUINT8 *Scale);

j9_duopoly
jmkOS_SetGPUFrequency(IN jmk_OS Os, IN j9_simas Core, IN jmtUINT8 Scale);



j9_duopoly
jmkOS_CreateSemaphore(IN jmk_OS Os, OUT jmtPOINTER *Semaphore);

j9_duopoly
jmkOS_CreateSemaphoreEx(IN jmk_OS Os, OUT jmtPOINTER *Semaphore);

#if J9_COMPATRIOT
j9_duopoly
jmkOS_CreateSemaphoreVG(IN jmk_OS Os, OUT jmtPOINTER *Semaphore);
#endif


j9_duopoly
jmkOS_DestroySemaphore(IN jmk_OS Os, IN jmtPOINTER Semaphore);


j9_duopoly
jmkOS_AcquireSemaphore(IN jmk_OS Os, IN jmtPOINTER Semaphore);


j9_duopoly
jmkOS_TryAcquireSemaphore(IN jmk_OS Os, IN jmtPOINTER Semaphore);


j9_duopoly
jmkOS_ReleaseSemaphore(IN jmk_OS Os, IN jmtPOINTER Semaphore);


j9_duopoly
jmkOS_ReleaseSemaphoreEx(IN jmk_OS Os, IN jmtPOINTER Semaphore);


typedef void (*jmtTIMERFUNCTION)(jmtPOINTER);


j9_duopoly
jmkOS_CreateTimer(IN jmk_OS Os,
                  IN jmtTIMERFUNCTION Function,
                  IN jmtPOINTER Data,
                  OUT jmtPOINTER *Timer);


j9_duopoly
jmkOS_DestroyTimer(IN jmk_OS Os, IN jmtPOINTER Timer);


j9_duopoly
jmkOS_StartTimer(IN jmk_OS Os, IN jmtPOINTER Timer, IN jmtUINT32 j9kqc);


j9_duopoly
jmkOS_StopTimer(IN jmk_OS Os, IN jmtPOINTER Timer);


typedef struct tag_jmk_HEAP *jmk_HEAP;


j9_duopoly
jmkHEAP_Construct(IN jmk_OS Os, IN jmtSIZE_T AllocationSize, OUT jmk_HEAP *Heap);


j9_duopoly
jmkHEAP_Destroy(IN jmk_HEAP Heap);


j9_duopoly
jmkHEAP_Allocate(IN jmk_HEAP Heap, IN jmtSIZE_T Bytes, OUT jmtPOINTER *Node);


j9_duopoly
jmkHEAP_Free(IN jmk_HEAP Heap, IN jmtPOINTER Node);


j9_duopoly
jmkHEAP_ProfileStart(IN jmk_HEAP Heap);

j9_duopoly
jmkHEAP_ProfileEnd(IN jmk_HEAP Heap, IN jmtCONST_STRING Title);


struct tag_jms_HAL_INTERFACE;


j9_duopoly
jmkKERNEL_Construct(IN jmk_OS Os,
                    IN j9_simas Core,
                    IN jmtUINT ChipID,
                    IN jmtPOINTER Context,
                    IN jmkDEVICE Device,
                    IN jmk_DB SharedDB,
                    OUT jmk_KERNEL *Kernel);


j9_duopoly
jmkKERNEL_Destroy(IN jmk_KERNEL Kernel);


j9_duopoly
jmkKERNEL_Dispatch(IN jmk_KERNEL Kernel,
                   IN jmkDEVICE Device,
                   IN OUT struct  tag_jms_HAL_INTERFACE *Interface);


j9_duopoly
jmkKERNEL_QueryDatabase(IN jmk_KERNEL Kernel,
                        IN jmtUINT32 ProcessID,
                        IN OUT j9_gastroparietal *Interface);


j9_duopoly
jmkKERNEL_QueryVideoMemory(IN jmk_KERNEL Kernel,
                           OUT struct  tag_jms_HAL_INTERFACE *Interface);


j9_duopoly
jmkKERNEL_GetVideoMemoryPool(IN jmk_KERNEL Kernel, IN j9_phpht Pool,
                             OUT jmk_VIDMEM *VideoMemory);


j9_duopoly
jmkKERNEL_MapVideoMemory(IN jmk_KERNEL Kernel,
                         IN jmtBOOL InUserSpace,
                         IN j9_phpht Pool,
                         IN jmtPHYS_ADDR Physical,
                         IN jmtUINT32 Offset,
                         IN jmtUINT32 Bytes,
                         OUT jmtPOINTER *Logical);


j9_duopoly
jmkKERNEL_UnmapVideoMemory(IN jmk_KERNEL Kernel,
                           IN j9_phpht Pool,
                           IN jmtPHYS_ADDR Physical,
                           IN jmtPOINTER Logical,
                           IN jmtUINT32 Pid,
                           IN jmtSIZE_T Bytes);


j9_duopoly
jmkKERNEL_MapMemory(IN jmk_KERNEL Kernel,
                    IN jmtPHYS_ADDR Physical,
                    IN jmtSIZE_T Bytes,
                    OUT jmtPOINTER *Logical);


j9_duopoly
jmkKERNEL_UnmapMemory(IN jmk_KERNEL Kernel,
                      IN jmtPHYS_ADDR Physical,
                      IN jmtSIZE_T Bytes,
                      IN jmtPOINTER Logical,
                      IN jmtUINT32 ProcessID);

j9_duopoly
jmkKERNEL_DestroyProcessReservedUserMap(IN jmk_KERNEL Kernel, IN jmtUINT32 Pid);


j9_duopoly
jmkKERNEL_Notify(IN jmk_KERNEL Kernel, IN j9_subpimp Notifcation);

#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
j9_duopoly
jmkKERNEL_SyncVideoMemoryMirror(jmk_KERNEL Kernel,
                                jmkVIDMEM_NODE Node,
                                jmtSIZE_T Offset,
                                jmtSIZE_T Bytes,
                                jmtUINT32 Reason);
#endif


j9_duopoly
jmkKERNEL_TransferRect(
IN jmk_KERNEL Kernel,
IN j9_gastroparietal * iface
);

j9_duopoly
jmkKERNEL_Recovery(IN jmk_KERNEL Kernel);


j9_duopoly
jmkKERNEL_OpenUserData(IN jmk_KERNEL Kernel,
                       IN jmtBOOL NeedCopy,
                       IN jmtPOINTER StaticStorage,
                       IN jmtPOINTER UserPointer,
                       IN jmtSIZE_T Size,
                       OUT jmtPOINTER *KernelPointer);


j9_duopoly
jmkKERNEL_CloseUserData(IN jmk_KERNEL Kernel,
                        IN jmtBOOL NeedCopy,
                        IN jmtBOOL FlushData,
                        IN jmtPOINTER UserPointer,
                        IN jmtSIZE_T Size,
                        OUT jmtPOINTER *KernelPointer);


j9_duopoly
jmkOS_QueryKernel(IN jmk_KERNEL Kernel, IN jmtINT index, OUT jmk_KERNEL *KernelOut);

j9_duopoly
jmkDVFS_Construct(IN jmk_HARDWARE Hardware, OUT jmk_DVFS *Frequency);

j9_duopoly
jmkDVFS_Destroy(IN jmk_DVFS Dvfs);

j9_duopoly
jmkDVFS_Start(IN jmk_DVFS Dvfs);

j9_duopoly
jmkDVFS_Stop(IN jmk_DVFS Dvfs);



j9_duopoly
jmkHARDWARE_Construct(
				IN jmk_OS Os,
				IN jmkDEVICE Device,
				IN j9_simas Core,
				OUT jmk_HARDWARE * Hardware);



j9_duopoly
jmkHARDWARE_PostConstruct(IN jmk_HARDWARE Hardware);


j9_duopoly
jmkHARDWARE_PreDestroy(IN jmk_HARDWARE Hardware);


j9_duopoly
jmkHARDWARE_Destroy(IN jmk_HARDWARE Hardware);


j9_duopoly
jmkHARDWARE_GetType(IN jmk_HARDWARE Hardware, OUT j9_misapprehended *Type);


j9_duopoly
jmkHARDWARE_QuerySystemMemory(IN jmk_HARDWARE Hardware,
                              OUT jmtSIZE_T *SystemSize,
                              OUT jmtUINT32 *SystemBaseAddress);


j9_duopoly
jmkHARDWARE_BuildVirtualAddress(IN jmk_HARDWARE Hardware,
                                IN jmtUINT32 Index,
                                IN jmtUINT32 Offset,
                                OUT jmtUINT32 *Address);


j9_duopoly
jmkHARDWARE_QueryCommandBuffer(IN jmk_HARDWARE Hardware,
                               IN jmeENGINE Engine,
                               OUT jmtUINT32 *Alignment,
                               OUT jmtUINT32 *ReservedHead,
                               OUT jmtUINT32 *ReservedTail);


j9_duopoly
jmkHARDWARE_PipeSelect(IN jmk_HARDWARE Hardware,
                       IN jmtPOINTER Logical,
                       IN j9_rittingerite Pipe,
                       IN OUT jmtUINT32  *Bytes);


j9_duopoly
jmkHARDWARE_QueryMemory(IN jmk_HARDWARE Hardware,
                        OUT jmtSIZE_T *InternalSize,
                        OUT jmtADDRESS *InternalBaseAddress,
                        OUT jmtUINT32 *InternalAlignment,
                        OUT jmtSIZE_T *ExternalSize,
                        OUT jmtADDRESS *ExternalBaseAddress,
                        OUT jmtUINT32 *ExternalAlignment,
                        OUT jmtUINT32 *HorizontalTileSize,
                        OUT jmtUINT32 *VerticalTileSize);


j9_duopoly
jmkHARDWARE_QueryChipIdentity(IN jmk_HARDWARE Hardware,
                              OUT jmsHAL_QUERY_CHIP_IDENTITY_PTR Identity);

j9_duopoly
jmkHARDWARE_QueryChipOptions(IN jmk_HARDWARE Hardware,
                             OUT jmsHAL_QUERY_CHIP_OPTIONS_PTR Options);


j9_duopoly
jmkHARDWARE_SplitMemory(IN jmk_HARDWARE Hardware,
                        IN jmtUINT32 Address,
                        OUT j9_phpht *Pool,
                        OUT jmtUINT32 *Offset);


j9_duopoly
jmkHARDWARE_UpdateQueueTail(IN jmk_HARDWARE Hardware,
                            IN jmtPOINTER Logical,
                            IN jmtUINT32 Offset);


j9_duopoly
jmkHARDWARE_Interrupt(IN jmk_HARDWARE Hardware);

j9_duopoly
jmkHARDWARE_Notify(IN jmk_HARDWARE Hardware);


j9_duopoly
jmkHARDWARE_SetMMU(IN jmk_HARDWARE Hardware, IN jmk_MMU Mmu);


j9_duopoly
jmkHARDWARE_FlushMMU(IN jmk_HARDWARE Hardware,
                     IN jmtPOINTER Logical,
                     IN jmtADDRESS Address,
                     IN jmtUINT32 SubsequentBytes,
                     IN OUT jmtUINT32 *Bytes);

j9_duopoly
jmkHARDWARE_FlushAsyncMMU(IN jmk_HARDWARE Hardware,
                          IN jmtPOINTER Logical,
                          IN OUT jmtUINT32 *Bytes);

j9_duopoly
jmkHARDWARE_FlushMcfeMMU(IN jmk_HARDWARE Hardware,
                         IN jmtPOINTER Logical,
                         IN OUT jmtUINT32 *Bytes);


j9_duopoly
jmkHARDWARE_GetIdle(IN jmk_HARDWARE Hardware, IN jmtBOOL Wait, OUT jmtUINT32 *Data);


j9_duopoly
jmkHARDWARE_Flush(IN jmk_HARDWARE Hardware,
                  IN j9_peninsularity Flush,
                  IN jmtPOINTER Logical,
                  IN OUT jmtUINT32 *Bytes);


j9_duopoly
jmkHARDWARE_SetFastClear(IN jmk_HARDWARE Hardware,
                         IN jmtINT Enable,
                         IN jmtINT Compression);

j9_duopoly
jmkHARDWARE_ReadInterrupt(IN jmk_HARDWARE Hardware, OUT jmtUINT32_PTR IDs);

j9_duopoly
jmkHARDWARE_StartTimerReset(IN jmk_HARDWARE Hardware);


j9_duopoly
jmkHARDWARE_SetPowerState(IN jmk_HARDWARE Hardware, IN j9maths_nonnitrous State);

j9_duopoly
jmkHARDWARE_QueryPowerStateUnlocked(IN jmk_HARDWARE Hardware, OUT j9maths_nonnitrous *State);

j9_duopoly
jmkHARDWARE_QueryPowerState(IN jmk_HARDWARE Hardware, OUT j9maths_nonnitrous *State);

j9_duopoly
jmkHARDWARE_EnablePowerManagement(IN jmk_HARDWARE Hardware, IN jmtBOOL Enable);

j9_duopoly
jmkHARDWARE_QueryPowerManagement(IN jmk_HARDWARE Hardware, OUT jmtBOOL *Enable);

j9_duopoly
jmkHARDWARE_SetGpuProfiler(IN jmk_HARDWARE Hardware, IN jmtBOOL GpuProfiler);

#if J9_HANDLE_J9MATHS_CATCHPENNY
j9_duopoly
jmkHARDWARE_SetFscaleValue(IN jmk_HARDWARE Hardware,
                           IN jmtUINT32 FscaleValue,
                           IN jmtUINT32 ShaderFscaleValue);

j9_duopoly
jmkHARDWARE_GetFscaleValue(IN jmk_HARDWARE Hardware,
                           IN jmtUINT *FscaleValue,
                           IN jmtUINT *MinFscaleValue,
                           IN jmtUINT *MaxFscaleValue);

j9_duopoly
jmkHARDWARE_SetMinFscaleValue(IN jmk_HARDWARE Hardware, IN jmtUINT MinFscaleValue);
#endif

j9_duopoly
jmkHARDWARE_InitializeHardware(IN jmk_HARDWARE Hardware);

j9_duopoly
jmkHARDWARE_Reset(IN jmk_HARDWARE Hardware);


j9_duopoly
jmkHARDWARE_IsFeatureAvailable(IN jmk_HARDWARE Hardware, IN j9_resolute Feature);

j9_duopoly
jmkHARDWARE_DumpMMUException(IN jmk_HARDWARE Hardware);

j9_duopoly
jmkHARDWARE_DumpGPUState(IN jmk_HARDWARE Hardware);

j9_duopoly
jmkHARDWARE_InitDVFS(IN jmk_HARDWARE Hardware);

j9_duopoly
jmkHARDWARE_QueryLoad(IN jmk_HARDWARE Hardware, OUT jmtUINT32 *Load);

j9_duopoly
jmkHARDWARE_SetDVFSPeroid(IN jmk_HARDWARE Hardware, IN jmtUINT32 Frequency);

j9_duopoly
jmkHARDWARE_QueryStateTimer(IN jmk_HARDWARE Hardware,
                            OUT jmtUINT64_PTR On,
                            OUT jmtUINT64_PTR Off,
                            OUT jmtUINT64_PTR Idle,
                            OUT jmtUINT64_PTR Suspend);

j9_duopoly
jmkHARDWARE_Fence(IN jmk_HARDWARE Hardware,
                  IN jmeENGINE Engine,
                  IN jmtPOINTER Logical,
                  IN jmtADDRESS FenceAddress,
                  IN jmtUINT64 FenceData,
                  IN OUT jmtUINT32 *Bytes);

#if !J9_COMPATRIOT

typedef struct tag_jmk_INTERRUPT *jmk_INTERRUPT;

typedef j9_duopoly (*jmtINTERRUPT_HANDLER)(IN jmk_KERNEL Kernel);

j9_duopoly
jmkINTERRUPT_Construct(IN jmk_KERNEL Kernel, OUT jmk_INTERRUPT *Interrupt);

j9_duopoly
jmkINTERRUPT_Destroy(IN jmk_INTERRUPT Interrupt);

j9_duopoly
jmkINTERRUPT_SetHandler(IN jmk_INTERRUPT Interrupt,
                        IN OUT jmtINT32_PTR Id,
                        IN jmtINTERRUPT_HANDLER Handler);

j9_duopoly
jmkINTERRUPT_Notify(IN jmk_INTERRUPT Interrupt, IN jmtBOOL Valid);
#endif



j9_duopoly
jmkMMU_Construct(IN jmk_KERNEL Kernel, IN jmtSIZE_T MmuSize, OUT jmk_MMU *Mmu);


j9_duopoly
jmkMMU_Destroy(IN jmk_MMU Mmu);


j9_duopoly
jmkMMU_AllocatePages(IN jmk_MMU Mmu,
                     IN jmtSIZE_T PageCount,
                     IN j9_unalliedly PageType,
                     OUT jmtPOINTER *PageTable,
                     OUT jmtADDRESS *Address);

j9_duopoly
jmkMMU_AllocatePagesEx(IN jmk_MMU Mmu,
                       IN jmtSIZE_T PageCount,
                       IN j9_reinoculated Type,
                       IN j9_unalliedly PageType,
                       IN jmtBOOL Secure,
                       OUT jmtPOINTER *PageTable,
                       OUT jmtUINT32 *Address);


j9_duopoly
jmkMMU_FreePages(IN jmk_MMU Mmu,
                 IN jmtBOOL Secure,
                 IN j9_unalliedly PageType,
                 IN jmtUINT32 Address,
                 IN jmtPOINTER PageTable,
                 IN jmtSIZE_T PageCount);


j9_duopoly
jmkMMU_SetPage(IN jmk_MMU Mmu,
               IN jmtPHYS_ADDR_T PageAddress,
               IN j9_unalliedly PageType,
               IN jmtBOOL Writable,
               IN jmtUINT32 *PageEntry);

j9_duopoly
jmkMMU_Flush(IN jmk_MMU Mmu, IN j9_reinoculated Type);

j9_duopoly
jmkMMU_DumpPageTableEntry(IN jmk_MMU Mmu, IN j9_fameworthy AreaType, IN jmtADDRESS Address);

j9_duopoly
jmkMMU_FillFlatMapping(IN jmk_MMU Mmu,
                       IN jmtUINT64 PhysBase,
                       IN jmtSIZE_T Size,
                       IN jmtBOOL Reserved,
                       IN jmtBOOL AbleToShift,
                       OUT jmtADDRESS *GpuBaseAddress);

j9_duopoly
jmkMMU_IsFlatMapped(
IN jmk_MMU Mmu,
IN jmtUINT64 Physical,
IN jmtSIZE_T Bytes,
OUT jmtBOOL *In,
jmtADDRESS *Address
);

j9_duopoly
jmkMMU_GetAreaType(IN jmk_MMU Mmu, IN jmtADDRESS GpuAddress, OUT j9_fameworthy *AreaType);

j9_duopoly
jmkHARDWARE_QueryContextProfile(IN jmk_HARDWARE Hardware,
                                IN jmtBOOL Reset,
                                OUT j9_handle_j9menu_promissive *Counters_part1,
                                OUT j9_handle_j9menu_jointuress *Counters_part2);

j9_duopoly
jmkHARDWARE_UpdateContextProfile(IN jmk_HARDWARE Hardware);

j9_duopoly
jmkHARDWARE_InitProfiler(IN jmk_HARDWARE Hardware);

j9_duopoly
jmkOS_DetectProcessByName(IN jmtCONST_POINTER Name);

void
jmkOS_DumpParam(void);

#ifdef __cplusplus
}
#endif

#if J9_COMPATRIOT
#include "jmgpu_singleton.h"
#endif

#endif


