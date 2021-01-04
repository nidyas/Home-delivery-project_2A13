#include "employe.h"

#include<QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
 EMPLOYE::EMPLOYE(int id,QString nom,QString pren,QString date,int salaire,int nbrheure)
{
this->id=id;
     this->nom=nom;
     this->pren=pren;
     this->date=date;
     this->salaire=salaire;
     this->nbrheure=nbrheure;
}
 bool EMPLOYE::ajouter()
 {
 QSqlQuery query;
     //QString id= QString::number(ID);
     query.prepare("INSERT INTO AJID (id,nom,pren,date_nais,salaire,nbr_heure) "
                         "VALUES (:id, :nom, :pren,:date ,:salaire,:nbr_heure)");
     query.bindValue(":id",id);
     query.bindValue(":nom",nom);
     query.bindValue(":pren",pren);
     query.bindValue(":date",date);
     query.bindValue(":salaire",salaire);
     query.bindValue(":nbr_heure",nbrheure);


     return    query.exec();

 }

 bool EMPLOYE :: supprimer(int idd)
 {
     QString ident1= QString ::number(idd);
     QSqlQuery query;
     query.prepare("Delete from AJID where id = :id ");
     query.bindValue(":id",ident1);
     return    query.exec();

 }


 QSqlQueryModel * EMPLOYE ::afficher()
 {

     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("select * from AJID");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("PREN "));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_NAIS "));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("SALAIRE "));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("NBR_HEURE "));

         return model;
 }

 bool EMPLOYE::modifier(int id , int salaire ,int nbheure)
 {

     QSqlQuery query;
QString idc=QString::number(id);
     query.prepare("UPDATE AJID SET salaire= :salaire, nbr_heure= :nbr_heure where id= :id ");
     query.bindValue(":id", idc);
     query.bindValue(":salaire", salaire);
     query.bindValue(":nbr_heure",nbheure);

             return    query.exec();

 }
 bool modifier(int id,int salaire, int nbrheure)
 {

     QSqlQuery query;

     query.prepare("UPDATE AJID SET salaire= :salaire, nbr_heure= :nbr_heure where id= :id ");
     query.bindValue(":id", id);
     query.bindValue(":salaire", salaire);
     query.bindValue(":nbr_heure",nbrheure);
           return    query.exec();
 }
 QSqlQueryModel * EMPLOYE ::afficheroncombo()
 {

     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("select * from AJID");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

         return model;
 }

bool EMPLOYE::rechercher(int id)
{

    QSqlQuery query;
               query.prepare("Select * from AJID where ID= :ID");
               query.bindValue(":ID", id);
               query.exec();
                QSqlQueryModel * model = new QSqlQueryModel();
              model->setQuery(query);
              if(model->rowCount() == 0){ return false;}//thabet e requete ili b3thetha el SQL heki el 7aja mawjouda wala la
           return  true;


}
void  EMPLOYE::genererPDF(){
//QDateTime datecreation = date.currentDateTime();
              //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                     QPdfWriter pdf("C:\\Users\\hedia\\OneDrive\\Documents\\qtvalid1\\pdf.pdf");
                     QPainter painter(&pdf);
                    int i = 4000;
                         painter.setPen(Qt::red);
                         painter.setFont(QFont("Arial", 30));
                         painter.drawText(1100,1200,"Liste Des EMPLOYE");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial", 15));
                        // painter.drawText(1100,2000,afficheDC);
                         painter.drawRect(100,100,7300,2600);
                         //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                         painter.drawRect(0,3000,9600,500);
                         painter.setFont(QFont("Arial", 9));
                         painter.drawText(200,3300,"Matricule");
                         painter.drawText(1300,3300,"Capacity");
                         painter.drawText(2100,3300,"Model");

                         QSqlQuery query;
                         query.prepare("select * from AJID");
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

              notifyIcon->showMessage("GESTION DES  EMPLYOES ","Liste vehicule pret dans PDF",QSystemTrayIcon::Information,15000);

              painter.end();
          }
          if (reponse == QMessageBox::No)
          {
               painter.end();
          }
}

QSqlQueryModel* EMPLOYE::trides()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from AJID order by SALAIRE DESC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PREN "));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_NAIS "));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("SALAIRE "));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("NBR_HEURE "));



            return model;
}

QSqlQueryModel * EMPLOYE::triasc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from AJID order by SALAIRE ASC");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("PREN "));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_NAIS "));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("SALAIRE "));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("NBR_HEURE "));

           return model;
}







