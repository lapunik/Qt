#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    resize(900,600);

     window = new Test_widget(this);

     window->setLayout(layout);

     setCentralWidget(window);
}

MainWindow::~MainWindow()
{
}


//void MainWindow::mouseDoubleClickEvent( QMouseEvent * e )
//{

//    if ( e->button() == Qt::LeftButton )
//    {
//        QMessageBox mb = QMessageBox(QMessageBox::Warning,"Chyba","chyba");
//        mb.exec();
//    }

//    // You may have to call the parent's method for other cases
//    QMainWindow::mouseDoubleClickEvent(e);
//}


