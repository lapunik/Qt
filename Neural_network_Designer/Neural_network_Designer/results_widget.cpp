#include "results_widget.h"

Results_widget::Results_widget(QWidget *parent) : QWidget{parent}
{
    set_window();
    current_g = g_all;
}

Results_widget::~Results_widget()
{

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
    button_widget->setFixedWidth(150);
    graph_chosing = new QVBoxLayout();
    all = new QPushButton();
    all->setDisabled(true);
    all->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    // all->setFixedHeight(50);
    //all->setText("All");
    all->setIcon(QIcon(":/res/icon/all"));
    all->setIconSize(QSize(150,70));
    connect(all,SIGNAL(clicked()),this,SLOT(all_clicked()));
    best = new QPushButton();
    best->setDisabled(true);
    best->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //  best->setFixedHeight(50);
    //best->setText("Individual");
    best->setIcon(QIcon(":/res/icon/best"));
    best->setIconSize(QSize(150,70));
    connect(best,SIGNAL(clicked()),this,SLOT(best_clicked()));
    parret = new QPushButton();
    parret->setDisabled(true);
    parret->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //  parret->setFixedHeight(50);
    //parret->setText("Parret");
    parret->setIcon(QIcon(":/res/icon/parret"));
    parret->setIconSize(QSize(150,70));
    connect(parret,SIGNAL(clicked()),this,SLOT(parret_clicked()));
    reg_mse = new QPushButton();
    reg_mse->setDisabled(true);
    reg_mse->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //   reg_mse->setFixedHeight(50);
    //reg_mse->setText("MSE");
    reg_mse->setIcon(QIcon(":/res/icon/mse"));
    reg_mse->setIconSize(QSize(150,70));
    connect(reg_mse,SIGNAL(clicked()),this,SLOT(reg_mse_clicked()));
    reg_NonZC = new QPushButton();
    reg_NonZC->setDisabled(true);
    reg_NonZC->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //   reg_NonZC->setFixedHeight(50);
    //reg_NonZC->setText("NonZC");
    reg_NonZC->setIcon(QIcon(":/res/icon/NonZC"));
    reg_NonZC->setIconSize(QSize(150,70));
    connect(reg_NonZC,SIGNAL(clicked()),this,SLOT(reg_NonZC_clicked()));
    graph_chosing->addWidget(all);
    graph_chosing->addWidget(best);
    graph_chosing->addWidget(parret);
    graph_chosing->addWidget(reg_mse);
    graph_chosing->addWidget(reg_NonZC);
    button_widget->setLayout(graph_chosing);

    output_layout = new QHBoxLayout();
    download = new QPushButton();
    download->setText("  Download");
    download->setFixedWidth(100);
    download->setIcon(QIcon(":/res/icon/download"));
    download->setIconSize(QSize(20,20));

    output_layout->addWidget(new QLabel("Output data: "));
    output_layout->addWidget(download);

    connect(download,SIGNAL(clicked()),this,SLOT(download_clicked()));

    best_layout = new QHBoxLayout();
    best_button = new QPushButton();
    best_button->setText("Best");
    best_button->setFixedWidth(100);
    best_button->setFixedHeight(20);

    best_layout->addWidget(new QLabel(""));
    best_layout->addWidget(best_button);
    best_layout->addWidget(new QLabel(""));

    connect(best_button,SIGNAL(clicked()),this,SLOT(best_button_clicked()));

    control_layout = new QHBoxLayout();
    counter = new QLabel("  0/0");
    counter->setFixedWidth(30);
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

    main_V_layout = new QVBoxLayout();
    main_V_layout->addLayout(output_layout);
    QLabel *l = new QLabel();
    l->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    main_V_layout->addWidget(l);
    main_V_layout->addLayout(best_layout);
    main_V_layout->addLayout(control_layout);

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

    graph_l = new QLabel();
    graph_l->setAlignment(Qt::AlignCenter);
    graph_l->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    control_input_layout = new QHBoxLayout();
    counter_input = new QLabel("  x1");
    counter_input->setFixedWidth(30);
    left_input = new QPushButton();
    left_input->setFixedSize(QSize(40,40));
    set_arrows(false, left_input);
    connect(left_input,SIGNAL(clicked()),this,SLOT(arrowl_input_clicked()));
    right_input = new QPushButton();
    right_input->setFixedSize(QSize(40,40));
    set_arrows(false,right_input);
    connect(right_input,SIGNAL(clicked()),this,SLOT(arrow_input_clicked()));
    control_input_layout->addWidget(left_input);
    control_input_layout->addWidget(new QLabel());
    control_input_layout->addWidget(counter_input);
    control_input_layout->addWidget(new QLabel());
    control_input_layout->addWidget(right_input);

    graph_V_layout->addWidget(graph_l);
    graph_V_layout->addLayout(control_input_layout);

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
    if(nn_model->regularization_range.size() > 1)
    {
        best->setDisabled(false);
        parret->setDisabled(false);
        reg_mse->setDisabled(false);
        reg_NonZC->setDisabled(false);

    }

    counter->setText(QString("  %1/%2").arg(current_index+1).arg(model->Y.size()));

    if(model->regularization_range.size() == 1)
    {
        best_button->setDisabled(true);
    }
    else
    {
        best_button->setEnabled(true);
        best_index = search_best();
    }


    all_clicked();
}

void Results_widget::redraw()
{
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
    emit save();
}

