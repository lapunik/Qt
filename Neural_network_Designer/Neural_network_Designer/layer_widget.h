#ifndef LAYER_WIDGET_H
#define LAYER_WIDGET_H

#include <QWidget>
#include <QString>
#include <QVBoxLayout>
#include <QLabel>
#include <QVector>
#include "button_roundted.h"
#include <neural_network_model.h>
#include <QMessageBox>
#include <neuron.h>
#include <neuron_settings_window.h>

class Layer_widget : public QWidget
{
    Q_OBJECT
public:
    explicit Layer_widget(QWidget *parent = nullptr);
    explicit Layer_widget(QList<Neuron::func> *neuron,QWidget *parent = nullptr);
    explicit Layer_widget(bool input, bool output,QWidget *parent = nullptr);
    virtual ~Layer_widget();

    std::vector<function> get_neurons();
    QVector<Neuron*> *neurons = nullptr;

private:

    QVBoxLayout *mp_main_layout = nullptr; // přidání layoutu
    QVBoxLayout *mp_inner_layout = nullptr; // přidání layoutu
    QLabel *mp_label = nullptr;

    Button_roundted *mp_add_neuron_buttton = nullptr;
    Button_roundted *mp_remove_neuron_buttton = nullptr;

    function neuron_to_function(Neuron *n);

    bool output_layer = false;
    bool input_layer = false;

    void set_widget();

private slots:

    void add_widget();
    void add_widget(Neuron::func fun);
    void remove_widget();

    void choose_function(Neuron *n);

    //void clear_layout(QLayout* layout, bool deleteWidgets = true);

signals:

    void redraw();

};

#endif // LAYER_WIDGET_H
