#-------------------------------------------------
#
# Project created by QtCreator 2016-05-21T11:34:35
#
#-------------------------------------------------

#QT       += core
QT       += core gui
#QT       -= gui

TARGET = PDI-Ejemplo_03
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    programa.cpp

#LIBS += -L/usr/local/lib -lwiringPi    // Solo para el RaspberryPi
#LIBS += -L/usr/local/lib -lpthread     // Solo para el RaspberryPi

HEADERS += \
    Ejemplo3.h
