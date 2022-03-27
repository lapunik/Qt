#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    model* m;

    void resizeEvent(QResizeEvent*);

public slots:

    void set_add();
    void set_sub();
    void set_mlp();
    void set_div();

    void calculate();

    void zero_division();


};
#endif // MAINWINDOW_H
