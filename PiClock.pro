#-------------------------------------------------
#
# Project created by QtCreator 2017-09-28T08:28:51
#
#-------------------------------------------------

QT       += core gui network websockets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PiClock
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -std=c++0x
CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    weekdaybutton.cpp \
    musicplayer.cpp \
    volumeknobthread.cpp \
    mopidyreader.cpp \
    scrolltext.cpp \
    alarmsettings.cpp \
    temperature.cpp

HEADERS += \
        mainwindow.h \
    weekdaybutton.h \
    musicplayer.h \
    volumeknobthread.h \
    mopidyreader.h \
    scrolltext.h \
    alarmsettings.h \
    temperature.h

FORMS += \
        mainwindow.ui \
    musicplayer.ui \
    alarmsettings.ui

RESOURCES += \
    resourses.qrc

!macx {
    LIBS += WiringPi/wiringPi/libwiringPi.so.2.44
}
