#include "results_widget.h"

Results_widget::Results_widget(QWidget *parent) : QWidget{parent}
{
    set_window();
    current_g = g_all;
}

Results_widget::~Results_widget()
{
    if(graph_title != nullptr)
    {
        delete graph_title;
    }
    if(graph_x_label != nullptr)
    {
        delete graph_x_label;
    }
    if(graph_y_label != nullptr)
    {
        delete graph_y_label;
    }
    if(mp_model_combo != nullptr)
    {
        delete mp_model_combo;
    }
    if(mp_coefficients != nullptr)
    {
        delete mp_coefficients;
    }
    if(graph_settings != nullptr)
    {
        delete graph_settings;
    }
    if(graph_l != nullptr)
    {
        delete graph_l;
    }
    if(counter_input != nullptr)
    {
        delete counter_input;
    }
    if(right_input != nullptr)
    {
        delete right_input;
    }
    if(left_input != nullptr)
    {
        delete left_input;
    }
    if(counter != nullptr)
    {
        delete counter;
    }
    if(right != nullptr)
    {
        delete right;
    }
    if(left != nullptr)
    {
        delete left;
    }
    if(best_label != nullptr)
    {
        delete best_label;
    }
    if(best_button != nullptr)
    {
        delete best_button;
    }
    if(download_all != nullptr)
    {
        delete download_all;
    }
    if(download != nullptr)
    {
        delete download;
    }
    if(reg_NonZC != nullptr)
    {
        delete reg_NonZC;
    }
    if(reg_mse != nullptr)
    {
        delete reg_mse;
    }
    if(parret != nullptr)
    {
        delete parret;
    }
    if(best != nullptr)
    {
        delete best;
    }
    if(all != nullptr)
    {
        delete all;
    }
    if(control_input_layout != nullptr)
    {
        delete control_input_layout;
    }
    if(graph_l_layout != nullptr)
    {
        delete graph_l_layout;
    }
    if(graph_V_layout != nullptr)
    {
        delete graph_V_layout;
    }
    if(graph_chosing != nullptr)
    {
        delete graph_chosing;
    }
    if(control_layout != nullptr)
    {
        delete control_layout;
    }
    if(download_layout != nullptr)
    {
        delete download_layout;
    }
    if(download_all_layout != nullptr)
    {
        delete download_all_layout;
    }
    if(main_V_layout != nullptr)
    {
        delete main_V_layout;
    }
    if(main_H_layout != nullptr)
    {
        delete main_H_layout;
    }

}

