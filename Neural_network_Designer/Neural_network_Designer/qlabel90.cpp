#include "qlabel90.h"

QLabel90::QLabel90(QWidget *parent) : QLabel{parent}
{

}

void QLabel90::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    //    painter.setPen(Qt::black);
    //... Need an appropriate call to painter.translate() for this to work properly
    //painter.translate(0,sizeHint().height());
    painter.rotate(270);
    painter.drawText(QRect(QPoint(-(height()/2)-(text().size()*4),-5),QLabel::sizeHint()),Qt::AlignCenter,text());
}
