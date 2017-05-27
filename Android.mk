LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_PRELINK_MODULE := false

LOCAL_SRC_FILES :=  main.cpp

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils


LOCAL_MODULE_TAGS := optional
LOCAL_CFLAGS += -DPLATFORM_ANDROID
LOCAL_MODULE := killall
include $(BUILD_EXECUTABLE)
 
