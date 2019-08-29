#-------------------------------------------------
#
# Project created by QtCreator 2019-08-20T19:06:13
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Login
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    form.cpp \
    myregist.cpp

HEADERS  += widget.h \
    form.h \
    myregist.h

FORMS    += widget.ui \
    form.ui \
    myregist.ui

RESOURCES += \
    pic.qrc
