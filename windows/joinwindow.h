#pragma once

#include "../common.h"

class CJoinWindow : public QWidget
{
    Q_OBJECT
public:
    CJoinWindow(QWidget *parent = 0);
    ~CJoinWindow();



signals:
    void exec_mainWindow();

private slots:
    void clicked_onJoin();

private:
    void applyCustomDesign();

    QVector<QString> labels {
        "glad2see - join with us",
        "Enter your code:",
        "Join",
        "Quit",
    };

    QLineEdit *leUser = new QLineEdit(this);
    QLineEdit *leCode = new QLineEdit(this);

    QLabel *user = new QLabel(this);
    QLabel *code = new QLabel(this);
    QLabel *joinWithUs = new QLabel(this);


    QPushButton *enter = new QPushButton(/*labels[2], */this);
    QPushButton *quit = new QPushButton(/*labels[3], */this);
};