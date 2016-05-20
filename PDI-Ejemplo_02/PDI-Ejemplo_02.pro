#-------------------------------------------------
#
# Project created by QtCreator 2016-05-20T17:03:18
# En este proyecto se lee una imagen, y se cambia
# el color de los pixeles,pero ademas se pone en "H"
# y en "L" el PIN 11 del RaspberryPI para medir el
# tiempo que se tarda el algoritmo.
# Sacar los comentarios para compilar en RaspberyPI
#----------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PDI-Ejemplo_02
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui
#LIBS += -L/usr/local/lib -lwiringPi    // Solo para el RaspberryPi
#LIBS += -L/usr/local/lib -lpthread     // Solo para el RaspberryPi
