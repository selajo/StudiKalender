QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


MYSQL_LIBS=-lmysqld
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Datenbank.cpp \
    Kalender.cpp \
    Lernplan.cpp \
    Studienfach_Klasse.cpp \
    Termin_Klasse.cpp \
    deleteprofil.cpp \
    lernplanui.cpp \
    main.cpp \
    mainwindow.cpp \
    monatsansicht.cpp \
    password.cpp \
    pbearbeiten.cpp \
    profil.cpp \
    registrieren.cpp \
    studifaecher.cpp \
    studifaecher_verwalten.cpp \
    tagesansicht.cpp \
    termin_bearbeiten.cpp \
    termin_erstellen.cpp \
    username.cpp \
    wochenansicht.cpp \
    Nutzerprofil.cpp


HEADERS += \
    Datenbank.h \
    Kalender.h \
    Lernplan.h \
    Nutzerprofil.h \
    QList_Model_AusgabeTagesansicht.h \
    QList_Model_FuerAusgabeStudienfaecher.h \
    Reminder_Klasse.h \
    Studienfach_Klasse.h \
    Termin_Klasse.h \
    deleteprofil.h \
    lernplanui.h \
    mainwindow.h \
    monatsansicht.h \
    password.h \
    pbearbeiten.h \
    profil.h \
    registrieren.h \
    studifaecher.h \
    studifaecher_verwalten.h \
    tagesansicht.h \
    termin_bearbeiten.h \
    termin_erstellen.h \
    username.h \
    wochenansicht.h

FORMS += \
    deleteprofil.ui \
    lernplanui.ui \
    mainwindow.ui \
    monatsansicht.ui \
    password.ui \
    pbearbeiten.ui \
    profil.ui \
    registrieren.ui \
    studifaecher.ui \
    studifaecher_verwalten.ui \
    tagesansicht.ui \
    termin_bearbeiten.ui \
    termin_erstellen.ui \
    username.ui \
    wochenansicht.ui

RC_ICONS = Logo_quadr.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
