#pragma once

#include <mysql.h>
#include "../common.h"
#include <sstream>
class CDatabase
{

public:
    CDatabase();
    ~CDatabase();
    void Connect();
    
    template<typename T>
    T makeQuery(std::string query, int rowIndex = 0)
    {
        mysql_query(conn, query.c_str());
        res = mysql_store_result(conn);
        row = mysql_fetch_row(res);
        return convertTo<T>(row[rowIndex]);
    }
private:
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    bool bConnected = false;
    template<typename T>
    T convertTo(std::string value) {
        T result;
        std::istringstream iss(value);
        iss >> result;
        return result;
    }
};