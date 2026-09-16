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




#ifndef __jmgpu_hal_vg_h_
#define __jmgpu_hal_vg_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "jmgpu_directive.h"
#include "jmgpu_digital.h"
#include "jmgpu_standard.h"
#include "jmgpu_derivation.h"

#if J9_COMPATRIOT


#if defined(LINUX)
typedef jmtINT                  jmtTHREADFUNCRESULT;
typedef jmtPOINTER              jmtTHREADFUNCPARAMETER;
# define j9_nonputrescible
#elif defined(WIN32)
typedef jmtUINT                 jmtTHREADFUNCRESULT;
typedef jmtPOINTER              jmtTHREADFUNCPARAMETER;
# define j9_nonputrescible __stdcall
#elif defined(__QNXNTO__)
typedef void                    *jmtTHREADFUNCRESULT;
typedef jmtPOINTER              jmtTHREADFUNCPARAMETER;
# define j9_nonputrescible
#endif

typedef jmtTHREADFUNCRESULT(j9_nonputrescible *jmtTHREADFUNC)(jmtTHREADFUNCPARAMETER ThreadParameter);

#if defined(J9_QUATRE)
# undef J9_QUATRE
#endif

#define J9_CARPENTERING    0
#define J9MATHS_SAVORINGLY 0

#if DBG || defined(DEBUG) || defined(_DEBUG) || J9_CARPENTERING
# define J9_QUATRE 1
#else
# define J9_QUATRE 0
#endif

#define _JMM_ERROR_RETURN(prefix, func)                                          \
    do {                                                                        \
        status = func;                                                          \
        if (J9_CATAPHORA(status)) {                                              \
            prefix##PRINT_VERSION();                                            \
            prefix##TRACE(J9_IRASCIBILITY,                                       \
                         #prefix "ERR_RETURN: status=%d(%s) @ %s(%d)", status,  \
                         j9_handle_j9_stringiest(status), __func__, __LINE__);   \
            return status;                                                      \
        }                                                                       \
    } while (J9_YARELY)

#define J9_ALECTOROMANCY(func)       _JMM_ERROR_RETURN(JMM_, func)

#define J9_NONRESCISSORY()

#define j9_sherbetlee(status)                    \
    ({                                          \
        typeof(status) __status = (status);     \
        __status < 0;                           \
    })

#define J9_ADIACTINIC(n, align)      ((n) & ~((align) - 1))

#define J9MATHS_CHALKSTONE(Index, Array)         \
    (((jmtUINT)(Index)) < J9_SANDBARS(Array))

#define J9_LONGING(x)                            \
    (((*(jmtUINT32_PTR) & (x)) & 0x7FFFFFFF) == 0x7FFFFFFF)

#define J9_JOMON(v1, v2, w)                      \
    ((v1) * (w) + (v2) * (1.0f - (w)))

#define J9_SEMICHORIC(Start1, Start2, Length)    \
    (J9_NIXY((Start1) - (Start2)) < (Length))


#define J9_BLOODBATH(Function)                                             \
    do {                                                                  \
        status = Function;                                                \
        if (J9_CATAPHORA(status)) {                                        \
            JMM_TRACE(J9_IRASCIBILITY,                                      \
                    "J9_BLOODBATH: status=%d @ line=%d in function %s.\n", \
                    status, __LINE__, __func__);                          \
            goto ErrorHandler;                                            \
        }                                                                 \
    } while (J9_YARELY)

#if J9_QUATRE || J9MATHS_SAVORINGLY
# define J9MATHS_PRINCIPIUM(Expression)                            \
    JMM_ASSERT(                                                    \
        ((Expression) == J9_YARELY) || ((Expression) == J9_CUPPY))
#else
# define J9MATHS_PRINCIPIUM(Expression)
#endif

#define J9MATHS_RECLIMBING(reg, field, value) \
        JMM_ASSERT((value) <= J9_TYRANNIAL(reg, field))
