#ifndef RESULT_WIDGET_H
#define RESULT_WIDGET_H

#include <QWidget>
#include <QTabWidget>
#include "layer_widget.h"
#include "neural_network_model.h"
#include "network_widget.h"
#include "settings_widget.h"
#include "results_widget.h"

class Result_widget : public QWidget
{
    Q_OBJECT
public:
    explicit Result_widget(QWidget *parent = nullptr);
    virtual ~Result_widget();

private:


    Neural_network_model *nn_model = nullptr;

    QHBoxLayout *layout = nullptr;
    QTabWidget *tools = nullptr;
    Network_widget *structure = nullptr;
    Settings_widget *settings = nullptr;
    Results_widget *results = nullptr;



signals:

private slots:

    void calculate();

};

#endif // RESULT_WIDGET_H
