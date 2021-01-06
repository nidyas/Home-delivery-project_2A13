#include "departement.h"

#include<QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>

 depart::depart()
{

}


    depart::depart(int iddep,QString nomdep,int nbr_emp)
    {
    this->iddep=iddep;
        this->nomdep=nomdep;
        this->nbr_emp=nbr_emp;
    }

    bool depart::ajouterdep()
    {
    QSqlQuery query;
        //QString id= QString::number(ID);
        query.prepare("INSERT INTO DEPART (id_dep,nom_dep,nbr_emp) "
                            "VALUES (:iddep, :nomdep,:nbr_emp)");
        query.bindValue(":iddep",iddep);
        query.bindValue(":nomdep",nomdep);
        query.bindValue(":nbr_emp",nbr_emp);


        return    query.exec();

    }

    QSqlQueryModel * depart ::afficherdep()
    {

        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from DEPART");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DEP"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_DEP "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBR_EMP "));
            return model;
    }

    bool depart :: supprimerdep(int idd)
    {
        QString ident1= QString ::number(idd);
        QSqlQuery query;
        query.prepare("Delete from DEPART where id_dep = :iddep ");
        query.bindValue(":iddep",ident1);
        return    query.exec();

    }

    QSqlQueryModel * depart ::afficheroncombodep()
    {

        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from DEPART");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DEP"));

            return model;
    }

    bool depart::modifierdep(int id,int nbremp)
    {

        QSqlQuery query;
   QString idc=QString::number(id);
        query.prepare("UPDATE DEPART SET NBR_EMP= :nbr_emp where ID_DEP= :iddep");
        query.bindValue(":iddep", idc);
        query.bindValue(":nbr_emp", nbremp);

                return    query.exec();

    }


    void  depart::genererPDFdep(){
    //QDateTime datecreation = date.currentDateTime();
                  //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                         QPdfWriter pdf("C:\\Users\\hedia\\OneDrive\\Documents\\qtvalid1\\pdfdep.pdf");
                         QPainter painter(&pdf);
                        int i = 4000;
                             painter.setPen(Qt::blue);
                             painter.setFont(QFont("Arial", 30));
                             painter.drawText(1100,1200,"Liste Des depart");
                             painter.setPen(Qt::black);
                             painter.setFont(QFont("Arial", 15));
                            // painter.drawText(1100,2000,afficheDC);
                             painter.drawRect(100,100,7300,2600);
                             //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                             painter.drawRect(0,3000,9600,500);
                             painter.setFont(QFont("Arial", 9));
                             painter.drawText(200,3300,"id dep");
                             painter.drawText(1300,3300,"nom_dep");
                             painter.drawText(2100,3300,"nbr_emp");

                             QSqlQuery query;
                             query.prepare("select * from DEPART");
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

                  notifyIcon->showMessage("GESTION DES  DEPART ","Liste depart pret dans PDF",QSystemTrayIcon::Information,15000);

                  painter.end();
              }
              if (reponse == QMessageBox::No)
              {
                   painter.end();
              }
    }

    bool  depart::rechercherdepp(int id  )
    {

        QSqlQuery query;
                   query.prepare("Select * from DEPART where ID_DEP= :iddep");
                   query.bindValue(":iddep", id);
                   query.exec();
                    QSqlQueryModel * model = new QSqlQueryModel();
                  model->setQuery(query);
                  if(model->rowCount() == 0){ return false;}//thabet e requete ili b3thetha el SQL heki el 7aja mawjouda wala la
               return  true;


    }

    QSqlQueryModel* depart::tridesdep()
    {
        QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("select * from DEPART order by NBR_EMP DESC");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DEP"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_DEP "));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBR_EMP "));




                return model;
    }

    QSqlQueryModel* depart::triascdep()
    {
        QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("select * from DEPART order by NBR_EMP ASC");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DEP"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_DEP "));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBR_EMP "));




                return model;
    }
