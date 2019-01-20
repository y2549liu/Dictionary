#pragma once

#include <QtWidgets>
#include "ui_Dictionary.h"
#include "trie.cpp"
#include "fstream"
#include <string>
#include <queue>
#include <exception>
class Dictionary : public QMainWindow
{
	Q_OBJECT

public:
	Dictionary (QWidget *parent = Q_NULLPTR);
	
private:
	Ui::DictionaryClass ui;
	QWidget *addWordWidget = new QWidget;
	QLabel *wordLabel = new QLabel("word:", addWordWidget);
	QLabel *defLabel = new QLabel("definition:", addWordWidget);
	QLineEdit *wordLine = new QLineEdit(addWordWidget);
	QLineEdit *defLine = new QLineEdit(addWordWidget);
	QPushButton *ActionAdd = new QPushButton("Add", addWordWidget);
	trie dict;

public slots:
	void search();
	void aboutPressed();
	void textChanged();
	void addWordWindow();
	void addWord();
};
