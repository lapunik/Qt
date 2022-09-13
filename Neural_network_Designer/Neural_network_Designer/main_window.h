#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QApplication> // knihovna pro získání ukazatele na program přes makro qApp (např pro slot quit atd..)
#include <QMessageBox>
#include <QDebug> // knihovna pro lepší ladění, např. výpis nějakého info
#include <QLineEdit>
#include <QComboBox>
#include <QTabWidget>
#include <QAction>
#include <QVector>
#include <QToolButton>


#include "neural_network_model.h"
#include "layer_widget.h"
#include "result_widget.h"

class Main_window : public QMainWindow
{
    Q_OBJECT

public:
    Main_window(QWidget *parent = nullptr);
    ~Main_window();

private:
    const QString APP_TITLE = tr("Neural network designer");

    QWidget *window = nullptr;
    QVBoxLayout *layout_main_vertical = nullptr;
    QHBoxLayout *layout_main_horizontal = nullptr;

    // Title bar
    QWidget *title_bar_w = nullptr;
    QHBoxLayout *layout_title_bar = nullptr;
    QPushButton *exit_button = nullptr;
    QPushButton *maximize_button = nullptr;
    QPushButton *minimize_button = nullptr;
    QLabel *title = nullptr;
    QPushButton *icon = nullptr;
    QLineEdit *search = nullptr;

    // Left bar
    QWidget *left_bar_w = nullptr;
    QVBoxLayout *layout_left_bar = nullptr;
    QPushButton *exit_button2 = nullptr;
    QPushButton *new_button = nullptr;
    QPushButton *save_button = nullptr;
    QPushButton *load_button = nullptr;
    QPushButton *about_button = nullptr;
    QPushButton *settings_button = nullptr;

    // Result Widget
    QTabWidget *network_tabs = nullptr;
    QVector<Result_widget*> *result_wigets = nullptr;
    //bool removed = false;

    void set_window();
    void set_title_layout();
    void set_left_layout();
    void set_menubar_layout();

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    QPointF mpos; //For dragging, relative mouse position to upper left
    QPointF global_mpos; //For resizing, global mouse position at mouse click
    QPointF rs_mpos; //for resizing
    int storeWidth; //fix window size at mouseclick for resizing
    int storeHeight;

private slots:

    void maximize();
    void minimize();
    void new_tab(int index);
    void new_tab_left_bar();
    void remove_tab(int index);

};

#endif // MAIN_WINDOW_H
