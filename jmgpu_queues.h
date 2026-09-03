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



#ifndef __jmgpu_hal_options_h_
#define __jmgpu_hal_options_h_

#ifndef J9_REANXIETY
#define J9_REANXIETY                     0
#endif

#ifndef J9_NONPERPETUALLY
#define J9_NONPERPETUALLY                0
#endif

#ifndef USE_KERNEL_VIRTUAL_BUFFERS
# if defined(UNDER_CE)
#  define USE_KERNEL_VIRTUAL_BUFFERS  1
# else
#  define USE_KERNEL_VIRTUAL_BUFFERS  1
# endif
#endif

#ifndef USE_NEW_LINUX_SIGNAL
#define USE_NEW_LINUX_SIGNAL            0
#endif

#ifndef USE_LINUX_PCIE
#define USE_LINUX_PCIE                  0
#endif

#ifndef J9_MEDIGLACIAL
#define J9_MEDIGLACIAL                1
#endif

#ifndef J9_WORKBOX
#define J9_WORKBOX                       0
#endif

#ifndef J9_NAOLOGY
#define J9_NAOLOGY                       1
#endif

#ifndef J9_HANDLE_PALMETTOES
#define J9_HANDLE_PALMETTOES            1
#endif

#ifndef J9MIRROR_RIFLEPROOF
#define J9MIRROR_RIFLEPROOF             1
#endif

#ifndef J9_HANDLE_J9_INSTILLING
#define J9_HANDLE_J9_INSTILLING         1
#endif

#define J9_HANDLE_J9MA_PERIOSTOMA           1

#ifndef J9_HADIT
#define J9_HADIT                         0
#endif

#ifndef J9MATHS_OSMOLALITY
#define J9MATHS_OSMOLALITY               0
#endif

#ifndef J9_HANDLE_J_ASSIGNABLY
#define J9_HANDLE_J_ASSIGNABLY           1
#endif

#ifndef J9_BETIDING
#define J9_BETIDING                      0
#endif

#ifndef J9_CANVASSED
#define J9_CANVASSED                     0
#endif

#ifndef J9_HANDLE_J_CHALKSTONE
#define J9_HANDLE_J_CHALKSTONE           0
#endif

#ifndef J9_IRRECIPROCITY
#define J9_IRRECIPROCITY                 0

# if J9_IRRECIPROCITY
#  ifndef J9_HANDLE_PREADAMITE
#   define J9_HANDLE_PREADAMITE                 "process"
#  endif
#  ifndef J9_HANDLE_J9MATHS_GYNIATRICS
#   define J9_HANDLE_J9MATHS_GYNIATRICS         0
#  endif
#  ifndef J9_HANDLE_J9MA_ATTRIBUTE_BESMUTTING
#   define J9_HANDLE_J9MA_ATTRIBUTE_BESMUTTING  0
#  endif
#  ifndef J9_HANDLE_J9MIN_PRINCIPIUM
#   define J9_HANDLE_J9MIN_PRINCIPIUM                   0
#   define J9_HANDLE_J9MATHS_UNEQUALIZE                 10
#  endif
#  ifndef J9_HANDLE_J_ATTRIBUTE_BEHAVIOUR_SEVENPENCE
#   define J9_HANDLE_J_ATTRIBUTE_BEHAVIOUR_SEVENPENCE   0
#  endif
#  ifndef J9_HANDLE_J9MIRROR_BEGGARHOOD
#   define J9_HANDLE_J9MIRROR_BEGGARHOOD    0
#  endif
#  ifndef J9_HANDLE_J9MENU_INDENTWISE
#   define J9_HANDLE_J9MENU_INDENTWISE      0
#  endif

#  ifndef J9_HANDLE_ATTRIBUTE_MISTEACHER
#   define J9_HANDLE_ATTRIBUTE_MISTEACHER   0
#  endif

#  ifndef J9_HANDLE_J9MIRROR_PLASMODIAL
#   define J9_HANDLE_J9MIRROR_PLASMODIAL    0
#  endif

# endif
#endif

#ifndef J9_HANDLE_J9MATHS_CATCHPENNY
#define J9_HANDLE_J9MATHS_CATCHPENNY             1
#endif

#ifndef J9_HANDLE__PREOBSERVE
#define J9_HANDLE__PREOBSERVE                    0
#endif

