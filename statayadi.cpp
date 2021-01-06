#include "statayadi.h"
#include "ui_statayadi.h"
#include <QSqlQuery>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
statayadi::statayadi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statayadi)
{
    ui->setupUi(this);
    this->setWindowTitle("Statsitique");
    QPieSeries *series =new QPieSeries ;

    QList<qreal> list= stat_budget();
     QList<QString> list2=stat_bud();

     for(int i=0 ;i<list.size();i++)
     {
          series->append(list2[i],list[i]);

     }
        QChart *chart =new QChart;
        chart->addSeries(series);
        chart->setTitle("STATS des Invitées");
         QChartView *chartview= new QChartView(chart);
         chartview->setParent(ui->horizontalFrame);
}

statayadi::~statayadi()
{
    delete ui;
}
QList<qreal> statayadi::stat_budget()
{
    QList<qreal> list ;
    QSqlQuery query;
    query.prepare("select budget, count( budget) from agence group by budget ;");
    query.exec();
    while(query.next())
    {list.append(query.value(1).toInt());}

    return list;
}

QList<QString> statayadi::stat_bud()
{
    QList<QString> list ;
    QSqlQuery query;
    query.prepare("select budget, count( budget) from agence group by budget ;");
    query.exec();
    while(query.next())
    {list.append(query.value(0).toString());}

    return list;
}
