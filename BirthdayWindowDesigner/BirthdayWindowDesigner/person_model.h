#ifndef PERSON_MODEL_H
#define PERSON_MODEL_H

#include <QObject>

#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QFile>
#include <QDate>
#include <QList>
#include <QStringList>

#include "person.h"

class Person_model : public QObject
{
    Q_OBJECT

private:
    const QString FILENAME = "persons.json";     // Jméno fyzického souboru na disku (koncovka json)

    const QString JSON_ID = "id"; // názvy jednotlivých polí v JSON souboru, budeme je používat jako klíče slovníku v JSON souborech
    const QString JSON_NAME = "name";
    const QString JSON_SURNAME = "surname";
    const QString JSON_DAY = "day";
    const QString JSON_MONTH = "month";
    const QString JSON_YEAR = "year";

    QJsonDocument m_json_person_document;
    QJsonArray m_json_person_array;

    bool m_isChanged;

    int get_last_id();
    void get_person(QJsonObject &json_object, Person *person);
    void set_person(QJsonObject &json_object, Person &person);
    void save_document();

public:

    explicit Person_model(QObject *parent = nullptr);
    virtual ~Person_model();

    void add_person(Person& person);
    bool save_person(int id,Person &person);
    bool delete_person(int id);

    bool find_by_id(int id, Person *person);
    bool find_by_name(QString name, QList<Person> *person_list); // tady je list místo jen jedné osoby. Je to tím, že teoreticky můžu mít v připomínkovači dva lidi s úplně totožným jménem
    bool find_by_date(long julian_day, QList<Person> *person_list); // tady je taky list, protože více lidí může mít narozky ve stejný den

    bool find_all_names(QStringList *person_list);

    int count();

signals:

};

#endif // PERSON_MODEL_H
