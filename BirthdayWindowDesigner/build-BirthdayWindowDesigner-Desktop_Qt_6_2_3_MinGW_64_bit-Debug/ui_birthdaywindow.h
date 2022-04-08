/********************************************************************************
** Form generated from reading UI file 'birthdaywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIRTHDAYWINDOW_H
#define UI_BIRTHDAYWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BirthdayWindow
{
public:
    QAction *mp_action_pridat_osobu;
    QAction *action_upravit_osobu;
    QAction *action_panel_nastroju;
    QAction *action_stavovy_radek;
    QAction *action_o_programu;
    QAction *action_o_Qt;
    QAction *action_exit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuOsoby;
    QMenu *menuZobrazit;
    QMenu *menuN_pov_da;
    QStatusBar *statusbar;
    QToolBar *tool_bar;

    void setupUi(QMainWindow *BirthdayWindow)
    {
        if (BirthdayWindow->objectName().isEmpty())
            BirthdayWindow->setObjectName(QString::fromUtf8("BirthdayWindow"));
        BirthdayWindow->resize(622, 407);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/img/res/img/mainIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        BirthdayWindow->setWindowIcon(icon);
        mp_action_pridat_osobu = new QAction(BirthdayWindow);
        mp_action_pridat_osobu->setObjectName(QString::fromUtf8("mp_action_pridat_osobu"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/img/res/img/addPerson.png"), QSize(), QIcon::Normal, QIcon::Off);
        mp_action_pridat_osobu->setIcon(icon1);
        action_upravit_osobu = new QAction(BirthdayWindow);
        action_upravit_osobu->setObjectName(QString::fromUtf8("action_upravit_osobu"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/img/res/img/editPerson.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_upravit_osobu->setIcon(icon2);
        action_panel_nastroju = new QAction(BirthdayWindow);
        action_panel_nastroju->setObjectName(QString::fromUtf8("action_panel_nastroju"));
        action_panel_nastroju->setCheckable(true);
        action_panel_nastroju->setChecked(true);
        action_stavovy_radek = new QAction(BirthdayWindow);
        action_stavovy_radek->setObjectName(QString::fromUtf8("action_stavovy_radek"));
        action_stavovy_radek->setCheckable(true);
        action_stavovy_radek->setChecked(true);
        action_o_programu = new QAction(BirthdayWindow);
        action_o_programu->setObjectName(QString::fromUtf8("action_o_programu"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/img/res/img/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_o_programu->setIcon(icon3);
        action_o_Qt = new QAction(BirthdayWindow);
        action_o_Qt->setObjectName(QString::fromUtf8("action_o_Qt"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/img/res/img/qt.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_o_Qt->setIcon(icon4);
        action_exit = new QAction(BirthdayWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/img/res/img/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon5);
        centralwidget = new QWidget(BirthdayWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        BirthdayWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BirthdayWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 622, 21));
        menuOsoby = new QMenu(menubar);
        menuOsoby->setObjectName(QString::fromUtf8("menuOsoby"));
        menuZobrazit = new QMenu(menubar);
        menuZobrazit->setObjectName(QString::fromUtf8("menuZobrazit"));
        menuN_pov_da = new QMenu(menubar);
        menuN_pov_da->setObjectName(QString::fromUtf8("menuN_pov_da"));
        BirthdayWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(BirthdayWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BirthdayWindow->setStatusBar(statusbar);
        tool_bar = new QToolBar(BirthdayWindow);
        tool_bar->setObjectName(QString::fromUtf8("tool_bar"));
        BirthdayWindow->addToolBar(Qt::LeftToolBarArea, tool_bar);

        menubar->addAction(menuOsoby->menuAction());
        menubar->addAction(menuZobrazit->menuAction());
        menubar->addAction(menuN_pov_da->menuAction());
        menuOsoby->addAction(mp_action_pridat_osobu);
        menuOsoby->addAction(action_upravit_osobu);
        menuOsoby->addSeparator();
        menuOsoby->addAction(action_exit);
        menuZobrazit->addAction(action_panel_nastroju);
        menuZobrazit->addAction(action_stavovy_radek);
        menuN_pov_da->addAction(action_o_programu);
        menuN_pov_da->addAction(action_o_Qt);
        tool_bar->addAction(mp_action_pridat_osobu);
        tool_bar->addAction(action_upravit_osobu);
        tool_bar->addAction(action_o_programu);
        tool_bar->addAction(action_o_Qt);
        tool_bar->addAction(action_exit);

        retranslateUi(BirthdayWindow);

        QMetaObject::connectSlotsByName(BirthdayWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BirthdayWindow)
    {
        BirthdayWindow->setWindowTitle(QCoreApplication::translate("BirthdayWindow", "Narozeniny", nullptr));
        mp_action_pridat_osobu->setText(QCoreApplication::translate("BirthdayWindow", "P\305\231idat osobu", nullptr));
#if QT_CONFIG(statustip)
        mp_action_pridat_osobu->setStatusTip(QCoreApplication::translate("BirthdayWindow", "P\305\231idat novou osobu do seznamu.", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        mp_action_pridat_osobu->setShortcut(QCoreApplication::translate("BirthdayWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        action_upravit_osobu->setText(QCoreApplication::translate("BirthdayWindow", "Upravit osobu", nullptr));
#if QT_CONFIG(statustip)
        action_upravit_osobu->setStatusTip(QCoreApplication::translate("BirthdayWindow", "Upravit existuj\303\255c\303\255 osobu v seznamu.", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        action_upravit_osobu->setShortcut(QCoreApplication::translate("BirthdayWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        action_panel_nastroju->setText(QCoreApplication::translate("BirthdayWindow", "Panel n\303\241stroj\305\257", nullptr));
#if QT_CONFIG(statustip)
        action_panel_nastroju->setStatusTip(QCoreApplication::translate("BirthdayWindow", "Zobrazen\303\255 nebo skryt\303\255 n\303\241strojov\303\251ho panelu.", nullptr));
#endif // QT_CONFIG(statustip)
        action_stavovy_radek->setText(QCoreApplication::translate("BirthdayWindow", "Stavov\303\275 \305\231\303\241dek", nullptr));
#if QT_CONFIG(statustip)
        action_stavovy_radek->setStatusTip(QCoreApplication::translate("BirthdayWindow", "Zobrazen\303\255 nebo skryt\303\255 status panelu.", nullptr));
#endif // QT_CONFIG(statustip)
        action_o_programu->setText(QCoreApplication::translate("BirthdayWindow", "O programu", nullptr));
#if QT_CONFIG(statustip)
        action_o_programu->setStatusTip(QCoreApplication::translate("BirthdayWindow", "Informace o programu.", nullptr));
#endif // QT_CONFIG(statustip)
        action_o_Qt->setText(QCoreApplication::translate("BirthdayWindow", "O Qt", nullptr));
#if QT_CONFIG(statustip)
        action_o_Qt->setStatusTip(QCoreApplication::translate("BirthdayWindow", "Informace o Qt.", nullptr));
#endif // QT_CONFIG(statustip)
        action_exit->setText(QCoreApplication::translate("BirthdayWindow", "Exit", nullptr));
#if QT_CONFIG(statustip)
        action_exit->setStatusTip(QCoreApplication::translate("BirthdayWindow", "Ukon\304\215en\303\255 aplikace.", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        action_exit->setShortcut(QCoreApplication::translate("BirthdayWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        menuOsoby->setTitle(QCoreApplication::translate("BirthdayWindow", "Osoby", nullptr));
        menuZobrazit->setTitle(QCoreApplication::translate("BirthdayWindow", "Zobrazit", nullptr));
        menuN_pov_da->setTitle(QCoreApplication::translate("BirthdayWindow", "N\303\241pov\304\233da", nullptr));
        tool_bar->setWindowTitle(QCoreApplication::translate("BirthdayWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BirthdayWindow: public Ui_BirthdayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIRTHDAYWINDOW_H
