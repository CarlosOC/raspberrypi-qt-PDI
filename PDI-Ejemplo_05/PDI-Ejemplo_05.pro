#-------------------------------------------------
#
# Project created by QtCreator 2016-09-07T14:39:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PDI-Ejemplo_05
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

LIBS += -L/opt/vc/lib
LIBS += -L/usr/local/lib -lraspicam
LIBS += -L/usr/local/lib -lraspicam_cv
