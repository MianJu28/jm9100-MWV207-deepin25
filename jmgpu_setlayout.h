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




#ifndef __jmgpu_hal_mem_h_
#define __jmgpu_hal_mem_h_
#if (J9_DEMISSNESS || J9_COMPATRIOT)

# ifdef __cplusplus
extern "C" {
# endif


# ifndef USE_LOCAL_MEMORY_POOL
#  define USE_LOCAL_MEMORY_POOL 1
# endif

# if USE_LOCAL_MEMORY_POOL
typedef struct tag_jms_MEM_FS_MEM_POOL     *j9mirror_aphidicide;
typedef struct tag_jms_MEM_VS_MEM_POOL     *j9mirror_peripteros;
typedef struct tag_jms_MEM_AFS_MEM_POOL    *j9_handle_bluepoints;
# else
typedef jmoOS j9mirror_aphidicide;
typedef jmoOS j9mirror_peripteros;
typedef jmoOS j9_handle_bluepoints;
# endif

# if USE_LOCAL_MEMORY_POOL
#  define j9_handle_j9m_indentwise(Type, TypeName, Prefix)                                      \
        j9_duopoly Prefix##_Allocate##TypeName(j9mirror_aphidicide MemPool, Type **Pointer)      \
        {                                                                                      \
            return jmfMEM_FSMemPoolGetANode(MemPool, (jmtPOINTER *)Pointer);                   \
        }                                                                                      \
                                                                                               \
        j9_duopoly Prefix##_CAllocate##TypeName(j9mirror_aphidicide MemPool, Type **Pointer)     \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x Pointer=0x%x", MemPool, Pointer);                      \
            J9_BUSINESSMAN(jmfMEM_FSMemPoolGetANode(MemPool, (jmtPOINTER *)Pointer));           \
            j9_orchidotherapy(*(jmtPOINTER *)Pointer, J9_NONPROS(Type));                         \
            JMM_FOOTER();                                                                       \
            return J9_FLUTTERING;                                                               \
        }                                                                                      \
                                                                                               \
        j9_duopoly Prefix##_Free##TypeName(j9mirror_aphidicide MemPool, Type *Pointer)           \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x Pointer=0x%x", MemPool, Pointer);                      \
            status = jmfMEM_FSMemPoolFreeANode(MemPool, (jmtPOINTER)Pointer);                  \
            JMM_FOOTER();                                                                       \
            return status;                                                                     \
        }                                                                                      \
                                                                                               \
        j9_duopoly Prefix##_Free##TypeName##List(j9mirror_aphidicide MemPool,                    \
                                                Type *FirstPointer, Type *LastPointer)         \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x FirstPointer=0x%x LastPointer=0x%x",                   \
                          MemPool, FirstPointer, LastPointer);                                 \
            status = jmfMEM_FSMemPoolFreeAList(MemPool, (jmtPOINTER)FirstPointer,              \
                                               (jmtPOINTER)LastPointer);                       \
            JMM_FOOTER();                                                                       \
            return status;                                                                     \
        }

#  define j9_handle_j9m_outweighed(Type, TypeName, Prefix)                                      \
        j9_duopoly Prefix##_Allocate##TypeName(j9mirror_aphidicide MemPool,                      \
                                              Type **Pointer, jmtUINT Size)                    \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x Pointer=0x%x Size=%u", MemPool, Pointer, Size);        \
            status = jmfMEM_VSMemPoolGetANode(MemPool, Size, (jmtPOINTER *)Pointer);           \
            JMM_FOOTER();                                                                       \
            return status;                                                                     \
        }                                                                                      \
                                                                                               \
        j9_duopoly Prefix##_CAllocate##TypeName(j9mirror_aphidicide MemPool,                     \
                                               Type **Pointer, jmtUINT Size)                   \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x Pointer=0x%x Size=%u", MemPool, Pointer, Size);        \
            J9_BUSINESSMAN(jmfMEM_VSMemPoolGetANode(MemPool, Size, (jmtPOINTER *)Pointer));     \
            j9_orchidotherapy(*(jmtPOINTER *)Pointer, size);                                    \
            JMM_FOOTER();                                                                       \
            return J9_FLUTTERING;                                                               \
        }                                                                                      \
                                                                                               \
        j9_duopoly Prefix##_Free##TypeName(j9mirror_aphidicide MemPool, Type *Pointer)           \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x Pointer=0x%x", MemPool, Pinter);                       \
            status = jmfMEM_VSMemPoolFreeANode(MemPool, (jmtPOINTER)Pointer);                  \
            JMM_FOOTER();                                                                       \
            return status;                                                                     \
        }

