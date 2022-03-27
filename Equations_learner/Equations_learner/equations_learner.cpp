#include "equations_learner.h"
#include "ui_equations_learner.h"

Equations_learner::Equations_learner(QWidget *parent) : QMainWindow(parent), ui(new Ui::Equations_learner)
{
    ui->setupUi(this);
}

Equations_learner::~Equations_learner()
{
    delete ui;
}

