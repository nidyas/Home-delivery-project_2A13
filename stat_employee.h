#ifndef STAT_EMPLOYEE_H
#define STAT_EMPLOYEE_H

#include <QDialog>

namespace Ui {
class stat_employee;
}

class stat_employee : public QDialog
{
    Q_OBJECT

public:
    explicit stat_employee(QWidget *parent = nullptr);
    ~stat_employee();
    QList<qreal> stat_employe();
    QList <QString> stat_employee_nom();

private:
    Ui::stat_employee *ui;

};

#endif // STAT_EMPLOYEE_H
