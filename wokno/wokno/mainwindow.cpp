#include "mainwindow.h"
#include <QApplication> // tato knihovna obsahuje slot quit(), kterou chci k ukončení aplikace tlačítkem. Slot je vlastně možný příjemce signálu

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) // Konstruktor třídy MainWindow
{
    resize(640,480); // Velikost okna
    setWindowTitle("The program"); // Titulek okna
    setWindowIcon(QIcon(":/img/icon")); // Změna ikony. Nejdříve jsem přidal nový Qt resource file, pojmenoval ho "Resources", připad prefix "img" a nakonec do něj nahrál obrázek ikony. Ikoně jsem přidal alias, jak ji budu v kódu označovat. Tento příkaz potom ikonu nastaví, QIcon je třída ikony a argument začínám dvojtečkou. To protože jsem použil qrc soubor a konkrétně alias souboru s ikonou
    setToolTip("Úplně prázdný program"); // Nápověda, co se zobrazí po najetí myší na okno
    setToolTipDuration(10000); // Čas, po kterém nápověda zmizí

    central = new QWidget(this); // připravím si okno central wiget (viz rozložení okna v aplikaci: https://www.itnetwork.cz/cplusplus/qt/dokonceni-prvniho-okna-v-qt-a-cplusplus-tlacitko )

    layout = new QHBoxLayout(); // inicializuji si layout
    central->setLayout(layout); // nastavím layout pro okno central wiget

    tlacitko = new QPushButton("Zavřít"); // vytvořím nové tlačítko
    //tlacitko->setFixedWidth(100); // nastavení šířky na 100px na pevno
    tlacitko->setMaximumWidth(100); // nastavení maximální šířky tlačítka
    tlacitko->setToolTip("Zevření celého okna."); // můžu mu zase přidat nápovědu

    layout->addWidget(tlacitko); // tlačítko přidám do layoutu

    setCentralWidget(central); // a nakonec nastavím naše vytvořené okno central wiget právě jako central wiget okno pro okenní aplikaci

    connect(tlacitko,SIGNAL(clicked()),qApp,SLOT(quit()),Qt::QueuedConnection); // Ve vytváření aplikace budeme používat tzv. SIGNALY a SLOTY. Jedná se vlastně o způsob komunikace mezi jednotlivými prvky aplikace. Právě např. propojím (connect SIGNÁL "clicked()" tlačítka se SLOTEM quit(), čímž zařídím quit po stisknutí tlačítka)
    // prvním argumentem je tedy ukazatel na nějaký objekt (QObject), v našem případě na tlačítko másleduje SIGNÁL clicked(), poté následuje makro reprezentující ukazatel na celou aplikaci (makro je z knihovny "QApplication") a potom SLOT quit().
    // úplně posledním argumentem je tzv. ConnectionType, kde QueuedConnection znamená, že se příkazy řadí do fronty. Nestane se tedy, aby se aplikace zavřela a např. nedokončila určité ukládání dat atd..
}

MainWindow::~MainWindow() // Destruktor třídy MainWindow
{
    if(central != NULL)
    {
        delete central;
    }

    if(layout != NULL)
    {
        delete layout;
    }

    if(tlacitko != NULL)
    {
        delete tlacitko;
    }

}

