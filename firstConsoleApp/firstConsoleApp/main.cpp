#include <iostream>
#include <QCoreApplication>

int main(int argc, char *argv[]) {

    std::cout << "Qt version: " << qVersion() << std::endl;
    std::cout << "Next column\n";


    std::cout << "Have " << argc << " arguments:" << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
}
