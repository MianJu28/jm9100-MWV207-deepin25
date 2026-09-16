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





#ifndef __jmgpu_hal_eglplatform_type_h_
#define __jmgpu_hal_eglplatform_type_h_

#ifdef __cplusplus
extern "C" {
#endif


typedef struct _halKeyMap {

    halKeys normal;


    halKeys extended;
} halKeyMap;


typedef struct _halEvent {

    halEventType type;


    union _halEventData {

        struct _halKeyboard {

            halKeys scancode;


            char    key;


            char    pressed;
        } keyboard;


        struct _halPointer {

            int     x;
            int     y;
        } pointer;


        struct _halButton {

            int     left;


            int     middle;


            int     right;


            int     x;
            int     y;
        } button;
    } data;
} halEvent;

typedef struct _halDISPLAY_INFO {

    int                 width;
    int                 height;

    int                 stride;


    int                 bitsPerPixel;

    void                *logical;

    unsigned long       physical;


    int                 wrapFB;


    int                 multiBuffer;
    int                 backBufferY;


    int                 tiledBuffer;
    int                 tileStatus;
    int                 compression;


    unsigned int        alphaLength;
    unsigned int        alphaOffset;
    unsigned int        redLength;
    unsigned int        redOffset;
    unsigned int        greenLength;
    unsigned int        greenOffset;
    unsigned int        blueLength;
    unsigned int        blueOffset;


    int flip;
} halDISPLAY_INFO;

#ifdef __cplusplus
}
#endif

#endif


