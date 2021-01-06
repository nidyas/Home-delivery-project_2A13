#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class EMPLOYE
{
    QString nom,pren,date;
    int id,salaire,nbrheure;
public:
    //const
    EMPLOYE(){}
    EMPLOYE(int,QString,QString,QString,int,int);
    //getter
    QString getnom(){return nom;}
    QString getpren(){return pren;}
    QString getdate(){return date;}
    int getid(){return id;}
    int getsalaire(){return salaire;}
    int getnbreheure(){return nbrheure;}
    //SETTER
    void setnom(QString n){nom=n;}
    void setpren(QString p){pren=p;}
    void setdate(QString d){date=d;}
    void setid(int i){id=i;}
    void setsalaire(int s){salaire=s;}
    void setnbrheure(int nbr){nbrheure=nbr;}
    //fonction

    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(int id,int salaire, int nbrheure);
    QSqlQueryModel * afficheroncombo();
    bool  rechercher(int id  );
    QSqlQueryModel * trides();
       QSqlQueryModel * triasc();


    bool supprimer(int);
    void genererPDF();
      QString showold(QString);

};

#endif // EMPLOYE_H
