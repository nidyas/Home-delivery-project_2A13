#ifndef VEHICULE_H
#define VEHICULE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include"models.h"
class Vehicule
{

    QString matricule,model;
    int capacity;

public:
     //constructor
    Vehicule();
    Vehicule(QString,QString, int);
    //getters and setters
    QString getmat(){return matricule;}
    QString getmod(){return  model;}
    // methodes
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString mat, QString model, int capacity);

    bool  search(QString matricule );
    QSqlQueryModel * sort();
    QSqlQueryModel * sortAsc();
    static QSqlQueryModel * afficher1();
    void pdf();
    Models searchMultiple(QString);
    QString showold(QString);
};

#endif // VEHICULE_H
