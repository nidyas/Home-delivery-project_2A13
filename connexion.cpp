#include "connexion.h"

connexion::connexion()
{

}
bool connexion::create_cnx(){

    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet_2a");
       db.setUserName("amine");
       db.setPassword("sideksaid1");
    if(db.open())
        test=true;
    return test;
}

void connexion::close_cnx(){db.close();}
