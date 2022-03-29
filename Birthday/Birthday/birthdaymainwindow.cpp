#include "birthdaymainwindow.h"

#include <QIcon> // knihovna pro zobrazení ikony
#include <QMenu> // knihovna pro položky v menu
#include <QMenuBar> // knihovna pro práci v menu
#include <QStatusBar> // knihovna pro stavový řádek a jeho obsluhy
#include <QMessageBox> // už známe, klasické dialogy
#include <QApplication> // knihovna pro získání ukazatele na program přes makro qApp (např pro slot quit atd..)
#include <QDebug> // knihovna pro lepší ladění, např. výpis nějakého info

void BirthdayMainWindow::not_implemented() // pomocná funkce/slot, která je přiřazena tam, kde skutečná implementace zatím chybí
{
    QMessageBox message;
    message.setWindowTitle(TITLE_WND);
    message.setText("Funkce zatím není implementována");
    message.setIcon(QMessageBox::Warning);
    message.exec();
}

void BirthdayMainWindow::about_dialog() // funkce/slot pro otevření dialogu s informacemi o aplikaci
{
    QMessageBox message;
    message.about(this, TITLE_WND, tr("Vítej,\ntato aplikace ti pomůže připomenou ti narozenny tvých nejbližších.\n"));
}

void BirthdayMainWindow::about_qt_dialog() // funkce/slot pro otevření dialogu s informacemi o danné verzi Qt
{
    QMessageBox message;
    message.aboutQt(this, TITLE_WND);
}

void BirthdayMainWindow::toggle_statusbar()
{
    if (mp_view_status_act->isChecked()) {
        statusBar()->show();
    }
    else {
        statusBar()->hide();
    }
}

void BirthdayMainWindow::toggle_toolbar()
{
    if (mp_view_tool_act->isChecked()) {
        mp_tool_bar->show();
    }
    else {
        mp_tool_bar->hide();
    }
}

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


    QMenu *view_menu = menuBar()->addMenu(tr("Zobrazit"));
    view_menu->addAction(mp_view_status_act);
    view_menu->addAction(mp_view_tool_act);

    QMenu *help_menu = menuBar()->addMenu(tr("Nápověda"));
    help_menu->addAction(mp_about_help_act);
    help_menu->addAction(mp_about_Qt_help_act);

    // Toolbar je deklarovaný v hlavičkovém souboru protože k němu budeme muset přistupovat z více míst programu
    mp_tool_bar = addToolBar("mainToolBar");
    mp_tool_bar->addAction(mp_new_person_act);
    mp_tool_bar->addAction(mp_edit_person_act);
    mp_tool_bar->addSeparator();
    mp_tool_bar->addAction(mp_about_help_act);
    mp_tool_bar->addAction(mp_about_Qt_help_act);
    mp_tool_bar->addSeparator();
    mp_tool_bar->addAction(mp_exit_act);

   statusBar()->showMessage("Ready");

}

BirthdayMainWindow::~BirthdayMainWindow()
{

    if(mp_new_person_act != nullptr)
        delete mp_new_person_act; // QAction je užitečná třída, která umožní zpracování udýlostí menu nebo toolbaru

    if(mp_edit_person_act != nullptr)
        delete mp_edit_person_act;

    if(mp_view_status_act != nullptr)
        delete mp_view_status_act;

    if(mp_view_tool_act != nullptr)
        delete mp_view_tool_act;

    if(mp_exit_act != nullptr)
        delete mp_exit_act;

    if(mp_about_help_act != nullptr)
        delete mp_about_help_act;

    if(mp_about_Qt_help_act != nullptr)
        delete mp_about_Qt_help_act;

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
    mp_about_Qt_help_act->setStatusTip(tr("Zobrazení informaci o Qt."));
    connect(mp_about_Qt_help_act, SIGNAL(triggered()),this, SLOT(about_qt_dialog()));

}
