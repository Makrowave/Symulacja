TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        generatorlosowy.cpp \
        main.cpp \
        mieszkaniec.cpp \
        nisza.cpp \
        organizm.cpp \
        osobniki.cpp \
        sasiedztwo.cpp \
        srodowisko.cpp \
        ustawieniasymulacji.cpp

HEADERS += \
    generatorlosowy.h \
    mieszkaniec.h \
    nisza.h \
    organizm.h \
    osobniki.h \
    projekt_enum.h \
    sasiedztwo.h \
    srodowisko.h \
    ustawieniasymulacji.h
