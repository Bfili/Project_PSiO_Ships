-TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "C:/SFML-2.5.1/include"

LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}


SOURCES += \
        barrel.cpp \
        bullet.cpp \
        enemy_ship.cpp \
        floating_object.cpp \
        hero_ship.cpp \
        main.cpp

HEADERS += \
    barrel.h \
    bullet.h \
    enemy_ship.h \
    floating_object.h \
    hero_ship.h
