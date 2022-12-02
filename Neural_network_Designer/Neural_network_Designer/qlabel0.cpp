#include "qlabel0.h"

QLabel0::QLabel0(QWidget *parent) : QLabel{parent}
{

}

void QLabel0::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.rotate(0);
    painter.drawText(QRect(QPoint(((width()/2)+20)-(text().size()*4),(-height()/2)+1),QLabel::sizeHint()),Qt::AlignCenter,text());
}
