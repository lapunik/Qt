#include "birthdaymainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BirthdayMainWindow w;
    w.show();
    return a.exec();
}
