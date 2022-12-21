#include "../common.h"
#include "../main.h"

class CDatabase
{

public:
    CDatabase(bool bInstaConnect = true);
    ~CDatabase();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
private:

};