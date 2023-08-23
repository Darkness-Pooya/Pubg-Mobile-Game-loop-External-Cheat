#pragma once

#include "Includes.h"
#include "Global\Global.h"

typedef struct _MEMORY_REGION
{
	DWORD_PTR dwBaseAddr;
	DWORD_PTR dwMemorySize;

} MEMORY_REGION, * PMEMORY_REGION;

namespace Utility
{
	HANDLE ProcessHandler;
	INT GetTrueProcessId(PCHAR ProcessName);
	BOOL MemSearch(BYTE* bSearchData, int nSearchSize, DWORD_PTR dwStartAddr, DWORD_PTR dwEndAddr, BOOL bIsCurrProcess, int iSearchMode, std::vector<DWORD_PTR>& vRet);
	VOID ChangeClickability(BOOL CanClick, HWND hWindow);
	int SINGLEAOBSCAN(BYTE BypaRep[], SIZE_T size);

	template <typename T>
	T ReadMemoryEx(DWORD BaseAddress)
	{
		T Buffer;
		ReadProcessMemory(Game::hProcess, (LPCVOID)BaseAddress, &Buffer, sizeof(Buffer), nullptr);

		return Buffer;
	}

	template <typename T>
	void WriteMemoryEx(DWORD BaseAddress, T WriteValue)
	{
		WriteProcessMemory(Game::hProcess, (LPVOID)BaseAddress, &WriteValue, sizeof(WriteValue), nullptr);
	}

	template <typename T>
	void WriteProtectedMemoryEx(DWORD BaseAddress, T WriteValue)
	{
		DWORD OldProtect;

		VirtualProtectEx(Game::hProcess, (LPVOID)BaseAddress, sizeof(WriteValue), PAGE_EXECUTE_READWRITE, &OldProtect);
		WriteProcessMemory(Game::hProcess, (LPVOID)BaseAddress, &WriteValue, sizeof(WriteValue), nullptr);
		VirtualProtectEx(Game::hProcess, (LPVOID)BaseAddress, sizeof(WriteValue), OldProtect, nullptr);
	}

	template <typename... T>
	void writeBytes(DWORD addr, T... towrite)
	{
		DWORD old;
		BYTE pBuf[] = { towrite... };
		int pid = Utility::GetTrueProcessId((PCHAR)"aow_exe.exe");
		ProcessHandler = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
		VirtualProtectEx(ProcessHandler, (LPVOID)addr, sizeof(pBuf), PAGE_READWRITE, &old);
		WriteProcessMemory(ProcessHandler, (LPVOID)addr, pBuf, sizeof(pBuf), 0);
	}

	template <typename T>
	T RPM(DWORD Address)
	{
		T Buffer;

		ReadProcessMemory(ProcessHandler, (void*)Address, &Buffer, sizeof(Buffer), nullptr);

		return Buffer;
	}

	template<class T>
	T read(DWORD_PTR address, DWORD bufSize) {
		T buff;
		ReadProcessMemory(Game::hProcess, reinterpret_cast<LPCVOID>(address), &buff, sizeof(buff), nullptr);
		return buff;
	}
}