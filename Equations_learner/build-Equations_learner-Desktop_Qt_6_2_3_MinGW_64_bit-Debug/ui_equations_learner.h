/********************************************************************************
** Form generated from reading UI file 'equations_learner.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUATIONS_LEARNER_H
#define UI_EQUATIONS_LEARNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Equations_learner
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Equations_learner)
    {
        if (Equations_learner->objectName().isEmpty())
            Equations_learner->setObjectName(QString::fromUtf8("Equations_learner"));
        Equations_learner->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(127, 129, 131, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        QBrush brush2(QColor(227, 227, 227, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(160, 160, 160, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush4(QColor(255, 255, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush4);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush4);
        QBrush brush5(QColor(240, 240, 240, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush5);
        QBrush brush6(QColor(105, 105, 105, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        QBrush brush7(QColor(46, 47, 48, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush4);
        QBrush brush8(QColor(0, 0, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush8);
        QBrush brush9(QColor(255, 0, 255, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush9);
        QBrush brush10(QColor(245, 245, 245, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush);
        QBrush brush11(QColor(255, 255, 220, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush11);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush12(QColor(0, 0, 0, 128));
        brush12.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        QBrush brush13(QColor(0, 0, 0, 255));
        brush13.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush13);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush11);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        QBrush brush14(QColor(120, 120, 120, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush14);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        QBrush brush15(QColor(247, 247, 247, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush14);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush14);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush16(QColor(0, 120, 215, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush16);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        QBrush brush17(QColor(0, 0, 0, 255));
        brush17.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush17);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush11);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
        Equations_learner->setPalette(palette);
        centralwidget = new QWidget(Equations_learner);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Equations_learner->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Equations_learner);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Equations_learner->setMenuBar(menubar);
        statusbar = new QStatusBar(Equations_learner);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Equations_learner->setStatusBar(statusbar);

        retranslateUi(Equations_learner);

        QMetaObject::connectSlotsByName(Equations_learner);
    } // setupUi

    void retranslateUi(QMainWindow *Equations_learner)
    {
        Equations_learner->setWindowTitle(QCoreApplication::translate("Equations_learner", "Equations_learner", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Equations_learner: public Ui_Equations_learner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUATIONS_LEARNER_H