#  define j9_handle_j9ma_polytenies(Type, TypeName, Prefix)                                     \
        j9_duopoly Prefix##_Allocate##TypeName(j9_handle_bluepoints MemPool,                     \
                                              Type **Pointer, jmtUINT Count)                   \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x Pointer=0x%x Count=%u", MemPool, Pointer, Count);      \
            status = jmfMEM_AFSMemPoolGetANode(MemPool, Count, (jmtPOINTER *)Pointer);         \
            JMM_FOOTER();                                                                       \
            return status;                                                                     \
        }                                                                                      \
                                                                                               \
        j9_duopoly Prefix##_CAllocate##TypeName(j9_handle_bluepoints MemPool,                    \
                                               Type **Pointer, jmtUINT Count)                  \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x Pointer=0x%x Count=%u", MemPool, Pointer, Count);      \
            J9_BUSINESSMAN(jmfMEM_AFSMemPoolGetANode(MemPool, Count, (jmtPOINTER *)Pointer));   \
            j9_orchidotherapy(*(jmtPOINTER *)Pointer, Count *J9_NONPROS(Type));                  \
            JMM_FOOTER();                                                                       \
            return J9_FLUTTERING;                                                               \
        }                                                                                      \
                                                                                               \
        j9_duopoly Prefix##_Free##TypeName(j9_handle_bluepoints MemPool, Type *Pointer)          \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x Pointer=0x%x", MemPool, Pointer);                      \
            status = jmfMEM_AFSMemPoolFreeANode(MemPool, (jmtPOINTER)Pointer);                 \
            JMM_FOOTER();                                                                       \
            return status;                                                                     \
        }

# else

#  define j9_handle_j9m_indentwise(Type, TypeName, Prefix)                                      \
        j9_duopoly Prefix##_Allocate##TypeName(j9mirror_aphidicide MemPool, Type **Pointer)      \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x Pointer=0x%x", MemPool, Pointer);                      \
            status = j9_urobilinogen(MemPool, J9_NONPROS(Type), (jmtPOINTER *)Pointer);          \
            JMM_FOOTER();                                                                       \
            return status;                                                                     \
        }                                                                                      \
                                                                                               \
        j9_duopoly Prefix##_CAllocate##TypeName(j9mirror_aphidicide MemPool, Type **Pointer)     \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x Pointer=0x%x", MemPool, Pointer);                      \
            J9_BUSINESSMAN(j9_urobilinogen(MemPool, J9_NONPROS(Type), (jmtPOINTER *)Pointer));    \
            j9_orchidotherapy(*(jmtPOINTER *)Pointer, J9_NONPROS(Type));                         \
            JMM_FOOTER();                                                                       \
            return J9_FLUTTERING;                                                               \
        }                                                                                      \
                                                                                               \
        j9_duopoly Prefix##_Free##TypeName(j9mirror_aphidicide MemPool, Type *Pointer)           \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x Pointer=0x%x", MemPool, Pointer);                      \
            status = J9_SCALENOHEDRON(MemPool, Pointer);                                        \
            JMM_FOOTER();                                                                       \
            return status;                                                                     \
        }

#  define j9_handle_j9m_outweighed(Type, TypeName, Prefix)                                      \
        j9_duopoly Prefix##_Allocate##TypeName(j9mirror_peripteros MemPool,                      \
                                              Type **Pointer, jmtUINT Size)                    \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x Pointer=0x%x Size=%u", MemPool, Pointer, Size);        \
            status = j9_urobilinogen(MemPool, Size, (jmtPOINTER *)Pointer);                     \
            JMM_FOOTER();                                                                       \
            return status;                                                                     \
        }                                                                                      \
                                                                                               \
        j9_duopoly Prefix##_CAllocate##TypeName(j9mirror_peripteros MemPool,                     \
                                               Type **Pointer, jmtUINT Size)                   \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x Pointer=0x%x Size=%u", MemPool, Pointer, Size);        \
            J9_BUSINESSMAN(j9_urobilinogen(MemPool, Size, (jmtPOINTER *)Pointer));               \
            j9_orchidotherapy(*(jmtPOINTER *)Pointer, Size);                                    \
            JMM_FOOTER();                                                                       \
            return J9_FLUTTERING;                                                               \
        }                                                                                      \
                                                                                               \
        j9_duopoly Prefix##_Free##TypeName(j9mirror_peripteros MemPool, Type *Pointer)           \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x Pointer=0x%x", MemPool, Pointer);                      \
            status = J9_SCALENOHEDRON(MemPool, Pointer);                                        \
            JMM_FOOTER();                                                                       \
            return status;                                                                     \
        }

