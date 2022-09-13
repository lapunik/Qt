#ifndef SMART_TAB_WIDGET_H
#define SMART_TAB_WIDGET_H

#include <QWidget>
#include <QTabWidget>

class Smart_tab_widget : public QTabWidget
{
    Q_OBJECT
public:
    explicit Smart_tab_widget(QWidget *parent = nullptr);
    virtual ~Smart_tab_widget();

protected:
    void tabBarClicked(int index);


signals:

};

#endif // SMART_TAB_WIDGET_H
