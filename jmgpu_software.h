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


#ifndef __ce1996b1_H_
#define __ce1996b1_H_

#include <linux/version.h>
#include <linux/moduleparam.h>

#define J9_HANDLE_J9M_NOVICELIKE                (0x01200000)
#define J9_HANDLE_J9MIN_INTERESTER              (0x40000)
#define J9_HANDLE_J9MIN_BURSECTOMY(_chan)       (J9_HANDLE_J9M_NOVICELIKE + J9_HANDLE_J9MIN_INTERESTER * (_chan))


#define J9_HANDLE_J9MENU_SCOUTINGLY                       (J9_HANDLE_J9MIRROR_UNHONESTLY + (0x400))

#define J9_HANDLE_J9MIRROR_CELIBATIST(_chan)              (J9_HANDLE_J9MIRROR_UNHONESTLY + (0x6000) + ((_chan) * 0x800))
#define J9_HANDLE_ATTRIBUTE_CHALKSTONE(_chan)             (J9_HANDLE_J9MENU_SCOUTINGLY + ((_chan) * 0x100))

#define J9_HANDLE_J_DEMOLISHED 0x100
#define J9_HANDLE_J_INTERESTER(_chan) (J9_HANDLE_J9MIRROR_UNHONESTLY + (0x400) + (_chan * J9_HANDLE_J_DEMOLISHED))


#define J9_DISGREGATED                          0x0000
#define J9_PROTOGELATOSE                        0x0001
#define J9_UNPERCEPTIBLY                        0x0002
#define J9_ZOOPHYSIOLOGY                        0x0003
#define J9_APHORISTICAL                         0x0004
#define J9_CALLISTHENIC                         0x0005
#define J9_ZIETRISIKITE                         0x0006
#define J9_PREVALESCENT                         0x0007


#define J9_UNRESPONSIBLE                        0x0100
#define J9_INDOCIBLENESS                        0x0101
#define J9_INAPPRECIABLE                        0x0102
#define J9_CRINICULTURAL                        0x0103
#define J9_ANCHORITICALLY                       0x0104
#define J9MATHS_MANEUVERER                      0x0105
#define J9_REACCLIMATIZED                       0x0106
#define J9_SUBLACUSTRINE                        0x0107
#define J9_HANDLE__NONSERVILE                   0x0108
#define J9_HANDLE_J9_CENOTAPHIC                 0x0109

#define J9_HANDLE__APHORIZING                   0x0180
#define J9_HANDLE__DELINEAVIT                   0x0181
#define J9_HANDLE__NONERODING                   0x0182
#define J9_HANDLE__INCESSABLE                   0x0183
#define J9_HANDLE_J_DENEGATION                  0x0184
#define J9_HANDLE_J9_SUPERDUPER                 0x0185
#define J9_HANDLE_J_SUBRECTORY                  0x0186
#define J9_HANDLE__SUICIDICAL                   0x0187
#define J9_HANDLE_J9MIN_TRIPSOMELY              0x0188
#define J9_HANDLE_J9MATHS_HERETICIZE            0x0189
#define J9_CELEBRITY                            0x01FF


#define J9_EXHIBITABLE                          0x0200
#define J9MATHS_ANTERETHIC                      0x0201
#define J9_SEMIELEVATED                         0x0202
#define J9_INTHRALLMENT                         0x0203
#define J9_MOLLUSCICIDAL                        0x0204
#define J9_PURPOSIVENESS                        0x0205
#define J9_UNINVIGORATED                        0x0206
#define J9_NEOPLASTICISM                        0x0207


#define J9_ANCHORITESS                          0x0800
#define J9_POPULARITY                           0x0801
#define J9_PSEUDOSMIA                           0x0802
#define J9_SEMIFLORET                           0x0803
#define J9_ACQUAINTS                            0x0804
#define J9_CHINOVNIK                            0x0805
#define J9_SOLENIUM                             0x0806
#define J9_OVERMORAL                            0x0807
#define J9_CASSOCKS                             0x0808


#define J9_NONRUINOUSNESS                       0x1000
#define J9_PRELIQUIDATED                        0x1001
#define J9_COMPANIONSHIP                        0x1002
#define J9_TRIDIMENSIONED                       0x1003
#define J9_PROTOAMPHIBIAN                       0x1004
#define J9_SEMIOSTRACISM                        0x1005
#define J9_TRICHOSCHISIS                        0x1006
#define J9_SEMITRADITONAL                        0x1007
#define J9_DESTRUCTIONISM                        0x102e
#define J9_HANDLE__PROMULGING                   0x1008
#define J9_HANDLE__PLATYRRHIN                   0x1009
#define J9_HANDLE__OMMATIDIUM                   0x100A
#define J9_HANDLE__ANTHRAMINE                   0x100B
#define J9_HANDLE__AMPHIMIXES                    0x100C
#define J9_HANDLE__ELEMENTISH                    0x102f
#define J9_HANDLE_NONSERVILE                    0x100D
#define J9_CHIEFTAINESS                         0x100E
#define J9_VATICINATION                         0x100F
#define J9_SPHINCTERIAL                         0x1010
#define J9_UNCLASSIFIED                         0x1011
#define J9_DIFFERENTIATOR                       0x1012
#define J9MATHS_DIVINENESS                      0x1013
#define J9_UNTHEORETICAL                        0x1014
#define J9_PROPOLIZATION                        0x1015
#define J9_APOTHEOSIZING                        0x1016
#define J9_MONOTONICALLY                        0x1017
#define J9_SLIMMING                             0x1018
#define J9_MYELONEURITIS                        0x1019
#define J9_URETHROBULBAR                        0x101A
#define J9_AUTOINHIBITED                        0x101B
#define J9_CHRYSAROBIN                          0x101C
#define J9_HALLUCINOSES                         0x101D
#define J9_FLUOTANTALIC                         0x101E
#define J9_REEMIGRATION                         0x101F
#define J9_INDECLINABLY                         0x1020
#define J9_SEDUCTRESSES                         0x1021
#define J9_CIRCUMCENTER                         0x1022
#define J9_NONCERTITUDE                         0x1023
#define J9_MALLOSEISMIC                         0x1024
#define J9_ESTABLISHMENTS                       0x1025
#define J9_REMATRICULATED                       0x1026
#define J9_ELECTROTHERAPY                       0x1027
#define J9_UNADULTEROUSLY                       0x1028
#define J9MATHS_CHATOYANCY                      0x1029
#define J9_DISCRIMINANT                         0x102A
#define J9MATHS_ACQUIRENDA                      0x1030
#define J9MATHS_UNCUTTABLE                      0x1031
#define J9MIRROR_DULCIGENIC                     0x1032
#define J9MIRROR_PROMULGING                     0x1033
#define J9MIRROR_PLATYRRHIN                     0x1034
#define J9MIRROR_OMMATIDIUM                     0x1035
#define J9MIRROR_ANTHRAMINE                     0x1036
#define J9MIRROR_NONSERVILE                     0x1037
#define J9MIRROR_INCESSABLE                     0x1038
#define J9MIRROR_APHORIZING                     0x1039
#define J9MIRROR_DELINEAVIT                     0x103A
#define J9MIRROR_NONERODING                     0x103B
#define J9_HANDLE_HISTOLOGIC                    0x103C
#define J9_HANDLE_CORPULENCE                    0x103D
#define J9_HANDLE_OSMOLALITY                    0x103E
#define J9_HANDLE_INDIGENOUS                    0x103F
#define J9_HANDLE_ANTISTATIC                    0x1040
#define J9_HANDLE_DRAMATIZED                    0x1041
#define J9_HANDLE_SAVORINGLY                    0x1042
#define J9_HANDLE_MATURITIES                    0x1043
#define J9_HANDLE_SUCCUSSION                    0x1044
#define J9_HANDLE_POLYPORITE                    0x1045
#define J9_HANDLE_DULCIGENIC                    0x1046
#define J9_HANDLE_PROMULGING                    0x1047
#define J9_HANDLE_PLATYRRHIN                    0x1048
#define J9_HANDLE_OMMATIDIUM                    0x1049
#define J9_HANDLE_J_TARPAULIAN                  0x104A
#define J9_HANDLE_J_SHOWERIEST                  0x104B
#define J9_HANDLE_J_PARANOIACS                  0x104C
#define J9_HANDLE_J_PRESIDENTE                  0x104D
#define J9_HANDLE_J_PHOTOMURAL                  0x104E
#define J9_HANDLE_J_ARCHIVAULT                  0x104F
#define J9_HANDLE_J_INOCULABLE                  0x1050
#define J9_HANDLE_J_SCAPULETTE                  0x1051
#define J9_HANDLE_J9_SHOWERIEST                 0x1052
#define J9_HANDLE_J9_PARANOIACS                 0x1053
#define J9_HANDLE_J9_PRESIDENTE                 0x1054
#define J9_HANDLE_J9_PHOTOMURAL                 0x1055
#define J9_HANDLE_J9_ARCHIVAULT                 0x1056
#define J9_HANDLE_J9_INOCULABLE                 0x1057
#define J9_HANDLE_J9_SCAPULETTE                 0x1058
#define J9_HANDLE_J9_SUBRECTORY                 0x1059
#define J9_HANDLE_J9_DENEGATION                 0x105A
#define J9_HANDLE_J9_HYPOTARSUS                 0x105B
#define J9_HANDLE_J9M_SCAPULETTE                0x105C
#define J9_HANDLE_J9M_SUBRECTORY                0x105D
#define J9_HANDLE_J9M_DENEGATION                0x105E
#define J9_HANDLE_J9M_HYPOTARSUS                0x105F
#define J9_HANDLE_J9M_CENOTAPHIC                0x1060
#define J9_HANDLE_J9M_SUPERDUPER                0x1061
#define J9_HANDLE_MINELAYERS                    0x1062
#define J9_OVERSUPPLYING                        0x1063
#define J9_DICARBOXYLATE                        0x1064
#define J9_UNRAFTERED                           0x1065
#define J9_RHEOMETRIC                           0x1066
#define J9MATHS_MUTATIONAL                      0x1067
#define J9MATHS_UNARTISTIC                      0x1068
#define J9MATHS_REQUESTERS                      0x1069
#define J9MATHS_RENEGATION                      0x106a
#define J9MATHS_UNDERTRUMP                      0x106b
#define J9MATHS_ONWARDNESS                      0x106c
#define J9MATHS_PHORONOMIA                      0x106d
#define J9MATHS_INCUMBENCY                      0x106e
#define J9MATHS_INKINESSES                      0x106f
#define J9MIRROR_MATURITIES                     0x1070
#define J9MIRROR_SUCCUSSION                     0x1071
#define J9MIRROR_POLYPORITE                     0x1072
#define J9_VIOLONCELLISTS                       0x1073
#define J9_DIGESTIVENESS                        0x1074
#define J9_ACCORDERS                            0x1075
#define J9_INJUSTICES                           0x1076
#define J9_CHECKBOOKS                           0x1077
#define J9_ASSOILMENT                           0x1078
#define J9_ABECEDAIRE                           0x1079
#define J9_INTERPOINT                           0x107A
#define J9_TRIBASILAR                           0x107B
#define J9_PREHORIZON                           0x107C
#define J9_HOMODYNAMY                           0x107D
#define J9_INDUSIATED                           0x107E
#define J9_NONSOLDIER                           0x107F
#define J9_LUMINATION                           0x1080
#define J9_CULICIFORM                           0x1081
#define J9_LECTURETTE                           0x1082
#define J9_REVIGORATE                           0x1083
#define J9_SUBENDORSE                           0x1084
#define J9_PUBESCENCY                           0x1085
#define J9_MONOLITHIC                           0x1086
#define J9_DROLLERIES                           0x1087
#define J9_CIRCULARLY                           0x1088
#define J9_ECLIPTICS                            0x1089
#define J9_TIMESCALE                            0x108A
#define J9_VITELLARY                            0x108B
#define J9_CLATTERED                            0x108C
#define J9_GYPSYWISE                            0x108D
#define J9_ADDLENESS                            0x108E
#define J9_DULCINEAS                            0x108F
#define J9_SUBSUMING                            0x1090
#define J9_SYPHERING                            0x1091
#define J9_PRESCRIPTION                         0x1092
#define J9_SPIRITUALIZED                        0x1093
#define J9_ARBITRARINESS                        0x1094
#define J9_CRYPTOCARPOUS                        0x1095
#define J9_NONBENEFICIAL                        0x1096
#define J9_PAWNBROKERAGE                        0x1097
#define J9_DEVOLUTIONARY                        0x1098
#define J9_CONTRAVARIANT                        0x1099
#define J9_MANNERLINESS                         0x109A
#define J9_SOUSAPHONIST                         0x109B
#define J9_CHAMBERLAINS                         0x109C
#define J9_HYPERMORALLY                         0x109D
#define J9_ELLIPTICALLY                         0x109E
#define J9_MIDSUMMERISH                         0x109F
#define J9_INTERNECINAL                         0x10A0
#define J9_BILIPURPURIN                         0x10A1
#define J9_BROMOAURATES                         0x10A2
#define J9_EXTRACTORSHIP                        0x10A3
#define J9_COLLABORATORS                        0x10A4
#define J9_VELLOZIACEOUS                        0x10A5
#define J9_NONSYNONYMOUS                        0x10A6
#define J9_HAEMAPOPHYSIS                        0x10A7
#define J9_OVERMODIFYING                        0x10A8
#define J9_COMFORTINGLY                         0x10A9
#define J9_APPOSABILITY                         0x10AA
#define J9_STRANGULLION                         0x10AB
#define J9_HYDROPHOBIAS                         0x10AC
#define J9_ARTERIARCTIA                         0x10AD
#define J9_BEGUILEMENTS                         0x10AE
#define J9_RAKISHNESSES                         0x10AF
#define J9_UNMENDACIOUS                         0x10B0
#define J9_INHOSPITABLY                         0x10B1
#define J9_OVERPENALIZE                         0x10B2
#define J9_MESOPRESCUTAL                        0x10B3
#define J9_ARCHICEREBRUM                        0x10B4
#define J9_PSEUDOLATERAL                        0x10B5
#define J9_RETROUSSAGE                          0x10B6
#define J9_DAGUERREOTYPY                        0x10B7
#define J9_APOCARPOUS                           0x10B8
#define J9_THRESHOLDS                           0x10B9
#define J9_PREPYLORIC                           0x10BA
#define J9_UNOCCUPIED                           0x10BB
#define J9_LAURELLING                           0x10BC
#define J9_KARYOLITIC                           0x10BD
#define J9_TRANSPLANT                           0x10BE
#define J9_SNOOZINESS                           0x10BF
#define J9_GOLDENWING                           0x10D0
#define J9_OCCUPIERS                            0x10D1
#define J9_FORMALITER                           0x10D2
#define J9_CROCODILE                            0x10D3
#define J9_GEMELLIONE                           0x10D4
#define J9_DITCHSIDE                            0x10D5
#define J9_CITIZENDOM                           0x10D6
#define J9_COMPUTIST                            0x10D7
#define J9_ARBALISTER                           0x10D8
#define J9_GENEOLOGY                            0x10D9
#define J9_GROCERYMEN                           0x10DA
#define J9_PREDEVOTE                            0x10DB
#define J9_GHOSTFLOWER                          0x10E0
#define J9_HANDLE_J_PERIOSTOMA                  0x10E1
#define J9_HANDLE_J9M_INOCULABLE                0x10E2
#define J9_HANDLE_SULPHUROUS                    0x10E3

