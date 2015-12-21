LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

#LOCAL_LDLIBS := -lm -llog//这一句是可选的，如果代码中使用android中的记录日志的api,就需要加上，否则不需要加上。

LOCAL_MODULE := listfiles

LOCAL_SRC_FILES := listfiles.c

#此处设置为生成可执行的目标码,如果生成so共享库，则需要修改为
include $(BUILD_EXECUTABLE) 

#include $(BUILD_SHARED_LIBRARY)
