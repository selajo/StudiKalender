QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
MYSQL_LIBS=-lmysqld


include(gtest_dependency.pri)

MYSQL_LIBS=-lmysqld


DEFINES += QT_DEPRECATED_WARNINGS
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread

HEADERS += \
        tst_101_104.h

SOURCES += \
        main.cpp
