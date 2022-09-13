#ifndef TEST_WIDGET_H
#define TEST_WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QMouseEvent>

class Test_widget : public QWidget
{
    Q_OBJECT
public:
    explicit Test_widget(QWidget *parent = nullptr);

private:

    QWidget *window = nullptr;
    QHBoxLayout *layout = nullptr;

    void mouseDoubleClickEvent( QMouseEvent * e );

signals:

};

#endif // TEST_WIDGET_H
