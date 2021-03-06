QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    aigle.cpp \
    aiglefemmelle.cpp \
    animal.cpp \
    animals.cpp \
    animaltype.cpp \
    coq.cpp \
    habitat.cpp \
    habitataigle.cpp \
    habitatpoule.cpp \
    habitats.cpp \
    habitattigre.cpp \
    main.cpp \
    mainwindow.cpp \
    poule.cpp \
    showanimalsinhabitat.cpp \
    templateanimal.cpp \
    tigre.cpp \
    tigrefemmelle.cpp \
    vendor.cpp \
    zoo.cpp \
    zoobudget.cpp \
    zoomessage.cpp \
    zoomessages.cpp \
    zooobject.cpp \
    zoostock.cpp

HEADERS += \
    FoodType.h \
    aigle.h \
    aiglefemmelle.h \
    animal.h \
    animals.h \
    animaltype.h \
    animaltype.h \
    coq.h \
    habitat.h \
    habitataigle.h \
    habitatpoule.h \
    habitats.h \
    habitattigre.h \
    mainwindow.h \
    poule.h \
    showanimalsinhabitat.h \
    templateanimal.h \
    tigre.h \
    tigrefemmelle.h \
    vendor.h \
    zoo.h \
    zoobudget.h \
    zoomessage.h \
    zoomessages.h \
    zooobject.h \
    zoostock.h

FORMS += \
    mainwindow.ui \
    showanimalsinhabitat.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
