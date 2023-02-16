#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "../../common.h"

uintptr_t gBaseAddress = 0x400000;

uintptr_t gotoPtrAddress(HANDLE hProc, uintptr_t ptr, std::vector<unsigned> offsets)
{
    uintptr_t addr = ptr;
    for (unsigned i = 0; i < offsets.size(); ++i)
    {
        ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
        addr += offsets[i];
    }
    return addr;
}

struct offsets
{
    std::vector<unsigned> healthOffsets {0x3F8};
} offsets;

struct SPlayer
{
    uintptr_t pHealth = gBaseAddress + 0x79BD9C;
};




class CGTASAMPAPI
{
public:
    CGTASAMPAPI()
    {
        gtaWindow = FindWindowA(NULL, gtaWindowName);
        if(!gtaWindow)
        {
            qDebug() << "* Can't find GTA:SA Window\n* Run GTA:SA or try to check gtaWindowName";
        }
        else
        {
            
            GetWindowThreadProcessId(gtaWindow, &dwProcessId);
            handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);


        }
    }

    template<typename T>
    void writeMemory(uintptr_t address, T value, std::vector<unsigned> offsets = 0)
    {
        if(offsets.size() > 0)
        {
            WriteProcessMemory(handle, (BYTE*)gotoPtrAddress(handle, address, offsets), &value, sizeof(value), 0);
        }
        else
        {
            WriteProcessMemory(handle, (BYTE*)address, &value, sizeof(value), 0);
        }
    }
private:

    LPCSTR gtaWindowName = "GTA:SA:MP";

    DWORD dwProcessId;
    HANDLE handle;
    HWND gtaWindow;
    

};