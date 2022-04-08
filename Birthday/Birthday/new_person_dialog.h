#ifndef NEW_PERSON_DIALOG_H
#define NEW_PERSON_DIALOG_H

#include <QObject>
#include <QDialog>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QDateEdit>
#include <QPushButton>

#include "person_model.h"

class New_person_dialog : public QDialog
{
    Q_OBJECT
public:
    New_person_dialog(Person_model *model, QWidget *parent = nullptr);
    virtual ~New_person_dialog();

private:

    Person_model *mp_model;

QBoxLayout *mp_main_layout = nullptr;
QBoxLayout *mp_sub_layout = nullptr;
QBoxLayout *mp_calendar_layout = nullptr;
QBoxLayout *mp_button_layout = nullptr;

QFormLayout *mp_form_layout = nullptr;

QLineEdit *mp_name_edit;
QLineEdit *mp_surname_edit;
QLineEdit *mp_day_edit;
QLineEdit *mp_month_edit;
QLineEdit *mp_year_edit;

QCalendarWidget *mp_calendar_edit;
QDateEdit *mp_date_edit;

QPushButton *mp_button_ok;
QPushButton *mp_button_cancel;

signals:

private slots:

void on_calendar_selection_changed();
void on_date_edit_changed(const QDate &date);
void on_day_edit_changed(const QString &day);
void on_month_edit_changed(const QString &month);
void on_year_edit_changed(const QString &year);

void on_button_ok_clicked();
void on_button_cancel_clicked();
};

#endif // NEW_PERSON_DIALOG_H
