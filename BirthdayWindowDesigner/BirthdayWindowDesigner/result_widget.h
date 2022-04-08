#ifndef RESULT_WIDGET_H
#define RESULT_WIDGET_H

#include <QWidget>
#include <QString>
#include <QDate>
#include <QList>

#include "person.h"
#include "person_model.h"

namespace Ui {
class Result_widget;
}

class Result_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Result_widget(Person_model *model, QWidget *parent = nullptr);
    ~Result_widget();
    void redraw();

private:

    Ui::Result_widget *ui;

    Person_model *mp_model;
    QString no_result = QString("Žádná událost");
    QDate m_today;

    QString get_saint_name(); // získání jména dnešního svátku z JSON souboru
    void set_saint_name(); // nastavení jména dnešního svátku
    void whos_birthday(); // nastavení záznamů narozenin z našeho vytvořeného modelu_person
    QString create_reusult_string(QList<Person> &person_list); // Vytvoření stringu pro label s narozeninami

};

#endif // RESULT_WIDGET_H
