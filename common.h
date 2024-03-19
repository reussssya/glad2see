#pragma once

#include <string>
#include <Windows.h>
#include <windowsx.h>
#include <sys/types.h>
#include <vector>
#include <iostream>
#include <thread>

#include <spdlog/spdlog.h>

#include "vendor/xorstr.hpp"
#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#define DEBUG_C

#define     BG_COLOR_BLACK      "#0D0D0D"
#define     BG2_COLOR_GREY      "#121212"
#define     FONT_COLOR_WHITE    "#E6E6E6"
#define     LINE_COLOR_GRERY    "#333333"

inline std::string gLogin;
inline int gSubscripted, gSubtime;

inline wchar_t* regKeyPath = L"Software\\glad2see";

static bool EnsureRegistryKey(const wchar_t* path)
{
    HKEY hKey;
    if (RegOpenKeyEx(HKEY_CURRENT_USER, LPCSTR(path), 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return true; // Ключ уже существует
    } else {
        return RegCreateKeyEx(HKEY_CURRENT_USER, LPCSTR(path), 0, nullptr, REG_OPTION_NON_VOLATILE, KEY_WRITE, nullptr, &hKey, nullptr) == ERROR_SUCCESS;
    }
}