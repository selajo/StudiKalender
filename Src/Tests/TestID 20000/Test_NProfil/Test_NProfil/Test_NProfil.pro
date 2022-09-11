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
        tst_ProcilChangeEmail.h \
        tst_ProfilCheckEmail.h \
        tst_ProfilCheckPasswort.h \
        tst_ProfilCheckVorhanden.h \
        tst_ProfilGetImage.h \
        tst_ProfilInsert.h \
        tst_ProfilLaden.h \
        tst_ProfilLoeschen.h \
        tst_ProfilNutzernameVergessen.h \
        tst_ProfilPasswortVergessen.h \
        tst_ProfilUpdatePasswort.h \
        tst_ProfilUploadProfil.h \
        tst_tst.h

SOURCES += \
        main.cpp
