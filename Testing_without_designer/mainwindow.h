#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QMouseEvent>
#include "test_widget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    Test_widget *window = nullptr;
    QHBoxLayout *layout = nullptr;


    //void mouseDoubleClickEvent( QMouseEvent * e );

};
#endif // MAINWINDOW_H
