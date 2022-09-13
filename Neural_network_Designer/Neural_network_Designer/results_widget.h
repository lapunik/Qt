#ifndef RESULTS_WIDGET_H
#define RESULTS_WIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "pbPlots.h"
#include "supportLib.h"
#include "neural_network_model.h"


class Results_widget : public QWidget
{
    Q_OBJECT
public:
    explicit Results_widget(QWidget *parent = nullptr);
    virtual ~Results_widget();

private:

    QHBoxLayout *main_H_layout = nullptr;
    QVBoxLayout *main_V_layout = nullptr;
    QHBoxLayout *output_layout = nullptr;
    QHBoxLayout *control_layout = nullptr;

    //QLabel *download_label = nullptr;
    QPushButton *download = nullptr;
    QPushButton *left = nullptr;
    QPushButton *right = nullptr;
    QLabel *counter = nullptr;
    QLabel *graph_l = nullptr;

    QPixmap graph;
    //RGBABitmapImageReference graph_ref;

    Neural_network_model* model;

    void redraw();
    void setWindow();

    std::vector<int> change_color(std::vector<int> color);

signals:

public slots:
    //void load_img_ref(RGBABitmapImageReference ref);
    void load_model(Neural_network_model *nn_model);

};

#endif // RESULTS_WIDGET_H
