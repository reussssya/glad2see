#include <QtWidgets/QApplication>
#include <QWindow>
#include "windows/regwindow.h"
#include "windows/mainwindow.h"
#include "common.h"
#include "main.h"
#include "data/database.h"


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    RegWindow regwnd;
    mainWindow mainwnd;
    CDatabase data;
    
    
    

    return a.exec();
}