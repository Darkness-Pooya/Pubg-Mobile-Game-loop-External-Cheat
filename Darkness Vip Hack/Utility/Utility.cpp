#include "Utility.h"

INT Utility::GetTrueProcessId(PCHAR ProcessName)
{
    INT ProcessId = 0;
    INT ThreadCount = 0;

    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE)
    {
        return 0;
    }
    else
    {
        PROCESSENTRY32 ProcessEntry32;
        ProcessEntry32.dwSize = sizeof(PROCESSENTRY32);

        if (Process32First(hSnapshot, &ProcessEntry32))
        {
            do
            {
                if (!_stricmp(ProcessEntry32.szExeFile, ProcessName) && ProcessEntry32.cntThreads > ThreadCount)
                {
                    ThreadCount = ProcessEntry32.cntThreads;
                    ProcessId = (INT)ProcessEntry32.th32ProcessID;
                }
            } while (Process32Next(hSnapshot, &ProcessEntry32));
        }

        CloseHandle(hSnapshot);
        return ProcessId;
    }

    return 0;
}

int MemFind(BYTE* buffer, int dwBufferSize, BYTE* bstr, DWORD dwStrLen)
{
    if (dwBufferSize < 0)
    {
        return -1;
    }

    DWORD  i, j;
    for (i = 0; i < dwBufferSize; i++)
    {
        for (j = 0; j < dwStrLen; j++)
        {
            if (buffer[i + j] != bstr[j] && bstr[j] != '?')
                break;
        }

        if (j == dwStrLen)
            return i;
    }

    return -1;
}

int SundaySearch(BYTE* bStartAddr, int dwSize, BYTE* bSearchData, DWORD dwSearchSize)
{
    if (dwSize < 0)
    {
        return -1;
    }

    int iIndex[256] = { 0 };
    int i, j;
    DWORD k;
    for (i = 0; i < 256; i++)
    {
        iIndex[i] = -1;
    }

    j = 0;
    for (i = dwSearchSize - 1; i >= 0; i--)
    {
        if (iIndex[bSearchData[i]] == -1)
        {
            iIndex[bSearchData[i]] = dwSearchSize - i;
            if (++j == 256)
                break;
        }
    }

    i = 0;
    BOOL bFind = FALSE;
    j = dwSize - dwSearchSize + 1;
    while (i < j)
    {
        for (k = 0; k < dwSearchSize; k++)
        {
            if (bStartAddr[i + k] != bSearchData[k])
                break;
        }

        if (k == dwSearchSize)
        {
            bFind = TRUE;
            break;
        }

        if (i + dwSearchSize >= dwSize)
        {

            return -1;
        }

        k = iIndex[bStartAddr[i + dwSearchSize]];
        if (k == -1)
            i = i + dwSearchSize + 1;
        else
            i = i + k;
    }

    if (bFind)
    {
        return i;
    }
    else
        return -1;
}

BOOL Utility::MemSearch(BYTE* bSearchData, int nSearchSize, DWORD_PTR dwStartAddr, DWORD_PTR dwEndAddr, BOOL bIsCurrProcess, int iSearchMode, std::vector<DWORD_PTR>& vRet)
{
    BYTE* pCurrMemoryData = NULL;
    MEMORY_BASIC_INFORMATION	mbi;
    std::vector<MEMORY_REGION> m_vMemoryRegion;
    mbi.RegionSize = 0x1000;
    DWORD dwAddress = dwStartAddr;

    while (VirtualQueryEx(Game::hProcess, (LPCVOID)dwAddress, &mbi, sizeof(mbi)) && (dwAddress < dwEndAddr) && ((dwAddress + mbi.RegionSize) > dwAddress))
    {
        if ((mbi.State == MEM_COMMIT) && ((mbi.Protect & PAGE_GUARD) == 0) && (mbi.Protect != PAGE_NOACCESS) && ((mbi.AllocationProtect & PAGE_NOCACHE) != PAGE_NOCACHE))
        {

            MEMORY_REGION mData = { 0 };
            mData.dwBaseAddr = (DWORD_PTR)mbi.BaseAddress;
            mData.dwMemorySize = mbi.RegionSize;
            m_vMemoryRegion.push_back(mData);
        }

        dwAddress = (DWORD)mbi.BaseAddress + mbi.RegionSize;
    }

    std::vector<MEMORY_REGION>::iterator it;
    for (it = m_vMemoryRegion.begin(); it != m_vMemoryRegion.end(); it++)
    {
        MEMORY_REGION mData = *it;
        DWORD_PTR dwNumberOfBytesRead = 0;
        if (bIsCurrProcess)
        {
            pCurrMemoryData = (BYTE*)mData.dwBaseAddr;
            dwNumberOfBytesRead = mData.dwMemorySize;
        }
        else
        {
            pCurrMemoryData = new BYTE[mData.dwMemorySize];
            ZeroMemory(pCurrMemoryData, mData.dwMemorySize);
            ReadProcessMemory(Game::hProcess, (LPCVOID)mData.dwBaseAddr, pCurrMemoryData, mData.dwMemorySize, &dwNumberOfBytesRead);

            if ((int)dwNumberOfBytesRead <= 0)
            {
                delete[] pCurrMemoryData;
                continue;
            }
        }

        if (iSearchMode == 0)
        {
            DWORD_PTR dwOffset = 0;
            int iOffset = MemFind(pCurrMemoryData, dwNumberOfBytesRead, bSearchData, nSearchSize);
            while (iOffset != -1)
            {
                dwOffset += iOffset;
                vRet.push_back(dwOffset + mData.dwBaseAddr);
                dwOffset += nSearchSize;
                iOffset = MemFind(pCurrMemoryData + dwOffset, dwNumberOfBytesRead - dwOffset - nSearchSize, bSearchData, nSearchSize);
            }
        }
        else if (iSearchMode == 1)
        {
            DWORD_PTR dwOffset = 0;
            int iOffset = SundaySearch(pCurrMemoryData, dwNumberOfBytesRead, bSearchData, nSearchSize);

            while (iOffset != -1)
            {
                dwOffset += iOffset;
                vRet.push_back(dwOffset + mData.dwBaseAddr);
                dwOffset += nSearchSize;
                iOffset = MemFind(pCurrMemoryData + dwOffset, dwNumberOfBytesRead - dwOffset - nSearchSize, bSearchData, nSearchSize);
            }
        }

        if (!bIsCurrProcess && (pCurrMemoryData != NULL))
        {
            delete[] pCurrMemoryData;
            pCurrMemoryData = NULL;
        }
    }

    return TRUE;
}

VOID Utility::ChangeClickability(BOOL CanClick, HWND hWindow)
{
    LONG Style = GetWindowLong(hWindow, GWL_EXSTYLE);

    if (CanClick)
    {
        Style &= ~WS_EX_LAYERED;
        SetWindowLong(hWindow, GWL_EXSTYLE, Style);
        SetForegroundWindow(hWindow);
    }
    else
    {
        Style |= WS_EX_LAYERED;
        SetWindowLong(hWindow, GWL_EXSTYLE, Style);
    }
}

int Utility::SINGLEAOBSCAN(BYTE BypaRep[], SIZE_T size)
{
    DWORD pid = Utility::GetTrueProcessId((PCHAR)"aow_exe.exe");
    HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
    std::vector<DWORD_PTR> Bypassdo;
    Utility::MemSearch(BypaRep, size, 0x26000000, 0xB0000000, false, 0, Bypassdo);

    if (Bypassdo.size() != 0) {
        return Bypassdo[0];
    }
}