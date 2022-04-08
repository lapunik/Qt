#include "person.h"

Person::Person(QObject *parent) : QObject{parent}
{

}

Person::Person(QString name, QString surename, QDate birthday,QObject *parent) : QObject{parent}
{
    m_name = name;
    m_surname = surename;
    m_birthday = birthday;
}

Person::Person(const Person &person)
{
    m_id = person.m_id;
    m_name = person.m_name;
    m_surname = person.m_surname;
    m_birthday = person.m_birthday;
}

void Person::operator=(const Person &person)
{
    m_id = person.m_id;
    m_name = person.m_name;
    m_surname = person.m_surname;
    m_birthday = person.m_birthday;
}

void Person::set_id(int id)
{
    m_id = id;
}

void Person::set_name(QString name)
{
    m_name = name;
}

void Person::set_surname(QString name)
{
    m_surname = name;
}

void Person::set_birthday(QDate date)
{
    m_birthday = date;
}

void Person::set_birthday(int day, int month, int year)
{
    m_birthday.setDate(year, month, day);
}

int Person::get_id()
{
    return m_id;
}

QString Person::get_name()
{
    return m_name;
}

QString Person::get_surname()
{
    return m_surname;
}

QDate Person::get_birthday()
{
    return m_birthday;
}

int Person::get_day()
{
    return m_birthday.day();
}

int Person::get_month()
{
    return m_birthday.month();
}

int Person::get_year()
{
    return m_birthday.year();
}

QString Person::to_string()
{
    return QString("Person\nID: %1\nName: %2\nSurname: %3\nDate: %4").arg(m_id).arg(m_name).arg(m_surname).arg(m_birthday.toString());
}
