#pragma once

#include <mysql.h>
class CDatabase
{

public:
    CDatabase();
    ~CDatabase();
    void Connect();
    
private:
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    bool bConnected = false;
};