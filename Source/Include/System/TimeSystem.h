﻿

#ifndef __LIB_TIME_SYSTEM_H__
#define __LIB_TIME_SYSTEM_H__
#include "SystemTypeDefines.h"

//	获取格林尼治时间（单位：秒）
double GetGMTTime();

//	获取格林尼治时间时间戳（单位：毫秒）
double GetGMTTimeStamp();

//	获取时间戳（单位：毫秒）
UI32 GetTimeStamp();

//	获取日期
bool GetCurTimeString(char* strTime, UI32 uStrCout, const char* strParam = "", bool bNeedDayOfWeek = false);


#endif	//__LIB_TIME_SYSTEM_H__
