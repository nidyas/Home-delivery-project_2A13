#include "employe.h"
#include "dialoghedi.h"
#include "ui_dialoghedi.h"
#include "departement.h"
#include<QMessageBox>
#include<QTableView>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include "dialogbaaedlogin.h"
#include <QtDebug>
#include "arduino.h"
#include <QFileDialog>
#include <QFile>

Dialoghedi::Dialoghedi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialoghedi)
{
    ui->setupUi(this);
    this->setWindowTitle("WEDEVAPP");
    ui->tableView->setModel(emp.afficher());
ui->comboBox->setModel(emp.afficheroncombo());
ui->comboBox_4->setModel(emp.afficheroncombo());
    ui->combomodep->setModel(depp.afficheroncombodep());
    ui->combosupdep->setModel(depp.afficheroncombodep());
    ui->tableView_2->setModel(depp.afficherdep());
    int ret=A.connect_arduino();
             switch(ret){
             case(0):qDebug()<< "arduino is availble and connected to :"<< A.getarduino_port_name();
                 break;
             case(1):qDebug()<< "arduino is availble but not connected to :"<< A.getarduino_port_name();
                 break;
             case(-1):qDebug()<< "arduino is not availble";
             }
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(alert()));
}


Dialoghedi::~Dialoghedi()
{
    delete ui;
}

void Dialoghedi::alert(){

    data=A.read_from_arduino();
    QString DataAsString = QString(data);
    qDebug()<< data;
    if (data=="1"){
           A.write_to_arduino("1");
    }
    if (data=="0"){
           A.write_to_arduino("0");
    }
    if(data=="1"){
            check=!check;
       }
    if (data=="1"){
        QMessageBox::critical(nullptr, QObject::tr("INVITE"),
                    QObject::tr("THE GAZ IS DETECTED ! .\n"
                                "Please check your GAZ ."), QMessageBox::Ok);

    }

}

void Dialoghedi::on_pushButton_2_clicked()//aller du menu a ajouter
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialoghedi::on_pushButton_10_clicked()//aller retour au  menu
{
     ui->stackedWidget->setCurrentIndex(0);
}

void Dialoghedi::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Dialoghedi::on_pushButton_5_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void Dialoghedi::on_pushButton_6_clicked()
{
      ui->stackedWidget->setCurrentIndex(4);
}


void Dialoghedi::on_pushButton_20_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
}

void Dialoghedi::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialoghedi::on_pushButton_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialoghedi::on_pushButton_19_clicked()
{
    
    EMPLOYE e(ui->lineEditid1->text().toInt(),ui->lineEditid2->text(),ui->lineEdit3->text(),ui->dateEdit->text(),ui->lineEdit4->text().toInt(),ui->lineEdit5->text().toInt());
       bool test= e.ajouter();

       QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


       if (test)
       {ui->tableView->setModel(emp.afficher());//actualisation taa afficher
           notifyIcon->showMessage("GESTION DES  EMPLYOES ","Liste employe pret dans PDF",QSystemTrayIcon::Information,15000);
                   QMessageBox::information(nullptr,QObject::tr("ok"),
                                            QObject::tr("ajout succful .\n"),
                           QMessageBox::Cancel);
               }

               else
                   QMessageBox::critical(nullptr,QObject::tr("ajout not open"),
                                           QObject::tr("click cancel to exist"),
                                           QMessageBox::Cancel);



        ui->tableView->setModel(emp.afficher());
}

void Dialoghedi::on_pushButton_9_clicked() //generer pdf
{
    emp.genererPDF();
}

void Dialoghedi::on_comboBox_currentIndexChanged(int index) //combo modifier
{
    int a;
        a=index;
        index=a;
        ui->comboBox->currentText();
}


void Dialoghedi::on_pushButton_21_clicked() //button modifier
{
    bool    test=emp.modifier(ui->comboBox->currentText().toInt(),ui->lineEdit_20->text().toInt(), ui->lineEdit_11->text().toInt()) ;
          if (test)
          {
                ui->tableView->setModel(emp.afficher());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}




void Dialoghedi::on_comboBox_4_currentIndexChanged(int index) //combo supp
{
    int a;
        a=index;
    ui->comboBox_4->currentText();//combo mt3 supprimer
}




void Dialoghedi::on_pushButton_24_clicked()
{
    bool test=emp.supprimer(ui->comboBox_4->currentText().toInt());
    if(test)
    {ui->tableView->setModel(emp.afficher());//actualisation taa afficher
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}



void Dialoghedi::on_pushButton_8_clicked()
{
    EMPLOYE *e =new EMPLOYE(ui->lineEditid1->text().toInt(),ui->lineEditid2->text(),ui->lineEdit3->text(),ui->dateEdit->text(),ui->lineEdit4->text().toInt(),ui->lineEdit5->text().toInt());
    if(ui->tridesemp->isChecked()){
       ui->tableView->setModel(e->trides());

    }
    if(ui->triascemp->isChecked()){
        ui->tableView->setModel(e->triasc());    }
    delete e;
}

void Dialoghedi::on_comboBox_3_currentIndexChanged(int index)//rechercher
{
    ui->comboBox_3->currentText();
}

void Dialoghedi::on_lineEdit_5_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->comboBox_3->currentText()=="ID")
    {
        query->prepare("SELECT * FROM AJID WHERE ID LIKE'"+arg1+"%'");//
query->exec();
    model->setQuery(*query);
ui->tableView->setModel(model);


    }
    else {
        if(ui->comboBox_3->currentText()=="NOM"){
            query->prepare("SELECT * FROM AJID WHERE NOM LIKE'"+arg1+"%'");//
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);
        }


    else {
        if(ui->comboBox_3->currentText()=="PREN")
        {
            query->prepare("SELECT * FROM AJID WHERE PREN LIKE'"+arg1+"%'");//
    query->exec();
        model->setQuery(*query);
    ui->tableView->setModel(model);

        }
    }}}

