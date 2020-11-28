#include "agence.h"
#include "QSqlRecord"
#include<QMessageBox>
#include<QSqlRecord>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include <QMessageBox>
#include<QSqlQueryModel>


Agence::Agence()
{

}



Agence::Agence(QString nom,QString adresse, int budget)
{

    this->nom = nom;
    this->adresse = adresse;
    this->budget = budget;

}

bool Agence::ajouter()
{
        QSqlQuery query;
        query.prepare("INSERT INTO AGENCE (nom,adresse,budget) "
                      "VALUES (:nom,:adresse,:budget)");
        query.bindValue(":nom",nom);
        query.bindValue(":adresse",adresse);
        query.bindValue(":budget",budget);


        return    query.exec();



}
QSqlQueryModel * Agence ::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from AGENCE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("BUDGET "));



        return model;
}

QSqlQueryModel *Agence ::afficher1()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from AGENCE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));

        return model;
}



bool Agence :: supprimer(QString nom)
{
    QSqlQuery query;
    query.prepare("Delete from AGENCE where nom = :nom ");
    query.bindValue(":nom",nom);
    return    query.exec();

}

bool Agence::modifier(QString nom, QString adresse,int budget)
{

    QSqlQuery query;

    query.prepare("UPDATE AGENCE SET adresse= :adresse, budget= :budget where nom= :nom ");
    query.bindValue(":nom", nom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":budget",budget);
       return    query.exec();

}


bool  Agence::search(QString nom ){
       QSqlQuery query;
           query.prepare("Select * from AGENCE where nom= :nom");
           query.bindValue(":nom", nom);
           query.exec();
            QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery(query);
          if(model->rowCount() == 0){ return false;}//thabet e requete ili b3thetha el SQL heki el 7aja mawjouda wala la
       return  true;
}
QSqlQueryModel * Agence::sort(){

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from Agence order by BUDGET DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("BUDGET "));



        return model;
}
QSqlQueryModel * Agence :: sortAsc(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from AGENCE order by BUDGET ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("BUDGET "));



        return model;
}
QSqlQueryModel * Agence ::modi1()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from AGENCE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));

        return model;

}
void Agence :: pdf(){
    //QDateTime datecreation = date.currentDateTime();
                //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                       QPdfWriter pdf("C:\\Users\\Utilisateur\\Documents\\crudvehicule\\file3.pdf");
                       QPainter painter(&pdf);
                      int i = 4000;
                           painter.setPen(Qt::blue);
                           painter.setFont(QFont("Arial", 30));
                           painter.drawText(1100,1200,"Liste Des Agences");
                           painter.setPen(Qt::black);
                           painter.setFont(QFont("Arial", 15));
                          // painter.drawText(1100,2000,afficheDC);
                           painter.drawRect(100,100,7300,2600);
                           //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                           painter.drawRect(0,3000,9600,500);
                           painter.setFont(QFont("Arial", 9));
                           painter.drawText(200,3300,"NOM");
                           painter.drawText(1300,3300,"ADRESSE");
                           painter.drawText(2100,3300,"BUDGET");

                           QSqlQuery query;
                           query.prepare("select * from AGENCE");
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

                notifyIcon->showMessage("GESTION AGENCES ","Liste AGENCES pret dans PDF",QSystemTrayIcon::Information,15000);

                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                 painter.end();
            }
}
