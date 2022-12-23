#pragma once

#include "../common.h"
#include <QMainWindow>
#include "joinwindow.h"

class mainWindow : public QMainWindow
{
public:
    mainWindow(QMainWindow* parent = 0);
    ~mainWindow();

private slots:
    bool process_onJoin();

private:

    CJoinWindow *jwnd;

    Qt::WindowFlags flags = Qt::Window | Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint;
    const QString title = "glad2see - private programkit";
};