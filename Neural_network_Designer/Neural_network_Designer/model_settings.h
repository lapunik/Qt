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
        nothing,
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
    int regularization_cycles;

    static algorithm string_to_algorithm (QString al);
    static QString algorithm_to_string(algorithm al);
    static int algorithm_to_index(algorithm al);
    static int regularization_to_index(regularization reg);
    static regularization string_to_regularization (QString al);
    static QString regularization_to_string(regularization reg);


};

#endif // MODEL_SETTINGS_H
