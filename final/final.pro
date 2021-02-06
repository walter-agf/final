QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bala.cpp \
    base.cpp \
    bullet.cpp \
    cannon.cpp \
    cannon_d.cpp \
    fisicas.cpp \
    main.cpp \
    mainwindow.cpp \
    rastro.cpp

HEADERS += \
    bala.h \
    base.h \
    bullet.h \
    cannon.h \
    cannon_d.h \
    fisicas.h \
    mainwindow.h \
    rastro.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    datos.qrc
