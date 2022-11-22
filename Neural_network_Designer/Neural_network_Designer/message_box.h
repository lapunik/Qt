#ifndef MESSAGE_BOX_H
#define MESSAGE_BOX_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QLabel>

class Message_box : public QDialog
{
    Q_OBJECT
public:
    explicit Message_box(QString text, QString title, QWidget *parent = nullptr);
    virtual ~Message_box();

private slots:

        void ok_button_clicked();

signals:

private:

    QLabel *title = nullptr;
    QPushButton *exit_button = nullptr;
    QVBoxLayout *layout_main_horizontal = nullptr;
    QHBoxLayout *layout_title_bar = nullptr;
    QWidget *title_bar_w = nullptr;
    QPushButton *icon = nullptr;

    void set_window(QString title_txt);
    void set_title_layout(QString title_txt);


    // Prvky rozložení
    QWidget *mp_main_widget = nullptr;
    QVBoxLayout *mp_main_layout = nullptr;
    QHBoxLayout *mp_button_layout = nullptr;


    QPushButton *mp_button_ok = nullptr;
    QLabel *mp_text = nullptr;


};

#endif // MESSAGE_BOX_H
