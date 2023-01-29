#include "neuron_settings_window.h"

Neuron_settings_window::Neuron_settings_window(Neuron *n ,QWidget *parent): QDialog{parent}
{
    neuron = n;
    original_func = n->get_function();

    set_window();

    mp_main_layout = new QVBoxLayout();
    mp_sub_layout = new QHBoxLayout();
    mp_graph_layout = new QVBoxLayout();
    mp_button_layout = new QHBoxLayout();

    mp_main_layout->addLayout(mp_sub_layout);

    mp_list_widget = new QListWidget();
    mp_list_widget->setFixedWidth(180);
    mp_list_widget->setStyleSheet(QString("QListWidget{"
                                       "background-color: rgba(255, 255, 255, 255);"
                                       "color: rgba(0, 0, 0, 255);"
                                       "border: none;"
                                       "border-radius: 3px;"
                                       "}"
                                       "}"));

    Neuron *temp;

    for(int i = 0; i < static_cast<int>(Neuron::output_e)-1;i++)
    {
        temp = new Neuron(static_cast<Neuron::func>(i));
        mp_list_widget->addItem(temp->get_name());
    }

    mp_list_widget->setCurrentRow(0);

    connect(mp_list_widget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(list_clicked(QListWidgetItem*)));

    mp_equation = new QLabel();

    mp_equation->setFixedHeight(100);
    equation.load(":/res/equation/id");
    mp_equation->setAlignment(Qt::AlignCenter);
    //equation = equation.scaled(QSize(100,50));
    mp_equation->setPixmap(equation);
    //mp_equation->setScaledContents(true);

    mp_picture = new QLabel();

    mp_graph_layout->addWidget(mp_picture);
    mp_graph_layout->addWidget(mp_equation);

    graph.load(":/res/graphs/id");
    mp_picture->setPixmap(graph);
    //mp_picture->setScaledContents(true);
    //mp_picture->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);

    mp_picture->setStyleSheet(QString("QLabel{"
                                       "background-color: rgba(255, 255, 255, 255);"
                                       "color: rgba(0, 0, 0, 255);"
                                       "border: none;"
                                       "border-radius: 3px;"
                                       "}"
                                       "}"));

    mp_equation->setStyleSheet(QString("QLabel{"
                                       "background-color: rgba(255, 255, 255, 255);"
                                       "color: rgba(0, 0, 0, 255);"
                                       "border: none;"
                                       "border-radius: 3px;"
                                       "}"
                                       "}"));


    mp_sub_layout->addWidget(mp_list_widget);
    mp_sub_layout->addLayout(mp_graph_layout);

    // Ještě nám zbývají tlačítka, tak do hlavního layoutu přidáme jeden pro ně
    mp_main_layout->addLayout(mp_button_layout);

    // Zajistíme si pro tlačítka paměť
    mp_button_ok = new QPushButton(tr("OK"));
    mp_button_ok->setFixedHeight(30);
    mp_button_cancel = new QPushButton(tr("Cancel"));
    mp_button_cancel->setFixedHeight(30);
    mp_button_ok->setStyleSheet(QString("QPushButton{"
                                       "background-color: rgba(100, 100, 100, 255);"
                                       "color: rgba(255, 255, 255, 255);"
                                       "border: none;"
                                       "border-radius: 3px;"
                                       "}"
                                       "QPushButton:hover"
                                       "{"
                                       "background-color:rgba(200, 200, 200, 255);"
                                       "}"));
    mp_button_cancel->setStyleSheet(mp_button_ok->styleSheet());

    connect(mp_button_cancel, SIGNAL(clicked()), this, SLOT(cancel_button_clicked()));
    connect(mp_button_ok, SIGNAL(clicked()), this, SLOT(ok_button_clicked()));

    // a vložíme je do posledního horizontálního boxu
    mp_button_layout->addWidget(mp_button_cancel);
    mp_button_layout->addWidget(mp_button_ok);

    // Teď již jen nastavit dialogu, který layout má použít


    mp_main_widget = new QWidget();
    //mp_main_widget->setFixedHeight(40);
    mp_main_widget->setStyleSheet("QWidget{"
                               "background-color: rgba(230, 230, 230, 255);"
                               //"background-color: rgba(0, 0, 100, 255);"
                               "border-top-left-radius: 0px;"
                               "border-top-right-radius: 0px;"
                               "border-bottom-left-radius: 10px;"
                               "border-bottom-right-radius: 10px;"
                               "color: white}");


    mp_main_widget->setLayout(mp_main_layout);

    layout_main_horizontal->addWidget(mp_main_widget);

}

