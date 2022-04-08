#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *button = new QPushButton(this);

//    button->setText("f_{x}");
    button->setIcon(QIcon(":res/ico/plus"));
    button->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    button->setFixedHeight(50);
    button->setFixedWidth(50);

    ui->verticalLayout->setAlignment(Qt::AlignCenter);

    button->setStyleSheet(QString("QPushButton{"
//                  "background-color: #FFFFFF;"
//                  "color:#000000;"
//                  "border: 2px solid #F0F0F0;"
//                  "border-radius:%1px;
                                  "border:none;"
                                  "background-color:rgba(255, 255, 255,100);"
                  "}"
                  "QPushButton:hover"
                  "{"
                  "background-color: #F0F0F0;"
                  "}"
                  "QPushButton:focus"
                  "{"
                  "background-color: #F0F0F0;"
                  "}"
                   ).arg(button->height()/2));

    button->setIconSize(QSize(button->height(),button->height()));

//    QRect rect(0,0,button->height(),button->width());
//    qDebug() << rect.size();
//    qDebug() << button->size();
//    QRegion region(rect, QRegion::Ellipse);
//    qDebug() << region.boundingRect().size();

    QPushButton *button2 = new QPushButton(this);
    QPushButton *button3 = new QPushButton(this);

    *button2 = *button;


    ui->verticalLayout->addWidget(button);

//    button->setMask(region);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setRoundedButton(QPushButton *button,int size,int base_color,int hover_color, int focus_color)
{

}
