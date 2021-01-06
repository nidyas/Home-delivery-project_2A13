#ifndef SOCIETE_H
#define SOCIETE_H



#define SOCIETE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Societe
{
    QString nom, add, ser;

public:
    Societe(){};
    Societe(QString, QString,QString);
    QString getNom()
    {
        return nom;
    }
    QString getadd()
    {
        return add;
    }

    QString getser()
    {
        return ser;
    }


    void setNom(QString n)
    {
        nom = n;
    }
    void setadd(QString a)
    {
        add = a;
    }
    void setser(QString s)
    {
        ser = s;
    }

    bool ajouter_soc();
    QSqlQueryModel *afficher_soc(QString nom, QString add ,QString ser);
    QString affecter_nom(QString);
    QString affecter_add(QString);
    QString affecter_ser(QString);

    bool modifier_soc(QString, QString, QString);
    bool supprimer_soc(QString);

};

#endif // SOCIETE_H


