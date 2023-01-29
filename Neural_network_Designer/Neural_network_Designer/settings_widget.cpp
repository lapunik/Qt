#include "settings_widget.h"

Settings_widget::Settings_widget(QWidget *parent) : QWidget{parent}
{
    setWindow();

    connect(input_data_button,SIGNAL(clicked()),this,SLOT(input_data_button_clicked()));
    connect(stochastic_check,SIGNAL(stateChanged(int)),this,SLOT(stochastic_check_clicked(int)));
    connect(tolerance_check,SIGNAL(stateChanged(int)),this,SLOT(tolerance_check_clicked(int)));
    connect(max_iterations_check,SIGNAL(stateChanged(int)),this,SLOT(max_iterations_check_clicked(int)));
    connect(regularization_check,SIGNAL(stateChanged(int)),this,SLOT(regularization_check_clicked(int)));
    connect(regularization_spin_from,SIGNAL(valueChanged(int)),this,SLOT(regularization_from_check(int)));
    connect(regularization_spin_to,SIGNAL(valueChanged(int)),this,SLOT(regularization_to_check(int)));


}

Settings_widget::~Settings_widget()
{

    if(main_H_layout != nullptr)
    {
        main_H_layout = nullptr;
    }
    if(main_V_layout != nullptr)
    {
        main_V_layout = nullptr;
    }
    if(main_V_layout2 != nullptr)
    {
        main_V_layout2 = nullptr;
    }
    if(algorithm_layout != nullptr)
    {
        algorithm_layout = nullptr;
    }
    if(stochastic_layout != nullptr)
    {
        stochastic_layout = nullptr;
    }
    if(learning_coef_layout != nullptr)
    {
        learning_coef_layout = nullptr;
    }
    if(max_iterations_layout != nullptr)
    {
        max_iterations_layout = nullptr;
    }
    if(tolerance_layout != nullptr)
    {
        tolerance_layout = nullptr;
    }
    if(input_data_layout != nullptr)
    {
        input_data_layout = nullptr;
    }
    if(regularization_layout != nullptr)
    {
        regularization_layout = nullptr;
    }
    if(regularization_setting_iterations_layout != nullptr)
    {
        regularization_setting_iterations_layout = nullptr;
    }
    if(algorithm_combo != nullptr)
    {
        algorithm_combo = nullptr;
    }
    if(stochastic_check != nullptr)
    {
        stochastic_check = nullptr;
    }
    if(stochastic_spin != nullptr)
    {
        stochastic_spin = nullptr;
    }

}

