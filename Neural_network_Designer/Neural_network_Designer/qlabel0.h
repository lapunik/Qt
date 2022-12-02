#ifndef QLABEL0_H
#define QLABEL0_H

#include <QLabel>
#include <QPainter>

class QLabel0 : public QLabel
{
    Q_OBJECT
public:
    explicit QLabel0(QWidget *parent = nullptr);
private:
    void paintEvent(QPaintEvent*);
signals:

};

#endif // QLABEL0_H
