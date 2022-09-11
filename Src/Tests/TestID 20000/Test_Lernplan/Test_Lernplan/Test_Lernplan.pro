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
        tst_Konstruktor.h \
        tst_LernplanErstellenStart.h \
        tst_LernplanErstellenTag.h \
        tst_LernplanErstellenWoche.h \
        tst_LernplanLoeschen.h \
        tst_RechneStunden.h \
        tst_checkStunden.h \
        tst_prepareTermine.h \
        tst_setZeroSeconds.h \
        tst_tst_checkenddatum.h

SOURCES += \
        main.cpp
