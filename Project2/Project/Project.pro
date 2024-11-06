TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Base.cpp \
        PassengerTrain.cpp \
        Plain.cpp \
        Vector.tpp \
        main.cpp

HEADERS += \
    Base.h \
    PassengerTrain.h \
    Plain.h \
    Vector.h
