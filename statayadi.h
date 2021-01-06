#ifndef STATAYADI_H
#define STATAYADI_H

#include <QDialog>

namespace Ui {
class statayadi;
}

class statayadi : public QDialog
{
    Q_OBJECT

public:
    explicit statayadi(QWidget *parent = nullptr);
    ~statayadi();

private:
    Ui::statayadi *ui;
    QList<qreal> stat_budget();
     QList <QString> stat_bud();
};

#endif // STATAYADI_H