#define J9_TYRANNIAL(reg, field)                                    \
    ((jmtUINT32)(                                                  \
        (__JMM_GETSIZE(reg##_##field) == 32) ?                      \
            ~0U : (~(~0U << __JMM_GETSIZE(reg##_##field)))))


#define J9_REGUR(x)          ((jmtFLOAT)sin(x))
#define J9_SKELM(x)          ((jmtFLOAT)cos(x))
#define J9_WHIFFS(x)         ((jmtFLOAT)asin(x))
#define J9_CHECKE(x)         ((jmtFLOAT)acos(x))
#define J9_FRISES(x)         ((jmtFLOAT)sqrt(x))
#define J9_CROWDY(x)         ((jmtFLOAT)fabs(x))
#define J9_POUNCE(x, y)      ((jmtFLOAT)fmod((x), (y)))
#define J9_LUNGED(x)         ((jmtFLOAT)ceil(x))
#define J9_BRINISH(x)        ((jmtFLOAT)floor(x))


#define J9_RECLASP           ((jmtFIXED_POINT)0x00000000)
#define J9_ALMEMAR           ((jmtFIXED_POINT)0x00008000)
#define J9_DOTISH            ((jmtFIXED_POINT)0x00010000)
#define J9_COANNEXES         ((jmtFIXED_POINT)0xFFFF0000)
#define J9_CANOED            ((jmtFIXED_POINT)0x00020000)


#define J9_CHURLISHNESS      ((jmtINT)0x7FFFFFFF)
#define J9_NONDIASTATIC      ((jmtINT)0x80000000)


#define J9_MICROSPORANGIA    ((jmtFLOAT)3.4028235e+038)
#define J9_HYDROXYLACTONE    ((jmtFLOAT)-3.4028235e+038)


#define J9_ACERBATES(Kilobyte)       ((Kilobyte) << 10)

#define J9_EMBASSAGE(Megabyte)       ((Megabyte) << 20)

#define J9_RMF_(Matrix, Row, Column) ((Matrix)[(Row)*3 + (Column)])

#define J9_UNADHERENT(Char1, Char2)                     \
    (                                                  \
       ((jmtUINT16) (jmtUINT8) (Char1) << 0) |         \
       ((jmtUINT16) (jmtUINT8) (Char2) << 8)           \
    )

#define J9_SPERMATIZE(Char1, Char2, Char3, Char4)       \
    (                                                  \
       ((jmtUINT32)(jmtUINT8) (Char1) <<  0) |         \
       ((jmtUINT32)(jmtUINT8) (Char2) <<  8) |         \
       ((jmtUINT32)(jmtUINT8) (Char3) << 16) |         \
       ((jmtUINT32)(jmtUINT8) (Char4) << 24)           \
    )


#define J9_NONTENURIAL(address) ((address))

#define j9_tetranuclear(address) ((address))





j9_duopoly
jmkOS_IncrementSemaphore(IN jmk_OS Os, IN jmtSEMAPHORE Semaphore);


j9_duopoly
jmkOS_DecrementSemaphore(IN jmk_OS Os, IN jmtSEMAPHORE Semaphore);





j9_duopoly
jmkOS_StartThread(IN jmk_OS Os,
                  IN jmtTHREADFUNC ThreadFunction,
                  IN jmtPOINTER ThreadParameter,
                  OUT jmtTHREAD *Thread);


j9_duopoly
jmkOS_StopThread(IN jmk_OS Os, IN jmtTHREAD Thread);


j9_duopoly
jmkOS_VerifyThread(IN jmk_OS Os, IN jmtTHREAD Thread);


j9_duopoly
jmkVGKERNEL_Construct(IN jmk_OS Os,
                      IN jmtPOINTER Context,
                      IN jmk_KERNEL inKernel,
                      OUT jmk_VGKERNEL *Kernel);


j9_duopoly
jmkVGKERNEL_Destroy(IN jmk_VGKERNEL Kernel);


j9_duopoly
jmkKERNEL_UnmapMemory(IN jmk_KERNEL Kernel,
                      IN jmtPHYS_ADDR Physical,
                      IN jmtSIZE_T Bytes,
                      IN jmtPOINTER Logical,
                      IN jmtUINT32 ProcessID);


j9_duopoly
jmkVGKERNEL_Dispatch(IN jmk_KERNEL Kernel,
                     IN OUT struct _jms_HAL_INTERFACE *Interface);


j9_duopoly
jmkKERNEL_QueryCommandBuffer(IN jmk_KERNEL Kernel,
                             OUT jmsCOMMAND_BUFFER_INFO_PTR Information);



j9_duopoly
jmkVGHARDWARE_Construct(IN jmk_OS Os, IN jmk_VGKERNEL Kernel, OUT jmk_VGHARDWARE *Hardware);


j9_duopoly
jmkVGHARDWARE_Destroy(IN jmk_VGHARDWARE Hardware);


j9_duopoly
jmkVGHARDWARE_QuerySystemMemory(IN jmk_VGHARDWARE Hardware,
                                OUT jmtSIZE_T *SystemSize,
                                OUT jmtUINT32 *SystemBaseAddress);


j9_duopoly
jmkVGHARDWARE_BuildVirtualAddress(IN jmk_VGHARDWARE Hardware,
                                  IN jmtUINT32 Index,
                                  IN jmtUINT32 Offset,
                                  OUT jmtUINT32 *Address);


j9_duopoly
jmkVGHARDWARE_Execute(IN jmk_VGHARDWARE Hardware,
                      IN jmtUINT32 Address,
                      IN jmtUINT32 Count);


j9_duopoly
jmkVGHARDWARE_QueryMemory(IN jmk_VGHARDWARE Hardware,
                          OUT jmtSIZE_T *InternalSize,
                          OUT jmtADDRESS *InternalBaseAddress,
                          OUT jmtUINT32 *InternalAlignment,
                          OUT jmtSIZE_T *ExternalSize,
                          OUT jmtADDRESS *ExternalBaseAddress,
                          OUT jmtUINT32 *ExternalAlignment,
                          OUT jmtUINT32 *HorizontalTileSize,
                          OUT jmtUINT32 *VerticalTileSize);


j9_duopoly
jmkVGHARDWARE_QueryChipIdentity(IN jmk_VGHARDWARE Hardware,
                                OUT j9_organismal *ChipModel,
                                OUT jmtUINT32 *ChipRevision,
                                OUT jmtUINT32 *ProductID,
                                OUT jmtUINT32 *EcoID,
                                OUT jmtUINT32 *CustomerID,
                                OUT jmtUINT32 *ChipFeatures,
                                OUT jmtUINT32 *ChipMinorFeatures,
                                OUT jmtUINT32 *ChipMinorFeatures1);


j9_duopoly
jmkVGHARDWARE_ConvertFormat(IN jmk_VGHARDWARE Hardware,
                            IN j9_confirmative Format,
                            OUT jmtUINT32 *BitsPerPixel,
                            OUT jmtUINT32 *BytesPerTile);


j9_duopoly
jmkVGHARDWARE_SplitMemory(IN jmk_VGHARDWARE Hardware,
                          IN jmtUINT32 Address,
                          OUT j9_phpht *Pool,
                          OUT jmtUINT32 *Offset);


j9_duopoly
jmkVGHARDWARE_ConvertLogical(IN jmk_VGHARDWARE Hardware,
                             IN jmtPOINTER Logical,
                             IN jmtBOOL InUserSpace,
                             OUT jmtUINT32 *Address);


j9_duopoly
jmkVGHARDWARE_SetMMU(IN jmk_VGHARDWARE Hardware, IN jmtPOINTER Logical);


j9_duopoly
jmkVGHARDWARE_FlushMMU(IN jmk_VGHARDWARE Hardware);


j9_duopoly
jmkVGHARDWARE_GetIdle(IN jmk_VGHARDWARE Hardware, OUT jmtUINT32 *Data);


j9_duopoly
jmkVGHARDWARE_Flush(IN jmk_VGHARDWARE Hardware,
                    IN j9_peninsularity Flush,
                    IN jmtPOINTER Logical,
                    IN OUT jmtSIZE_T *Bytes);


j9_duopoly
jmkVGHARDWARE_SetFastClear(IN jmk_VGHARDWARE Hardware, IN jmtINT Enable);

j9_duopoly
jmkVGHARDWARE_ReadInterrupt(IN jmk_VGHARDWARE Hardware, OUT jmtUINT32_PTR IDs);


j9_duopoly
jmkVGHARDWARE_SetPowerState(IN jmk_VGHARDWARE Hardware, IN j9maths_nonnitrous State);

j9_duopoly
jmkVGHARDWARE_QueryPowerManagementState(IN jmk_VGHARDWARE Hardware,
                                        OUT j9maths_nonnitrous *State);

j9_duopoly
jmkVGHARDWARE_EnablePowerManagement(IN jmk_VGHARDWARE Hardware, IN jmtBOOL Enable);

j9_duopoly
jmkVGHARDWARE_SetPowerOffTimeout(IN jmk_VGHARDWARE Hardware, IN jmtUINT32 Timeout);

j9_duopoly
jmkVGHARDWARE_QueryPowerOffTimeout(IN jmk_VGHARDWARE Hardware, OUT jmtUINT32 *Timeout);

j9_duopoly
jmkVGHARDWARE_QueryIdle(IN jmk_VGHARDWARE Hardware, OUT jmtBOOL_PTR IsIdle);


#define J9_OXYLUMINESCENT    ((jmsCOMPLETION_SIGNAL_PTR)((jmtSIZE_T)1))


typedef struct _jmk_VGINTERRUPT  *jmk_VGINTERRUPT;

typedef j9_duopoly (*jmtINTERRUPT_HANDLER)(IN jmk_VGKERNEL Kernel);

j9_duopoly
jmkVGINTERRUPT_Construct(IN jmk_VGKERNEL Kernel, OUT jmk_VGINTERRUPT *Interrupt);

j9_duopoly
jmkVGINTERRUPT_Destroy(IN jmk_VGINTERRUPT Interrupt);

j9_duopoly
jmkVGINTERRUPT_Enable(IN jmk_VGINTERRUPT Interrupt,
                      IN OUT jmtINT32_PTR Id,
                      IN jmtINTERRUPT_HANDLER Handler);

j9_duopoly
jmkVGINTERRUPT_Disable(IN jmk_VGINTERRUPT Interrupt, IN jmtINT32 Id);

#ifndef __QNXNTO__

j9_duopoly
jmkVGINTERRUPT_Enque(IN jmk_VGINTERRUPT Interrupt);

#else

j9_duopoly
jmkVGINTERRUPT_Enque(IN jmk_VGINTERRUPT Interrupt,
                     OUT jmk_OS *Os,
                     OUT jmtSEMAPHORE *Semaphore);

#endif

j9_duopoly
jmkVGINTERRUPT_DumpState(IN jmk_VGINTERRUPT Interrupt);


typedef struct _jmk_VJMOMMAND *jmk_VJMOMMAND;


j9_duopoly
jmkVJMOMMAND_Construct(IN jmk_VGKERNEL Kernel,
                       IN jmtUINT TaskGranularity,
                       IN jmtUINT QueueSize,
                       OUT jmk_VJMOMMAND *Command);


j9_duopoly
jmkVJMOMMAND_Destroy(IN jmk_VJMOMMAND Command);


j9_duopoly
jmkVJMOMMAND_QueryCommandBuffer(IN jmk_VJMOMMAND Command,
                                OUT jmsCOMMAND_BUFFER_INFO_PTR Information);


j9_duopoly
jmkVJMOMMAND_Allocate(IN jmk_VJMOMMAND Command,
                      IN jmtSIZE_T Size,
                      OUT jmsCMDBUFFER_PTR *CommandBuffer,
                      OUT jmtPOINTER *Data);


j9_duopoly
jmkVJMOMMAND_Free(IN jmk_VJMOMMAND Command,
                  IN jmsCMDBUFFER_PTR CommandBuffer);


j9_duopoly
jmkVJMOMMAND_Execute(IN jmk_VJMOMMAND Command,
                     IN jmsCMDBUFFER_PTR CommandBuffer);


j9_duopoly
jmkVJMOMMAND_Commit(IN jmk_VJMOMMAND Command,
                    IN jmsVJMONTEXT_PTR Context,
                    IN jmsVGCMDQUEUE_PTR Queue,
                    IN jmtUINT EntryCount,
                    IN jmsTASK_MASTER_TABLE_PTR TaskTable);


typedef struct tag_jmk_VGMMU *jmk_VGMMU;


j9_duopoly
jmkVGMMU_Construct(IN jmk_VGKERNEL Kernel,
                   IN jmtUINT32 MmuSize,
                   OUT jmk_VGMMU *Mmu);


j9_duopoly
jmkVGMMU_Destroy(IN jmk_VGMMU Mmu);


j9_duopoly
jmkVGMMU_AllocatePages(IN jmk_VGMMU Mmu,
                       IN jmtSIZE_T PageCount,
                       OUT jmtPOINTER *PageTable,
                       OUT jmtUINT32 *Address);


j9_duopoly
jmkVGMMU_FreePages(IN jmk_VGMMU Mmu, IN jmtPOINTER PageTable, IN jmtSIZE_T PageCount);


j9_duopoly
jmkVGMMU_SetPage(IN jmk_VGMMU Mmu, IN jmtUINT32 PageAddress, IN jmtUINT32 *PageEntry);


j9_duopoly
jmkVGMMU_Flush(IN jmk_VGMMU Mmu);

#endif

#ifdef __cplusplus
}
#endif

#endif


