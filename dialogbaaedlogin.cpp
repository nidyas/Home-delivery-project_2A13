#include "dialogbaaedlogin.h"
#include "ui_dialogbaaedlogin.h"
#include"dialoghedi.h"
#include"dialoglogin.h"
#include "dialogyassine.h"
#include "dialogamine.h"

Dialogbaaedlogin::Dialogbaaedlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogbaaedlogin)
{
    ui->setupUi(this);
    this->setWindowTitle("WEDEVAPP");
}

Dialogbaaedlogin::~Dialogbaaedlogin()
{
    delete ui;
}

void Dialogbaaedlogin::on_pushButton_clicked()
{
    hide();
    Dialoghedi DH;
    DH.setModal(true);
    DH.exec();
}

void Dialogbaaedlogin::on_pushButton_3_clicked()
{
    hide();
    Dialoglogin logg;
    logg.setModal(true);
    logg.exec();
}

void Dialogbaaedlogin::on_pushButton_2_clicked()
{
    hide();
    Dialogyassine Dy;
    Dy.setModal(true);
    Dy.exec();
}

void Dialogbaaedlogin::on_pushButton_4_clicked()
{

    hide();
    Dialogamine DA;
    DA.setModal(true);
    DA.exec();
}
