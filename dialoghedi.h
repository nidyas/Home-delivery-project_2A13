#ifndef DIALOGHEDI_H
#define DIALOGHEDI_H

#include <QDialog>
#include "employe.h"
#include "departement.h"
#include "stat_employee.h"
#include "stat_depart.h"
#include "arduino.h"
namespace Ui {
class Dialoghedi;
}

class Dialoghedi : public QDialog
{
    Q_OBJECT

public:
    explicit Dialoghedi(QWidget *parent = nullptr);
    ~Dialoghedi();

private slots:
    void alert();

    void on_pushButton_2_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_9_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_21_clicked();

    void on_pushButton_24_clicked();

    void on_comboBox_4_currentIndexChanged(int index);

    void on_pushButton_8_clicked();

    void on_comboBox_3_currentIndexChanged(int index);

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_16_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_58_clicked();



    void on_combomodep_activated(const QString &arg1);

    void on_combomodep_currentIndexChanged(int index);

    void on_pushButton_28_clicked();

    void on_combosupdep_currentIndexChanged(int index);

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_8_textChanged(const QString &arg1);

    void on_label_10_linkActivated(const QString &link);

    void on_pushButton_clicked();

    void on_label_10_windowTitleChanged(const QString &title);

    void on_pushButton_25_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

    void on_stackedWidget_destroyed();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

private:
    Ui::Dialoghedi *ui;
    EMPLOYE emp;
     depart depp;
     stat_employee *stat_employe;
     stat_depart *stat_depar;
     arduino A;
      QByteArray data;
      bool check;
};

#endif // DIALOGHEDI_H
