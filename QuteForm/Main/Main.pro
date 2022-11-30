QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH    += ../Plugs/PlugManager
INCLUDEPATH    += ui/form
INCLUDEPATH    += ui/home

SOURCES += \
    basewidget.cpp \
    formwindow.cpp \
    hintdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    nearformshow.cpp \
    starformshow.cpp \
    createform.cpp \
    createformcell.cpp\
    allformfileshow.cpp

HEADERS += \
    nearformshow.h \
    pluginsInterface.h \
    basewidget.h \
    formwindow.h \
    hintdialog.h \
    mainwindow.h \
    starformshow.h \
    createform.h \
    createformcell.h\
    allformfileshow.h

FORMS += \
    ui/form/formwindow.ui \
    ui/form/hintdialog.ui \
    ui/home/mainwindow.ui \
    ui/home/nearformshow.ui \
    ui/home/starformshow.ui \
    ui/home/allformfileshow.ui \
    ui/form/createform.ui

TRANSLATIONS += \
    QuteForm_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

DESTDIR += ../../Build/Generate #目标路径
TARGET = QuteForm  #软件名

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../Resources/icons/Icons.qrc