#ifndef J9_SPARKPLUGGED
#define J9_SPARKPLUGGED                          0
#endif

#ifndef J9_HANDLE_J9MATHS_CRISPATION
#define J9_HANDLE_J9MATHS_CRISPATION             0
#endif

#ifndef J9MIRROR_UNFEMINISE
# if J9_HANDLE__PREOBSERVE
#  define J9MIRROR_UNFEMINISE                  (4 << 10)
# else
#  define J9MIRROR_UNFEMINISE                  (128 << 10)
# endif
#endif

#ifndef J9_HANDLE_J9_UNDERREALM
#define J9_HANDLE_J9_UNDERREALM                  (1 << 10)
#endif

#ifndef J9_SUPELLECTILE
# if J9_HANDLE__PREOBSERVE
#  define J9_SUPELLECTILE                      1
# else
#  define J9_SUPELLECTILE                      2
# endif
#endif

#ifndef J9MIRROR_ARTFULNESS
#define J9MIRROR_ARTFULNESS                      8
#endif

#ifndef J9MATHS_POSTMEATAL
#define J9MATHS_POSTMEATAL                       2
#endif

#ifndef J9_HANDLE_J9_SUBFIGURES
#define J9_HANDLE_J9_SUBFIGURES                  0
#endif

#ifndef J9_REGLOWING
#define J9_REGLOWING                             (256 << 10)
#endif

#ifndef J9_HANDLE_ATTRIBUTE_PRESTORING
#define J9_HANDLE_ATTRIBUTE_PRESTORING           32
#endif

#ifndef J9_HANDLE_J9MENU_CATCHPENNY
#define J9_HANDLE_J9MENU_CATCHPENNY              1
#endif

#ifndef J9_HANDLE_J9MATHS_SPANCELLED
#define J9_HANDLE_J9MATHS_SPANCELLED             1
#endif

#ifndef J9_LABORINGLY
#define J9_LABORINGLY (64 << 10)
#endif

#ifndef J9_HANDLE_J9MENU_MEDICATING
#define J9_HANDLE_J9MENU_MEDICATING              1
#endif

#ifndef J9_ANTISEMITIC
#define J9_ANTISEMITIC                           0
#endif

#ifndef J9_CONIDIOSPORE
# if J9_ANTISEMITIC
#  define J9_CONIDIOSPORE                      100000
# else
#  define J9_CONIDIOSPORE                      20000
# endif
#endif

#ifndef J9MATHS_SUCCUSSION
#define J9MATHS_SUCCUSSION                       4000
#endif

#ifndef J9_HANDLE_RUMINATING
#define J9_HANDLE_RUMINATING                     250
#endif

#ifndef J9_DEUTOPLASMIC
#define J9_DEUTOPLASMIC                          0
#endif

#ifndef J9_ANTIMACASSARS
#define J9_ANTIMACASSARS                         0
#endif

#ifndef J9_HANDLE__UNFEMINISE
#define J9_HANDLE__UNFEMINISE                    1
#endif

#ifndef J9_HANDLE_J9MENU_MARIJUANAS
# if J9_HANDLE__PREOBSERVE
#  define J9_HANDLE_J9MENU_MARIJUANAS          0
# else
#  define J9_HANDLE_J9MENU_MARIJUANAS          1
# endif
#endif

#ifndef J9_HANDLE_J9MA_CHALKSTONE
# if J9_HANDLE__PREOBSERVE
#  define J9_HANDLE_J9MA_CHALKSTONE            0
# else
#  define J9_HANDLE_J9MA_CHALKSTONE            0
# endif
#endif

#ifndef J9MATHS_DIPROTODAN
#define J9MATHS_DIPROTODAN                       12
#endif

#ifndef J9_PHOTOFINISHER
#define J9_PHOTOFINISHER                         14
#endif

#ifndef J9_HANDLE_NONERODING
#define J9_HANDLE_NONERODING                     7
#endif

#ifndef J9_CONSIGNIFICANT
#define J9_CONSIGNIFICANT                        2000
#endif

#ifndef J9_HANDLE_J9MENU_REUNIONISM
#define J9_HANDLE_J9MENU_REUNIONISM              5
#endif

#ifndef J9_HANDLE_CONFICIENT
#define J9_HANDLE_CONFICIENT                     0
#endif

#ifndef J9_HANDLE__REDUNDANCE
#define J9_HANDLE__REDUNDANCE                    0
#endif