Neuron_settings_window::~Neuron_settings_window()
{
    if(neuron != nullptr)
    {
        delete neuron;
    }
    if(exit_button != nullptr)
    {
        delete exit_button;
    }
    if(title != nullptr)
    {
        delete title;
    }
    if(mp_button_cancel != nullptr)
    {
        delete mp_button_cancel;
    }
    if(mp_button_ok != nullptr)
    {
        delete mp_button_ok;
    }
    if(mp_equation != nullptr)
    {
        delete mp_equation;
    }
    if(mp_picture != nullptr)
    {
        delete mp_picture ;
    }
    if(mp_list_widget != nullptr)
    {
        delete mp_list_widget;
    }
    if(mp_button_layout != nullptr)
    {
        delete mp_button_layout;
    }
    if(mp_graph_layout != nullptr)
    {
        delete mp_graph_layout;
    }
    if(mp_sub_layout != nullptr)
    {
        delete mp_sub_layout;
    }
    if(mp_main_layout != nullptr)
    {
        delete mp_main_layout;
    }
    if(mp_main_widget != nullptr)
    {
        delete mp_main_widget;
    }
    if(icon != nullptr)
    {
        delete icon;
    }
    if(layout_title_bar != nullptr)
    {
        delete layout_title_bar;
    }
    if(title_bar_w != nullptr)
    {
        delete title_bar_w;
    }
    if(layout_main_horizontal != nullptr)
    {
        delete layout_main_horizontal;
    }

}

void Neuron_settings_window::set_title_layout()
{
    exit_button = new QPushButton(this);
    exit_button->setFixedSize(QSize(40,25));
    exit_button->setIcon(QIcon(":/res/icon/exit"));
    exit_button->setIconSize(QSize(10,10));
    exit_button->setStyleSheet(QString("QPushButton{"
                                       "background-color: rgba(255, 120, 120, 255);"
                                       "color: black;"
                                       "border: none;"
                                       "border-radius: 3px;"
                                       "}"
                                       "QPushButton:hover"
                                       "{"
                                       "background-color:rgba(200, 200, 200, 255);"
                                       "}"));

    connect(exit_button,SIGNAL(clicked()),this,SLOT(cancel_button_clicked()));


    title = new QLabel(TITLE);
    title->setStyleSheet("font: bold large");
    icon = new QPushButton(this);
    icon->setFixedSize(40,40);

    icon->setIcon(QIcon(":/res/icon/graph"));
    icon->setIconSize(QSize(30,30));


    QLabel *space = new QLabel("");
    space->setFixedSize(3,1);
    QLabel *space2 = new QLabel("");
    space2->setFixedSize(3,1);
    QLabel *space3 = new QLabel("");
    space3->setFixedSize(10,1);


    layout_title_bar->addWidget(space2);
    layout_title_bar->addWidget(icon);
    layout_title_bar->addWidget(title);
    layout_title_bar->addWidget(space3);
    layout_title_bar->addWidget(exit_button);
    layout_title_bar->addWidget(space);
    layout_title_bar->setSpacing(5);
    layout_title_bar->setContentsMargins(0,0,0,0);

}

void Neuron_settings_window::set_window()
{
    resize(550,420);
    //setWindowIcon(QIcon(":/res/icon/main_icon"));
    //setWindowTitle(TITLE);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    layout_main_horizontal = new QVBoxLayout();
    layout_main_horizontal->setSpacing(0);
    layout_main_horizontal->setContentsMargins(0,0,0,0);

    layout_title_bar = new QHBoxLayout();
    set_title_layout();
    title_bar_w = new QWidget();
    title_bar_w->setFixedHeight(40);
    title_bar_w->setStyleSheet("QWidget{"
                               "background-color: rgba(100, 100, 100, 255);"
                               "border-top-left-radius: 10px;"
                               "border-top-right-radius: 10px;"
                               "color: white}");
    title_bar_w->setLayout(layout_title_bar);

    layout_main_horizontal->addWidget(title_bar_w);

    setLayout(layout_main_horizontal);

    //setLayout(layout_main_horizontal);

}

void Neuron_settings_window::ok_button_clicked()
{
    close();
}

void Neuron_settings_window::cancel_button_clicked()
{
    neuron->set_function(original_func);
    close();
}


