#pragma once

#include "../common.h"

class CJoinWindow
{
public:
    CJoinWindow();
    ~CJoinWindow();
    void show() {
        spdlog::info("opened CJoinWindow");
    }
    void hide() {
        spdlog::info("closed CJoinWindow");
    }
protected:
    void applyCustomDesign();

    void clicked_onJoin();
    std::vector<std::string> labels {
        "glad2see - join with us",
        "Enter your code:",
        "Join",
        "Quit",
    };

};