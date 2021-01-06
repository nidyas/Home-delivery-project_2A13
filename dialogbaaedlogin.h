#ifndef DIALOGBAAEDLOGIN_H
#define DIALOGBAAEDLOGIN_H

#include <QDialog>

namespace Ui {
class Dialogbaaedlogin;
}

class Dialogbaaedlogin : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogbaaedlogin(QWidget *parent = nullptr);
    ~Dialogbaaedlogin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialogbaaedlogin *ui;
};

#endif // DIALOGBAAEDLOGIN_H
