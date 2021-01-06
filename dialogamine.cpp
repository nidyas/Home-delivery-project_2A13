#include "dialogamine.h"
#include "ui_dialogamine.h"


Dialogamine::Dialogamine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogamine)
{
    ui->setupUi(this);

    ui->tableView->setModel(c.afficher_contrat("XYZ","XYZ"));
        ui->tableView_2->setModel(s.afficher_soc("XYZ","XYZ","XYZ"));
        QTimer *timer_p=new QTimer(this);
              connect(timer_p,SIGNAL(timeout()),this,SLOT(showTime()));
              timer_p->start();
              //DAate systeme
              QDateTime Date_p=QDateTime::currentDateTime();
              QString Date_txt=Date_p.toString("dddd dd MMMM yyyy");
              ui->Date->setText(Date_txt);
}

Dialogamine::~Dialogamine()
{
    delete ui;

}

void Dialogamine::showTime()
{
    QTime time=QTime::currentTime();
    QString time_txt=time.toString("hh:mm:ss");
    ui->Timer->setText(time_txt);
}

void Dialogamine::on_contrat_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
}

void Dialogamine::on_backtomenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialogamine::on_afficher_c_clicked()
{
    ui->tableView->setModel(c.afficher_contrat("XYZ","XYZ"));
    ui->stackedWidget->setCurrentIndex(2);
}

void Dialogamine::on_backtocontrat_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialogamine::on_ok_clicked()
{
    QString ben = ui->benificier_t_2->text();
    QString type = ui->type_t_2->text();


        Contrat c(ben,type);
        bool test = c.ajouter_contrat();
        if (test)
        {

            ui->benificier_t_2->clear();
            ui->type_t_2->clear();

            ui->tableView->setModel(c.afficher_contrat("XYZ","XYZ"));

            QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("contrat Successfully Added!\n"), QMessageBox::Ok);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Failed"), QObject::tr("Failed to add contrat\n"
                                                                              "Click cancel."),
                                  QMessageBox::Cancel);
        }
}

void Dialogamine::on_gerer_c_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Dialogamine::on_backtocontrat_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialogamine::on_ajouter_c_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialogamine::on_cancel_clicked()
{
    ui->benificier_t_2->clear();
    ui->type_t_2->clear();

     ui->stackedWidget->setCurrentIndex(3);
}

void Dialogamine::on_search_2_clicked()
{
    QString ben= ui->benificier_2->text();

    ui->benificier_3->setText(c.affecter_ben(ben));
    ui->typet->setText(c.affecter_type(ben));
}

void Dialogamine::on_modifier_c_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void Dialogamine::on_modifier_clicked()
{
    QString ben = ui->benificier_3->text();
    QString type = ui->typet->text();

    bool test = c.modifier_contrat(ben,type);
    if (test)
    {
        ui->benificier_3->clear();
        ui->typet->clear();

        ui->tableView->setModel(c.afficher_contrat("XYZ","XYZ"));

        QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("contrat Successfully Modified!\n"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Failed"), QObject::tr("Failed to Modify contrat\n"
                                                                          "Click cancel."),
                              QMessageBox::Cancel);
    }
}

void Dialogamine::on_cancel_2_clicked()
{
    ui->benificier_3->clear();
    ui->typet->clear();

     ui->stackedWidget->setCurrentIndex(3);
}

void Dialogamine::on_delete_2_clicked()
{
    QString ben = ui->benificierd->text();
    bool test = c.supprimer_contrat(ben);
    if (test)
    {
        QString nom_mus;
        ui->tableView->setModel(c.afficher_contrat("XYZ","XYZ"));

        QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("contrat Successfully Deleted!\n"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Failed"), QObject::tr("Failed to delete contrat\n"
                                                                          "Click cancel."),
                              QMessageBox::Cancel);
    }
}

void Dialogamine::on_supprimer_c_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void Dialogamine::on_afficher_s_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void Dialogamine::on_societe_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void Dialogamine::on_search_3_clicked()
{
    QString nom = ui->nom_s->text().trimmed();
    QString add= ui->adresse_s->text().trimmed();
    QString ser= ui->service_s->text().trimmed();
    if (nom!="" && add=="" && ser=="")
    {
      ui->tableView_2->setModel(s.afficher_soc(nom,"XYZ","XYZ"));
    }
    if (nom=="" && add!="" && ser=="")
    {
      ui->tableView_2->setModel(s.afficher_soc("XYZ",add,"XYZ"));
    }
    if(nom=="" && add=="" && ser!="")
    {
        ui->tableView_2->setModel(s.afficher_soc("XYZ","XYZ",ser));
    }
    if(nom=="" && add=="" && ser=="")
    {
         ui->tableView_2->setModel(s.afficher_soc("XYZ","XYZ","XYZ"));
    }
}

