#
# Copyright (C) 2011 Iranian Supreme Council of ICT, The FarsiTel Project
#

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_PRELINK_MODULE := false

LOCAL_SRC_FILES := \
	fribidi-char-sets.c          fribidi-char-sets-iso8859-6.c \
	fribidi-char-sets-cap-rtl.c  fribidi-char-sets-iso8859-8.c \
	fribidi-char-sets-cp1255.c                                 \
	fribidi-char-sets-cp1256.c   fribidi-char-sets-utf8.c

LOCAL_C_INCLUDES =       \
	$(LOCAL_PATH)         \
	$(LOCAL_PATH)/../lib

LOCAL_CFLAGS += -O3

LOCAL_SHARED_LIBRARIES += libfribidilib

LOCAL_MODULE := libfribidics

include $(BUILD_SHARED_LIBRARY)