#define J9_DETACHABILITY                        0x1100
#define J9_ORTHONORMAL                          0x1101
#define J9_AMPHIBRYOUS                          0x1102
#define J9_UNCONFIDENTLY                        0x1103
#define J9_ARCHVISITOR                          0x1104
#define J9_CRESCENTWISE                         0x1105
#define J9_WEALTHMAKING                         0x1106
#define J9_LEPTOCEPHALY                         0x1107
#define J9_HEARTFULNESS                         0x1108
#define J9_ICONOCLASTIC                         0x1109
#define J9_CLINANDRDRIA                         0x110A
#define J9_UNREMORSEFUL                         0x110B
#define J9_CONTESTATION                         0x110C
#define J9_TICKETMONGER                         0x110D
#define J9_CONTRASTABLY                         0x110E
#define J9_POSTEROMESIAL                        0x110F
#define J9_COCHLEARIFORM                        0x1110
#define J9_MULTIMODALITY                        0x1111
#define J9_SPLENEPATITIS                        0x1112
#define J9_HYDRADEPHAGAN                        0x1113
#define J9_HOMESTRETCHES                        0x1114
#define J9_RETRANSPLANTS                        0x1115
#define J9_PALAEOLITHOID                        0x1116
#define J9_PERIPHLEBITIS                        0x1117
#define J9_CELLULOSITIES                        0x1118
#define J9_MICROGONIDIAL                        0x1119
#define J9_GENTLEMANHOOD                        0x111A
#define J9_TRANSMUTUALLY                        0x111B
#define J9_EXTRASYLLABIC                        0x111C
#define J9_GEUMATOPHOBIA                        0x111D
#define J9_CARDIODILATOR                        0x111E
#define J9_NONDISASTROUS                        0x111F
#define J9_PRESSIROSTRAL                        0x1120

#define J9_MARTIALISTS                          0x1167
#define J9_UNTORPORIFIC                         0x1168
#define J9_PSEUDOSOCIAL                         0x1169
#define J9_SUCCEDANEUMS                         0x116A
#define J9_TRUNCHEONING                         0x116B
#define J9_BARMYBRAINED                         0x116C
#define J9_UNMALEVOLENT                         0x116D
#define J9_DICOTYLEDONS                         0x116E
#define J9_NONDIASTASIC                         0x116F
#define J9_IRREPLACABLY                         0x1170
#define J9_PHOSPHORISED                         0x1171
#define J9_DISCIPLINATE                         0x1172
#define J9_PECCADILLOES                         0x1173
#define J9_NONCOSTRAIGHT                        0x1174
#define J9_NAVICULAEFORM                        0x1175
#define J9_TRICHORRHEXIS                        0x1176
#define J9_LATERIFOLIOUS                        0x1177
#define J9_UNSACRIFICIAL                        0x1178
#define J9_NONLEGUMINOUS                        0x1179
#define J9_NONSENSICALLY                        0x117A
#define J9_ALBOCINEREOUS                        0x117B
#define J9_THANKLESSNESS                        0x117C
#define J9_UNAUSTERENESS                        0x117D
#define J9_INFRASPINATUS                        0x117E
#define J9_IMPERFORMABLE                        0x117F
#define J9_UNDISCLOSABLE                        0x1180
#define J9_OLIGOSPERMOUS                        0x1181
#define J9_REQUISITENESS                        0x1182
#define J9_XANTHODONTOUS                        0x1183
#define J9_VENEREOPHOBIA                        0x1184

#define J9_BENZOTHIAZINE                        0x1200
#define J9MATHS_SIGNATURES                      0x1201
#define J9MATHS_BIDIAGONAL                      0x1202
#define J9MATHS_SKITTYBOOT                      0x1203
#define J9MATHS_CRAQUELURE                      0x1204
#define J9MATHS_CONTRABAND                      0x1205
#define J9MATHS_SEROMANIAC                      0x1206
#define J9MATHS_DEFAITISME                      0x1207
#define J9MATHS_SILVERIEST                      0x1208
#define J9MATHS_DELIQUESCE                      0x1209
#define J9MATHS_INTRATOMIC                      0x120A
#define J9MATHS_PELTATIFID                      0x120B
#define J9MATHS_FORTEMENTE                      0x120C
#define J9MATHS_KLENDUSIVE                      0x120D
#define J9MATHS_SNOBBINESS                      0x120E
#define J9MATHS_CHURNSTAFF                      0x120F
#define J9MATHS_EYESTRAINS                      0x1210
#define J9MATHS_QUASIORDER                      0x1211
#define J9MATHS_ECSTATICAL                      0x1212
#define J9MATHS_NONMELODIC                      0x1213
#define J9MATHS_NONJURIDIC                      0x1214
#define J9MATHS_PLOTTINGLY                      0x1215
#define J9MATHS_TURNAROUND                      0x1216
#define J9MATHS_APOZEMICAL                      0x1217
#define J9MATHS_CLEANLIEST                      0x1218
#define J9_PEPTIDOGLYCAN                        0x1219
#define J9_PENEPLANATION                        0x121A
#define J9_METHEMOGLOBIN                        0x121B


#define J9_INCREMATION                          0x3000
#define J9_OUTCHEATED                           0x3001
#define J9_OVERTHROWS                           0x3002
#define J9_DECAHEDRAL                           0x3003
#define J9_FICTIONALLY                          0x3004
#define J9_EPIBLEMATA                           0x3005
#define J9_PHANTOMLIKE                          0x3006
#define J9_SUBPROCTOR                           0x3007


