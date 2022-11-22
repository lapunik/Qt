#include "message_box.h"


Message_box::Message_box(QString text, QString title_txt, QWidget *parent): QDialog{parent}
{

    set_window(title_txt);

    mp_main_layout = new QVBoxLayout();
    mp_button_layout = new QHBoxLayout();

    mp_text = new QLabel();
    mp_text->setText(text);
    mp_text->setAlignment(Qt::AlignLeft);
    mp_text->setFixedHeight(120);
    mp_text->setStyleSheet(QString("QLabel{"
                                   "color: rgba(0, 0, 0, 255);"
                                   "background-color: rgba(255, 255, 255, 255);"
                                   "border: none;"
                                   "border-radius: 3px;"
                                   "}"));

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

    QLabel *l = new QLabel();
    l->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    mp_button_layout->addWidget(l);
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

Message_box::~Message_box()
{

}

void Message_box::set_title_layout(QString title_txt)
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


    title = new QLabel(title_txt);
    title->setStyleSheet("font: bold large");
    icon = new QPushButton(this);
    icon->setFixedSize(40,40);

    icon->setIcon(QIcon(":/res/icon/danger"));
    icon->setIconSize(QSize(30,30));


    QLabel *space = new QLabel("");
    space->setFixedSize(3,1);
    QLabel *space2 = new QLabel("");
    space2->setFixedSize(3,1);
    QLabel *space3 = new QLabel("");
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

void Message_box::set_window(QString title_txt)
{
    resize(350,210);
    //setWindowIcon(QIcon(":/res/icon/main_icon"));
    //setWindowTitle(TITLE);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    layout_main_horizontal = new QVBoxLayout();
    layout_main_horizontal->setSpacing(0);
    layout_main_horizontal->setContentsMargins(0,0,0,0);

    layout_title_bar = new QHBoxLayout();
    set_title_layout(title_txt);
    title_bar_w = new QWidget();
    title_bar_w->setFixedHeight(40);
    title_bar_w->setStyleSheet("QWidget{"
                               "background-color: rgba(100, 100, 100, 255);"
                               "border-bottom-left-radius: 0px;"
                               "border-bottom-right-radius: 0px;"
                               "border-top-left-radius: 10px;"
                               "border-top-right-radius: 10px;"
                               "color: white}");
    title_bar_w->setLayout(layout_title_bar);

    layout_main_horizontal->addWidget(title_bar_w);

    setLayout(layout_main_horizontal);

}

void Message_box::ok_button_clicked()
{
    close();
}