void Settings_widget::setWindow()
{
    setContentsMargins(0,0,0,0);

    algorithm_layout = new QHBoxLayout();
    algorithm_combo = new QComboBox();
    algorithm_combo->addItem("ADAM");
    algorithm_combo->addItem("Moment");
    algorithm_combo->addItem("None");
    algorithm_combo->setFixedWidth(200);
    setComboBox(algorithm_combo,false);
    algorithm_layout->addWidget(new QLabel("Gradient algorithm: "));
    algorithm_layout->addWidget(algorithm_combo);


    stochastic_layout = new QHBoxLayout();
    stochastic_check = new QCheckBox();
    stochastic_check->setCheckState(Qt::Unchecked);
    stochastic_check->setFixedSize(QSize(20,20));
    stochastic_label = new QLabel("ratio: ");
    stochastic_label->setStyleSheet("QLabel{"
                                    "color: rgb(200, 200, 200);"
                                    "}"
                                    );
    stochastic_label->setFixedWidth(30);
    stochastic_spin = new QDoubleSpinBox();
    stochastic_spin->setValue(0.6);
    stochastic_spin->setMaximum(1);
    stochastic_spin->setSingleStep(0.1);
    stochastic_spin->setFixedWidth(100);
    setDoubleSpinBox(stochastic_spin,true);
    stochastic_layout->addWidget(stochastic_check);
    stochastic_layout->addWidget(new QLabel("Stochastic: "));
    stochastic_layout->addWidget(stochastic_label);
    stochastic_layout->addWidget(stochastic_spin);


    learning_coef_layout = new QHBoxLayout();
    learning_coef_spin = new QDoubleSpinBox();
    learning_coef_spin->setDecimals(4);
    learning_coef_spin->setValue(0.1);
    learning_coef_spin->setSingleStep(0.01);
    learning_coef_spin->setFixedWidth(100);
    setDoubleSpinBox(learning_coef_spin,false);

    learning_coef_layout->addWidget(new QLabel("Learning coefficient: "));
    learning_coef_layout->addWidget(learning_coef_spin);


    max_iterations_layout = new QHBoxLayout();
    max_iterations_check = new QCheckBox();
    max_iterations_check->setCheckState(Qt::Checked);
    max_iterations_check->setFixedSize(QSize(20,20));
    max_iterations_spin = new QSpinBox();
    max_iterations_spin->setMaximum(10000000);
    max_iterations_spin->setValue(3000);
    max_iterations_spin->setSingleStep(100);
    max_iterations_spin->setFixedWidth(100);
    setSpinBox(max_iterations_spin,false);
    max_iterations_layout->addWidget(max_iterations_check);
    max_iterations_layout->addWidget(new QLabel("Maximum number of cycles: "));
    max_iterations_layout->addWidget(max_iterations_spin);


    tolerance_layout = new QHBoxLayout();
    tolerance_check = new QCheckBox();
    tolerance_check->setCheckState(Qt::Checked);
    tolerance_check->setFixedSize(QSize(20,20));
    tolerance_spin = new QDoubleSpinBox();
    tolerance_spin->setDecimals(8);
    tolerance_spin->setSingleStep(0.000001);
    tolerance_spin->setValue(0.00005);
    tolerance_spin->setFixedWidth(100);
    setDoubleSpinBox(tolerance_spin,false);
    tolerance_layout->addWidget(tolerance_check);
    tolerance_layout->addWidget(new QLabel("Maximal tolerance: "));
    tolerance_layout->addWidget(tolerance_spin);


    input_data_layout = new QHBoxLayout();
    input_data_button = new QPushButton();
    input_data_button->setText("  Choose file");
    input_data_button->setFixedWidth(100);
    input_data_button->setIcon(QIcon(":/res/icon/file"));
    input_data_button->setIconSize(QSize(20,20));
    input_data_button->setStyleSheet(QString("QPushButton{"
                                             "background-color: rgba(220, 220, 220, 255);"
                                             "color: black;"
                                             "border: 1px;"
                                             "border-radius: 3px;"
                                             "border-color: rgba(255, 255, 255, 255);"
                                             "}"
                                             "QPushButton:hover"
                                             "{"
                                             "background-color:rgba(200, 200, 200, 255);"
                                             "}"
                                             "QPushButton:pressed"
                                             "{"
                                             "background-color:rgba(150, 150, 150, 255);"
                                             "}"
                                             ));
    input_data_label = new QLabel("*No file uploaded");
    input_data_label->setStyleSheet("QLabel{"
                                    "font: italic;"
                                    "color: rgba(255, 0, 0, 255);"
                                    "}"
                                    );
    input_data_label->setFixedWidth(95);
    input_data_layout->addWidget(new QLabel("Input data: "));
    input_data_layout->addWidget(input_data_button);
    input_data_layout->addWidget(input_data_label);


    regularization_layout = new QHBoxLayout();
    regularization_check = new QCheckBox();
    regularization_check->setCheckState(Qt::Unchecked);
    regularization_check->setFixedSize(QSize(20,20));
    regularization_combo = new QComboBox();
    regularization_combo->addItem("Lasso");
    regularization_combo->setFixedWidth(200);
    setComboBox(regularization_combo,true);


    regularization_layout->addWidget(regularization_check);
    regularization_layout->addWidget(new QLabel("Reguralization: "));
    regularization_layout->addWidget(regularization_combo);


    regularization_setting_iterations_layout = new QHBoxLayout();
    regularization_spin_from = new QSpinBox();
    regularization_spin_from->setMaximum(20);
    regularization_spin_from->setMinimum(-20);
    regularization_spin_from->setValue(-5);
    regularization_spin_from->setPrefix("10^(");
    regularization_spin_from->setSuffix(")");
    setSpinBox(regularization_spin_from,true);
    regularization_label_from = new QLabel("from: ");
    regularization_label_from->setStyleSheet("QLabel{"
                                             "color:rgb(200, 200, 200);"
                                             "}"
                                             );
    regularization_spin_to = new QSpinBox();
    regularization_spin_to->setMaximum(20);
    regularization_spin_to->setMinimum(-20);
    regularization_spin_to->setValue(-1);
    regularization_spin_to->setPrefix("10^(");
    regularization_spin_to->setSuffix(")");
    setSpinBox(regularization_spin_to,true);
    regularization_label_to = new QLabel("to: ");
    regularization_label_to->setStyleSheet("QLabel{"
                                           "color:rgb(200, 200, 200);"
                                           "}"
                                           );
    regularization_setting_iterations_layout->addWidget(regularization_label_from);
    regularization_setting_iterations_layout->addWidget(regularization_spin_from);
    regularization_setting_iterations_layout->addWidget(regularization_label_to);
    regularization_setting_iterations_layout->addWidget(regularization_spin_to);

    regularization_setting_iterations_cycles_layout = new QHBoxLayout();
    regularization_spin_cycles = new QSpinBox();
    regularization_spin_cycles->setMaximum(100000);
    regularization_spin_cycles->setValue(10);
    regularization_spin_cycles->setSingleStep(1);
    regularization_spin_cycles->setFixedWidth(100);
    setSpinBox(regularization_spin_cycles,true);
    regularization_label_cycles = new QLabel("Number of steps: ");
    regularization_label_cycles->setStyleSheet("QLabel{"
                                               "color:rgb(200, 200, 200);"
                                               "}"
                                               );
    regularization_setting_iterations_cycles_layout->addWidget(regularization_label_cycles);
    regularization_setting_iterations_cycles_layout->addWidget(regularization_spin_cycles);


    main_V_layout = new QVBoxLayout();
    main_V_layout->addLayout(input_data_layout);
    main_V_layout->addLayout(algorithm_layout);
    main_V_layout->addLayout(stochastic_layout);
    main_V_layout->addLayout(learning_coef_layout);
    main_V_layout->addLayout(max_iterations_layout);
    main_V_layout->addLayout(tolerance_layout);
    main_V_layout->addLayout(regularization_layout);
    main_V_layout->addLayout(regularization_setting_iterations_layout);
    main_V_layout->addLayout(regularization_setting_iterations_cycles_layout);
    QLabel *ll = new QLabel();
    ll->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    main_V_layout->addWidget(ll);

    QWidget *left_widget = new QWidget();
    left_widget->setLayout(main_V_layout);
    left_widget->setFixedWidth(400);
    left_widget->setStyleSheet("QWidget{"
                               "background-color: rgba(255, 255, 255, 255);"
                               "border-radius: 0px;"
                               "}");

    main_V_layout2 = new QVBoxLayout();
    calculate_button = new QPushButton();
    calculate_button->setDisabled(true);
    calculate_button->setStyleSheet("QPushButton{"
                                    "image: url(:/res/icon/calculate3);"
                                    "}"
                                    "QPushButton:hover{"
                                    "image: url(:/res/icon/calculate3);"
                                    "}"
                                    "QPushButton:pressed{"
                                    "image: url(:/res/icon/calculate3);"
                                    "}"
                                    );
    calculate_button->setIconSize(QSize(100,100));
    calculate_button->setFixedSize(QSize(100,100));
    connect(calculate_button,SIGNAL(clicked()),this,SLOT(calculate_button_clicked()));
    main_V_layout2->addWidget(new QLabel());
    main_V_layout2->addWidget(calculate_button);

    main_H_layout = new QHBoxLayout();
    main_H_layout->addWidget(left_widget);

    main_H_layout->addWidget(new QLabel());

    main_H_layout->addLayout(main_V_layout2);
    setLayout(main_H_layout);
}

