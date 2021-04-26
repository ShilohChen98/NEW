#-------------------------------------------------
#
# Project created by QtCreator 2021-03-20T20:54:31
#
#-------------------------------------------------

QT       += core gui sql
QT       += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cu1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    main.cpp \
    form1.cpp

HEADERS += \
        mainwindow.h \
    form1.h

FORMS += \
    mainwindow.ui \
    form1.ui
INCLUDEPATH += $$quote(D:/QT+VTK/VTK/debug/include/vtk-8.2)
CONFIG(debug, debug|release) {
LIBS +=  $$quote(D:/QT+VTK/VTK/debug/lib/vtk*.lib)
} else {
LIBS +=  $$quote(D:/QT+VTK/VTK/release/lib/vtk*.lib)
}

INCLUDEPATH +=C:\app\Administrator\product\11.2.0\dbhome_1\OCI\lib\MSVC

LIBPATH += C:\app\Administrator\product\11.2.0\dbhome_1\OCI\lib\MSVC

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

DISTFILES +=
