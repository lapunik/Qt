#include "model.h"

Model::Model(QObject *parent) : QObject{parent}
{
    first_num = 0;
    second_num = 0;
    op = Model::add;
    nb = Model::dec;
    is_first_ok = false;
    is_second_ok = false;

}

// SETtery, neboli funkce pro nastavení hodnot

void Model::set_first(QString value) // funkce pro nastavení prvního čísla
{
    first_num = number_test(value,&is_first_ok);
}
void Model::set_second(QString value) // funkce pro nastavení druhého čísla
{
    second_num = number_test(value,&is_second_ok);
}
void Model::set_operation(operation value) // funkce pro nastavení operace
{
    op = value;
}
void Model::set_num_basis(number_basis value) // funkce pro nastavení číslené soustavy
{
    nb = value;
}

int Model::number_test(QString number, bool *isOk) // test vstupů
{
    switch(nb) // podle číselné soustavy se pokusím převést na int v danné číselné soustavě
    {
    case Model::dec:
        return number.toInt(isOk,10); // v ukazateli isOk si vracím bool nebo false podle toho, jestli se převod povedl
    case Model::bin:
        return number.toInt(isOk,2);
    case Model::hex:
        return number.toInt(isOk,16);
    case Model::oct:
        return number.toInt(isOk,8);
    default:
        *isOk = false;
        return 0;
    }
}

int Model::calculate()
{
    if(!is_first_ok)
    {
        emit number_false(Model::first); // emit je příkaz pro vyvolání signálu, v tomto případě vyvolání signálu s informací a chybě v prvním čísle
        return 0;
    }

    if(!is_second_ok)
    {
        emit number_false(Model::second); // emit je příkaz pro vyvolání signálu, v tomto případě vyvolání signálu s informací a chybě v prvním čísle
        return 0;
    }

    if((second_num == 0)&&(op == Model::div))
    {
        emit zero_divide(); // emit je příkaz pro vyvolání signálu, v tomto případě vyvolání signálu s informací a chybě v prvním čísle
        return 0;
    }

    switch(op) // podle číselné soustavy se pokusím převést na int v danné číselné soustavě
    {
    case Model::add:
        return first_num + second_num; // v ukazateli isOk si vracím bool nebo false podle toho, jestli se převod povedl
        break;
    case Model::sub:
        return first_num - second_num;
        break;
    case Model::mlp:
        return first_num * second_num;
        break;
    case Model::div:
        return first_num / second_num;
        break;
    default:
        return 0;
    }

}
