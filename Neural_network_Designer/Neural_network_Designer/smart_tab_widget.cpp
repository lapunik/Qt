#include "smart_tab_widget.h"

Smart_tab_widget::Smart_tab_widget(QWidget *parent): QTabWidget{parent}
{
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabSelected()));
}

Smart_tab_widget::~Smart_tab_widget()
{

}

void Smart_tab_widget::tabBarClicked(int index)
{
    if(this->count() == index)
    {
        int a = 5;
    }

    QTabWidget::tabBarClicked(index);
}
