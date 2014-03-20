#-------------------------------------------------
#
# Project created by QtCreator 2014-03-20T00:23:19
#
#-------------------------------------------------

#/**
# * The project manifest file
# *
# * @package Text Encoder
# * @since Text Encoder 1.0
# * @license GNU General Public License v3 or later
# * @copyright (C) 2014  Linuxihaa, linuxihaa.ir
# * @author Misam Saki,  http://misam.ir/
# */

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TextEncoder
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    icon.qrc
