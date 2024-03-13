#pragma once

#include "../common.h"
#include "joinwindow.h"
#include "../trackplayer.hpp"
#include <windowsx.h>
class CMainWindow
{
public:
    CMainWindow();
    ~CMainWindow();

    bool bSubscriptionCheck();
    void applyCustomStyleSheet();
    
    void show() {}
    void hide() {}
    const std::string title = "glad2see";
    



    
    
private:
    CJoinWindow *pJoinWindow;
    
    

    
};
