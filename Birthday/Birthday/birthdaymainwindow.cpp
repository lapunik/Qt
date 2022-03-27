#include "birthdaymainwindow.h"

#include <QIcon> // knihovna pro zobrazení ikony
#include <QMenu> // knihovna pro položky v menu
#include <QMenuBar> // knihovna pro práci v menu
#include <QStatusBar> // knihovna pro stavový řádek a jeho obsluhy
#include <QMessageBox> // už známe, klasické dialogy
#include <QApplication> // knihovna pro získání ukazatele na program přes makro qApp (např pro slot quit atd..)
#include <QDebug> // knihovna pro lepší ladění, např. výpis nějakého info

BirthdayMainWindow::BirthdayMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle(TITLE_WND); // použijeme našá konstantu
    setWindowIcon(QIcon(":/res/img/ico_main"));
    resize(640,480);

    create_action();

    QMenu *person_menu = menuBar()->addMenu(tr("Lidé"));
    person_menu->addAction(mp_new_person_act);
    person_menu->addAction(mp_edit_person_act);
    person_menu->addSeparator();
    person_menu->addAction(mp_exit_act);


    QMenu *view_menu = menuBar()->addMenu(tr("Lidé"));
}

BirthdayMainWindow::~BirthdayMainWindow()
{
}

void BirthdayMainWindow::create_action()
{
    mp_new_person_act = new QAction(QIcon(":res/img/ico_add_person"),tr("Nová osoba"),this);
    mp_new_person_act->setStatusTip(tr("Přidá novou osobu do seznamu."));
    connect(mp_new_person_act, SIGNAL(triggered()), this, SLOT(not_implemented()));

    mp_edit_person_act = new QAction(QIcon(":res/img/ico_edit_person"),tr("Úprava osoby"),this);
    mp_edit_person_act->setStatusTip(tr("Dovolí upravovat existující osoby v seznamu."));
    connect(mp_edit_person_act, SIGNAL(triggered()), this, SLOT(not_implemented()));

    mp_view_status_act = new QAction(("Stavový řádek"),this);
    mp_view_status_act->setCheckable(true);
    mp_view_status_act->setChecked(true);
    mp_view_status_act->setStatusTip(tr("Zobrazí nebo skryje stavový řádek."));
    connect(mp_view_status_act, SIGNAL(triggered()), this, SLOT(toggle_statusbar()));

    mp_view_tool_act = new QAction(("Panel nástrojů"),this);
    mp_view_tool_act->setCheckable(true);
    mp_view_tool_act->setChecked(true);
    mp_view_tool_act->setStatusTip(tr("Zobrazí nebo skryje panel nástrojů."));
    connect(mp_view_tool_act, SIGNAL(triggered()), this, SLOT(toggle_toolbar()));

    mp_exit_act = new QAction(QIcon(":res/img/ico_exit"),tr("Konec"),this);
    mp_exit_act->setStatusTip(tr("Uložení dat a ukončení programu."));
    connect(mp_exit_act, SIGNAL(triggered()), qApp, SLOT(quit()));

    mp_about_help_act = new QAction(QIcon(":res/img/ico_about"),tr("O programu"),this);
    mp_about_help_act->setStatusTip(tr("Yobrayen9 informaci o tomto programu."));
    connect(mp_about_help_act, SIGNAL(triggered()),this, SLOT(about_dialog()));

    mp_about_Qt_help_act = new QAction(QIcon(":res/img/ico_qt"),tr("O Qt"),this);
    mp_about_Qt_help_act->setStatusTip(tr("Yobrayen9 informaci o Qt."));
    connect(mp_about_Qt_help_act, SIGNAL(triggered()),this, SLOT(about_at_dialog()));

}