void Settings_widget::setComboBox(QComboBox *combo, bool disable)
{

    QString b_color((disable)?"rgb(238, 238, 238)":"rgb(220, 220, 220)");
    QString h_color((disable)?"rgb(238, 238, 238)":"rgb(200, 200, 200)");
    QString color((disable)?"rgb(200, 200, 200)":"rgb(0, 0, 0)");

    combo->setStyleSheet("QComboBox{"
                         "border:none;"
                         "background-color:   " + b_color + ";"
                                                            "color: " + color + ";"
              "padding:5px;"
              "}"
              "QComboBox::drop-down{"
              "    border: none;"
              "    background-color:   " + b_color + ";"
         "    color: rgb(255, 255, 255);"
         "    padding: 0px;"
         "}"
         "QComboBox::down-arrow{"
         "    image: url(:/res/icon/combo" + (disable?"_d":"") + ");"
      "    width: 10px;"
      "    height: 10px;"
      "}"
      "QListView{"
      "    border:none;"
      "    background-color:rgb(240, 240, 240);"
      "    color: " + color + ";"
                     "    show-decoration-selected: 1;"
                     "    margin-left:-10px;"
                     "    padding-left:15px;"
                     "}"
                     "QListView::item:hover"
                     "{"
                     "    background-color:   " + h_color + ";"
               "    border:                 none;"
               "    color:rgb(0, 0, 0);"
               "}"
               "    QComboBox:hover"
               "{"
               "    background-color:   " + h_color + ";"
                                                      "}"
                                                      "}"
                         );
}

