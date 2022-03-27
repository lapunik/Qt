#ifndef KALKULACKA_H
#define KALKULACKA_H

#include <QWidget>
#include <QGridLayout>
#include <QLCDNumber>
#include <QRadioButton>
#include <QButtonGroup>
#include <QLineEdit>
#include <QPushButton>

#include "model.h"

class Kalkulacka : public QWidget
{
    Q_OBJECT

public:
    Kalkulacka(QWidget *parent = nullptr);
    ~Kalkulacka();

    QGridLayout *layout; // mřížkové rozložení
    QLCDNumber *disp; // LCD displej
    QRadioButton *button_10; // radiobox pro desítkovou soustavu
    QRadioButton *button_16; // radiobox pro šestnáctkovou soustavu
    QRadioButton *button_2;  // radiobox pro dvojkovou soustavu
    QRadioButton *button_8;  // radiobox pro osmičkovou soustavu
    QButtonGroup *num_buttons;  // skupina radio boxů pro výběr soustavy
    QLineEdit *number_1; // první číslo výpočtu
    QLineEdit *number_2; // druhé číslo výpočtu
    QRadioButton *btn_add;  // radiobox pro sčítání
    QRadioButton *btn_sub; // radiobox pro odečítání
    QRadioButton *btn_mlp; // radiobox pro násobení
    QRadioButton *btn_div; // radiobox pro dělení
    QButtonGroup *operation_buttons; // // skupina radio boxů pro výběr matematické operace
    QPushButton *compute_btn; // tlačítko rovná se (výpočet)

private:

    Model *model;

public slots: // tady pro změnu připravíme sloty (funkce) pro přijímání signálů, kterých bude potřeba přijímat spousta, protože skrze ně vlastně bude komunikace s modelem. Nastavovací funkce, nebo signály, ty všechny musí mít nějaký slot

    void number_too_big();

    void set_add();
    void set_sub();
    void set_mlp();
    void set_div();

    void set_dec();
    void set_bin();
    void set_hex();
    void set_oct();

    void get_false_num(Model::number);
    void get_zero_divide();

    void calculate();

};

#endif // KALKULACKA_H
