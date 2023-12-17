#pragma once

#include "../common.h"

class CDatabase
{

public:
    CDatabase();
    ~CDatabase();

    
private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
};