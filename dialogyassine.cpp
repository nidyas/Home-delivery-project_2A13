#include "dialogyassine.h"
#include "ui_dialogyassine.h"
#include "vehicule.h"
#include<QMessageBox>
#include"models.h"
#include"agence.h"
#include<QPrinter>
#include<QPrintDialog>
Dialogyassine::Dialogyassine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogyassine)
{
    ui->setupUi(this);
    this->setWindowTitle("WEDEVAPP");
    ui->tableView2->setModel(tabvh.afficher());
    ui->comboBox->setModel(Vehicule::afficher1());
    ui->tableView2_2->setModel(tabag.afficher());
    ui->comboBox_3->setModel(Agence::afficher1());
    ui->comboBox_4->setModel(Agence::afficher1());


}

Dialogyassine::~Dialogyassine()
{
    delete ui;
}

void Dialogyassine::on_pushButton_17_clicked()
{
     ui->stackedWidgetyas->setCurrentIndex(2);

}



void Dialogyassine::on_pushButton_clicked()
{
    ui->stackedWidgetyas->setCurrentIndex(1);
}

void Dialogyassine::on_pushButton_12_clicked()
{
    Vehicule v(ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text().toUInt());
    bool q=  v.ajouter();
        if( q == true){
            ui->tableView2->setModel(tabvh.afficher());

            QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Vehicule  ajoutée"),
                                 QMessageBox::Ok);
        }else{
            QMessageBox::information(nullptr,QObject::tr("not OK"),
                                 QObject::tr("Behicule non ajoutée"),
                                 QMessageBox::Ok);
        }
}

void Dialogyassine::on_pushButton_11_clicked()
{
    ui->stackedWidgetyas->setCurrentIndex(1);
}

void Dialogyassine::on_pushButton_5_clicked()
{
    ui->stackedWidgetyas->setCurrentIndex(4);
    ui->comboBox_2->setModel(Vehicule::afficher1());
}

void Dialogyassine::on_pushButton_6_clicked()
{
    ui->stackedWidgetyas->setCurrentIndex(3);

}

void Dialogyassine::on_pushButton_18_clicked()
{
    ui->stackedWidgetyas->setCurrentIndex(0);

}

void Dialogyassine::on_pushButton_9_clicked()
{
    tabvh.pdf();

}

void Dialogyassine::on_pushButton_14_clicked()
{
    ui->stackedWidgetyas->setCurrentIndex(1);

}

void Dialogyassine::on_pushButton_15_clicked()
{
    ui->stackedWidgetyas->setCurrentIndex(1);

}

void Dialogyassine::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->comboBox->currentText();
}

void Dialogyassine::on_pushButton_13_clicked()
{
    bool    test=tabvh.supprimer( ui->comboBox->currentText());
        if (test)
        {

              ui->tableView2->setModel(tabvh.afficher());
                QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("supression établie"),
                                 QMessageBox::Ok);}
        else{
        QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                QObject::tr("supression non établie"),
                                QMessageBox::Cancel);}
        ui->comboBox->setModel(Vehicule::afficher1());
}

void Dialogyassine::on_pushButton_16_clicked()
{
    bool    test=tabvh.modifier(ui->comboBox_2->currentText(),ui->lineEdit_5->text(), ui->lineEdit_6->text().toInt()) ;
       if (test)
       {
             ui->tableView2->setModel(tabvh.afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("modification établie"),
                                QMessageBox::Ok);}
       else{
       QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                               QObject::tr("modification non établie"),
                               QMessageBox::Cancel);}
}

void Dialogyassine::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    ui->comboBox_2->currentText();
    ui->info->setText(tabvh.showold(arg1));
}

void Dialogyassine::on_pushButton_8_clicked()
{
    Vehicule * v = new Vehicule(ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text().toUInt());
    if(ui->asc->isChecked()){
       ui->tableView2->setModel(v->sortAsc());
    }
    if(ui->des->isChecked()){
        ui->tableView2->setModel(v->sort());    }
    delete v;
}

void Dialogyassine::on_pushButton_7_clicked()
{
    bool q=tabvh.search(ui->lineEdit_7->text());

       if( q == true){
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("Found ! this Vehicule already exists"),
                                QMessageBox::Ok);
       }else{
           QMessageBox::information(nullptr,QObject::tr("not OK"),
                                QObject::tr("Not Found ! this Vehicule does not exist"),
                                QMessageBox::Ok);
       }
}

