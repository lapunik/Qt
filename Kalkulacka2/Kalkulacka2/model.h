#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class model : public QObject
{
    Q_OBJECT
public:

    enum operation
    {
        add,
        sub,
        mlp,
        div,
    };

    explicit model(QObject *parent = nullptr);
    void set_first_number(QString value);
    void set_second_number(QString value);

    void set_operation(operation oper);

    double calculate();

private:

    double first_num;
    double second_num;

    operation op;

signals:

    void deleni_nulou();

};

#endif // MODEL_H
