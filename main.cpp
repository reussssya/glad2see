#include "main.h"
#include "windows/mainwindow.h"
#include "windows/joinwindow.h"
#include "common.h"
#include "data/database.h"
#include "rustapi/rustplus.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    CDatabase data;
    
    
    CMainWindow mWnd;
    RustPlusSocket rps;
    
    
    return a.exec();
}