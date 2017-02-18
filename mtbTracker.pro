#-------------------------------------------------
#
# Project created by QtCreator 2016-07-04T19:48:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mtbTracker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Tour.cpp \
    logiccode.cpp \
    newtourwindow.cpp

HEADERS  += mainwindow.h \
    Tour.h \
    logiccode.h \
    newtourwindow.h

FORMS    += mainwindow.ui \
    newtourwindow.ui

QMAKE_CXXFLAGS += -std=c++11

OTHER_FILES += \
    testfile.csv
