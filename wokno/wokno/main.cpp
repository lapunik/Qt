#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w; // instance třídy MainWindow viz mainwindow.h, jedná se o hlavní okno aplikace
    w.show(); // zobrazení hlavního okna aplikace
    return a.exec();
}
