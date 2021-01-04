#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class depart
{
    QString nomdep;
    int iddep,nbr_emp;
public:
    depart();
    depart(int,QString,int);

    bool ajouterdep();
    QSqlQueryModel * afficherdep();
    QSqlQueryModel * afficheroncombodep();
    bool modifierdep(int id,int nbremp);
    bool supprimerdep(int);
    void genererPDFdep();
    bool  rechercherdepp(int id  );
    QSqlQueryModel * tridesdep();
       QSqlQueryModel * triascdep();
};




#endif // DEPARTEMENT_H