void Dialoghedi::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->comboBox_4->currentText();
    ui->label_10->setText(emp.showold(arg1));
}

void Dialoghedi::on_pushButton_16_clicked()//ajouter dep
{
     ui->stackedWidget->setCurrentIndex(6);
}

void Dialoghedi::on_pushButton_26_clicked()
{
    depart d(ui->lineEdit_7->text().toInt(),ui->lineEdit_14->text(),ui->lineEdit_17->text().toInt());

      d.ajouterdep();
}

void Dialoghedi::on_combomodep_currentIndexChanged(int index)
{
    int a;
    a=index;
     ui->combomodep->currentText();
}

void Dialoghedi::on_pushButton_58_clicked()
{
    bool    test=depp.modifierdep(ui->combomodep->currentText().toInt(),ui->lineEdit_36->text().toInt()) ;
         if (test)
         {ui->tableView_2->setModel(depp.afficherdep());//actualisation taa afficher
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("modifier succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("modifier not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);}





void Dialoghedi::on_pushButton_28_clicked()
{
    bool test=depp.supprimerdep(ui->combosupdep->currentText().toInt());
    if(test)
    {ui->tableView_2->setModel(depp.afficherdep());//actualisation taa afficher
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}

void Dialoghedi::on_combosupdep_currentIndexChanged(int index)
{
    int a;
    a=index;
     ui->combosupdep->currentText();
}

void Dialoghedi::on_pushButton_12_clicked()
{
       ui->stackedWidget->setCurrentIndex(7);
}

void Dialoghedi::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void Dialoghedi::on_pushButton_18_clicked()
{
    depp.genererPDFdep();
}

void Dialoghedi::on_pushButton_17_clicked()
{
    depart *d =new depart(ui->lineEdit_7->text().toInt(),ui->lineEdit_14->text(),ui->lineEdit_17->text().toInt());
    if(ui->triascdep->isChecked()){
       ui->tableView_2->setModel(d->triascdep());

    }
    if(ui->tridesdep->isChecked()){
        ui->tableView_2->setModel(d->tridesdep());    }
    delete d;
}

void Dialoghedi::on_comboBox_2_currentIndexChanged(int index)
{
     ui->comboBox_2->currentText();
}

void Dialoghedi::on_lineEdit_8_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->comboBox_2->currentText()=="ID_"
            "DEP"){
        query->prepare("SELECT * FROM DEPART WHERE ID_DEP LIKE'"+arg1+"%'");//
query->exec();
    model->setQuery(*query);
ui->tableView_2->setModel(model);


    }
    else {
        if(ui->comboBox_2->currentText()=="nom"){
            query->prepare("SELECT * FROM DEPART WHERE NOM_DEP LIKE'"+arg1+"%'");//+tri
    query->exec();
        model->setQuery(*query);
    ui->tableView_2->setModel(model);
        }

        }
}



void Dialoghedi::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}



void Dialoghedi::on_pushButton_25_clicked()
{ hide();
    Dialogbaaedlogin logg;
    logg.setModal(true);
    logg.exec();

}

void Dialoghedi::on_pushButton_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialoghedi::on_pushButton_29_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialoghedi::on_pushButton_30_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}

void Dialoghedi::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialoghedi::on_pushButton_31_clicked()
{
    stat_employe=new stat_employee(this);
    stat_employe->show();
}

void Dialoghedi::on_pushButton_32_clicked()
{
    stat_depar=new stat_depart(this);
    stat_depar->show();
}



void Dialoghedi::on_pushButton_33_clicked()
{
    QTableView *table;
               table = ui->tableView;

               QString filters("CSV files (.csv);;All files (.*)");
               QString defaultFilter("CSV files (*.csv)");
               QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                  filters, &defaultFilter);
               QFile file(fileName);

               QAbstractItemModel *model =  table->model();
               if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                   QTextStream data(&file);
                   QStringList strList;
                   for (int i = 0; i < model->columnCount(); i++) {
                       if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                           strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                       else
                           strList.append("");
                   }
                   data << strList.join(";") << "\n";
                   for (int i = 0; i < model->rowCount(); i++) {
                       strList.clear();
                       for (int j = 0; j < model->columnCount(); j++) {

                           if (model->data(model->index(i, j)).toString().length() > 0)
                               strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") + "\n";
                   }
                   file.close();
                   QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
               }
}

void Dialoghedi::on_pushButton_34_clicked()
{
     A.write_to_arduino("5");
}
