#include "mainwindow.h"

#define         MAINWND_W_SIZE          1600
#define         MAINWND_H_SIZE          900

void CMainWindow::applyCustomDesign()
{
    this->setWindowIcon(QIcon("data/img/mainIcon.png"));
    this->setWindowFlags(flags);
    this->setFixedSize(MAINWND_W_SIZE, MAINWND_H_SIZE);


    this->setParent(0);

    // background 
    QPixmap bkgnd("data/img/mainWindow.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);

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

    jwnd = new CJoinWindow;
    jwnd->show();

    connect(jwnd, &CJoinWindow::exec_mainWindow, this, &CMainWindow::show);
    
    this->close();

}

CMainWindow::~CMainWindow()
{

}