#define QML
#define SAMP



#include "main.h"
#include "common.h"

#include "windows/mainwindow.h"
#include "windows/joinwindow.h"

#include "data/database.h"

#include "api/rustapi/rustplus.h"


#ifdef SAMP
#include "api/gtasampapi/sampapi.h"
#endif

#include "qmlengine.h"


const QUrl qmlUrl("newdesign/main.qml");

int main(int argc, char* argv[])
{

#ifndef QML
    QApplication a(argc, argv);
    CDatabase data;
    AppTeamChat aatc;
    
    CMainWindow mWnd;
#else
    QGuiApplication a(argc, argv);

    /////QQuickView view;
    /////view.setSource(QUrl(QStringLiteral("../../newdesign/main.qml")));
    /////view.show();

    QQmlApplicationEngine qmlEngine;

    qmlEngine.load(qmlUrl);
#endif

    CGTASAMPAPI pGTASAMPAPI;
    /*RustPlusSocket *rs = new RustPlusSocket;
    AppChatMessage msg, prevmsg;
    a.exec();
    do 
    {
        msg = rs->getMessagesFromTeamChat().messages().Get(rs->getMessagesFromTeamChat().messages().size() - 1);
        std::cout << msg.message();
        Sleep(1000);
        prevmsg = msg;
    }
    while(msg.has_message());*/
    a.exec();
    return 0;
}