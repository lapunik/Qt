#include "new_person_dialog.h"
#include "ui_new_person_dialog.h"
#include <QMessageBox>

New_person_dialog::New_person_dialog(Person_model *model, QWidget *parent) : QDialog(parent),ui(new Ui::New_person_dialog)
{
        mp_model = model;
        ui->setupUi(this);

        QDate currentDate = ui->calendarWidget->selectedDate();
        ui->dateEdit->setDate(currentDate);
        ui->edit_day->setText(QString::number(currentDate.day()));
        ui->edit_month->setText(QString::number(currentDate.month()));
        ui->edit_year->setText(QString::number(currentDate.year()));
}

New_person_dialog::~New_person_dialog()
{
    delete ui;

    if (mp_model != nullptr)
    {
        delete mp_model;
    }
}

void New_person_dialog::on_calendarWidget_selectionChanged()
{
    QDate date = ui->calendarWidget->selectedDate();

    ui->dateEdit->setDate(date);

    ui->edit_day->setText(QString::number(date.day()));
    ui->edit_month->setText(QString::number(date.month()));
    ui->edit_year->setText(QString::number(date.year()));
}


void New_person_dialog::on_dateEdit_dateChanged(const QDate &date)
{
    ui->calendarWidget->setSelectedDate(date);
}


void New_person_dialog::on_edit_day_textChanged(const QString &day)
{
    QDate date = ui->dateEdit->date();
    date = QDate(date.year(), date.month(), day.toInt());
    ui->dateEdit->setDate(date);
}


void New_person_dialog::on_edit_month_textChanged(const QString &month)
{
    QDate date = ui->dateEdit->date();
    date = QDate(date.year(), month.toInt(), date.day());
    ui->dateEdit->setDate(date);
}


void New_person_dialog::on_edit_year_textChanged(const QString &year)
{
    QDate date = ui->dateEdit->date();
    date = QDate(year.toInt(), date.month(), date.day());
    ui->dateEdit->setDate(date);
}


void New_person_dialog::on_button_close_clicked()
{
    close();
}


void New_person_dialog::on_button_OK_clicked()
{
    QMessageBox msg;

    if (ui->edit_name->text().isEmpty())
    {
        msg.warning(this, tr("Chyba"), tr("Jméno nelze nechat nevyplněné."));
        return;
    }

    if (ui->edit_surname->text().isEmpty())
    {
       msg.warning(this, tr("Chyba"), tr("Příjmení nelze nechat nevyplněné."));
       return;
    }

    bool isOk = true;
    int day = ui->edit_day->text().toInt(&isOk);
    int month = ui->edit_month->text().toInt(&isOk);
    int year = ui->edit_year->text().toInt(&isOk);

    if (!isOk)
    {
        msg.warning(this, tr("Chyba"), tr("Neplatné znaky v editačním okně datumu."));
        return;
    }

    QDate date = QDate(year, month, day);

    if (!date.isValid() || !isOk)
    {
        msg.warning(this, tr("Chyba"), tr("Datum je zadané chybně."));
        return;
    }

    Person person;
    person.set_name(ui->edit_name->text());
    person.set_surname(ui->edit_surname->text());
    person.set_birthday(date);

    // Osobu uložíme
    mp_model->add_person(person);

    close();

    msg.information(this, tr("Hotovo"), tr("Osoba byla úspěšně přidána do seznamu."));
}