void Settings_widget::setSpinBox(QSpinBox *spin, bool disable)
{
    QString b_color((disable)?"rgb(238, 238, 238)":"rgb(220, 220, 220)");
    QString h_color((disable)?"rgb(238, 238, 238)":"rgb(200, 200, 200)");
    QString color((disable)?"rgb(200, 200, 200)":"rgb(0, 0, 0)");

    spin->setDisabled(disable);

    spin->setStyleSheet("QSpinBox{"
                        "border:none;"
                        "background-color:   " + b_color + ";"
                                                           "color: " + color + ";"
             "padding:5px;"
             "}"
             "QSpinBox:hover"
             "{"
             "background-color:   " + h_color + ";"
    "}"
    "QSpinBox::down-arrow"
    "{"
    "image: url(:/res/icon/combo" + (disable?"_d":"") + ");"
                                                        "width: 8px;"
                                                        "height: 8px;"
                                                        "}"
                                                        "QSpinBox::down-button{"
                                                        "    border: none;"
                                                        "    background-color:   " + b_color + ";"
                           "    padding: 0px;"
                           "}"
                           "QSpinBox::up-arrow"
                           "{"
                           "image: url(:/res/icon/combo2" + (disable?"_d":"") + ");"
                                   "width: 8px;"
                                   "height: 8px;"
                                   "}"
                                   "QSpinBox::up-button{"
                                   "    border: none;"
                                   "    background-color:   " + b_color + ";"
        "    padding: 0px;"
        "}"
                        );
}

void Settings_widget::setDoubleSpinBox(QDoubleSpinBox *spin,bool disable)
{
    QString b_color((disable)?"rgb(238, 238, 238)":"rgb(220, 220, 220)");
    QString h_color((disable)?"rgb(238, 238, 238)":"rgb(200, 200, 200)");
    QString color((disable)?"rgb(200, 200, 200)":"rgb(0, 0, 0)");

    spin->setDisabled(disable);

    spin->setStyleSheet("QDoubleSpinBox{"
                        "border:none;"
                        "background-color:   " + b_color + ";"
                                                           "color: " + color + ";"
             "padding:5px;"
             "}"
             "QDoubleSpinBox:hover"
             "{"
             "background-color:   " + h_color + ";"
    "}"
    "QDoubleSpinBox::down-arrow"
    "{"
    "image: url(:/res/icon/combo" + (disable?"_d":"") + ");"
                                                        "width: 8px;"
                                                        "height: 8px;"
                                                        "}"
                                                        "QDoubleSpinBox::down-button{"
                                                        "    border: none;"
                                                        "    background-color:   " + b_color + ";"
                        //"    color: rgb(255, 255, 255);"
                        "    padding: 0px;"
                        "}"
                        "QDoubleSpinBox::up-arrow"
                        "{"
                        "image: url(:/res/icon/combo2" + (disable?"_d":"") + ");"
           "width: 8px;"
           "height: 8px;"
           "}"
           "QDoubleSpinBox::up-button{"
           "    border: none;"
           "    background-color:   " + b_color + ";"
                        //"    color: rgb(255, 255, 255);"
                        "    padding: 0px;"
                        "}"
                        );
}