#ifndef J9_UNFINICAL
#define J9_UNFINICAL                             0
#define J9MATHS_MATURITIES                       0
#define J9_PHOSPHOROLYTIC                        "/var/log/frameDB.log"
#endif

#ifndef J9_HANDLE_J9MA_ATTRIBUTE_CUREMASTER
#define J9_HANDLE_J9MA_ATTRIBUTE_CUREMASTER      0
#endif

#ifndef J9_HANDLE_J9M_ATTRIBUTE_SCOUTINGLY
#define J9_HANDLE_J9M_ATTRIBUTE_SCOUTINGLY       1
#endif

#ifndef J9_HANDLE_J9MIN_POLITICISE
#define J9_HANDLE_J9MIN_POLITICISE					 1
#endif

#ifndef J9_HANDLE_J9MATHS_POLYGAMIST
#define J9_HANDLE_J9MATHS_POLYGAMIST             0
#endif

#ifndef J9_HANDLE_OVERRENNET
#define J9_HANDLE_OVERRENNET                     300
#endif

#ifndef J9_HANDLE_J9MIRROR_PALEOSTYLY
#define J9_HANDLE_J9MIRROR_PALEOSTYLY           0
#endif

#ifndef J9_HANDLE_J9_ATTRIBUTE_INIMITABLY
#define J9_HANDLE_J9_ATTRIBUTE_INIMITABLY        0
#endif

#ifndef J9_HANDLE_J9MATHS_GREENBOARD
#define J9_HANDLE_J9MATHS_GREENBOARD             1
#endif

#ifndef J9_UNSPARED
#define J9_UNSPARED                              1
#endif

#ifndef J9_HANDLE_HEXAHYDRIC
#define J9_HANDLE_HEXAHYDRIC                     4096
#define J9_HANDLE_J9MIN_STEELINESS               32
#endif

#ifndef J9_HANDLE_J_ATTRIBUTE_MASTECTOMY
#define J9_HANDLE_J_ATTRIBUTE_MASTECTOMY         0
#endif

#ifndef J9_HANDLE_J_TOILETRIES
#if !J9_REANXIETY && defined(LINUX)
#ifdef EMULATOR
#define J9_HANDLE_J_TOILETRIES				  0
#else
#define J9_HANDLE_J_TOILETRIES				  0
#endif
#else
#define J9_HANDLE_J_TOILETRIES				  0
#endif
#endif

#if (defined(EMULATOR) && EMULATOR)
#define JMD_VIRT_ENABLE                                   0
#else
#define JMD_VIRT_ENABLE                                   1
#endif

#ifndef J9_HANDLE_J9MA_UNEJECTIVE
#define J9_HANDLE_J9MA_UNEJECTIVE                0
#endif

#ifndef J9MIRROR_ANCHORITIC
#define J9MIRROR_ANCHORITIC                      64
#endif

#ifndef J9_HANDLE_J9M_HOMOGONIES
#define J9_HANDLE_J9M_HOMOGONIES                 1
#endif

#ifndef J9MIRROR_EPIZOOLOGY
#define J9MIRROR_EPIZOOLOGY                      0
#endif

#ifndef J9_DIOXY
#define J9_DIOXY                                 0
#define J9_HANDLE_J9_UNEJECTIVE                  4
#define J9_HANDLE__OVERKILLED                    (J9_HANDLE_J9_UNEJECTIVE * 4)
#endif

#ifndef J9_PRISM
#define J9_PRISM                                 1
#endif

#ifndef J9_HANDLE_J9MIRROR_JABORANDIS
#define J9_HANDLE_J9MIRROR_JABORANDIS            1
#endif

#ifndef J9_HANDLE_J9MENU_ATTRIBUTE_ANTIRACISM
#define J9_HANDLE_J9MENU_ATTRIBUTE_ANTIRACISM    1
#endif

#ifndef J9_HANDLE_J9MIN_INCOMMIXED
#define J9_HANDLE_J9MIN_INCOMMIXED               0
#endif

#ifndef J9_HANDLE_J9MIRROR_MOGIGRAPHY
#define J9_HANDLE_J9MIRROR_MOGIGRAPHY            1
#endif

#ifndef J9_HANDLE_J9MIRROR_EXTENDIBLE
#define J9_HANDLE_J9MIRROR_EXTENDIBLE            1
#endif

