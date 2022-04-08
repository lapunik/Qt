#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int * butt = new int;
    *butt = 10;

    int * butt2 = new int;
    *butt2 = *butt;



    return a.exec();
}
