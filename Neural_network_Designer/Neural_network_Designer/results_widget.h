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

    enum graph_function
    {
        g_all,
        g_best,
        g_parret,
        g_mse,
        g_NonZC
    };

    QHBoxLayout *main_H_layout = nullptr;
    QVBoxLayout *main_V_layout = nullptr;
    QHBoxLayout *output_layout = nullptr;
    QHBoxLayout *control_layout = nullptr;
    QHBoxLayout *control_input_layout = nullptr;
    QVBoxLayout *graph_chosing = nullptr;
    QHBoxLayout *best_layout = nullptr;
    QVBoxLayout *graph_V_layout = nullptr;

    QPushButton *all = nullptr;
    QPushButton *best = nullptr;
    QPushButton *parret = nullptr;
    QPushButton *reg_mse = nullptr;
    QPushButton *reg_NonZC = nullptr;

    QPushButton *download = nullptr;
    QPushButton *best_button = nullptr;
    QLabel *best_label = nullptr;
    QPushButton *left = nullptr;
    QPushButton *right = nullptr;
    QLabel *counter = nullptr;
    QPushButton *left_input = nullptr;
    QPushButton *right_input = nullptr;
    QLabel *counter_input = nullptr;
    QLabel *graph_l = nullptr;

    ScatterPlotSettings* graph_settings;
    QPixmap graph;
    int best_index = 0;
    int current_index = 0;
    int current_input = 0;

    graph_function current_g = g_all;

    Neural_network_model* model = nullptr;

    void redraw();
    void set_window();
    void set_arrows(bool enable, QPushButton* arrow);

    int search_best();

    std::vector<int> change_color(std::vector<int> color);

signals:

    void save();

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void download_clicked();

    void all_clicked();
    void best_clicked();
    void parret_clicked();
    void reg_mse_clicked();
    void reg_NonZC_clicked();
    void arrow_clicked();
    void arrowl_clicked();
    void arrow_input_clicked();
    void arrowl_input_clicked();
    void best_button_clicked();

public slots:
    //void load_img_ref(RGBABitmapImageReference ref);
    void load_model(Neural_network_model *nn_model);
};

#endif // RESULTS_WIDGET_H
