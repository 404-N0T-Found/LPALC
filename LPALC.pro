QT += core
QT -= gui

TARGET = local-cycles-LPA
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    src/node.cpp \
    src/network.cpp \

HEADERS += \
    src/node.h \
    src/network.h \

CONFIG += c++11
