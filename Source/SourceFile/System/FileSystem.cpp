﻿
#include "../../Include/System/FileSystem.h"

#ifdef _WIN_
#include "../../Include/Windows/WindowsFileSystem.h"
#else
#include "../../Include/Linux/LinuxFileSystem.h"
#endif

//	获取当前工作路径
bool GetCurrentDir(char* strOut, UI32 strCount)
{
	bool bRet = false;
#ifdef _WIN_
	bRet = Windows_GetCurrentDir(strOut, strCount);
#else
	bRet = Linux_GetCurrentDir(strOut, strCount);
#endif
	return bRet;
}

//	创建目录
bool CreatePath(const char* strName)
{
	bool bRet = false;
#ifdef _WIN_
	bRet = Windows_CreatePath(strName);
#else
	bRet = Linux_CreatePath(strName);
#endif
	return bRet;
}

//	删除目录
bool DeletePath(const char* strName)
{
	bool bRet = false;
#ifdef _WIN_
	bRet = Windows_DeletePath(strName);
#else
	bRet = Linux_DeletePath(strName);
#endif
	return bRet;
}

//	文件是否存在
bool FileExists(const char* strFileName)
{
	bool bRet = false;
#ifdef _WIN_
	bRet = Windows_FileExists(strFileName);
#else
	bRet = Linux_FileExists(strFileName);
#endif
	return bRet;
}

//	目录是否存在
bool PathExists(const char* strName)
{
	bool bRet = false;
#ifdef _WIN_
	bRet = Windows_PathExists(strName);
#else
	bRet = Linux_PathExists(strName);
#endif
	return bRet;
}

//	创建文件(未实现)
FILE* System_CreateFile(const char* strFileName)
{
	FILE* pFile = NULL;
#ifdef _WIN_
	pFile = Windows_CreateFile(strFileName);
#else
	pFile = Linux_CreateFile(strFileName);
#endif

	return pFile;
}

FILE* System_OpenFile(const char* strFileName, const char* strMode)
{
	FILE* pFile = nullptr;
#ifdef _WIN_
	pFile = Windows_OpenFile(strFileName, strMode);
#else
	pFile = Linux_OpenFile(strFileName, strMode);
#endif

	return pFile;
}

//	删除文件
bool System_DeleteFile(const char* strFileName)
{
	bool bRet = false;
#ifdef _WIN_
	bRet = Windows_DeleteFile(strFileName);
#else
	bRet = Linux_DeleteFile(strFileName);
#endif
	return bRet;
}

//	检查文件或目录权限(非公开调用)
EFilePermissionCheckResult CheckFileOrPathPermission(const char* strName, EFileCheckSystemType eType)
{
	EFilePermissionCheckResult eRet = EFPCR_NO_PERMISSION;
#ifdef _WIN_
	eRet = Windows_CheckFileOrPathPermission(strName, eType);
#else
	eRet = Linux_CheckFileOrPathPermission(strName, eType);
#endif
	return eRet;
}

//	检查文件或目录是否有权限（公开）
//	参数strName问路径时，只能检查路径是否存在
EFilePermissionCheckResult CheckFilePermission(const char* strName, int eType)
{
	EFilePermissionCheckResult eRet = EFPCR_NO_PERMISSION;
#ifdef _WIN_
	eRet = Windows_CheckFilePermission(strName, eType);
#else
	eRet = Linux_CheckFilePermission(strName, eType);
#endif

	return eRet;
}

void PrintLogTextToScreen(const char* strValue, void* pConsole, ELogLevelType eType)
{
#ifdef _WIN_
	if (nullptr != pConsole)
		Windows_PrintLogTextToScreen(strValue, pConsole, eType);
#else
	Linux_PrintLogTextToScreen(strValue, pConsole, eType);
#endif
}

SYSTEM_HANDLE LoadDynamicFile(const char* strFileName, char* strErrorCode)
{
#ifdef _WIN_
	return Windows_LoadDynamicFile(strFileName, strErrorCode);
#else
	return Linux_LoadDynamicFile(strFileName, strErrorCode);
#endif
}

//	加载动态链接库中的符号
void* LoadDynamicFileSymbol(SYSTEM_HANDLE pHandle, const char* strSymbolName, char* strErrorCode)
{
#ifdef _WIN_
	return Windows_LoadDynamicFileSymbol(pHandle, strSymbolName, strErrorCode);
#else
	return Linux_LoadDynamicFileSymbol(pHandle, strSymbolName, strErrorCode);
#endif
}

//	卸载动态链接库
bool CloseDynamicFile(SYSTEM_HANDLE pHandle, char* strErrorCode)
{
#ifdef _WIN_
	return Windows_CloseDynamicFile(pHandle, strErrorCode);
#else
	return Linux_CloseDynamicFile(pHandle, strErrorCode);
#endif
}

bool GetDllLastError(char* strErrorCode)
{
#ifdef _WIN_
	return Windows_GetLastError(strErrorCode);
#else
	return Linux_GetDllLastError(strErrorCode);
#endif
	return nullptr;
}
