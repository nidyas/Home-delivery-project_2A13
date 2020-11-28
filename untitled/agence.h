#ifndef AGENCE_H
#define AGENCE_H
#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>

class Agence
{
    QString nom,adresse;
    int budget  ;

public:
     //constructor
    Agence();
    Agence(QString,QString, int);
    //getters and setters
    QString getnom(){return nom;}
    QString getadr(){return adresse;}
    // methodes
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString nom , QString adresse, int budget);

    bool  search(QString nom );
    QSqlQueryModel * sort();
    QSqlQueryModel * sortAsc();
    static QSqlQueryModel * afficher1();
    static QSqlQueryModel *modi1();
    void pdf();
};

#endif // AGENCE_H
