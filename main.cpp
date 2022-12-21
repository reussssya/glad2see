#include "main.h"
#include "windows/joinwindow.h"
#include "windows/mainwindow.h"
#include "common.h"
#include "data/database.h"



int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    CDatabase data;
    CJoinWindow *jwnd = new CJoinWindow;
    mainWindow mwnd;
    
    jwnd->show();
    //while(!jwnd->isVisible())
    //{
    //    qDebug() << "is not visible";
    //    QThread::sleep(5);
    //}
    

    return a.exec();
}