#include "data/database.h"
#include "common.h"

#include "windows/mainwindow.h"
#include "windows/joinwindow.h"


#include "discordrpc.h"
#include "trackplayer.hpp"

#include <GL/GL.h>
#include <tchar.h>



int main(int argc, char* argv[])
{
    //QIcon trayIcon = QIcon(":/data/img/trayIcon.ico");
    
    DiscordRPC discord;
    std::thread ds(&DiscordRPC::Start, &discord);
    ds.detach();
    CMainWindow *mainWnd = new CMainWindow();

    


    return 0;
}