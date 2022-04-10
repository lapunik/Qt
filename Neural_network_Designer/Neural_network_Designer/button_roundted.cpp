#include "button_roundted.h"

Button_roundted::Button_roundted(QWidget *parent) : QWidget{parent}
{
    mp_layout = new QGridLayout();
    mp_button = new QPushButton();

    mp_layout->addWidget(mp_button);
    setLayout(mp_layout);

    //connect(this, SIGNAL(), this, SLOT(redraw()));

}

Button_roundted::~Button_roundted()
{
    if(mp_button != nullptr)
    {
        delete mp_button;
    }
    if(mp_layout != nullptr)
    {
        delete mp_layout;
    }
}

void Button_roundted::redraw()
{

}
