#include "layer_widget.h"

Layer_widget::Layer_widget(QWidget *parent) : QWidget{parent}
{
    set_widget();

    add_widget(Neuron::id_e);
}

Layer_widget::Layer_widget(bool input, bool output, QWidget *parent) : QWidget{parent}
{

    output_layer = output;
    input_layer = input;

    set_widget();

    if(output)
        add_widget(Neuron::output_e);

    if(input)
        add_widget(Neuron::input_e);
}

Layer_widget::Layer_widget(QList<Neuron::func> *neuron, QWidget *parent) : QWidget{parent}
{

    set_widget();

    for (auto i : *neuron)
    {
        add_widget(i);
    }

}

void Layer_widget::set_widget()
{
    mp_main_layout = new QVBoxLayout(this);
    mp_main_layout->setSpacing(0);
    mp_main_layout->setContentsMargins(0,0,0,0);

    mp_inner_layout = new QVBoxLayout(this);
    mp_inner_layout->setSpacing(0);
    mp_inner_layout->setContentsMargins(0,0,0,0);

    mp_remove_neuron_buttton = new Button_roundted();
    mp_remove_neuron_buttton->button->setStyleSheet("QPushButton{"
                                                    "    image: url(:/res/icon/minus);"
                                                    "}"
                                                    "QPushButton:hover"
                                                    "{"
                                                    "    image: url(:/res/icon/minus_clicked);"
                                                    "}"
                                                    "QPushButton:pressed"
                                                    "{"
                                                    "    image: url(:/res/icon/minus_disabled2);"
                                                    "}"
                                                    );
    mp_remove_neuron_buttton->setFixedSize(QSize(30,30));
    //mp_remove_neuron_buttton->button->setIconSize(QSize(28,28));
    mp_remove_neuron_buttton->reconfigurable = false;
    connect(mp_remove_neuron_buttton->button, SIGNAL(clicked()), this, SLOT(remove_widget()));
    rem = new QHBoxLayout();
    l = new QLabel();
    rem->addWidget(l);
    rem->addWidget(mp_remove_neuron_buttton);
    rem->addWidget(l);

    mp_add_neuron_buttton = new Button_roundted();
    mp_add_neuron_buttton->button->setStyleSheet("QPushButton{"
                                                 "    image: url(:/res/icon/plus);"
                                                 "}"
                                                 "QPushButton:hover"
                                                 "{"
                                                 "    image: url(:/res/icon/plus_clicked);"
                                                 "}"
                                                 "QPushButton:pressed"
                                                 "{"
                                                 "    image: url(:/res/icon/plus_disabled2);"
                                                 "}"
                                                 );
    mp_add_neuron_buttton->setFixedSize(QSize(30,30));
    //mp_add_neuron_buttton->button->setIconSize(QSize(28,28));
    mp_add_neuron_buttton->reconfigurable = false;
    connect(mp_add_neuron_buttton->button, SIGNAL(clicked()), this, SLOT(add_widget()));
    ad = new QHBoxLayout();
    ad->addWidget(new QLabel());
    ad->addWidget(mp_add_neuron_buttton);
    ad->addWidget(new QLabel());

    if(!output_layer)
    {
        mp_main_layout->addLayout(rem);
    }
    mp_main_layout->addLayout(mp_inner_layout);
    if(!output_layer)
    {
        mp_main_layout->addLayout(ad);
    }

    neurons = new QList<Neuron*>();

    setLayout(mp_main_layout);

    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    // nastavení vytvořeného layoutu jako layout okna předka

    setStyleSheet("background-color: rgba(240, 240, 240, 255)");

    //connect(this, SIGNAL(redraw()), parent(), SLOT(resize_inner_event()));

}

Layer_widget::~Layer_widget()
{

    if(mp_label != nullptr)
    {
        delete mp_label;
    }
    if(rem != nullptr)
    {
        delete rem;
    }
    if(ad != nullptr)
    {
        delete ad;
    }
    if(neurons != nullptr)
    {
        for(int i = 0; i < neurons->size();i++)
        {
                if (neurons->at(i) != nullptr)
                {
                    delete neurons->at(i);
                }
        }

        delete neurons;
    }
    if(l != nullptr)
    {
        delete l;
    }
    if(mp_inner_layout != nullptr)
    {
        delete mp_inner_layout;
    }
    if(mp_main_layout != nullptr)
    {
        delete mp_main_layout;
    }
    if(mp_remove_neuron_buttton != nullptr)
    {
        delete mp_remove_neuron_buttton;
    }
    if( mp_add_neuron_buttton != nullptr)
    {
        delete  mp_add_neuron_buttton;
    }

}

void Layer_widget::add_widget()
{
    add_widget(Neuron::id_e);
}

