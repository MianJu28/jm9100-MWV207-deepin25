#####################Set BUILD_TYPE#####################
BUILD_TYPE     ?=JMGPU_TRUECHIP
ifeq ($(BUILD_TYPE),JMGPU_TRUECHIP)
X11_DRI3               =1
ENABLE_KMS             =1
JMGPU_ENABLE_3D        =1
SOC_PLATFORM           =jmgpu
GL4_DRI_BUILD          =1
JMGPU_ENABLE_DRM       =1
ENABLE_KMS_2D          =1
EXTRA_CFLAGS          +=-DMWV207_TRUECHIP_BUILD
EGL_API_FB			   =1
EGL_API_GBM			   =1
USE_VDK				   =1
FPGA_BUILD             =1
LINUX_EMULATOR         =0
USE_PLATFORM_DRIVER    =0
BUILD_TARGET           =jmgpu
BUILD_OPENCL_ICD       =1
ENABLE_CL_GL           =1
else ifeq ($(BUILD_TYPE),JMGPU_TRUECHIP_FB)
X11_DRI3               =0
ENABLE_KMS             =1
JMGPU_ENABLE_3D        =1
SOC_PLATFORM           =jmgpu
GL4_DRI_BUILD          =0
JMGPU_ENABLE_DRM       =1
ENABLE_KMS_2D          =1
EXTRA_CFLAGS          +=-DMWV207_TRUECHIP_BUILD
EGL_API_FB             =1
EGL_API_GBM            =0
USE_VDK                =1
FPGA_BUILD             =1
LINUX_EMULATOR         =0
USE_PLATFORM_DRIVER    =0
BUILD_TARGET           =jmgpu
BUILD_OPENCL_ICD       =1
ENABLE_CL_GL           =1
else
$(error "Please set BUILD_TYPE")
endif
OS=$(shell cat /etc/os-release | sed -n '/^ID=/p' | sed -e 's/"//g' -e 's/ID=//g' )
ifeq ($(ARCH_TYPE),)
    result=$(shell uname -m)

    ifeq ($(result),aarch64)
        ARCH_TYPE=arm64
    endif

    ifeq ($(result),mips64)
        ARCH_TYPE=mips
    endif

    ifeq ($(result),x86_64)
        ARCH_TYPE=x86_64
    endif

    ifeq ($(result),loongarch64)
        ARCH_TYPE=loongarch
    endif
    ifeq ($(result),sw_64)
        EXTRA_CFLAGS+=-D_MWV207_SW_64_
	ifeq ($(OS),kylin)
		EXTRA_CFLAGS+=-D_MWV207_SW64_KYLIN
	endif
    endif

    ifeq ($(ARCH_TYPE),)
        ARCH_TYPE=$(shell uname -m)
    endif
endif

ifeq ($(OS), neokylin)
    EXTRA_CFLAGS += -DNEOKYLIN50
endif


export $(ARCH_TYPE)

ifeq ($(KVER),)
export KERNEL_DIR=/lib/modules/$(shell uname -r)/build/
else
export KERNEL_DIR=/lib/modules/$(KVER)/build/
endif
export ROOTFS=/
export TOOLCHAIN=/usr
export CROSS_COMPILE=""
export CPU_TYPE=
export CPU_ARCH=
export USE_LINUX_PCIE=1

DEBUG                          ?=0
ABI                            =0
LINUX_OABI                     =0
NO_DMA_COHERENT                =0
USE_VDK                        =1
JMGPU_NO_VG                  =1
J9_DEUTOPLASMIC                 =0
CUSTOM_PIXMAP                  =0
USE_FB_DOUBLE_BUFFER           =0
USE_PLATFORM_DRIVER           ?=0
CONFIG_DOVEXC5_BOARD          ?=0
FPGA_BUILD                    ?=0

EGL_API_FB                    ?=0
EGL_API_DFB                   ?=0
EGL_API_DRI                   ?=0
EGL_API_X                     ?=0
X11_DRI3                      ?=0
EGL_API_WL                    ?=0
EGL_API_GBM                   ?=0
EGL_API_NULLWS                ?=0
USE_OPENCL                    ?=1
USE_OPENVX                    ?=0
USE_VULKAN                    ?=1
ENABLE_GPU_CLOCK_BY_DRIVER    ?=0
GL4_DRI_BUILD                 ?=0

ifeq ($(ARCH_TYPE),x86_64)
    ENABLE_ARM_L2_CACHE       =0
    JMD_NO_POWER_MANAGEMENT    ?=1
    USE_POWER_MANAGEMENT      ?=0
endif