#define J9_HANDLE_J9M_FLIMSILYST                0x3020
#define J9_HANDLE_J9MIN_ISTHMISTIC              0x3021
#define J9_HANDLE_J9MIN_MAGNETISED              0x3022
#define J9_HANDLE_J9MIN_PROCELLOUS              0x3023
#define J9_HANDLE_J9MIN_PIPEFISHES              0x3024
#define J9_HANDLE_J9MIN_ARROWSTONE              0x3025
#define J9_HANDLE_J9MATHS_MARIJUANAS            0x3026
#define J9_HANDLE_J_CENOTAPHIC                  0x3027
#define J9_HANDLE_J9MA_UNDERTRIBE               0x3028
#define J9_HANDLE_J_HYPOTARSUS                  0x3029
#define J9_HANDLE_J9MENU_MASKALONGE             0x302a
#define J9_HANDLE_J_ATTRIBUTE_COMMENCING        0x302b
#define J9_HANDLE_J_ATTRIBUTE_DISTORTION        0x302c
#define J9_HANDLE_J_ATTRIBUTE_PEDIMENTED        0x302d
#define J9_HANDLE_J_ATTRIBUTE_STICHARION        0x302e
#define J9_HANDLE_J_ATTRIBUTE_DEMOLISHED        0x302f
#define J9_HANDLE_J_ATTRIBUTE_JOINTURESS        0x3030
#define J9_HANDLE_J_ATTRIBUTE_SPORICIDAL        0x3031
#define J9_HANDLE_J_ATTRIBUTE_DOWNLOADED        0x3032


#define J9_TELEKINETIC                          0x3100
#define J9_TRANQUILEST                          0x3101
#define J9_PANICALLY                            0x3102
#define J9_BELLHANGING                          0x3103
#define J9_BAYSMELT                             0x3200
#define J9_MISPLANS                             0x3201
#define J9_UPISLAND                             0x3202
#define J9_WESTERNISE                           0x3203
#define J9_NIGHTDRESS                           0x3204
#define J9_EMBRYULCIA                           0x3205
#define J9MIRROR_DRAMATIZED                     0x3206
#define J9_REAPPROACHABLE			0x3302
#define J9MATHS_SIPHUNCLED                      0x3400
#define J9MIRROR_ANTISTATIC                     0x3401
#define J9_POTENTIALNESS                        0x3402
#define J9_SACROCOTYLOID                        0x3403
#define J9_DIMENSIONALITY                       0x3404

#define J9_UNDERUSHER                           0x3500
#define J9_RELAPSABLE                           0x3501
#define J9_SUPERFOLLY                           0x3502
#define J9_FRUCTUOUS                            0x3503
#define J9_ISOTONIA                             0x3504
#define J9_BUCKEROOS                            0x3505
#define J9_PROCURER                             0x3506


#define J9MATHS_PROVITAMIN                      0x3600
#define J9MATHS_EXTRADOSES                      0x3601
#define J9_ELECTROLYTICAL                       0x3602
#define J9MIRROR_MINELAYERS                     0x3603
#define J9_HANDLE_J9MENU_SPLOTCHING             0x3604
#define J9_HANDLE_J9MENU_OWNERSHIPS             0x3605
#define J9_HANDLE_J9MENU_TUNNELLERS             0x3606
#define J9_HANDLE_J9MENU_SCHEMOZZLE             0x3607
#define J9_HANDLE_J9MENU_MURICULATE             0x3608
#define J9_HANDLE_J9MENU_STEELINESS             0x3609
#define J9_HANDLE_J9MENU_OESOPHAGAL             0x360a
#define J9_HANDLE_J9MENU_INCOMMIXED             0x360b
#define J9_HANDLE__DRAMATIZED                   0x360c
#define J9_HANDLE__SAVORINGLY                   0x360d
#define J9_HANDLE__MATURITIES                   0x360e
#define J9_HANDLE__SUCCUSSION                   0x360f
#define J9_HANDLE_J_REAPPROVAL                  0x3610
#define J9_HANDLE_J_SPASMODIST                  0x3611
#define J9_NONFELONIOUSLY                       0x3614
#define J9_EVOLUTIONISTS                        0x3615
#define J9MATHS_PUNCHPROOF                      0x3616
#define J9_HANDLE__DULCIGENIC                   0x3617
#define J9_HANDLE_FORTEMENTE                    0x3618
#define J9_HANDLE__POLYPORITE                   0x3619
#define J9_HANDLE_CHURNSTAFF                    0x361a
#define J9MATHS_BIPETALOUS                      0x361b
#define J9MIRROR_SULPHUROUS                     0x361c
#define J9MATHS_UNABETTING                      0x361d
#define J9_HANDLE_J9MENU_COPRESENCE             0x3620
#define J9_HANDLE_J9MENU_PENTHOUSES             0x3621
#define J9_HANDLE_J9MENU_POLYTENIES             0x3622
#define J9_HANDLE_J9MENU_SUBCOASTAL             0x3623
#define J9_HANDLE_J9MENU_RETURNABLE             0x3624
#define J9_HANDLE_J9MENU_ADPOSITION             0x3625
#define J9_HANDLE_J9MENU_REJOICINGS             0x3626
#define J9_HANDLE_J9MENU_BISECTIONS             0x3627


#define J9_THYSANUROUS                          0x4000
#define J9_BIOCOENOSIS                          0x4001
#define J9_LATICOSTATE                          0x4002
#define J9_UNFEMINISED                          0x4003
#define J9_EPITHALAMIAST                        0x4004
#define J9_UNVOYAGEABLE                         0x4005
#define J9MIRROR_ALARMCLOCK                     0x4006
#define J9MIRROR_HUMILIATED                     0x4007


#define J9_FANFISHES                            0x4100
#define J9_UNHONORABLE                          0x4101
#define J9_HANDLE_PLOTTINGLY                    0x4102
#define J9_HANDLE_ECSTATICAL                    0x4103
#define J9_HANDLE_DIVINENESS                    0x4104
#define J9_HANDLE_CLEANLIEST                    0x4105
#define J9_HANDLE_ACQUIRENDA                    0x4106
#define J9_HANDLE_CHATOYANCY                    0x4107
#define J9_HANDLE_DAUPHINESS                    0x4108
#define J9_HANDLE_UNCUTTABLE                    0x4109
#define J9_HANDLE_CITYNESSES                    0x410A
#define J9_HANDLE_MANEUVERER                    0x410B
#define J9_HANDLE_SEMESTRIAL                    0x410C
#define J9_HANDLE_ANTERETHIC                    0x410D
#define J9_HANDLE_SORDIDNESS                    0x410E
#define J9_HANDLE_CONQUERING                    0x410F
#define J9_HANDLE_PROSNEUSIS                    0x4110
#define J9_HANDLE_UNCONTRITE                    0x4111
#define J9_HANDLE_DIPROTODAN                    0x4112
#define J9_HANDLE_ABRIDGABLE                    0x4113
#define J9_HANDLE_CORROSIVES                    0x4114
#define J9_HANDLE_FORBEARING                    0x4115
#define J9_HANDLE_UNCIFEROUS                    0x4116
#define J9_HANDLE_POSTMEATAL                    0x4117
#define J9_HANDLE_CRYOHYDRIC                    0x4118
#define J9_HANDLE_PERIDINIAN                    0x4119


#define J9_PROTHYSTERON                         0x5000
#define J9_MULTINUCLEAR                         0x5001
#define J9_CONSIGNATORY                         0x5002
#define J9_GALVANOMETER                         0x5003
#define J9_ANKYLOPHOBIA                         0x5004
#define J9_MUNICIPALITY                         0x5005
#define J9_STOMATOGRAPHY                        0x5006
#define J9_NEUROPSYCHOSIS                       0x5007
#define J9_ELECTROPHILIC                        0x5008
#define J9_TELECOMPUTING                        0x5009
#define J9_BEACHCOMBERS                         0x500A
#define J9MIRROR_HISTOLOGIC                     0x500B
#define J9MIRROR_CORPULENCE                     0x500C
#define J9MIRROR_OSMOLALITY                     0x500D
#define J9MIRROR_INDIGENOUS                     0x500E
#define J9_REFLOATATION                         0x500F
#define J9_MONETARIST                           0x5010
#define J9_BLONDENESS                           0x5011
#define J9_DRAWFILING                           0x5012
#define J9_LEUCOCIDIC                           0x5013
#define J9_APPARENTATION                        0x5014
#define J9_EXPLANATIVELY                        0x5015
#define J9_PHILOSOPHIC                          0x5016
#define J9_TALLOWMAKING                         0x5017
#define J9_DIVERTICULATE                        0x5018
#define J9_EXTRANEOUSLY                         0x5019
#define J9_HIEROGLYPHER                         0x501A
#define J9_COUNTERSENSE                         0x5020


#define J9_ADJUSTMENTAL                         0x7E00
#define J9_FRIGHTENEDNESS                       0x7E01
#define J9_SUBTERRANEAN                         0x7E02
#define J9_TUNDAGSLATTA                         0x7E03
#define J9MIRROR_SUICIDICAL                     0x7E04
#define J9_EIGENVALUE                           0x7E05
#define J9_CHROMONEMATIC                        0x7E06
#define J9_VENERACEAN                           0x7E07
#define J9_OVERAMPLIFYING                       0x7E08
#define J9MATHS_DAUPHINESS                      0x7E09
#define J9_UNINTERDICTED                        0x7E0A
#define J9_HANDLE_J9MATHS_EQUIPOISED            0x7E0B
#define J9_HANDLE_J9MATHS_DOWAGERISM            0x7E0C
#define J9_HANDLE_J9MATHS_REUNIONISM            0x7E0D
#define J9_HANDLE_J9MATHS_ANIMALNESS            0x7E0E
#define J9_HANDLE_J9MATHS_PREINSURED            0x7E0F
#define J9_HANDLE_J9MATHS_HANDYFIGHT            0x7E10
#define J9_HANDLE_J9MATHS_DEEDHOLDER            0x7E11
#define J9_HANDLE_J9MATHS_ACECAFFINE            0x7E12

enum {

	HDMI_PRODUCT_ID0_HDMI_TX = 0xa0,


	HDMI_PRODUCT_ID1_HDCP = 0xc0,
	HDMI_PRODUCT_ID1_HDMI_RX = 0x02,
	HDMI_PRODUCT_ID1_HDMI_TX = 0x01,


	HDMI_CONFIG0_I2S = 0x10,
	HDMI_CONFIG0_CEC = 0x02,


	HDMI_CONFIG1_AHB = 0x01,


	HDMI_CONFIG3_AHBAUDDMA = 0x02,
	HDMI_CONFIG3_GPAUD = 0x01,


