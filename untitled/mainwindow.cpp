#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"vehicule.h"
#include<QMessageBox>
#include<QTableView>
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




    if(tabvh.search(ui->searchmat->text()) == true){
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
