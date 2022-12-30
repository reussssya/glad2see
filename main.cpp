#include "main.h"
#include "windows/joinwindow.h"
#include "windows/mainwindow.h"
#include "common.h"
#include "data/database.h"


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    CDatabase data;
    CJoinWindow jwnd;
    CMainWindow mwnd;


    
    
    return a.exec();
}