void Neuron_settings_window::list_clicked(QListWidgetItem* item)
{

    if (mp_list_widget ->item(0) == item)
    {

        equation.load(":/res/equation/id");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/id");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(0));
    }
    else if(mp_list_widget ->item(1) == item)
    {

        equation.load(":/res/equation/pow2");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/pow2");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(1));
    }
    else if(mp_list_widget ->item(2) == item)
    {

        equation.load(":/res/equation/pow3");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/pow3");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(2));
    }
    else if(mp_list_widget ->item(3) == item)
    {

        equation.load(":/res/equation/pow4");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/pow4");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(3));
    }
    else if(mp_list_widget ->item(4) == item)
    {

        equation.load(":/res/equation/times");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/times");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(4));
    }
    else if(mp_list_widget ->item(5) == item)
    {

        equation.load(":/res/equation/divide");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/divide");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(5));
    }
    else if(mp_list_widget ->item(6) == item)
    {

        equation.load(":/res/equation/sin");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/sin");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(6));
    }
    else if(mp_list_widget ->item(7) == item)
    {

        equation.load(":/res/equation/cos");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/cos");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(7));
    }
    else if(mp_list_widget ->item(8) == item)
    {

        equation.load(":/res/equation/sigmoid");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/sigmoid");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(8));
    }
    else if(mp_list_widget ->item(9) == item)
    {

        equation.load(":/res/equation/n_sigmoid");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/n_sigmoid");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(9));
    }
    else if(mp_list_widget ->item(10) == item)
    {

        equation.load(":/res/equation/tanh");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/tanh");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(10));
    }
    else if(mp_list_widget ->item(11) == item)
    {

        equation.load(":/res/equation/f_sigmoid");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/f_sigmoid");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(11));
    }
    else if(mp_list_widget ->item(12) == item)
    {

        equation.load(":/res/equation/heaviside");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/heaviside");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(12));
    }
    else if(mp_list_widget ->item(13) == item)
    {

        equation.load(":/res/equation/signum");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/signum");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(13));
    }
    else if(mp_list_widget ->item(14) == item)
    {

        equation.load(":/res/equation/p_id");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/p_id");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(14));
    }
    else if(mp_list_widget ->item(15) == item)
    {

        equation.load(":/res/equation/sat");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/sat");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(15));
    }
    else if(mp_list_widget ->item(16) == item)
    {

        equation.load(":/res/equation/p_sat");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/p_sat");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(16));
    }
    else if(mp_list_widget ->item(17) == item)
    {

        equation.load(":/res/equation/rad");
        mp_equation->setPixmap(equation);

        graph.load(":/res/graphs/rad");
        mp_picture->setPixmap(graph);

        neuron->set_function(static_cast<Neuron::func>(17));
    }
}

//void Neuron_settings_window::mousePressEvent(QMouseEvent *event)
//{
//    //From Qt Documentation:
//    //Reason why pos() wasn't working is because the global
//    //position at time of event may be very different
//    //This is why the mpos = event->pos(); line before was
//    //possibly causing jumping behavior

//    if (event->button() == Qt::LeftButton)
//    {
//        //Coordinates have been mapped such that the mouse position is relative to the
//        //upper left of the main window
//        mpos = event->globalPos() - frameGeometry().topLeft();

//        //At the moment of mouse click, capture global position and
//        //lock the size of window for resizing
//        global_mpos = event->globalPos();
//        storeWidth = this->width();
//        storeHeight= this->height();

//        event->accept();

//    }

//}

//void Neuron_settings_window::mouseReleaseEvent(QMouseEvent *event)
//{
//    QApplication::setOverrideCursor(Qt::ArrowCursor);
//}

//void Neuron_settings_window::mouseMoveEvent(QMouseEvent *event)
//{

//    //mapped mouse relative to upper left of window
//    rs_mpos=event->globalPos()-frameGeometry().topLeft();//general position tracker for resizing
//    QTextStream out(stdout);

//    //How much of the corner is considered a "resizing zone"
//    //I was experiencing jumping behavior with rs_size is 10 so
//    //I recommend rs_size=50
//    int rs_size=50;

//    //Big if statement checks if your mouse is in the upper left,
//    //upper right, lower left, and lower right
//    if ( (abs(rs_mpos.x()) < rs_size && abs(rs_mpos.y()) < rs_size) ||
//         (abs(rs_mpos.x()) > this->width()-rs_size && abs(rs_mpos.y()) <rs_size) ||
//         (abs(rs_mpos.x()) < rs_size && abs(rs_mpos.y())> this->height()-rs_size) ||
//         (abs(rs_mpos.x()) > this->width()-rs_size && abs(rs_mpos.y())> this->height()-rs_size)

//         )
//    {



