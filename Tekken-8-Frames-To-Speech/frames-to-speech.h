#ifndef TEKKEN7_FRAMESTOSPEECH_H
#define TEKKEN7_FRAMESTOSPEECH_H

#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include <tlhelp32.h>
#include <fstream>
#include <vector>

typedef __int64 QWORD;

extern HANDLE tekkenHandle;
extern int tekkenPid;
extern void* tekkenModulePointer;

//main.cpp
void init();
void initTekkenHandle();
void initModuleAddresses();
void mainLoop();
void closeProgram();

//memory.cpp
HANDLE getProcessHandle(DWORD pid);
DWORD getProcessId(const std::wstring& nameProgramExe);
uintptr_t getModuleBaseAddress(DWORD pid, const wchar_t* moduleName);
QWORD getDynamicPointer(HANDLE processHandle, void* basePointer, std::vector<DWORD> offsets);
void writeDwordToMemory(HANDLE processHandle, void* address, DWORD newValue);
void writeStringLimitedToMemory(HANDLE processHandle, void* address, char* newValue);
void writeStringUnlimitedToMemory(HANDLE processHandle, void* address, char* newValue);
void writeStringSafeToMemory(HANDLE processHandle, void* address, char* newValue);
bool isMemoryReadable(HANDLE processHandle, void* address);
DWORD readDwordFromMemory(HANDLE processHandle, void* address);
QWORD readQwordFromMemory(HANDLE processHandle, void* address);
char* readStringFromMemory(HANDLE processHandle, void* address);
int getSizeStringInMemory(HANDLE processHandle, void* address);
int getMaxSizeStringInMemory(HANDLE processHandle, void* address);

#endif
