#ifndef BUTTON_ROUNDTED_H
#define BUTTON_ROUNDTED_H

#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QGridLayout>
#include <QMessageBox>
#include <QMouseEvent>
#include <my_button.h>


class Button_roundted : public QWidget
{
    Q_OBJECT
public:
    explicit Button_roundted(QWidget *parent = nullptr);
    virtual ~Button_roundted();

    bool reconfigurable = true;

   My_button *button = nullptr;

signals:
    void double_clicked_signal();

private:
    QGridLayout *mp_layout = nullptr;

//protected:
//    void resizeEvent(QResizeEvent *event);

public slots:

//    int get_redraw();
//    void redraw();
    void set_redraw(int diameter);

    //void double_clicked_slot();

};

#endif // BUTTON_ROUNDTED_H
