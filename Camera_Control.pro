#-------------------------------------------------
#
# Project created by QtCreator 2016-02-03T10:12:24
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Camera_Control
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:\\opencv310\\include \
                C:\\opencv310\\include\\opencv \
                C:\\opencv310\\include\\opencv2

LIBS += C:\\opencv310\\lib\\opencv_world310.lib \
        C:\\opencv310\\lib\\opencv_world310d.lib
