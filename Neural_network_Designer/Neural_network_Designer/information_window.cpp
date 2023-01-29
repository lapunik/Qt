#include "information_window.h"

Information_window::Information_window(std::vector<double> e,std::vector<int> N, QWidget *parent): QDialog{parent}
{

    set_window();

    mp_main_layout = new QVBoxLayout();
    mp_button_layout = new QHBoxLayout();

    QStringList text;

    for(int i = 0;i<static_cast<int>(e.size());i++)
    {
        text.push_back(tr("Model %1:\n       Number of itaration:\t\t%2\n       Error:\t\t\t%3").arg(i+1).arg(N.at(i)).arg(e.at(i)));
    }

    mp_text = new QListView();
    mp_string_list_model = new QStringListModel(text);
    mp_text->setModel(mp_string_list_model);
    mp_text->setStyleSheet(QString("QListView{"
                                   "color: rgba(0, 0, 0, 255);"
                                   "background-color: rgba(255, 255, 255, 255);"
                                   "border: none;"
                                   "border-radius: 3px;"
                                   "}"));
    scroll_bar = new QScrollBar();
    scroll_bar->setStyleSheet("QScrollBar:vertical {"
                       "    border: none;"
                       "    background-color: rgba(200, 200, 200, 255);"
                       "}"
                       "QScrollBar::handle:vertical {"
                       "    background: rgba(100, 100, 100, 255);"
                       "  border: 1px black;"
                       "  border-radius: 3px;"
                       "}"
                       "QScrollBar::down-arrow:vertical {"
                       "    image: url(:/res/icon/combo);"
                       "    width: 10px;"
                       "    height: 10px;"
                       "}"
                       );
    mp_text->setVerticalScrollBar(scroll_bar);

    mp_text->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    mp_button_ok = new QPushButton(tr("OK"));
    mp_button_ok->setFixedWidth(80);
    mp_button_ok->setFixedHeight(30);
    mp_button_ok->setStyleSheet(QString("QPushButton{"
                                        "background-color: rgba(0, 0, 100, 255);"
                                        "color: rgba(255, 255, 255, 255);"
                                        "border: none;"
                                        "border-radius: 3px;"
                                        "}"
                                        "QPushButton:hover"
                                        "{"
                                        "background-color:rgba(200, 200, 200, 255);"
                                        "}"
                                        ));

    connect(mp_button_ok, SIGNAL(clicked()), this, SLOT(ok_button_clicked()));

    label = new QLabel();
    label->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    mp_button_layout->addWidget(label);
    mp_button_layout->addWidget(mp_button_ok);

    mp_main_layout->addWidget(mp_text);
    mp_main_layout->addLayout(mp_button_layout);

    mp_main_widget = new QWidget();
    //mp_main_widget->setFixedHeight(40);
    mp_main_widget->setStyleSheet("QWidget{"
                                  "background-color: rgba(185, 185, 185, 255);"
                                  //"background-color: rgba(0, 0, 100, 255);"
                                  "border-top-left-radius: 0px;"
                                  "border-top-right-radius: 0px;"
                                  "border-bottom-left-radius: 10px;"
                                  "border-bottom-right-radius: 10px;"
                                  "color: black}");


    mp_main_widget->setLayout(mp_main_layout);

    layout_main_horizontal->addWidget(mp_main_widget);

}

Information_window::~Information_window()
{
    if(mp_main_layout != nullptr)
    {
        delete mp_main_layout;
    }
    if( mp_button_layout != nullptr)
    {
        delete  mp_button_layout;
    }
    if(mp_text != nullptr)
    {
        delete mp_text ;
    }
    if(mp_string_list_model != nullptr)
    {
        delete mp_string_list_model;
    }
    if( mp_button_ok != nullptr)
    {
        delete  mp_button_ok;
    }
    if(scroll_bar != nullptr)
    {
        delete scroll_bar;
    }
    if(mp_main_widget != nullptr)
    {
        delete mp_main_widget;
    }
    if(label != nullptr)
    {
        delete label;
    }
    if( exit_button != nullptr)
    {
        delete  exit_button;
    }
    if(title != nullptr)
    {
        delete title;
    }
    if(icon != nullptr)
    {
        delete icon;
    }
    if(space != nullptr)
    {
        delete space;
    }
    if(space2 != nullptr)
    {
        delete space2;
    }
    if(space3 != nullptr)
    {
        delete space3;
    }
    if(layout_main_horizontal != nullptr)
    {
        delete layout_main_horizontal;
    }
    if(layout_title_bar != nullptr)
    {
        delete layout_title_bar;
    }
    if(title_bar_w != nullptr)
    {
        delete title_bar_w;
    }




}

void Information_window::set_title_layout()
{
    exit_button = new QPushButton(this);
    exit_button->setFixedSize(QSize(40,25));
    exit_button->setIcon(QIcon(":/res/icon/exit"));
    exit_button->setIconSize(QSize(10,10));
    exit_button->setStyleSheet(QString("QPushButton{"
                                       "background-color: rgba(255, 120, 120, 255);"
                                       "color: black;"
                                       "border: none;"
                                       "border-radius: 3px;"
                                       "}"
                                       "QPushButton:hover"
                                       "{"
                                       "background-color:rgba(200, 200, 200, 255);"
                                       "}"));

    connect(exit_button,SIGNAL(clicked()),this,SLOT(ok_button_clicked()));


    title = new QLabel(TITLE);
    title->setStyleSheet("font: bold large");
    icon = new QPushButton(this);
    icon->setFixedSize(40,40);

    icon->setIcon(QIcon(":/res/icon/information"));
    icon->setIconSize(QSize(30,30));


    space = new QLabel("");
    space->setFixedSize(3,1);
    space2 = new QLabel("");
    space2->setFixedSize(3,1);
    space3 = new QLabel("");
    space3->setFixedSize(10,1);


    layout_title_bar->addWidget(space2);
    layout_title_bar->addWidget(icon);
    layout_title_bar->addWidget(title);
    layout_title_bar->addWidget(space3);
    layout_title_bar->addWidget(exit_button);
    layout_title_bar->addWidget(space);
    layout_title_bar->setSpacing(5);
    layout_title_bar->setContentsMargins(0,0,0,0);

}

void Information_window::set_window()
{
    resize(350,240);
    //setWindowIcon(QIcon(":/res/icon/main_icon"));
    //setWindowTitle(TITLE);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    layout_main_horizontal = new QVBoxLayout();
    layout_main_horizontal->setSpacing(0);
    layout_main_horizontal->setContentsMargins(0,0,0,0);

    layout_title_bar = new QHBoxLayout();
    set_title_layout();
    title_bar_w = new QWidget();
    title_bar_w->setFixedHeight(40);
    title_bar_w->setStyleSheet("QWidget{"
                               "background-color: rgba(100, 100, 100, 255);"
                               "border-top-left-radius: 10px;"
                               "border-top-right-radius: 10px;"
                               "color: white}");
    title_bar_w->setLayout(layout_title_bar);

    layout_main_horizontal->addWidget(title_bar_w);

    setLayout(layout_main_horizontal);

}

void Information_window::ok_button_clicked()
{
    close();
}


