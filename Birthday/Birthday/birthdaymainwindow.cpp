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

void BirthdayMainWindow::toggle_statusbar() // zapnutí nebo vypnutí stavového řádku. Malý řádek na spodku okna, který krátce komentuje, co které tlačítko dělá atd..
{
    if (mp_view_status_act->isChecked()) {
        statusBar()->show();
    }
    else {
        statusBar()->hide();
    }
}

void BirthdayMainWindow::toggle_toolbar() // zobrazení nebo skrytí nástrojového řádku. Řádek v horní části okna s jednoduchými ikonami pro rychlé ovládání aplikace. Nejedná se o Menu bar!!!
{
    if (mp_view_tool_act->isChecked()) {
        mp_tool_bar->show();
    }
    else {
        mp_tool_bar->hide();
    }
}

void BirthdayMainWindow::add_person_dialog()
{
    mp_new_person_dialog = new New_person_dialog(mp_model, this);
    mp_new_person_dialog->exec();

    mp_result_widget->redraw();

    if (mp_new_person_dialog != nullptr)
    {
        delete mp_new_person_dialog;
    }
}

void BirthdayMainWindow::edit_person_dialog()
{
    mp_edit_person_dialog = new Edit_person_dialog(mp_model, this);
    mp_edit_person_dialog->exec();
    mp_result_widget->redraw();

    if (mp_edit_person_dialog != nullptr)
    {
        delete mp_edit_person_dialog;
    }
}

BirthdayMainWindow::BirthdayMainWindow(QWidget *parent) : QMainWindow(parent) // konstruktor
{
    setWindowTitle(TITLE_WND); // Jako název použijeme naší vytvořenou konstantu
    setWindowIcon(QIcon(":/res/img/ico_main")); // zvolíme ikonu
    resize(640,480); // a změníme velikost okna

    create_action(); // volání funkce, která zařídí

    QMenu *person_menu = menuBar()->addMenu(tr("Lidé")); // Nová položka v menu baru s názvem Lidé (horní lišta)
    person_menu->addAction(mp_new_person_act); // přidání akce nové osoby do položky lidé do menu baru
    person_menu->addAction(mp_edit_person_act); // přidání akce editace osoby do položky lidé do menu baru
    person_menu->addSeparator(); // přidání oddělovače do položky lidé do menu baru
    person_menu->addAction(mp_exit_act); // přidání akce ukončení aplikace do položky lidé do menu baru

    QMenu *view_menu = menuBar()->addMenu(tr("Zobrazit")); // Nová položka v menubaru s názvem Zobrazit
    view_menu->addAction(mp_view_status_act); // přidání akce pro zapnutí či vypnutní stavového řádku do položky Zobrazit v menubaru
    view_menu->addAction(mp_view_tool_act); // přidání akce pro zapnutí či vypnutní nástrojového řádku do položky Zobrazit v menubaru

    QMenu *help_menu = menuBar()->addMenu(tr("Nápověda")); // Nová položka v menubaru s názvem Nápověda
    help_menu->addAction(mp_about_help_act);  // přidání akce O aplikaci do položky Nápověda v menubaru
    help_menu->addAction(mp_about_Qt_help_act); // přidání akce O Qt do položky Nápověda v menubaru

    // Toolbar je deklarovaný v hlavičkovém souboru protože k němu budeme muset přistupovat z více míst programu
    mp_tool_bar = addToolBar("mainToolBar"); // Vytvoření nového Toolbaru (to je prsotě lišta, kam si m´ůžeme přidávat položky podobně jako do menubaru a k nim klidně ikonky atd..)
    mp_tool_bar->addAction(mp_new_person_act); // přidání akce nová osoba do toolbaru
    mp_tool_bar->addAction(mp_edit_person_act); // přidání akce uprava osoby do toolbaru
    mp_tool_bar->addSeparator(); // přidání oddělovače d toolbaru
    mp_tool_bar->addAction(mp_about_help_act); // přidání akce O programu do toolbaru
    mp_tool_bar->addAction(mp_about_Qt_help_act);// přidání akce O Qt do toolbaru
    mp_tool_bar->addSeparator(); // přidání separátoru do toolbaru
    mp_tool_bar->addAction(mp_exit_act); // přidání akce pro ukoncčení aplikace

   statusBar()->showMessage("Ready"); // Status bar vypíše, že je vše připraveno

   mp_model = new Person_model(this);

   mp_result_widget = new Result_widget(mp_model,this);
   setCentralWidget(mp_result_widget);
}

BirthdayMainWindow::~BirthdayMainWindow() // klasika destruktor
{

    if(mp_new_person_act != nullptr)
    {
        delete mp_new_person_act; // QAction je užitečná třída, která umožní zpracování udýlostí menu nebo toolbaru
    }
    if(mp_edit_person_act != nullptr)
    {
        delete mp_edit_person_act;
    }
    if(mp_view_status_act != nullptr)
    {
        delete mp_view_status_act;
    }
    if(mp_view_tool_act != nullptr)
    {
        delete mp_view_tool_act;
    }
    if(mp_exit_act != nullptr)
    {
        delete mp_exit_act;
    }
    if(mp_about_help_act != nullptr)
    {
        delete mp_about_help_act;
    }
    if(mp_about_Qt_help_act != nullptr)
    {
        delete mp_about_Qt_help_act;
    }
    if (mp_result_widget != nullptr)
    {
        delete  mp_result_widget;
    }

}

void BirthdayMainWindow::create_action()
{
    mp_new_person_act = new QAction(QIcon(":res/img/ico_add_person"),tr("Nová osoba"),this); // tohle je vytvoření nové akce, kterou potom můžu přidat do menubaru nebo toolbaru
    mp_new_person_act->setStatusTip(tr("Přidá novou osobu do seznamu.")); // vypsání akce do stavového řádku
    connect(mp_new_person_act, SIGNAL(triggered()), this, SLOT(add_person_dialog())); // propojení akce (trrigered) s příslušným slotem (funkcí) pro obsluhu

    mp_edit_person_act = new QAction(QIcon(":res/img/ico_edit_person"),tr("Úprava osoby"),this);
    mp_edit_person_act->setStatusTip(tr("Dovolí upravovat existující osoby v seznamu."));
    connect(mp_edit_person_act, SIGNAL(triggered()), this, SLOT(edit_person_dialog()));

    mp_view_status_act = new QAction(("Stavový řádek"),this); // tady chybí ikona, protože tady budou místo ikon checkboxy
    mp_view_status_act->setCheckable(true); //tady ještě přidám zaškrtávátko a nastavím ho defalutně na zaškrtnuto.
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
    mp_about_help_act->setStatusTip(tr("Zobrazení informaci o tomto programu."));
    connect(mp_about_help_act, SIGNAL(triggered()),this, SLOT(about_dialog()));

    mp_about_Qt_help_act = new QAction(QIcon(":res/img/ico_qt"),tr("O Qt"),this);
    mp_about_Qt_help_act->setStatusTip(tr("Zobrazení informaci o Qt."));
    connect(mp_about_Qt_help_act, SIGNAL(triggered()),this, SLOT(about_qt_dialog()));

}
