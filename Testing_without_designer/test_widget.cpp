#include "test_widget.h"

Test_widget::Test_widget(QWidget *parent)
    : QWidget{parent}
{

}

void Test_widget::mouseDoubleClickEvent( QMouseEvent * e )
{

    if ( e->button() == Qt::LeftButton )
    {
        QMessageBox mb = QMessageBox(QMessageBox::Warning,"Chyba","chyba");
        mb.exec();
    }

    // You may have to call the parent's method for other cases
    QWidget::mouseDoubleClickEvent(e);
}

