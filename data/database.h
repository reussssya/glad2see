#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include "../common.h"

class CDatabase
{
public:
    CDatabase(bool bInstaConnect = true);
    ~CDatabase();
private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
};