#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m = new model(this);

    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(set_add()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(set_sub()));
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(set_mlp()));
    connect(ui->radioButton_4,SIGNAL(clicked()),this,SLOT(set_div()));

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(calculate()));

    connect(m,SIGNAL(deleni_nulou()),this,SLOT(zero_division()));




}

MainWindow::~MainWindow()
{
    delete ui;
    delete m;
}

void MainWindow::set_add()
{
    m->set_operation(model::add);
}
void MainWindow::set_sub()
{
    m->set_operation(model::sub);
}

void MainWindow::set_mlp()
{
    m->set_operation(model::mlp);
}

void MainWindow::set_div()
{
    m->set_operation(model::div);
}

void MainWindow::calculate()
{
    m->set_first_number(ui->lineEdit->text());
    m->set_second_number(ui->lineEdit_2->text());

    ui->lcdNumber->setText(QString::number(m->calculate()));
}

void MainWindow::zero_division()
{
    QMessageBox m = QMessageBox(QMessageBox::Warning, QString("Dělení nulou."),QString("Pokus o dělení nulou."));
    m.exec();
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    int containerWidth = this->width();
    int containerHeight = this->height();

    int contentsHeight = containerHeight ;
    int contentsWidth = containerHeight * 1.25;
    if (contentsWidth > containerWidth ) {
        contentsWidth = containerWidth ;
        contentsHeight = containerWidth / 1.25;
    }

    this->resize(contentsWidth, contentsHeight);

    QFont font = ui->lcdNumber->font();
    font.setPointSize(static_cast<int>(this->width()/20));
    ui->lcdNumber->setFont(font);
    ui->lineEdit->setFont(font);
    ui->lineEdit_2->setFont(font);
}
