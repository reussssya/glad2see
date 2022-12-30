#include "database.h"


CDatabase::CDatabase(bool bLocalConnect)
{
    if(bLocalConnect)
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
            qDebug() << "Can't connect to database!";
        }
    }
    else
    {
        // release 
    }
    
}

CDatabase::~CDatabase()
{
    
}