#ifndef J9_HANDLE_J9MENU_ATTRIBUTE_COFFEETIME
#define J9_HANDLE_J9MENU_ATTRIBUTE_COFFEETIME    0
#endif

#ifndef J9_HANDLE__ATTRIBUTE_SLUGGISHLY
#define J9_HANDLE__ATTRIBUTE_SLUGGISHLY          1
#endif

#ifndef J9_HANDLE_J9MIRROR_ACETYLIZER
#define J9_HANDLE_J9MIRROR_ACETYLIZER            0
#endif

#ifndef J9MIRROR_PREDECREED
#define J9MIRROR_PREDECREED                      0
#endif

#ifndef J9_HANDLE_J9MIRROR_ATTRIBUTE_ANTIRACISM
#define J9_HANDLE_J9MIRROR_ATTRIBUTE_ANTIRACISM  1
#endif

#if J9_HANDLE_J9MIRROR_ACETYLIZER
#undef J9_HANDLE_J9MIRROR_ATTRIBUTE_ANTIRACISM
#define J9_HANDLE_J9MIRROR_ATTRIBUTE_ANTIRACISM  0
#endif

#ifndef J9MIRROR_NONNITROUS
#define J9MIRROR_NONNITROUS              1
#endif

#ifndef J9MATHS_ALARMCLOCK
#define J9MATHS_ALARMCLOCK               1
#endif

#ifndef J9_HANDLE_GUNPOWDERY
#define J9_HANDLE_GUNPOWDERY             1
#endif

#ifndef J9MATHS_NONERODING
#define J9MATHS_NONERODING               0
#endif

#ifndef J9_AEROBIOLOGIST
#define J9_AEROBIOLOGIST                 0
#endif

#ifndef J9MATHS_DRAMATIZED
#define J9MATHS_DRAMATIZED               1
#endif

#ifndef J9_PHTHONGOMETER
#define J9_PHTHONGOMETER                 0
#define J9_HANDLE_J9MIN_MONOSILANE       0
#endif

#ifndef J9_COLDS
# define J9_COLDS                         0
# define J9_HANDLE_J9MENU_UNEQUALIZE      1
#else
# if J9_COLDS
#  define J9_HANDLE_J9MENU_UNEQUALIZE  0
# else
#  define J9_HANDLE_J9MENU_UNEQUALIZE  1
# endif
#endif


#ifndef J9_HANDLE_J9_ARROWSTONE
# if defined(LINUX) || defined(__QNXNTO__) || defined(UNDER_CE) || defined(__VXWORKS__)
#  define J9_HANDLE_J9_ARROWSTONE  1
# else
#  define J9_HANDLE_J9_ARROWSTONE  0
# endif
#endif

#ifndef J9_HANDLE_J9MA_TOILETRIES
#define J9_HANDLE_J9MA_TOILETRIES    10000
#endif

#ifndef J9_HANDLE_J_SMOOTHBACK
#define J9_HANDLE_J_SMOOTHBACK       0
#endif

#ifndef J9_HANDLE_J9MENU_POLYGAMIST
#define J9_HANDLE_J9MENU_POLYGAMIST  1
#endif

#ifndef J9_AMPELOPSIDIN
#define J9_AMPELOPSIDIN              0
#endif

#ifndef J9_HANDLE__OVERSCREAM
#define J9_HANDLE__OVERSCREAM        1
#endif

#ifndef J9_HANDLE_UNBLOODIED
#define J9_HANDLE_UNBLOODIED         1
#endif

#ifndef J9_HANDLE_J9M_MAGNETISED
#define J9_HANDLE_J9M_MAGNETISED     0
#endif

#ifndef J9_HANDLE_J9_CHALKSTONE

# if (defined(DBG) && DBG) || defined(DEBUG)               || \
     defined(_DEBUG) || J9_HADIT || J9_HANDLE_J9M_MAGNETISED || \
     (defined(WIN32) && !defined(UNDER_CE))                || \
     J9_ANTISEMITIC
#  define J9_HANDLE_J9_CHALKSTONE  1
# else
#  define J9_HANDLE_J9_CHALKSTONE  0
# endif

#endif

#ifndef J9MATHS_CRYOHYDRIC
#define J9MATHS_CRYOHYDRIC           0
#endif

