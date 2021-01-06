#ifndef MODELS_H
#define MODELS_H

#include <QSqlQueryModel>

class Models
{
public:
    QSqlQueryModel * matricule;
    QSqlQueryModel * modele;
    QSqlQueryModel * capacity;
    Models();
};

#endif // MODELS_H
