#ifndef DIALOGYASSINE_H
#define DIALOGYASSINE_H

#include <QDialog>
#include "vehicule.h"
#include"agence.h"
#include"statayadi.h"
namespace Ui {
class Dialogyassine;
}

class Dialogyassine : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogyassine(QWidget *parent = nullptr);
    ~Dialogyassine();

private slots:
    void on_pushButton_17_clicked();

    void on_pushButton_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_13_clicked();

    void on_pushButton_16_clicked();

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_lineEdit_7_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_29_clicked();

    void on_comboBox_3_currentIndexChanged(int index);

    void on_pushButton_31_clicked();

    void on_comboBox_4_currentIndexChanged(const QString &arg1);

    void on_pushButton_23_clicked();

    void on_lineEdit_8_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_32_clicked();

private:
    Ui::Dialogyassine *ui;
    Vehicule tabvh;
    Agence tabag;
    statayadi *stat;

};

#endif // DIALOGYASSINE_H
