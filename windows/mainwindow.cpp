#include "../data/database.h"
#include "mainwindow.h"
#include "../g2s.h"
bool CMainWindow::bSubscriptionCheck()
{
    time_t currentTime = time(0);
    
    CDatabase db;
    time_t reg = db.makeQuery<time_t>("SELECT UNIX_TIMESTAMP(subscripted) FROM users WHERE name = 'asd'", 0); // login
    
    
    spdlog::info(reg);

    time_t expreg = db.makeQuery<time_t>("SELECT UNIX_TIMESTAMP(subtime) FROM users WHERE name = 'asd'", 0);
    bool bExpired = (currentTime > reg+expreg ? true : false);
    spdlog::info("Is ok");
    return bExpired;
}



void CMainWindow::applyCustomStyleSheet()
{

    this->setWindowIcon(QIcon(":/data/img/mainIcon.png"));
    
    //QSlider slider;
}

CMainWindow::CMainWindow(QWidget *parent) : QWidget(parent)
{
    pJoinWindow = new CJoinWindow();
    hLayout = new QHBoxLayout(parent);
    tBtnExit = new QToolButton();
    tBtnMaximize = new QToolButton();
    tBtnMinimize = new QToolButton();
    // rounding window's corners
    
    this->setWindowFlags(flags);
    
    
    this->setBaseSize(1280, 720);
    //this->resize(width() - (width() * 0.15), height() - (height() * 0.15));
    this->setMinimumSize(width() - (width() * 0.60), height() - (height() * 0.60));

    applyCustomStyleSheet();

    if(!qs->value("bIsAuthed").toBool())
    {
        this->hide();
        
        
        connect(pJoinWindow, &CJoinWindow::exec_mainWindow, this, &CMainWindow::show);
        pJoinWindow->show();
    }
    else if(!bSubscriptionCheck())
    {
        this->hide();
        
        pJoinWindow->show();
        connect(pJoinWindow, &CJoinWindow::exec_mainWindow, this, &CMainWindow::show);
        QMessageBox::information(this, "Ваша подписка истекла", "Хотите продолжить пользоваться снова? :3\nОбратитесь сюда: vk.com/reussssya или t.me/amireusya");
    }
    else
    {
        show();

        QHBoxLayout *layout = new QHBoxLayout(this);

        // Создаем пустой виджет с фиксированным размером до кнопки
        QWidget *spacerBefore = new QWidget(this);
        spacerBefore->setFixedWidth(100);

        // Создаем пустой виджет с фиксированным размером после кнопки
        QWidget *spacerAfter = new QWidget(this);
        spacerAfter->setFixedWidth(100);
        QPushButton* btn = new QPushButton("Open", this);
        
        btn->setStyleSheet(Cg2sStyle::getPushButtonStyleSheet());
        btn->setFixedSize(defaultButtonSizeX, defaultButtonSizeY);

        connect(btn, &QPushButton::released, this, &CMainWindow::showMaximized);

        layout->addWidget(spacerBefore);
        layout->addWidget(btn);
        layout->addWidget(spacerAfter);
        setLayout(hLayout);
        
        
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
