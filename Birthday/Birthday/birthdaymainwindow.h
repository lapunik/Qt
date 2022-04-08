#ifndef BIRTHDAYMAINWINDOW_H
#define BIRTHDAYMAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QToolBar>
#include <QString>
#include "result_widget.h"
#include "new_person_dialog.h"
#include "edit_person_dialog.h"

class BirthdayMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    BirthdayMainWindow(QWidget *parent = nullptr);
    ~BirthdayMainWindow();

private:
    const QString TITLE_WND = tr("Narozeniny"); // název aplikace bude na více místech, proto si ho nadefinujeme jako konstantu, abychom ho mohli na všech místech případně rychle změnit

    QAction *mp_new_person_act; // QAction je užitečná třída, která umožní zpracování událostí menu nebo toolbaru
    QAction *mp_edit_person_act; // více méně akce, je položka v menu, nebo v tool baru na kterou kliknu a ona je pro connectěná s fukcí (slotem)  která se má zavolat
    QAction *mp_view_status_act;
    QAction *mp_view_tool_act;
    QAction *mp_exit_act;
    QAction *mp_about_help_act;
    QAction *mp_about_Qt_help_act;

    QToolBar *mp_tool_bar; // K toolbar budeme muset mít přístup po celou dobu aplikace, ne pouze z konstruktoru hlavního okna, proto na něj uděláme ukazatel tímto způsobem. (Toolbar není Menubar, Menubar je horní lisšta kde si vyberu co chci dělat. Toolbar je prostě nějaká část pro lepší ovládání aplikace)

    void create_action(); // funkce kde si vytvoříme všechny akce abychom je pak mohli přiřadit do tool baru a do menubaru

    Person_model *mp_model;

    Result_widget *mp_result_widget = nullptr;

    New_person_dialog *mp_new_person_dialog = nullptr;

    Edit_person_dialog *mp_edit_person_dialog = nullptr;

private slots:
    void toggle_statusbar(); // zapnutí nebo vypnutí stavového řádku. Malý řádek na spodku okna, který krátce komentuje, co které tlačítko dělá atd..
    void toggle_toolbar(); // zobrazení nebo skrytí nástrojového řádku. Řádek v horní části okna s jednoduchými ikonami pro rychlé ovládání aplikace. Nejedná se o Menu bar!!!
    void about_dialog(); // zobrazí informace o programu (ať už ho spouštím z panelu nástrojů, nebo z menubaru)
    void about_qt_dialog(); // zobrazí informace o qt (ať už ho spouštím z panelu nástrojů, nebo z menubaru)

    void not_implemented(); // dobrý je si vytvořit nějakou takovouhle funkci/slot, na kterou budeme signály přesměrovávat, pokud ještě nebudou deklarovány

    void add_person_dialog();
    void edit_person_dialog();
};
#endif // BIRTHDAYMAINWINDOW_H
