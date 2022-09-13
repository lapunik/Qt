#ifndef MY_BUTTON_H
#define MY_BUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QMouseEvent>

class My_button : public QPushButton
{
    Q_OBJECT
public:
    explicit My_button(QPushButton *parent = nullptr);

signals:
    void double_clicked();

private:

protected:
    void mouseDoubleClickEvent(QMouseEvent *e);

};

#endif // MY_BUTTON_H
