#include "database.h"


CDatabase::CDatabase()
{
    sql::Driver *driver;
    sql::Connection* conn;
    driver = get_driver_instance();
    conn = driver->connect("tcp://127.0.0.1", "root", "");
    //conn->setSchema("g2s");
    
    
    if(true) //con is ok
    {
        std::cout << "Connected to database!";
    }
    else
    {
        std::cout << "Error! Try again... Can't connect to server :(";
        // have to close the window and popup window with error connecting to db
        std::terminate();
    }
}

CDatabase::~CDatabase()
{
    delete this;
}