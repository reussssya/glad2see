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
            this->setAttribute(Qt::WA_QuitOnClose, false);
            this->close();
            emit firstWindow();
        }
        else
        {
            QMessageBox::warning(this, "glad2see - failed authorization", "Please, contact to vk.com/reussssya if you forgot the password\
                                                   Or try again..."); // if there no account in db do sth
        }
    }
    
}

CJoinWindow::CJoinWindow(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(weight, height);
    this->setWindowTitle(labels[0]);
    this->setWindowFlags(flags);
    

    QLabel *user = new QLabel("Identificator:", this);
    user->setAlignment(Qt::AlignRight);

    QLabel *code = new QLabel("Code:", this);
    code->setAlignment(Qt::AlignRight);
    

    leUser->setFixedHeight(22);
    leCode->setFixedHeight(22);

    QGridLayout *grid = new QGridLayout(); 
    


    grid->addWidget(user, 0, 0);
    grid->addWidget(code, 1, 0);

    grid->addWidget(leUser, 0,1);
    grid->addWidget(leCode, 1, 1);
    
    grid->setRowStretch(2,2);


    enter->setGeometry(185, 70, 70, 25);
    quit->setGeometry(20, 70, 70, 25);

    connect(quit, &QPushButton::clicked, this, &QApplication::quit);
    connect(enter, &QPushButton::clicked, this, &CJoinWindow::clicked_onJoin);



    
    setLayout(grid);
    this->show();
}

CJoinWindow::~CJoinWindow()
{

}


