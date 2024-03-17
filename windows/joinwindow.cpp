#include "../data/database.h"
#include "joinwindow.h"



#define         JOINWND_W_SIZE          400
#define         JOINWND_H_SIZE          200

void CJoinWindow::clicked_onJoin()
{
    /*
    QSqlQuery q;
    q.prepare("SELECT id FROM users WHERE name = :name");
    q.bindValue(":name", leUser->text());

    if(!q.exec())
    {
        std::cout << "Can't execute the query";
    }
    else
    {
        if(!q.next()) QMessageBox::warning(this, "glad2see - ошибка авторизации", "Пожалуйста, обратитесь сюда: t.me/reussssya, если у Вас нету аккаунта\
                                                   Или попробуйте снова..."); // if there is no account in db do sth                    
    }

    q.clear();
    q.finish();

    q.prepare("SELECT giftcode FROM users WHERE name = :name");
    q.bindValue(":name", leUser->text());

    if(!q.exec())
    {
        std::cout << "Can't execute the query";
    } 
    while(q.next())
    {
        std::string receivedCode = q.value(0).toString();
        if(receivedCode == leCode->text())
        {
            QSettings registry(QSettings::NativeFormat,QSettings::UserScope,"glad2see","g2s");
            registry.setValue("bIsAuthed", 1);
            registry.setValue("szUser", leUser->text());
            QMessageBox::information(this, "glad2see - добро пожаловать", "Вы успешно вошли в аккаунт\nНаслаждайтесь...");
            //this->setAttribute(Qt::WA_QuitOnClose, false);


            emit exec_mainWindow();
            this->close();
        }
        else if(receivedCode != leCode->text())
        {
            QMessageBox::warning(this, "glad2see - ошибка авторизации", "Пожалуйста, обратитесь сюда: t.me/amireusya, если вы забыли пароль\
                                                   Или попробуйте снова..."); // if there no account in db do sth
        }
    }
    */
}


void CJoinWindow::applyCustomDesign()
{
    

}


CJoinWindow::CJoinWindow()
{
    applyCustomDesign();
    
}

CJoinWindow::~CJoinWindow()
{
    delete this;
}


