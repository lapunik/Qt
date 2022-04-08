#include "result_widget.h"
#include "ui_result_widget.h"

#include <QMessageBox>

Result_widget::Result_widget(Person_model *model, QWidget *parent) : QWidget(parent), ui(new Ui::Result_widget)
{
    ui->setupUi(this);

    m_today = QDate::currentDate();
    mp_model = model;

    redraw();
}

Result_widget::~Result_widget()
{
    delete ui;
}

void Result_widget::set_saint_name()
{
    ui->label_today_date->setText(m_today.toString("dd. MMMM yyyy (dddd)"));

    ui->label_today_saint->setText(get_saint_name()); ;
}

void Result_widget::whos_birthday()
{
        Person person;

        QList<Person> person_list;

        QString no_result(tr("Žádná událost"));

        ui->label_yesterday2->setText(no_result);
        ui->label_yesterday->setText(no_result);
        ui->label_today->setText(no_result);
        ui->label_today->setStyleSheet("font-size: 24px;");
        ui->label_tomorrow->setText(no_result);
        ui->label_tomorrow->setStyleSheet("font-size: 20px;");
        ui->label_tomorrow2->setText(no_result);

        if (mp_model->find_by_date(m_today.toJulianDay()-2, &person_list))
        {
           ui->label_yesterday2->setText(create_reusult_string(person_list));
        }
        else
        {
            ui->label_yesterday2->setText(no_result);
        }

        if (mp_model->find_by_date(m_today.toJulianDay()-1, &person_list))
        {
           ui->label_yesterday->setText(create_reusult_string(person_list));
        }
        else
        {
            ui->label_yesterday->setText(no_result);
        }

        if (mp_model->find_by_date(m_today.toJulianDay(), &person_list))
        {
           ui->label_today->setText(create_reusult_string(person_list));
        }
        else
        {
            ui->label_today->setText(no_result);
        }

        if (mp_model->find_by_date(m_today.toJulianDay()+1, &person_list))
        {
           ui->label_tomorrow->setText(create_reusult_string(person_list));
        }
        else
        {
            ui->label_tomorrow->setText(no_result);
        }

        if (mp_model->find_by_date(m_today.toJulianDay()+2, &person_list))
        {
           ui->label_tomorrow2->setText(create_reusult_string(person_list));
        }
        else
        {
            ui->label_tomorrow2->setText(no_result);
        }
}

QString Result_widget::get_saint_name()
{
    QFile file(":res/file/when"); // Nastavit soubor pro čtení - svátky podle data

    file.open(QIODevice::ReadOnly | QIODevice::Text); // otevřít pro čtení

    QJsonParseError jerror; // pro případ errorů (už známe)
    QJsonDocument jdoc= QJsonDocument::fromJson(file.readAll(),&jerror); // Soubor načíst do dokumentu
    file.close(); // zavřít soubor

    if(jerror.error != QJsonParseError::NoError) // Vyhodnocení správnosti souboru
    {
        throw("Nastala chyba v souboru JSON");
    }

    QJsonObject obj = jdoc.object(); // Z dokumentu udělat objekt JSON
    QString when = m_today.toString("ddMM"); // Datum převést na formát číselného řetězce den+měsíc např.: "0212"
    QJsonArray day_array = obj[when].toArray(); // Vhodnou položku převést na pole JSON, protože jmen může být několik
    QString names;

    if (day_array.isEmpty()) // Pokud se neuložilo pole, znamená to, že je tam je jeden string
    {
        QString day_string = obj[when].toString();
        names = day_string;
    }
    else     // Položek bylo více, tak z nich udělat opět řetězec s oddělovačem
    {
        for (auto item: day_array)
        {
            names.append(item.toString());
            names.append("\n");
        }
        // Poslední oddělovač odstranit
        names = names.left(names.length() - 2);
    }

    return names;
}

QString Result_widget::create_reusult_string(QList<Person> &person_list)
{
    int year = m_today.year(); // Dnešní datum - tedy letošní rok

    QString names;
    Person person;


    for (Person &item: person_list) // Projít seznam a z každé položky udělat řetězec a postupně přidávat
    {
        int howMany = year - item.get_year(); // Kolik let uběhlo od narození

        names.append(item.get_surname()).append(" ").append(item.get_name()).append(" (");
        names.append(QString::number(howMany)).append(" let) ").append("\n");
    }

    if (!names.isEmpty()) // Pokud seznam není prázdný, vymazat poslední oddělovač
    {
        names = names.left(names.length() - 2);
    }

    person_list.clear(); // Seznam osob vyčistit, aby byl připraven pro další hledání.

    return names;
}

void Result_widget::redraw()
{
    set_saint_name(); // zjištění, kdo má dnes svátek ze souboru whos/when
    whos_birthday(); //zjištění, kdo má narozeniny
}