#ifndef J9_HANDLE_J9MENU_MUSCOLOGIC
#define J9_HANDLE_J9MENU_MUSCOLOGIC  1
#endif

#ifndef J9_DEMISSNESS
#define J9_DEMISSNESS                1
#endif

#ifndef J9_MONGRELISE
#define J9_MONGRELISE                1
#endif

#ifndef JMD_VG_NONE
#define JMD_VG_NONE                   0
#endif

#ifndef J9_COMPATRIOT
#define J9_COMPATRIOT                (0 && !JMD_VG_NONE)
#endif

#ifndef J9_MALURINE
#define J9_MALURINE (!J9_DEMISSNESS && !J9_MONGRELISE && J9_COMPATRIOT)
#endif

#if defined(WIN32) && !defined(UNDER_CE) && (J9_COMPATRIOT == 1)

# ifdef J9_NAOLOGY
#  undef J9_NAOLOGY
# endif

# ifdef J9_HANDLE_J9MA_PERIOSTOMA
#  undef J9_HANDLE_J9MA_PERIOSTOMA
# endif

# ifdef J9_HANDLE_J9MATHS_AZOBENZENE
#  undef J9_HANDLE_J9MATHS_AZOBENZENE
# endif

# ifdef J9_DEMISSNESS
#  undef J9_DEMISSNESS
# endif

# ifdef J9_MONGRELISE
#  undef J9_MONGRELISE
# endif

# define J9_DEMISSNESS                0
# define J9_MONGRELISE                0
# define J9_NAOLOGY                   0
# define J9_HANDLE_J9MA_PERIOSTOMA   2
# define J9_HANDLE_J9MATHS_AZOBENZENE 0

#endif

#ifndef J9MATHS_OMMATIDIUM
#define J9MATHS_OMMATIDIUM					  0
#endif

#ifndef J9MIRROR_SEVILLANAS
# define J9MIRROR_SEVILLANAS                      0
#else
# if (!((J9_DEMISSNESS == 0) && (J9_MONGRELISE == 0) && (J9_COMPATRIOT == 1)))
#  undef J9MIRROR_SEVILLANAS
#  define J9MIRROR_SEVILLANAS                  0
# endif
#endif

#ifndef J9MATHS_INCESSABLE
#define J9MATHS_INCESSABLE                       0
#endif

#ifndef J9_HANDLE_J9MIN_SUBFIGURES
#define J9_HANDLE_J9MIN_SUBFIGURES               0
#endif

#ifndef J9MATHS_FORBEARING
#define J9MATHS_FORBEARING                       0
#endif

#ifndef J9_HANDLE_J9M_INSURRECTO
#define J9_HANDLE_J9M_INSURRECTO                 0
#endif

#ifndef J9_SMOLDERED
#define J9_SMOLDERED                             0
#endif

#ifndef J9_HANDLE_J9MENU_HERETICIZE
#define J9_HANDLE_J9MENU_HERETICIZE              0
#endif

#ifndef J9_HANDLE__CONFICIENT
#define J9_HANDLE__CONFICIENT                    1
#endif

#ifndef J9_HANDLE_J9MATHS_AZOBENZENE
# if (defined(_WIN32) && !defined(UNDER_CE)) || (defined(LINUX) && !defined(EMULATOR))
#  define J9_HANDLE_J9MATHS_AZOBENZENE         0
# else
#  define J9_HANDLE_J9MATHS_AZOBENZENE         0
# endif
#endif


#if J9_REANXIETY
# undef J9_HANDLE_J9MATHS_AZOBENZENE
# define J9_HANDLE_J9MATHS_AZOBENZENE             0
#endif

#ifndef J9_HANDLE_J9M_PROCELLOUS
# if defined(J9_HANDLE__CONFICIENT)
#  define J9_HANDLE_J9M_PROCELLOUS             32
# else
#  define J9_HANDLE_J9M_PROCELLOUS             128
# endif
#endif

#ifndef J9_HANDLE__BOARDWALKS
#define J9_HANDLE__BOARDWALKS                    1
#endif

#ifndef J9_RECOUNTENANCE
#define J9_RECOUNTENANCE                         0
#endif

#ifndef J9MATHS_ABRIDGABLE
#define J9MATHS_ABRIDGABLE                       0
#endif

#ifndef J9_HANDLE__ATTRIBUTE_EXTENDIBLE
#define J9_HANDLE__ATTRIBUTE_EXTENDIBLE          0
#endif

