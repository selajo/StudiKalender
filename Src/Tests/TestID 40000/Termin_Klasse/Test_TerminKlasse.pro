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
    tst_40001.h \
    tst_40002-40003.h \
    tst_40004-40005.h \
    tst_40006-40008.h \
    tst_40009-40010.h \
    tst_40011-40016.h \
    tst_40017-40018.h \
    tst_40019.h

SOURCES += \
        main.cpp
