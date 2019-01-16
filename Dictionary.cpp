#include "Dictionary.h"

Dictionary::Dictionary(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.lineEdit->setText("Please enter the word you want to look up.");
	connect(ui.lineEdit, &QLineEdit::returnPressed, this, &Dictionary::LineEditEnterPressed);
	connect(ui.actionAbout, &QAction::triggered, this, &Dictionary::AboutPressed);
	ifstream fin;
	fin.open("dict.txt");
	string word, definition;
	while (fin >> word) {
		fin.get();
		getline(fin, definition);
		dict.insert(word, definition);
	}
	fin.close();
}

void Dictionary::LineEditEnterPressed() {
	string definition = dict.search(ui.lineEdit->text().toStdString());
	ui.textBrowser->setText(QString::fromLocal8Bit(definition.c_str()));
}
void Dictionary::AboutPressed() {
	QMessageBox::information(this, QString::fromLocal8Bit("About"), QString::fromLocal8Bit("This is a simple dictionary software."));
}