#include "mainwindow.h"
#include"connexion.h"
#include<QMessageBox>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    bool test=c.create_cnx();



    if(test){
    //qDebug()<<"connexion etablie";
    QMessageBox::information(nullptr,QObject::tr("database is open"),
                             QObject::tr("connexion etablie"),
                             QMessageBox::Ok);}
    else{
    //qDebug()<<"connexion echouer";
    QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                            QObject::tr("non connecter"),
                            QMessageBox::Cancel);}
     //qDebug()<<"connexion echouer";

    MainWindow w;
    w.show();
    return a.exec();
}
