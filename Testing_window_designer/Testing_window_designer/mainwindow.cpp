#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *button = new QPushButton(this);
    setRoundedButton(button,100,":res/ico/plus");

    QPushButton *button2 = new QPushButton(this);
    setRoundedButton(button2,100,":res/ico/plus");

    QPushButton *button3 = new QPushButton(this);
    setRoundedButton(button3,100,":res/ico/plus");

    ui->verticalLayout->addWidget(button);
    ui->verticalLayout->addWidget(button2);
    ui->verticalLayout->addWidget(button3);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setRoundedButton(QPushButton *button,int size,QString icon)
{
//        button->setText("f_{x}");
        button->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
        button->setFixedHeight(size);
        button->setFixedWidth(size);
        button->setIcon(QIcon(icon));
        button->setIconSize(QSize(button->height(),button->height()));

//        ui->verticalLayout->setAlignment(Qt::AlignHCenter);

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

    //    QRect rect(0,0,button->height(),button->width());
    //    qDebug() << rect.size();
    //    qDebug() << button->size();
    //    QRegion region(rect, QRegion::Ellipse);
    //    qDebug() << region.boundingRect().size();
    //    button->setMask(region);
}
