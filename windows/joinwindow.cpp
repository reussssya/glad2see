#include "joinwindow.h"
#include "../common.h"
#include "../data/database.h"
#include "../main.h"


void CJoinWindow::clicked_onJoin()
{
    // got user & code
    //userspace::qUser = leUser->text();
    //userspace::qCode = leCode->text();

    // query to check if user exist
    QSqlQuery q;
    q.prepare("SELECT id FROM users WHERE name = :name");
    //query.prepare("INSERT INTO users (name, giftcode) VALUES (:name, :giftcode)");
    q.bindValue(":name", leUser->text());
    //query.bindValue(":giftcode", code);

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
    if(!q.exec()) qDebug() << "cant exec";
    while(q.next())
    {
        QString receivedCode = q.value(0).toString();
        if(receivedCode == leCode->text())
        {
            this->close();
            QMessageBox::information(this, "glad2see - you are welcome", "Successfuly joined in your account\nEnjoy...");
        }
        else
        {
            QMessageBox::warning(this, "glad2see - failed authorization", "Please, contact to vk.com/reussssya if you forgot the password\
                                                   Or try again..."); // if there no account in db do sth
        }
    }

    /*QSqlQuery qr;
    qr.prepare("SELECT giftcode FROM users WHERE name = :name");
    qr.bindValue(":name", userspace::qUser);
    qr.exec();

    while(qr.next())
    {
        qDebug() << qr.value(0).toString();
    }*/
    
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
}

CJoinWindow::~CJoinWindow()
{

}


