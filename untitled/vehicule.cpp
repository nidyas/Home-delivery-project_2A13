#include "vehicule.h"
#include "QSqlRecord"
#include<QMessageBox>
#include<QSqlRecord>
Vehicule::Vehicule()
{

}
Vehicule::Vehicule(QString matricule,QString model, int capacity)
{

    this->matricule = matricule;
    this->model = model;
    this->capacity = capacity;

}

bool Vehicule::ajouter()
{
        QSqlQuery query;
        query.prepare("INSERT INTO Vehicule(matricule,model,capacity) "
                      "VALUES (:matricule,:model,:capacity)");
        query.bindValue(":matricule",matricule);
        query.bindValue(":capacity",capacity);
        query.bindValue(":model",model);


        return    query.exec();



}
QSqlQueryModel * Vehicule ::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from vehicule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CAPACITY "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODEL "));



        return model;
}
bool Vehicule :: supprimer(QString matricule)
{
    QSqlQuery query;
    query.prepare("Delete from vehicule where matricule = :matricule ");
    query.bindValue(":matricule",matricule);
    return    query.exec();

}

bool Vehicule::modifier(QString matricule_a_changer, QString matricule,QString model,int capacity)
{

    QSqlQuery query;

    query.prepare("UPDATE Vehicule SET matricule= :mat, model= :model, capacity= :capacity where matricule= :matricule ");
    query.bindValue(":mat", matricule_a_changer);
    query.bindValue(":matricule", matricule);
    query.bindValue(":model",model);
    query.bindValue(":capacity",capacity);

            return    query.exec();

}
bool Vehicule::search(QString matricule ){
       QSqlQuery query;
       query.prepare("SELECT * from Vehicule where matricule= :matricule");
       query.bindValue(":matricule", matricule);

       QSqlQueryModel *q = new QSqlQueryModel();
       q->setQuery(query);
       if(q->record(0).isEmpty() == true){return false;}


       query.exec();
       return true;

}