void Settings_widget::input_data_button_clicked()
{
    file_name = QFileDialog::getOpenFileName(this,"Choose input data file","");

    QFile file(file_name);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        input_data.input_data.clear();

        QStringList list;
        bool is_double = false;
        QVector<double> temp;
        //int col = 0;
        double num = 0.0;
        QTextStream stream(&file);
        while (!stream.atEnd())
        {
            list = stream.readLine().split(',');

            for(int i = 0;i < list.count();i++)
            {
                num = list.at(i).toDouble(&is_double);

                if(is_double)
                {
                    temp.push_back(num);
                }
            }

            input_data.input_data.push_back(temp);
            temp.clear();

        }

    input_data_ready();

    file.close();


    }
}

void Settings_widget::input_data_ready()
{

    bool fault = false;

    int size = input_data.input_data.at(0).size();

    for(int i = 1; i < input_data.input_data.size();i++)
    {
       if(input_data.input_data.at(i).size() != size)
       {
           fault = true;
           break;
       }
    }

    if(fault)
    {

        QString err_text = "";

        if(input_data.input_data.size()==2)
        {
            err_text = ("\n The number of inputs does not match\n  the number of outputs.");
        }
        else
        {
            err_text = ("\n The number of inputs does not match\n  the number of outputs or another input.");
        }

        Message_box* mess = new Message_box(err_text,"Error",this);
        mess->exec();
        if (mess != nullptr)
        {
            delete mess;
        }

        input_data_label->setText("*No file uploaded");
        input_data_label->setStyleSheet("QLabel{"
                                        "font: italic;"
                                        "color: rgba(255, 0, 0, 255);"
                                        "}"
                                        );
        calculate_button->setDisabled(true);
        calculate_button->setStyleSheet("QPushButton{"
                                        "image: url(:/res/icon/calculate3);"
                                        "}"
                                        "QPushButton:hover{"
                                        "image: url(:/res/icon/calculate3);"
                                        "}"
                                        "QPushButton:pressed{"
                                        "image: url(:/res/icon/calculate3);"
                                        "}"
                                        );

    }
    else
    {

    input_data_label->setText("*File uploaded");
    input_data_label->setStyleSheet("QLabel{"
                                    "font: italic;"
                                    "color: rgba(13, 160, 24, 255);"
                                    "}"
                                    );
    calculate_button->setEnabled(true);
    calculate_button->setStyleSheet("QPushButton{"
                                    "image: url(:/res/icon/calculate);"
                                    "}"
                                    "QPushButton:hover{"
                                    "image: url(:/res/icon/calculate2);"
                                    "}"
                                    "QPushButton:pressed{"
                                    "image: url(:/res/icon/calculate3);"
                                    "}"
                                    );
    }

}

void Settings_widget::stochastic_check_clicked(int state)
{
    stochastic_spin->setDisabled(!state);
    setDoubleSpinBox(stochastic_spin,!state);
    QString color((state)?"rgb(0, 0, 0)":"rgb(200, 200, 200)");
    stochastic_label->setStyleSheet("QLabel{"
                                    "color: " + color + ";"
                                                        "}"
                                    );
}

void Settings_widget::max_iterations_check_clicked(int state)
{
    max_iterations_spin->setDisabled(!state);
    setSpinBox(max_iterations_spin,!state);

    if((!state)&&(!tolerance_check->isChecked()))
    {
        tolerance_check->setCheckState(Qt::Checked);
    }
}

