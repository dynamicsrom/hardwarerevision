/* 
	HardwareRevision application for Sony Ericsson XPERIA X1.
	Shows hardware info.
*/
#include "stdafx.h"

extern "C"
{
	BOOL	SetKMode(BOOL bFlag);
	DWORD	SetProcPermissions(DWORD dwPerms);
}

int _tmain(int argc, _TCHAR* argv[])
{
	BOOL bMode = SetKMode(TRUE);
	DWORD dwPerm = SetProcPermissions(0xFFFFFFFF);

	DWORD	microP1Version = 0xFFFFFFFF, 
			microP2Version = 0xFFFFFFFF, 
			engineerID = 0xFFFFFFFF, 
			projectID = 0xFFFFFFFF;
	BYTE byHWBoaredVersion = 0xFF;

	microP1Version = *(DWORD*)(0xBA081C2C);
	microP2Version = *(DWORD*)(0xBA081C30);
	byHWBoaredVersion = *(BYTE*)(0xBA081030);
	engineerID = *(DWORD*)(0xBA081C88);
	projectID = *(DWORD*)(0xBA081C8C);

	SetKMode(bMode);
	SetProcPermissions(dwPerm);

	wchar_t str[500];
	swprintf(str, L"microP1Version = %X\nmicroP2Version = %X\nboard = %X\nengineerID = %X\nprojectID = %X\n",
					microP1Version, microP2Version, byHWBoaredVersion, engineerID, projectID);

	MessageBox(NULL, str, L"HardwareRevision for SE X1", 0);
	return 0;
}

