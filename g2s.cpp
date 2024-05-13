#include "g2s.h"
QString Cg2sStyle::getWindowStyleSheet()
{
    return ""
           "background-color:" COLOR_2 "; "
           "border: 1px solid black;"
           "";
}
 
QString Cg2sStyle::getLabelStyleSheet()
{
    return "QLabel { "
           "color: #8f8f8f; "
           "border: none; "
           "margin: 6px; "
           "}";
}


QString Cg2sStyle::getPushButtonStyleSheet()
{
    return "QPushButton {"
           "background-color:" BTN_COLOR_WHITE ";"
           "border: none;"
           "font-family: Inter;"
           "font-size: 12px;"
           "font-weight: Black;"
           "}"
           "QPushButton:pressed {"
           "background-color:" BTN_COLOR_GREY ";"
           "border: none;"
           "font-family: Inter;"
           "font-size: 12px;"
           "font-weight: Black;"
           "}";
}
QString Cg2sStyle::getToolButtonStyleSheet()
{
    return "QToolButton {"
           "background-color:" BTN_COLOR_WHITE ";"
           "border: none;"
           "}"
           "QToolButton:pressed {"
           "background-color:" BTN_COLOR_GREY ";"
           "border: none;"
           "}";
}

QString Cg2sStyle::getCloseStyleSheet()
{
    return "QToolButton { "
           "image: url(:/data/img/tBtnClose.png);"
           "background-color:" BTN_COLOR_WHITE ";"
           "border: none;"
           "}"
           "QToolButton:pressed {"
           "image: url(:/data/img/tBtnClosePressed.png);"
           "border: none;"
           "background-color:" BTN_COLOR_GREY ";"
           "}";
}

 
QString Cg2sStyle::getMaximizeStyleSheet()
{
    return "QToolButton { "
           "image: url(:/data/img/tBtnMaximize.png);"
           "background-color:" BTN_COLOR_WHITE ";"
           "border: none;"
           "}"
           "QToolButton:pressed {"
           "image: url(:/data/img/tBtnMaximizePressed.png);"
           "border: none;"
           "background-color:" BTN_COLOR_GREY ";"
           "}";
}
 
QString Cg2sStyle::getMinimizeStyleSheet()
{
    return "QToolButton { "
           "image: url(:/data/img/tBtnMinimize.png);"
           "background-color:" BTN_COLOR_WHITE ";"
           "border: none;"
           "}"
           "QToolButton:pressed {"
           "image: url(:/data/img/tBtnMinimizePressed.png);"
           "border: none;"
           "background-color:" BTN_COLOR_GREY ";"
           "}";
}
 
QString Cg2sStyle::getNextStyleSheet()
{
    return "QToolButton { "
           "image: url(:/buttons/skip-next.png);"
           "icon-size: 24px;"
           "padding: 6px;"
           "margin: 6px;"
           "border: none;"
           "}"
           "QToolButton:pressed { "
           "image: url(:/buttons/skip-next-orange.png)"
           "}";
}
 
QString Cg2sStyle::getPreviousStyleSheet()
{
    return "QToolButton { "
           "image: url(:/buttons/skip-previous.png);"
           "icon-size: 24px;"
           "padding: 6px;"
           "margin: 6px;"
           "border: none;"
           "}"
           "QToolButton:pressed { "
           "image: url(:/buttons/skip-previous-orange.png)"
           "}";
}
 
QString Cg2sStyle::getStopStyleSheet()
{
    return "QToolButton { "
           "image: url(:/buttons/stop.png);"
           "icon-size: 24px;"
           "padding: 6px;"
           "margin: 6px;"
           "border: none;"
           "}"
           "QToolButton:pressed { "
           "image: url(:/buttons/stop-orange.png)"
           "}";
}
 
QString Cg2sStyle::getPlayStyleSheet()
{
    return "QToolButton { "
           "image: url(:/buttons/play.png);"
           "icon-size: 48px;"
           "padding: 6px;"
           "margin: 6px;"
           "border: none;"
           "}"
           "QToolButton:pressed { "
           "image: url(:/buttons/play-orange.png)"
           "}";
}
 
QString Cg2sStyle::getPauseStyleSheet()
{
    return "QToolButton { "
           "image: url(:/buttons/pause.png);"
           "icon-size: 24px;"
           "padding: 6px;"
           "margin: 6px;"
           "border: none;"
           "}"
           "QToolButton:pressed { "
           "image: url(:/buttons/pause-orange.png)"
           "}";
}
 
QString Cg2sStyle::getMenuStyleSheet()
{
    return "QToolButton { "
           "color: #8f8f8f;"
           "background-color: #292929;"
           "icon-size: 12px;"
           "padding-left: 10px;"
           "padding-right: 10px;"
           "padding-top: 5px;"
           "padding-bottom: 5px;"
           "border: 1px solid #292929; "
           "}"
           "QToolButton:hover {"
           "color: white;"
           "}"
           "QToolButton:pressed { "
           "color: white; "
           "background-color: #de8e37; "
           "}";
}
 
QString Cg2sStyle::getTableViewStyleSheet()
{
    return "QTableView { "
           "background-color: white; "
           "color: black; "
           "border: 1px solid #e2e2de;"
           "}"
           "QTableView::item:selected {"
           "background-color: #de8e37;"
           "}"
           "QHeaderView::section:horizintal {"
           "background-color: white;"
           "border-style: none;"
           "color: black; "
           "border: 1px solid #e2e2de; "
           "padding: 6px; "
           "}";
}

QToolButton* Cg2sStyle::getToolButton(int x, int y, int btnsize_x, int btnsize_y)
{
    QToolButton* btn = new QToolButton();
    btn->setStyleSheet(Cg2sStyle::getToolButtonStyleSheet());

    btn->setFixedSize(btnsize_x,btnsize_y);
    btn->move(x,y);
    return btn;
}

QPushButton* Cg2sStyle::getPushButton(QString text, int x, int y, int btnsize_x, int btnsize_y)
{
    QPushButton* btn = new QPushButton;
    
    btn->setStyleSheet(Cg2sStyle::getPushButtonStyleSheet());
    btn->setFixedSize(btnsize_x,btnsize_y);

    btn->move(x,y);
    btn->setText(text);
    return btn;
}