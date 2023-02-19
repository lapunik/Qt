#ifndef RESULTS_WIDGET_H
#define RESULTS_WIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStringList>
#include <QStringListModel>
#include <QScrollBar>
#include <QFileDialog>
#include <QListView>
#include "pbPlots.h"
#include "qlabel90.h"
#include "qlabel0.h"
#include "supportLib.h"
#include "neural_network_model.h"
#include "message_box.h"


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
    QHBoxLayout *download_all_layout = nullptr;
    QHBoxLayout *download_layout = nullptr;
    QHBoxLayout *control_layout = nullptr;
    QHBoxLayout *control_input_layout = nullptr;
    QVBoxLayout *graph_chosing = nullptr;
    QVBoxLayout *graph_V_layout = nullptr;
    QHBoxLayout *graph_l_layout = nullptr;

    QPushButton *all = nullptr;
    QPushButton *best = nullptr;
    QPushButton *parret = nullptr;
    QPushButton *reg_mse = nullptr;
    QPushButton *reg_NonZC = nullptr;


    QPushButton *download = nullptr;
    QPushButton *download_all = nullptr;
    QPushButton *best_button = nullptr;
    QLabel *best_label = nullptr;
    QPushButton *left = nullptr;
    QPushButton *right = nullptr;
    QLabel *counter = nullptr;
    QPushButton *left_input = nullptr;
    QPushButton *right_input = nullptr;
    QLabel *counter_input = nullptr;
    QLabel *graph_l = nullptr;
    QLabel *graph_title = nullptr;
    QLabel0 *graph_x_label = nullptr;
    QLabel90 *graph_y_label = nullptr;

    QComboBox *mp_model_combo = nullptr;
    QListView *mp_coefficients = nullptr;
    void setComboBox(QComboBox *combo, bool disable);

    ScatterPlotSettings* graph_settings = nullptr;
    QPixmap graph;
    int best_index = 0;
    int current_index = 0;
    int current_input = 0;

    bool size_change_blockator = false;

    graph_function current_g = g_all;

    Neural_network_model* model = nullptr;

    void redraw();
    void set_window();
    void set_arrows(bool enable, QPushButton* arrow);
    void set_buttons_size(int h, int w);
    void set_coef_widget();

    void set_button_disable(QPushButton* b,bool disable);
    int search_best();
    void download_func(bool all);
    void set_download(std::string name);

    std::vector<int> change_color(std::vector<int> color);

signals:

    //void save();

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void all_clicked(bool draw= true);
    void best_clicked(bool draw= true);
    void parret_clicked(bool draw= true,bool particular = true);
    void reg_mse_clicked(bool draw= true);
    void reg_NonZC_clicked(bool draw= true);
    void reg_NonZC_clicked2(bool draw= true);
    void arrow_clicked();
    void arrowl_clicked();
    void arrow_input_clicked();
    void arrowl_input_clicked();
    void best_button_clicked();
    void download_clicked();
    void download_all_clicked();
    void comboBox_item_changed(int index);

public slots:

    void load_model(Neural_network_model *nn_model);
    void change_blockator(bool state);
};

#endif // RESULTS_WIDGET_H