JMGPU_ENABLE_3D                 ?= 1
JMGPU_ENABLE_2D                 ?= 0
JMGPU_ENABLE_VG                 ?= 0
JMGPU_ENABLE_DRM                ?= 1
NO_DMA_COHERENT                   ?= 0
USE_PLATFORM_DRIVER               ?= 1
ENABLE_GPU_CLOCK_BY_DRIVER        ?= 1
CACHE_FUNCTION_UNIMPLEMENTED      ?= 0
USE_BANK_ALIGNMENT                ?= 0
BANK_BIT_START                    ?= 0
BANK_BIT_END                      ?= 0
BANK_CHANNEL_BIT                  ?= 0
J9_ALLOY                          ?= 0
ENABLE_HD                         ?= 0
ENABLE_CMD_MMU                    ?= 1

EXTRA_CFLAGS += -Wno-unused-function -Werror

KERNEL_DIR ?= $(TOOL_DIR)/kernel

HOST := $(shell hostname)

MODULE_NAME ?= jmgpu

ifeq ($(USE_LINUX_PCIE), 1)
EXTRA_CFLAGS +=-DJMD_IRQ_SHARED
# EXTRA_CFLAGS +=-DJMD_ENABLE_BUFFERABLE_VIDEO_MEMORY=1
endif


OBJS= jmgpu_bullets.o  jmgpu_bookmark.o  mwv207_diagrams.o  jmgpu_license.o  jmgpu_setlayout.o  jmgpu_authentication.o  jmgpu_framework.o  jmgpu_aptech.o  jmgpu_garbage.o  jmgpu_hypertext.o  jmgpu_concurrent.o  jmgpu_efficient.o  jmgpu_accessible.o  jmgpu_arithmetic.o  jmgpu_insert.o   mwv207_shading.o   jmgpu_protect.o  jmgpu_toolbars.o  jmgpu_marketing.o  jmgpu_crosstab.o  jmgpu_background.o  jmgpu_location.o  mwv207_method.o  jmgpu_through.o  jmgpu_autoformat.o  jmgpu_driven.o  jmgpu_services.o  jmgpu_review.o  jmgpu_remote.o  jmgpu_detect.o  jmgpu_unchecked.o  jmgpu_limited.o   jmgpu_define.o  jmgpu_letter.o  mwv207_boolean.o  jmgpu_forward.o  jmgpu_program.o  jmgpu_setfont.o  jmgpu_symbol.o  jmgpu_default.o  jmgpu_destroy.o  jmgpu_register.o  mwv207_update.o  jmgpu_library.o  jmgpu_messages.o  jmgpu_console.o  jmgpu_permanents.o   jmgpu_script.o  jmgpu_scroll.o  jmgpu_printer.o   jmgpu_numbering.o  jmgpu_enc.o   jmgpu_formula.o   jmgpu_package.o  jmgpu_repeat.o  jmgpu_throws.o  jmgpu_gridlines.o  jmgpu_clause.o  jmgpu_subsets.o  jmgpu_language.o  jmgpu_source.o  jmgpu_refactor.o  jmgpu_static.o  jmgpu_calendar.o   jmgpu_middleware.o  jmgpu_signal.o
OBJS+=jmgpu_buttons.o jmgpu_nicely.o jmgpu_character.o jmgpu_parallel.o jmgpu_implicit.o jmgpu_bitmap.o jmgpu_search.o jmgpu_nemyry.o jmgpu_analog.o


ifneq ($(CONFIG_SYNC),)
    ifneq ($(CONFIG_SYNC_FILE),)
      EXTRA_CFLAGS += -DJMD_LINUX_SYNC_FILE=1
    endif
else
    ifneq ($(CONFIG_SYNC_FILE),)
      EXTRA_CFLAGS += -DJMD_LINUX_SYNC_FILE=1
    endif
endif

ifeq ($(KERNELRELEASE), )

ifeq ($(CONFIG_KASAN),)
EXTRA_CFLAGS += -Werror -Wno-implicit-fallthrough
endif

.PHONY: all clean install

# Define targets.
all:
	$(MAKE) V=$(V) ARCH=$(ARCH_TYPE) -C $(KERNEL_DIR) M=`pwd` modules

clean:
	@rm -rf $(OBJS)
	@rm -rf modules.order Module.symvers .tmp_versions
	@find . -name ".jmgpu_*.cmd" | xargs rm -f
	@rm -f $(MODULE_NAME).ko $(MODULE_NAME).o $(MODULE_NAME).mod.[co] .jmgpu.*.cmd

install: all

else


EXTRA_CFLAGS += -DLINUX -DDRIVER

ifeq ($(FLAREON),1)
EXTRA_CFLAGS += -DFLAREON
endif

ifeq ($(DEBUG), 1)
EXTRA_CFLAGS += -DDBG=1 -DDEBUG -D_DEBUG
else
EXTRA_CFLAGS += -DDBG=0
endif

ifeq ($(NO_DMA_COHERENT), 1)
EXTRA_CFLAGS += -DNO_DMA_COHERENT
endif

ifeq ($(CONFIG_DOVE_GPU), 1)
EXTRA_CFLAGS += -DCONFIG_DOVE_GPU=1
endif

