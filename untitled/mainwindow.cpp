#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"vehicule.h"
#include<QMessageBox>
#include<QTableView>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Welcome");
    ui->tableaff->setModel(tabvh.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    Vehicule v(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text().toUInt());
    v.ajouter();
      ui->tableaff->setModel(tabvh.afficher());



}

void MainWindow::on_pushButton_2_clicked()
{
    bool    test=tabvh.supprimer( ui->lineEdit_7->text());
    if (test)
    {
          ui->tableaff->setModel(tabvh.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("supression établie"),
                             QMessageBox::Ok);}
    else{
    //qDebug()<<"connexion echouer";
    QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                            QObject::tr("supression non établie"),
                            QMessageBox::Cancel);}

}

void MainWindow::on_pushButton_3_clicked()
{

    bool    test=tabvh.modifier(ui->lineEdit_16->text(), ui->lineEdit_8->text(),ui->lineEdit_18->text(),ui->lineEdit_19->text().toUInt()) ;
    if (test)
    {
          ui->tableaff->setModel(tabvh.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("modification établie"),
                             QMessageBox::Ok);}
    else{
    //qDebug()<<"connexion echouer";
    QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                            QObject::tr("modification non établie"),
                            QMessageBox::Cancel);}

}

void MainWindow::on_searchbutt_clicked(){


    bool q=tabvh.search(ui->searchmat->text());

    if( q == true){
       // ui->found->setText("found!");
        QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("Found ! this Vehicule already exists"),
                             QMessageBox::Ok);
    }else{
        //ui->found->setText("not found!");
        QMessageBox::information(nullptr,QObject::tr("not OK"),
                             QObject::tr("Not Found ! this Vehicule does not exist"),
                             QMessageBox::Ok);
    }

}

void MainWindow::on_tributt_clicked()
{
    ui->tableaff->setModel(tabvh.sort());

}

void MainWindow::on_pushButton_7_clicked()
{


    //QDateTime datecreation = date.currentDateTime();
            //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                   QPdfWriter pdf("C:\\Users\\Utilisateur\\Documents\\crudvehicule\\file2.pdf");
                   QPainter painter(&pdf);
                  int i = 4000;
                       painter.setPen(Qt::blue);
                       painter.setFont(QFont("Arial", 30));
                       painter.drawText(1100,1200,"Liste Des Vehicule Client");
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


    int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
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
