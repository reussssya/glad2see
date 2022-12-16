#include "mainwindow.h"

#define         WND_W_SIZE          600
#define         WND_H_SIZE          400

mainWindow::mainWindow()
{
    window.setFlags(flags);
    window.resize(WND_W_SIZE, WND_H_SIZE);
    window.setTitle(title);
    window.show();
}

mainWindow::~mainWindow()
{

}