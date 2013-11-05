#-------------------------------------------------
#
# Project created by QtCreator 2013-11-05T09:20:23
#
#-------------------------------------------------

QT       -= core gui

TARGET = Tracking
TEMPLATE = lib

DEFINES += TRACKING_LIBRARY

SOURCES += tracking.cpp

HEADERS += tracking.h\
        tracking_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
