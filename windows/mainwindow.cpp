#include "mainwindow.h"
#include "../g2s.h"

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
    time_t expreg = subquery.value(0).toDateTime().toTime_t();
    

    

    bool bExpired = (currentTime > reg+expreg ? true : false);

    return bExpired;
}



void CMainWindow::applyCustomStyleSheet()
{
    // rounding window's corners
    QPainterPath path;
    path.addRoundedRect(this->rect(), 6, 6);
    this->setMask(path.toFillPolygon().toPolygon());
    

    this->setWindowIcon(QIcon(":/data/img/mainIcon.png"));
    
    this->setStyleSheet(Cg2sStyle::getWindowStyleSheet());

    
    
}

CMainWindow::CMainWindow(QWidget *parent)
{
    pJoinWindow = new CJoinWindow();
    hLayout = new QHBoxLayout();
    tBtnExit = new QToolButton();
    tBtnMaximize = new QToolButton();
    tBtnMinimize = new QToolButton();
    // rounding window's corners
    
    this->setWindowFlags(flags);
    
    
    this->setFixedSize(1920, 1080);
    //this->resize(width() - (width() * 0.15), height() - (height() * 0.15));
    this->setMaximumSize(1920, 1080);
    this->setMinimumSize(width() - (width() * 0.60), height() - (height() * 0.60));

    applyCustomStyleSheet();

    if(!qs->value("bIsAuthed").toBool())
    {
        this->hide();
        
        
        connect(pJoinWindow, &CJoinWindow::exec_mainWindow, this, &CMainWindow::show);
        pJoinWindow->show();
    }
    else if(bSubscriptionCheck())
    {
        this->hide();
        
        pJoinWindow->show();
        connect(pJoinWindow, &CJoinWindow::exec_mainWindow, this, &CMainWindow::show);
        QMessageBox::information(this, "Ваша подписка истекла", "Хотите продолжить пользоваться снова? :3\nОбратитесь сюда: vk.com/reussssya или t.me/reussssya");
    }
    else
    {
        this->show();
        

        this->tBtnMaximize->setStyleSheet(Cg2sStyle::getMaximizeStyleSheet());
        this->tBtnMaximize->setFixedSize(30,30);

        this->tBtnMinimize->setStyleSheet(Cg2sStyle::getMinimizeStyleSheet());
        this->tBtnMinimize->setFixedSize(30,30);

        this->tBtnExit->setStyleSheet(Cg2sStyle::getCloseStyleSheet());
        this->tBtnExit->setFixedSize(30,30);

        this->hLayout->addWidget(tBtnMinimize, 1, Qt::AlignmentFlag::AlignRight | Qt::AlignmentFlag::AlignTop);
        this->hLayout->addWidget(tBtnMaximize, 0, Qt::AlignmentFlag::AlignRight | Qt::AlignmentFlag::AlignTop);
        this->hLayout->addWidget(tBtnExit, 0, Qt::AlignmentFlag::AlignRight | Qt::AlignmentFlag::AlignTop);



        connect(tBtnMinimize, &QPushButton::released ,this, &CMainWindow::showMinimized);
        connect(tBtnMaximize, &QPushButton::released ,this, &CMainWindow::clicked_onMaximize);
        connect(tBtnExit, &QPushButton::released ,this, &CMainWindow::close);


        
        
        this->hLayout->setMargin(0);
        this->hLayout->setSpacing(0);

        
        this->setLayout(this->hLayout);
        
        
        
    }

}


void CMainWindow::clicked_onMaximize()
{
    if(!m_bIsMaximized)
    {
        this->showFullScreen();
        this->showMaximized();
        m_bIsMaximized = true;
        
    }
    else
    {
        this->resize(width() - (width() * 0.50), height() - (height() * 0.50));
        this->move(width() - (width() * 0.90), height()- (height() * 0.90));
        this->showNormal();
        m_bIsMaximized = false;
    }
}


CMainWindow::~CMainWindow()
{
    QApplication::quit();
}
