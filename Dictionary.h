#pragma once

#include <QtWidgets>
#include "ui_Dictionary.h"
#include "trie.cpp"
#include "fstream"
#include <string>


class Dictionary : public QMainWindow
{
	Q_OBJECT

public:
	Dictionary(QWidget *parent = Q_NULLPTR);
	trie dict;
private:
	Ui::DictionaryClass ui;

public slots:
	void LineEditEnterPressed();
	void AboutPressed();
};