void Settings_widget::tolerance_check_clicked(int state)
{
    tolerance_spin->setDisabled(!state);
    setDoubleSpinBox(tolerance_spin,!state);

    if((!state)&&(!max_iterations_check->isChecked()))
    {
        max_iterations_check->setCheckState(Qt::Checked);
    }
}

void Settings_widget::regularization_check_clicked(int state)
{
    regularization_spin_from->setDisabled(!state);
    setSpinBox(regularization_spin_from,!state);

    regularization_spin_to->setDisabled(!state);
    setSpinBox(regularization_spin_to,!state);

    regularization_spin_cycles->setDisabled(!state);
    setSpinBox(regularization_spin_cycles,!state);

    QString color((state)?"rgb(0, 0, 0)":"rgb(200, 200, 200)");
    regularization_label_from->setStyleSheet("QLabel{"
                                             "color: " + color + ";"
                                                                 "}"
                                             );
    regularization_label_to->setStyleSheet("QLabel{"
                                           "color: " + color + ";"
                                                               "}"
                                           );
    regularization_label_cycles->setStyleSheet("QLabel{"
                                               "color: " + color + ";"
                                                                   "}"
                                               );

    regularization_combo->setDisabled(!state);
    setComboBox(regularization_combo,!state);

}

void Settings_widget::regularization_from_check(int val)
{
    if(val >= regularization_spin_to->value())
    {
        regularization_spin_from->setValue(val-1);
    }
}

void Settings_widget::regularization_to_check(int val)
{
    if(val <= regularization_spin_from->value())
    {
        regularization_spin_to->setValue(val+1);
    }
}

Model_settings Settings_widget::get_settings()
{

    input_data.algo = Model_settings::string_to_algorithm(algorithm_combo->currentText());
    input_data.stochastic = stochastic_check->isChecked();
    if(input_data.stochastic)
        input_data.stochastic_ratio = stochastic_spin->value();
    input_data.learning_coeff = learning_coef_spin->value();
    input_data.max_cycles_bool = max_iterations_check->isChecked();
    if(input_data.max_cycles_bool)
        input_data.max_cycles = max_iterations_spin->value();
    input_data.max_tolerance_bool = tolerance_check->isChecked();
    if(input_data.max_tolerance_bool)
        input_data.max_tolerance = tolerance_spin->value();

    input_data.regularization_bool = regularization_check->isChecked();
    if(input_data.regularization_bool)
    {
        input_data.regularization_from = regularization_spin_from->value();
        input_data.regularization_to = regularization_spin_to->value();
        input_data.regularization_cycles = regularization_spin_cycles->value();
        input_data.regularization_type = Model_settings::lasso;
    }

    return input_data;
}

int Settings_widget::get_num_of_inputs()
{
    return input_data.input_data.size()-1;
}

void Settings_widget::calculate_button_clicked()
{
    emit calculate();
}

bool Settings_widget::is_input_data()
{
    if(input_data_label->text() == "*File uploaded")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Settings_widget::load_model(Model_settings sett)
{
    algorithm_combo->setCurrentIndex(Model_settings::algorithm_to_index(sett.algo));
    stochastic_check->setChecked(sett.stochastic);
    stochastic_spin->setValue(sett.stochastic_ratio);
    learning_coef_spin->setValue(sett.learning_coeff);
    max_iterations_check->setChecked(sett.max_cycles_bool);
    max_iterations_spin->setValue(sett.max_cycles);
    tolerance_check->setChecked(sett.max_tolerance_bool);
    tolerance_spin->setValue(sett.max_tolerance);
    regularization_check->setChecked(sett.regularization_bool);
    if(sett.regularization_bool)
    {
        regularization_spin_from->setValue(sett.regularization_from);
        regularization_spin_to->setValue(sett.regularization_to);
        regularization_spin_cycles->setValue(sett.regularization_cycles);
        regularization_combo->setCurrentIndex(Model_settings::regularization_to_index(sett.regularization_type));
    }

    if(sett.input_data.size())
    {
    input_data.input_data = sett.input_data;
    input_data_ready();
    }
}
