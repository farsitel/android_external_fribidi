#
# Copyright (C) 2011 Iranian Supreme Council of ICT, The FarsiTel Project
#

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

subdirs := $(addprefix $(LOCAL_PATH)/,$(addsuffix /Android.mk, \
		lib     \
		charset \
	))

include $(subdirs)
