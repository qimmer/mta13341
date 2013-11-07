#-------------------------------------------------
#
# Project created by QtCreator 2013-11-05T09:20:23
#
#-------------------------------------------------

QT       += gui core

TARGET = Tracking
TEMPLATE = lib

DEFINES += TRACKING_LIBRARY

INCLUDEPATH += "C:\Program Files\Microsoft SDKs\Kinect\v1.8\inc"

LIBS += -L"C:\Program Files\Microsoft SDKs\Kinect\v1.8\lib\x86" -l"Kinect10"

SOURCES += tracking.cpp \
    sensor.cpp \
    playertracker.cpp \
    depthslicer.cpp \
    velocitymapper.cpp

HEADERS += tracking.h\
        tracking_global.h \
    sensor.h \
    playertracker.h \
    depthslicer.h \
    velocitymapper.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
