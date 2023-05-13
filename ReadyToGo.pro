QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    deliveryboy.cpp \
    main.cpp \
    mainmenu.cpp \
    seller.cpp \
    user.cpp \
    warehouse.cpp

HEADERS += \
    admin.h \
    deliveryboy.h \
    mainmenu.h \
    seller.h \
    user.h \
    warehouse.h

FORMS += \
    admin.ui \
    deliveryboy.ui \
    mainmenu.ui \
    seller.ui \
    user.ui \
    warehouse.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
