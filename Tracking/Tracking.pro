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
    depthslicer.cpp \
    velocitymapper.cpp \
    BlobDetector.cpp

HEADERS += tracking.h\
        tracking_global.h \
    sensor.h \
    playertracker.h \
    depthslicer.h \
    velocitymapper.h \
    BlobDetector.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
