#include "kalkulacka.h"
#include <QIcon>
#include <QMessageBox>
#include <QString>

Kalkulacka::Kalkulacka(QWidget *parent) : QWidget(parent)
{
    layout = new QGridLayout();

    disp = new QLCDNumber();

    layout->addWidget(disp,1,1,1,4); // poloha y,x,velikost v ose y, velikost v ose x

    button_10 = new QRadioButton("DEC",this);
    button_16 = new QRadioButton("HEX",this);
    button_8 = new QRadioButton("OCT",this);
    button_2 = new QRadioButton("BIN",this);
    button_10->setChecked(true);

    layout->addWidget(button_10, 2, 1); // nemusím udávat velikost, pokud chci prvek o velikosti 1x1
    layout->addWidget(button_2, 2, 2);
    layout->addWidget(button_16, 2, 3);
    layout->addWidget(button_8, 2, 4);

    num_buttons = new QButtonGroup();
    num_buttons->addButton(button_10);
    num_buttons->addButton(button_2);
    num_buttons->addButton(button_16);
    num_buttons->addButton(button_8);

    number_1 = new QLineEdit();
    number_2 = new QLineEdit();

    layout->addWidget(number_1, 3, 1, 1, 2);
    layout->addWidget(number_2, 3, 3, 1, 2);

    btn_add = new QRadioButton("+",this);
    btn_sub = new QRadioButton("-",this);
    btn_mlp = new QRadioButton("*",this);
    btn_div = new QRadioButton("/",this);
    btn_add->setChecked(true);

    operation_buttons = new QButtonGroup();
    operation_buttons->addButton(btn_add);
    operation_buttons->addButton(btn_sub);
    operation_buttons->addButton(btn_mlp);
    operation_buttons->addButton(btn_div);

    layout->addWidget(btn_add, 4, 1); // nemusím udávat velikost, pokud chci prvek o velikosti 1x1
    layout->addWidget(btn_sub, 4, 2);
    layout->addWidget(btn_mlp, 4, 3);
    layout->addWidget(btn_div, 4, 4);

    compute_btn = new QPushButton(tr("Calculate")); // tr je použito kvůli mezinárodnímu rozhraní (pokud budeme všechny řetězce uzavírat do této funkce, máme ji připravenou na vícejazyčnou formu)
    layout->addWidget(compute_btn,5,1,1,4);

    setLayout(layout);

    resize(500,250); // Velikost okna
    setWindowTitle("Mocná kalkulačka"); // Titulek okna
    setWindowIcon(QIcon(":/img/ikona")); // Změna ikony

    disp->setDigitCount(32); // nastavení počtu čísel displeje
    disp->setMaximumHeight(50); // nastavení macimální výšky displeje

    model = new Model(this); // vytvoření instance našeho modelu (this je ukazatel na rodiče instance, kterým tedy je naše třída kalkulačka)

    // v tuto chvíli již provedeme připojení signálů vizuálního okna k naším vytvořeným slotům
    connect(button_8,SIGNAL(clicked()),this,SLOT(set_oct()));
    connect(button_10,SIGNAL(clicked()),this,SLOT(set_dec()));
    connect(button_16,SIGNAL(clicked()),this,SLOT(set_hex()));
    connect(button_2,SIGNAL(clicked()),this,SLOT(set_bin()));

    connect(btn_add,SIGNAL(clicked()),this,SLOT(set_add()));
    connect(btn_sub,SIGNAL(clicked()),this,SLOT(set_sub()));
    connect(btn_mlp,SIGNAL(clicked()),this,SLOT(set_mlp()));
    connect(btn_div,SIGNAL(clicked()),this,SLOT(set_div()));

    connect(compute_btn,SIGNAL(clicked()),this,SLOT(calculate()));

    // displej má signál overflow, který signalizuje přetečení displeje. My tento signál budeme zpracovávat, aby se uživatel nedivil, že výslesledky nesedí
    connect(disp,SIGNAL(overflow()),this,SLOT(number_too_big()));

    // nakonec tady dochází k propojení našich uživatelských signálů k slotům preo zpracování ve vizuální vrstvě
    connect(model,SIGNAL(number_false(int)),this,SLOT(get_false_num(int)));
    connect(model,SIGNAL(zero_divide()),this,SLOT(get_zero_divide()));

}

Kalkulacka::~Kalkulacka()
{
    if(compute_btn != nullptr)
    {
        delete compute_btn;
    }
    if(operation_buttons != nullptr)
    {
        delete operation_buttons;
    }
    if(btn_add != nullptr)
    {
        delete btn_add;
    }
    if(btn_div != nullptr)
    {
        delete btn_div;
    }
    if(btn_mlp != nullptr)
    {
        delete btn_mlp;
    }
    if(btn_sub != nullptr)
    {
        delete btn_sub;
    }
    if(number_1 != nullptr)
    {
        delete number_1;
    }
    if(number_2 != nullptr)
    {
        delete number_2;
    }
    if(num_buttons != nullptr)
    {
        delete num_buttons;
    }
    if(button_10 != nullptr)
    {
        delete button_10;
    }
    if(button_8 != nullptr)
    {
        delete button_8;
    }
    if(button_2 != nullptr)
    {
        delete button_2;
    }
    if(button_16 != nullptr)
    {
        delete button_16;
    }
    if(disp != nullptr)
    {
        delete disp;
    }
    if(layout != nullptr)
    {
        delete layout;
    }
    if(model != nullptr)
    {
        delete model;
    }
}

// Je na čase všechny SLOTy deklarovat
void Kalkulacka::set_add()
{
    model->set_operation(Model::add);
}
void Kalkulacka::set_sub()
{
    model->set_operation(Model::sub);
}
void Kalkulacka::set_mlp()
{
    model->set_operation(Model::mlp);
}
void Kalkulacka::set_div()
{
    model->set_operation(Model::div);
}

void Kalkulacka::set_dec()
{
    model->set_num_basis(Model::dec);
    disp->setDecMode();
}
void Kalkulacka::set_bin()
{
    model->set_num_basis(Model::bin);
    disp->setBinMode();
}
void Kalkulacka::set_hex()
{
    model->set_num_basis(Model::hex);
    disp->setHexMode();
}
void Kalkulacka::set_oct()
{
    model->set_num_basis(Model::oct);
    disp->setOctMode();
}

// následují SLOTy s chybami

void Kalkulacka::number_too_big()
{
    QMessageBox mess(QMessageBox::Information,tr("Příliš dlouhé číslo"),tr("Číslo je příliš dlouhé pro vypsání na displej."));
    mess.exec(); // exec (execute) je vlastně samotné vyskočení chybového okna
}

void Kalkulacka::get_false_num(Model::number n)
{
    if(n == Model::first)
    {
        QMessageBox mess(QMessageBox::Critical, tr("První číslo není zadané správně"), tr("Někdě se stala chyba. Špatný formát čísla nebo nebylo zadáno vůbec"));
        mess.exec();
    }
    else
    {
        QMessageBox mess(QMessageBox::Critical, tr("Druhé číslo není zadané správně"), tr("Někdě se stala chyba. Špatný formát čísla nebo nebylo zadáno vůbec"));
        mess.exec();
    }
}

void Kalkulacka::get_zero_divide()
{
    QMessageBox mess(QMessageBox::Critical, tr("Dělení nulou"), tr("Dělení nulou nelze vypočítat."));
    mess.exec();
}

// Poslední SLOT je pochopitelně pro samotný výpočet
void Kalkulacka::calculate()
{
    model->set_first(number_1->text());
    model->set_second(number_2->text());
    int result = model->calculate();
    disp->display(result);
}