	HDMI_IH_FC_INT2_OVERFLOW_MASK = 0x03,
	HDMI_IH_FC_INT2_LOW_PRIORITY_OVERFLOW = 0x02,
	HDMI_IH_FC_INT2_HIGH_PRIORITY_OVERFLOW = 0x01,


	HDMI_IH_FC_STAT2_OVERFLOW_MASK = 0x03,
	HDMI_IH_FC_STAT2_LOW_PRIORITY_OVERFLOW = 0x02,
	HDMI_IH_FC_STAT2_HIGH_PRIORITY_OVERFLOW = 0x01,


	HDMI_IH_PHY_STAT0_RX_SENSE3 = 0x20,
	HDMI_IH_PHY_STAT0_RX_SENSE2 = 0x10,
	HDMI_IH_PHY_STAT0_RX_SENSE1 = 0x8,
	HDMI_IH_PHY_STAT0_RX_SENSE0 = 0x4,
	HDMI_IH_PHY_STAT0_TX_PHY_LOCK = 0x2,
	HDMI_IH_PHY_STAT0_HPD = 0x1,


	HDMI_IH_I2CM_STAT0_DONE = 0x2,
	HDMI_IH_I2CM_STAT0_ERROR = 0x1,


	HDMI_IH_MUTE_I2CMPHY_STAT0_I2CMPHYDONE = 0x2,
	HDMI_IH_MUTE_I2CMPHY_STAT0_I2CMPHYERROR = 0x1,


	HDMI_IH_AHBDMAAUD_STAT0_BUFFOVERRUN = 0x40,
	HDMI_IH_AHBDMAAUD_STAT0_ERROR = 0x20,
	HDMI_IH_AHBDMAAUD_STAT0_LOST = 0x10,
	HDMI_IH_AHBDMAAUD_STAT0_RETRY = 0x08,
	HDMI_IH_AHBDMAAUD_STAT0_DONE = 0x04,
	HDMI_IH_AHBDMAAUD_STAT0_BUFFFULL = 0x02,
	HDMI_IH_AHBDMAAUD_STAT0_BUFFEMPTY = 0x01,
	HDMI_IH_AHBDMAAUD_STAT0_MASK =
	    (HDMI_IH_AHBDMAAUD_STAT0_BUFFOVERRUN |
	     HDMI_IH_AHBDMAAUD_STAT0_ERROR |
	     HDMI_IH_AHBDMAAUD_STAT0_LOST |
	     HDMI_IH_AHBDMAAUD_STAT0_RETRY |
	     HDMI_IH_AHBDMAAUD_STAT0_DONE |
	     HDMI_IH_AHBDMAAUD_STAT0_BUFFFULL |
	     HDMI_IH_AHBDMAAUD_STAT0_BUFFEMPTY),


	HDMI_IH_MUTE_FC_STAT2_OVERFLOW_MASK = 0x03,
	HDMI_IH_MUTE_FC_STAT2_LOW_PRIORITY_OVERFLOW = 0x02,
	HDMI_IH_MUTE_FC_STAT2_HIGH_PRIORITY_OVERFLOW = 0x01,


	HDMI_IH_MUTE_AHBDMAAUD_STAT0_BUFFOVERRUN = 0x40,
	HDMI_IH_MUTE_AHBDMAAUD_STAT0_ERROR = 0x20,
	HDMI_IH_MUTE_AHBDMAAUD_STAT0_LOST = 0x10,
	HDMI_IH_MUTE_AHBDMAAUD_STAT0_RETRY = 0x08,
	HDMI_IH_MUTE_AHBDMAAUD_STAT0_DONE = 0x04,
	HDMI_IH_MUTE_AHBDMAAUD_STAT0_BUFFFULL = 0x02,
	HDMI_IH_MUTE_AHBDMAAUD_STAT0_BUFFEMPTY = 0x01,
	HDMI_IH_MUTE_AHBDMAAUD_STAT0_MASK =
	    (HDMI_IH_MUTE_AHBDMAAUD_STAT0_BUFFOVERRUN |
	     HDMI_IH_MUTE_AHBDMAAUD_STAT0_ERROR |
	     HDMI_IH_MUTE_AHBDMAAUD_STAT0_LOST |
	     HDMI_IH_MUTE_AHBDMAAUD_STAT0_RETRY |
	     HDMI_IH_MUTE_AHBDMAAUD_STAT0_DONE |
	     HDMI_IH_MUTE_AHBDMAAUD_STAT0_BUFFFULL |
	     HDMI_IH_MUTE_AHBDMAAUD_STAT0_BUFFEMPTY),


	HDMI_IH_MUTE_MUTE_WAKEUP_INTERRUPT = 0x2,
	HDMI_IH_MUTE_MUTE_ALL_INTERRUPT = 0x1,
	HDMI_IH_MUTE_MUTE_MASK =
	    (HDMI_IH_MUTE_MUTE_WAKEUP_INTERRUPT |
	     HDMI_IH_MUTE_MUTE_ALL_INTERRUPT),


	HDMI_TX_INVID0_INTERNAL_DE_GENERATOR_MASK = 0x80,
	HDMI_TX_INVID0_INTERNAL_DE_GENERATOR_ENABLE = 0x80,
	HDMI_TX_INVID0_INTERNAL_DE_GENERATOR_DISABLE = 0x00,
	HDMI_TX_INVID0_VIDEO_MAPPING_MASK = 0x1F,
	HDMI_TX_INVID0_VIDEO_MAPPING_OFFSET = 0,


	HDMI_TX_INSTUFFING_BDBDATA_STUFFING_MASK = 0x4,
	HDMI_TX_INSTUFFING_BDBDATA_STUFFING_ENABLE = 0x4,
	HDMI_TX_INSTUFFING_BDBDATA_STUFFING_DISABLE = 0x0,
	HDMI_TX_INSTUFFING_RCRDATA_STUFFING_MASK = 0x2,
	HDMI_TX_INSTUFFING_RCRDATA_STUFFING_ENABLE = 0x2,
	HDMI_TX_INSTUFFING_RCRDATA_STUFFING_DISABLE = 0x0,
	HDMI_TX_INSTUFFING_GYDATA_STUFFING_MASK = 0x1,
	HDMI_TX_INSTUFFING_GYDATA_STUFFING_ENABLE = 0x1,
	HDMI_TX_INSTUFFING_GYDATA_STUFFING_DISABLE = 0x0,


	HDMI_VP_PR_CD_COLOR_DEPTH_MASK = 0xF0,
	HDMI_VP_PR_CD_COLOR_DEPTH_OFFSET = 4,
	HDMI_VP_PR_CD_DESIRED_PR_FACTOR_MASK = 0x0F,
	HDMI_VP_PR_CD_DESIRED_PR_FACTOR_OFFSET = 0,


	HDMI_VP_STUFF_IDEFAULT_PHASE_MASK = 0x20,
	HDMI_VP_STUFF_IDEFAULT_PHASE_OFFSET = 5,
	HDMI_VP_STUFF_IFIX_PP_TO_LAST_MASK = 0x10,
	HDMI_VP_STUFF_IFIX_PP_TO_LAST_OFFSET = 4,
	HDMI_VP_STUFF_ICX_GOTO_P0_ST_MASK = 0x8,
	HDMI_VP_STUFF_ICX_GOTO_P0_ST_OFFSET = 3,
	HDMI_VP_STUFF_YCC422_STUFFING_MASK = 0x4,
	HDMI_VP_STUFF_YCC422_STUFFING_STUFFING_MODE = 0x4,
	HDMI_VP_STUFF_YCC422_STUFFING_DIRECT_MODE = 0x0,
	HDMI_VP_STUFF_PP_STUFFING_MASK = 0x2,
	HDMI_VP_STUFF_PP_STUFFING_STUFFING_MODE = 0x2,
	HDMI_VP_STUFF_PP_STUFFING_DIRECT_MODE = 0x0,
	HDMI_VP_STUFF_PR_STUFFING_MASK = 0x1,
	HDMI_VP_STUFF_PR_STUFFING_STUFFING_MODE = 0x1,
	HDMI_VP_STUFF_PR_STUFFING_DIRECT_MODE = 0x0,


	HDMI_VP_CONF_BYPASS_EN_MASK = 0x40,
	HDMI_VP_CONF_BYPASS_EN_ENABLE = 0x40,
	HDMI_VP_CONF_BYPASS_EN_DISABLE = 0x00,
	HDMI_VP_CONF_PP_EN_ENMASK = 0x20,
	HDMI_VP_CONF_PP_EN_ENABLE = 0x20,
	HDMI_VP_CONF_PP_EN_DISABLE = 0x00,
	HDMI_VP_CONF_PR_EN_MASK = 0x10,
	HDMI_VP_CONF_PR_EN_ENABLE = 0x10,
	HDMI_VP_CONF_PR_EN_DISABLE = 0x00,
	HDMI_VP_CONF_YCC422_EN_MASK = 0x8,
	HDMI_VP_CONF_YCC422_EN_ENABLE = 0x8,
	HDMI_VP_CONF_YCC422_EN_DISABLE = 0x0,
	HDMI_VP_CONF_BYPASS_SELECT_MASK = 0x4,
	HDMI_VP_CONF_BYPASS_SELECT_VID_PACKETIZER = 0x4,
	HDMI_VP_CONF_BYPASS_SELECT_PIX_REPEATER = 0x0,
	HDMI_VP_CONF_OUTPUT_SELECTOR_MASK = 0x3,
	HDMI_VP_CONF_OUTPUT_SELECTOR_BYPASS = 0x3,
	HDMI_VP_CONF_OUTPUT_SELECTOR_YCC422 = 0x1,
	HDMI_VP_CONF_OUTPUT_SELECTOR_PP = 0x0,


	HDMI_VP_REMAP_MASK = 0x3,
	HDMI_VP_REMAP_YCC422_24bit = 0x2,
	HDMI_VP_REMAP_YCC422_20bit = 0x1,
	HDMI_VP_REMAP_YCC422_16bit = 0x0,


