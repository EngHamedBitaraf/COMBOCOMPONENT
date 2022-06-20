#-------------------------------------------------
#
# Project created by QtCreator 2016-10-04T22:23:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CollapsibleSection
TEMPLATE = app


SOURCES += main.cpp\
        TreeViewModel.cpp \
        mainwindow.cpp \
        section.cpp

HEADERS  += mainwindow.h \
    TreeViewModel.h \
    section.h

FORMS    += mainwindow.ui

RESOURCES += \
    icon.qrc
