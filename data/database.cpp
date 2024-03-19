#include "database.h"


CDatabase::CDatabase()
{
    Connect();
}
void CDatabase::Connect()
{
    conn = mysql_init(NULL);

    if(mysql_real_connect(conn, "localhost", "root", "", "glad2see", 0, NULL, 0))
    {
        spdlog::info("Connected to server");
        if(mysql_select_db(conn, "users"))
        {
            spdlog::info("Connected to database");
            bConnected = true;
        }
        else
        {
            spdlog::info("Can't connect to database");
        }
    }
    else
    {
        spdlog::info("Can't connect to server");
    }

    

}

CDatabase::~CDatabase()
{
    mysql_close(conn);
}