	HDMI_FC_INVIDCONF_HDCP_KEEPOUT_MASK = 0x80,
	HDMI_FC_INVIDCONF_HDCP_KEEPOUT_ACTIVE = 0x80,
	HDMI_FC_INVIDCONF_HDCP_KEEPOUT_INACTIVE = 0x00,
	HDMI_FC_INVIDCONF_VSYNC_IN_POLARITY_MASK = 0x40,
	HDMI_FC_INVIDCONF_VSYNC_IN_POLARITY_ACTIVE_HIGH = 0x40,
	HDMI_FC_INVIDCONF_VSYNC_IN_POLARITY_ACTIVE_LOW = 0x00,
	HDMI_FC_INVIDCONF_HSYNC_IN_POLARITY_MASK = 0x20,
	HDMI_FC_INVIDCONF_HSYNC_IN_POLARITY_ACTIVE_HIGH = 0x20,
	HDMI_FC_INVIDCONF_HSYNC_IN_POLARITY_ACTIVE_LOW = 0x00,
	HDMI_FC_INVIDCONF_DE_IN_POLARITY_MASK = 0x10,
	HDMI_FC_INVIDCONF_DE_IN_POLARITY_ACTIVE_HIGH = 0x10,
	HDMI_FC_INVIDCONF_DE_IN_POLARITY_ACTIVE_LOW = 0x00,
	HDMI_FC_INVIDCONF_DVI_MODEZ_MASK = 0x8,
	HDMI_FC_INVIDCONF_DVI_MODEZ_HDMI_MODE = 0x8,
	HDMI_FC_INVIDCONF_DVI_MODEZ_DVI_MODE = 0x0,
	HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC_MASK = 0x2,
	HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC_ACTIVE_HIGH = 0x2,
	HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC_ACTIVE_LOW = 0x0,
	HDMI_FC_INVIDCONF_IN_I_P_MASK = 0x1,
	HDMI_FC_INVIDCONF_IN_I_P_INTERLACED = 0x1,
	HDMI_FC_INVIDCONF_IN_I_P_PROGRESSIVE = 0x0,


	HDMI_FC_AUDICONF0_CC_OFFSET = 4,
	HDMI_FC_AUDICONF0_CC_MASK = 0x70,
	HDMI_FC_AUDICONF0_CT_OFFSET = 0,
	HDMI_FC_AUDICONF0_CT_MASK = 0xF,


	HDMI_FC_AUDICONF1_SS_OFFSET = 4,
	HDMI_FC_AUDICONF1_SS_MASK = 0x30,
	HDMI_FC_AUDICONF1_SF_OFFSET = 0,
	HDMI_FC_AUDICONF1_SF_MASK = 0x7,


	HDMI_FC_AUDICONF3_LFEPBL_OFFSET = 5,
	HDMI_FC_AUDICONF3_LFEPBL_MASK = 0x60,
	HDMI_FC_AUDICONF3_DM_INH_OFFSET = 4,
	HDMI_FC_AUDICONF3_DM_INH_MASK = 0x10,
	HDMI_FC_AUDICONF3_LSV_OFFSET = 0,
	HDMI_FC_AUDICONF3_LSV_MASK = 0xF,


	HDMI_FC_AUDSCHNLS0_CGMSA_OFFSET = 4,
	HDMI_FC_AUDSCHNLS0_CGMSA_MASK = 0x30,
	HDMI_FC_AUDSCHNLS0_COPYRIGHT_OFFSET = 0,
	HDMI_FC_AUDSCHNLS0_COPYRIGHT_MASK = 0x01,


	HDMI_FC_AUDSCHNLS3_OIEC_CH0_OFFSET = 0,
	HDMI_FC_AUDSCHNLS3_OIEC_CH0_MASK = 0x0f,
	HDMI_FC_AUDSCHNLS3_OIEC_CH1_OFFSET = 4,
	HDMI_FC_AUDSCHNLS3_OIEC_CH1_MASK = 0xf0,
	HDMI_FC_AUDSCHNLS4_OIEC_CH2_OFFSET = 0,
	HDMI_FC_AUDSCHNLS4_OIEC_CH2_MASK = 0x0f,
	HDMI_FC_AUDSCHNLS4_OIEC_CH3_OFFSET = 4,
	HDMI_FC_AUDSCHNLS4_OIEC_CH3_MASK = 0xf0,

	HDMI_FC_AUDSCHNLS5_OIEC_CH0_OFFSET = 0,
	HDMI_FC_AUDSCHNLS5_OIEC_CH0_MASK = 0x0f,
	HDMI_FC_AUDSCHNLS5_OIEC_CH1_OFFSET = 4,
	HDMI_FC_AUDSCHNLS5_OIEC_CH1_MASK = 0xf0,
	HDMI_FC_AUDSCHNLS6_OIEC_CH2_OFFSET = 0,
	HDMI_FC_AUDSCHNLS6_OIEC_CH2_MASK = 0x0f,
	HDMI_FC_AUDSCHNLS6_OIEC_CH3_OFFSET = 4,
	HDMI_FC_AUDSCHNLS6_OIEC_CH3_MASK = 0xf0,


	HDMI_FC_AUDSCHNLS7_ACCURACY_OFFSET = 4,
	HDMI_FC_AUDSCHNLS7_ACCURACY_MASK = 0x30,
	HDMI_FC_AUDSCHNLS7_SAMPFREQ_OFFSET = 0,
	HDMI_FC_AUDSCHNLS7_SAMPFREQ_MASK = 0x0f,


	HDMI_FC_AUDSCHNLS8_ORIGSAMPFREQ_MASK = 0xf0,
	HDMI_FC_AUDSCHNLS8_ORIGSAMPFREQ_OFFSET = 4,
	HDMI_FC_AUDSCHNLS8_WORDLEGNTH_MASK = 0x0f,
	HDMI_FC_AUDSCHNLS8_WORDLEGNTH_OFFSET = 0,


	HDMI_FC_AUDSCONF_AUD_PACKET_SAMPFIT_MASK = 0xF0,
	HDMI_FC_AUDSCONF_AUD_PACKET_SAMPFIT_OFFSET = 4,
	HDMI_FC_AUDSCONF_AUD_PACKET_LAYOUT_MASK = 0x1,
	HDMI_FC_AUDSCONF_AUD_PACKET_LAYOUT_OFFSET = 0,
	HDMI_FC_AUDSCONF_AUD_PACKET_LAYOUT_LAYOUT1 = 0x1,
	HDMI_FC_AUDSCONF_AUD_PACKET_LAYOUT_LAYOUT0 = 0x0,


	HDMI_FC_STAT2_OVERFLOW_MASK = 0x03,
	HDMI_FC_STAT2_LOW_PRIORITY_OVERFLOW = 0x02,
	HDMI_FC_STAT2_HIGH_PRIORITY_OVERFLOW = 0x01,


	HDMI_FC_INT2_OVERFLOW_MASK = 0x03,
	HDMI_FC_INT2_LOW_PRIORITY_OVERFLOW = 0x02,
	HDMI_FC_INT2_HIGH_PRIORITY_OVERFLOW = 0x01,


	HDMI_FC_MASK2_OVERFLOW_MASK = 0x03,
	HDMI_FC_MASK2_LOW_PRIORITY_OVERFLOW = 0x02,
	HDMI_FC_MASK2_HIGH_PRIORITY_OVERFLOW = 0x01,


	HDMI_FC_PRCONF_INCOMING_PR_FACTOR_MASK = 0xF0,
	HDMI_FC_PRCONF_INCOMING_PR_FACTOR_OFFSET = 4,
	HDMI_FC_PRCONF_OUTPUT_PR_FACTOR_MASK = 0x0F,
	HDMI_FC_PRCONF_OUTPUT_PR_FACTOR_OFFSET = 0,


	HDMI_FC_PACKET_TX_EN_DRM_MASK = 0x80,
	HDMI_FC_PACKET_TX_EN_DRM_ENABLE = 0x80,
	HDMI_FC_PACKET_TX_EN_DRM_DISABLE = 0x00,


	HDMI_FC_AVICONF0_PIX_FMT_MASK = 0x03,
	HDMI_FC_AVICONF0_PIX_FMT_RGB = 0x00,
	HDMI_FC_AVICONF0_PIX_FMT_YCBCR422 = 0x01,
	HDMI_FC_AVICONF0_PIX_FMT_YCBCR444 = 0x02,
	HDMI_FC_AVICONF0_ACTIVE_FMT_MASK = 0x40,
	HDMI_FC_AVICONF0_ACTIVE_FMT_INFO_PRESENT = 0x40,
	HDMI_FC_AVICONF0_ACTIVE_FMT_NO_INFO = 0x00,
	HDMI_FC_AVICONF0_BAR_DATA_MASK = 0x0C,
	HDMI_FC_AVICONF0_BAR_DATA_NO_DATA = 0x00,
	HDMI_FC_AVICONF0_BAR_DATA_VERT_BAR = 0x04,
	HDMI_FC_AVICONF0_BAR_DATA_HORIZ_BAR = 0x08,
	HDMI_FC_AVICONF0_BAR_DATA_VERT_HORIZ_BAR = 0x0C,
	HDMI_FC_AVICONF0_SCAN_INFO_MASK = 0x30,
	HDMI_FC_AVICONF0_SCAN_INFO_OVERSCAN = 0x10,
	HDMI_FC_AVICONF0_SCAN_INFO_UNDERSCAN = 0x20,
	HDMI_FC_AVICONF0_SCAN_INFO_NODATA = 0x00,

	HDMI_FC_AVICONF1_ACTIVE_ASPECT_RATIO_MASK = 0x0F,
	HDMI_FC_AVICONF1_ACTIVE_ASPECT_RATIO_USE_CODED = 0x08,
	HDMI_FC_AVICONF1_ACTIVE_ASPECT_RATIO_4_3 = 0x09,
	HDMI_FC_AVICONF1_ACTIVE_ASPECT_RATIO_16_9 = 0x0A,
	HDMI_FC_AVICONF1_ACTIVE_ASPECT_RATIO_14_9 = 0x0B,
	HDMI_FC_AVICONF1_CODED_ASPECT_RATIO_MASK = 0x30,
	HDMI_FC_AVICONF1_CODED_ASPECT_RATIO_NO_DATA = 0x00,
	HDMI_FC_AVICONF1_CODED_ASPECT_RATIO_4_3 = 0x10,
	HDMI_FC_AVICONF1_CODED_ASPECT_RATIO_16_9 = 0x20,
	HDMI_FC_AVICONF1_COLORIMETRY_MASK = 0xC0,
	HDMI_FC_AVICONF1_COLORIMETRY_NO_DATA = 0x00,
	HDMI_FC_AVICONF1_COLORIMETRY_SMPTE = 0x40,
	HDMI_FC_AVICONF1_COLORIMETRY_ITUR = 0x80,
	HDMI_FC_AVICONF1_COLORIMETRY_EXTENDED_INFO = 0xC0,

