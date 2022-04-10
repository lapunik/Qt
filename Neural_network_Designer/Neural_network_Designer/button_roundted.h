#ifndef BUTTON_ROUNDTED_H
#define BUTTON_ROUNDTED_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class Button_roundted : public QWidget
{
    Q_OBJECT
public:
    explicit Button_roundted(QWidget *parent = nullptr);
    virtual ~Button_roundted();

private:
    QPushButton *mp_button = nullptr;
    QGridLayout *mp_layout = nullptr;
    void redraw();
signals:

};

#endif // BUTTON_ROUNDTED_H
