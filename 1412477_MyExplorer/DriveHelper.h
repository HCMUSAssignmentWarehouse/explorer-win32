#ifndef CDRIVE_H
#define CDRIVE_H

#include <windows.h>
#include <tchar.h>
#include "DriveSize.h"

#define MAX_BUFFER_LEN 105 //Để chữa chuỗi tối đa 26 x 4 + 1 kí tự (Ví dụ "A:\\")

#define VOLUME_NAME_SIZE		MAX_BUFFER_LEN
#define VOLUME_SERIAL_NUMBER	NULL
#define MAX_COMPONENT_LEN		NULL
#define FILE_SYSTEM_FLAG		NULL
#define FILE_SYSTEM_NAME_BUFF	NULL //Name of File System (NTFS, FAT,...)
#define FILE_SYSTEM_NAME_SIZE	0  //Size of buffer for file system name

#define MAX_TYPE_LEN		20
#define MAX_DRIVE_LETTER	4
#define MAX_VOLUME_NAME		30
#define MAX_DISPLAY_NAME	30

#define FIXED_DRIVE		_T("Fixed drive")
#define REMOVABLE_DRIVE _T("Removable drive")
#define CD_ROM			_T("CD-ROM")
#define REMOTE_DRIVE	_T("Network drive")

class DriveHelper
{
private:
	TCHAR** mDriveLetter;
	TCHAR** mVolumeLabel; //Kết hợp giữa pszDrive và pszVolName
	TCHAR** mDriveType;
	int mNumberOfDrive;
	CDriveSize** mDriveSize;

	CDriveSize* getDriveSize(int i);

public:
	DriveHelper();
	~DriveHelper();

	TCHAR* GetDriveName(const int &i);
	TCHAR* GetDisplayName(const int &i);
	int GetCount();
	

	void GetSystemDrives();

	TCHAR* getDriveType(int position);
	LPWSTR getTotalSize(int i);
	LPWSTR getFreeSpace(int i);
};

#endif