	HDMI_FC_AVICONF2_SCALING_MASK = 0x03,
	HDMI_FC_AVICONF2_SCALING_NONE = 0x00,
	HDMI_FC_AVICONF2_SCALING_HORIZ = 0x01,
	HDMI_FC_AVICONF2_SCALING_VERT = 0x02,
	HDMI_FC_AVICONF2_SCALING_HORIZ_VERT = 0x03,
	HDMI_FC_AVICONF2_RGB_QUANT_MASK = 0x0C,
	HDMI_FC_AVICONF2_RGB_QUANT_DEFAULT = 0x00,
	HDMI_FC_AVICONF2_RGB_QUANT_LIMITED_RANGE = 0x04,
	HDMI_FC_AVICONF2_RGB_QUANT_FULL_RANGE = 0x08,
	HDMI_FC_AVICONF2_EXT_COLORIMETRY_MASK = 0x70,
	HDMI_FC_AVICONF2_EXT_COLORIMETRY_XVYCC601 = 0x00,
	HDMI_FC_AVICONF2_EXT_COLORIMETRY_XVYCC709 = 0x10,
	HDMI_FC_AVICONF2_EXT_COLORIMETRY_SYCC601 = 0x20,
	HDMI_FC_AVICONF2_EXT_COLORIMETRY_ADOBE_YCC601 = 0x30,
	HDMI_FC_AVICONF2_EXT_COLORIMETRY_ADOBE_RGB = 0x40,
	HDMI_FC_AVICONF2_IT_CONTENT_MASK = 0x80,
	HDMI_FC_AVICONF2_IT_CONTENT_NO_DATA = 0x00,
	HDMI_FC_AVICONF2_IT_CONTENT_VALID = 0x80,

	HDMI_FC_AVICONF3_IT_CONTENT_TYPE_MASK = 0x03,
	HDMI_FC_AVICONF3_IT_CONTENT_TYPE_GRAPHICS = 0x00,
	HDMI_FC_AVICONF3_IT_CONTENT_TYPE_PHOTO = 0x01,
	HDMI_FC_AVICONF3_IT_CONTENT_TYPE_CINEMA = 0x02,
	HDMI_FC_AVICONF3_IT_CONTENT_TYPE_GAME = 0x03,
	HDMI_FC_AVICONF3_QUANT_RANGE_MASK = 0x0C,
	HDMI_FC_AVICONF3_QUANT_RANGE_LIMITED = 0x00,
	HDMI_FC_AVICONF3_QUANT_RANGE_FULL = 0x04,


	HDMI_FC_DBGFORCE_FORCEAUDIO = 0x10,
	HDMI_FC_DBGFORCE_FORCEVIDEO = 0x1,


	HDMI_FC_DATAUTO0_VSD_MASK = 0x08,
	HDMI_FC_DATAUTO0_VSD_OFFSET = 3,


	HDMI_PHY_CONF0_PDZ_MASK = 0x80,
	HDMI_PHY_CONF0_PDZ_OFFSET = 7,
	HDMI_PHY_CONF0_ENTMDS_MASK = 0x40,
	HDMI_PHY_CONF0_ENTMDS_OFFSET = 6,
	HDMI_PHY_CONF0_SVSRET_MASK = 0x20,
	HDMI_PHY_CONF0_SVSRET_OFFSET = 5,
	HDMI_PHY_CONF0_GEN2_PDDQ_MASK = 0x10,
	HDMI_PHY_CONF0_GEN2_PDDQ_OFFSET = 4,
	HDMI_PHY_CONF0_GEN2_TXPWRON_MASK = 0x8,
	HDMI_PHY_CONF0_GEN2_TXPWRON_OFFSET = 3,
	HDMI_PHY_CONF0_GEN2_ENHPDRXSENSE_MASK = 0x4,
	HDMI_PHY_CONF0_GEN2_ENHPDRXSENSE_OFFSET = 2,
	HDMI_PHY_CONF0_SELDATAENPOL_MASK = 0x2,
	HDMI_PHY_CONF0_SELDATAENPOL_OFFSET = 1,
	HDMI_PHY_CONF0_SELDIPIF_MASK = 0x1,
	HDMI_PHY_CONF0_SELDIPIF_OFFSET = 0,


	HDMI_PHY_TST0_TSTCLR_MASK = 0x20,
	HDMI_PHY_TST0_TSTCLR_OFFSET = 5,
	HDMI_PHY_TST0_TSTEN_MASK = 0x10,
	HDMI_PHY_TST0_TSTEN_OFFSET = 4,
	HDMI_PHY_TST0_TSTCLK_MASK = 0x1,
	HDMI_PHY_TST0_TSTCLK_OFFSET = 0,


	HDMI_PHY_RX_SENSE3 = 0x80,
	HDMI_PHY_RX_SENSE2 = 0x40,
	HDMI_PHY_RX_SENSE1 = 0x20,
	HDMI_PHY_RX_SENSE0 = 0x10,
	HDMI_PHY_HPD = 0x02,
	HDMI_PHY_TX_PHY_LOCK = 0x01,


	HDMI_PHY_I2CM_SLAVE_ADDR_PHY_GEN2 = 0x69,
	HDMI_PHY_I2CM_SLAVE_ADDR_HEAC_PHY = 0x49,


	HDMI_PHY_I2CM_OPERATION_ADDR_WRITE = 0x10,
	HDMI_PHY_I2CM_OPERATION_ADDR_READ = 0x1,


	HDMI_PHY_I2CM_INT_ADDR_DONE_POL = 0x08,
	HDMI_PHY_I2CM_INT_ADDR_DONE_MASK = 0x04,


	HDMI_PHY_I2CM_CTLINT_ADDR_NAC_POL = 0x80,
	HDMI_PHY_I2CM_CTLINT_ADDR_NAC_MASK = 0x40,
	HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_POL = 0x08,
	HDMI_PHY_I2CM_CTLINT_ADDR_ARBITRATION_MASK = 0x04,


	HDMI_AUD_CONF0_SW_RESET = 0x80,
	HDMI_AUD_CONF0_I2S_SELECT = 0x20,
	HDMI_AUD_CONF0_I2S_EN3 = 0x08,
	HDMI_AUD_CONF0_I2S_EN2 = 0x04,
	HDMI_AUD_CONF0_I2S_EN1 = 0x02,
	HDMI_AUD_CONF0_I2S_EN0 = 0x01,


	HDMI_AUD_CONF1_MODE_I2S = 0x00,
	HDMI_AUD_CONF1_MODE_RIGHT_J = 0x20,
	HDMI_AUD_CONF1_MODE_LEFT_J = 0x40,
	HDMI_AUD_CONF1_MODE_BURST_1 = 0x60,
	HDMI_AUD_CONF1_MODE_BURST_2 = 0x80,
	HDMI_AUD_CONF1_WIDTH_16 = 0x10,
	HDMI_AUD_CONF1_WIDTH_24 = 0x18,


	HDMI_AUD_CTS3_N_SHIFT_OFFSET = 5,
	HDMI_AUD_CTS3_N_SHIFT_MASK = 0xe0,
	HDMI_AUD_CTS3_N_SHIFT_1 = 0,
	HDMI_AUD_CTS3_N_SHIFT_16 = 0x20,
	HDMI_AUD_CTS3_N_SHIFT_32 = 0x40,
	HDMI_AUD_CTS3_N_SHIFT_64 = 0x60,
	HDMI_AUD_CTS3_N_SHIFT_128 = 0x80,
	HDMI_AUD_CTS3_N_SHIFT_256 = 0xa0,
	HDMI_AUD_CTS3_CTS_MANUAL = 0x10,
	HDMI_AUD_CTS3_AUDCTS19_16_MASK = 0x0f,


	HDMI_AUD_INPUTCLKFS_128FS = 0,
	HDMI_AUD_INPUTCLKFS_256FS = 1,
	HDMI_AUD_INPUTCLKFS_512FS = 2,
	HDMI_AUD_INPUTCLKFS_64FS = 4,


	HDMI_AHB_DMA_CONF0_SW_FIFO_RST = 0x80,
	HDMI_AHB_DMA_CONF0_INSERT_PCUV = 0x40,
	HDMI_AHB_DMA_CONF0_HBR = 0x10,
	HDMI_AHB_DMA_CONF0_EN_HLOCK_MASK = 0x08,
	HDMI_AHB_DMA_CONF0_INCR_TYPE_MASK = 0x06,
	HDMI_AHB_DMA_CONF0_INCR16 = 0x6,
	HDMI_AHB_DMA_CONF0_INCR8 = 0x4,
	HDMI_AHB_DMA_CONF0_INCR4 = 0x2,
	HDMI_AHB_DMA_CONF0_BURST_MODE = 0x1,


	HDMI_AHB_DMA_START_START_OFFSET = 0,
	HDMI_AHB_DMA_START_START_MASK = 0x01,


	HDMI_AHB_DMA_STOP_STOP_OFFSET = 0,
	HDMI_AHB_DMA_STOP_STOP_MASK = 0x01,


	HDMI_AHB_DMA_DONE = 0x80,
	HDMI_AHB_DMA_RETRY_SPLIT = 0x40,
	HDMI_AHB_DMA_LOSTOWNERSHIP = 0x20,
	HDMI_AHB_DMA_ERROR = 0x10,
	HDMI_AHB_DMA_FIFO_THREMPTY = 0x04,
	HDMI_AHB_DMA_FIFO_FULL = 0x02,
	HDMI_AHB_DMA_FIFO_EMPTY = 0x01,
	HDMI_AHB_DMA_MASK_MASK =
	    (HDMI_AHB_DMA_DONE |
	     HDMI_AHB_DMA_RETRY_SPLIT |
	     HDMI_AHB_DMA_LOSTOWNERSHIP |
	     HDMI_AHB_DMA_ERROR |
	     HDMI_AHB_DMA_FIFO_THREMPTY |
	     HDMI_AHB_DMA_FIFO_FULL | HDMI_AHB_DMA_FIFO_EMPTY),


	HDMI_AHB_DMA_BUFFSTAT_FULL = 0x02,
	HDMI_AHB_DMA_BUFFSTAT_EMPTY = 0x01,


	HDMI_MC_CLKDIS_HDCPCLK_DISABLE = 0x40,
	HDMI_MC_CLKDIS_CECCLK_DISABLE = 0x20,
	HDMI_MC_CLKDIS_CSCCLK_DISABLE = 0x10,
	HDMI_MC_CLKDIS_AUDCLK_DISABLE = 0x8,
	HDMI_MC_CLKDIS_PREPCLK_DISABLE = 0x4,
	HDMI_MC_CLKDIS_TMDSCLK_DISABLE = 0x2,
	HDMI_MC_CLKDIS_PIXELCLK_DISABLE = 0x1,


