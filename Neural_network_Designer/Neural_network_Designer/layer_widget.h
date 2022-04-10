#ifndef LAYER_WIDGET_H
#define LAYER_WIDGET_H

#include <QWidget>
#include <QString>
#include <QVBoxLayout>
#include <QLabel>
#include <QCalendarWidget>

#include "button_roundted.h"

class Layer_widget : public QWidget
{
    Q_OBJECT
public:
    explicit Layer_widget(QWidget *parent = nullptr);
    virtual ~Layer_widget();

private:

    QVBoxLayout *mp_main_layout = nullptr; // přidání layoutu
    QVBoxLayout *mp_inner_layout = nullptr; // přidání layoutu
    QLabel *mp_label = nullptr;

    Button_roundted *mp_add_neuron_buttton = nullptr;


signals:

};

#endif // LAYER_WIDGET_H
