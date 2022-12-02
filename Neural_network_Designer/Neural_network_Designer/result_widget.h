#ifndef RESULT_WIDGET_H
#define RESULT_WIDGET_H

#include <QWidget>
#include <QTabWidget>
#include <QMessageBox>
#include "layer_widget.h"
#include "neural_network_model.h"
#include "network_widget.h"
#include "settings_widget.h"
#include "results_widget.h"
#include "information_window.h"

class Result_widget : public QWidget
{
    Q_OBJECT
public:
    explicit Result_widget(int id,QWidget *parent = nullptr);
    virtual ~Result_widget();
    void update_ID(int id);
    void load_model(QString file_name);
    void disconnect_save();

private:


    Neural_network_model *nn_model = nullptr;

    QWidget *m_parent = nullptr;

    QHBoxLayout *layout = nullptr;
    QTabWidget *tools = nullptr;
    Network_widget *structure = nullptr;
    Settings_widget *settings = nullptr;
    Results_widget *results = nullptr;

    QString file_name = "";
    int ID = 0;

    void download();
    bool write_file(QString file_name);
    std::vector<std::vector<std::vector<double>>> fill_koeficients(std::vector<std::vector<function>> net, int inputs,std::vector<std::vector<double>> values);


signals:

    void change_name(int id, QString name);
    void redraw();
    void change_block_state(bool state);

private slots:

    void calculate();
    void save_process(bool as, int index);

public slots:

    void change_blockator(bool state);

};

#endif // RESULT_WIDGET_H
