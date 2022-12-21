#include "database.h"


CDatabase::CDatabase(bool bInstaConnect)
{
    if(bInstaConnect)
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
    
}

CDatabase::~CDatabase()
{
    
}