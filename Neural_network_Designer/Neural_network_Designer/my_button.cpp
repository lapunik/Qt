#include "my_button.h"

My_button::My_button(QPushButton *parent) : QPushButton{parent}
{

}

void My_button::mouseDoubleClickEvent(QMouseEvent *e)
{

    if ( e->button() == Qt::LeftButton )
    {
        emit double_clicked();
    }

    QPushButton::mouseDoubleClickEvent(e);
}