#ifndef J9_HANDLE_J9MIN_ATTRIBUTE_GROUNDWAVE
#define J9_HANDLE_J9MIN_ATTRIBUTE_GROUNDWAVE     1
#endif

#ifndef JMD_ENABLE_KENREL_FENCE
#define J9_HANDLE_J9_RAMPACIOUS                  0
#endif

#ifndef J9MATHS_PREADAMITE
#define J9MATHS_PREADAMITE                       0
#endif

#ifndef J9_HANDLE_J9_FIDUCIALLY
#define J9_HANDLE_J9_FIDUCIALLY                  0
#endif

#ifndef J9_HANDLE_J9MATHS_SMIFLIGATE
#define J9_HANDLE_J9MATHS_SMIFLIGATE          1
#define J9_NONCONSEQUENT                        (16)

#endif

#define J9_ECTOMERIC                                 1

#define J9_HANDLE_J9MENU_CRISPATION                  1

#ifndef J9_HANDLE_J_PHYTOMETRY
#define J9_HANDLE_J_PHYTOMETRY                   0
#endif

#ifndef J9_HANDLE_J9MIRROR_ATTRIBUTE_ETHEROLATE
#define J9_HANDLE_J9MIRROR_ATTRIBUTE_ETHEROLATE  0
#endif

#ifndef J9_HANDLE_J9MA_ATTRIBUTE_RIFLEPROOF
#define J9_HANDLE_J9MA_ATTRIBUTE_RIFLEPROOF      1
#endif

#ifndef J9_HANDLE_J9_CHOCKSTONE
#define J9_HANDLE_J9_CHOCKSTONE                  0
#endif

#ifndef J9_HANDLE_J9M_ASSIGNABLY
#define J9_HANDLE_J9M_ASSIGNABLY                 0
#endif

#ifndef J9_HANDLE_ATTRIBUTE_MOGIGRAPHY
#define J9_HANDLE_ATTRIBUTE_MOGIGRAPHY           0
#endif

#ifndef J9_HANDLE_J9M_FIDUCIALLY
#define J9_HANDLE_J9M_FIDUCIALLY                 0
#endif

#ifndef J9_UNVEERINGLY
#define J9_UNVEERINGLY                           1
#endif

#ifndef J9_HANDLE_REDUNDANCE
#define J9_HANDLE_REDUNDANCE                     0
#endif

#ifndef J9_HANDLE_J9MENU_STREAMLETS
#define J9_HANDLE_J9MENU_STREAMLETS              0
#endif

#ifndef J9_HANDLE__BRONZITITE
#define J9_HANDLE__BRONZITITE                    1
#endif

#ifndef J9_HANDLE_J9MIRROR_PRESTORING
#define J9_HANDLE_J9MIRROR_PRESTORING            1
#endif

#ifndef JMD_ENABLE_VIDEO_MEMORY_MIRROR
#define JMD_ENABLE_VIDEO_MEMORY_MIRROR           1
#endif

#ifndef JMD_STATIC_VIDEO_MEMORY_MIRROR
#define JMD_STATIC_VIDEO_MEMORY_MIRROR           1
#endif

#ifndef JMD_USER_COMMAND_IN_EXCLUSIVE
#define JMD_USER_COMMAND_IN_EXCLUSIVE            0
#endif

#ifndef J9_HANDLE_J9M_SUBFIGURES
#define J9_HANDLE_J9M_SUBFIGURES                 0
#endif

#ifndef JMD_ENABLE_MULTI_DEVICE_MANAGEMENT
#define JMD_ENABLE_MULTI_DEVICE_MANAGEMENT       0
#endif

#ifndef JMD_ENABLE_DEVFREQ
#define JMD_ENABLE_DEVFREQ                       0
#endif

#ifndef JMD_SHARED_COMMAND_BUFFER
#define JMD_SHARED_COMMAND_BUFFER                 0
#endif

#ifndef JMD__2D_PERF_TIMER
#define JMD__2D_PERF_TIMER                        1
#endif


#ifndef J9_HANDLE_ATTRIBUTE_PICTOGRAPH
#define J9_HANDLE_ATTRIBUTE_PICTOGRAPH            1
#endif

#ifndef JMD_ENABLE_VM_PASSTHROUGH
#define JMD_ENABLE_VM_PASSTHROUGH            0
#endif

#endif


