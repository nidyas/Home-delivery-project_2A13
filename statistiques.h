#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QMainWindow>

namespace Ui {
class statistiques;
}

class statistiques : public QMainWindow
{
    Q_OBJECT

public:
    explicit statistiques(QWidget *parent = nullptr);
    ~statistiques();

private:
    Ui::statistiques *ui;
};

#endif // STATISTIQUES_H
