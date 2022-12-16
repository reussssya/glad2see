#include "database.h"

CDatabase::CDatabase(bool bInstaConnect)
{
    if(bInstaConnect)
    {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setUserName("root");
        db.setPassword("");
        db.setDatabaseName("glad2see");

        if(db.open())
        {
            qDebug() << "Connected to database!";
            // TESTING

            /*QString name = "reussssya";
            QString giftcode = "abcd";


            QSqlQuery query;

            query.prepare("INSERT INTO users (name, giftcode) VALUES (:name, :giftcode)");
            query.bindValue(":name", name);
            query.bindValue(":giftcode", giftcode);

            if(query.exec())
            {
                qDebug() << "here we go";
            } else {
                qDebug() << "unfortunately cant insert data";
            }*/
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