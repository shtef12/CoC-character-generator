#-------------------------------------------------
#
# Project created by QtCreator 2016-09-22T13:52:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CoC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    character.cpp \
    characteristics.cpp \
    skills.cpp \
    reader.cpp \
    helpers.cpp \
    occupations.cpp

HEADERS  += mainwindow.h \
    character.h \
    characteristics.h \
    skills.h \
    reader.h \
    helpers.h \
    skillsconstants.h \
    occupations.h

FORMS    += mainwindow.ui

CONFIG += c++11

DISTFILES += \
    baseSkillValues.txt \
    maleNames.txt \
    femaleNames.txt \
    surnames.txt \
    occupations.txt
