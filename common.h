#pragma once

#include <string>
#include <Windows.h>
#include <windowsx.h>
#include <sys/types.h>
#include <vector>
#include <iostream>
#include <thread>

#include <spdlog/spdlog.h>

#include <QTableView>
#include <QStandardItemModel>
#include <QToolButton>
#include <QScreen>
#include <QString>
#include <QSize>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>
#include <QWindow>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QApplication>
#include <QListWidget>
#include <QThread>
#include <QCloseEvent>
#include <QSettings>
#include <QProgressBar>
#include <QSlider>
#include <QPixmap>
#include <QPainterPath>
#include <QStringLiteral>
#include <QSystemTrayIcon>
#include <QAction>
#include <QDesktopServices>

#include <QMenu>
#include <QStringList>
#include <QPalette>
#include <QKeyEvent>
#include <QTimer>
#include <QFileDialog>
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

static int defaultButtonSizeX = 50;
static int defaultButtonSizeY = 14;
static int defaultFontSize = 14;
//inline wchar_t regKeyPath = L"Software\\glad2see";
/*
static bool EnsureRegistryKey(const wchar_t* path)
{
    HKEY hKey;
    if (RegOpenKeyEx(HKEY_CURRENT_USER, LPCSTR(path), 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return true; // Ключ уже существует
    } else {
        return RegCreateKeyEx(HKEY_CURRENT_USER, LPCSTR(path), 0, nullptr, REG_OPTION_NON_VOLATILE, KEY_WRITE, nullptr, &hKey, nullptr) == ERROR_SUCCESS;
    }
}*/