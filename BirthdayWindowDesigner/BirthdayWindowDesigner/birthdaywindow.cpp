#include "birthdaywindow.h"
#include "ui_birthdaywindow.h"
#include "QMessageBox"

BirthdayWindow::BirthdayWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::BirthdayWindow)
{
    ui->setupUi(this);

    ui->action_panel_nastroju->setChecked(true);
    ui->action_panel_nastroju->setChecked(true);

    mp_model = new Person_model(this);

    mp_result_widget = new Result_widget(mp_model, this);

    setCentralWidget(mp_result_widget);


}

BirthdayWindow::~BirthdayWindow()
{
    delete mp_result_widget;
    delete ui;
}

void BirthdayWindow::not_implemented()
{
    QMessageBox mess;
    mess.information(this, WND_TITLE,"Tato funkce ješt není implementována.");
}

void BirthdayWindow::on_mp_action_pridat_osobu_triggered()
{
    mp_new_person_dialog = new New_person_dialog(mp_model, this);
    mp_new_person_dialog->exec();
    mp_result_widget->redraw();

    if (mp_new_person_dialog != nullptr)
    {
        delete mp_new_person_dialog;
    }
}


void BirthdayWindow::on_action_upravit_osobu_triggered()
{
    mp_edit_person_dialog = new Edit_person_dialog(mp_model, this);
    mp_edit_person_dialog->exec();
    mp_result_widget->redraw();

    if (mp_edit_person_dialog != nullptr)
    {
        delete mp_edit_person_dialog;
    }
}


void BirthdayWindow::on_action_exit_triggered()
{
    qApp->quit();
}


void BirthdayWindow::on_action_panel_nastroju_triggered()
{
    if (ui->action_panel_nastroju->isChecked()) {
        ui->tool_bar->show();
    }
    else {
        ui->tool_bar->hide();
    }
}


void BirthdayWindow::on_action_stavovy_radek_triggered()
{
    if (ui->action_stavovy_radek->isChecked()) {
        ui->statusbar->show();
    }
    else {
        ui->statusbar->hide();
    }
}


void BirthdayWindow::on_action_o_Qt_triggered()
{
    QMessageBox mess;
    mess.aboutQt(this,WND_TITLE);
}


void BirthdayWindow::on_action_o_programu_triggered()
{
    QMessageBox mess;
    mess.about(this,WND_TITLE,"Ahoj,\numím vám připomenout narozeniny vašich blízkých.");

}


