#include "layer_widget.h"

Layer_widget::Layer_widget(QWidget *parent) : QWidget{parent}
{
    mp_main_layout = new QVBoxLayout(this);

    mp_inner_layout = new QVBoxLayout();

    mp_label = new QLabel("Vrstva 1");
    mp_label->setFixedHeight(20);
    mp_label->setAlignment(Qt::AlignHCenter);

    mp_main_layout->addWidget(mp_label);
    mp_main_layout->addLayout(mp_inner_layout);

//    QCalendarWidget *cw = new QCalendarWidget();
//    mp_inner_layout->addWidget(cw);

    mp_add_neuron_buttton = new Button_roundted();
    mp_inner_layout->addWidget(mp_add_neuron_buttton);



    setLayout(mp_main_layout); // nastavení vytvořeného layoutu jako layout okna předka

}

Layer_widget::~Layer_widget()
{
    if(mp_main_layout != nullptr)
    {
        delete mp_main_layout;
    }
    if(mp_inner_layout != nullptr)
    {
        delete mp_inner_layout;
    }
    if(mp_label != nullptr)
    {
        delete mp_label;
    }
}
