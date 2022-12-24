#include "mainwindow.h"

#define         WND_W_SIZE          600
#define         WND_H_SIZE          400

mainWindow::mainWindow(QMainWindow *parent) : QMainWindow(parent)
{
    this->setFixedSize(600,400);
    //this->close();

    jwnd = new CJoinWindow;
    jwnd->show();
    connect(jwnd, &CJoinWindow::exec_mainWindow, this, &mainWindow::show);
    this->close();

}

mainWindow::~mainWindow()
{

}