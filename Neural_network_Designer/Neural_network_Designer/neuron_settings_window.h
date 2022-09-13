#ifndef NEURON_SETTINGS_WINDOW_H
#define NEURON_SETTINGS_WINDOW_H


#include <QDialog>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
//#include <QMouseEvent>
#include <neuron.h>
#include <QApplication>
#include <QLabel> // na obrazek



class Neuron_settings_window : public QDialog
{
    Q_OBJECT
public:
    explicit Neuron_settings_window(Neuron *n, QWidget *parent = nullptr);
    virtual ~Neuron_settings_window();

private slots:

        void ok_button_clicked();
        void cancel_button_clicked();
        void list_clicked(QListWidgetItem* item);

signals:

//protected:
    //void resizeEvent(QResizeEvent *event);

private:

    const QString TITLE = tr("Activation function");

    QLabel *title = nullptr;
    QPushButton *exit_button = nullptr;
    QVBoxLayout *layout_main_horizontal = nullptr;
    QHBoxLayout *layout_title_bar = nullptr;
    QWidget *title_bar_w = nullptr;
    QPushButton *icon = nullptr;

    void set_window();
    void set_title_layout();


    // Prvky rozložení
    QWidget *mp_main_widget = nullptr;
    QVBoxLayout *mp_main_layout = nullptr;
    QHBoxLayout *mp_sub_layout = nullptr;
    QVBoxLayout *mp_graph_layout = nullptr;
    QHBoxLayout *mp_button_layout = nullptr;

    QListWidget *mp_list_widget = nullptr;
    QLabel *mp_picture = nullptr;
    QLabel *mp_equation = nullptr;

    QPixmap graph;
    QPixmap equation;

    QPushButton *mp_button_ok = nullptr;
    QPushButton *mp_button_cancel = nullptr;

    Neuron *neuron = nullptr;
    Neuron::func original_func;



//    void mousePressEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);
//    QPoint mpos; //For dragging, relative mouse position to upper left
//    QPoint global_mpos; //For resizing, global mouse position at mouse click
//    QPoint rs_mpos; //for resizing
//    int storeWidth; //fix window size at mouseclick for resizing
//    int storeHeight;

//    void redraw();

};

#endif // NEURON_SETTINGS_WINDOW_H
