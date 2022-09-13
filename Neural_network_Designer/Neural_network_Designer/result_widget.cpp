#include "result_widget.h"

Result_widget::Result_widget(QWidget *parent) : QWidget{parent}
{

    layout = new QHBoxLayout(this);
    layout->setSpacing(0);

    tools = new QTabWidget(this);
    setContentsMargins(0,0,0,0);
    //tools->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
//    tools->setStyleSheet("QTabWidget::pane {"
//                         "border: 2px solid #C2C7CB;"
//                         "}"
//                         "QTabBar::tab"
//                         "{"
//                         "height: 50px;"
//                         "width: 150px;"
//                         " }"
//                          );

    structure = new Network_widget();
    settings = new Settings_widget(this);
    connect(settings,SIGNAL(calculate()),this,SLOT(calculate()));
    results = new Results_widget(this);

    tools->addTab(structure,QIcon(":/res/icon/edit"),"Design");
    tools->addTab(settings,QIcon(":/res/icon/settings2"),"Settings");
    tools->addTab(results,QIcon(":/res/icon/results"),"Results");

    tools->setIconSize(QSize(30,30));

    layout->addWidget(tools);

    setLayout(layout);

}


Result_widget::~Result_widget()
{

}

void Result_widget::calculate()
{
    nn_model = new Neural_network_model(structure->get_net(),settings->get_settings());
    results->load_model(nn_model);

}
