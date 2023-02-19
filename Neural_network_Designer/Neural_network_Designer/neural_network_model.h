#ifndef NEURAL_NETWORK_MODEL_H
#define NEURAL_NETWORK_MODEL_H

#define _USE_MATH_DEFINES

#include <QObject>
#include <QTextStream>
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include  <math.h>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <limits.h>
#include "model_settings.h"
#include "pbPlots.h"
#include "supportLib.h"

typedef double (*function)(double, double);

class Neural_network_model : public QObject
{
    Q_OBJECT
public:

    explicit Neural_network_model(std::vector<std::vector<function>> net, Model_settings setting,QObject *parent = nullptr);
    explicit Neural_network_model(std::vector<std::vector<function>> net, Model_settings setting, std::vector<std::vector<std::vector<std::vector<double>>>> koef_m, QObject *parent = nullptr);
    virtual ~Neural_network_model();

    static double id(double x, double x2 = 0);
    static double pow2(double x, double x2 = 0);
    static double pow3(double x, double x2 = 0);
    static double pow4(double x, double x2 = 0);
    static double times(double x, double x2);
    static double divide(double x, double x2);
    static double sin(double x, double x2 = 0);
    static double cos(double x, double x2 = 0);
    static double sigmoid(double x, double x2 = 0);
    static double n_sigmoid(double x, double x2 = 0);
    static double tanh(double x, double x2 = 0);
    static double f_sigmoid(double x, double x2 = 0);
    static double heaviside(double x, double x2 = 0);
    static double signum(double x, double x2 = 0);
    static double p_id(double x, double x2 = 0);
    static double sat(double x, double x2 = 0);
    static double p_sat(double x, double x2 = 0);
    static double rad(double x, double x2 = 0);

    std::vector<std::vector<double>> x;
    std::vector<std::vector<double>> Y;
    std::vector<double> y0;
    std::vector<double> regularization_range;
    std::vector<double> MSE;
    std::vector<double> NonZC;
    std::vector<std::vector<std::vector<std::vector<double>>>> KOEF;
    std::vector<double> err;
    std::vector<int> itt;

    static std::string function_to_string(function f);
    static function string_to_function(std::string);

private:

    std::vector<double>  y;

    double mse(std::vector<double> y0, std::vector<double> y1);
    std::vector<std::vector<std::vector<double>>> initialize_koeficients(std::vector<std::vector<function>> net, int inputs , double w_val, double b_val);
    std::vector<std::vector<std::vector<double>>> initialize_koeficients(std::vector<std::vector<function>> net, int inputs);
    std::vector<std::vector<std::vector<double>>> initialize_koeficients(std::vector<std::vector<function>> net);
    std::vector<std::vector<std::vector<double>>> initialize_random_koeficients(std::vector<std::vector<function>> net, int inputs, double min, double max);
    std::vector<std::vector<std::vector<double>>> initialize_random_koeficients(std::vector<std::vector<function>> net, int inputs);
    std::vector<std::vector<std::vector<double>>> initialize_random_koeficients(std::vector<std::vector<function>> net);
    double calculate(function f, double x, double x2);
    double calculate(std::vector<function> functions, double x, double x2);
    std::vector<double> calculate(function f, std::vector<double> x, std::vector<double> x2);
    std::vector<double> calculate(std::vector<function> functions, std::vector<double> x, std::vector<double> x2);
    std::vector<double> calculate(std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef);
    std::vector<double> calculate(std::vector<std::vector<double>> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef);
    double derivate(function f, double x, double x2);
    double derivate(std::vector<function> functions, double x, double x2);
    std::vector<double> derivate(function f, std::vector<double> x, std::vector<double> x2);
    std::vector<double> derivate(std::vector<function> functions, std::vector<double> x, std::vector<double> x2);
    double derivate_mse(std::vector<double> y0, std::vector<std::vector<double>> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, int t, int l, int n);
    double derivate_mse(std::vector<double> y0, std::vector<std::vector<double>> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, int t, int l, int n, double lambda);
    double derivate_mse(std::vector<double> y0, std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, int t, int l, int n);
    double derivate_mse(std::vector<double> y0, std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, int t, int l, int n, double lambda);
    std::vector<std::vector<std::vector<double>>> ADAM(std::vector<double> y0, std::vector<std::vector<double>> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, double alpha, double tau, int N, double lambda);
    std::vector<std::vector<std::vector<double>>> stochastic_ADAM(std::vector<double> y0, std::vector<std::vector<double>> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, double alpha, double tau, int N, double ratio, double lambda);
    std::vector<std::vector<std::vector<double>>> stochastic_ADAM(std::vector<double> y0, std::vector<std::vector<double>> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, double alpha, double tau, int N, double ratio);
    std::vector<std::vector<std::vector<double>>> stochastic_ADAM(std::vector<double> y0, std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, double alpha, double tau, int N, double ratio, double lambda);
    std::vector<std::vector<std::vector<double>>> stochastic_ADAM(std::vector<double> y0, std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, double alpha, double tau, int N, double ratio);
    //std::vector<double> generate(double min, double max, int N);
    //std::vector<double> noise_generate(std::vector<double> x, double sd);
    void export_graph(std::vector<double> x, std::vector<double> y, int size_x, int size_y, std::string name);
    void export_graph(std::vector<double> x, std::vector<std::vector<double>> y, int size_x, int size_y, std::string name);
    std::vector<int> change_color(std::vector<int> color);
    void fill_properties(std::vector<std::vector<std::vector<double>>> koef);

};

#endif // NEURAL_NETWORK_MODEL_H
