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
    mainWindow mwnd;

    QSettings *registry = new QSettings(QSettings::NativeFormat,QSettings::UserScope,"glad2see","g2s");
    registry->setValue("bIsAuthed", 0);


    
    
    return a.exec();
}