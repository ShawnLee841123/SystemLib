﻿


#ifdef _WIN_

#ifndef __WINDOWS_TIME_SYSTEM_H__
#define __WINDOWS_TIME_SYSTEM_H__

#include "../System/SystemTypeDefines.h"

//	获取格林尼治时间（单位：秒）
double Windows_GetGMTTime();

//	获取格林尼治时间时间戳（单位：毫秒）
double Windows_GetGMTTimeStamp();

//	获取时间戳（单位：毫秒）
UI32 Windows_GetTimeStamp();

//	获取日期
bool Windows_GetCurTimeString(char* strTime, UI32 uStrCout, const char* strParam = "", bool bNeedDayOfWeek = false);
#endif	//	__WINDOWS_TIME_SYSTEM_H__

#endif	//	_WINDOWS_

