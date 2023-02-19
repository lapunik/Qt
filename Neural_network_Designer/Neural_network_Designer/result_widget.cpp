#include "result_widget.h"

Result_widget::Result_widget(int id, QWidget *parent) : QWidget{parent}
{

    ID = id;
    m_parent = parent;

    layout = new QHBoxLayout(this);
    layout->setSpacing(0);

    tools = new QTabWidget(this);
    setContentsMargins(0,0,0,0);

    structure = new Network_widget();
    connect(this,SIGNAL(change_block_state(bool)),structure,SLOT(change_blockator(bool)));
    settings = new Settings_widget(this);
    connect(settings,SIGNAL(calculate()),this,SLOT(calculate()));
    results = new Results_widget(this);
    connect(results,SIGNAL(save()),this,SLOT(download()));
    connect(this,SIGNAL(change_block_state(bool)),results,SLOT(change_blockator(bool)));

    connect(parent,SIGNAL(save(bool,int)),this,SLOT(save_process(bool,int)));

    tools->addTab(structure,QIcon(":/res/icon/edit"),"Design");
    tools->addTab(settings,QIcon(":/res/icon/settings2"),"Settings");
    tools->addTab(results,QIcon(":/res/icon/results"),"Results");

    tools->setIconSize(QSize(30,30));

    layout->addWidget(tools);

    setLayout(layout);

}

Result_widget::~Result_widget()
{

    if(settings != nullptr)
    {
        delete settings;
    }
    if(results != nullptr)
    {
        delete results;
    }
    if(structure != nullptr)
    {
        delete structure;
    }
    if(tools != nullptr)
    {
        delete tools;
    }
    if(layout != nullptr)
    {
        delete layout;
    }
    if(nn_model != nullptr)
    {
        delete nn_model;
    }
}

void Result_widget::disconnect_save()
{

    disconnect(m_parent,SIGNAL(save(bool,int)),0,0);

}

void  Result_widget::download()
{
    save_process(true,ID);
}

void Result_widget::calculate()
{

    if(structure->get_number_of_inputs() != settings->get_num_of_inputs())
    {
        Message_box* mess = new Message_box("\n The number of inputs in the input data\n  does not correspond the number of neurons\n  in the input layer.","Error",this);
        mess->exec();
        if (mess != nullptr)
        {
            delete mess;
        }
        return;
    }

    QApplication::setOverrideCursor(Qt::WaitCursor);

    if(nn_model != nullptr)
    {
        delete nn_model;
    }

    nn_model = new Neural_network_model(structure->get_net(),settings->get_settings());

    Information_window* win = new Information_window(nn_model->err,nn_model->itt);

    QApplication::setOverrideCursor(Qt::ArrowCursor);

    win->exec();
    if (win != nullptr)
    {
        delete win;
    }

    if(results != nullptr)
    {
        disconnect(results,SIGNAL(save()),0,0);
        delete results;
    }

    results = new Results_widget(this);
    connect(this,SIGNAL(change_block_state(bool)),results,SLOT(change_blockator(bool)));
    connect(results,SIGNAL(save()),this,SLOT(download()));
    results->load_model(nn_model);
    tools->addTab(results,QIcon(":/res/icon/results"),"Results");
    tools->setCurrentIndex(2);



}

void Result_widget::save_process(bool as, int index)
{

    if(ID != index)
    {
        return;
    }

    if((file_name == "" )||(as))
    {

        QString answer = QFileDialog::getSaveFileName(this, tr("Save File"),QDir::currentPath().append("/untitled.nnd"),tr("Neural network file (*.nnd)"));

        if(answer == "")
        {
            return;
        }

        file_name = answer;

        QStringList list1 = file_name.split(u'/');
        emit change_name(ID,list1.last());
    }

    write_file(file_name);

    Message_box* mess = new Message_box("\n The model have been saved.","Information",this);
    mess->exec();
    if (mess != nullptr)
    {
        delete mess;
    }

}

