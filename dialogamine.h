#ifndef DIALOGAMINE_H
#define DIALOGAMINE_H
#include "contrat.h"
#include "societe.h"
#include <QMainWindow>
#include <QPrinter>
#include <QFileDialog>
#include <QFileInfo>
#include <QTimer>
#include <QDateTime>
#include "mail.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialogamine; }
QT_END_NAMESPACE

class Dialogamine:public QDialog
{
    Q_OBJECT

public:
    Dialogamine(QWidget *parent = nullptr);
    ~Dialogamine();

private slots:

    void on_contrat_clicked();

    void on_backtomenu_clicked();

    void on_afficher_c_clicked();

    void on_backtocontrat_clicked();

    void on_ok_clicked();

    void on_gerer_c_clicked();

    void on_backtocontrat_2_clicked();

    void on_ajouter_c_clicked();

    void on_cancel_clicked();

    void on_search_2_clicked();

    void on_modifier_c_clicked();

    void on_modifier_clicked();

    void on_cancel_2_clicked();

    void on_delete_2_clicked();

    void on_supprimer_c_clicked();

    void on_afficher_s_clicked();

    void on_societe_clicked();

    void on_search_3_clicked();

    void on_ok_2_clicked();

    void on_ajouter_s_clicked();

    void on_gerer_s_clicked();

    void on_modifier_2_clicked();

    void on_search_4_clicked();

    void on_backtosociete_clicked();

    void on_backtogerersociete_clicked();

    void on_modifier_s_clicked();

    void on_backtomenu_2_clicked();

    void on_supp_clicked();

    void on_backtogerersociete_4_clicked();

    void on_supprimer_s_clicked();

    void on_search_clicked();

    void on_reset_clicked();

    void on_backtogerersociete_3_clicked();

    void on_cancel_4_clicked();

    void on_backtogerersociete_2_clicked();

    void on_cancel_3_clicked();

    void on_backtogerercontrat_3_clicked();

    void on_backtogerercontrat_2_clicked();

    void on_backtogerercontrat_clicked();

    void on_supprimer_c_2_clicked();

    void on_backtocontrat_3_clicked();

    void on_backtocontrat_4_clicked();

    void on_pdf_clicked();

    void showTime();

private:
    Ui::Dialogamine *ui;
    Contrat c;
    Societe s;
};
#endif // MAINWINDOW_H
