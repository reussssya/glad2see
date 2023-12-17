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
    explicit CMainWindow(QWidget* parent = 0);
    ~CMainWindow();

    bool bSubscriptionCheck();
    void applyCustomStyleSheet();
    QSettings* qs = new QSettings(QSettings::NativeFormat,QSettings::UserScope,"glad2see","g2s");

    Qt::WindowFlags flags = Qt::Widget | Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint;
    const QString title = "glad2see";
    
private slots:

    void clicked_onMaximize();

protected:
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
    
    bool nativeEvent(const QByteArray& eventType, void* message, long* result) override
    {
        MSG* msg = reinterpret_cast<MSG*>(message);


        
        ////
        if (msg->message == WM_NCHITTEST)
        {
            *result = 0;
            const LONG borderWidth = 5;
            RECT winrect;
            GetWindowRect(HWND(winId()), &winrect);

            // must be short' to correctly work with multiple monitors (negative coordinates)
            long x = GET_X_LPARAM(msg->lParam);
            long y = GET_Y_LPARAM(msg->lParam);

            bool resizeWidth = minimumWidth() != maximumWidth();
            bool resizeHeight = minimumHeight() != maximumHeight();
            if (resizeWidth)
            {
                //left border
                if (x >= winrect.left && x < winrect.left + borderWidth)
                {
                    *result = HTLEFT;
                }
                //right border
                if (x < winrect.right && x >= winrect.right - borderWidth)
                {
                    *result = HTRIGHT;
                }
            }
            if (resizeHeight)
            {
                //bottom border
                if (y < winrect.bottom && y >= winrect.bottom - borderWidth)
                {
                    *result = HTBOTTOM;
                }
                //top border
                if (y >= winrect.top && y < winrect.top + borderWidth)
                {
                    *result = HTTOP;
                }
            }
            if (resizeWidth && resizeHeight)
            {
                //bottom left corner
                if (x >= winrect.left && x < winrect.left + borderWidth &&
                    y < winrect.bottom && y >= winrect.bottom - borderWidth)
                {
                    *result = HTBOTTOMLEFT;
                }
                //bottom right corner
                if (x < winrect.right && x >= winrect.right - borderWidth &&
                    y < winrect.bottom && y >= winrect.bottom - borderWidth)
                {
                    *result = HTBOTTOMRIGHT;
                }
                //top left corner
                if (x >= winrect.left && x < winrect.left + borderWidth &&
                    y >= winrect.top && y < winrect.top + borderWidth)
                {
                    *result = HTTOPLEFT;
                }
                //top right corner
                if (x < winrect.right && x >= winrect.right - borderWidth &&
                    y >= winrect.top && y < winrect.top + borderWidth)
                {
                    *result = HTTOPRIGHT;
                }
            }

            if (*result != 0)
                return true;

            // delete
            QWidget *action = QApplication::widgetAt(QCursor::pos());
            if (action == this){
                *result = HTCAPTION;
                return true;
            }

            
            
            return false;
        }

        return false;
    }
    
    
private:
    CJoinWindow *pJoinWindow;
    
    QLabel* m_szBuildRelease = new QLabel(this);
    bool m_bIsMaximized = true;
    CTrackPlayer* pTrackPlayer;
    QHBoxLayout* hLayout;
    QGridLayout* pGridLayout = new QGridLayout();
    QToolButton *tBtnExit, *tBtnMinimize, *tBtnMaximize;

    
};