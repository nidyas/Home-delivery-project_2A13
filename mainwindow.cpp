#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialoglogin.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("WEDEVAPP");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    Dialoglogin logg;
    logg.setModal(true);
    logg.exec();
}
