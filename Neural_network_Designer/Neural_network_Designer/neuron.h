#ifndef NEURON_H
#define NEURON_H

#include <QObject>
#include <QIcon>
#include <QString>
#include <button_roundted.h>
#include <neural_network_model.h>

typedef double (*function)(double, double);


class Neuron : public Button_roundted
{
    Q_OBJECT

    typedef double (*function)(double, double);

public:

    enum func
    {
        id_e,
        pow2_e,
        pow3_e,
        pow4_e,
        times_e,
        divide_e,
        sin_e,
        cos_e,
        sigmoid_e,
        n_sigmoid_e,
        tanh_e,
        f_sigmoid_e,
        heaviside_e,
        signum_e,
        p_id_e,
        sat_e,
        p_sat_e,
        rad_e,
        input_e,
        output_e
    };

    explicit Neuron(Button_roundted *parent = nullptr);
    explicit Neuron(func f,Button_roundted *parent = nullptr);
    virtual ~Neuron();


private:

    QIcon ic;
    QString name;
    func m_func;

    const int graph_width = 200;
    const int graph_height = 200;
    const int equation_height = 100;

public:

    void set_function(func fu);
    func get_function();
    QString get_name();
    QIcon get_ic();
    static func string_to_func(QString str);

signals:

    void double_clicked_signal(Neuron *n);

public slots:

    void double_clicked_slot();

};

#endif // NEURON_H
