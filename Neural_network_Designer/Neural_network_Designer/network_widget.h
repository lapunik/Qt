#ifndef NETWORK_WIDGET_H
#define NETWORK_WIDGET_H

#include <QWidget>
#include <layer_widget.h>
#include <QVector>
#include "neuron.h"

class Network_widget : public QWidget
{
    Q_OBJECT
public:
    explicit Network_widget(QWidget *parent = nullptr);
    virtual ~Network_widget();

    std::vector<std::vector<function>> get_net();
    int get_number_of_inputs();
    void load_model(std::vector< QList<Neuron::func>*> f);

private:

    QHBoxLayout *layout = nullptr;
    QHBoxLayout *mp_inner_layout = nullptr;

    QVector<Layer_widget*> *layers = nullptr;

    Layer_widget *input_layer = nullptr;
    Layer_widget *output_layer = nullptr;

    Button_roundted *mp_add_layer_buttton = nullptr;
    Button_roundted *mp_remove_layer_buttton = nullptr;

    void redraw();

    bool size_change_blockator = false;

private slots:

    void add_layer();
    void add_layer(QList<Neuron::func> *fun);
    void remove_layer();
    void resize_inner_event();

public slots:

    void change_blockator(bool state);

protected:
    void resizeEvent(QResizeEvent *event);

signals:

};

#endif // NETWORK_WIDGET_H