bool Result_widget::write_file(QString f_name)
{

    std::vector<std::vector<function>> net = structure->get_net();
    Model_settings sett = settings->get_settings();

    int num_of_inputs = structure->get_number_of_inputs();
    std::string str = ("name=" + f_name.split('/').last() + "\n").toStdString();
    str.append("layers=" + std::to_string(net.size()) + "\n");
    str.append("neurons=");
    str.append(std::to_string(num_of_inputs) + ",");
    for (int i = 0; i < static_cast<int>(net.size()-2); i++)
    {
        str.append(std::to_string(net.at(i).size()) + ",");
    }
    str.append(std::to_string(net.at(net.size()-2).size()) + "\n");
    str.append("algorithm=" + sett.algorithm_to_string(sett.algo).toStdString() + "\n");
    str.append("stochastic=");
    str.append(sett.stochastic ? "true" : "false");
    str.append(",");
    str.append((sett.stochastic?std::to_string(sett.stochastic_ratio):("0")));
    str.append("\nlearning_coefficient=" + std::to_string(sett.learning_coeff) + "\n");
    str.append("cycles=");
    str.append(sett.max_cycles_bool ? "true" : "false");
    str.append("," + std::to_string(sett.max_cycles) + "\n");
    str.append("tolerance=");
    str.append(sett.max_tolerance_bool ? "true" : "false");
    str.append("," + std::to_string(sett.max_tolerance) + "\n");
    str.append("regularization=");
    str.append(sett.regularization_bool ? "true" : "false");
    str.append("," + sett.regularization_to_string(sett.regularization_type).toStdString() + ",");
    str.append(((sett.regularization_bool)?(std::to_string(sett.regularization_from)):("0")));
    str.append(",");
    str.append((sett.regularization_bool?std::to_string(sett.regularization_to):("0")));
    str.append(",");
    str.append((sett.regularization_bool?std::to_string(sett.regularization_cycles):("0")));
    str.append("\n");
    for (int j = 0; j < static_cast<int>(net.size()-1); j++)
    {
        str.append("l" + std::to_string(j+1) + "=");

        for (int i = 0; i < static_cast<int>(net.at(j).size()) - 1; i++)
        {
            str.append((Neural_network_model::function_to_string(net.at(j).at(i))) + ",");
        }

        str.append(Neural_network_model::function_to_string(net.at(j).at(net.at(j).size() - 1)) + "\n");
    }
    str.append("input_data=");
    str.append(settings->is_input_data() ? "true" : "false\n");
    if(settings->is_input_data())
    {
        str.append("," + std::to_string(sett.input_data.at(0).size()) + "\n");
        for (int j = 0; j < static_cast<int>(sett.input_data.size()); j++)
        {
            str.append("d_");
            str.append((j == 0) ? "y" : "x");
            str.append(std::to_string(j) + "=");

            for (int i = 0; i < sett.input_data.at(0).size()-1; i++)
            {
                str.append(std::to_string(sett.input_data.at(j).at(i)) + ",");
            }

            str.append(std::to_string(sett.input_data.at(j).at(sett.input_data.at(0).size() - 1)) + "\n");

        }
    }
    str.append("calculated=");
    str.append(nn_model != nullptr ? "true" : "false");
    str.append("\n");
    if (nn_model != nullptr)
    {
        int temp_cnt = 1;

        for (int l = 0; l < static_cast<int>(nn_model->KOEF.size()); l++)
        {
            str.append("model_" + std::to_string(l) + "=\n");

            for (int k = 0; k < static_cast<int>(nn_model->KOEF.at(l).size()); k++)
            {
                for (int j = 0; j < static_cast<int>(nn_model->KOEF.at(l).at(k).size()); j++)
                {
                    for (int i = 0; i < static_cast<int>(nn_model->KOEF.at(l).at(k).at(j).size()); i++)
                    {
                        str.append((k==0?"w":"b"));
                        str.append(std::to_string(temp_cnt));
                        temp_cnt++;
                        str.append("=");
                        str.append(std::to_string(nn_model->KOEF.at(l).at(k).at(j).at(i)));
                        str.append("\n");
                    }
                }

                temp_cnt = 1;
            }
        }
    }

    std::fstream file;

    file.open(file_name.toStdString(), std::ios::out);

    file << str;

    file.close();

    return true;
}

