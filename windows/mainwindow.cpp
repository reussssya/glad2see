#include "mainwindow.h"

bool CMainWindow::bSubscriptionCheck()
{
/*
    time_t currentTime = time(0);
    QSqlQuery subquery;
    // need to make if else construct to prevent errors while logging
    subquery.prepare("SELECT subscripted FROM users WHERE name = :name");
    subquery.bindValue(":name", qs->value("user").toString());
    subquery.exec();
    subquery.first();

    time_t reg = subquery.value(0).toDateTime().toSecsSinceEpoch();

    subquery.clear();
    subquery.finish();

    
    subquery.prepare("SELECT subtime FROM users WHERE name = :name");
    subquery.bindValue(":name", qs->value("user").toString());
    subquery.exec();
    subquery.first();
    time_t expreg = subquery.value(0).toDateTime().toSecsSinceEpoch();
    

    

    bool bExpired = (currentTime > reg+expreg ? true : false);

    return bExpired;*/
    return 1;
}



void CMainWindow::applyCustomStyleSheet()
{

    

    //this->setWindowIcon(QIcon(":/data/img/mainIcon.png"));
    

    
    
}

CMainWindow::CMainWindow()
{
    pJoinWindow = new CJoinWindow();
    
    // rounding window's corners
    
    applyCustomStyleSheet();
    /*
    if(!qs->value("bIsAuthed").toBool())
    {
        this->hide();
        
        
        pJoinWindow->show();
    }
    else if(bSubscriptionCheck())
    {
        this->hide();
        
        pJoinWindow->show();
        //QMessageBox::information(this, "Ваша подписка истекла", "Хотите продолжить пользоваться снова? :3\nОбратитесь сюда: vk.com/reussssya или t.me/reussssya");
    }
    else
    {
        this->show();
        
        
        
    }
*/
}




CMainWindow::~CMainWindow()
{
    delete this;
}
