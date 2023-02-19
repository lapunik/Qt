#include "neural_network_model.h"

Neural_network_model::Neural_network_model(std::vector<std::vector<function>> net, Model_settings setting, QObject *parent) : QObject{parent}
{
    x.resize(setting.input_data.size()-1);

    for(int j = 0; j < static_cast<int>(x.size()); j++)
    {
        for(int i = 0; i < setting.input_data.at(j).size(); i++)
        {
            x.at(j).push_back(setting.input_data.at(j).at(i));
        }
    }

    double tau;
    if (setting.max_tolerance_bool)
    {
        tau = setting.max_tolerance;
    }
    else
    {
        tau = 0;
    }

    int N;
    if (setting.max_cycles_bool)
    {
        N = setting.max_cycles;
    }
    else
    {
        N = std::numeric_limits< int >::max();
    }

    std::vector<std::vector<std::vector<double>>> koef;

    for(int i = 0; i < setting.input_data.last().size() ; i++)
    {
        y0.push_back(setting.input_data.last().at(i));
    }

    if(setting.regularization_bool && (setting.regularization_cycles > 0))
    {
        setting.regularization_from = -setting.regularization_from;
        setting.regularization_to = -setting.regularization_to;

        double temp = 0;
        double from_to_diff = static_cast<double>(setting.regularization_from-setting.regularization_to);

        if(setting.regularization_cycles == 1)
        {
            regularization_range.push_back(pow(10,(-setting.regularization_from)));
        }
        else
        {
            for(int i = 0;i < setting.regularization_cycles; i++)
            {
                temp = static_cast<double>(setting.regularization_from) - (static_cast<double>(i)*(from_to_diff/(static_cast<double>(setting.regularization_cycles-1))));

                regularization_range.push_back(pow(10,(-temp)));

            }
        }
    }
    else
    {
        regularization_range.push_back(0);
    }

    for (int i = 0; i < static_cast<int>(regularization_range.size()); i++)
    {
        koef = initialize_koeficients(net, x.size(), 1.0, 1.0);

        if(setting.algo == Model_settings::ADAM)
        {
            koef = ADAM(y0, x, net, koef, setting.learning_coeff, tau, N,regularization_range.at(i));
        }
        else if(setting.algo == Model_settings::moment)
        {
            // TODO Moment
            koef = ADAM(y0, x, net, koef, setting.learning_coeff, tau, N,regularization_range.at(i));
        }
        else if(setting.algo == Model_settings::none)
        {
            // TODO None
            koef = ADAM(y0, x, net, koef, setting.learning_coeff, tau, N,regularization_range.at(i));
        }
        else
        {
            koef = ADAM(y0, x, net, koef, setting.learning_coeff, tau, N,regularization_range.at(i));
        }

        for(int i = 0;i<static_cast<int>(koef.size());i++)
        {
            for(int j = 0;j<static_cast<int>(koef.at(i).size());j++)
            {
                for(int k = 0;k<static_cast<int>(koef.at(i).at(j).size());k++)
                {
                    if(koef.at(i).at(j).at(k) <= 0.01 && koef.at(i).at(j).at(k) >= -0.01)
                    {
                        koef.at(i).at(j).at(k) = 0.0;
                    }
                }
            }
        }

        y = calculate(x, net, koef); // vypočítej y podle současného modelu

        fill_properties(koef);

    }

    std::transform(regularization_range.begin(), regularization_range.end(), regularization_range.begin(), [](double& c) { return std::log10(c); });


    // dodělat mBGD a Moment

    // dodělat stochastic!

    // Tisk času
    //            auto start = std::chrono::high_resolution_clock::now();
    //            auto stop = std::chrono::high_resolution_clock::now();
    //std::cout << "\n\nIt took " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " ms.\n\n";

    // Převod na logaritmickou osu
    //std::transform(regularization_range.begin(), regularization_range.end(), regularization_range.begin(), [](double& c) { return std::log10(c); })

    // dodělat mBGD

    ///// TODO: Vykreslnení grafů? Vypsání koeficientů?
}

