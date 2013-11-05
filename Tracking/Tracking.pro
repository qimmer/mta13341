#-------------------------------------------------
#
# Project created by QtCreator 2013-11-05T09:20:23
#
#-------------------------------------------------

QT       += gui core

TARGET = Tracking
TEMPLATE = lib

DEFINES += TRACKING_LIBRARY

INCLUDEPATH += "../libfreenect-master/include"

SOURCES += tracking.cpp \
    sensor.cpp \
    playertracker.cpp

HEADERS += tracking.h\
        tracking_global.h \
    sensor.h \
    playertracker.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
