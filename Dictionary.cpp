#include "Dictionary.h"

Dictionary::Dictionary(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.lineEdit->setText("Enter the word");
	connect(ui.lineEdit, &QLineEdit::returnPressed, this, &Dictionary::search);
	connect(ui.actionAbout, &QAction::triggered, this, &Dictionary::aboutPressed);
	connect(ui.lineEdit, &QLineEdit::textEdited, this, &Dictionary::textChanged);
	connect(ui.searchButton, &QPushButton::clicked, this, &Dictionary::search);
	connect(ui.actionAdd_custom_word, &QAction::triggered, this, &Dictionary::addWordWindow);

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


void Dictionary::search() {
	string definition = dict.search(ui.lineEdit->text().toStdString());
	ui.textBrowser->setText(QString::fromLocal8Bit(definition.c_str()));
}
void Dictionary::aboutPressed() {
	QMessageBox::information(this, QString::fromLocal8Bit("About"), QString::fromLocal8Bit("This is a simple dictionary software.\nThe default dictionary is from English to Chinese."));
}
void Dictionary::textChanged() {
	ui.textBrowser->setText("");
	string prefix = ui.lineEdit->text().toStdString();
	trie *p = dict.searchPrefix(prefix);
	if (p == nullptr)
		return;
	ui.textBrowser->setText("You may want to search:");
	unsigned int cnt = 0;
	queue< pair<trie*, string> > q;
	q.push(make_pair(p,prefix));
	while (cnt < 8 && q.size()) {
		trie *head = q.front().first;
		string prefix = q.front().second;
		q.pop();
		if (head == nullptr)
			continue;
		if (head->definition != "") {
			++cnt;
			ui.textBrowser->append(QString::fromLocal8Bit(prefix.c_str()));
		}
		for (auto child : head->ch) 
			if (child.second) 
				q.push(make_pair (child.second, string(prefix + child.first)));
	}
}

void Dictionary::addWordWindow() {
	addWordWidget = new QWidget;
	wordLabel = new QLabel("word:", addWordWidget);
	defLabel = new QLabel("definition:", addWordWidget);
	wordLine = new QLineEdit(addWordWidget);
	defLine = new QLineEdit(addWordWidget);
	ActionAdd = new QPushButton("Add", addWordWidget);
	connect(ActionAdd, &QPushButton::clicked, this, &Dictionary::addWord);
	addWordWidget->resize(400, 200);
	wordLabel->setGeometry(10, 10, 80, 30);
	defLabel->setGeometry(10, 50, 80, 30);
	wordLine->setGeometry(120, 10, 260, 30);
	defLine->setGeometry(120, 50, 260, 30);
	ActionAdd->setGeometry(100, 100, 200, 30);
	addWordWidget->show();
	wordLabel->show();
	defLabel->show();
	wordLine->show();
	defLine->show();
	ActionAdd->show();
}

	

void Dictionary::addWord()
{
	addWordWidget->hide();
	dict.insert(wordLine->text().toLocal8Bit().toStdString(),defLine->text().toLocal8Bit().toStdString());
	
	fstream fout;
	fout.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		fout.open("dict.txt", ios::app);
		fout.seekp(0, ios_base::end);
		fout << endl << wordLine->text().toStdString() << endl;
		fout << string(defLine->text().toLocal8Bit());
		fout.close();
	}
	catch (std::ifstream::failure e) {
		QMessageBox::information(this, QString::fromLocal8Bit("Error"), QString::fromLocal8Bit("Exception opening/reading/closing file"));
		return;
	}
	QMessageBox::information(this, QString::fromLocal8Bit(""), QString::fromLocal8Bit("Success!"));
}

