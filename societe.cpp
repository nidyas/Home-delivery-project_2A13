#include "societe.h"
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include <QPageSize>
#include <QFont>
Societe::Societe(QString nom,QString add, QString ser)
{
    this->nom = nom;
    this->add = add;
    this->ser = ser;

}
bool Societe::ajouter_soc()
{
    QSqlQuery query;

    query.prepare("INSERT INTO SOCIETE(NOM,AD,SER) VALUES(:nom,:ad,:ser);");

    query.bindValue(":nom", nom);
    query.bindValue(":ad", add);
    query.bindValue(":ser", ser);

    return query.exec();
}
QSqlQueryModel * Societe::afficher_soc(QString nom, QString add,QString ser)
{
    QSqlQuery query;

    QSqlQueryModel *model1 = new QSqlQueryModel();

        if(nom=="XYZ" && add=="XYZ" && ser=="XYZ")
        {
         model1->setQuery("SELECT * FROM SOCIETE");
        }
        else if(nom!="XYZ" && add=="XYZ" && ser=="XYZ" )
           {
            query.prepare("SELECT * FROM SOCIETE WHERE NOM= :nom");
            query.bindValue(":nom",nom);
            query.exec();
            model1->setQuery(query);
           }
        else if(nom=="XYZ" && add!="XYZ" && ser=="XYZ")
        {
            query.prepare("SELECT * FROM SOCIETE WHERE AD= :ad");
            query.bindValue(":ad",add);
            query.exec();
            model1->setQuery(query);
        }
        else if(nom=="XYZ" && add=="XYZ" && ser!="XYZ")
        {
            query.prepare("SELECT * FROM SOCIETE WHERE SER= :ser");
            query.bindValue(":ser",ser);
            query.exec();
            model1->setQuery(query);
        }


        model1->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
        model1->setHeaderData(1, Qt::Horizontal, QObject::tr("add"));
        model1->setHeaderData(2, Qt::Horizontal, QObject::tr("ser"));

        return model1;
    }
QString Societe::affecter_nom(QString nom)
{
    QString n;
    QSqlQuery query;

    query.prepare("Select * from SOCIETE where NOM= :nom");
    query.bindValue(":nom", nom);
    if (query.exec())
    {
        while (query.next())
        {
            n = query.value(0).toString();
        }
    }
    return n;
}
QString Societe::affecter_add(QString nom)
{
    QString a;
    QSqlQuery query;
    query.prepare("Select * from SOCIETE where NOM= :nom");
    query.bindValue(":nom", nom);
    if (query.exec())
    {
        while (query.next())
        {
            a = query.value(1).toString();
        }
    }
    return a;
}
QString Societe::affecter_ser(QString nom)
{
    QString s;
    QSqlQuery query;
    query.prepare("Select * from SOCIETE where NOM= :nom");
    query.bindValue(":nom", nom);
    if (query.exec())
    {
        while (query.next())
        {
            s = query.value(2).toString();
        }
    }
    return s;
}


bool Societe::modifier_soc(QString nom, QString add, QString ser)
  {  QSqlQuery query;

    query.prepare("UPDATE SOCIETE SET NOM= :nom, AD= :ad, SER= :ser WHERE NOM= :nom");
    query.bindValue(":nom",nom);
    query.bindValue(":ad", add);
    query.bindValue(":ser", ser);

    return query.exec();
}
bool Societe::supprimer_soc(QString nom)
{
    QSqlQuery query;

        query.prepare("DELETE FROM SOCIETE WHERE NOM= :nom");
        query.bindValue(":nom", nom);
        return query.exec();
}
