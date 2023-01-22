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
        qDebug() << "error cant connect to db";
    }
}

CDatabase::~CDatabase()
{
    
}