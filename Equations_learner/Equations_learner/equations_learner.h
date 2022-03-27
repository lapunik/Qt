#ifndef EQUATIONS_LEARNER_H
#define EQUATIONS_LEARNER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Equations_learner; }
QT_END_NAMESPACE

class Equations_learner : public QMainWindow
{
    Q_OBJECT

public:
    Equations_learner(QWidget *parent = nullptr);
    ~Equations_learner();

private:
    Ui::Equations_learner *ui;
};
#endif // EQUATIONS_LEARNER_H
