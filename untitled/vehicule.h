#ifndef VEHICULE_H
#define VEHICULE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
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
    static QSqlQueryModel *modi1();
    void pdf();
};

#endif // VEHICULE_H
