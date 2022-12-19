#include "regwindow.h"
#include "../common.h"

void RegWindow::checkUser()
{
    QString name = leUser->text();
    std::cout << name.toStdString();
}


RegWindow::RegWindow(QWidget *parent) : QWidget(parent)
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
    connect(enter, &QPushButton::clicked, this, &RegWindow::checkUser);




    setLayout(grid);
}
RegWindow::~RegWindow()
{

}


