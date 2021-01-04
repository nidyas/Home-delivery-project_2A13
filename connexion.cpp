#include "connexion.h"

connexion::connexion()
{

}
bool connexion::create_cnx(){

    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("AJID");
    db.setUserName("SYSTEM");
    db.setPassword("SYSTEM");
    if(db.open())
        test=true;
    return test;
}

void connexion::close_cnx(){db.close();}
