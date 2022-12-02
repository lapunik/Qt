#ifndef QLABEL90_H
#define QLABEL90_H

#include <QLabel>
#include <QPainter>

class QLabel90 : public QLabel
{
    Q_OBJECT
public:
    explicit QLabel90(QWidget *parent = nullptr);
private:
    void paintEvent(QPaintEvent*);
signals:

};

#endif // QLABEL90_H
