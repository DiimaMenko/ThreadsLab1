#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T14:11:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThreadsLab1
TEMPLATE = app


SOURCES += main.cpp\
        mymainwindow.cpp \
    calculateintegral.cpp \
    resultwidget.cpp \
    mythread.cpp

HEADERS  += mymainwindow.h \
    calculateintegral.h \
    resultwidget.h \
    mythread.h

FORMS    += mymainwindow.ui
