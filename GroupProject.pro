#-------------------------------------------------
#
# Project created by QtCreator 2016-04-02T16:58:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GroupProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Item.cpp \
    Order.cpp \
    inventory.cpp

HEADERS  += mainwindow.h \
    Item.h \
    Order.h \
    inventory.h

FORMS    += mainwindow.ui
