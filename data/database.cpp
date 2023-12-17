#include "database.h"


CDatabase::CDatabase()
{
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("glad2see");
    
    if(db.open())
    {
        qDebug() << "Connected to database!";
    }
    else
    {
        qDebug() << "Error! Try again... Can't connect to server :(";
        // have to close the window and popup window with error connecting to db
        std::terminate();
    }
}

CDatabase::~CDatabase()
{
    
}