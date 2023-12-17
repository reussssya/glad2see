#pragma once

#include "../common.h"
#include "../g2s.h"

class CJoinWindow : public QWidget
{
    Q_OBJECT
public:
    CJoinWindow(QWidget *parent = 0);
    ~CJoinWindow();

    void mousePressEvent(QMouseEvent *event)
    {
        if (event->buttons().testFlag(Qt::LeftButton))
        {
            HWND hWnd = ::GetAncestor((HWND)(window()->windowHandle()->winId()), GA_ROOT);
            POINT pt;
            ::GetCursorPos(&pt);
            ::ReleaseCapture();
            ::SendMessage(hWnd, WM_NCLBUTTONDOWN, HTCAPTION, POINTTOPOINTS(pt));
        }
    }



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