#include "../common.h"
#include "../main.h"


class CDatabase
{

public:
    CDatabase(bool bInstaConnect = true);
    ~CDatabase();

private:
    QString user = "";
    QString code = "";

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
};