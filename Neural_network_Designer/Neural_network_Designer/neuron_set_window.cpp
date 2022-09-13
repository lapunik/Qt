#include "neuron_set_window.h"

Neuron_set_window::Neuron_set_window(QWidget *parent) : QMainWindow(parent)
{
    set_window();

//    network_tabs = new QTabWidget(this);
//    network_tabs->setContentsMargins(0,0,0,0);
//    network_tabs->setTabsClosable(true);

//    result_wigets = new QVector<Result_widget*>();

//    connect(network_tabs, SIGNAL(tabBarClicked(int)), this, SLOT(new_tab(int)));
//    connect(new_button, SIGNAL(clicked()), this, SLOT(new_tab_left_bar()));
//    connect(network_tabs, SIGNAL(tabCloseRequested(int)), this, SLOT(remove_tab(int)));

//    network_tabs->addTab(new QWidget(this),QIcon(":/res/icon/plus2"),"");

//    network_tabs->setIconSize(QSize(10,10));

//    network_tabs->setStyleSheet("QTabWidget::pane {"
//                                "border-top: 2px solid #C2C7CB;"
//                                "}"
//                                );

//    layout_main_vertical->addWidget(network_tabs);

}

Neuron_set_window::~Neuron_set_window()
{

    if(layout_main_horizontal != nullptr)
    {
        layout_main_horizontal = nullptr;
    }
    if(layout_main_vertical != nullptr)
    {
        layout_main_vertical = nullptr;
    }
    if(window != nullptr)
    {
        window = nullptr;
    }
    if(search != nullptr)
    {
        search = nullptr;
    }
    if(icon != nullptr)
    {
        icon = nullptr;
    }
    if(title != nullptr)
    {
        title = nullptr;
    }
    if(minimize_button != nullptr)
    {
        minimize_button = nullptr;
    }
    if(maximize_button != nullptr)
    {
        maximize_button = nullptr;
    }
    if(exit_button != nullptr)
    {
        exit_button = nullptr;
    }
    if(layout_title_bar != nullptr)
    {
        layout_title_bar = nullptr;
    }
    if(title_bar_w != nullptr)
    {
        title_bar_w = nullptr;
    }
    if(settings_button != nullptr)
    {
        settings_button = nullptr;
    }
    if(about_button != nullptr)
    {
        about_button = nullptr;
    }
    if(load_button != nullptr)
    {
        load_button = nullptr;
    }
    if(save_button != nullptr)
    {
        save_button = nullptr;
    }
    if(new_button != nullptr)
    {
        new_button = nullptr;
    }
    if(exit_button2 != nullptr)
    {
        exit_button2 = nullptr;
    }
    if(layout_left_bar != nullptr)
    {
        layout_left_bar = nullptr;
    }
    if(left_bar_w != nullptr)
    {
        left_bar_w = nullptr;
    }

}

void Neuron_set_window::set_left_layout()
{
    exit_button2 = new QPushButton(this);
    exit_button2->setFixedSize(QSize(40,25));
    exit_button2->setIcon(QIcon(":/res/icon/exit2"));
    exit_button2->setIconSize(QSize(20,20));
    exit_button2->setStyleSheet("QPushButton"
                                "{"
                                "border: none;"
                                "border-radius: 3px;"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "background-color:rgba(200, 200, 200, 255);"
                                "}"
                                );
    connect(exit_button2,SIGNAL(clicked()),qApp,SLOT(quit()));



    new_button = new QPushButton(this);
    new_button->setFixedSize(QSize(40,25));
    new_button->setIcon(QIcon(":/res/icon/new"));
    new_button->setIconSize(QSize(23,23));
    new_button->setStyleSheet("QPushButton"
                              "{"
                              "border: none;"
                              "border-radius: 3px;"
                              "}"
                              "QPushButton:hover"
                              "{"
                              "background-color:rgba(200, 200, 200, 255);"
                              "}"
                              );

    save_button = new QPushButton(this);
    save_button->setFixedSize(QSize(40,25));
    save_button->setIcon(QIcon(":/res/icon/save"));
    save_button->setIconSize(QSize(20,20));
    save_button->setStyleSheet("QPushButton"
                               "{"
                               "border: none;"
                               "border-radius: 3px;"
                               "}"
                               "QPushButton:hover"
                               "{"
                               "background-color:rgba(200, 200, 200, 255);"
                               "}"
                               );

    load_button = new QPushButton(this);
    load_button->setFixedSize(QSize(40,25));
    load_button->setIcon(QIcon(":/res/icon/load"));
    load_button->setIconSize(QSize(20,20));
    load_button->setStyleSheet("QPushButton"
                               "{"
                               "border: none;"
                               "border-radius: 3px;"
                               "}"
                               "QPushButton:hover"
                               "{"
                               "background-color:rgba(200, 200, 200, 255);"
                               "}"
                               );

    settings_button = new QPushButton(this);
    settings_button->setFixedSize(QSize(40,25));
    settings_button->setIcon(QIcon(":/res/icon/settings"));
    settings_button->setIconSize(QSize(23,23));
    settings_button->setStyleSheet("QPushButton"
                                   "{"
                                   "border: none;"
                                   "border-radius: 3px;"
                                   "}"
                                   "QPushButton:hover"
                                   "{"
                                   "background-color:rgba(200, 200, 200, 255);"
                                   "}"
                                   );

    about_button = new QPushButton(this);
    about_button->setFixedSize(QSize(40,25));
    about_button->setIcon(QIcon(":/res/icon/about"));
    about_button->setIconSize(QSize(20,20));
    about_button->setStyleSheet("QPushButton"
                                "{"
                                "border: none;"
                                "border-radius: 3px;"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "background-color:rgba(200, 200, 200, 255);"
                                "}"
                                );

    QLabel * label = new QLabel("");
    label->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    layout_left_bar->setSpacing(5);
    layout_left_bar->addWidget(new_button);
    layout_left_bar->addWidget(save_button);
    layout_left_bar->addWidget(load_button);
    layout_left_bar->addWidget(exit_button2);
    layout_left_bar->addWidget(label);
    layout_left_bar->addWidget(about_button);
    layout_left_bar->addWidget(settings_button);

}

