#ifndef MY_BUTTON_H
#define MY_BUTTON_H

#include <QWidget>
#include <QPushButton>

class My_button : public QPushButton
{
    Q_OBJECT
public:
    explicit My_button(QWidget *parent = nullptr);
    virtual ~My_button();
    virtual void setFixedHeight(int h);

private:
    void redraw();

signals:

};

#endif // MY_BUTTON_H
