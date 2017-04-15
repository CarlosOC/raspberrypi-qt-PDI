#-----------------------------------------------------------    #
# Project created by QtCreator 2016-05-21T11:34:35              #
# En este proyecto se lee una imagen, y se cambia               #
# el color de los pixeles,pero ademas se pone en "H"            #
# y en "L" el PIN 11 del RaspberryPI para medir el              #
# tiempo que se tarda el algoritmo.                             #
# Sacar los comentarios para compilar en RaspberyPI             #
# Este ejemplo es una aplicacion de Terminal                    #
# Serviria para medir el tiempo de ejecucion del algoritmo      #
# Se requiere un osciloscopio y medir el PIN 11 del Raspberry   #
# Deberia ser mucho menos a la mitad de 50ms                    #
#-------------------------------------------------------------  #

QT       += core gui

TARGET = PDI-Ejemplo_06
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    programa.cpp

HEADERS += \
    pdi-ejemplo_06.h

#LIBS += -L/usr/local/lib -lwiringPi    // Solo para el RaspberryPi
#LIBS += -L/usr/local/lib -lpthread     // Solo para el RaspberryPi
#LIBS += -L/opt/vc/lib
#LIBS += -L/usr/local/lib -lraspicam
#LIBS += -L/usr/local/lib -lraspicam_cv
