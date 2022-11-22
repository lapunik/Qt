#ifndef SETTINGS_WIDGET_H
#define SETTINGS_WIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QFileDialog>
#include <QFile>
#include "model_settings.h"
#include "message_box.h"


class Settings_widget : public QWidget
{
    Q_OBJECT
public:
    explicit Settings_widget(QWidget *parent = nullptr);
    virtual ~Settings_widget();

    Model_settings get_settings();
    int get_num_of_inputs();
    bool is_input_data();
    void load_model(Model_settings sett);

private:

    QString file_name = "";

    QHBoxLayout *main_H_layout = nullptr;
    QVBoxLayout *main_V_layout = nullptr;
    QVBoxLayout *main_V_layout2 = nullptr;
    QHBoxLayout *algorithm_layout = nullptr;
    QHBoxLayout *stochastic_layout = nullptr;
    QHBoxLayout *learning_coef_layout = nullptr;
    QHBoxLayout *max_iterations_layout = nullptr;
    QHBoxLayout *tolerance_layout = nullptr;
    QHBoxLayout *input_data_layout = nullptr;
    QHBoxLayout *regularization_layout = nullptr;
    QHBoxLayout *regularization_setting_iterations_layout = nullptr;
    QHBoxLayout *regularization_setting_iterations_cycles_layout = nullptr;

    QComboBox *algorithm_combo = nullptr;
    QCheckBox *stochastic_check = nullptr;
    QLabel *stochastic_label = nullptr;
    QDoubleSpinBox *stochastic_spin = nullptr;
    QDoubleSpinBox *learning_coef_spin = nullptr;
    QCheckBox *max_iterations_check = nullptr;
    QSpinBox *max_iterations_spin = nullptr;
    QCheckBox *tolerance_check = nullptr;
    QDoubleSpinBox *tolerance_spin = nullptr;
    QPushButton *input_data_button = nullptr;
    QLabel *input_data_label = nullptr;
    QComboBox *regularization_combo = nullptr;
    QCheckBox *regularization_check = nullptr;
    QSpinBox *regularization_spin_from = nullptr;
    QSpinBox *regularization_spin_to = nullptr;
    QLabel *regularization_label_from = nullptr;
    QLabel *regularization_label_to = nullptr;
    QLabel *regularization_label_cycles = nullptr;
    QSpinBox *regularization_spin_cycles = nullptr;

    QPushButton *calculate_button = nullptr;


    void setComboBox(QComboBox *combo, bool disable);
    void setSpinBox(QSpinBox *spin, bool disable);
    void setDoubleSpinBox(QDoubleSpinBox *spin, bool disable);
    void setWindow();
    void input_data_ready();

    Model_settings input_data;


signals:

    void calculate();

private slots:

    void input_data_button_clicked();
    void stochastic_check_clicked(int state);
    void max_iterations_check_clicked(int state);
    void tolerance_check_clicked(int state);
    void regularization_check_clicked(int state);
    void regularization_from_check(int val);
    void regularization_to_check(int val);
    void calculate_button_clicked();
};

#endif // SETTINGS_WIDGET_H
