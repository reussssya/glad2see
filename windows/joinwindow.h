#pragma once

#include "../common.h"

class CJoinWindow
{
public:
    CJoinWindow();
    ~CJoinWindow();

private:
    void applyCustomDesign();
    void show() {}
    void hide() {}
    void clicked_onJoin();
    std::vector<std::string> labels {
        "glad2see - join with us",
        "Enter your code:",
        "Join",
        "Quit",
    };

};