#include "stat_depart.h"
#include "ui_stat_depart.h"
#include <QSqlQuery>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

stat_depart::stat_depart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_depart)
{
    ui->setupUi(this);
    QPieSeries *series =new QPieSeries ;

    QList<qreal> list= stat_depar();
     QList<QString> list2=stat_depar_nom();

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

stat_depart::~stat_depart()
{
    delete ui;
}

QList<qreal> stat_depart::stat_depar()
{
    QList<qreal> list ;
    QSqlQuery query;
    query.prepare("select nom_dep,count(nbr_emp) from depart group by nom_dep;");
    query.exec();
    while(query.next())
    {list.append(query.value(1).toInt());}

    return list;
}

QList<QString> stat_depart::stat_depar_nom()
{QList<QString> list ;
    QSqlQuery query;
    query.prepare("select nom_dep,count(nbr_emp) from depart group by nom_dep;");
    query.exec();
    while(query.next())
    {list.append(query.value(0).toString());}

  return list;

}