	HDMI_MC_SWRSTZ_I2SSWRST_REQ = 0x08,
	HDMI_MC_SWRSTZ_TMDSSWRST_REQ = 0x02,


	HDMI_MC_FLOWCTRL_FEED_THROUGH_OFF_MASK = 0x1,
	HDMI_MC_FLOWCTRL_FEED_THROUGH_OFF_CSC_IN_PATH = 0x1,
	HDMI_MC_FLOWCTRL_FEED_THROUGH_OFF_CSC_BYPASS = 0x0,


	HDMI_MC_PHYRSTZ_PHYRSTZ = 0x01,


	HDMI_MC_HEACPHY_RST_ASSERT = 0x1,
	HDMI_MC_HEACPHY_RST_DEASSERT = 0x0,


	HDMI_CSC_CFG_INTMODE_MASK = 0x30,
	HDMI_CSC_CFG_INTMODE_OFFSET = 4,
	HDMI_CSC_CFG_INTMODE_DISABLE = 0x00,
	HDMI_CSC_CFG_INTMODE_CHROMA_INT_FORMULA1 = 0x10,
	HDMI_CSC_CFG_INTMODE_CHROMA_INT_FORMULA2 = 0x20,
	HDMI_CSC_CFG_DECMODE_MASK = 0x3,
	HDMI_CSC_CFG_DECMODE_OFFSET = 0,
	HDMI_CSC_CFG_DECMODE_DISABLE = 0x0,
	HDMI_CSC_CFG_DECMODE_CHROMA_INT_FORMULA1 = 0x1,
	HDMI_CSC_CFG_DECMODE_CHROMA_INT_FORMULA2 = 0x2,
	HDMI_CSC_CFG_DECMODE_CHROMA_INT_FORMULA3 = 0x3,


	HDMI_CSC_SCALE_CSC_COLORDE_PTH_MASK = 0xF0,
	HDMI_CSC_SCALE_CSC_COLORDE_PTH_24BPP = 0x00,
	HDMI_CSC_SCALE_CSC_COLORDE_PTH_30BPP = 0x50,
	HDMI_CSC_SCALE_CSC_COLORDE_PTH_36BPP = 0x60,
	HDMI_CSC_SCALE_CSC_COLORDE_PTH_48BPP = 0x70,
	HDMI_CSC_SCALE_CSCSCALE_MASK = 0x03,


	HDMI_A_HDCPCFG0_ELVENA_MASK = 0x80,
	HDMI_A_HDCPCFG0_ELVENA_ENABLE = 0x80,
	HDMI_A_HDCPCFG0_ELVENA_DISABLE = 0x00,
	HDMI_A_HDCPCFG0_I2CFASTMODE_MASK = 0x40,
	HDMI_A_HDCPCFG0_I2CFASTMODE_ENABLE = 0x40,
	HDMI_A_HDCPCFG0_I2CFASTMODE_DISABLE = 0x00,
	HDMI_A_HDCPCFG0_BYPENCRYPTION_MASK = 0x20,
	HDMI_A_HDCPCFG0_BYPENCRYPTION_ENABLE = 0x20,
	HDMI_A_HDCPCFG0_BYPENCRYPTION_DISABLE = 0x00,
	HDMI_A_HDCPCFG0_SYNCRICHECK_MASK = 0x10,
	HDMI_A_HDCPCFG0_SYNCRICHECK_ENABLE = 0x10,
	HDMI_A_HDCPCFG0_SYNCRICHECK_DISABLE = 0x00,
	HDMI_A_HDCPCFG0_AVMUTE_MASK = 0x8,
	HDMI_A_HDCPCFG0_AVMUTE_ENABLE = 0x8,
	HDMI_A_HDCPCFG0_AVMUTE_DISABLE = 0x0,
	HDMI_A_HDCPCFG0_RXDETECT_MASK = 0x4,
	HDMI_A_HDCPCFG0_RXDETECT_ENABLE = 0x4,
	HDMI_A_HDCPCFG0_RXDETECT_DISABLE = 0x0,
	HDMI_A_HDCPCFG0_EN11FEATURE_MASK = 0x2,
	HDMI_A_HDCPCFG0_EN11FEATURE_ENABLE = 0x2,
	HDMI_A_HDCPCFG0_EN11FEATURE_DISABLE = 0x0,
	HDMI_A_HDCPCFG0_HDMIDVI_MASK = 0x1,
	HDMI_A_HDCPCFG0_HDMIDVI_HDMI = 0x1,
	HDMI_A_HDCPCFG0_HDMIDVI_DVI = 0x0,


	HDMI_A_HDCPCFG1_DISSHA1CHECK_MASK = 0x8,
	HDMI_A_HDCPCFG1_DISSHA1CHECK_DISABLE = 0x8,
	HDMI_A_HDCPCFG1_DISSHA1CHECK_ENABLE = 0x0,
	HDMI_A_HDCPCFG1_PH2UPSHFTENC_MASK = 0x4,
	HDMI_A_HDCPCFG1_PH2UPSHFTENC_ENABLE = 0x4,
	HDMI_A_HDCPCFG1_PH2UPSHFTENC_DISABLE = 0x0,
	HDMI_A_HDCPCFG1_ENCRYPTIONDISABLE_MASK = 0x2,
	HDMI_A_HDCPCFG1_ENCRYPTIONDISABLE_DISABLE = 0x2,
	HDMI_A_HDCPCFG1_ENCRYPTIONDISABLE_ENABLE = 0x0,
	HDMI_A_HDCPCFG1_SWRESET_MASK = 0x1,
	HDMI_A_HDCPCFG1_SWRESET_ASSERT = 0x0,


	HDMI_A_VIDPOLCFG_UNENCRYPTCONF_MASK = 0x60,
	HDMI_A_VIDPOLCFG_UNENCRYPTCONF_OFFSET = 5,
	HDMI_A_VIDPOLCFG_DATAENPOL_MASK = 0x10,
	HDMI_A_VIDPOLCFG_DATAENPOL_ACTIVE_HIGH = 0x10,
	HDMI_A_VIDPOLCFG_DATAENPOL_ACTIVE_LOW = 0x0,
	HDMI_A_VIDPOLCFG_VSYNCPOL_MASK = 0x8,
	HDMI_A_VIDPOLCFG_VSYNCPOL_ACTIVE_HIGH = 0x8,
	HDMI_A_VIDPOLCFG_VSYNCPOL_ACTIVE_LOW = 0x0,
	HDMI_A_VIDPOLCFG_HSYNCPOL_MASK = 0x2,
	HDMI_A_VIDPOLCFG_HSYNCPOL_ACTIVE_HIGH = 0x2,
	HDMI_A_VIDPOLCFG_HSYNCPOL_ACTIVE_LOW = 0x0,


	HDMI_I2CM_OPERATION_WRITE = 0x10,
	HDMI_I2CM_OPERATION_READ_EXT = 0x2,
	HDMI_I2CM_OPERATION_READ = 0x1,


	HDMI_I2CM_INT_DONE_POL = 0x8,
	HDMI_I2CM_INT_DONE_MASK = 0x4,


	HDMI_I2CM_CTLINT_NAC_POL = 0x80,
	HDMI_I2CM_CTLINT_NAC_MASK = 0x40,
	HDMI_I2CM_CTLINT_ARB_POL = 0x8,
	HDMI_I2CM_CTLINT_ARB_MASK = 0x4,
};

#define J9_HANDLE_J_SENATORIAL			0x00
#define J9_HANDLE_J9MA_CLINICIANS		0x01
#define J9_HANDLE_J9M_PHOTOMURAL		0x02
#define J9_HANDLE_J9MATHS_OUTWEIGHED		0x03
#define J9_HANDLE_J9M_ARCHIVAULT		0x04
#define J9_HANDLE_J9M_SPASMODIST		0x05
#define J9_HANDLE_J9M_OVERPEOPLE		0x06
#define J9_HANDLE_J9MATHS_TOPHETICAL		0x07
#define J9_HANDLE_J9MA_HOMOGONIES		0x08
#define J9_HANDLE_J9MIN_DREARIHEAD		0x09
#define J9_HANDLE_J9MA_FLIMSILYST		0x0a
#define J9_HANDLE_J9MA_SUPERDUPER		0x0b
#define J9_HANDLE_J9MIN_CHOCKSTONE		0x0c
#define J9_HANDLE_J9_OVERPEOPLE			0x0d
#define J9_HANDLE_J9_TARPAULIAN			0x0e
#define J9_HANDLE_J_ESTAFETTED			0x0f
#define J9_HANDLE_J9_REAPPROVAL			0x10
#define J9_HANDLE_J9MA_CENTERMOST		0x11
#define J9_HANDLE_J9MIN_FIDUCIALLY		0x12
#define J9_HANDLE_J9MIN_ASSIGNABLY		0x13
#define J9_HANDLE_J9_SPASMODIST			0x14
#define J9_HANDLE_J_DOGMATISED			0x15
#define J9_HANDLE_J9MENU_DESOLATELY		0x16
#define J9_HANDLE_J9_PERIOSTOMA			0x17
#define J9_HANDLE_J9MENU_ARECACEOUS		0x18
#define J9_HANDLE__ANTISTATIC			0x19
#define J9_HANDLE_J9MA_UNDERREALM		0x1a
#define J9_HANDLE_J9MA_BALLASTING		0x1b
#define J9_HANDLE_J9MA_COMMANDERY		0x1c
#define J9_HANDLE_J9M_PRESIDENTE		0x1d
#define J9_HANDLE_J9M_PERIOSTOMA		0x1e
#define J9_HANDLE_J9MA_HARBOUROUS		0x1f
#define J9_HANDLE_J9M_TARPAULIAN		0x20
#define J9_HANDLE_J9M_SHOWERIEST		0x21
#define J9_HANDLE_J9M_PARANOIACS		0x22
#define J9_HANDLE_J9MIN_CHALKSTONE		0x23
#define J9_HANDLE_J9MIN_TOILETRIES		0x24
#define J9_HANDLE_J9MATHS_INDENTWISE		0x25
#define J9_HANDLE_J9MIRROR_BILOCATION		0x26


#define J9_HANDLE_J9_ATTRIBUTE_AUTOGENIES		BIT(15)


#define J9_HANDLE_J9MATHS_ATTRIBUTE_OXAMETHANE		BIT(13)
#define J9_HANDLE_J9M_ATTRIBUTE_BEHAVIOUR_HOUSESMITH	(0 << 1)
#define J9_HANDLE_J9MA_ATTRIBUTE_PARAPSIDAL		(1 << 1)
#define J9_HANDLE_J9MIN_ATTRIBUTE_CHORIOMATA		(2 << 1)
#define J9_HANDLE_J9MATHS_ATTRIBUTE_PRENEGLECT		(3 << 1)
#define J9_HANDLE_J9MIN_ATTRIBUTE_PREPERFECT		BIT(0)


