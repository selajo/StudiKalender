QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
MYSQL_LIBS=-lmysqld


include(gtest_dependency.pri)

MYSQL_LIBS=-lmysqld

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread

HEADERS += \
        tst_CheckLernplan.h \
        tst_StudienfachVonNutzer.h \
        tst_tst_termineinwoche.h

SOURCES += \
        main.cpp
