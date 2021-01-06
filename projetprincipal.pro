QT       += core gui charts
QT += sql
QT       += serialport
QT       += core gui printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agence.cpp \
    arduino.cpp \
    connexion.cpp \
    departement.cpp \
    dialogbaaedlogin.cpp \
    dialoghedi.cpp \
    dialoglogin.cpp \
    dialogyassine.cpp \
    employe.cpp \
    main.cpp \
    mainwindow.cpp \
    models.cpp \
    stat_depart.cpp \
    stat_employee.cpp \
    statayadi.cpp \
    vehicule.cpp

HEADERS += \
    agence.h \
    arduino.h \
    connexion.h \
    departement.h \
    dialogbaaedlogin.h \
    dialoghedi.h \
    dialoglogin.h \
    dialogyassine.h \
    employe.h \
    mainwindow.h \
    models.h \
    stat_depart.h \
    stat_employee.h \
    statayadi.h \
    vehicule.h

FORMS += \
    dialogbaaedlogin.ui \
    dialoghedi.ui \
    dialoglogin.ui \
    dialogyassine.ui \
    mainwindow.ui \
    stat_depart.ui \
    stat_employee.ui \
    statayadi.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    dosres.qrc
