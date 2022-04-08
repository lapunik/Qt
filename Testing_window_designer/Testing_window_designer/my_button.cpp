#include "my_button.h"

My_button::My_button(QWidget *parent):  QPushButton{parent}
{
    this->setStyleSheet(QString("QPushButton"
                  "{background-color: #FFFFFF;"
                  "color:#000000;"
                  "border: 2px solid #F0F0F0;"
                  "border-radius:%1px;}"
                  "QPushButton:hover{"
                  "background-color: #F0F0F0;}"
                  "QPushButton:focus{"
                  "background-color: #AAAAAA;}"
                   ).arg(this->height()/2));

    QFont font = this->font();
    font.setPixelSize(this->height()/2);
    this->setFont(font);
}



My_button::~My_button()
{

}


void My_button::setFixedHeight(int h)
{
    QPushButton::setFixedHeight(h);
    redraw();
}

void My_button::redraw()
{
      setStyleSheet(QString("QPushButton{border-radius:%1px;").arg(this->height()/2));
}
