#ifndef MODEL_SETTINGS_H
#define MODEL_SETTINGS_H

#include <iostream>
#include <QVector>
#include <QString>

class Model_settings
{
public:

    enum algorithm
    {
        ADAM,
        moment,
        none
    };

    enum regularization
    {
        lasso,
    };

    Model_settings();

    QVector<QVector<double>> input_data;
    algorithm algo;
    bool stochastic;
    double stochastic_ratio;
    double learning_coeff;
    bool max_cycles_bool;
    int max_cycles;
    bool max_tolerance_bool;
    double max_tolerance;
    bool regularization_bool;
    regularization regularization_type;
    int regularization_from;
    int regularization_to;

    static algorithm string_to_algorithm (QString al);
    static QString algorithm_to_string(algorithm al);


};

#endif // MODEL_SETTINGS_H
