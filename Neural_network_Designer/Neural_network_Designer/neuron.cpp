#include "neuron.h"


Neuron::Neuron(Button_roundted *parent) : Button_roundted{parent}
{
    set_function(id_e);
    connect(button, SIGNAL(double_clicked()), this, SLOT(double_clicked_slot()));
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}

Neuron::Neuron(func fun, Button_roundted *parent) : Button_roundted{parent}
{
    set_function(fun);
    connect(button, SIGNAL(double_clicked()), this, SLOT(double_clicked_slot()));
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}

Neuron::~Neuron()
{

}

Neuron::func Neuron::get_function()
{
    return m_func;
}

QString Neuron::get_name()
{
    return name;
}

QIcon Neuron::get_ic()
{
    return ic;
}

void Neuron::set_function(func fu)
{
    m_func = fu;

    switch(fu)
    {
    case id_e:
        ic = QIcon(":/res/icon/id");
        name = QString("Linear");
        break;
    case pow2_e:
        ic = QIcon(":/res/icon/pow2");
        name = QString("Squere power");
        break;
    case pow3_e:
        ic = QIcon(":/res/icon/pow3");
        name = QString("Cube power");
        break;
    case pow4_e:
        ic = QIcon(":/res/icon/pow4");
        name = QString("Quatter power");
        break;
    case times_e:
        ic = QIcon(":/res/icon/times");
        name = QString("Times");
        break;
    case divide_e:
        ic = QIcon(":/res/icon/divide");
        name = QString("Divide");
        break;
    case sin_e:
        ic = QIcon(":/res/icon/sin");
        name = QString("Sinus");
        break;
    case cos_e:
        ic = QIcon(":/res/icon/cos");
        name = QString("Cosinus");
        break;
    case sigmoid_e:
        ic = QIcon(":/res/icon/sigmoid");
        name = QString("Sigmoid");
        break;
    case n_sigmoid_e:
        ic = QIcon(":/res/icon/n_sigmoid");
        name = QString("Symetric sigmoid");
        break;
    case tanh_e:
        ic = QIcon(":/res/icon/tanh");
        name = QString("Hyperbolic tangent");
        break;
    case f_sigmoid_e:
        ic = QIcon(":/res/icon/f_sigmoid");
        name = QString("Fake sigmoid");
        break;
    case heaviside_e:
        ic = QIcon(":/res/icon/heaviside");
        name = QString("Heaviside");
        break;
    case signum_e:
        ic = QIcon(":/res/icon/signum");
        name = QString("Signum");
        break;
    case p_id_e:
        ic = QIcon(":/res/icon/p_id");
        name = QString("Positive linear");
        break;
    case sat_e:
        ic = QIcon(":/res/icon/sat");
        name = QString("Saturation linear");
        break;
    case p_sat_e:
        ic = QIcon(":/res/icon/p_sat");
        name = QString("Positive saturation linear");
        break;
    case rad_e:
        ic = QIcon(":/res/icon/rad");
        name = QString("Radial");
        break;
    case input_e:
        ic = QIcon(":/res/icon/times");
        name = QString("Input");
        break;
    case output_e:
        ic = QIcon(":/res/icon/output");
        name = QString("Output");
        break;

    }

    button->setIcon(ic);
}


void Neuron::double_clicked_slot()
{

    if(reconfigurable)
        emit double_clicked_signal(this);
}
