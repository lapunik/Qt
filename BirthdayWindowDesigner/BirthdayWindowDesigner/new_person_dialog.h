#ifndef NEW_PERSON_DIALOG_H
#define NEW_PERSON_DIALOG_H

#include <QDialog>
#include "person_model.h"

namespace Ui {
class New_person_dialog;
}

class New_person_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit New_person_dialog(Person_model *model, QWidget *parent = nullptr);
    ~New_person_dialog();

private slots:
    void on_calendarWidget_selectionChanged();

    void on_dateEdit_dateChanged(const QDate &date);

    void on_button_close_clicked();

    void on_button_OK_clicked();

    void on_edit_day_textChanged(const QString &arg1);

    void on_edit_month_textChanged(const QString &arg1);

    void on_edit_year_textChanged(const QString &arg1);

private:
    Ui::New_person_dialog *ui;
    Person_model *mp_model;
};

#endif // NEW_PERSON_DIALOG_H
