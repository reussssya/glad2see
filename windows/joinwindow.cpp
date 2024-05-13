#include "../data/database.h"
#include "joinwindow.h"



#define         JOINWND_W_SIZE          400
#define         JOINWND_H_SIZE          200

void CJoinWindow::clicked_onJoin()
{
    
    CDatabase db;
    std::string q = "SELECT id FROM users WHERE name = '" + leUser->text().toStdString() + "'";
    int id = db.makeQuery<int>(q, 0); // login
    if (!id)
    {
        QMessageBox::warning(this, "glad2see - ошибка авторизации", "Пожалуйста, обратитесь сюда: t.me/amireusya, если у Вас нету аккаунта\
                                                   Или попробуйте снова..."); // if there is no account in db do sth
        
    }
    q = "SELECT giftcode FROM users WHERE name = '" + leUser->text().toStdString() + "'";
    std::string receivedCode = db.makeQuery<std::string>(q, 0); // get code

    if (receivedCode == leCode->text().toStdString())
    {
        QSettings registry(QSettings::NativeFormat,QSettings::UserScope,"glad2see","g2s");
        registry.setValue("bIsAuthed", 1);
        registry.setValue("szUser", leUser->text());
        QMessageBox::information(this, "glad2see - добро пожаловать", "Вы успешно вошли в аккаунт\nНаслаждайтесь...");
        //this->setAttribute(Qt::WA_QuitOnClose, false);

        
        emit exec_mainWindow();
        this->close();
    }
    else if(receivedCode != leCode->text().toStdString())
    {
        QMessageBox::warning(this, "glad2see - ошибка авторизации", "Пожалуйста, обратитесь сюда: t.me/amireusya, если вы забыли пароль\
                                                Или попробуйте снова..."); // if there no account in db do sth
    }
}


void CJoinWindow::applyCustomDesign()
{
    QIcon regIcon(QPixmap(":data/img/regIcon.png"));
    this->setWindowIcon(regIcon);

    this->setFixedSize(JOINWND_W_SIZE, JOINWND_H_SIZE);
    this->setWindowFlags(Qt::Widget);

    // background 
    QPixmap bkgnd(":/data/img/joinWindow.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);

    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);

    this->setPalette(palette);

    // round window's corners

    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 5, 5, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());

}


CJoinWindow::CJoinWindow(QWidget *parent)
{
    applyCustomDesign();

    user->setPixmap(QPixmap(":/data/img/identificatorLabel.png"));
    code->setPixmap(QPixmap(":/data/img/codeLabel.png"));
    joinWithUs->setPixmap(QPixmap(":/data/img/joinWithUsLabel.png"));
    
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



    enter->setStyleSheet("QPushButton { border-image:url(:/data/img/joinButtonFinal.png); }"
                        "QPushButton:pressed { border-image:url(:/data/img/joinButtonFinalPressed.png); }");

    quit->setStyleSheet("QPushButton { border-image:url(:/data/img/quitButtonFinal.png); }"
                        "QPushButton:pressed { border-image:url(:/data/img/quitButtonFinalPressed.png); }");


    joinWithUs->setGeometry(145,12,110,20);
    
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


