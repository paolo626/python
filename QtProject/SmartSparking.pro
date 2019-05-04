#-------------------------------------------------
#
# Project created by QtCreator 2018-04-05T17:37:38
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartSparking
TEMPLATE = app


SOURCES += main.cpp\
    control.cpp \
    loginDialog.cpp \
    setserial.cpp \
    startshow.cpp \
    startload.cpp

HEADERS  += \
    control.h \
    loginDialog.h \
    setserial.h \
    startshow.h \
    startload.h

FORMS    += \
    loginDialog.ui \
    startshow.ui \
    startload.ui
