#include "dialoglogin.h"
#include "ui_dialoglogin.h"
#include "dialogbaaedlogin.h"
#include<QMessageBox>

Dialoglogin::Dialoglogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialoglogin)
{
    ui->setupUi(this);
    this->setWindowTitle("LOGIN");
}

Dialoglogin::~Dialoglogin()
{
    delete ui;
}

void Dialoglogin::on_pushButton_clicked()
{

    if((ui->lineEdit->text()=="admin")&&(ui->lineEdit_2->text()=="admin"))
  {

        QMessageBox::information(this,"Sucess","Accee garantie");
        hide();
        Dialogbaaedlogin baaedlogg;
        baaedlogg.setModal(true);
        baaedlogg.exec();
  }
      else
      {
          QMessageBox::information(this,"Erreur","Verifier vos informations");

      }

}