void Dialogamine::on_ok_2_clicked()
{
    QString nom=ui->nom_s_2->text();
    QString add=ui->adresse_s_2->text();
    QString ser=ui->service_s_2->text();

    Societe s ( nom,add,ser );



 bool test=s.ajouter_soc();
 if (test)
 {

     ui->nom_s_2->clear();
     ui->adresse_s_2->clear();
     ui->service_s_2->clear();

     ui->tableView_2->setModel(s.afficher_soc("XYZ","XYZ","XYZ"));

     QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("Socite Successfully Added!\n"), QMessageBox::Ok);
 }
 else
 {
     QMessageBox::critical(nullptr, QObject::tr("Failed"), QObject::tr("Failed to add societe\n"
                                                                       "Click cancel."),
                           QMessageBox::Cancel);
 }
}

void Dialogamine::on_ajouter_s_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void Dialogamine::on_gerer_s_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void Dialogamine::on_modifier_2_clicked()
{
    QString nom = ui->nom_s_3->text();
    QString add = ui->adresse_s_3->text();
    QString ser = ui->service_s_3->text();

    bool test = s.modifier_soc(nom,add,ser);
    if (test)
    {
        ui->nom_s_3->clear();
        ui->adresse_s_3->clear();
        ui->service_s_3->clear();

        ui->tableView_2->setModel(s.afficher_soc("XYZ","XYZ","XYZ"));

        QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("societe Successfully Modified!\n"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Failed"), QObject::tr("Failed to Modify societe\n"
                                                                          "Click cancel."),
                              QMessageBox::Cancel);
    }
}

void Dialogamine::on_search_4_clicked()
{
    QString nom = ui->nomd->text().trimmed();

    ui->nom_s_3->setText(s.affecter_nom(nom));
    ui->adresse_s_3->setText(s.affecter_add(nom));
    ui->service_s_3->setText(s.affecter_ser(nom));

}

void Dialogamine::on_backtosociete_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void Dialogamine::on_backtogerersociete_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void Dialogamine::on_modifier_s_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialogamine::on_backtomenu_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void Dialogamine::on_supp_clicked()
{
    QString nom= ui->nom_d->text();
     bool test =s.supprimer_soc(nom);
     if (test)
     {
         QString nom_mus;
         ui->tableView_2->setModel(s.afficher_soc("XYZ","XYZ","XYZ"));

         QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("societe Successfully Deleted!\n"), QMessageBox::Ok);
     }
     else
     {
         QMessageBox::critical(nullptr, QObject::tr("Failed"), QObject::tr("Failed to delete societe\n"
                                                                           "Click cancel."),
                               QMessageBox::Cancel);
     }
}

void Dialogamine::on_backtogerersociete_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void Dialogamine::on_supprimer_s_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void Dialogamine::on_search_clicked()
{
    QString ben =ui->benificier_t->text().trimmed();
    QString type =ui->type_t->text().trimmed();

    if (ben=="" && type!="")
    {
      ui->tableView->setModel(c.afficher_contrat("XYZ",type));
    }
    if (ben !="" && type=="")
    {
      ui->tableView->setModel(c.afficher_contrat(ben,"XYZ"));
    }
    if(ben!="" && type!="")
    {
        ui->tableView->setModel(c.afficher_contrat(ben,type));
    }
}

void Dialogamine::on_reset_clicked()
{
    ui->benificier_t->clear();
    ui->type_t->clear();
    ui->tableView->setModel(c.afficher_contrat("XYZ","XYZ"));
}

void Dialogamine::on_backtogerersociete_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void Dialogamine::on_cancel_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void Dialogamine::on_backtogerersociete_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(10);
}

void Dialogamine::on_cancel_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void Dialogamine::on_backtogerercontrat_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Dialogamine::on_backtogerercontrat_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Dialogamine::on_backtogerercontrat_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Dialogamine::on_supprimer_c_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void Dialogamine::on_backtocontrat_3_clicked()
{
    mail* smtp = new mail("projet.esprit11@gmail.com", "esprit2020", "smtp.gmail.com", 465);

            smtp->sendMail("projet.esprit11@gmail.com", ui->ecrire_mail->text() , ui->ecrire_objet->text() ,ui->ecrire_txt->toPlainText());
}

void Dialogamine::on_backtocontrat_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Dialogamine::on_pdf_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Open PDF", QString(), "*.pdf");
                        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("SOCIETE.pdf"); }

                        QPrinter printer(QPrinter::PrinterResolution);
                        printer.setOutputFormat(QPrinter::PdfFormat);
                        printer.setPaperSize(QPrinter::A4);
                        printer.setOutputFileName(fileName);

                        QTextDocument doc;
                        QSqlQuery q;
                        q.prepare("SELECT * from SOCIETE");
                        q.exec();
                QString pdf="<br>  <body style='background-color:LightYellow'> <h1  style='color:DarkKhaki'> listes des societes:  <br></h1>\n <br>  <table>  <tr><th>NOM </th>           <th> ADRESSE </th>       <th> SERVICE</th>   </tr>" ;


                        while ( q.next()) {

                       pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>  <td>   " + q.value(1).toString()+" </td>     <td>    "  +q.value(2).toString() +"   </td>     </td>" ;

                        }
                        doc.setHtml(pdf);
                        doc.setPageSize(printer.pageRect().size());
                        doc.print(&printer);
}
