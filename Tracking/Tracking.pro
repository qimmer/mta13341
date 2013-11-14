#-------------------------------------------------
#
# Project created by QtCreator 2013-11-05T09:20:23
#
#-------------------------------------------------

QT       += gui core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tracking
TEMPLATE = lib

DEFINES += TRACKING_LIBRARY

INCLUDEPATH += "C:\Program Files\Microsoft SDKs\Kinect\v1.8\inc"

win32 {

    ## Windows common build here

    !contains(QMAKE_TARGET.arch, x86_64) {
        LIBS += -L"C:\Program Files\Microsoft SDKs\Kinect\v1.8\lib\x86" -l"Kinect10"

    } else {
       LIBS += -L"C:\Program Files\Microsoft SDKs\Kinect\v1.8\lib\amd64" -l"Kinect10"
    }
}

SOURCES += tracking.cpp \
    sensor.cpp \
    playertracker.cpp \
    velocitymapper.cpp \
    BlobDetector.cpp \
    utility.cpp \
    player.cpp \
    debugwindow.cpp \
    imagedebugger.cpp \
    sensorimagedebugger.cpp \
    blobimagedebugger.cpp \
    playeroverviewdebugger.cpp

HEADERS += tracking.h\
        tracking_global.h \
    sensor.h \
    playertracker.h \
    velocitymapper.h \
    BlobDetector.h \
    utility.h \
    player.h \
    debugwindow.h \
    imagedebugger.h \
    sensorimagedebugger.h \
    blobimagedebugger.h \
    playeroverviewdebugger.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

FORMS += \
    debugwindow.ui \
    imagedebugger.ui \
    blobimagedebugger.ui \
    playeroverviewdebugger.ui