void Neuron_set_window::set_title_layout()
{
    exit_button = new QPushButton(this);
    exit_button->setFixedSize(QSize(40,25));
    exit_button->setIcon(QIcon(":/res/icon/exit"));
    exit_button->setIconSize(QSize(10,10));
    exit_button->setStyleSheet(QString("QPushButton{"
                                       "background-color: rgba(255, 100, 100, 255);"
                                       "color: black;"
                                       "border: none;"
                                       "border-radius: 3px;"
                                       "}"
                                       "QPushButton:hover"
                                       "{"
                                       "background-color:rgba(200, 200, 200, 255);"
                                       "}"));
    connect(exit_button,SIGNAL(clicked()),qApp,SLOT(quit()));

    maximize_button = new QPushButton(this);
    maximize_button->setFixedSize(QSize(40,25));
    maximize_button->setIcon(QIcon(":/res/icon/maximize"));
    maximize_button->setIconSize(QSize(10,10));
    maximize_button->setStyleSheet(QString("QPushButton{"
                                           "background-color: rgba(240, 240, 240, 255);"
                                           "color: black;"
                                           "border: none;"
                                           "border-radius: 3px;"
                                           "}"
                                           "QPushButton:hover"
                                           "{"
                                           "background-color:rgba(200, 200, 200, 255);"
                                           "}"));

    connect(maximize_button,SIGNAL(clicked()),this,SLOT(maximize()));

    minimize_button = new QPushButton(this);
    minimize_button->setFixedSize(QSize(40,25));
    minimize_button->setIcon(QIcon(":/res/icon/minimize"));
    minimize_button->setIconSize(QSize(10,10));

    minimize_button->setStyleSheet(QString("QPushButton{"
                                           "background-color: rgba(240, 240, 240, 255);"
                                           "color: black;"
                                           "border: none;"
                                           "border-radius: 3px;"
                                           "background-position: center bottom;"
                                           "}"
                                           "QPushButton:hover"
                                           "{"
                                           "background-color:rgba(200, 200, 200, 255);"
                                           "}"));

    connect(minimize_button,SIGNAL(clicked()),this,SLOT(minimize()));

    title = new QLabel(APP_TITLE);
    title->setStyleSheet("font: bold large");
    icon = new QPushButton(this);
    icon->setFixedSize(40,40);

    icon->setIcon(QIcon(":/res/icon/main_icon"));
    icon->setIconSize(QSize(30,30));


    QLabel *space = new QLabel("");
    space->setFixedSize(3,1);
    QLabel *space2 = new QLabel("");
    space2->setFixedSize(3,1);
    QLabel *space3 = new QLabel("");
    space3->setFixedSize(10,1);
    search = new QLineEdit(this);
    search->setText("Search");
    search->addAction(QIcon(":/res/icon/search"),QLineEdit::LeadingPosition);
    search->setStyleSheet("QLineEdit"
                          "{"
                          "background-color:rgba(255, 255, 255, 255);"
                          "border-radius: 5px;"
                          "color: black"
                          "}");
    search->setFixedSize(150,25);

    layout_title_bar->addWidget(space2);
    layout_title_bar->addWidget(icon);
    layout_title_bar->addWidget(title);
    layout_title_bar->addWidget(search);
    layout_title_bar->addWidget(space3);
    layout_title_bar->addWidget(minimize_button);
    layout_title_bar->addWidget(maximize_button);
    layout_title_bar->addWidget(exit_button);
    layout_title_bar->addWidget(space);
    layout_title_bar->setSpacing(5);
    layout_title_bar->setContentsMargins(0,0,0,0);

}

