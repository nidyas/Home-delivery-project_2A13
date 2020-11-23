#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"vehicule.h"
#include <QMainWindow>

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

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_searchbutt_clicked();

    void on_tributt_clicked();

private:
    Ui::MainWindow *ui;
    Vehicule tabvh;
};
#endif // MAINWINDOW_H
