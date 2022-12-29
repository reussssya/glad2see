#include "mainwindow.h"

#define         WND_W_SIZE          600
#define         WND_H_SIZE          400

CMainWindow::CMainWindow(QMainWindow *parent) : QMainWindow(parent)
{
    this->setFixedSize(600,400);
    //this->close();

    jwnd = new CJoinWindow;
    jwnd->show();
    connect(jwnd, &CJoinWindow::exec_mainWindow, this, &CMainWindow::show);
    this->close();

}

CMainWindow::~CMainWindow()
{

}