void Layer_widget::add_widget(Neuron::func fun)
{

    if(input_layer)
    {
        fun = Neuron::input_e;
    }

    neurons->push_back(new Neuron(fun));

    if(!input_layer && !output_layer)
        connect(neurons->last(), SIGNAL(double_clicked_signal(Neuron*)), this, SLOT(choose_function(Neuron*)));

    mp_inner_layout->addWidget(neurons->last());

    if(neurons->count() == 1)
    {
        mp_remove_neuron_buttton->button->setStyleSheet("QPushButton{"
                                                        "    image: url(:/res/icon/minus_disabled);"
                                                        "}"
                                                        "QPushButton:hover"
                                                        "{"
                                                        "    image: url(:/res/icon/minus_disabled);"
                                                        "}"
                                                        "QPushButton:pressed"
                                                        "{"
                                                        "    image: url(:/res/icon/minus_disabled);"
                                                        "}"
                                                        );
    }
    else
    {
        mp_remove_neuron_buttton->button->setStyleSheet("QPushButton{"
                                                        "    image: url(:/res/icon/minus);"
                                                        "}"
                                                        "QPushButton:hover"
                                                        "{"
                                                        "    image: url(:/res/icon/minus_clicked);"
                                                        "}"
                                                        "QPushButton:pressed"
                                                        "{"
                                                        "    image: url(:/res/icon/minus_disabled2);"
                                                        "}"
                                                        );
    }

    emit redraw();
}

void Layer_widget::remove_widget()
{

    if(neurons->count() <= 1)
    {
        return;
    }

    QList<Neuron::func> *neurons_temp = new QList<Neuron::func>();

    for (int i = 0; i < neurons->count()-1; i++)
    {
        neurons_temp->push_back(neurons->at(i)->get_function());
    }

    for(int i = mp_inner_layout->count()-1;i >= 0;i--)
    {
        mp_inner_layout->itemAt(i)->widget()->setParent(0);
    }

    while(!neurons->isEmpty())
    {
        neurons->removeAt(0);
    }

    for (auto i : *neurons_temp)
    {
        add_widget(i);
    }

    if(neurons_temp != nullptr)
    {
        delete neurons_temp;
    }

    if(neurons->count() == 1)
    {
        mp_remove_neuron_buttton->button->setStyleSheet("QPushButton{"
                                                        "    image: url(:/res/icon/minus_disabled);"
                                                        "}"
                                                        "QPushButton:hover"
                                                        "{"
                                                        "    image: url(:/res/icon/minus_disabled);"
                                                        "}"
                                                        "QPushButton:pressed"
                                                        "{"
                                                        "    image: url(:/res/icon/minus_disabled);"
                                                        "}"
                                                        );
    }

    emit redraw();

}

void Layer_widget::choose_function(Neuron *n)
{
    Neuron_settings_window * win = new Neuron_settings_window(n);

    win->exec();

    //mp_result_widget->redraw();

    if (win != nullptr)
    {
        delete win;
    }

}

std::vector<function> Layer_widget::get_neurons()
{
    std::vector<function> temp;

    for(int i = 0;i < neurons->count();i++)
    {
        temp.push_back(neuron_to_function(neurons->at(i)));
    }

    return temp;
}

function Layer_widget::neuron_to_function(Neuron *n)
{
    Neuron::func f = n->get_function();

    if(f == Neuron::id_e)
    {
        return Neural_network_model::id;
    }
    else if (f == Neuron::pow2_e)
    {
        return Neural_network_model::pow2;
    }
    else if (f == Neuron::pow3_e)
    {
        return Neural_network_model::pow3;
    }
    else if (f == Neuron::pow4_e)
    {
        return Neural_network_model::pow4;
    }
    else if (f == Neuron::times_e)
    {
        return Neural_network_model::times;
    }
    else if (f == Neuron::divide_e)
    {
        return Neural_network_model::divide;
    }
    else if (f == Neuron::sin_e)
    {
        return Neural_network_model::sin;
    }
    else if (f == Neuron::cos_e)
    {
        return Neural_network_model::cos;
    }
    else if (f == Neuron::sigmoid_e)
    {
        return Neural_network_model::sigmoid;
    }
    else if (f == Neuron::n_sigmoid_e)
    {
        return Neural_network_model::n_sigmoid;
    }
    else if (f == Neuron::tanh_e)
    {
        return Neural_network_model::tanh;
    }
    else if (f == Neuron::f_sigmoid_e)
    {
        return Neural_network_model::f_sigmoid;
    }
    else if (f == Neuron::heaviside_e)
    {
        return Neural_network_model::heaviside;
    }
    else if (f == Neuron::signum_e)
    {
        return Neural_network_model::signum;
    }
    else if (f == Neuron::p_id_e)
    {
        return Neural_network_model::p_id;
    }
    else if (f == Neuron::sat_e)
    {
        return Neural_network_model::sat;
    }
    else if (f == Neuron::p_sat_e)
    {
        return Neural_network_model::p_sat;
    }
    else if (f == Neuron::rad_e)
    {
        return Neural_network_model::rad;
    }
    else
    {
        return Neural_network_model::id;
    }

}



