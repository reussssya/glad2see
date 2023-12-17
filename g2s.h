#pragma once

#ifndef G2S_STYLE_H
#define G2S_STYLE_H

#define COLOR_1         "#0E0E15"
#define COLOR_2         "#0E0E0E"
#define BTN_COLOR_WHITE "#D9D9D9"
#define BTN_COLOR_GREY  "#252525"
#include <QString>


class Cg2sStyle
{
public:
    static QString getWindowStyleSheet();
    static QString getToolButtonStyleSheet();
    static QString getButtonStyleSheet();
    static QString getLabelStyleSheet();
    static QString getCloseStyleSheet();
    static QString getMaximizeStyleSheet();
    static QString getRestoreStyleSheet();
    static QString getMinimizeStyleSheet();
    static QString getNextStyleSheet();
    static QString getPreviousStyleSheet();
    static QString getStopStyleSheet();
    static QString getPlayStyleSheet();
    static QString getPauseStyleSheet();
    static QString getMenuStyleSheet();
    static QString getTableViewStyleSheet();
};

#endif