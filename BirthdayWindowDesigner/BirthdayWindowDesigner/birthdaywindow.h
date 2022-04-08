#ifndef BIRTHDAYWINDOW_H
#define BIRTHDAYWINDOW_H

#include <QMainWindow>
#include <QString>
#include "result_widget.h"
#include "new_person_dialog.h"
#include "edit_person_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BirthdayWindow; } // jmený prostor UI, které zajišťuje spolupráci s návrhem formuláře.
QT_END_NAMESPACE

class BirthdayWindow : public QMainWindow
{
    Q_OBJECT

public:
    BirthdayWindow(QWidget *parent = nullptr);
    ~BirthdayWindow();

private slots:
    void on_mp_action_pridat_osobu_triggered();

    void on_action_upravit_osobu_triggered();

    void on_action_exit_triggered();

    void on_action_panel_nastroju_triggered();

    void on_action_stavovy_radek_triggered();

    void on_action_o_Qt_triggered();

    void on_action_o_programu_triggered();

private:
    Ui::BirthdayWindow *ui;

    const QString WND_TITLE = "Narozeniny";

    Person_model *mp_model = nullptr;

    void not_implemented();

    Result_widget *mp_result_widget = nullptr;

    New_person_dialog *mp_new_person_dialog = nullptr;

    Edit_person_dialog *mp_edit_person_dialog = nullptr;

};
#endif // BIRTHDAYWINDOW_H
