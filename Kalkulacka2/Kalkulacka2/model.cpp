#include "model.h"

model::model(QObject *parent): QObject{parent}
{
    first_num = 0;
    second_num = 0;
    op = model::add;
}


void model::set_first_number(QString value)
{
    first_num = value.toDouble(nullptr);
}
void model::set_second_number(QString value)
{
    second_num = value.toDouble(nullptr);
}

void model::set_operation(operation oper)
{
    op = oper;
}

double model::calculate()
{
    switch (op)
    {
    case add:
        return first_num + second_num;
    case sub:
        return first_num - second_num;
    case mlp:
        return first_num * second_num;
    case div:
        if(second_num == 0)
        {
            emit deleni_nulou();
            return 0;
        }
        return first_num / second_num;
    }


}
