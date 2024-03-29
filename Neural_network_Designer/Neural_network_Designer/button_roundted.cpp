#include "button_roundted.h"

Button_roundted::Button_roundted(QWidget *parent) : QWidget{parent}
{
    mp_layout = new QGridLayout();
    mp_layout->setSpacing(0);
    mp_layout->setContentsMargins(0,0,0,0);

    button = new My_button();
    button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //button->setIcon(QIcon(":/res/icon/id"));

    //connect(button, SIGNAL(double_clicked()), this, SLOT(double_clicked_slot()));

    mp_layout->addWidget(button);
    setLayout(mp_layout);

    //redraw();
}

Button_roundted::~Button_roundted()
{
    if(button != nullptr)
    {
        delete button;
    }
    if(mp_layout != nullptr)
    {
        delete mp_layout;
    }
}

void Button_roundted::set_redraw(int diameter)
{
    button->setFixedSize(diameter,diameter);
    button->setIconSize(QSize(diameter-2,diameter-2));
}

