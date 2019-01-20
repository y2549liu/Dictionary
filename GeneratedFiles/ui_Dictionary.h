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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DictionaryClass
{
public:
    QAction *actionAbout;
    QAction *actionAdd_custom_word;
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QTextBrowser *textBrowser;
    QPushButton *searchButton;
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
        actionAdd_custom_word = new QAction(DictionaryClass);
        actionAdd_custom_word->setObjectName(QString::fromUtf8("actionAdd_custom_word"));
        centralWidget = new QWidget(DictionaryClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 281, 31));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 50, 380, 320));
        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setGeometry(QRect(299, 10, 91, 31));
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
        menu->addAction(actionAdd_custom_word);

        retranslateUi(DictionaryClass);

        QMetaObject::connectSlotsByName(DictionaryClass);
    } // setupUi

    void retranslateUi(QMainWindow *DictionaryClass)
    {
        DictionaryClass->setWindowTitle(QApplication::translate("DictionaryClass", "Dictionary", nullptr));
        actionAbout->setText(QApplication::translate("DictionaryClass", "About", nullptr));
        actionAdd_custom_word->setText(QApplication::translate("DictionaryClass", "Add custom word", nullptr));
        searchButton->setText(QApplication::translate("DictionaryClass", "Search", nullptr));
        menu->setTitle(QApplication::translate("DictionaryClass", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DictionaryClass: public Ui_DictionaryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICTIONARY_H
