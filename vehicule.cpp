#include "vehicule.h"
#include "QSqlRecord"
#include<QMessageBox>
#include<QSqlRecord>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include <QMessageBox>
#include "models.h"
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

QSqlQueryModel * Vehicule ::afficher1()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from vehicule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));

        return model;
}



bool Vehicule :: supprimer(QString matricule)
{
    QSqlQuery query;
    query.prepare("Delete from vehicule where matricule = :matricule ");
    query.bindValue(":matricule",matricule);
    return    query.exec();

}

bool Vehicule::modifier(QString matricule, QString model,int capacity)
{

    QSqlQuery query;

    query.prepare("UPDATE Vehicule SET model= :model, capacity= :capacity where matricule= :matricule ");
    query.bindValue(":matricule", matricule);
    query.bindValue(":capacity",capacity);
    query.bindValue(":model",model);
       return    query.exec();

}


bool  Vehicule::search(QString matricule ){
       QSqlQuery query;
           query.prepare("Select * from Vehicule where matricule= :matricule");
           query.bindValue(":matricule", matricule);
           query.exec();
            QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery(query);
          if(model->rowCount() == 0){ return false;}//thabet e requete ili b3thetha el SQL heki el 7aja mawjouda wala la
       return  true;
}
QSqlQueryModel * Vehicule::sort(){

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from vehicule order by capacity DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CAPACITY "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODEL "));



        return model;
}
QSqlQueryModel * Vehicule :: sortAsc(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from vehicule order by capacity ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CAPACITY "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODEL "));



        return model;
}

void Vehicule :: pdf(){

                       QPdfWriter pdf("C:\\Users\\Utilisateur\\Documents\\crudvehicule\\file.pdf");
                       QPainter painter(&pdf);
                      int i = 4000;
                           painter.setPen(Qt::blue);
                           painter.setFont(QFont("Arial", 30));
                           painter.drawText(1100,1200,"Liste Des A");
                           painter.setPen(Qt::black);
                           painter.setFont(QFont("Arial", 15));
                           painter.drawRect(100,100,7300,2600);
                           painter.drawRect(0,3000,9600,500);
                           painter.setFont(QFont("Arial", 9));
                           painter.drawText(200,3300,"Matricule");
                           painter.drawText(1300,3300,"Capacity");
                           painter.drawText(2100,3300,"Model");

                           QSqlQuery query;
                           query.prepare("select * from Vehicule");
                           query.exec();
                           while (query.next())
                           {
                               painter.drawText(200,i,query.value(0).toString());
                               painter.drawText(1300,i,query.value(1).toString());
                               painter.drawText(2200,i,query.value(2).toString());
                               painter.drawText(3200,i,query.value(3).toString());

                              i = i + 500;
                           }


        int reponse = QMessageBox::Yes;
            if (reponse == QMessageBox::Yes)
            {
                QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                notifyIcon->show();
                notifyIcon->setIcon(QIcon("icone.png"));

                notifyIcon->showMessage("GESTION vehicule CLIENTS ","Liste vehicule pret dans PDF",QSystemTrayIcon::Information,15000);

                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                 painter.end();
            }
}
Models Vehicule :: searchMultiple(QString text){
    Models m;
    QSqlQuery query;
    query.prepare("Select * from Vehicule where matricule like '"+text+"%'");
    //query.bindValue(":val", text);
    query.exec();
     QSqlQueryModel * model = new QSqlQueryModel();
   model->setQuery(query);
   m.matricule = model;

   QSqlQuery query1;
   query1.prepare("Select * from Vehicule where model like '"+text+"%'");
   //query1.bindValue(":val", text);
   query1.exec();
    QSqlQueryModel * model1 = new QSqlQueryModel();
  model1->setQuery(query1);
  m.modele = model1;

  QSqlQuery query2;
  query2.prepare("Select * from Vehicule where capacity like '"+text+"%'");
  //query2.bindValue(":val", text);
  query2.exec();
   QSqlQueryModel * model2 = new QSqlQueryModel();
 model2->setQuery(query2);
 m.capacity = model2;
 return m;
}
QString  Vehicule ::showold(QString name)
{
    QSqlQuery query2;
    query2.prepare("Select * from Vehicule where  matricule= :mat");
    query2.bindValue(":mat", name);

    query2.exec();
    QSqlQueryModel * model2 = new QSqlQueryModel();
    model2->setQuery(query2);
    QString k="MODELE: ";
    QSqlRecord rec = model2->record(0);
    k += rec.value("model").toString();
    k += " CAPACITY: ";
    k += rec.value("capacity").toString();

    return k;
}
