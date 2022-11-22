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

Neuron::func Neuron::string_to_func(QString str)
{
    if(str == "id")
    {
        return Neuron::id_e;
    }
    else if(str == "pow2")
    {
        return Neuron::pow2_e;
    }
    else if(str == "pow3")
    {
        return Neuron::pow3_e;
    }
    else if(str == "pow4")
    {
        return Neuron::pow4_e;
    }
    else if(str == "tim")
    {
        return Neuron::times_e;
    }
    else if(str == "div")
    {
        return Neuron::divide_e;
    }
    else if(str == "sin")
    {
        return Neuron::sin_e;
    }
    else if(str == "cos")
    {
        return Neuron::cos_e;
    }
    else if(str == "sig")
    {
        return Neuron::sigmoid_e;
    }
    else if(str == "n_sig")
    {
        return Neuron::n_sigmoid_e;
    }
    else if(str == "tanh")
    {
        return Neuron::tanh_e;
    }
    else if(str == "f_sig")
    {
        return Neuron::f_sigmoid_e;
    }
    else if(str == "hea")
    {
        return Neuron::heaviside_e;
    }
    else if(str == "sign")
    {
        return Neuron::signum_e;
    }
    else if(str == "p_id")
    {
        return Neuron::p_id_e;
    }
    else if(str == "sat")
    {
        return Neuron::sat_e;
    }
    else if(str == "p_sat")
    {
        return Neuron::p_sat_e;
    }
    else if(str == "rad")
    {
        return Neuron::rad_e;
    }
    else
    {
        return Neuron::id_e;
    }

}

