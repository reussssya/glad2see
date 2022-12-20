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
            // TESTING

            QString name = "reussssya";
            QString giftcode = "abcd";

            
            QSqlQuery query(db);
            query.prepare("SELECT id FROM users WHERE name = :name");
            //query.prepare("INSERT INTO users (name, giftcode) VALUES (:name, :giftcode)");
            query.bindValue(":name", user);
            //query.bindValue(":giftcode", code);

            if(!query.exec())
            {
                qDebug() << "unfortunately cant insert data";
            } else {
                while(query.next())
                {
                    QString id = query.value(0).toString();
                    qDebug() << "here we go" << id;
                }
                
            }
            //WORKS NICE
            


            //-----
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