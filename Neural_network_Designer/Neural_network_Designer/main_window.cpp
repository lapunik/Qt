#include "main_window.h"

Main_window::Main_window(QWidget *parent) : QMainWindow(parent)
{
    set_window();

    Layer_widget *lw = new Layer_widget(this);

    setCentralWidget(lw);


}

Main_window::~Main_window()
{
}

void Main_window::set_window()
{
    resize(640,480);
    setWindowTitle(APP_TITLE);
    setWindowIcon(QIcon(":/res/icon/main_icon"));
}
