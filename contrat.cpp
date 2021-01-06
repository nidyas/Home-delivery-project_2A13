#include "contrat.h"
#include <string>
#include <iostream>
Contrat::Contrat(QString ben, QString type)
{
    this->ben = ben;
    this->type = type;

}
bool Contrat::ajouter_contrat()
{

    QSqlQuery query;
    query.prepare("INSERT INTO CONTRAT (BEN,TYPE) VALUES(:ben,:type);");

    query.bindValue(":ben", ben);
    query.bindValue(":type", type);

    return query.exec();
}
bool Contrat::supprimer_contrat(QString ben)
{
    QSqlQuery query;

    query.prepare("DELETE FROM CONTRAT WHERE BEN= :ben");
    query.bindValue(":ben", ben);
    return query.exec();
}
QSqlQueryModel *Contrat::afficher_contrat(QString ben,QString type)
{
    QSqlQuery query;

    QSqlQueryModel *model = new QSqlQueryModel();

    if(ben=="XYZ" && type=="XYZ")
    {
     model->setQuery("SELECT * FROM CONTRAT");
    }
    else if(ben!="XYZ" && type=="XYZ")
       {
        query.prepare("SELECT * FROM CONTRAT WHERE BEN= :ben");
        query.bindValue(":ben",ben);
        query.exec();
        model->setQuery(query);
       }
    else if(ben=="XYZ" && type !="XYZ")
    {
        query.prepare("SELECT * FROM CONTRAT WHERE TYPE= :type");
        query.bindValue(":type",type);
        query.exec();
        model->setQuery(query);
    }
    else if(ben!="XYZ" && type!="XYZ")
    {
        query.prepare("SELECT * FROM CONTRAT WHERE BEN= :ben AND TYPE= :type");
        query.bindValue(":ben",ben);
        query.bindValue(":type",type);
        query.exec();
        model->setQuery(query);
    }



    model->setHeaderData(0, Qt::Horizontal, QObject::tr("BEN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));

    return model;
}
QString Contrat::affecter_ben(QString ben)
{
 QString b;
    QSqlQuery query;

    query.prepare("Select * from CONTRAT where BEN= :ben");
    query.bindValue(":ben", ben);
    if (query.exec())
    {
        while (query.next())
        {
            b = query.value(0).toString();
        }
    }
    return b;
}
QString Contrat::affecter_type(QString ben)
{
    QString t;
    QSqlQuery query;
    query.prepare("Select * from CONTRAT where BEN= :ben");
    query.bindValue(":ben", ben);
    if (query.exec())
    {
        while (query.next())
        {
            t = query.value(1).toString();
        }
    }
    return t;
}

bool Contrat::modifier_contrat(QString ben , QString type)
{
    QSqlQuery query;

    query.prepare("UPDATE CONTRAT SET BEN= :ben, TYPE= :type");
    query.bindValue(":ben", ben);
    query.bindValue(":type", type);

    return query.exec();
}
