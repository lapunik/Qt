#ifndef RESULT_WIDGET_H
#define RESULT_WIDGET_H

#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QString>
#include <QDate>
#include <QList>

#include "person.h"
#include "person_model.h"

class Result_widget : public QWidget
{
    Q_OBJECT
public:
    explicit Result_widget(Person_model *model,QWidget *parent = nullptr);
    void redraw();
    virtual ~Result_widget();

private:

    QString no_result = QString("Žádná událost");

    QFormLayout *mp_layout; // přidání layoutu

    QLabel *mp_label_today_date = nullptr;     // přidání jednotlivých labelů do layoutu
    QLabel *mp_label_today_saint = nullptr;
    QLabel *mp_label_yesterday2 = nullptr;
    QLabel *mp_label_yesterday = nullptr;
    QLabel *mp_label_today = nullptr;
    QLabel *mp_label_tomorrow = nullptr;
    QLabel *mp_label_tomorrow2 = nullptr;

    Person_model *mp_model;
    QDate m_today;

    QString get_saint_name(); // získání jména dnešního svátku z JSON souboru
    void set_saint_name(); // nastavení jména dnešního svátku
    void whos_brithday(); // nastavení záznamů narozenin z našeho vytvořeného modelu_person
    QString create_reusult_string(QList<Person> &person_list); // Vytvoření stringu pro label s narozeninami

signals:

};

#endif // RESULT_WIDGET_H
