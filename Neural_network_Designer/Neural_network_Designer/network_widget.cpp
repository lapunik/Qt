#include "network_widget.h"

Network_widget::Network_widget(QWidget *parent) : QWidget{parent}
{
    layout = new QHBoxLayout(this);
    layout->setSpacing(0);
    setContentsMargins(0,0,0,0);

    mp_remove_layer_buttton = new Button_roundted();
    mp_remove_layer_buttton->button->setIcon(QIcon(":/res/icon/minus"));
    mp_remove_layer_buttton->reconfigurable = false;
    mp_remove_layer_buttton->setFixedWidth(30);
    mp_remove_layer_buttton->button->setIconSize(QSize(28,28));
    connect(mp_remove_layer_buttton->button, SIGNAL(clicked()), this, SLOT(remove_layer()));

    mp_add_layer_buttton = new Button_roundted();
    mp_add_layer_buttton->button->setIcon(QIcon(":/res/icon/plus"));
    mp_add_layer_buttton->reconfigurable = false;
    mp_add_layer_buttton->setFixedWidth(30);
    mp_remove_layer_buttton->button->setIconSize(QSize(28,28));
    connect(mp_add_layer_buttton->button, SIGNAL(clicked()), this, SLOT(add_layer()));

    input_layer = new Layer_widget(true, false, this);
    connect(input_layer, SIGNAL(redraw()), this, SLOT(resize_inner_event()));
    output_layer = new Layer_widget(false, true, this);

    layers = new QVector<Layer_widget*>();

    QList<Neuron::func> *l_1 = new QList<Neuron::func>();
    l_1->push_back(Neuron::id_e);
    l_1->push_back(Neuron::sin_e);
    l_1->push_back(Neuron::times_e);

    layers->push_back(new Layer_widget(l_1,this));

    while(!l_1->isEmpty())
    {
        l_1->removeAt(0);
    }

    l_1->push_back(Neuron::divide_e);

    layers->push_back(new Layer_widget(l_1,this));

    for(int i = 0;i < layers->count();i++)
    {
        connect(layers->at(i), SIGNAL(redraw()), this, SLOT(resize_inner_event()));
    }

    mp_inner_layout = new QHBoxLayout();

    mp_inner_layout->addWidget(input_layer);

    for(int i = 0;i < layers->count();i++)
    {
        mp_inner_layout->addWidget(layers->at(i));
    }

    mp_inner_layout->addWidget(output_layer);

    layout->addWidget(mp_remove_layer_buttton);

    layout->addLayout(mp_inner_layout);

    layout->addWidget(mp_add_layer_buttton);

    setLayout(layout);

}

Network_widget::~Network_widget()
{

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

    output_layer = new Layer_widget(false, true, this);

    mp_inner_layout->addWidget(output_layer);

    if(layers->count() == 1)
    {
        mp_remove_layer_buttton->button->setIcon(QIcon(":/res/icon/minus_disabled"));
    }
    else
    {
        mp_remove_layer_buttton->button->setIcon(QIcon(":/res/icon/minus"));
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

    output_layer = new Layer_widget(false, true, this);

    mp_inner_layout->addWidget(output_layer);

    if(layers->count() == 0)
    {
        mp_remove_layer_buttton->button->setIcon(QIcon(":/res/icon/minus_disabled"));
    }
    else
    {
        mp_remove_layer_buttton->button->setIcon(QIcon(":/res/icon/minus"));
    }

    resize_inner_event();

}

void Network_widget::redraw()
{

    if(size_change_blockator)
    {
        return;
        ////////////////////////////// Doplnit skrytí neurnů dokud nereleasnu myš  !!!!  }
    }

    //    int min_diameter = input_layer->neurons->at(0)->get_redraw();

    //    int size = 0;

    //    for(auto i : *layers)
    //    {
    //        size = i->neurons->at(0)->get_redraw();

    //        if(size < min_diameter)
    //        {
    //            min_diameter = size;
    //        }
    //    }

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

    if((height()/max_count) > (width()/(layers->size()+2)))
    {
        diameter = (width()/(layers->size()+2));
    }
    else
    {
        diameter = (height()/max_count);
    }

    diameter -= 60;

    output_layer->neurons->at(0)->set_redraw(diameter);

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
