/********************************************************************************
** Form generated from reading UI file 'result_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULT_WIDGET_H
#define UI_RESULT_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Result_widget
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *dnesJeLabel;
    QLabel *label_today_date;
    QLabel *label_2;
    QLabel *label_today_saint;
    QLabel *label_4;
    QLabel *label_yesterday2;
    QLabel *label;
    QLabel *label_yesterday;
    QLabel *label_3;
    QLabel *label_today;
    QLabel *label_5;
    QLabel *label_tomorrow;
    QLabel *label_tomorrow2;
    QLabel *label_7;

    void setupUi(QWidget *Result_widget)
    {
        if (Result_widget->objectName().isEmpty())
            Result_widget->setObjectName(QString::fromUtf8("Result_widget"));
        Result_widget->resize(400, 300);
        Result_widget->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}"));
        formLayoutWidget = new QWidget(Result_widget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 381, 281));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(0, 0, 0, 0);
        dnesJeLabel = new QLabel(formLayoutWidget);
        dnesJeLabel->setObjectName(QString::fromUtf8("dnesJeLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, dnesJeLabel);

        label_today_date = new QLabel(formLayoutWidget);
        label_today_date->setObjectName(QString::fromUtf8("label_today_date"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_today_date);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_today_saint = new QLabel(formLayoutWidget);
        label_today_saint->setObjectName(QString::fromUtf8("label_today_saint"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_today_saint);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        label_yesterday2 = new QLabel(formLayoutWidget);
        label_yesterday2->setObjectName(QString::fromUtf8("label_yesterday2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_yesterday2);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label);

        label_yesterday = new QLabel(formLayoutWidget);
        label_yesterday->setObjectName(QString::fromUtf8("label_yesterday"));

        formLayout->setWidget(3, QFormLayout::FieldRole, label_yesterday);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        label_today = new QLabel(formLayoutWidget);
        label_today->setObjectName(QString::fromUtf8("label_today"));
        label_today->setStyleSheet(QString::fromUtf8("font-size: 24px;"));

        formLayout->setWidget(4, QFormLayout::FieldRole, label_today);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        label_tomorrow = new QLabel(formLayoutWidget);
        label_tomorrow->setObjectName(QString::fromUtf8("label_tomorrow"));
        label_tomorrow->setStyleSheet(QString::fromUtf8("font-size: 20px;"));

        formLayout->setWidget(5, QFormLayout::FieldRole, label_tomorrow);

        label_tomorrow2 = new QLabel(formLayoutWidget);
        label_tomorrow2->setObjectName(QString::fromUtf8("label_tomorrow2"));

        formLayout->setWidget(6, QFormLayout::FieldRole, label_tomorrow2);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);


        retranslateUi(Result_widget);

        QMetaObject::connectSlotsByName(Result_widget);
    } // setupUi

    void retranslateUi(QWidget *Result_widget)
    {
        Result_widget->setWindowTitle(QCoreApplication::translate("Result_widget", "Form", nullptr));
        dnesJeLabel->setText(QCoreApplication::translate("Result_widget", "Dnes je:", nullptr));
        label_today_date->setText(QCoreApplication::translate("Result_widget", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Result_widget", "Sv\303\241tek m\303\241: ", nullptr));
        label_today_saint->setText(QCoreApplication::translate("Result_widget", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("Result_widget", "P\305\231edev\304\215\303\255rem", nullptr));
        label_yesterday2->setText(QCoreApplication::translate("Result_widget", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("Result_widget", "V\304\215era:", nullptr));
        label_yesterday->setText(QCoreApplication::translate("Result_widget", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("Result_widget", "Dnes:", nullptr));
        label_today->setText(QCoreApplication::translate("Result_widget", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("Result_widget", "Z\303\255tra:", nullptr));
        label_tomorrow->setText(QCoreApplication::translate("Result_widget", "TextLabel", nullptr));
        label_tomorrow2->setText(QCoreApplication::translate("Result_widget", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("Result_widget", "Poz\303\255t\305\231\303\255:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Result_widget: public Ui_Result_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULT_WIDGET_H
