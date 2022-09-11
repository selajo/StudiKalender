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
    tst_40101.h \
    tst_40102-40103.h \
    tst_40104.h \
    tst_40105.h

SOURCES += \
        main.cpp