ifneq ($(USE_PLATFORM_DRIVER), 0)
EXTRA_CFLAGS += -DUSE_PLATFORM_DRIVER=1
else
EXTRA_CFLAGS += -DUSE_PLATFORM_DRIVER=0
endif

EXTRA_CFLAGS += -DJMGPU_PROFILER=1
EXTRA_CFLAGS += -DJMGPU_PROFILER_CONTEXT=1

ifeq ($(ENABLE_GPU_CLOCK_BY_DRIVER), 1)
EXTRA_CFLAGS += -DENABLE_GPU_CLOCK_BY_DRIVER=1
else
EXTRA_CFLAGS += -DENABLE_GPU_CLOCK_BY_DRIVER=0
endif

ifeq ($(USE_NEW_LINUX_SIGNAL), 1)
EXTRA_CFLAGS += -DUSE_NEW_LINUX_SIGNAL=1
else
EXTRA_CFLAGS += -DUSE_NEW_LINUX_SIGNAL=0
endif

ifeq ($(USE_LINUX_PCIE), 1)
EXTRA_CFLAGS += -DUSE_LINUX_PCIE=1
else
EXTRA_CFLAGS += -DUSE_LINUX_PCIE=0
endif

ifeq ($(CACHE_FUNCTION_UNIMPLEMENTED), 1)
EXTRA_CFLAGS += -DJMD_CACHE_FUNCTION_UNIMPLEMENTED=1
else
EXTRA_CFLAGS += -DJMD_CACHE_FUNCTION_UNIMPLEMENTED=0
endif

ifeq ($(JMGPU_ENABLE_3D),0)
EXTRA_CFLAGS += -DJMD_ENABLE_3D=0
else
EXTRA_CFLAGS += -DJMD_ENABLE_3D=1
endif

ifeq ($(JMGPU_ENABLE_2D),0)
EXTRA_CFLAGS += -DJMD_ENABLE_2D=0
else
EXTRA_CFLAGS += -DJMD_ENABLE_2D=1
endif

ifeq ($(JMGPU_ENABLE_VG),0)
EXTRA_CFLAGS += -DJMD_ENABLE_VG=0
else
EXTRA_CFLAGS += -DJMD_ENABLE_VG=1
endif

ifeq ($(USE_BANK_ALIGNMENT), 1)
    EXTRA_CFLAGS += -DJMD_ENABLE_BANK_ALIGNMENT=1
    ifneq ($(BANK_BIT_START), 0)
	        ifneq ($(BANK_BIT_END), 0)
	            EXTRA_CFLAGS += -DJMD_BANK_BIT_START=$(BANK_BIT_START)
	            EXTRA_CFLAGS += -DJMD_BANK_BIT_END=$(BANK_BIT_END)
	        endif
    endif

    ifneq ($(BANK_CHANNEL_BIT), 0)
        EXTRA_CFLAGS += -DJMD_BANK_CHANNEL_BIT=$(BANK_CHANNEL_BIT)
    endif
endif

ifeq ($(FPGA_BUILD), 1)
EXTRA_CFLAGS += -DJMD_FPGA_BUILD=1
else
EXTRA_CFLAGS += -DJMD_FPGA_BUILD=0
endif

ifeq ($(J9_ALLOY), 1)
EXTRA_CFLAGS += -DJMD_SECURITY=1
endif

ifneq ($(CONFIG_DRM),)
    ifneq ($(CONFIG_ANDROID),)
    EXTRA_CFLAGS += -DJMD_ENABLE_DRM=$(JMGPU_ENABLE_DRM)
    else
#    EXTRA_CFLAGS += -DJMD_ENABLE_DRM=0
    EXTRA_CFLAGS += -DJMD_ENABLE_DRM=$(JMGPU_ENABLE_DRM)
    endif
    ifeq ($(ENABLE_KMS),0)
    EXTRA_CFLAGS += -DJMD_ENABLE_KMS=0
    else
    EXTRA_CFLAGS += -DJMD_ENABLE_KMS=1
    endif
else
EXTRA_CFLAGS += -DJMD_ENABLE_DRM=0
endif

EXTRA_CFLAGS += -I.

EXTRA_CFLAGS += -DHOST=\"$(HOST)\"

ifeq ($(ENABLE_HD), 1)
EXTRA_CFLAGS += -DENABLE_HD
endif

ifeq ($(ENABLE_CMD_MMU), 1)
EXTRA_CFLAGS += -DENABLE_CMD_MMU
endif

obj-m = $(MODULE_NAME).o

$(MODULE_NAME)-objs  = $(OBJS)

endif

ISRPM=$(shell command -v rpm 2>/dev/null)
ISDPKG=$(shell command -v dpkg 2>/dev/null)

ifneq ($(ISRPM),)
ifeq ($(ISDPKG),)
    EXTRA_CFLAGS += -DOS_IS_SERVER
endif
endif
