#pragma once

#include "../common.h"
#include <QMainWindow>
#include "joinwindow.h"

class CMainWindow : public QMainWindow
{
public:
    CMainWindow(QMainWindow* parent = 0);
    ~CMainWindow();

private:

    CJoinWindow *jwnd;

    Qt::WindowFlags flags = Qt::Window | Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint;
    const QString title = "glad2see - private programkit";
};