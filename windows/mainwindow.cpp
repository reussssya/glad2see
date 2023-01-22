#include "mainwindow.h"

#define         MAINWND_W_SIZE          1600
#define         MAINWND_H_SIZE          900

bool CMainWindow::bSubscriptionCheck()
{

    time_t currentTime = time(0);
    QSqlQuery subquery;
    // need to make if else construct to prevent errors while logging
    subquery.prepare("SELECT subscripted FROM users WHERE name = :name");
    subquery.bindValue(":name", qs->value("user").toString());
    subquery.exec();
    subquery.first();

    time_t reg = subquery.value(0).toDateTime().toTime_t();

    subquery.clear();
    subquery.finish();

    
    subquery.prepare("SELECT subtime FROM users WHERE name = :name");
    subquery.bindValue(":name", qs->value("user").toString());
    subquery.exec();
    subquery.first();
    time_t expreg = subquery.value(0).toInt();
    

    

    bool bExpired = (currentTime > reg+expreg ? true : false);

    return bExpired;
}

void CMainWindow::applyCustomDesign()
{
    this->setWindowIcon(QIcon("data/img/mainfIcon.png"));
    this->setWindowFlags(flags);
    this->setFixedSize(MAINWND_W_SIZE, MAINWND_H_SIZE);


    this->setParent(0);

    // background 
    QPixmap bkgnd("data/img/mainWindow.png");
    bkgnd = bkgnd.scaled(this->size());

    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);

    this->setPalette(palette);

    // round window's corners

    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 5, 5, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());
}

CMainWindow::CMainWindow(QMainWindow *parent) : QMainWindow(parent)
{
    applyCustomDesign();
    

    if(!qs->value("bIsAuthed").toBool())
    {
        this->close();
        jwnd = new CJoinWindow();
        jwnd->show();
        connect(jwnd, &CJoinWindow::exec_mainWindow, this, &CMainWindow::show);

    }
    else if(bSubscriptionCheck())
    {
        this->close();
        jwnd = new CJoinWindow();
        jwnd->show();
        connect(jwnd, &CJoinWindow::exec_mainWindow, this, &CMainWindow::show);
        QMessageBox::information(this, "Your subscription has expired", "Wanna use this beautiful app again? :3\nContact: vk.com/reussssya or t.me/reussssya");
    }
    else
    {
        this->show();
    }

    

}

CMainWindow::~CMainWindow()
{

}