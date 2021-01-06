#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialoglogin.h"
#include "stat_employee.h"
#include"statayadi.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    stat_employee *stat_employee;
    statayadi *stat;

};
#endif // MAINWINDOW_H