void Result_widget::load_model(QString f_name)
{

    QFile file(f_name);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {


        QStringList list;
        QTextStream stream(&file);

        std::vector<QList<Neuron::func>*> net;
        Model_settings sett = Model_settings();

        file_name = f_name;

        list = stream.readLine().split('=');
        emit change_name(ID,QString(list.at(1)));
        list = stream.readLine().split('=');
        int layers_count = list.at(1).toInt();
        std::vector<int> neurons_count;
        list = stream.readLine().split('=');
        list = list.at(1).split(',');
        for (int i = 0; i < layers_count; i++)
        {
            neurons_count.push_back(list.at(i).toInt());
        }
        list = stream.readLine().split('=');
        sett.algo = Model_settings::string_to_algorithm(list.at(1));
        list = stream.readLine().split('=');
        list = list.at(1).split(',');
        sett.stochastic = (list.at(0) == "true") ? true : false;
        if(sett.stochastic)
        {
            sett.stochastic_ratio = list.at(1).toDouble();
        }
        else
        {
            sett.stochastic_ratio = 1.0;
        }
        list = stream.readLine().split('=');
        sett.learning_coeff = list.at(1).toDouble();
        list = stream.readLine().split('=');
        list = list.at(1).split(',');
        sett.max_cycles_bool = (list.at(0) == "true") ? true : false;
        sett.max_cycles = list.at(1).toDouble();
        list = stream.readLine().split('=');
        list = list.at(1).split(',');
        sett.max_tolerance_bool = (list.at(0) == "true") ? true : false;
        sett.max_tolerance = list.at(1).toDouble();
        list = stream.readLine().split('=');
        list = list.at(1).split(',');
        sett.regularization_bool = (list.at(0) == "true") ? true : false;
        sett.regularization_type = Model_settings::string_to_regularization(list.at(1));
        sett.regularization_from = list.at(2).toInt();
        sett.regularization_to = list.at(3).toInt();
        sett.regularization_cycles = list.at(4).toInt();
        QList<Neuron::func>* q;
        for (int j = 1; j < layers_count; j++)
        {
            list = stream.readLine().split('=');
            list = list.at(1).split(",");

            q = new QList<Neuron::func>();

            for (int i = 0; i < neurons_count.at(j); i++)
            {
                q->push_back(Neuron::string_to_func(list.at(i)));
            }
            net.push_back(q);
        }
        list = stream.readLine().split('=');
        list = list.at(1).split(',');
        if(list.at(0) == "true")
        {

            int data_cout = list.at(1).toInt();

            QVector<double> vek;

            for(int j = 0;j < neurons_count.at(0)+1;j++)
            {

                list = stream.readLine().split('=');
                list = list.at(1).split(',');

                for(int i = 0; i < data_cout;i++)
                {
                    vek.push_back(list.at(i).toDouble());
                }

                sett.input_data.push_back(vek);
                vek.clear();
            }
        }

        structure->load_model(net);

        settings->load_model(sett);

        list = stream.readLine().split('=');
        list = list.at(1).split(',');
        if(list.at(0) == "true")
        {

            if(nn_model != nullptr)
            {
                delete nn_model;
            }

            try
            {

                std::vector<std::vector<std::vector<std::vector<double>>>> koef;
                koef.resize(sett.regularization_bool?sett.regularization_cycles:1);
                std::vector<std::vector<double>> values;
                values.resize(2);

                list = stream.readLine().split('=');

                for(int j = 0;j < static_cast<int>(koef.size());j++)
                {

                    while(true)
                    {
                        list = stream.readLine().split('=');
                        if(list.count() == 2)
                        {
                            if(list.at(0)[0] == 'w')
                            {
                                values.at(0).push_back(list.at(1).toDouble());
                            }
                            else if(list.at(0)[0] == 'b')
                            {
                                values.at(1).push_back(list.at(1).toDouble());
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }

                    koef.at(j) = fill_koeficients(structure->get_net(),neurons_count.front(),values);

                    values.clear();
                    values.resize(2);


                }

                nn_model = new Neural_network_model(structure->get_net(),settings->get_settings(),koef);
            }
            catch (char const* str)
            {
                Message_box* mess = new Message_box(str,"Something wrong!",this);
                mess->exec();
                if (mess != nullptr)
                {
                    delete mess;
                }
                return;
            }


            results->load_model(nn_model);

            tools->setCurrentIndex(2);

        }
        else
        {
            tools->setCurrentIndex(1);
        }

    }

    file.close();

}

void  Result_widget::update_ID(int id)
{
    ID = id;
}

std::vector<std::vector<std::vector<double>>> Result_widget::fill_koeficients(std::vector<std::vector<function>> net, int inputs,std::vector<std::vector<double>> values)
{

    std::vector<std::vector<double>> w(net.size());
    std::vector<std::vector<double>> b(net.size());

    int w_count = 0;
    int b_count = 0;

    int net_size = net.at(0).size();

    const char* coeff_err = "The number of calculated coefficients does not\n correspond to the structure of neural network.";

    for (int n = 0; n < net_size; n++)
    {
        for (int i = 0; i < inputs; i++)
        {

            if(static_cast<int>(net.at(0).size()) > n)
            {
                if (((net.at(0).at(n) == Neural_network_model::times) || (net.at(0).at(n) == Neural_network_model::divide))&&(i==0))
                {
                    net_size = net_size + 1;
                }
            }

            if(w_count >= static_cast<int>(values.at(0).size()))
            {
                throw(coeff_err);
            }
            w.at(0).push_back((values.at(0).at(w_count)));
            w_count++;
        }
    }

    for (int l = 0; l < static_cast<int>(net.size()); l++)
    {

        for (int n = 0; n < static_cast<int>(net.at(l).size()); n++)
        {

            if(b_count > static_cast<int>(values.at(1).size()))
            {
                throw(coeff_err);
            }
            b.at(l).push_back((values.at(1).at(b_count)));
            b_count++;
        }

        if (l != static_cast<int>(net.size() - 1))
        {

            net_size = net.at(l).size() * net.at(l + 1).size();


            for (int n = 0; n < net_size; n++)
            {
                if(static_cast<int>(net.at(l+1).size()) > n)
                {
                    if ((net.at(l + 1).at(n) == Neural_network_model::times) || (net.at(l + 1).at(n) == Neural_network_model::divide))
                    {
                        net_size = net_size + net.at(l).size();
                    }
                }

                if(w_count >= static_cast<int>(values.at(0).size()))
                {
                    throw(coeff_err);
                }

                w.at(l + 1).push_back((values.at(0).at(w_count)));
                w_count++;
            }
        }
    }

    return std::vector<std::vector<std::vector<double>>>{w,b};
}

void Result_widget::change_blockator(bool state)
{
    emit change_block_state(state);
}
