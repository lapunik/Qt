#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseDoubleClickEvent( QMouseEvent * e )
{

    if ( e->button() == Qt::LeftButton )
    {
        QMessageBox mb = QMessageBox(QMessageBox::Warning,"Chyba","chyba");
        mb.exec();
    }

    // You may have to call the parent's method for other cases
    QMainWindow::mouseDoubleClickEvent(e);
}
