QT += core
QT -= gui

TARGET = LPACL
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    src/network.cpp \

HEADERS += \
    src/network.h \

CONFIG += c++11
