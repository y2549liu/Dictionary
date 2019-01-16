/********************************************************************************
** Form generated from reading UI file 'Dictionary.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICTIONARY_H
#define UI_DICTIONARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DictionaryClass
{
public:
    QAction *actionAbout;
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DictionaryClass)
    {
        if (DictionaryClass->objectName().isEmpty())
            DictionaryClass->setObjectName(QString::fromUtf8("DictionaryClass"));
        DictionaryClass->resize(400, 400);
        actionAbout = new QAction(DictionaryClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(DictionaryClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 380, 20));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 40, 380, 310));
        DictionaryClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DictionaryClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 18));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        DictionaryClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(DictionaryClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DictionaryClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionAbout);

        retranslateUi(DictionaryClass);

        QMetaObject::connectSlotsByName(DictionaryClass);
    } // setupUi

    void retranslateUi(QMainWindow *DictionaryClass)
    {
        DictionaryClass->setWindowTitle(QApplication::translate("DictionaryClass", "Dictionary", nullptr));
        actionAbout->setText(QApplication::translate("DictionaryClass", "about", nullptr));
        menu->setTitle(QApplication::translate("DictionaryClass", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DictionaryClass: public Ui_DictionaryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICTIONARY_H
