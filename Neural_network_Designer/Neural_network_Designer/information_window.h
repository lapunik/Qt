#ifndef INFORMATION_WINDOW_H
#define INFORMATION_WINDOW_H

#include <QDialog>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <neuron.h>
#include <QApplication>
#include <QLabel>
#include <QStringList>
#include <QStringListModel>
#include <QScrollBar>
#include <QListView>




class Information_window : public QDialog
{
    Q_OBJECT
public:
    explicit Information_window(std::vector<double> e,std::vector<int> N,QWidget *parent = nullptr);
    virtual ~Information_window();

private slots:

        void ok_button_clicked();

signals:

private:

    const QString TITLE = tr("Calculation information");

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
    QHBoxLayout *mp_button_layout = nullptr;

    QListView *mp_text = nullptr;

    QPushButton *mp_button_ok = nullptr;


};

#endif // INFORMATION_WINDOW_H
