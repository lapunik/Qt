#ifndef BIRTHDAYMAINWINDOW_H
#define BIRTHDAYMAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QToolBar>
#include <QString>

class BirthdayMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    BirthdayMainWindow(QWidget *parent = nullptr);
    ~BirthdayMainWindow();

private:
    const QString TITLE_WND = tr("Narozeniny"); // název aplikace bude na více místech, proto si ho nadefinujeme jako konstantu, abychom ho mohli na všech místech případně rychle změnit

    QAction *mp_new_person_act; // QAction je užitečná třída, která umožní zpracování udýlostí menu nebo toolbaru
    QAction *mp_edit_person_act;
    QAction *mp_view_status_act;
    QAction *mp_view_tool_act;
    QAction *mp_exit_act;
    QAction *mp_about_help_act;
    QAction *mp_about_Qt_help_act;

    QToolBar *mp_tool_bar; // K toolbar budeme muset mít přístup po celou dobu aplikace, ne pouze z konstruktoru hlavního okna, proto na něj uděláme ukazatel tímto způsobem.

    void create_action(); // funkce kde si vytvoříme všechny akce

private slots:
    void not_implemented(); // dobrý je si vytvořit nějakou takovouhle funkci/slot, na kterou budeme signály přesměrovávat, pokud ještě nebudou deklarovány
    void toggle_statusbar(); // vyrolování a srolování stavového řádku/ nástrojového řádku
    void toggle_toolbar();
    void about_dialog(); // zobrazí informace o programu/qt
    void about_qt_dialog();
};
#endif // BIRTHDAYMAINWINDOW_H
