#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <string>
using namespace std;

template<typename T=string>
class Trie {

};

struct trie {
	string definition="";
	unordered_map<char, trie*> ch;
	void insert(string word, string meaning) {
		trie* ptr = this;
		for (auto c : word)
			if (ptr->ch[c])
				ptr = ptr->ch[c];
			else
				ptr = ptr->ch[c] = new trie;
		ptr->definition = meaning;
	}
	void insert(char* word, char* meaning) {
		insert(string(word), string(meaning));
	}
	trie* searchPrefix(string prefix) {
		trie* ptr = this;
		for (auto c : prefix)
			if (ptr->ch[c])
				ptr = ptr->ch[c];
			else
				return nullptr;
		return ptr;
	}
	string search(string word) {
		trie* ptr = searchPrefix(word);
		return (ptr && ptr->definition != "") ? ptr->definition : "Not found!";
	}
	void fuzzySearchPrefix(string prefix) {
		trie* ptr = searchPrefix(prefix);
		return void(ptr ? ptr->list(prefix) : 0);
	}
	void list(string prefix) {
		if (definition != "") 
			cout << std::left << setw(16) << prefix << '|' << definition << endl;
		for (auto p:ch) 
			if (p.second) 
				p.second->list(prefix + p.first);
	}
};
