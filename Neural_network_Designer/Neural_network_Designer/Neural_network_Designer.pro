QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    button_roundted.cpp \
    layer_widget.cpp \
    main.cpp \
    main_window.cpp \
    model_settings.cpp \
    my_button.cpp \
    network_widget.cpp \
    neural_network_model.cpp \
    neuron.cpp \
    neuron_settings_window.cpp \
    pbPlots.cpp \
    result_widget.cpp \
    results_widget.cpp \
    settings_widget.cpp \
    supportLib.cpp

HEADERS += \
    button_roundted.h \
    layer_widget.h \
    main_window.h \
    model_settings.h \
    my_button.h \
    network_widget.h \
    neural_network_model.h \
    neuron.h \
    neuron_settings_window.h \
    pbPlots.h \
    result_widget.h \
    results_widget.h \
    settings_widget.h \
    supportLib.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
     Resources.qrc