void Neuron_set_window::set_window()
{
    resize(900,600);
    setWindowIcon(QIcon(":/res/icon/main_icon"));
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    // Layouts for bars
    layout_main_vertical = new QVBoxLayout(this);
    layout_main_vertical->setSpacing(0);
    layout_main_vertical->setContentsMargins(0,0,0,0);

    layout_main_horizontal = new QHBoxLayout(this);
    layout_main_horizontal->setSpacing(0);
    layout_main_horizontal->setContentsMargins(0,0,0,0);

    // Title bar
    layout_title_bar = new QHBoxLayout(this);
    set_title_layout();
    title_bar_w = new QWidget(this);
    title_bar_w->setFixedHeight(40);
    title_bar_w->setStyleSheet("QWidget{"
                               "background-color: rgba(100, 100, 100, 255);"
                               "border-top-left-radius: 0px;"
                               "border-bottom-left-radius: 0px;"
                               "border-bottom-right-radius: 0px;"
                               "color: white}");
    title_bar_w->setLayout(layout_title_bar);

    layout_main_vertical->addWidget(title_bar_w);

    // Left bar
    layout_left_bar = new QVBoxLayout(this);
    set_left_layout();
    left_bar_w = new QWidget(this);
    left_bar_w->setStyleSheet("QWidget{background-color: rgba(0, 0, 100, 255);"
                              "border-top-right-radius: 0px;"
                              "border-bottom-right-radius: 0px;"

                              "color: white}");
    left_bar_w->setLayout(layout_left_bar);

    layout_main_horizontal->addWidget(left_bar_w);
    layout_main_horizontal->addLayout(layout_main_vertical);

    window = new QWidget(this);
    window->setLayout(layout_main_horizontal);
    window->setStyleSheet("QWidget{"
                          "background-color: rgba(255, 255, 255, 255);"
                          "border: none;"
                          "border-radius: 10px;"
                          "}");

    setCentralWidget(window);

}

void Neuron_set_window::maximize()
{
    if(windowState() == Qt::WindowMaximized)
    {
        setWindowState(Qt::WindowNoState);
        maximize_button->setIcon(QIcon(":/res/icon/maximize"));
        maximize_button->setIconSize(QSize(10,10));
        window->setStyleSheet("QWidget{"
                              "background-color: rgba(255, 255, 255, 255);"
                              "border: none;"
                              "border-radius: 10px;"
                              "}");

    }
    else
    {
        setWindowState(Qt::WindowMaximized);
        maximize_button->setIcon(QIcon(":/res/icon/maximize_2"));
        maximize_button->setIconSize(QSize(12,12));
        window->setStyleSheet("QWidget{"
                              "background-color: rgba(255, 255, 255, 255);"
                              "border: none;"
                              "border-radius: 0px;"
                              "}");
    }


}

void Neuron_set_window::minimize()
{
    setWindowState(Qt::WindowMinimized);
}

//Below two methods partially from Qt Shaped Clock example
void Neuron_set_window::mousePressEvent(QMouseEvent *event)
{
    //From Qt Documentation:
    //Reason why pos() wasn't working is because the global
    //position at time of event may be very different
    //This is why the mpos = event->pos(); line before was
    //possibly causing jumping behavior

    if (event->button() == Qt::LeftButton)
    {
        //Coordinates have been mapped such that the mouse position is relative to the
        //upper left of the main window
        mpos = event->globalPos() - frameGeometry().topLeft();

        //At the moment of mouse click, capture global position and
        //lock the size of window for resizing
        global_mpos = event->globalPos();
        storeWidth = this->width();
        storeHeight= this->height();

        event->accept();

    }

}

void Neuron_set_window::mouseReleaseEvent(QMouseEvent *event)
{
    QApplication::setOverrideCursor(Qt::ArrowCursor);
}