void Dialogyassine::on_lineEdit_7_textChanged(const QString &arg1)
{
    if(arg1 != ""){
        ui->stackedWidget->setCurrentIndex(0);
        Models m = tabvh.searchMultiple(arg1);
        ui->matricule->setModel(m.matricule);
        ui->modele->setModel(m.modele);
        ui->capacite->setModel(m.capacity);
    }else{
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void Dialogyassine::on_pushButton_2_clicked()
{
    ui->stackedWidgetyas->setCurrentIndex(5);
}

void Dialogyassine::on_pushButton_24_clicked()
{
    ui->stackedWidgetyas->setCurrentIndex(0);

}

void Dialogyassine::on_pushButton_19_clicked()
{
    ui->stackedWidgetyas->setCurrentIndex(6);

}

void Dialogyassine::on_pushButton_22_clicked()
{
    ui->stackedWidgetyas->setCurrentIndex(8);

}

void Dialogyassine::on_pushButton_21_clicked()
{
    ui->stackedWidgetyas->setCurrentIndex(7);

}

void Dialogyassine::on_pushButton_26_clicked()
{
    ui->stackedWidgetyas->setCurrentIndex(5);

}

void Dialogyassine::on_pushButton_28_clicked()
{
    ui->stackedWidgetyas->setCurrentIndex(5);

}

void Dialogyassine::on_pushButton_30_clicked()
{
    ui->stackedWidgetyas->setCurrentIndex(5);

}

void Dialogyassine::on_pushButton_27_clicked()
{
    Agence a(ui->lineEdit_10->text(),ui->lineEdit_11->text(),ui->lineEdit_9->text().toUInt());
     bool  q=a.ajouter();
        if( q == true){
            ui->tableView2_2->setModel(tabag.afficher());

            QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Agence  ajoutée"),
                                 QMessageBox::Ok);
        }else{
            QMessageBox::information(nullptr,QObject::tr("not OK"),
                                 QObject::tr("Agence non ajoutée"),
                                 QMessageBox::Ok);
        }
}

void Dialogyassine::on_pushButton_20_clicked()
{
    tabag.pdf();
}

void Dialogyassine::on_pushButton_29_clicked()
{
    bool    test=tabag.supprimer( ui->comboBox_3->currentText());
        if (test)
        {

              ui->tableView2_2->setModel(tabag.afficher());
                QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("supression établie"),
                                 QMessageBox::Ok);}
        else{
        QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                QObject::tr("supression non établie"),
                                QMessageBox::Cancel);}
        ui->comboBox_3->setModel(Agence::afficher1());
}

void Dialogyassine::on_comboBox_3_currentIndexChanged(int index)
{
    ui->comboBox_3->currentText();

}

void Dialogyassine::on_pushButton_31_clicked()
{
    bool    test=tabag.modifier(ui->comboBox_4->currentText(),ui->lineEdit_13->text(), ui->lineEdit_12->text().toInt()) ;
       if (test)
       {
             ui->tableView2_2->setModel(tabag.afficher());
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("modification établie"),
                                QMessageBox::Ok);}
       else{
       QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                               QObject::tr("modification non établie"),
                               QMessageBox::Cancel);}
}

void Dialogyassine::on_comboBox_4_currentIndexChanged(const QString &arg1)
{
    ui->comboBox_4->currentText();
    ui->info2->setText(tabag.showold(arg1));

}

void Dialogyassine::on_pushButton_23_clicked()
{
    Agence * a = new Agence(ui->lineEdit_10->text(),ui->lineEdit_11->text(),ui->lineEdit_9->text().toUInt());
    if(ui->asc_2->isChecked()){
       ui->tableView2_2->setModel(a->sortAsc());
    }
    if(ui->des_2->isChecked()){
        ui->tableView2_2->setModel(a->sort());    }
    delete a;
}

void Dialogyassine::on_lineEdit_8_textChanged(const QString &arg1)
{
    if(arg1 != ""){
        ui->stackedWidget_2->setCurrentIndex(0);
        Models m = tabag.searchMultiple(arg1);
        ui->matricule_2->setModel(m.matricule);
        ui->modele_2->setModel(m.modele);
        ui->capacite_2->setModel(m.capacity);
    }else{
        ui->stackedWidget_2->setCurrentIndex(1);
    }
}

void Dialogyassine::on_pushButton_3_clicked()
{
    QPrinter  printer;
        printer.setPrinterName("test");
        QPrintDialog dialog(&printer,this);
        if (dialog.exec()==QDialog::Rejected) return;
        //ui->textEdit->print(&printer);
}

void Dialogyassine::on_pushButton_33_clicked()
{
    stat =new statayadi(this);
           stat->show();
}

void Dialogyassine::on_pushButton_32_clicked()
{
    QPrinter  printer;
        printer.setPrinterName("test");
        QPrintDialog dialog(&printer,this);
        if (dialog.exec()==QDialog::Rejected) return;
}
