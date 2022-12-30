#pragma once

#include "../common.h"
#include "../main.h"

class CDatabase
{

public:
    CDatabase(bool bLocalConnect = true);
    ~CDatabase();

    
private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
};