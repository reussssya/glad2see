#pragma once

#include "../common.h"
#include <QMainWindow>
#include "joinwindow.h"
#include "../trackplayer.hpp"
#include <windowsx.h>
class CMainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

    bool bSubscriptionCheck();
    void applyCustomStyleSheet();
    QSettings* qs = new QSettings(QSettings::NativeFormat,QSettings::UserScope,"glad2see","g2s");

    Qt::WindowFlags flags = Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint;
    const QString title = "";
    
private slots:

    void clicked_onMaximize();
    
private:
    CJoinWindow *pJoinWindow;
    
    QLabel* m_szBuildRelease = new QLabel(this);
    bool m_bIsMaximized = true;
    CTrackPlayer* pTrackPlayer;
    QHBoxLayout* hLayout;
    QGridLayout* pGridLayout = new QGridLayout();
    QToolButton *tBtnExit, *tBtnMinimize, *tBtnMaximize;

    
};
