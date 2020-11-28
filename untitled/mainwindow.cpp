#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"vehicule.h"
#include<QMessageBox>
#include<QTableView>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include<iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Wedevapplication");
     ui->tableView->setModel(tabvh.afficher());
    ui->comboBox->setModel(Vehicule::afficher1());
    ui->tableView_2->setModel(tabag.afficher());
    ui->comboBox_3->setModel(Agence::afficher1());
    ui->comboBox_4->setModel(Agence::afficher1());

}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_clicked()
{
    ui->stack->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stack->setCurrentIndex(2);
}

void MainWindow::on_pushButton_9_clicked()
{
    Vehicule v(ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text().toUInt());
      v.ajouter();
        ui->tableView->setModel(tabvh.afficher());

}

void MainWindow::on_pushButton_4_clicked()
{
      ui->tableView->setModel(tabvh.afficher());
}

void MainWindow::on_pushButton_8_clicked()
{
    bool q=tabvh.search(ui->lineEdit->text());

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



void MainWindow::on_pushButton_12_clicked()
{
    tabvh.pdf();

}

void MainWindow::on_pushButton_6_clicked()
{

  ui->stack->setCurrentIndex(3);
  ui->comboBox->setModel(Vehicule::afficher1());

}


void MainWindow::on_pushButton_10_clicked()
{
    bool    test=tabvh.supprimer( ui->comboBox->currentText());
        if (test)
        {

              ui->tableView->setModel(tabvh.afficher());
                QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("supression établie"),
                                 QMessageBox::Ok);}
        else{
        QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                QObject::tr("supression non établie"),
                                QMessageBox::Cancel);}
        ui->comboBox->setModel(Vehicule::afficher1());


}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stack->setCurrentIndex(1);

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
        ui->comboBox->currentText();
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->stack->setCurrentIndex(1);

}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stack->setCurrentIndex(1);

}

void MainWindow::on_pushButton_11_clicked()
{
    bool    test=tabvh.modifier(ui->comboBox_2->currentText(),ui->lineEdit_5->text(), ui->lineEdit_6->text().toInt()) ;
       if (test)
       {
             ui->tableView->setModel(tabvh.afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("modification établie"),
                                QMessageBox::Ok);}
       else{
       QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                               QObject::tr("modification non établie"),
                               QMessageBox::Cancel);}
}



void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    ui->comboBox_2->currentText();

}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stack->setCurrentIndex(4);
    ui->comboBox_2->setModel(Vehicule::afficher1());


}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stack->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stack->setCurrentIndex(5);
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->stack->setCurrentIndex(0);
}

void MainWindow::on_pushButton_28_clicked()
{
    ui->stack->setCurrentIndex(6);
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stack->setCurrentIndex(7);
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->stack->setCurrentIndex(5);
}

void MainWindow::on_pushButton_24_clicked()
{
   ui->stack->setCurrentIndex(8);
   ui->comboBox_4->setModel(Agence::afficher1());

}

void MainWindow::on_pushButton_29_clicked()
{
    ui->stack->setCurrentIndex(5);
}

void MainWindow::on_pushButton_27_clicked()
{
    ui->stack->setCurrentIndex(5);

}

void MainWindow::on_tri_clicked(){
    Vehicule * v = new Vehicule(ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text().toUInt());
    if(ui->asc->isChecked()){
       ui->tableView->setModel(v->sortAsc());
    }
    if(ui->des->isChecked()){
        ui->tableView->setModel(v->sort());    }
    delete v;
}

void MainWindow::on_pushButton_18_clicked()
{
    Agence a(ui->lineEdit_8->text(),ui->lineEdit_9->text(),ui->lineEdit_7->text().toUInt());
      a.ajouter();
        ui->tableView_2->setModel(tabag.afficher());
}

void MainWindow::on_pushButton_22_clicked()
{
        tabag.pdf();
}

void MainWindow::on_pushButton_25_clicked()
{
    bool q=tabag.search(ui->lineEdit_10->text());

       if( q == true){
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("Found ! cette Agence existe deja."),
                                QMessageBox::Ok);
       }else{
           QMessageBox::information(nullptr,QObject::tr("not OK"),
                                QObject::tr("Not Found ! cette Agence n'existe pas"),
                                QMessageBox::Ok);
       }
}

void MainWindow::on_pushButton_21_clicked()
{
    Agence * a = new Agence(ui->lineEdit_8->text(),ui->lineEdit_9->text(),ui->lineEdit_7->text().toUInt());
    if(ui->radioButton_2->isChecked()){
       ui->tableView_2->setModel(a->sortAsc());
    }
    if(ui->radioButton->isChecked()){
        ui->tableView_2->setModel(a->sort());    }
    delete a;
}

void MainWindow::on_pushButton_26_clicked()
{
    bool    test=tabag.supprimer( ui->comboBox_3->currentText());
        if (test)
        {

              ui->tableView_2->setModel(tabag.afficher());
                QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("supression établie"),
                                 QMessageBox::Ok);}
        else{
        QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                QObject::tr("supression non établie"),
                                QMessageBox::Cancel);}
        ui->comboBox_3->setModel(Agence::afficher1());
}

void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    ui->comboBox_3->currentText();
}

void MainWindow::on_pushButton_30_clicked()
{
    bool    test=tabag.modifier(ui->comboBox_4->currentText(),ui->lineEdit_11->text(), ui->lineEdit_12->text().toInt()) ;
       if (test)
       {
             ui->tableView_2->setModel(tabag.afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("modification établie"),
                                QMessageBox::Ok);}
       else{
       QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                               QObject::tr("modification non établie"),
                               QMessageBox::Cancel);}
}


void MainWindow::on_comboBox_4_currentIndexChanged(int index)
{
    ui->comboBox_4->currentText();

}
