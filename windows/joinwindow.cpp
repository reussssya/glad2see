#include "joinwindow.h"

#include "../common.h"
#include "../data/database.h"


void CJoinWindow::clicked_onJoin()
{
    QSqlQuery q;
    q.prepare("SELECT id FROM users WHERE name = :name");
    q.bindValue(":name", leUser->text());

    if(!q.exec())
    {
        qDebug() << "Can't execute the query";
    }
    else
    {
        if(!q.next()) QMessageBox::warning(this, "glad2see - failed authorization", "Please, contact to vk.com/reussssya if you already don't have an account\
                                                   Or try again..."); // if there no account in db do sth                    
    }

    q.clear();
    q.finish();

    q.prepare("SELECT giftcode FROM users WHERE name = :name");
    q.bindValue(":name", leUser->text());

    if(!q.exec()) qDebug() << "Can't execute the query";
    while(q.next())
    {
        QString receivedCode = q.value(0).toString();
        if(receivedCode == leCode->text())
        {
            QSettings registry(QSettings::NativeFormat,QSettings::UserScope,"glad2see","g2s");
            registry.setValue("bIsAuthed", 1);

            QMessageBox::information(this, "glad2see - you are welcome", "Successfuly joined in your account\nEnjoy...");
            //this->setAttribute(Qt::WA_QuitOnClose, false);
            emit exec_mainWindow();
            this->close();
        }
        else if(receivedCode != leCode->text())
        {
            QMessageBox::warning(this, "glad2see - failed authorization", "Please, contact to vk.com/reussssya if you forgot the password\
                                                   Or try again..."); // if there no account in db do sth
        }
    }
    
}

void CJoinWindow::applyCustomDesign()
{
    this->setFixedSize(width, height);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setParent(0);
    // background 
    QPixmap bkgnd("data/img/JoinWindow.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);

    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);

    this->setPalette(palette);

    // round window's corners

    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 5, 5, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());

}

void CJoinWindow::pressed_quitButton()
{
    quit->setStyleSheet("border-image:url(data/img/quitButtonFinalPressed.png);");
}

void CJoinWindow::pressed_joinButton()
{
    enter->setStyleSheet("border-image:url(data/img/joinButtonFinalPressed.png);");
}

CJoinWindow::CJoinWindow(QWidget *parent) : QWidget(parent)
{
    applyCustomDesign();

    user->setPixmap(QPixmap("data/img/IDENTIFICATOR.png"));
    code->setPixmap(QPixmap("data/img/CODE.png"));
    joinWithUs->setPixmap(QPixmap("data/img/joinWithUs.png"));
    
    leUser->setStyleSheet("font: 13pt 'Inter';"
                        "color: #0A0A16;"
                        "background-color: #D9D9D9;"
                        "selection-color: #0A0A16;"
                        "border-radius: 5px;");
    leUser->setFixedHeight(35);

    leCode->setStyleSheet("font: 13pt 'Inter';"
                        "color: #0A0A16;"
                        "background-color: #D9D9D9;"
                        "selection-color: #0A0A16;"
                        "border-radius: 5px;");
    leCode->setFixedHeight(35);



    enter->setStyleSheet("QPushButton { border-image:url(data/img/joinButtonFinal.png); }"
                        "QPushButton:pressed { border-image:url(data/img/joinButtonFinalPressed.png); }");

    quit->setStyleSheet("QPushButton { border-image:url(data/img/quitButtonFinal.png); }"
                        "QPushButton:pressed { border-image:url(data/img/quitButtonFinalPressed.png); }");


    joinWithUs->setGeometry(145,10,110,20);
    
    user->setGeometry(27,46, 148,23);
    code->setGeometry(117,98, 58,19);

    leUser->setGeometry(190,40,190,35);
    leCode->setGeometry(190,90,190,35);

    enter->setGeometry(325, 160, 65, 25);
    quit->setGeometry(15, 160, 65, 25);


    //connect(quit, &QPushButton::pressed, this, &CJoinWindow::pressed_quitButton);
    //connect(quit, &QPushButton::, this, &CJoinWindow::applyCustomDesign);
    connect(quit, &QPushButton::clicked, this, &CJoinWindow::close);
    connect(enter, &QPushButton::clicked, this, &CJoinWindow::clicked_onJoin);
}

CJoinWindow::~CJoinWindow()
{

}


