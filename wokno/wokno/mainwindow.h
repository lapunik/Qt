#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>  // Nezapomenout na přidání knihoven pro layout i pro tlačítko!!!
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT // Makro pro předávání informací. Umožňuje nám používatsignály a sloty.

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget *central; // Komponenta nám poslouží jako obsah centrální části hlavního okna. Při rozsáhlejších programech bychom si pro něj vytvořili samostatnou třídu. Zatím to však není nutné.
    QHBoxLayout *layout; // Layout (skládá prvky vedle sebe. Když už se prvek nevejde, zalomí ho na další řádek)
    QPushButton *tlacitko; // Tlacitko


};
#endif // MAINWINDOW_H