void Results_widget::set_window()
{
    setContentsMargins(0,0,0,0);

    QWidget *button_widget = new QWidget();
    button_widget->setStyleSheet("QPushButton{"
                                 "background-color: rgba(220, 220, 220, 255);"
                                 "border-radius: 3px;"
                                 "}"
                                 "QPushButton:hover"
                                 "{"
                                 "background-color:rgba(200, 200, 200, 255);"
                                 "}"
                                 "QPushButton:pressed"
                                 "{"
                                 "background-color:rgba(150, 150, 150, 255);"
                                 "}"
                                 );
    button_widget->setFixedWidth(180);
    graph_chosing = new QVBoxLayout();
    all = new QPushButton();
    all->setDisabled(true);
    all->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    all->setIcon(QIcon(":/res/icon/all"));
    connect(all,SIGNAL(clicked()),this,SLOT(all_clicked()));
    best = new QPushButton();
    best->setDisabled(true);
    best->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    best->setIcon(QIcon(":/res/icon/best"));
    connect(best,SIGNAL(clicked()),this,SLOT(best_clicked()));
    parret = new QPushButton();
    parret->setDisabled(true);
    parret->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    parret->setIcon(QIcon(":/res/icon/parret"));
    connect(parret,SIGNAL(clicked()),this,SLOT(parret_clicked()));
    reg_mse = new QPushButton();
    reg_mse->setDisabled(true);
    reg_mse->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    reg_mse->setIcon(QIcon(":/res/icon/mse"));
    connect(reg_mse,SIGNAL(clicked()),this,SLOT(reg_mse_clicked()));
    reg_NonZC = new QPushButton();
    reg_NonZC->setDisabled(true);
    reg_NonZC->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    reg_NonZC->setIcon(QIcon(":/res/icon/NonZC"));
    connect(reg_NonZC,SIGNAL(clicked()),this,SLOT(reg_NonZC_clicked()));
    set_buttons_size(150,60);
    graph_chosing->addWidget(all);
    graph_chosing->addWidget(best);
    graph_chosing->addWidget(parret);
    graph_chosing->addWidget(reg_mse);
    graph_chosing->addWidget(reg_NonZC);
    button_widget->setLayout(graph_chosing);

    download_layout = new QHBoxLayout();
    download = new QPushButton();
    download->setText("  Download");
    download->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    download->setFixedHeight(30);
    download->setIcon(QIcon(":/res/icon/download"));
    download->setIconSize(QSize(20,20));
    set_button_disable(download,true);

    download_all_layout = new QHBoxLayout();
    download_all = new QPushButton();
    download_all->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    download_all->setText("  Download all");
    download_all->setFixedHeight(30);
    download_all->setIcon(QIcon(":/res/icon/download"));
    download_all->setIconSize(QSize(20,20));
    set_button_disable(download_all,true);

    connect(download,SIGNAL(clicked()),this,SLOT(download_clicked()));
    connect(download_all,SIGNAL(clicked()),this,SLOT(download_all_clicked()));

    mp_model_combo = new QComboBox();
    mp_model_combo->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    mp_model_combo->setFixedHeight(30);
    setComboBox(mp_model_combo,true);

    mp_coefficients = new QListView();
    mp_coefficients->setStyleSheet(QString("QListView{"
                                           "color: rgba(0, 0, 0, 255);"
                                           "background-color: rgba(235, 235, 235, 235);"
                                           "border: none;"
                                           "border-radius: 3px;"
                                           "}"));
    mp_coefficients->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QScrollBar *s_b = new QScrollBar();
    s_b->setStyleSheet("QScrollBar:vertical {"
                       "    border: none;"
                       "    background-color: rgba(0, 0, 0, 255);"
                       "}"
                       "QScrollBar::handle:vertical {"
                       "    background: rgba(100, 100, 100, 255);" // jezdec
                       "  border: 1px black;"
                       "  border-radius: 3px;"
                       "}"

                       );
    mp_coefficients->setVerticalScrollBar(s_b);

    mp_coefficients->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding); /////////////////////////// Nejsem si jistý

    best_button = new QPushButton();
    best_button->setText("Best");
    best_button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    set_button_disable(best_button,true);

    best_button->setFixedHeight(30);

    connect(best_button,SIGNAL(clicked()),this,SLOT(best_button_clicked()));

    control_layout = new QHBoxLayout();
    counter = new QLabel("  0/0");
    counter->setFixedWidth(60);
    counter->setAlignment(Qt::AlignCenter);
    left = new QPushButton();
    left->setFixedSize(QSize(40,40));
    set_arrows(false, left);
    connect(left,SIGNAL(clicked()),this,SLOT(arrowl_clicked()));
    right = new QPushButton();
    right->setFixedSize(QSize(40,40));
    set_arrows(false,right);
    connect(right,SIGNAL(clicked()),this,SLOT(arrow_clicked()));
    control_layout->addWidget(left);
    control_layout->addWidget(new QLabel());
    control_layout->addWidget(counter);
    control_layout->addWidget(new QLabel());
    control_layout->addWidget(right);

    download_layout->addWidget(download);
    download_all_layout->addWidget(download_all);

    main_V_layout = new QVBoxLayout();
    main_V_layout->addWidget(new QLabel("Model: "));
    main_V_layout->addWidget(new QLabel("    regularization: "));
    main_V_layout->addWidget(mp_model_combo);
    main_V_layout->addLayout(control_layout);
    main_V_layout->addWidget(best_button);
    main_V_layout->addWidget(new QLabel("Coefficients: "));
    main_V_layout->addWidget(mp_coefficients);
    main_V_layout->addWidget(new QLabel("Output data: "));
    main_V_layout->addLayout(download_layout);
    main_V_layout->addLayout(download_all_layout);

    QWidget *main_widget = new QWidget();
    main_widget->setFixedWidth(200);
    main_widget->setLayout(main_V_layout);
    main_widget->setStyleSheet(QString("QWidget{"
                                       "background-color: rgba(255, 255, 255, 255);"
                                       "border-radius: 0px;"
                                       "}"
                                       "QPushButton{"
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

    graph_V_layout = new QVBoxLayout();
    graph_l_layout = new QHBoxLayout();

    graph_l = new QLabel();
    graph_l->setAlignment(Qt::AlignCenter);
    graph_l->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    graph_y_label = new QLabel90();
    graph_y_label->setText("y");
    graph_y_label->setFixedWidth(15);
    graph_y_label->setStyleSheet(QString("QLabel{"
                                         "font-size: 16px;"
                                         "}"
                                         ));

    graph_l_layout->addWidget(graph_y_label);
    graph_l_layout->addWidget(graph_l);

    control_input_layout = new QHBoxLayout();
    counter_input = new QLabel("   x1");
    counter_input->setFixedWidth(30);
    left_input = new QPushButton();
    left_input->setFixedSize(QSize(40,40));
    set_arrows(false, left_input);
    connect(left_input,SIGNAL(clicked()),this,SLOT(arrowl_input_clicked()));
    right_input = new QPushButton();
    right_input->setFixedSize(QSize(40,40));
    set_arrows(false,right_input);
    connect(right_input,SIGNAL(clicked()),this,SLOT(arrow_input_clicked()));
    QLabel *lll = new QLabel();
    lll->setFixedWidth(70);
    QLabel *ll = new QLabel();
    ll->setFixedWidth(20);
    control_input_layout->addWidget(lll);
    control_input_layout->addWidget(left_input);
    control_input_layout->addWidget(new QLabel());
    control_input_layout->addWidget(counter_input);
    control_input_layout->addWidget(new QLabel());
    control_input_layout->addWidget(right_input);
    control_input_layout->addWidget(ll);
    graph_title = new QLabel();
    graph_title->setText("Title");
    graph_title->setAlignment(Qt::AlignCenter);
    graph_title->setStyleSheet(QString("QLabel{"
                                       "font-size: 22px;"
                                       "}"
                                       ));
    graph_x_label = new QLabel0();
    graph_x_label->setText("x");
    graph_x_label->setFixedHeight(15);
    graph_x_label->setStyleSheet(QString("QLabel{"
                                         "font-size: 16px;"
                                         "}"
                                         ));
    graph_V_layout->addWidget(graph_title);
    graph_V_layout->addLayout(graph_l_layout);
    graph_V_layout->addWidget(graph_x_label);
    graph_V_layout->addLayout(control_input_layout);
    graph_V_layout->setSpacing(0);

    main_H_layout = new QHBoxLayout();
    main_H_layout->addWidget(main_widget);
    main_H_layout->addWidget(button_widget);
    main_H_layout->addLayout(graph_V_layout);
    setLayout(main_H_layout);
}

void Results_widget::load_model(Neural_network_model *nn_model)
{

    model = nn_model;
    all->setDisabled(false);
    set_button_disable(download,false);
    set_button_disable(download_all,false);
    if(nn_model->regularization_range.size() > 1)
    {
        best->setDisabled(false);
        parret->setDisabled(false);
        reg_mse->setDisabled(false);
        reg_NonZC->setDisabled(false);
        setComboBox(mp_model_combo,false);
        QString text;
        QString d_text;
        for(int i = 0; i < static_cast<int>(model->regularization_range.size());i++)
        {
            text = "1e";
            d_text = QString::number(model->regularization_range.at(i),'f',2);
            text.append(d_text);
            mp_model_combo->addItem(tr("%1").arg(text));
        }
        mp_model_combo->setCurrentIndex(current_index);
        connect(mp_model_combo, SIGNAL(currentIndexChanged(int)),this,SLOT(comboBox_item_changed(int)));
    }

    counter->setText(QString("  %1/%2").arg(current_index+1).arg(model->Y.size()));

    set_coef_widget();

    if(model->regularization_range.size() == 1)
    {
        set_button_disable(best_button,true);
    }
    else
    {
        set_button_disable(best_button,false);
        best_index = search_best();
    }
}

void Results_widget::set_buttons_size(int h, int w)
{
    all->setIconSize(QSize(h,w));
    best->setIconSize(QSize(h,w));
    parret->setIconSize(QSize(h,w));
    reg_mse->setIconSize(QSize(h,w));
    reg_NonZC->setIconSize(QSize(h,w));
}

void Results_widget::redraw()
{

    if(size_change_blockator)
    {
        graph_l->setPixmap(*new QPixmap());
        set_buttons_size(1,1);
        return;
    }

    if(graph_settings == nullptr) // ještě není graf
    {
        return;
    }


    set_buttons_size(150,60);

    StringReference* errorMessage = new StringReference();
    RGBABitmapImageReference* imageReference = CreateRGBABitmapImageReference();

    DrawScatterPlotFromSettings(imageReference, graph_settings, errorMessage);

    QImage *img = new QImage(graph_settings->width, graph_settings->height, QImage::Format_RGB16);

    for(int i = 0; i < graph_settings->width; i++)
    {
        for(int u = 0; u < graph_settings->height; u++)
        {
            img->setPixelColor(i, u,QColor(static_cast<int>(255*imageReference->image->x->at(i)->y->at(u)->r),
                                           static_cast<int>(255*imageReference->image->x->at(i)->y->at(u)->g),
                                           static_cast<int>(255*imageReference->image->x->at(i)->y->at(u)->b),
                                           static_cast<int>(255*imageReference->image->x->at(i)->y->at(u)->a))
                               );
        }
    }
    graph = QPixmap::fromImage(*img);
    graph_l->setPixmap(graph);

}

std::vector<int> Results_widget::change_color(std::vector<int> color)
{
    char c = (color.at(0)) | (color.at(1) << 1) | (color.at(2) << 2);
    c++;

    if(c == 7)
        c=1;

    color.at(0) = c & 0x1 ? 1 : 0, color.at(1) = c & 0x2 ? 1 : 0, color.at(2) = c & 0x4 ? 1 : 0;

    return color;
}

void Results_widget::download_clicked()
{

    download_func(false);
}

void Results_widget::download_all_clicked()
{
    download_func(true);
}

void Results_widget::set_download(std::string name)
{
    StringReference* errorMessage = new StringReference();
    RGBABitmapImageReference* imageReference = CreateRGBABitmapImageReference();

    DrawScatterPlotFromSettings(imageReference, graph_settings, errorMessage);

    WriteToFile(ConvertToPNG(imageReference->image), name);
    DeleteImage(imageReference->image);
}

void Results_widget::download_func(bool all)
{

    QString answer = QFileDialog::getExistingDirectory(this, tr("Save File"),QDir::currentPath());

    if(answer == "")
    {
        return;
    }

    QApplication::setOverrideCursor(Qt::WaitCursor);

    std::string path = answer.toStdString();

    if(all)
    {
        int orig_index = current_index;
        int orig_input = current_input;
        std::string name = "";

        for(int i = 0; i < static_cast<int>(model->x.size());i++)
        {
            current_input = i;
            all_clicked(false);

            if(model->regularization_range.size() > 1)
            {
                if(model->x.size() > 1)
                {
                    name = (std::string(path + std::string("/all_models_x") + std::to_string(i+1) + std::string(".png")));
                }
                else
                {
                    name = (path + std::string("/all_models.png"));
                }
            }
            else
            {
                if(model->x.size() > 1)
                {
                    name = (std::string(path + std::string("/model_x") + std::to_string(i+1) + std::string(".png")));
                }
                else
                {
                    name = (path + std::string("/model.png"));
                }
            }

            set_download(name);

        }


        if(model->regularization_range.size() > 1)
        {

            for(int j = 0; j < static_cast<int>(model->x.size());j++)
            {
                current_input = j;
                for(int i = 0; i < static_cast<int>(model->regularization_range.size()); i++)
                {
                    current_index = i;
                    best_clicked(false);
                    set_download(std::string(path + std::string("/model_")) + std::to_string(i) + ((model->x.size()>1)?(std::string("_x") + std::to_string(j)):"") + std::string(".png"));
                }
            }
            parret_clicked(false,false);
            set_download(path + std::string("/parret.png"));
            reg_mse_clicked(false);
            set_download(path + std::string("/reg_to_mse.png"));
            reg_NonZC_clicked(false);
            set_download(path + std::string("/reg_to_value_of_coefficients.png"));

            std::string str;

            int temp_cnt = 1;

            for (int l = 0; l < static_cast<int>(model->KOEF.size()); l++)
            {
                str = "";

                for (int k = 0; k < static_cast<int>(model->KOEF.at(l).size()); k++)
                {
                    for (int j = 0; j < static_cast<int>(model->KOEF.at(l).at(k).size()); j++)
                    {
                        for (int i = 0; i < static_cast<int>(model->KOEF.at(l).at(k).at(j).size()); i++)
                        {
                            str.append((k==0?"w":"b"));
                            str.append(std::to_string(temp_cnt));
                            temp_cnt++;
                            str.append("=");
                            str.append(std::to_string(model->KOEF.at(l).at(k).at(j).at(i)));
                            str.append("\n");
                        }
                    }

                    temp_cnt = 1;
                }

                std::fstream file;
                file.open(path + std::string("/model_") + std::to_string(l) + std::string("_coefficients.txt"), std::ios::out);
                file << str;
                file.close();
            }

            current_index = orig_index;
            current_input = orig_input;

            switch(current_g)
            {
            case g_all:
                all_clicked();
                break;
            case g_best:
                best_clicked();
                break;
            case g_parret:
                parret_clicked();
                break;
            case g_mse:
                reg_mse_clicked();
                break;
            case g_NonZC:
                reg_NonZC_clicked();
                break;
            }

        }

    }
    else
    {
        std::string name;

        switch(current_g)
        {
        case g_all:
            name = path + ((model->regularization_range.size()>1)?(std::string("/all.png")):(std::string("/model1.png")));
            break;
        case g_best:
            name = std::string(path + std::string("/model_")) + std::to_string(current_index) +  std::string(".png");
            break;
        case g_parret:
            name = path + std::string("/parret.png");
            break;
        case g_mse:
            name = path + std::string("/reg_to_mse.png");
            break;
        case g_NonZC:
            name = path + std::string("/reg_to_value_of_coefficients.png");
            break;
        }

        set_download(name);

        std::string str;

        int temp_cnt = 1;

        str = "";

        for (int k = 0; k < static_cast<int>(model->KOEF.at(current_index).size()); k++)
        {
            for (int j = 0; j < static_cast<int>(model->KOEF.at(current_index).at(k).size()); j++)
            {
                for (int i = 0; i < static_cast<int>(model->KOEF.at(current_index).at(k).at(j).size()); i++)
                {
                    str.append((k==0?"w":"b"));
                    str.append(std::to_string(temp_cnt));
                    temp_cnt++;
                    str.append("=");
                    str.append(std::to_string(model->KOEF.at(current_index).at(k).at(j).at(i)));
                    str.append("\n");
                }
            }

            temp_cnt = 1;
        }

        std::fstream file;
        file.open(path + std::string("/coefficients.txt"), std::ios::out);
        file << str;
        file.close();
    }

    QApplication::setOverrideCursor(Qt::ArrowCursor);

    Message_box* mess = new Message_box("\n Output data have been saved.","Information",this);
    mess->exec();
    if (mess != nullptr)
    {
        delete mess;
    }
}

void Results_widget::best_clicked(bool draw)
{

    std::vector<ScatterPlotSeries*> series ;

    std::vector<int> colors{ 0,0,0 };

    if(model != nullptr)
    {
        series.push_back(GetDefaultScatterPlotSeriesSettings());
        series.at(0)->xs = &(model->x.at(current_input));
        series.at(0)->ys = &(model->y0);
        series.at(0)->linearInterpolation = false;
        series.at(0)->pointType = toVector(L"circles");
        series.at(0)->color = CreateRGBColor(colors.at(0), colors.at(1), colors.at(2));

        for(int i = 0;i < current_index+1;i++)
        {
            colors = change_color(colors);
        }

        series.push_back(GetDefaultScatterPlotSeriesSettings());
        series.at(1)->xs = &(model->x.at(current_input));
        series.at(1)->ys = &(model->Y.at(current_index));
        series.at(1)->linearInterpolation = true;
        series.at(1)->pointType = toVector(L"dots");
        //        series.at(1)->lineThickness = 1;
        series.at(1)->lineThickness = (std::ceil((graph_l->width()-20)/1000)+2);
        series.at(1)->color = CreateRGBColor(colors.at(0), colors.at(1), colors.at(2));



    }

    graph_settings = GetDefaultScatterPlotSettings();
    graph_settings->width = graph_l->width()-20;
    graph_settings->height = graph_l->height()-20;
    graph_settings->autoBoundaries = false;

    if(model != nullptr)
    {

        double y_min = model->y0.at(0);
        double y_max = model->y0.at(0);

        for(int i = 1;i < static_cast<int>(model->y0.size());i++)
        {
            if(model->y0.at(i) > y_max)
            {
                y_max = model->y0.at(i);
            }
            if(model->y0.at(i) < y_min)
            {
                y_min = model->y0.at(i);
            }
        }

        y_max += ((y_max < 0?-1:1)*y_max*0.2);
        y_min -= ((y_min < 0?-1:1)*y_min*0.2);
        graph_settings->yMax = y_max;
        graph_settings->yMin = y_min;
        graph_settings->xMin = model->x.at(current_input).at(0);
        graph_settings->xMax = model->x.at(current_input).back();

    }
    else
    {
        graph_settings->autoBoundaries = true;
    }

    graph_settings->autoPadding = true;

    QString text;
    text.append("Model (regularization 1e");
    QString d_text = QString::number(model->regularization_range.at(current_index),'f',3);
    text.append(d_text);
    text.append(")");
    if(current_index == best_index)
    {
        text.append(" - best ");
    }
    graph_title->setText(text);
    graph_x_label->setText("x");
    graph_y_label->setText("y");

    if(model != nullptr)
    {
        for (int i = 0; i < static_cast<int>(series.size()); i++)
        {
            graph_settings->scatterPlotSeries->push_back(series.at(i));
        }
    }

    if(draw)
    {

        current_g = g_best;

        if(model->regularization_range.size() == 1)
        {
            set_arrows(false,left);
            set_arrows(false,right);
        }
        else if(current_index == 0)
        {
            set_arrows(false,left);
            set_arrows(true,right);
        }
        else if(current_index == static_cast<int>(model->regularization_range.size()-1))
        {
            set_arrows(false,right);
            set_arrows(true,left);
        }
        else
        {
            set_arrows(true,right);
            set_arrows(true,left);
        }

        counter->setText(QString("  %1/%2").arg(current_index+1).arg(model->Y.size()));

        if(model->x.size() == 1)
        {
            set_arrows(false,left_input);
            set_arrows(false,right_input);
        }
        else if(current_input == 0)
        {
            set_arrows(false,left_input);
            set_arrows(true,right_input);
        }
        else if(current_input == static_cast<int>(model->x.size()-1))
        {
            set_arrows(false,right_input);
            set_arrows(true,left_input);
        }
        else
        {
            set_arrows(true,right_input);
            set_arrows(true,left_input);
        }

        counter_input->setText(QString("   x%1").arg(current_input+1));

        redraw();

    }

}

void Results_widget::all_clicked(bool draw)
{

    std::vector<ScatterPlotSeries*> series ;

    std::vector<int> colors{ 0,0,0 };

    if(model != nullptr)
    {

        series.push_back(GetDefaultScatterPlotSeriesSettings());
        series.at(0)->xs = &(model->x.at(current_input));
        series.at(0)->ys = &(model->y0);
        series.at(0)->linearInterpolation = false;
        series.at(0)->pointType = toVector(L"circles");
        series.at(0)->color = CreateRGBColor(colors.at(0), colors.at(1), colors.at(2));

        colors = change_color(colors);

        for (int i = 0; i < static_cast<int>(model->Y.size()); i++) ///////// TADY TAKY
        {
            series.push_back(GetDefaultScatterPlotSeriesSettings());
            series.at(i+1)->xs = &(model->x.at(current_input)); //////////////////// TADY SI NASTAVÍM ČEHO NA CO CHCI GRAF !!!!!
            series.at(i+1)->ys = &(model->Y.at(i));
            series.at(i+1)->linearInterpolation = true;
            series.at(i+1)->pointType = toVector(L"dots");
            series.at(i+1)->lineThickness = (std::ceil((graph_l->width()-20)/1000)+2);
            series.at(i+1)->color = CreateRGBColor(colors.at(0), colors.at(1), colors.at(2));
            colors = change_color(colors);

        }
    }

    graph_settings = GetDefaultScatterPlotSettings();
    graph_settings->width = graph_l->width()-20;
    graph_settings->height = graph_l->height()-20;
    graph_settings->autoBoundaries = false;

    if(model != nullptr)
    {

        double y_min = model->y0.at(0);
        double y_max = model->y0.at(0);

        for(int i = 1;i < static_cast<int>(model->y0.size());i++)
        {
            if(model->y0.at(i) > y_max)
            {
                y_max = model->y0.at(i);
            }
            if(model->y0.at(i) < y_min)
            {
                y_min = model->y0.at(i);
            }
        }

        y_max += ((y_max < 0?-1:1)*y_max*0.2);
        y_min -= ((y_min < 0?-1:1)*y_min*0.2);
        graph_settings->yMax = y_max;
        graph_settings->yMin = y_min;
        graph_settings->xMin = model->x.at(current_input).at(0);
        graph_settings->xMax = model->x.at(current_input).back();

    }
    else
    {
        graph_settings->autoBoundaries = true;
    }

    graph_settings->autoPadding = true;

    if(model != nullptr)
    {
        for (int i = 0; i < static_cast<int>(series.size()); i++)
        {
            graph_settings->scatterPlotSeries->push_back(series.at(i));
        }


    if(draw)
    {
        current_g = g_all;

        set_arrows(false,right);
        set_arrows(false,left);

        if(model->x.size() == 1)
        {
            set_arrows(false,left_input);
            set_arrows(false,right_input);
        }
        else if(current_input == 0)
        {
            set_arrows(false,left_input);
            set_arrows(true,right_input);
        }
        else if(current_input == static_cast<int>(model->x.size()-1))
        {
            set_arrows(false,right_input);
            set_arrows(true,left_input);
        }
        else
        {
            set_arrows(true,right_input);
            set_arrows(true,left_input);
        }

        counter_input->setText(QString("  x%1").arg(current_input+1));

        if(model != nullptr)
        {
            if(model->regularization_range.size() == 1)
            {
                graph_title->setText("Calculated model");
            }
            else
            {
                graph_title->setText("All models");
            }
        }
        else
        {
            graph_title->setText("All models");
        }
        graph_x_label->setText("x");
        graph_y_label->setText("y");

        redraw();
    }
    }
}

void Results_widget::parret_clicked(bool draw, bool particular)
{

    std::vector<ScatterPlotSeries*> series ;

    std::vector<double> choose_one_mse;
    std::vector<double> choose_one_nonzc;

    if(model != nullptr)
    {

        series.push_back(GetDefaultScatterPlotSeriesSettings());
        series.at(0)->xs = &(model->MSE);
        series.at(0)->ys = &(model->NonZC);
        series.at(0)->linearInterpolation = false;
        series.at(0)->pointType = toVector(L"dots");
        series.at(0)->color = CreateRGBColor(0, 0, 1);

        if(particular)
        {
            choose_one_mse.push_back(model->MSE.at(current_index));
            choose_one_nonzc.push_back(model->NonZC.at(current_index));

            series.push_back(GetDefaultScatterPlotSeriesSettings());
            series.at(1)->xs = &choose_one_mse;
            series.at(1)->ys = &choose_one_nonzc;
            series.at(1)->linearInterpolation = false;
            series.at(1)->pointType = toVector(L"dots");
            series.at(1)->color = CreateRGBColor(1, 0, 0);
        }

        graph_settings = GetDefaultScatterPlotSettings();

        double mse_min = model->MSE.at(0);
        double mse_max = model->MSE.at(0);

        for(int i = 1;i < static_cast<int>(model->MSE.size());i++)
        {
            if(model->MSE.at(i) > mse_max)
            {
                mse_max = model->MSE.at(i);
            }
            if(model->MSE.at(i) < mse_min)
            {
                mse_min = model->MSE.at(i);
            }
        }

        double nonzc_min = model->NonZC.at(0);
        double nonzc_max = model->NonZC.at(0);

        for(int i = 1;i < static_cast<int>(model->NonZC.size());i++)
        {
            if(model->NonZC.at(i) > nonzc_max)
            {
                nonzc_max = model->NonZC.at(i);
            }
            if(model->NonZC.at(i) < nonzc_min)
            {
                nonzc_min = model->NonZC.at(i);
            }
        }

        mse_max += ((mse_max < 0?-1:1)*mse_max*0.2);
        mse_min -= ((mse_min < 0?-1:1)*mse_min*0.2);
        nonzc_max += ((nonzc_max < 0?-1:1)*nonzc_max*0.2);
        nonzc_min -= ((nonzc_min < 0?-1:1)*nonzc_min*0.2);
        graph_settings->yMax = nonzc_max;
        graph_settings->yMin = nonzc_min;
        graph_settings->xMax = mse_max;
        graph_settings->xMin = mse_min;


    }
    graph_settings->width = graph_l->width()-20;
    graph_settings->height = graph_l->height()-20;
    graph_settings->autoBoundaries = false;
    graph_settings->autoPadding = true;
    if(model != nullptr)
    {   graph_settings->scatterPlotSeries->push_back(series.at(0));
        if(series.size()>1)
        {
            graph_settings->scatterPlotSeries->push_back(series.at(1));
        }
    }
    if(draw){

        current_g = g_parret;

        graph_title->setText("Pareto chart");
        graph_x_label->setText("mse");
        graph_y_label->setText("number of non-zero coefficients");

        if(model->regularization_range.size() == 1)
        {
            set_arrows(false,left);
            set_arrows(false,right);
        }
        else if(current_index == 0)
        {
            set_arrows(false,left);
            set_arrows(true,right);
        }
        else if(current_index == static_cast<int>(model->regularization_range.size()-1))
        {
            set_arrows(false,right);
            set_arrows(true,left);
        }
        else
        {
            set_arrows(true,right);
            set_arrows(true,left);
        }

        counter->setText(QString("  %1/%2").arg(current_index+1).arg(model->Y.size()));

        set_arrows(false,right_input);
        set_arrows(false,left_input);

        redraw();
    }
}

void Results_widget::reg_mse_clicked(bool draw)
{

    ScatterPlotSeries* series;

    if(model != nullptr)
    {
        series = GetDefaultScatterPlotSeriesSettings();
        series->ys = &(model->MSE);
        series->xs = &(model->regularization_range);
        series->linearInterpolation = true;
        series->pointType = toVector(L"dots");
        series->lineThickness = (std::ceil((graph_l->width()-20)/1000)+2);
        series->color = GetBlack();

    }

    graph_settings = GetDefaultScatterPlotSettings();
    graph_settings->width = graph_l->width()-20;
    graph_settings->height = graph_l->height()-20;
    graph_settings->autoBoundaries = true;
    graph_settings->autoPadding = true;
    graph_title->setText("MSE dependent on regularization");
    graph_x_label->setText("regularization rate");
    graph_y_label->setText("mse");

    if(model != nullptr)
    {
        graph_settings->scatterPlotSeries->push_back(series);
    }

    if(draw){

        current_g = g_mse;

        set_arrows(false,right);
        set_arrows(false,left);

        set_arrows(false,right_input);
        set_arrows(false,left_input);

        redraw();
    }
}

void Results_widget::reg_NonZC_clicked(bool draw)
{

    std::vector<ScatterPlotSeries*> series ;

    std::vector<std::vector<double>> koefs;

    std::vector<int> colors{ 0,0,0 };

    int num_of_coeff = 0;

    if(model != nullptr)
    {
        for (int j = 0; j < static_cast<int>(model->KOEF.at(0).size()); j++)
        {
            for (int k = 0; k < static_cast<int>(model->KOEF.at(0).at(j).size()); k++)
            {
                for (int l = 0; l < static_cast<int>(model->KOEF.at(0).at(j).at(k).size()); l++)
                {
                    num_of_coeff++;
                }
            }
        }

        koefs.resize(num_of_coeff);

        int coeff_counter = 0;

        for (int i = 0; i < static_cast<int>(model->KOEF.size()); i++)
        {
            for (int j = 0; j < static_cast<int>(model->KOEF.at(i).size()); j++)
            {
                for (int k = 0; k < static_cast<int>(model->KOEF.at(i).at(j).size()); k++)
                {
                    for (int l = 0; l < static_cast<int>(model->KOEF.at(i).at(j).at(k).size()); l++)
                    {
                        // koefs.at(coeff_counter).push_back(model->KOEF.at(/*model_reg*/).at(/*w/b*/).at(/*vrstvy*/).at(/*koeficienty*/));
                        koefs.at(coeff_counter).push_back(model->KOEF.at(i).at(j).at(k).at(l));
                        coeff_counter++;
                    }
                }
            }
            coeff_counter = 0;
        }
    }

    for (int i = 0; i < static_cast<int>(koefs.size()); i++)
    {
        series.push_back(GetDefaultScatterPlotSeriesSettings());
        series.at(i)->xs = &(model->regularization_range);
        series.at(i)->ys = &(koefs.at(i));
        series.at(i)->linearInterpolation = true;
        series.at(i)->pointType = toVector(L"dots");
        //series.at(i)->lineThickness = (std::ceil((graph_l->width()-20)/1000)+2);
        series.at(i)->color = CreateRGBColor(colors.at(0), colors.at(1), colors.at(2));

        colors = change_color(colors);
    }

    graph_settings = GetDefaultScatterPlotSettings();
    graph_settings->width = graph_l->width()-20;
    graph_settings->height = graph_l->height()-20;
    graph_settings->autoBoundaries = true;
    graph_settings->autoPadding = true;
    graph_title->setText("Coefficients dependent on regularization");
    graph_x_label->setText("regularization rate");
    graph_y_label->setText("value of coefficients");

    if(model != nullptr)
    {
        for (int i = 0; i < static_cast<int>(series.size()); i++)
        {
            graph_settings->scatterPlotSeries->push_back(series.at(i));
        }
    }

    if(draw)
    {
        current_g = g_NonZC;

        set_arrows(false,right);
        set_arrows(false,left);

        set_arrows(false,right_input);
        set_arrows(false,left_input);

        redraw();
    }
}

void Results_widget::reg_NonZC_clicked2(bool draw)
{

    std::vector<ScatterPlotSeries*> series ;

    std::vector<std::vector<double>> koefs;

    std::vector<int> colors{ 0,0,0 };

    int koef_counter = 0;

    if(model != nullptr)
    {
        for (int j = 0; j < static_cast<int>(model->KOEF.at(0).size()); j++)
        {
            for (int k = 0; k < static_cast<int>(model->KOEF.at(0).at(j).size()); k++)
            {
                for (int l = 0; l < static_cast<int>(model->KOEF.at(0).at(j).at(k).size()); l++)
                {
                    koef_counter++;
                }
            }
        }
        for (int j = 0; j < static_cast<int>(model->KOEF.at(0).size()); j++)
        {
            for (int k = 0; k < static_cast<int>(model->KOEF.at(0).at(j).size()); k++)
            {
                for (int l = 0; l < static_cast<int>(model->KOEF.at(0).at(j).at(k).size()); l++)
                {
                    for(int i = 0;i < static_cast<int>(model->KOEF.size());i++)
                    {
                        koefs.at(koef_counter).push_back(model->KOEF.at(i).at(j).at(k).at(l));
                    }
                }
            }

        }
    }

    for (int i = 0; i < static_cast<int>(koefs.size()); i++)
    {
        series.push_back(GetDefaultScatterPlotSeriesSettings());
        series.at(i)->xs = &(model->regularization_range);
        series.at(i)->ys = &(koefs.at(i));
        series.at(i)->linearInterpolation = true;
        series.at(i)->pointType = toVector(L"dots");
        //series.at(i)->lineThickness = (std::ceil((graph_l->width()-20)/1000)+2);
        series.at(i)->color = CreateRGBColor(colors.at(0), colors.at(1), colors.at(2));

        colors = change_color(colors);
    }

    graph_settings = GetDefaultScatterPlotSettings();
    graph_settings->width = graph_l->width()-20;
    graph_settings->height = graph_l->height()-20;
    graph_settings->autoBoundaries = true;
    graph_settings->autoPadding = true;
    graph_title->setText("Coefficients dependent on regularization");
    graph_x_label->setText("regularization rate");
    graph_y_label->setText("value of coefficients");

    if(model != nullptr)
    {
        for (int i = 0; i < static_cast<int>(series.size()); i++)
        {
            graph_settings->scatterPlotSeries->push_back(series.at(i));
        }
    }

    if(draw)
    {
        current_g = g_NonZC;

        set_arrows(false,right);
        set_arrows(false,left);

        set_arrows(false,right_input);
        set_arrows(false,left_input);

        redraw();
    }
}

void Results_widget::arrowl_clicked()
{

    if(current_index <= 0)
    {
        return;
    }
    else
    {
        current_index--;
    }

    if(current_index == 0)
    {
        set_arrows(false,left);
        set_arrows(true,right);
    }

    mp_model_combo->setCurrentIndex(current_index);

}

void Results_widget::arrow_clicked()
{
    if(current_index >= static_cast<int>(model->regularization_range.size()-1))
    {
        return;
    }
    else
    {
        current_index++;
    }

    if(current_index == static_cast<int>(model->regularization_range.size()-1))
    {
        set_arrows(false,right);
        set_arrows(true,left);
    }

    mp_model_combo->setCurrentIndex(current_index);
}

void Results_widget::arrow_input_clicked()
{

    if(current_input >= static_cast<int>(model->x.size())-1)
    {
        return;
    }
    else
    {
        current_input++;
    }

    if(current_input == (static_cast<int>(model->x.size())-1))
    {
        set_arrows(false,right_input);
        set_arrows(true,left_input);
    }

    if (current_g == g_all)
    {
        all_clicked();
    } else
    {
        best_clicked();
    }

}

void Results_widget::arrowl_input_clicked()
{
    if(current_input <= 0)
    {
        return;
    }
    else
    {
        current_input--;
    }

    if(current_input == 0)
    {
        set_arrows(false,left_input);
        set_arrows(true,right_input);
    }

    if (current_g == g_all)
    {
        all_clicked();
    }
    else
    {
        best_clicked();
    }

}

void Results_widget::set_arrows(bool enable, QPushButton* arrow)
{
    arrow->setEnabled(enable);

    QString str = (enable?"1":"2");
    QString str2 = ((arrow == right) || (arrow == right_input)?"arrow":"arrowl");
    QString str3 = ((arrow == left_input) || (arrow == right_input)?"240":"255");
    arrow->setStyleSheet("QPushButton"
                         "{"
                         "background-color:rgba( " + str3 + " , " + str3 + " , " + str3 + " , 255);"
                                                                                          "image: url(:/res/icon/" + str2 + str + ");"
                                                                                                                                  "}"
                                                                                                                                  "QPushButton:hover{"
                                                                                                                                  "background-color:rgba( " + str3 + " , " + str3 + " , " + str3 + " , 255);"
                                                                                                                                                                                                   "image: url(:/res/icon/" + str2 + "2);"
                                                                                                                                                                                                                                     "}"
                                                                                                                                                                                                                                     "QPushButton:pressed{"
                                                                                                                                                                                                                                     "background-color:rgba( " + str3 + " , " + str3 + " , " + str3 + " , 255);"
                                                                                                                                                                                                                                                                                                      "image: url(:/res/icon/" + str2 + "3);"
                                                                                                                                                                                                                                                                                                                                        "}"
                         );



    if(enable)
    {
        (((arrow == left_input) || (arrow == right_input))?counter_input:counter)->setStyleSheet("QLabel{"
                                                                                                 "color: rgba(0, 0, 0, 255);"
                                                                                                 "}");
    }
    else
    {
        (((arrow == left_input) || (arrow == right_input))?counter_input:counter)->setStyleSheet("QLabel{"
                                                                                                 "color: rgba(100, 100, 100, 255);"
                                                                                                 "}");
    }

}

void Results_widget::set_coef_widget()
{
    int temp_cnt = 1;

    QString text_temp = "";
    QStringList text;

    for (int k = 0; k < static_cast<int>(model->KOEF.at(current_index).size()); k++)
    {
        for (int j = 0; j < static_cast<int>(model->KOEF.at(current_index).at(k).size()); j++)
        {
            for (int i = 0; i < static_cast<int>(model->KOEF.at(current_index).at(k).at(j).size()); i++)
            {
                text_temp.append((k==0?"w":"b"));
                text_temp.append(QString::number(temp_cnt));
                temp_cnt++;
                text_temp.append(":\t");
                text_temp.append(QString::number(model->KOEF.at(current_index).at(k).at(j).at(i)));
                //text_temp.append("\n");
                text.append(text_temp);
                text_temp = "";
            }
        }

        temp_cnt = 1;
    }


    mp_coefficients->setModel(new QStringListModel(text));

}

int Results_widget::search_best()
{
    std::vector<std::vector<double>> data;
    data.resize(3);
    data.at(0) = model->NonZC;
    data.at(1) = model->MSE;

    double NonZC_min = data.at(0).at(0);
    double NonZC_max = data.at(0).at(0);
    double mse_min = data.at(1).at(0);
    double mse_max = data.at(1).at(0);

    // hledání minimální a maximální chyby a minimálního a maximálního počtu koeficietů
    for(int i = 0;i < static_cast<int>(data.at(0).size());i++)
    {
        if(data.at(0).at(i) < NonZC_min)
        {
            NonZC_min = data.at(0).at(i);
        }
        if(data.at(0).at(i) > NonZC_max)
        {
            NonZC_max = data.at(0).at(i);
        }
        if(data.at(1).at(i) < mse_min)
        {
            mse_min = data.at(1).at(i);
        }
        if(data.at(1).at(i) > mse_max)
        {
            mse_max = data.at(1).at(i);
        }
    }

    for(int i = 0;i < static_cast<int>(data.at(0).size());i++) // odstranění modelů s chybou větší než desetinásobek nejmenší chyby
    {
        if(data.at(1).at(i) > (10*mse_min))
        {
            data.at(0).erase(data.at(0).begin()+i);
            data.at(1).erase(data.at(1).begin()+i);
            i--;
        }
    }

    NonZC_min = data.at(0).at(0);
    NonZC_max = data.at(0).at(0);
    mse_min = data.at(1).at(0);
    mse_max = data.at(1).at(0);

    for(int i = 0;i < static_cast<int>(data.at(0).size());i++) // jelikož jsem nějaké modely mohl odstranit, tak tady znovu zjistím minimum a maximum
    {
        if(data.at(0).at(i) < NonZC_min)
        {
            NonZC_min = data.at(0).at(i);
        }
        if(data.at(0).at(i) > NonZC_max)
        {
            NonZC_max = data.at(0).at(i);
        }
        if(data.at(1).at(i) < mse_min)
        {
            mse_min = data.at(1).at(i);
        }
        if(data.at(1).at(i) > mse_max)
        {
            mse_max = data.at(1).at(i);
        }
    }

    double NonZC_score = 0;
    double mse_score = 0;

    for(int i = 0;i < static_cast<int>(data.at(0).size());i++) // vypočtení "skore daneho modelu"
    {
        NonZC_score = (((NonZC_max-NonZC_min) != 0)?((((data.at(0).at(i)-NonZC_min)*10)/(NonZC_max-NonZC_min))): 0);
        mse_score = (((mse_max-mse_min) != 0)?(((data.at(1).at(i)-mse_min)*15)/(mse_max-mse_min)):0);

        data.at(2).push_back(NonZC_score+mse_score);
    }

    int index = 0;
    double min_val = data.at(2).at(index);

    for(int i = 1;i < static_cast<int>(data.at(0).size());i++)
    {
        if(data.at(2).at(i) < min_val)
        {
            min_val = data.at(2).at(i);
            index = i;
        }
    }

    for(int i = 0;i < static_cast<int>(model->MSE.size());i++)
    {
        if((model->MSE.at(i) == data.at(1).at(index))&&(model->NonZC.at(i) == data.at(0).at(index)))
        {
            return i;
        }
    }

    return model->MSE.size();
}

void Results_widget::best_button_clicked()
{
    mp_model_combo->setCurrentIndex(best_index);
    comboBox_item_changed(best_index);

}

void Results_widget::comboBox_item_changed(int index)
{
    if(model != nullptr)
    {
        current_index = index;
        if(current_g == g_parret)
        {
            parret_clicked();
        }
        else
        {
            best_clicked();
        }
        set_coef_widget();
    }
}

void Results_widget::resizeEvent(QResizeEvent *event)
{
    switch(current_g)
    {
    case g_all:
        all_clicked();
        break;
    case g_best:
        best_clicked();
        break;
    case g_parret:
        parret_clicked();
        break;
    case g_mse:
        reg_mse_clicked();
        break;
    case g_NonZC:
        reg_NonZC_clicked();
        break;
    }

    QWidget::resizeEvent(event);
}

void Results_widget::change_blockator(bool state)
{
    size_change_blockator = state;
    if(!state)
    {
        resizeEvent(nullptr);
    }
}

void Results_widget::setComboBox(QComboBox *combo, bool disable)
{

    QString b_color((disable)?"rgb(238, 238, 238)":"rgb(220, 220, 220)");
    QString h_color((disable)?"rgb(238, 238, 238)":"rgb(200, 200, 200)");
    QString color((disable)?"rgb(200, 200, 200)":"rgb(0, 0, 0)");

    combo->setDisabled(disable);
    combo->setStyleSheet("QComboBox"
                         "{"
                         "border:none;"
                         "background-color:   " + b_color + ";"
                                                            "color: " + color + ";"
                                                                                "padding:5px;"
                                                                                "}"
                                                                                "QComboBox::drop-down"
                                                                                "{"
                                                                                "    border: none;"
                                                                                "    background-color:   " + b_color + ";"
                                                                                                                       "  color: " + color + ";"
                                                                                                                                             "    padding: 0px;"
                                                                                                                                             "}"
                                                                                                                                             "QComboBox::down-arrow"
                                                                                                                                             "{"
                                                                                                                                             "    image: url(:/res/icon/combo" + (disable?"_d":"") + ");"
                                                                                                                                                                                                     "    width: 10px;"
                                                                                                                                                                                                     "    height: 10px;"
                                                                                                                                                                                                     "}"
                                                                                                                                                                                                     "QListView{"
                         //                         "    border:none;"
                         "    background-color:rgb(238, 238, 238);"
                         //                         "    color: " + color + ";"
                         //                         "    show-decoration-selected: 1;"
                         //                         "    margin-left:-10px;"
                         //                         "    padding-left:15px;"
                         "}"
                         "QListView::item:hover"
                         "{"
                         "    background-color:rgb(200, 200, 200);"
                         "    border:                 none;"
                         "    color:rgb(0, 0, 0);"
                         "}"
                         "QComboBox:hover"
                         "{"
                         "    background-color:   " + h_color + ";"
                                                                "}"
                                                                "}"
                         );

}

void Results_widget::set_button_disable(QPushButton *b,bool disable)
{
    QString b_color((disable)?"rgb(238, 238, 238)":"rgb(220, 220, 220)");
    QString h_color((disable)?"rgb(238, 238, 238)":"rgb(200, 200, 200)");
    QString color((disable)?"rgb(200, 200, 200)":"rgb(0, 0, 0)");

    b->setDisabled(disable);
    b->setStyleSheet("QPushButton{"
                     "background-color: " + b_color + ";"
                                                      "color: " + color + ";"
                                                                          "border: 1px;"
                                                                          "border-radius: 3px;"
                                                                          "border-color: rgba(255, 255, 255, 255);"
                                                                          "}"
                                                                          "QPushButton:hover"
                                                                          "{"
                                                                          "background-color: " + h_color + ";"
                                                                                                           "}"
                                                                                                           "QPushButton:pressed"
                                                                                                           "{"
                                                                                                           "background-color:rgba(150, 150, 150, 255);"
                                                                                                           "}"
                     );
}
