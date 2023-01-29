#include "network_widget.h"

Network_widget::Network_widget(QWidget *parent) : QWidget{parent}
{
    layout = new QHBoxLayout(this);
    layout->setSpacing(0);
    setContentsMargins(0,0,0,0);

    mp_remove_layer_buttton = new Button_roundted();
    mp_remove_layer_buttton->button->setStyleSheet("QPushButton{"
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
    mp_remove_layer_buttton->reconfigurable = false;
    mp_remove_layer_buttton->setFixedSize(QSize(30,30));
    mp_remove_layer_buttton->button->setIconSize(QSize(28,28));
    connect(mp_remove_layer_buttton->button, SIGNAL(clicked()), this, SLOT(remove_layer()));

    mp_add_layer_buttton = new Button_roundted();
    //mp_add_layer_buttton->button->setIcon(QIcon(":/res/icon/plus"));
    mp_add_layer_buttton->button->setIconSize(QSize(0,0));
    mp_add_layer_buttton->button->setStyleSheet("QPushButton{"
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
    mp_add_layer_buttton->reconfigurable = false;
    mp_add_layer_buttton->setFixedSize(QSize(30,30));
    mp_add_layer_buttton->button->setIconSize(QSize(28,28));
    connect(mp_add_layer_buttton->button, SIGNAL(clicked()), this, SLOT(add_layer()));

    mp_inner_layout = new QHBoxLayout();
    mp_inner_layout->setSpacing(0);
    mp_inner_layout->setContentsMargins(0,0,0,0);

    layers = new QVector<Layer_widget*>();

    input_layer = new Layer_widget(true, false, this);
    connect(input_layer, SIGNAL(redraw()), this, SLOT(resize_inner_event()));
    mp_inner_layout->addWidget(input_layer);

    output_layer = new Layer_widget(false, true, this);
    connect(output_layer, SIGNAL(redraw()), this, SLOT(resize_inner_event()));
    mp_inner_layout->addWidget(output_layer);

    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);

    layout->addWidget(mp_remove_layer_buttton);

    layout->addLayout(mp_inner_layout);

    layout->addWidget(mp_add_layer_buttton);

    setLayout(layout);

    // add defalut network
    QList<Neuron::func> *l_1 = new QList<Neuron::func>();
    l_1->push_back(Neuron::id_e);
    l_1->push_back(Neuron::sin_e);
    l_1->push_back(Neuron::times_e);

    add_layer(l_1);

    while(!l_1->isEmpty())
    {
        l_1->removeAt(0);
    }

    l_1->push_back(Neuron::divide_e);

    add_layer(l_1);

}

Network_widget::~Network_widget()
{
    if(mp_remove_layer_buttton != nullptr)
    {
        delete mp_remove_layer_buttton;
    }
    if(mp_add_layer_buttton != nullptr)
    {
        delete mp_add_layer_buttton;
    }
    if(output_layer != nullptr)
    {
        delete output_layer;
    }
    if(input_layer != nullptr)
    {
        delete input_layer;
    }
    if(layers != nullptr)
    {
        for(int i = 0; i < layers->size();i++)
        {
                if (layers->at(i) != nullptr)
                {
                    delete layers->at(i);
                }
        }

        delete layers;
    }
    if(mp_inner_layout != nullptr)
    {
        delete mp_inner_layout;
    }
    if(layout != nullptr)
    {
        delete layout;
    }

}

void Network_widget::add_layer()
{
    QList<Neuron::func> *l = new QList<Neuron::func>();
    l->push_back(Neuron::id_e);
    add_layer(l);
}

void Network_widget::add_layer(QList<Neuron::func> *fun)
{    

    mp_inner_layout->itemAt(mp_inner_layout->count()-1)->widget()->setParent(0);

    layers->push_back(new Layer_widget(fun,this));

    connect(layers->last(), SIGNAL(redraw()), this, SLOT(resize_inner_event()));

    mp_inner_layout->addWidget(layers->last());

    mp_inner_layout->addWidget(output_layer);

    if(layers->count() == 1)
    {
        mp_remove_layer_buttton->button->setStyleSheet("QPushButton{"
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
        mp_remove_layer_buttton->button->setStyleSheet("QPushButton{"
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

    resize_inner_event();

}

void Network_widget::remove_layer()
{
    if(layers->count() <= 0)
    {
        return;
    }

    mp_inner_layout->itemAt(mp_inner_layout->count()-1)->widget()->setParent(0);
    mp_inner_layout->itemAt(mp_inner_layout->count()-1)->widget()->setParent(0);

    layers->removeLast();

    mp_inner_layout->addWidget(output_layer);

    if(layers->count() == 0)
    {
        mp_remove_layer_buttton->button->setStyleSheet("QPushButton{"
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
        mp_remove_layer_buttton->button->setStyleSheet("QPushButton{"
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

    resize_inner_event();

}

void Network_widget::redraw()
{

    if(size_change_blockator)
    {
        set_neurons_size(2);
        return;
    }

    int diameter =0 ;
    int max_count = input_layer->neurons->size();
    int size = 0;

    for(auto i : *layers)
    {
        size = i->neurons->size();

        if(size > max_count)
        {
            max_count = size;
        }
    }

    if(((height()-60)/max_count) > ((width()-60)/(layers->size()+2)))
    {
        diameter = ((width()-60)/(layers->size()+2));
    }
    else
    {
        diameter = ((height()-60)/max_count);
    }

//    if(diameter > 300)
//    {
//        diameter -= 68; // Neměnit! Při menší hodnotě způsobuje cyklické zvětšování okna
//    }
//    else
//    {
        diameter -= diameter/10;
//    }

    set_neurons_size(diameter);

}

void Network_widget::set_neurons_size(int diameter)
{

    for(auto i : *input_layer->neurons)
    {
        i->set_redraw(diameter);
    }

    for(auto i : *layers)
    {
        for(auto j : *i->neurons)
        {
            j->set_redraw(diameter);
        }
    }

    output_layer->neurons->at(0)->set_redraw(diameter);
}

void Network_widget::resizeEvent(QResizeEvent *event)
{
    redraw();
    QWidget::resizeEvent(event);
}

void Network_widget::resize_inner_event()
{
    redraw();
}

std::vector<std::vector<function>> Network_widget::get_net()
{

    std::vector<std::vector<function>> net;

    for(int i = 0; i < layers->count();i++)
    {
        net.push_back(layers->at(i)->get_neurons());
    }

    std::vector<function> output = {Neural_network_model::id};

    net.push_back(output);

    return net;
}

int Network_widget::get_number_of_inputs()
{
    return input_layer->get_neurons().size();
}

void Network_widget::load_model(std::vector< QList<Neuron::func>*> f)
{
    for(int i = 0;i < layers->count()+1; i++)
    {
        remove_layer();
    }

    for(int j = 0;j < static_cast<int>(f.size()); j++)
    {
        add_layer(f.at(j));
    }
}

void Network_widget::change_blockator(bool state)
{
    size_change_blockator = state;
    if(!state)
    {
        redraw();
    }
}
