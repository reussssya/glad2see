#pragma once

#include <string>
#include <Windows.h>
#include <sys/types.h>
#include <vector>
#include <iostream>
#include <thread>

#include "vendor/xorstr.hpp"
#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_opengl3.h"
#include "vendor/imgui/imgui_impl_win32.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#define DEBUG_C

inline std::string gLogin;
inline int gSubscripted, gSubtime;