#define J9_HANDLE_J9M_ATTRIBUTE_INTERESTER		BIT(15)
#define J9_HANDLE_J9MATHS_ATTRIBUTE_MISQUALITY		BIT(8)
#define J9_HANDLE_J9MATHS_ATTRIBUTE_TARTRONATE		BIT(7)
#define J9_HANDLE_J9MATHS_ATTRIBUTE_EXTRANEOUS		BIT(6)
#define J9_HANDLE_J9MIN_ATTRIBUTE_BRAZENNESS		BIT(5)
#define J9_HANDLE_J9M_ATTRIBUTE_BURSECTOMY		BIT(4)
#define J9_HANDLE_J_ATTRIBUTE_BEHAVIOUR_MORBIDNESS	BIT(3)
#define J9_HANDLE_J9M_ATTRIBUTE_INIMITABLY		BIT(2)
#define J9_HANDLE_J9MATHS_ATTRIBUTE_REMODIFIED		BIT(1)
#define J9_HANDLE_J9MIN_ATTRIBUTE_INSTILLING		BIT(0)

#if LINUX_VERSION_CODE <= KERNEL_VERSION(4, 11, 0)


#define MEDIA_BUS_FMT_FIXED			0x0001


#define MEDIA_BUS_FMT_RGB444_1X12		0x1016
#define MEDIA_BUS_FMT_RGB444_2X8_PADHI_BE	0x1001
#define MEDIA_BUS_FMT_RGB444_2X8_PADHI_LE	0x1002
#define MEDIA_BUS_FMT_RGB555_2X8_PADHI_BE	0x1003
#define MEDIA_BUS_FMT_RGB555_2X8_PADHI_LE	0x1004
#define MEDIA_BUS_FMT_RGB565_1X16		0x1017
#define MEDIA_BUS_FMT_BGR565_2X8_BE		0x1005
#define MEDIA_BUS_FMT_BGR565_2X8_LE		0x1006
#define MEDIA_BUS_FMT_RGB565_2X8_BE		0x1007
#define MEDIA_BUS_FMT_RGB565_2X8_LE		0x1008
#define MEDIA_BUS_FMT_RGB666_1X18		0x1009
#define MEDIA_BUS_FMT_RBG888_1X24		0x100e
#define MEDIA_BUS_FMT_RGB666_1X24_CPADHI	0x1015
#define MEDIA_BUS_FMT_RGB666_1X7X3_SPWG		0x1010
#define MEDIA_BUS_FMT_BGR888_1X24		0x1013
#define MEDIA_BUS_FMT_GBR888_1X24		0x1014
#define MEDIA_BUS_FMT_RGB888_1X24		0x100a
#define MEDIA_BUS_FMT_RGB888_2X12_BE		0x100b
#define MEDIA_BUS_FMT_RGB888_2X12_LE		0x100c
#define MEDIA_BUS_FMT_RGB888_1X7X4_SPWG		0x1011
#define MEDIA_BUS_FMT_RGB888_1X7X4_JEIDA	0x1012
#define MEDIA_BUS_FMT_ARGB8888_1X32		0x100d
#define MEDIA_BUS_FMT_RGB888_1X32_PADHI		0x100f
#define MEDIA_BUS_FMT_RGB101010_1X30		0x1018
#define MEDIA_BUS_FMT_RGB121212_1X36		0x1019
#define MEDIA_BUS_FMT_RGB161616_1X48		0x101a


#define MEDIA_BUS_FMT_Y8_1X8			0x2001
#define MEDIA_BUS_FMT_UV8_1X8			0x2015
#define MEDIA_BUS_FMT_UYVY8_1_5X8		0x2002
#define MEDIA_BUS_FMT_VYUY8_1_5X8		0x2003
#define MEDIA_BUS_FMT_YUYV8_1_5X8		0x2004
#define MEDIA_BUS_FMT_YVYU8_1_5X8		0x2005
#define MEDIA_BUS_FMT_UYVY8_2X8			0x2006
#define MEDIA_BUS_FMT_VYUY8_2X8			0x2007
#define MEDIA_BUS_FMT_YUYV8_2X8			0x2008
#define MEDIA_BUS_FMT_YVYU8_2X8			0x2009
#define MEDIA_BUS_FMT_Y10_1X10			0x200a
#define MEDIA_BUS_FMT_UYVY10_2X10		0x2018
#define MEDIA_BUS_FMT_VYUY10_2X10		0x2019
#define MEDIA_BUS_FMT_YUYV10_2X10		0x200b
#define MEDIA_BUS_FMT_YVYU10_2X10		0x200c
#define MEDIA_BUS_FMT_Y12_1X12			0x2013
#define MEDIA_BUS_FMT_UYVY12_2X12		0x201c
#define MEDIA_BUS_FMT_VYUY12_2X12		0x201d
#define MEDIA_BUS_FMT_YUYV12_2X12		0x201e
#define MEDIA_BUS_FMT_YVYU12_2X12		0x201f
#define MEDIA_BUS_FMT_UYVY8_1X16		0x200f
#define MEDIA_BUS_FMT_VYUY8_1X16		0x2010
#define MEDIA_BUS_FMT_YUYV8_1X16		0x2011
#define MEDIA_BUS_FMT_YVYU8_1X16		0x2012
#define MEDIA_BUS_FMT_YDYUYDYV8_1X16		0x2014
#define MEDIA_BUS_FMT_UYVY10_1X20		0x201a
#define MEDIA_BUS_FMT_VYUY10_1X20		0x201b
#define MEDIA_BUS_FMT_YUYV10_1X20		0x200d
#define MEDIA_BUS_FMT_YVYU10_1X20		0x200e
#define MEDIA_BUS_FMT_VUY8_1X24			0x2024
#define MEDIA_BUS_FMT_YUV8_1X24			0x2025
#define MEDIA_BUS_FMT_UYYVYY8_0_5X24		0x2026
#define MEDIA_BUS_FMT_UYVY12_1X24		0x2020
#define MEDIA_BUS_FMT_VYUY12_1X24		0x2021
#define MEDIA_BUS_FMT_YUYV12_1X24		0x2022
#define MEDIA_BUS_FMT_YVYU12_1X24		0x2023
#define MEDIA_BUS_FMT_YUV10_1X30		0x2016
#define MEDIA_BUS_FMT_UYYVYY10_0_5X30		0x2027
#define MEDIA_BUS_FMT_AYUV8_1X32		0x2017
#define MEDIA_BUS_FMT_UYYVYY12_0_5X36		0x2028
#define MEDIA_BUS_FMT_YUV12_1X36		0x2029
#define MEDIA_BUS_FMT_YUV16_1X48		0x202a
#define MEDIA_BUS_FMT_UYYVYY16_0_5X48		0x202b


#define MEDIA_BUS_FMT_SBGGR8_1X8		0x3001
#define MEDIA_BUS_FMT_SGBRG8_1X8		0x3013
#define MEDIA_BUS_FMT_SGRBG8_1X8		0x3002
#define MEDIA_BUS_FMT_SRGGB8_1X8		0x3014
#define MEDIA_BUS_FMT_SBGGR10_ALAW8_1X8		0x3015
#define MEDIA_BUS_FMT_SGBRG10_ALAW8_1X8		0x3016
#define MEDIA_BUS_FMT_SGRBG10_ALAW8_1X8		0x3017
#define MEDIA_BUS_FMT_SRGGB10_ALAW8_1X8		0x3018
#define MEDIA_BUS_FMT_SBGGR10_DPCM8_1X8		0x300b
#define MEDIA_BUS_FMT_SGBRG10_DPCM8_1X8		0x300c
#define MEDIA_BUS_FMT_SGRBG10_DPCM8_1X8		0x3009
#define MEDIA_BUS_FMT_SRGGB10_DPCM8_1X8		0x300d
#define MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_BE	0x3003
#define MEDIA_BUS_FMT_SBGGR10_2X8_PADHI_LE	0x3004
#define MEDIA_BUS_FMT_SBGGR10_2X8_PADLO_BE	0x3005
#define MEDIA_BUS_FMT_SBGGR10_2X8_PADLO_LE	0x3006
#define MEDIA_BUS_FMT_SBGGR10_1X10		0x3007
#define MEDIA_BUS_FMT_SGBRG10_1X10		0x300e
#define MEDIA_BUS_FMT_SGRBG10_1X10		0x300a
#define MEDIA_BUS_FMT_SRGGB10_1X10		0x300f
#define MEDIA_BUS_FMT_SBGGR12_1X12		0x3008
#define MEDIA_BUS_FMT_SGBRG12_1X12		0x3010
#define MEDIA_BUS_FMT_SGRBG12_1X12		0x3011
#define MEDIA_BUS_FMT_SRGGB12_1X12		0x3012
#define MEDIA_BUS_FMT_SBGGR14_1X14		0x3019
#define MEDIA_BUS_FMT_SGBRG14_1X14		0x301a
#define MEDIA_BUS_FMT_SGRBG14_1X14		0x301b
#define MEDIA_BUS_FMT_SRGGB14_1X14		0x301c
#define MEDIA_BUS_FMT_SBGGR16_1X16		0x301d
#define MEDIA_BUS_FMT_SGBRG16_1X16		0x301e
#define MEDIA_BUS_FMT_SGRBG16_1X16		0x301f
#define MEDIA_BUS_FMT_SRGGB16_1X16		0x3020


#define MEDIA_BUS_FMT_JPEG_1X8			0x4001




#define MEDIA_BUS_FMT_S5C_UYVY_JPEG_1X8		0x5001


#define MEDIA_BUS_FMT_AHSV8888_1X32		0x6001
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 19, 0)
enum v4l2_ycbcr_encoding {
	V4L2_YCBCR_ENC_DEFAULT = 0,


	V4L2_YCBCR_ENC_601 = 1,


	V4L2_YCBCR_ENC_709 = 2,


	V4L2_YCBCR_ENC_XV601 = 3,


	V4L2_YCBCR_ENC_XV709 = 4,


	V4L2_YCBCR_ENC_SYCC = 5,


	V4L2_YCBCR_ENC_BT2020 = 6,


	V4L2_YCBCR_ENC_BT2020_CONST_LUM = 7,


	V4L2_YCBCR_ENC_SMPTE240M = 8,
};
#endif

#endif


