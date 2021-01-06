#include "stat_employee.h"
#include "ui_stat_employee.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QSqlQuery>

stat_employee::stat_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_employee)
{
    ui->setupUi(this);
    QPieSeries *series =new QPieSeries ;

    QList<qreal> list= stat_employe();
     QList<QString> list2=stat_employee_nom();

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

stat_employee::~stat_employee()
{
    delete ui;
}

QList<qreal> stat_employee::stat_employe()
{
    QList<qreal> list ;
    QSqlQuery query;
    query.prepare("select salaire,count(salaire) from ajid group by salaire");
    query.exec();
    while(query.next())
    {list.append(query.value(1).toInt());}

    return list;
}

QList<QString> stat_employee::stat_employee_nom()
{QList<QString> list ;
    QSqlQuery query;
    query.prepare("select salaire,count(salaire) from ajid group by salaire");
    query.exec();
    while(query.next())
    {list.append(query.value(0).toString());}

  return list;

}