//        //Below for debugging
//        /*
//         out << rs_mpos.x() << " , " << rs_mpos.y() << "\n";
//         out << "window: " << this->width() << " , " << this->height() << "\n";
//         out << "globalpos: " << event->globalPos().x() << " , "
//             << event->globalPos().y() << "\n";
//         */

//        //Use 2x2 matrix to adjust how much you are resizing and how much you
//        //are moving. Since the default coordinates are relative to upper left
//        //You cannot just have one way of resizing and moving the window.
//        //It will depend on which corner you are referring to

//        //adjXfac and adjYfac are for calculating the difference between your
//        //current mouse position and where your mouse was when you clicked.
//        //With respect to the upper left corner, moving your mouse to the right
//        //is an increase in coordinates, moving mouse to the bottom is increase
//        //etc.
//        //However, with other corners this is not so and since I chose to subtract
//        //This difference at the end for resizing, adjXfac and adjYfac should be
//        //1 or -1 depending on whether moving the mouse in the x or y directions
//        //increases or decreases the coordinates respectively.

//        //transXfac transYfac is to move the window over. Resizing the window does not
//        //automatically pull the window back toward your mouse. This is what
//        //transfac is for (translate window in some direction). It will be either
//        //0 or 1 depending on whether you need to translate in that direction.

//        //Initiate matrix
//        int adjXfac=0;
//        int adjYfac=0;
//        int transXfac=0;
//        int transYfac=0;

//        //Upper left corner section
//        if ( (abs(rs_mpos.x()) < rs_size && abs(rs_mpos.y()) < rs_size)){
//            this->setCursor(Qt::SizeFDiagCursor);



//            //Upper left. No flipping of axis, no translating window
//            adjXfac=1;
//            adjYfac=1;

//            transXfac=0;
//            transYfac=0;



//        }
//        //Upper right corner section
//        else if(abs(rs_mpos.x()) > this->width()-rs_size &&
//                abs(rs_mpos.y()) <rs_size){
//            this->setCursor(Qt::SizeBDiagCursor);


//            //upper right. Flip displacements in mouse movement across x axis
//            //and translate window left toward the mouse
//            adjXfac=-1;
//            adjYfac=1;

//            transXfac = 1;
//            transYfac =0;

//        }

//        //Lower left corner section
//        else if(abs(rs_mpos.x()) < rs_size &&
//                abs(rs_mpos.y())> this->height()-rs_size){
//            this->setCursor(Qt::SizeBDiagCursor);

//            //lower left. Flip displacements in mouse movement across y axis
//            //and translate window up toward mouse
//            adjXfac=1;
//            adjYfac=-1;

//            transXfac=0;
//            transYfac=1;


//        }
//        //Lower right corner section
//        else if(abs(rs_mpos.x()) > this->width()-rs_size &&
//                abs(rs_mpos.y())> this->height()-rs_size){
//            this->setCursor(Qt::SizeFDiagCursor);

//            //lower right. Flip mouse displacements on both axis and
//            //translate in both x and y direction left and up toward mouse.
//            adjXfac=-1;
//            adjYfac=-1;

//            transXfac=1;
//            transYfac=1;
//        }

//        if (event->buttons()==Qt::LeftButton ){

//            //Calculation of displacement. adjXfac=1 means normal displacement
//            //adjXfac=-1 means flip over axis
//            int adjXdiff = adjXfac*(event->globalPos().x() - global_mpos.x());

//            int adjYdiff = adjYfac*(event->globalPos().y() - global_mpos.y());

//            //if transfac is 1 then movepoint of mouse is translated
//            QPoint movePoint(mpos.x() - transXfac*adjXdiff, mpos.y()-transYfac*adjYdiff);
//            move(event->globalPos()-movePoint);
//            resize(storeWidth-adjXdiff, storeHeight-adjYdiff);

//            event->accept();


//        }

//    }

//    //in any move event if it is not in a resize region use the default cursor
//    else{

//        this->setCursor(Qt::ArrowCursor);


//        //simple move section
//        if (event->buttons()==Qt::LeftButton){
//            move(event->globalPos() - mpos);
//            event->accept();
//        }


//    }

//}

//void Neuron_settings_window::resizeEvent(QResizeEvent *event)
//{
//    redraw();
//    QWidget::resizeEvent(event);
//}

//void Neuron_settings_window::redraw()
//{
//    QPixmap pix;
//    pix.load(":/res/icon/plus");
//    pix = pix.scaled(mp_picture->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation);
//    mp_picture->setPixmap(pix);
//}
