# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = Tp3_Qt
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += AjoutCheque.cpp AjoutEpargne.cpp SupprimerCompte.cpp Tp3_fenetrePrincipal.cpp main.cpp
HEADERS += AjoutCheque.h AjoutEpargne.h SupprimerCompte.h Tp3_fenetrePrincipal.h
FORMS += AjoutCheque.ui AjoutEpargne.ui SupprimerCompte.ui Tp3_fenetrePrincipal.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += "../Tp3 Sources" 
LIBS += "../Tp3 Sources/dist/Debug/GNU-Linux/libtp3_sources.a"  
