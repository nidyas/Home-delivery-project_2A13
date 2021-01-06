#ifndef STAT_DEPART_H
#define STAT_DEPART_H

#include <QDialog>

namespace Ui {
class stat_depart;
}

class stat_depart : public QDialog
{
    Q_OBJECT

public:
    explicit stat_depart(QWidget *parent = nullptr);
    ~stat_depart();

private:
    Ui::stat_depart *ui;
    QList<qreal> stat_depar();
    QList <QString> stat_depar_nom();
};

#endif // STAT_DEPART_H
