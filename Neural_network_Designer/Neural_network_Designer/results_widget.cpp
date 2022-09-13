#include "results_widget.h"

Results_widget::Results_widget(QWidget *parent) : QWidget{parent}
{
    setWindow();
}

Results_widget::~Results_widget()
{

}

void Results_widget::setWindow()
{
    setContentsMargins(0,0,0,0);


    output_layout = new QHBoxLayout();
    download = new QPushButton();
    download->setText("  Download");
    download->setFixedWidth(100);
    download->setIcon(QIcon(":/res/icon/download"));
    download->setIconSize(QSize(20,20));
    download->setStyleSheet(QString("QPushButton{"
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
    output_layout->addWidget(new QLabel("Output data: "));
    output_layout->addWidget(download);


    control_layout = new QHBoxLayout();
    left = new QPushButton();
    left->setFixedSize(QSize(40,40));
    left->setStyleSheet("QPushButton{"
                        "image: url(:/res/icon/r_calculate);"
                        "}"
                        "QPushButton:hover{"
                        "image: url(:/res/icon/r_calculate2);"
                        "}"
                        "QPushButton:pressed{"
                        "image: url(:/res/icon/r_calculate3);"
                        "}"
                        );
    right = new QPushButton();
    right->setFixedSize(QSize(40,40));
    right->setStyleSheet("QPushButton{"
                         "image: url(:/res/icon/calculate);"
                         "}"
                         "QPushButton:hover{"
                         "image: url(:/res/icon/calculate2);"
                         "}"
                         "QPushButton:pressed{"
                         "image: url(:/res/icon/calculate3);"
                         "}"
                         );
    counter = new QLabel("0/0");
    counter->setStyleSheet("QLabel{"
                           "color: rgba(0, 0, 0, 255);"
                           "}");
    counter->setFixedWidth(30);
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
    main_V_layout->addLayout(control_layout);

    QWidget *main_widget = new QWidget();
    main_widget->setStyleSheet("QWidget{"
                               "background-color: rgba(255, 255, 255, 255);"
                               "border-radius: 0px;"
                               "}");
    main_widget->setFixedWidth(300);
    main_widget->setLayout(main_V_layout);

    graph_l = new QLabel();
    //graph.load(":/res/graphs/id");
    //graph_l->setAlignment(Qt::AlignCenter);
    //graph_l->setPixmap(graph);

    ////////////////////   TODO ////////////////////// Zkusit udělat real time vytváření grafu a jeho nahrávání do okna ve správném scaleu
    //graph_l->setPixmap(graph.scaled(graph_l->width(),graph_l->height(),Qt::KeepAspectRatio));

    main_H_layout = new QHBoxLayout();
    main_H_layout->addWidget(main_widget);
    main_H_layout->addWidget(graph_l);
    setLayout(main_H_layout);

}

void Results_widget::load_model(Neural_network_model *nn_model)
{
    model = nn_model;
    redraw();
}

void Results_widget::redraw()
{

    StringReference* errorMessage = new StringReference();
    RGBABitmapImageReference* imageReference = CreateRGBABitmapImageReference();

    std::vector<ScatterPlotSeries*> series;

    std::vector<int> colors{ 0,0,0 };

    for (int i = 0; i < static_cast<int>(model->Y.size()); i++)
    {


        series.push_back(GetDefaultScatterPlotSeriesSettings());
        series.at(i)->xs = &(model->x.at(0));
        series.at(i)->ys = &(model->Y.at(i));
        series.at(i)->linearInterpolation = (i==0?false:true);
        series.at(i)->pointType = (i == 0 ? toVector(L"circles") : toVector(L"dots"));
        //series.at(i)->lineThickness = 2;

        series.at(i)->color = CreateRGBColor(colors.at(0), colors.at(1), colors.at(2));

        colors = change_color(colors);

    }

    ScatterPlotSettings* settings = GetDefaultScatterPlotSettings();
    settings->width = 1000; // TODO ////// Velikost okna v pixelech
    settings->height = 750;
    settings->autoBoundaries = true;
    settings->autoPadding = true;
    settings->title = toVector(L"");
    settings->xLabel = toVector(L"");
    settings->yLabel = toVector(L"");

    for (int i = 0; i < static_cast<int>(model->Y.size()); i++)
    {
        settings->scatterPlotSeries->push_back(series.at(i));
    }

    DrawScatterPlotFromSettings(imageReference, settings, errorMessage);

    graph_l = new QLabel();

    QImage *img = new QImage(settings->width, settings->height, QImage::Format_RGB16);

    for(int i = 0; i < settings->width; i++)
    {
        for(int u = 0; u < settings->height; u++)
        {
            img->setPixel(i, u,
                          QColor(imageReference->image->x->at(i)->y->at(u)->r,
                                 imageReference->image->x->at(i)->y->at(u)->g,
                                 imageReference->image->x->at(i)->y->at(u)->b,
                                 imageReference->image->x->at(i)->y->at(u)->a)
                          );
        }
    }
    graph = (QPixmap::fromImage(*img));



    //auto a = ConvertToPNG(imageReference->image);

//    mp_equation->setFixedHeight(100);
//    graph = new QPixmap((ConvertToPNG(imageReference->image)));

//    mp_equation->setAlignment(Qt::AlignCenter);
//    //equation = equation.scaled(QSize(100,50));
//    mp_equation->setPixmap(equation);
//    //mp_equation->setScaledContents(true);

//    mp_picture = new QLabel();

//    mp_graph_layout->addWidget(mp_picture);
//    mp_graph_layout->addWidget(mp_equation);

//    graph.load(":/res/graphs/id");
//    mp_picture->setPixmap(graph);
//    //mp_picture->setScaledContents(true);
//    //mp_picture->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);

//    mp_picture->setStyleSheet(QString("QLabel{"
//                                      "background-color: rgba(255, 255, 255, 255);"
//                                      "color: rgba(0, 0, 0, 255);"
//                                      "border: none;"
//                                      "border-radius: 3px;"
//                                      "}"
//                                      "}"));

//    mp_equation->setStyleSheet(QString("QLabel{"
//                                       "background-color: rgba(255, 255, 255, 255);"
//                                       "color: rgba(0, 0, 0, 255);"
//                                       "border: none;"
//                                       "border-radius: 3px;"
//                                       "}"
//                                       "}"));


    //WriteToFile(ConvertToPNG(imageReference->image), "model.png");



}

std::vector<int> Results_widget::change_color(std::vector<int> color)
{
    char c = (color.at(0)) | (color.at(1) << 1) | (color.at(2) << 2);
    c++;
    color.at(0) = c & 0x1 ? 1 : 0, color.at(1) = c & 0x2 ? 1 : 0, color.at(2) = c & 0x4 ? 1 : 0;

    return color;
}