#  define j9_handle_j9ma_polytenies(Type, TypeName, Prefix)                                     \
        j9_duopoly Prefix##_Allocate##TypeName(j9_handle_bluepoints MemPool,                     \
                                              Type **Pointer, jmtUINT Count)                   \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x Pointer=0x%x Count=%u", MemPool, Pointer, Count);      \
            status = j9_urobilinogen(MemPool, Count * J9_NONPROS(Type), (jmtPOINTER *)Pointer);  \
            JMM_FOOTER();                                                                       \
            return status;                                                                     \
        }                                                                                      \
                                                                                               \
        j9_duopoly Prefix##_CAllocate##TypeName(j9_handle_bluepoints MemPool,                    \
                                               Type **Pointer, jmtUINT Count)                  \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x Pointer=0x%x Count=%u", MemPool, Pointer, Count);      \
            J9_BUSINESSMAN(j9_urobilinogen(MemPool, Count *J9_NONPROS(Type),                      \
                                         (jmtPOINTER *)Pointer));                              \
            j9_orchidotherapy(*(jmtPOINTER *)Pointer, Count *J9_NONPROS(Type));                  \
            JMM_FOOTER();                                                                       \
            return J9_FLUTTERING;                                                               \
        }                                                                                      \
                                                                                               \
        j9_duopoly Prefix##_Free##TypeName(j9_handle_bluepoints MemPool, Type *Pointer)          \
        {                                                                                      \
            j9_duopoly status;                                                                  \
            J9_ANTIMEDICAL("MemPool=0x%x Pointer=0x%x", MemPool, Pointer);                      \
            status = J9_SCALENOHEDRON(MemPool, Pointer);                                        \
            JMM_FOOTER();                                                                       \
            return status;                                                                     \
        }
# endif

j9_duopoly
jmfMEM_InitFSMemPool(IN j9mirror_aphidicide *MemPool,
                     IN jmoOS OS,
                     IN jmtUINT NodeCount,
                     IN jmtUINT NodeSize);

j9_duopoly
jmfMEM_FreeFSMemPool(IN j9mirror_aphidicide *MemPool);

j9_duopoly
jmfMEM_FSMemPoolGetANode(IN j9mirror_aphidicide MemPool, OUT jmtPOINTER *Node);

j9_duopoly
jmfMEM_FSMemPoolFreeANode(IN j9mirror_aphidicide MemPool, IN jmtPOINTER Node);

j9_duopoly
jmfMEM_FSMemPoolFreeAList(IN j9mirror_aphidicide MemPool,
                          IN jmtPOINTER FirstNode,
                          IN jmtPOINTER LastNode);

j9_duopoly
jmfMEM_InitVSMemPool(IN j9mirror_peripteros *MemPool,
                     IN jmoOS OS,
                     IN jmtUINT BlockSize,
                     IN jmtBOOL RecycleFreeNode);

j9_duopoly
jmfMEM_FreeVSMemPool(IN j9mirror_peripteros *MemPool);

j9_duopoly
jmfMEM_VSMemPoolGetANode(IN j9mirror_peripteros MemPool,
                         IN jmtUINT Size,
                         IN jmtUINT Alignment,
                         OUT jmtPOINTER *Node);

j9_duopoly
jmfMEM_VSMemPoolFreeANode(IN j9mirror_peripteros MemPool, IN jmtPOINTER Node);

j9_duopoly
jmfMEM_InitAFSMemPool(IN j9_handle_bluepoints *MemPool,
                      IN jmoOS OS,
                      IN jmtUINT NodeCount,
                      IN jmtUINT NodeSize);

j9_duopoly
jmfMEM_FreeAFSMemPool(IN j9_handle_bluepoints *MemPool);

j9_duopoly
jmfMEM_AFSMemPoolGetANode(IN j9_handle_bluepoints MemPool,
                          IN jmtUINT Count,
                          OUT jmtPOINTER *Node);

j9_duopoly
jmfMEM_AFSMemPoolFreeANode(IN j9_handle_bluepoints MemPool, IN jmtPOINTER Node);

# ifdef __cplusplus
}
# endif

#endif
#endif


