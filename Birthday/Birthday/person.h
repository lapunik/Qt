#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>
#include <QDate>

class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QObject *parent = nullptr);
    explicit Person(QString name, QString surname, QDate birthday, QObject *parent = nullptr);
    explicit Person(const Person &person);
    void operator = (const Person &person);
private:
    int m_id;
    QString m_name;
    QString m_surname;
    QDate m_birthday;
public:
    void set_id(int id);
    void set_name(QString name);
    void set_surname(QString name);

    void set_birthday(int day, int month, int year);
    void set_birthday(QDate date);

    int get_id();
    QString get_name();
    QString get_surname();
    QDate get_birthday();

    int get_year();
    int get_month();
    int get_day();

    QString to_string();

signals:

};

#endif // PERSON_H
