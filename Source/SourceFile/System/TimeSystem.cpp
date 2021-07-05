﻿
#include "../../Include/System/TimeSystem.h"

#ifdef _WIN_
#include "../../Include/Windows/WindowsTimeSystem.h"
#else
#include "../../Include/Linux/LinuxTimeSystem.h"
#endif

//	获取格林尼治时间（单位：秒）
double GetGMTTime()
{
	double dRet = 0.0;
#ifdef _WIN_
	dRet = Windows_GetGMTTime();
#else
	dRet = Linux_GetGMTTime();
#endif

	return dRet;
}

//	获取格林尼治时间时间戳（单位：毫秒）
double GetGMTTimeStamp()
{
	double dRet = 0.0;
#ifdef _WIN_
	dRet = Windows_GetGMTTimeStamp();
#else
	dRet = Linux_GetGMTTimeStamp();
#endif
	return dRet;
}

//	获取时间戳（单位：毫秒）
UI32 GetTimeStamp()
{
	UI32 uRet = 0;
#ifdef _WIN_
	uRet = Windows_GetTimeStamp();
#else
	uRet = Linux_GetTimeStamp();
#endif
	return uRet;
}

//	获取日期
bool GetCurTimeString(char* strTime, UI32 uStrCout, const char* strParam, bool bNeedDayOfWeek)
{
	bool bRet = false;
#ifdef _WIN_
	bRet = Windows_GetCurTimeString(strTime, uStrCout, strParam, bNeedDayOfWeek);
#else
	bRet = Linux_GetCurTimeString(strTime, uStrCout, strParam, bNeedDayOfWeek);
#endif
	return bRet;
}





