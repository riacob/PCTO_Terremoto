QT       += core gui
QT       += gui
QT       += multimedia
QT       += multimediawidgets
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aiuto.cpp \
    animatedsplashscreen.cpp \
    com.cpp \
    dial.cpp \
    grafico.cpp \
    hdlc.cpp \
    impostazioni.cpp \
    main.cpp \
    mainwindow.cpp \
    manometro_dialog.cpp \
    scudettomalignani.cpp \
    serialtransreceiver.cpp \
    video.cpp

HEADERS += \
    aiuto.h \
    animatedsplashscreen.h \
    com.h \
    dial.h \
    grafico.h \
    hdlc.h \
    impostazioni.h \
    mainwindow.h \
    manometro_dialog.h \
    scudettomalignani.h \
    serialtransreceiver.h \
    video.h

FORMS += \
    aiuto.ui \
    animatedsplashscreen.ui \
    com.ui \
    impostazioni.ui \
    mainwindow.ui \
    manometro_dialog.ui \
    scudettomalignani.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Immagini_tasti.qrc \
    animatedsplashscreen.qrc \
    main.qrc \
    manometro.qrc \
    video.qrc
