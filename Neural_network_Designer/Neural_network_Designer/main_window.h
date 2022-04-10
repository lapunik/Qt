#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "layer_widget.h"

class Main_window : public QMainWindow
{
    Q_OBJECT

public:
    Main_window(QWidget *parent = nullptr);
    ~Main_window();

private:
    const QString APP_TITLE = tr("Neural network designer");

    void set_window();

};
#endif // MAIN_WINDOW_H
