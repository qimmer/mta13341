#-------------------------------------------------
#
# Project created by QtCreator 2013-11-05T09:31:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrackerTest
TEMPLATE = app

INCLUDEPATH += "C:\Program Files\Microsoft SDKs\Kinect\v1.8\inc"

DEPENDPATH += . ../Tracking
INCLUDEPATH +=  ../Tracking

CONFIG(debug, debug|release) {
        LIBS+=  -L../Tracking/debug
    } else {
        LIBS+=  -L../Tracking/release
    }

LIBS+= -lTracking

SOURCES += main.cpp

HEADERS  +=

FORMS    +=
