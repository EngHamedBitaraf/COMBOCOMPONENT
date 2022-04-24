QT       += core gui quickwidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qmlwidget
TEMPLATE = app

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
    main.cpp \
    mainwindow.cpp \
    window_2.cpp

HEADERS += \
    mainwindow.h \
    window_2.h

FORMS += \
    mainwindow.ui \
    window_2.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc \

DISTFILES += \
    Back_G/LICENSE \
    Back_G/README.md \
    Back_G/img/samples/sample-1.jpg \
    Back_G/img/samples/sample-10.jpg \
    Back_G/img/samples/sample-11.jpg \
    Back_G/img/samples/sample-12.jpg \
    Back_G/img/samples/sample-2.jpg \
    Back_G/img/samples/sample-3.jpg \
    Back_G/img/samples/sample-4.jpg \
    Back_G/img/samples/sample-5.jpg \
    Back_G/img/samples/sample-6.jpg \
    Back_G/img/samples/sample-7.jpg \
    Back_G/img/samples/sample-8.jpg \
    Back_G/img/samples/sample-9.jpg \
    Back_G/img/samples/small/sample-10.jpg \
    Back_G/img/samples/small/sample-11.jpg \
    Back_G/img/samples/small/sample-12.jpg \
    Back_G/img/samples/small/sample-2.jpg \
    Back_G/img/samples/small/sample-3.jpg \
    Back_G/img/samples/small/sample-4.jpg \
    Back_G/img/samples/small/sample-5.jpg \
    Back_G/img/samples/small/sample-6.jpg \
    Back_G/img/samples/small/sample-7.jpg \
    Back_G/img/samples/small/sample-8.jpg \
    Back_G/img/screenshot.jpg \
    Back_G/index.html \
    Back_G/lib/builder_scripts.js \
    Back_G/lib/colpick.js \
    Back_G/lib/jquery-1.11.0.min.js \
    Back_G/lib/jquery.nicescroll.min.js \
    Back_G/lib/jquery.nouislider.min.js \
    Back_G/lib/modernizr-2.7.2.js \
    Back_G/waterpipe.js
