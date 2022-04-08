#ifndef EDIT_PERSON_DIALOG_H
#define EDIT_PERSON_DIALOG_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QListView>
#include <QStringList>
#include <QStringListModel>
#include <QModelIndex>
#include <QMessageBox>

#include "person_model.h"
#include "person.h"

class Edit_person_dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Edit_person_dialog(Person_model *model,QWidget *parent = nullptr);
    virtual ~Edit_person_dialog();

private:
    Person_model *mp_person_model;
    Person mp_person;

    QVBoxLayout *mp_main_layout = nullptr;
    QHBoxLayout *mp_sublayout = nullptr;
    QHBoxLayout *mp_buttons_layout = nullptr;
    QFormLayout * mp_form_layout = nullptr;

    QLineEdit *mp_name_edit;
    QLineEdit *mp_surname_edit;
    QLineEdit *mp_day_edit;
    QLineEdit *mp_month_edit;
    QLineEdit *mp_year_edit;

    QListView *mp_list_view;

    QPushButton *mp_button_save;
    QPushButton *mp_button_exit;
    QPushButton *mp_button_delete;

    QLabel *mp_id_label;

    QStringList *mp_string_list;
    QStringListModel *mp_string_list_model;
    QModelIndex mp_model_index; // zjednoduší nám přístup k jednotlivým řádkům seznamu v modelu

private slots:

    void on_list_view_clicked(const QModelIndex &index);
    void on_delete_button_clicked();
    void on_exit_button_clicked();
    void on_save_button_clicked();

signals:

};

#endif // EDIT_PERSON_DIALOG_H
