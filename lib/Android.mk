#
# Copyright (C) 2011 Iranian Supreme Council of ICT, The FarsiTel Project
#

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_PRELINK_MODULE := false

LOCAL_SRC_FILES := fribidi.c \
        fribidi-arabic.c \
        fribidi-bidi.c \
        fribidi-bidi-types.c \
        fribidi-deprecated.c \
        fribidi-joining.c \
        fribidi-joining-types.c \
        fribidi-mem.c \
        fribidi-mirroring.c \
        fribidi-run.c \
        fribidi-shape.c

LOCAL_C_INCLUDES =       \
	$(LOCAL_PATH)         \
	$(LOCAL_PATH)/../charset

LOCAL_CFLAGS += -O3

LOCAL_MODULE := libfribidilib

include $(BUILD_SHARED_LIBRARY)