void Neuron_set_window::mouseMoveEvent(QMouseEvent *event)
{

    //mapped mouse relative to upper left of window
    rs_mpos=event->globalPos()-frameGeometry().topLeft();//general position tracker for resizing
    QTextStream out(stdout);

    //How much of the corner is considered a "resizing zone"
    //I was experiencing jumping behavior with rs_size is 10 so
    //I recommend rs_size=50
    int rs_size=50;

    //Big if statement checks if your mouse is in the upper left,
    //upper right, lower left, and lower right
    if ( (abs(rs_mpos.x()) < rs_size && abs(rs_mpos.y()) < rs_size) ||
         (abs(rs_mpos.x()) > this->width()-rs_size && abs(rs_mpos.y()) <rs_size) ||
         (abs(rs_mpos.x()) < rs_size && abs(rs_mpos.y())> this->height()-rs_size) ||
         (abs(rs_mpos.x()) > this->width()-rs_size && abs(rs_mpos.y())> this->height()-rs_size)

         )
    {



        //Below for debugging
        /*
         out << rs_mpos.x() << " , " << rs_mpos.y() << "\n";
         out << "window: " << this->width() << " , " << this->height() << "\n";
         out << "globalpos: " << event->globalPos().x() << " , "
             << event->globalPos().y() << "\n";
         */

        //Use 2x2 matrix to adjust how much you are resizing and how much you
        //are moving. Since the default coordinates are relative to upper left
        //You cannot just have one way of resizing and moving the window.
        //It will depend on which corner you are referring to

        //adjXfac and adjYfac are for calculating the difference between your
        //current mouse position and where your mouse was when you clicked.
        //With respect to the upper left corner, moving your mouse to the right
        //is an increase in coordinates, moving mouse to the bottom is increase
        //etc.
        //However, with other corners this is not so and since I chose to subtract
        //This difference at the end for resizing, adjXfac and adjYfac should be
        //1 or -1 depending on whether moving the mouse in the x or y directions
        //increases or decreases the coordinates respectively.

        //transXfac transYfac is to move the window over. Resizing the window does not
        //automatically pull the window back toward your mouse. This is what
        //transfac is for (translate window in some direction). It will be either
        //0 or 1 depending on whether you need to translate in that direction.

        //Initiate matrix
        int adjXfac=0;
        int adjYfac=0;
        int transXfac=0;
        int transYfac=0;

        //Upper left corner section
        if ( (abs(rs_mpos.x()) < rs_size && abs(rs_mpos.y()) < rs_size)){
            this->setCursor(Qt::SizeFDiagCursor);



            //Upper left. No flipping of axis, no translating window
            adjXfac=1;
            adjYfac=1;

            transXfac=0;
            transYfac=0;



        }
        //Upper right corner section
        else if(abs(rs_mpos.x()) > this->width()-rs_size &&
                abs(rs_mpos.y()) <rs_size){
            this->setCursor(Qt::SizeBDiagCursor);


            //upper right. Flip displacements in mouse movement across x axis
            //and translate window left toward the mouse
            adjXfac=-1;
            adjYfac=1;

            transXfac = 1;
            transYfac =0;

        }

        //Lower left corner section
        else if(abs(rs_mpos.x()) < rs_size &&
                abs(rs_mpos.y())> this->height()-rs_size){
            this->setCursor(Qt::SizeBDiagCursor);

            //lower left. Flip displacements in mouse movement across y axis
            //and translate window up toward mouse
            adjXfac=1;
            adjYfac=-1;

            transXfac=0;
            transYfac=1;


        }
        //Lower right corner section
        else if(abs(rs_mpos.x()) > this->width()-rs_size &&
                abs(rs_mpos.y())> this->height()-rs_size){
            this->setCursor(Qt::SizeFDiagCursor);

            //lower right. Flip mouse displacements on both axis and
            //translate in both x and y direction left and up toward mouse.
            adjXfac=-1;
            adjYfac=-1;

            transXfac=1;
            transYfac=1;
        }

        if (event->buttons()==Qt::LeftButton ){

            //Calculation of displacement. adjXfac=1 means normal displacement
            //adjXfac=-1 means flip over axis
            int adjXdiff = adjXfac*(event->globalPos().x() - global_mpos.x());

            int adjYdiff = adjYfac*(event->globalPos().y() - global_mpos.y());

            //if transfac is 1 then movepoint of mouse is translated
            QPoint movePoint(mpos.x() - transXfac*adjXdiff, mpos.y()-transYfac*adjYdiff);
            move(event->globalPos()-movePoint);
            resize(storeWidth-adjXdiff, storeHeight-adjYdiff);

            event->accept();


        }

    }

    //in any move event if it is not in a resize region use the default cursor
    else{

        this->setCursor(Qt::ArrowCursor);


        //simple move section
        if (event->buttons()==Qt::LeftButton){
            move(event->globalPos() - mpos);
            event->accept();
        }


    }

}
