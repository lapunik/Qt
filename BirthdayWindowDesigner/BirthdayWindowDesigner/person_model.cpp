#include "person_model.h"

Person_model::Person_model(QObject *parent) : QObject{parent}
{
    QFile file(FILENAME);

    m_isChanged = false; // indikace, že nedošlo k žádné změně v datech

    if(file.exists())
    {
        if(!file.open(QIODevice::ReadOnly|QIODevice::Text)) // otevření souboru pro čtení textu
        {
            throw "Person_model - constructor: I cannot open the JSON file for reading.";
        }

        QJsonParseError json_errors; // případné chyby v JSON
        m_json_person_document = QJsonDocument::fromJson(file.readAll(),&json_errors); // načtení JSON dokumnetu a případné chyby budou v proměnné json_errors

        while(file.isOpen())
        {
            file.close();
        }

        if(json_errors.error != QJsonParseError::NoError) //ověření, že načtení JSONu proběhlo v pořádku
        {
            throw("Person_model - constructor: Some errors in JSON format.");
        }

        m_json_person_array = m_json_person_document.array();

    }
    else // pokud soubor neexistuje, tak ho vytvořím, a hned mu předám první osobu, což budu já
    {
        Person person;
        person.set_id(0);
        person.set_name("Vojtěch");
        person.set_surname("Lapuník");
        person.set_birthday(25,8,1997);
        add_person(person);
        m_isChanged = true;
    }
}

Person_model::~Person_model()
{
    save_document();
}

void Person_model::get_person(QJsonObject &json_object, Person *person) // osoba není vrácena jako návratová hodnota, ale pouze se zapíše na ukazatel vstupního argumentu
{
    person->set_id(json_object[JSON_ID].toInt());
    person->set_name(json_object[JSON_NAME].toString());
    person->set_surname(json_object[JSON_SURNAME].toString());
    person->set_birthday(json_object[JSON_DAY].toInt(),json_object[JSON_MONTH].toInt(),json_object[JSON_YEAR].toInt());

}

void Person_model::set_person(QJsonObject &json_object, Person &person)
{
    json_object[JSON_ID] = person.get_id();
    json_object[JSON_NAME] = person.get_name();
    json_object[JSON_SURNAME] = person.get_surname();
    json_object[JSON_DAY] = person.get_day();
    json_object[JSON_MONTH] = person.get_month();
    json_object[JSON_YEAR] = person.get_year();

}

void Person_model::save_document()
{
    if(m_isChanged)
    {
        QJsonDocument(m_json_person_array).toJson(QJsonDocument::Compact); // osekání JSON soubor o vše co nepotřebuje

        m_json_person_document.setArray(m_json_person_array); // následně uložíme osekané pole do proměnné s již samotným dokumentem

        QFile file(FILENAME);

        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            throw "Person_model - save_document: I cannot open the JSON file for writing.";
        }

        file.write(m_json_person_document.toJson());
        file.flush();

        while(file.isOpen())
        {
            file.close();
        }

        m_isChanged = false;

    }

}

int Person_model::count()
{
    return m_json_person_array.size();
}

int Person_model::get_last_id()
{
    int last_id = 0;
    for(auto item : m_json_person_array)
    {
        QJsonObject object = item.toObject();
        if(object[JSON_ID].toInt() > last_id)
        {
            last_id = object[JSON_ID].toInt();
        }
    }

    return last_id;
}

void Person_model::add_person(Person& person)
{
    QJsonObject json_object;
    person.set_id(get_last_id()+1);
    set_person(json_object,person);
    m_json_person_array.append(json_object);
    m_isChanged = true;
}

bool Person_model::save_person(int id,Person &person)
{
    bool person_changed = false; // logická proměná, která indikuje, že jsme osobu našli a její záznam změnili
    QJsonArray temporary_array; // pomocné pole, do kterého budeme ukládat záznam po záznamu infomrmace ze straého pole, až na ten jeden onen záznam, který chceme změnit

    for(auto item : m_json_person_array) // projíždíme celé pole záznamů
    {
        QJsonObject json_object = item.toObject(); //záznam si vytáhneme do pomocné proměnné

        if(json_object[JSON_ID] == id) // pokud je item zrovna osoba, kterou chci uložit, tak provedu změnu jejich údajů podle vstupního argumentu funkce
        {
            set_person(json_object,person);
            person_changed = true;
        }

        temporary_array.append(json_object);
    }

    m_json_person_array = temporary_array;

    m_isChanged = true;

    return person_changed;
}

bool Person_model::delete_person(int id)
{
    bool person_changed = false; // logická proměná, která indikuje, že jsme osobu našli a její záznam změnili
    QJsonArray temporary_array; // pomocné pole, do kterého budeme ukládat záznam po záznamu infomrmace ze straého pole, až na ten jeden onen záznam, který chceme změnit

    for(auto item : m_json_person_array) // projíždíme celé pole záznamů
    {
        QJsonObject json_object = item.toObject(); //záznam si vytáhneme do pomocné proměnné

        if(json_object[JSON_ID] == id) // pokud je item zrovna osoba, kterou chci uložit, tak provedu změnu jejich údajů podle vstupního argumentu funkce
        {
            person_changed = true;
            continue;
        }

        temporary_array.append(json_object);
    }

    m_json_person_array = temporary_array;

    m_isChanged = true;

    return person_changed;
}

bool Person_model::find_by_id(int id, Person *person)
{
    bool person_found = false;

    for(auto item : m_json_person_array)
    {
        QJsonObject obj = item.toObject();

        if(obj[JSON_ID] == id)
        {
            get_person(obj,person); // získání osoby
            person_found = true;
            break; // není třeba dále hledat, když už jsme osobu nalezli
        }
    }

    return person_found;
}

bool Person_model::find_by_name(QString name, QList<Person> *person_list)
{
    bool person_found = false;

    Person person;

    for(auto item : m_json_person_array)
    {
        QJsonObject obj = item.toObject();

        if((QString(obj[JSON_NAME].toString() + " " + obj[JSON_SURNAME].toString())) == name)
        {
            get_person(obj,&person); // získání osoby
            person_found = true;
            person_list->append(person);
        }
    }

    return person_found;
}

bool Person_model::find_by_date(long julian_day, QList<Person> *person_list)
{
    bool person_found = false;

    Person person;

    for(auto item : m_json_person_array)
    {
        QJsonObject obj = item.toObject();

        if(QDate(QDate::currentDate().year(),obj[JSON_MONTH].toInt(),obj[JSON_DAY].toInt()).toJulianDay() == julian_day)
        {
            get_person(obj,&person); // získání osoby
            person_found = true;
            person_list->append(person);
        }
    }

    return person_found;
}

bool Person_model::find_all_names(QStringList *person_list)
{
    bool retVal = false;

    Person person;

    for (auto item: m_json_person_array) {
        QJsonObject obj = item.toObject();

        get_person(obj, &person);
        QString name = QString("%1 %2 |%3|")
                           .arg(person.get_surname())
                           .arg(person.get_name())
                           .arg(QString::number(person.get_id()));
        person_list->append(name);
        retVal = true;
    }
    return retVal;
}