void Results_widget::best_clicked()
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

    counter_input->setText(QString("  x%1").arg(current_input+1));

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
        series.at(1)->lineThickness = 2;
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
    graph_settings->title = toVector(L"");
    graph_settings->xLabel = toVector(L"");
    graph_settings->yLabel = toVector(L"");

    if(model != nullptr)
    {
        for (int i = 0; i < static_cast<int>(series.size()); i++)
        {
            graph_settings->scatterPlotSeries->push_back(series.at(i));
        }
    }

    redraw();

}

void Results_widget::all_clicked()
{
    current_g = g_all;

    set_arrows(false,right);
    set_arrows(false,left);
    set_arrows(false,left_input);
    set_arrows(false,right_input);

    std::vector<ScatterPlotSeries*> series ;

    std::vector<int> colors{ 0,0,0 };

    if(model != nullptr)
    {

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
            series.at(i+1)->lineThickness = 2;
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
    graph_settings->title = toVector(L"");
    graph_settings->xLabel = toVector(L"");
    graph_settings->yLabel = toVector(L"");

    if(model != nullptr)
    {
        for (int i = 0; i < static_cast<int>(series.size()); i++)
        {
            graph_settings->scatterPlotSeries->push_back(series.at(i));
        }
    }

    redraw();
}

void Results_widget::parret_clicked()
{
    current_g = g_parret;

    set_arrows(false,right);
    set_arrows(false,left);

    set_arrows(false,right_input);
    set_arrows(false,left_input);

    ScatterPlotSeries* series;

    if(model != nullptr)
    {
        series = GetDefaultScatterPlotSeriesSettings();
        series->xs = &(model->MSE);
        series->ys = &(model->NonZC);
        series->linearInterpolation = false;
        series->pointType = toVector(L"dots");
        series->color = CreateRGBColor(0, 0, 1);

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
    graph_settings->title = toVector(L"");
    graph_settings->xLabel = toVector(L"");
    graph_settings->yLabel = toVector(L"");
    if(model != nullptr)
        graph_settings->scatterPlotSeries->push_back(series);


    redraw();
}

void Results_widget::reg_mse_clicked()
{
    current_g = g_mse;

    set_arrows(false,right);
    set_arrows(false,left);

    set_arrows(false,right_input);
    set_arrows(false,left_input);

    ScatterPlotSeries* series;

    if(model != nullptr)
    {
        series = GetDefaultScatterPlotSeriesSettings();
        series->ys = &(model->MSE);
        series->xs = &(model->regularization_range);
        series->linearInterpolation = true;
        series->pointType = toVector(L"dots");
        series->lineThickness = 2;
        series->color = GetBlack();

    }

    graph_settings = GetDefaultScatterPlotSettings();
    graph_settings->width = graph_l->width()-20;
    graph_settings->height = graph_l->height()-20;
    graph_settings->autoBoundaries = true;
    graph_settings->autoPadding = true;
    graph_settings->title = toVector(L"");
    graph_settings->xLabel = toVector(L"");
    graph_settings->yLabel = toVector(L"");

    if(model != nullptr)
    {

        graph_settings->scatterPlotSeries->push_back(series);

    }

    redraw();

}

void Results_widget::reg_NonZC_clicked()
{
    current_g = g_NonZC;

    set_arrows(false,right);
    set_arrows(false,left);

    set_arrows(false,right_input);
    set_arrows(false,left_input);

    std::vector<ScatterPlotSeries*> series ;

    std::vector<std::vector<double>> koefs;
    //koefs.resize(model->KOEF.size());

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

        koefs.resize(koef_counter);

        for (int i = 0; i < static_cast<int>(model->KOEF.size()); i++)
        {
            koef_counter = 0;

            for (int j = 0; j < static_cast<int>(model->KOEF.at(i).size()); j++)
            {
                for (int k = 0; k < static_cast<int>(model->KOEF.at(i).at(j).size()); k++)
                {
                    for (int l = 0; l < static_cast<int>(model->KOEF.at(i).at(j).at(k).size()); l++)
                    {
                        koefs.at(koef_counter).push_back(model->KOEF.at(i).at(j).at(k).at(l));
                        koef_counter++;
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
        //series.at(i)->lineThickness = 2;
        series.at(i)->color = CreateRGBColor(colors.at(0), colors.at(1), colors.at(2));

        colors = change_color(colors);
    }

    graph_settings = GetDefaultScatterPlotSettings();
    graph_settings->width = graph_l->width()-20;
    graph_settings->height = graph_l->height()-20;
    graph_settings->autoBoundaries = true;
    graph_settings->autoPadding = true;
    graph_settings->title = toVector(L"");
    graph_settings->xLabel = toVector(L"");
    graph_settings->yLabel = toVector(L"");

    if(model != nullptr)
    {
        for (int i = 0; i < static_cast<int>(series.size()); i++)
        {
            graph_settings->scatterPlotSeries->push_back(series.at(i));
        }
    }

    redraw();
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

    best_clicked();

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

    best_clicked();
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
    } else
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

    for(int i = 0;i < static_cast<int>(data.at(0).size());i++)
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

    for(int i = 0;i < static_cast<int>(data.at(0).size());i++)
    {
        data.at(2).push_back((((data.at(0).at(i)-NonZC_min)*10)/(NonZC_max-NonZC_min))+(((data.at(1).at(i)-mse_min)*15)/(mse_max-mse_min)));
    }

    int index = 0;
    double min_val = data.at(2).at(index);

    for(int i = 1;i < static_cast<int>(data.at(0).size());i++)
    {
        if(data.at(2).at(i) < min_val)
        {
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
    current_index = best_index;
    best_clicked();
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

    redraw();
    QWidget::resizeEvent(event);
}

