#ifndef CONNEXION_H
#define CONNEXION_H
#include<QSqlDatabase>


class connexion
{
    QSqlDatabase db;
public:
    connexion();
    bool create_cnx();
    void close_cnx();
};

#endif // CONNEXION_H