Neural_network_model::Neural_network_model(std::vector<std::vector<function>> net, Model_settings setting, std::vector<std::vector<std::vector<std::vector<double>>>> koef_m , QObject *parent) : QObject{parent}
{
    x.resize(setting.input_data.size()-1);

    for(int j = 0; j < static_cast<int>(x.size()); j++)
    {
        for(int i = 0; i < setting.input_data.at(j).size(); i++)
        {
            x.at(j).push_back(setting.input_data.at(j).at(i));
        }
    }

    std::vector<std::vector<std::vector<double>>> koef;

    for(int i = 0; i < setting.input_data.last().size() ; i++)
    {
        y0.push_back(setting.input_data.last().at(i));
    }

    if(setting.regularization_bool)
    {
        setting.regularization_from = -setting.regularization_from;
        setting.regularization_to = -setting.regularization_to;

        double temp = 0;
        double from_to_diff = static_cast<double>(setting.regularization_from-setting.regularization_to);

        for(int i = 0;i < setting.regularization_cycles; i++)
        {
            temp = static_cast<double>(setting.regularization_from) - (static_cast<double>(i)*(from_to_diff/(static_cast<double>(setting.regularization_cycles-1))));

            regularization_range.push_back(pow(10,(-temp)));
        }
    }
    else
    {
        regularization_range.push_back(0);
    }

    for (int i = 0; i < static_cast<int>(regularization_range.size()); i++)
    {

        koef = koef_m.at(i);

        y = calculate(x, net, koef); // vypočítej y podle současného modelu

        fill_properties(koef);

    }

    std::transform(regularization_range.begin(), regularization_range.end(), regularization_range.begin(), [](double& c) { return std::log10(c); });


    // dodělat mBGD a Moment

    // dodělat stochastic!
    // Tisk času
    //            auto start = std::chrono::high_resolution_clock::now();
    //            auto stop = std::chrono::high_resolution_clock::now();
    //std::cout << "\n\nIt took " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " ms.\n\n";

    // Převod na logaritmickou osu
    //std::transform(regularization_range.begin(), regularization_range.end(), regularization_range.begin(), [](double& c) { return std::log10(c); });

    // dodělat mBGD

    ///// TODO: Vykreslnení grafů? Vypsání koeficientů?
}

Neural_network_model::~Neural_network_model()
{

}

