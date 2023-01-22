#pragma once

#include "../common.h"
#include <QMainWindow>
#include "joinwindow.h"

class CMainWindow : public QMainWindow
{
public:
    CMainWindow(QMainWindow* parent = 0);
    ~CMainWindow();

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
private:
    void applyCustomDesign();
    bool bSubscriptionCheck();
    
    QSettings* qs = new QSettings(QSettings::NativeFormat,QSettings::UserScope,"glad2see","g2s");

    CJoinWindow *jwnd;

    Qt::WindowFlags flags = Qt::Window | Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint;
    const QString title = "glad2see - private programkit";
};