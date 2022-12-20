#include <QWindow>
#include "windows/joinwindow.h"
#include "windows/mainwindow.h"
#include "common.h"
#include "main.h"
#include "data/database.h"


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    mainWindow mainwnd;
    CJoinWindow jwnd;
    CDatabase data;

    jwnd.show();
    
    

    return a.exec();
}