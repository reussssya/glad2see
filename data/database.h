#pragma once

#include "../common.h"
#include "../main.h"

class CDatabase
{

public:
    CDatabase();
    ~CDatabase();

    
private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
};