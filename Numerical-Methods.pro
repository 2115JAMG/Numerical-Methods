#-------------------------------------------------
#
# Project created by QtCreator 2017-11-11T14:25:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Numerical-Methods
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        nummethods.cpp\
        nr.cpp\
        puntofijo.cpp\
        eliminaciongaussiana.cpp\
        gaussseidel.cpp\
        euler.cpp\
        difnum.cpp\
        rregresionlinealmultiple.cpp\
        rregresion_lineal.cpp\
        rungekutta.cpp\
        interpolacionlagrange.cpp\
        integracion.cpp
HEADERS += \
        nummethods.h\
        nr.h\
        puntofijo.h\
        eliminaciongaussiana.h\
        gaussseidel.h\
        euler.h\
        difnum.h\
        rregresionlinealmultiple.h\
        rregresion_lineal.h\
        rungekutta.h\
        interpolacionlagrange.h\
        integracion.h

FORMS += \
        nummethods.ui\
        nr.ui\
        puntofijo.ui\
        eliminaciongaussiana.ui\
        gaussseidel.ui\
        euler.ui\
        difnum.ui\
        rregresionlinealmultiple.ui\
        rregresion_lineal.ui\
        rungekutta.ui\
        interpolacionlagrange.ui\
        integracion.ui

RC_ICONS = icono.ico

#one mentions to each of the programs par the integrative project, placing their names and extensions as noted on the top, and choose the put icon

RESOURCES += \
    imagen.qrc