double Neural_network_model::id(double x, double x2)
{
    return x;
}
double Neural_network_model::pow2(double x, double x2)
{
    return x * x;
}
double Neural_network_model::pow3(double x, double x2)
{
    return x * x * x;
}
double Neural_network_model::pow4(double x, double x2)
{
    return x * x * x * x;
}
double Neural_network_model::times(double x, double x2)
{
    return x * x2;
}
double Neural_network_model::divide(double x, double x2)
{
    if (x2 <= 0.000000000000001)
    {
        return 0.0;
    }
    else
    {
        return x / x2;
    }


}
double Neural_network_model::sin(double x, double x2)
{
    return std::sin(x);
}
double Neural_network_model::cos(double x, double x2)
{
    return std::cos(x);
}
double Neural_network_model::sigmoid(double x, double x2)
{
    return (1 / (1 + exp(-x)));
}
double Neural_network_model::n_sigmoid(double x, double x2)
{
    return (2 / (1 + exp(-x))) - 1;
}
double Neural_network_model::tanh(double x, double x2)
{
    return std::tanh(x);
}
double Neural_network_model::f_sigmoid(double x, double x2)
{
    return (x / (1 + abs(x)));
}
double Neural_network_model::heaviside(double x, double x2)
{
    if (x < 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
double Neural_network_model::signum(double x, double x2)
{
    if (x < 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
double Neural_network_model::p_id(double x, double x2)
{
    if (x < 0)
    {
        return 0;
    }
    else
    {
        return x;
    }
}
double Neural_network_model::sat(double x, double x2)
{
    if (x < -1)
    {
        return -1;
    }
    else if (x > 1)
    {
        return 1;
    }
    else
    {
        return x;
    }
}
double Neural_network_model::p_sat(double x, double x2)
{
    if (x < 0)
    {
        return 0;
    }
    else if (x > 1)
    {
        return 1;
    }
    else
    {
        return x;
    }
}
double Neural_network_model::rad(double x, double x2)
{
    return (1 / (std::pow(exp(1), pow2(x, 0))));
}

double Neural_network_model::mse(std::vector<double> y0, std::vector<double> y1)
{
    std::vector<double> E(y0.size());

    std::transform(y0.begin(), y0.end(), y1.begin(), E.begin(), [](double& a, double& b) { return std::pow(a - b, 2); });

    return (std::accumulate(E.begin(), E.end(), 0.0) / E.size())/y0.size();
}
std::vector<std::vector<std::vector<double>>> Neural_network_model::initialize_koeficients(std::vector<std::vector<function>> net, int inputs = 1 , double w_val = 1.0, double b_val = 1.0)
{
    std::vector<std::vector<double>> w(net.size());
    std::vector<std::vector<double>> b(net.size());

    int net_size = net.at(0).size();

    for (int n = 0; n < net_size; n++)
    {
        for (int i = 0; i < inputs; i++)
        {
            try
            {
                if (((net.at(0).at(n) == Neural_network_model::times) || (net.at(0).at(n) == Neural_network_model::divide))&&(i==0))
                {
                    net_size = net_size + 1;
                }
            }
            catch (...) {}

            w.at(0).push_back((w_val));
        }
    }

    for (int l = 0; l < static_cast<int>(net.size()); l++)
    {

        for (int n = 0; n < static_cast<int>(net.at(l).size()); n++)
        {
            b.at(l).push_back(b_val);
        }

        if (l != static_cast<int>(net.size() - 1))
        {

            net_size = net.at(l).size() * net.at(l + 1).size();


            for (int n = 0; n < net_size; n++)
            {
                try
                {
                    if ((net.at(l + 1).at(n) == Neural_network_model::times) || (net.at(l + 1).at(n) == Neural_network_model::divide))
                    {
                        net_size = net_size + net.at(l).size();
                    }
                }
                catch (...) {}

                w.at(l + 1).push_back(w_val);
            }
        }
    }

    return std::vector<std::vector<std::vector<double>>>{w, b};
}
std::vector<std::vector<std::vector<double>>> Neural_network_model::initialize_random_koeficients(std::vector<std::vector<function>> net, int inputs = 1, double min = 0.0, double max = 0.1)
{
    std::vector<std::vector<double>> w(net.size());
    std::vector<std::vector<double>> b(net.size());

    int net_size = net.at(0).size();

    std::uniform_real_distribution<double> random(min, max);
    std::default_random_engine rng;

    for (int n = 0; n < net_size; n++)
    {
        for (int i = 0; i < inputs; i++)
        {
            try
            {
                if (((net.at(0).at(n) == Neural_network_model::times) || (net.at(0).at(n) == Neural_network_model::divide)) && (i == 0))
                {
                    net_size = net_size + 1;
                }
            }
            catch (...) {}

            w.at(0).push_back((random(rng)));
        }
    }

    for (int l = 0; l < static_cast<int>(net.size()); l++)
    {

        for (int n = 0; n < static_cast<int>(net.at(l).size()); n++)
        {
            b.at(l).push_back(random(rng));
        }

        if (l != static_cast<int>(net.size()) - 1)
        {

            net_size = net.at(l).size() * net.at(l + 1).size();


            for (int n = 0; n < net_size; n++)
            {
                try
                {
                    if ((net.at(l + 1).at(n) == Neural_network_model::times) || (net.at(l + 1).at(n) == Neural_network_model::divide))
                    {
                        net_size = net_size + net.at(l).size();
                    }
                }
                catch (...) {}

                w.at(l + 1).push_back(random(rng));
            }
        }
    }

    return std::vector<std::vector<std::vector<double>>>{w, b};
}
double Neural_network_model::calculate(function f, double x, double x2)
{
    return f(x, x2);
}
double Neural_network_model::calculate(std::vector<function> functions, double x, double x2)
{
    int i = 0;
    for (auto element : functions)
    {
        x = calculate(element, x, x2);
        i++;
    }

    return x;
}
std::vector<double> Neural_network_model::calculate(function f, std::vector<double> x, std::vector<double> x2)
{
    for (int i = 0; i < static_cast<int>(x.size()); i++)
    {
        x.at(i) = calculate(f, x.at(i), x2.at(i));
    }

    return x;
}
std::vector<double> Neural_network_model::calculate(std::vector<function> functions, std::vector<double> x, std::vector<double> x2)
{
    for (int i = 0; i < static_cast<int>(x.size()); i++)
    {
        x.at(i) = calculate(functions, x.at(i), x2.at(i));
    }

    return x;
}
std::vector<double> Neural_network_model::calculate(std::vector<double> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef)
{
    std::vector<std::vector<std::vector<double>>> results(net.size() + 1);

    results.at(0).resize(1); // jedna, protože jeden vstup, kdybych chtěl více vstupů, musím to zde změnit
    results.at(0).at(0) = x;

    double w;
    double b;

    std::vector<double> im_results;

    int koef_shift = 0; // pokud mám funcki násobení nebo dělení, tak už nesedí velikost vektoru result s koef, to znamená že musím
    std::vector<double> two_imput_results;


    //kam:        results.at(l + 1).at(nl2)
    //z:          results.at(l).at(nl1)
    //funkce:     net.at(l).at(nl2)
    //w:          koef.at(0).at(l).at((nl2 * results.at(l).size()) + nl1)
    //b:          koef.at(1).at(l).at(nl2))

    for (int l = 0; l < static_cast<int>(net.size()); l++)
    {
        results.at(l + 1).resize(net.at(l).size());

        koef_shift = 0;

        for (int nl2 = 0; nl2 < static_cast<int>(results.at(l + 1).size()); nl2++) // projed celou naslednou vrstvu
        {
            results.at(l + 1).at(nl2) = results.at(l).at(0);

            w = (koef.at(0).at(l).at(((nl2 + koef_shift) * results.at(l).size())));

            std::transform(results.at(l + 1).at(nl2).begin(), results.at(l + 1).at(nl2).end(), results.at(l + 1).at(nl2).begin(), [w](double& c) { return c * w; }); // první sčítanec
            // vynásobení koefiicentem w

            for (int nl1 = 1; nl1 < static_cast<int>(results.at(l).size()); nl1++) // projet celou predchozi vrstvu
            {
                w = koef.at(0).at(l).at(((nl2 + koef_shift) * results.at(l).size()) + nl1);

                im_results = results.at(l).at(nl1);

                std::transform(im_results.begin(), im_results.end(), im_results.begin(), [w](double& c) { return c * w; }); // zbytek sčítanců
                // vynásobení koefiicentem w

                std::transform(results.at(l + 1).at(nl2).begin(), results.at(l + 1).at(nl2).end(), im_results.begin(), results.at(l + 1).at(nl2).begin(), std::plus<double>());

            }

            if ((net.at(l).at(nl2) == Neural_network_model::times) || (net.at(l).at(nl2) == Neural_network_model::divide))
            {
                koef_shift++;

                two_imput_results = results.at(l).at(0);

                w = (koef.at(0).at(l).at((nl2 + koef_shift) * results.at(l).size()));

                std::transform(two_imput_results.begin(), two_imput_results.end(), two_imput_results.begin(), [w](double& c) { return c * w; }); // první sčítanec
                // vynásobení koefiicentem w

                for (int nl1 = 1; nl1 < static_cast<int>(results.at(l).size()); nl1++) // projet celou predchozi vrstvu
                {
                    w = koef.at(0).at(l).at(((nl2 + koef_shift) * results.at(l).size()) + nl1);

                    im_results = results.at(l).at(nl1);

                    std::transform(im_results.begin(), im_results.end(), im_results.begin(), [w](double& c) { return c * w; }); // zbytek sčítanců
                    // vynásobení koefiicentem w

                    std::transform(two_imput_results.begin(), two_imput_results.end(), im_results.begin(), two_imput_results.begin(), std::plus<double>());

                }

                results.at(l + 1).at(nl2) = calculate(net.at(l).at(nl2), results.at(l + 1).at(nl2), two_imput_results);

                b = koef.at(1).at(l).at(nl2);

                std::transform(results.at(l + 1).at(nl2).begin(), results.at(l + 1).at(nl2).end(), results.at(l + 1).at(nl2).begin(), [b](double& c) { return c + b; });
                // přičtení koeficientu b

            }
            else
            {
                b = koef.at(1).at(l).at(nl2);

                std::transform(results.at(l + 1).at(nl2).begin(), results.at(l + 1).at(nl2).end(), results.at(l + 1).at(nl2).begin(), [b](double& c) { return c + b; });
                // přičtení koeficientu b

                results.at(l + 1).at(nl2) = calculate(net.at(l).at(nl2), results.at(l + 1).at(nl2), results.at(l + 1).at(nl2));
            }


        }
    }

    return results.at(results.size() - 1).at(0);
}
std::vector<double> Neural_network_model::calculate(std::vector<std::vector<double>> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef)
{
    std::vector<std::vector<std::vector<double>>> results(net.size() + 1);

    results.at(0).resize(x.size()); // jedna, protože jeden vstup, kdybych chtěl více vstupů, musím to zde změnit
    results.at(0) = x;

    double w;
    double b;

    std::vector<double> im_results;

    int koef_shift = 0; // pokud mám funcki násobení nebo dělení, tak už nesedí velikost vektoru result s koef, to znamená že musím
    std::vector<double> two_imput_results;


    //kam:        results.at(l + 1).at(nl2)
    //z:          results.at(l).at(nl1)
    //funkce:     net.at(l).at(nl2)
    //w:          koef.at(0).at(l).at((nl2 * results.at(l).size()) + nl1)
    //b:          koef.at(1).at(l).at(nl2))

    for (int l = 0; l < static_cast<int>(net.size()); l++)
    {
        results.at(l + 1).resize(net.at(l).size());

        koef_shift = 0;

        for (int nl2 = 0; nl2 < static_cast<int>(results.at(l + 1).size()); nl2++) // projed celou naslednou vrstvu
        {
            results.at(l + 1).at(nl2) = results.at(l).at(0);

            w = (koef.at(0).at(l).at(((nl2 + koef_shift) * results.at(l).size())));

            std::transform(results.at(l + 1).at(nl2).begin(), results.at(l + 1).at(nl2).end(), results.at(l + 1).at(nl2).begin(), [w](double& c) { return c * w; }); // první sčítanec
            // vynásobení koefiicentem w

            for (int nl1 = 1; nl1 < static_cast<int>(results.at(l).size()); nl1++) // projet celou predchozi vrstvu
            {
                w = koef.at(0).at(l).at(((nl2 + koef_shift) * results.at(l).size()) + nl1);

                im_results = results.at(l).at(nl1);

                std::transform(im_results.begin(), im_results.end(), im_results.begin(), [w](double& c) { return c * w; }); // zbytek sčítanců
                // vynásobení koefiicentem w

                std::transform(results.at(l + 1).at(nl2).begin(), results.at(l + 1).at(nl2).end(), im_results.begin(), results.at(l + 1).at(nl2).begin(), std::plus<double>());

            }

            if ((net.at(l).at(nl2) == Neural_network_model::times) || (net.at(l).at(nl2) == Neural_network_model::divide))
            {
                koef_shift++;

                two_imput_results = results.at(l).at(0);

                w = (koef.at(0).at(l).at((nl2 + koef_shift) * results.at(l).size()));

                std::transform(two_imput_results.begin(), two_imput_results.end(), two_imput_results.begin(), [w](double& c) { return c * w; }); // první sčítanec
                // vynásobení koefiicentem w

                for (int nl1 = 1; nl1 < static_cast<int>(results.at(l).size()); nl1++) // projet celou predchozi vrstvu
                {
                    w = koef.at(0).at(l).at(((nl2 + koef_shift) * results.at(l).size()) + nl1);

                    im_results = results.at(l).at(nl1);

                    std::transform(im_results.begin(), im_results.end(), im_results.begin(), [w](double& c) { return c * w; }); // zbytek sčítanců
                    // vynásobení koefiicentem w

                    std::transform(two_imput_results.begin(), two_imput_results.end(), im_results.begin(), two_imput_results.begin(), std::plus<double>());

                }

                results.at(l + 1).at(nl2) = calculate(net.at(l).at(nl2), results.at(l + 1).at(nl2), two_imput_results);

                b = koef.at(1).at(l).at(nl2);

                std::transform(results.at(l + 1).at(nl2).begin(), results.at(l + 1).at(nl2).end(), results.at(l + 1).at(nl2).begin(), [b](double& c) { return c + b; });
                // přičtení koeficientu b

            }
            else
            {
                b = koef.at(1).at(l).at(nl2);

                std::transform(results.at(l + 1).at(nl2).begin(), results.at(l + 1).at(nl2).end(), results.at(l + 1).at(nl2).begin(), [b](double& c) { return c + b; });
                // přičtení koeficientu b

                results.at(l + 1).at(nl2) = calculate(net.at(l).at(nl2), results.at(l + 1).at(nl2), results.at(l + 1).at(nl2));
            }


        }
    }

    return results.at(results.size() - 1).at(0);
}
double Neural_network_model::derivate(function f, double x, double x2)
{
    return (calculate(f, x + 0.0000000000001, x2) - calculate(f, x, x2)) / 0.0000000000001;
}
double Neural_network_model::derivate(std::vector<function> functions, double x, double x2)
{
    return (calculate(functions, x + 0.0000000000001, x2) - calculate(functions, x, x2)) / 0.0000000000001;
}
std::vector<double> Neural_network_model::derivate(function f, std::vector<double> x, std::vector<double> x2)
{
    for (int i = 0; i < x.size(); i++)
    {
        x.at(i) = derivate(f, x.at(i), x2.at(i));
    }

    return x;
}
std::vector<double> Neural_network_model::derivate(std::vector<function> functions, std::vector<double> x, std::vector<double> x2)
{
    for (int i = 0; i < x.size(); i++)
    {
        x.at(i) = derivate(functions, x.at(i), x2.at(i));
    }

    return x;
}

double Neural_network_model::derivate_mse(std::vector<double> y0, std::vector<std::vector<double>> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, int t, int l, int n, double lambda = 0.0)
{
    double koef_sum = 0;

    for (int k = 0; k < static_cast<int>(koef.size()); k++)
    {
        for (int j = 0; j < static_cast<int>(koef.at(k).size()); j++)
        {
            for (int i = 0; i < static_cast<int>(koef.at(k).at(j).size()); i++)
            {
                koef_sum += abs(koef.at(k).at(j).at(i));
            }
        }
    }

    double e = mse(y0, calculate(x, net, koef)) + (lambda * koef_sum);

    double h = 0.000000000001;

    koef.at(t).at(l).at(n) = koef.at(t).at(l).at(n) + h;

    double e_h = mse(y0, calculate(x, net, koef)) + (lambda * (koef_sum + h));

    return ((e_h - e) / h);
}
std::vector<std::vector<std::vector<double>>> Neural_network_model::ADAM(std::vector<double> y0, std::vector<std::vector<double>> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, double alpha, double tau, int N, double lambda)
{

    double d_koef = 0;
    double max_d_koef;

    double epsilon = 10e-8;
    double beta1 = 0.9;
    double beta2 = 0.999;
    double beta1_1 = 1 - beta1;
    double beta2_1 = 1 - beta2;

    std::vector<std::vector<std::vector<double>>>  m = initialize_koeficients(net, x.size(), 1.0, 1.0);
    std::vector<std::vector<std::vector<double>>>  v = initialize_koeficients(net, x.size(), 1.0, 1.0);

    for (int i = 0; i < N; i++)
    {
        max_d_koef = 0;

        for (int wb = 0; wb < static_cast<int>(koef.size()); wb++)
        {
            for (int l = 0; l < static_cast<int>(koef.at(wb).size()); l++)
            {
                for (int n = 0; n < static_cast<int>(koef.at(wb).at(l).size()); n++) // projed celou naslednou verstvu
                {
                    d_koef = derivate_mse(y0, x, net, koef, wb, l, n, lambda);

                    m.at(wb).at(l).at(n) = (beta1 * m.at(wb).at(l).at(n)) + (beta1_1)*d_koef;
                    v.at(wb).at(l).at(n) = (beta2 * v.at(wb).at(l).at(n)) + ((beta2_1)*(Neural_network_model::pow2(d_koef, 0)));

                    koef.at(wb).at(l).at(n) = koef.at(wb).at(l).at(n) - ((alpha * m.at(wb).at(l).at(n) / (1 - pow(beta1, i + 1))) / (std::sqrt(v.at(wb).at(l).at(n) / (1 - pow(beta2, i + 1))) + epsilon));

                    if (std::abs(max_d_koef) < std::abs(d_koef))
                    {
                        max_d_koef = d_koef;
                    }

                }
            }
        }

        if (std::abs(max_d_koef) < tau)
        {
            err.push_back(std::abs(max_d_koef));
            itt.push_back(i);
            break;
        }

    }

    if (std::abs(max_d_koef) > tau)
    {
        err.push_back(std::abs(max_d_koef));
        itt.push_back(N);
    }

    return koef;
}
std::vector<std::vector<std::vector<double>>> Neural_network_model::stochastic_ADAM(std::vector<double> y0, std::vector<std::vector<double>> x, std::vector<std::vector<function>> net, std::vector<std::vector<std::vector<double>>> koef, double alpha, double tau, int N, double ratio, double lambda = 0.0)
{
    std::random_device dev;
    std::mt19937 rng(dev());


    for (int j = 0; j < x.size(); j++)
    {
        for (int i = 0; i < x.at(j).size()* (1 - ratio); i++)
        {

            std::uniform_int_distribution<std::mt19937::result_type> random(0, x.at(j).size() - 1);

            int q = random(rng);

            x.at(j).erase(x.at(j).begin() + q);
            y0.erase(y0.begin() + q);

        }
    }

    return ADAM(y0, x, net, koef, alpha, tau, N, lambda);
}
std::vector<int> Neural_network_model::change_color(std::vector<int> color)
{
    char c = (color.at(0)) | (color.at(1) << 1) | (color.at(2) << 2);
    c++;
    color.at(0) = c & 0x1 ? 1 : 0, color.at(1) = c & 0x2 ? 1 : 0, color.at(2) = c & 0x4 ? 1 : 0;

    return color;
}
void Neural_network_model::fill_properties(std::vector<std::vector<std::vector<double>>> koef)
{
    Y.push_back(y);
    MSE.push_back(mse(y0, y)); // výpočet pro vytvoření grafu vývoje chyby

    int NonZC_temp = 0;

    for(int i = 0;i<static_cast<int>(koef.size());i++)
    {
        for(int j = 0;j<static_cast<int>(koef.at(i).size());j++)
        {
            for(int k = 0;k<static_cast<int>(koef.at(i).at(j).size());k++)
            {
                if(koef.at(i).at(j).at(k) != 0.0)
                {
                    NonZC_temp++;
                }
            }
        }
    }

    KOEF.push_back(koef);
    NonZC.push_back(static_cast<double>(NonZC_temp));
}

std::string Neural_network_model::function_to_string(function f)
{

    if(f == id)
    {
        return "id";
    }
    else if(f == pow2)
    {
        return "pow2";
    }
    else if(f == pow3)
    {
        return "pow3";
    }
    else if(f == pow4)
    {
        return "pow4";
    }
    else if(f == times)
    {
        return "tim";
    }
    else if(f == divide)
    {
        return "div";
    }
    else if(f == sin)
    {
        return "sin";
    }
    else if(f == cos)
    {
        return "cos";
    }
    else if(f == sigmoid)
    {
        return "sig";
    }
    else if(f == n_sigmoid)
    {
        return "n_sig";
    }
    else if(f == tanh)
    {
        return "tanh";
    }
    else if(f == f_sigmoid)
    {
        return "f_sig";
    }
    else if(f == heaviside)
    {
        return "hea";
    }
    else if(f == signum)
    {
        return "sign";
    }
    else if(f == p_id)
    {
        return "p_id";
    }
    else if(f == sat)
    {
        return "sat";
    }
    else if(f == p_sat)
    {
        return "p_sat";
    }
    else if(f == rad)
    {
        return "rad";
    }
    else
    {
        return "error";
    }
}
function Neural_network_model::string_to_function(std::string f)
{

    if(f == "id")
    {
        return id;
    }
    else if(f == "pow2")
    {
        return pow2;
    }
    else if(f == "pow3")
    {
        return pow3;
    }
    else if(f == "pow4")
    {
        return pow4;
    }
    else if(f == "tim")
    {
        return times;
    }
    else if(f == "div")
    {
        return divide;
    }
    else if(f == "sin")
    {
        return sin;
    }
    else if(f == "cos")
    {
        return cos;
    }
    else if(f == "sig")
    {
        return sigmoid;
    }
    else if(f == "n_sig")
    {
        return n_sigmoid;
    }
    else if(f == "tanh")
    {
        return tanh;
    }
    else if(f == "f_sig")
    {
        return f_sigmoid;
    }
    else if(f == "hea")
    {
        return heaviside;
    }
    else if(f == "sign")
    {
        return signum;
    }
    else if(f == "p_id")
    {
        return p_id;
    }
    else if(f == "sat")
    {
        return sat;
    }
    else if(f == "p_sat")
    {
        return p_sat;
    }
    else if(f == "rad")
    {
        return rad;
    }
    else
    {
        return id;
    }
}



