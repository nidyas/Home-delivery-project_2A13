#ifndef CONTRAT_H
#define CONTRAT_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Contrat
{
    QString ben, type;

public:
    Contrat(){};
    Contrat(QString, QString);
    QString getben()
    {
        return ben;
    }
    QString gettype()
    {
        return type;
    }

    void setben(QString b)
    {
        ben = b;
    }
    void settype(QString t)
    {
        type = t;
    }

    bool ajouter_contrat();
    QSqlQueryModel *afficher_contrat(QString ben, QString type);
    bool supprimer_contrat(QString);
    bool modifier_contrat(QString, QString);

    QString affecter_ben(QString);
    QString affecter_type(QString);

};


#endif // CONTRAT_H
