#include "result_widget.h"

#include <QFile>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>

#include "person.h"
#include "person_model.h"

Result_widget::Result_widget(Person_model *model,QWidget *parent): QWidget{parent}
{

    mp_layout = new QFormLayout(this);
    mp_layout->setLabelAlignment(Qt::AlignRight);

    mp_model = model;

    m_today = QDate::currentDate();

    mp_label_today_date = new QLabel(this);
    mp_label_today_saint = new QLabel(this);

    mp_label_yesterday2 = new QLabel(no_result);
    mp_label_yesterday = new QLabel(no_result);
    mp_label_today = new QLabel(no_result);
    mp_label_today->setStyleSheet("font-size: 24px;");
    mp_label_tomorrow = new QLabel(no_result);
    mp_label_tomorrow->setStyleSheet("font-size: 20px;");
    mp_label_tomorrow2 = new QLabel(no_result);

    mp_layout->addRow(tr("Dnes je: "),mp_label_today_date); // nastavení obsahu jednotlicých řádků ve wigetu
    mp_layout->addRow(tr("Svátek má: "),mp_label_today_saint);
    mp_layout->addRow(tr("Předevčírem: "),mp_label_yesterday2);
    mp_layout->addRow(tr("Včera: "),mp_label_yesterday);
    mp_layout->addRow(tr("Dnes: "),mp_label_today);
    mp_layout->addRow(tr("Zítra: "),mp_label_tomorrow);
    mp_layout->addRow(tr("Pozítří: "),mp_label_tomorrow2);

    setLayout(mp_layout); // nastavení vytvořeného layoutu jako layout okna předka
    layout()->setSpacing(10); // mezery mezi prvky nasatavit na 10

    // Qt umí stylování pomocí CSS přímo u jednotlivých prvků,
    setStyleSheet("QLabel { font-size: 16px; font-weight: bold; }");

    redraw();
}

Result_widget::~Result_widget()
{
    if (mp_layout != nullptr)
    {
        delete mp_layout;
    }

    if (mp_label_today_date != nullptr)
    {
        delete mp_label_today_date;
    }

    if (mp_label_today_saint != nullptr)
    {
        delete mp_label_today_saint;
    }

    if (mp_label_yesterday2 != nullptr)
    {
        delete mp_label_yesterday2;
    }

    if (mp_label_yesterday != nullptr)
    {
        delete mp_label_yesterday;
    }

    if (mp_label_today != nullptr)
    {
        delete mp_label_today;
    }

    if (mp_label_tomorrow != nullptr)
    {
        delete mp_label_tomorrow;
    }

    if (mp_label_tomorrow2 != nullptr)
    {
        delete mp_label_tomorrow2;
    }
}

void Result_widget::redraw()
{
    set_saint_name(); // zjištění, kdo má dnes svátek ze souboru whos/when
    whos_brithday(); //zjištění, kdo má narozeniny
}

void Result_widget::set_saint_name()
{
    mp_label_today_date->setText(m_today.toString("dd. MMMM yyyy (dddd)"));
//    mp_label_today_date->setStyleSheet("color: indigo");

    mp_label_today_saint->setText(get_saint_name());
//    mp_label_today_saint->setStyleSheet("color: firebrick");
}

void Result_widget::whos_brithday()
{
    try
    {
        Person person;

        QList<Person> person_list;

        if (mp_model->find_by_date(m_today.toJulianDay()-2, &person_list))
        {
           mp_label_yesterday2->setText(create_reusult_string(person_list));
        }
        else
        {
            mp_label_yesterday2->setText(no_result);
        }

        if (mp_model->find_by_date(m_today.toJulianDay()-1, &person_list))
        {
           mp_label_yesterday->setText(create_reusult_string(person_list));
        }
        else
        {
            mp_label_yesterday->setText(no_result);
        }

        if (mp_model->find_by_date(m_today.toJulianDay(), &person_list))
        {
           mp_label_today->setText(create_reusult_string(person_list));
        }
        else
        {
            mp_label_today->setText(no_result);
        }

        if (mp_model->find_by_date(m_today.toJulianDay()+1, &person_list))
        {
           mp_label_tomorrow->setText(create_reusult_string(person_list));
        }
        else
        {
            mp_label_tomorrow->setText(no_result);
        }

        if (mp_model->find_by_date(m_today.toJulianDay()+2, &person_list))
        {
           mp_label_tomorrow2->setText(create_reusult_string(person_list));
        }
        else
        {
            mp_label_tomorrow->setText(no_result);
        }

    }
    catch (QString exp)
    {
        QMessageBox mess;
        mess.critical(this,"Chyba", exp.append("\nChyba ve čtení narozenin."));
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
