/********************************************************************************
** Form generated from reading UI file 'new_person_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_PERSON_DIALOG_H
#define UI_NEW_PERSON_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_New_person_dialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QFormLayout *formLayout_2;
    QLabel *edit_name_label;
    QLineEdit *edit_name;
    QLabel *edit_surname_label;
    QLineEdit *edit_surname;
    QLabel *edit_day_label;
    QLineEdit *edit_day;
    QLabel *edit_month_label;
    QLineEdit *edit_month;
    QLabel *edit_year_label;
    QLineEdit *edit_year;
    QVBoxLayout *verticalLayout_4;
    QCalendarWidget *calendarWidget;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *button_close;
    QPushButton *button_OK;

    void setupUi(QDialog *New_person_dialog)
    {
        if (New_person_dialog->objectName().isEmpty())
            New_person_dialog->setObjectName(QString::fromUtf8("New_person_dialog"));
        New_person_dialog->resize(640, 480);
        gridLayout = new QGridLayout(New_person_dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        edit_name_label = new QLabel(New_person_dialog);
        edit_name_label->setObjectName(QString::fromUtf8("edit_name_label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, edit_name_label);

        edit_name = new QLineEdit(New_person_dialog);
        edit_name->setObjectName(QString::fromUtf8("edit_name"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, edit_name);

        edit_surname_label = new QLabel(New_person_dialog);
        edit_surname_label->setObjectName(QString::fromUtf8("edit_surname_label"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, edit_surname_label);

        edit_surname = new QLineEdit(New_person_dialog);
        edit_surname->setObjectName(QString::fromUtf8("edit_surname"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, edit_surname);

        edit_day_label = new QLabel(New_person_dialog);
        edit_day_label->setObjectName(QString::fromUtf8("edit_day_label"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, edit_day_label);

        edit_day = new QLineEdit(New_person_dialog);
        edit_day->setObjectName(QString::fromUtf8("edit_day"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, edit_day);

        edit_month_label = new QLabel(New_person_dialog);
        edit_month_label->setObjectName(QString::fromUtf8("edit_month_label"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, edit_month_label);

        edit_month = new QLineEdit(New_person_dialog);
        edit_month->setObjectName(QString::fromUtf8("edit_month"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, edit_month);

        edit_year_label = new QLabel(New_person_dialog);
        edit_year_label->setObjectName(QString::fromUtf8("edit_year_label"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, edit_year_label);

        edit_year = new QLineEdit(New_person_dialog);
        edit_year->setObjectName(QString::fromUtf8("edit_year"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, edit_year);


        horizontalLayout_2->addLayout(formLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        calendarWidget = new QCalendarWidget(New_person_dialog);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        verticalLayout_4->addWidget(calendarWidget);

        dateEdit = new QDateEdit(New_person_dialog);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        verticalLayout_4->addWidget(dateEdit);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        button_close = new QPushButton(New_person_dialog);
        button_close->setObjectName(QString::fromUtf8("button_close"));

        horizontalLayout_3->addWidget(button_close);

        button_OK = new QPushButton(New_person_dialog);
        button_OK->setObjectName(QString::fromUtf8("button_OK"));

        horizontalLayout_3->addWidget(button_OK);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(New_person_dialog);

        QMetaObject::connectSlotsByName(New_person_dialog);
    } // setupUi

    void retranslateUi(QDialog *New_person_dialog)
    {
        New_person_dialog->setWindowTitle(QCoreApplication::translate("New_person_dialog", "Dialog", nullptr));
        edit_name_label->setText(QCoreApplication::translate("New_person_dialog", "Jm\303\251no: ", nullptr));
        edit_surname_label->setText(QCoreApplication::translate("New_person_dialog", "P\305\231ij\303\255men\303\255: ", nullptr));
        edit_day_label->setText(QCoreApplication::translate("New_person_dialog", "Den narozen\303\255: ", nullptr));
        edit_month_label->setText(QCoreApplication::translate("New_person_dialog", "M\304\233s\303\255c:", nullptr));
        edit_year_label->setText(QCoreApplication::translate("New_person_dialog", "Rok:", nullptr));
        button_close->setText(QCoreApplication::translate("New_person_dialog", "Zav\305\231\303\255t", nullptr));
        button_OK->setText(QCoreApplication::translate("New_person_dialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class New_person_dialog: public Ui_New_person_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_PERSON_DIALOG_H
