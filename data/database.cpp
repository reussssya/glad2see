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
        //std::cout << "Connected to glad2see" << std::endl;
        if(mysql_select_db(conn, "users"))
        {
            //  std::cout << "Connected to users' database" << std::endl;
            bConnected = true;
        }
        else
        {
            //std::cout << "Can't connect to database" << std::endl;
        }
    }
    

}
CDatabase::~CDatabase()
{
    mysql_close(conn);
}