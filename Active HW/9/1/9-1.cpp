#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

int const primeNumber = 3;
int const amount = 10000;

struct Word {
	char word[100];
	Word *next;
};

Word *create(char s []) {
	Word *creature = new Word;
	int i = 0;
	for (i; i < strlen(s); i++) {
		creature->word[i] = s[i];
	}
	creature->word[i + 1] = '\0';
	creature->next = nullptr;
	return creature;
}

void addEnd(Word *&last, char s []) {
	Word *creature = new Word;
	int i = 0;
	for (i; i < strlen(s); i++) {
		creature->word[i] = s[i];
	}
	creature->word[i + 1] = '\0';
	creature->next = nullptr;
	last->next = creature;
}



Word *findLast(Word *&first){
	Word *helper = first;
	while (helper->next) {
		helper = helper->next;
	}
	return helper;
}

int hashCount(char string []) {
	int result = 0;
	for (int i = 0; string[i] != '\0'; ++i)
		result = (result + string[i]) % amount;
	return result;
}

void del(Word **beginNode, Word *&pkey) {
	Word *start = *beginNode;

	// удалили первый //
	if (start == pkey) {
		*beginNode = nullptr;
		delete start;
	}
	else {
		bool found = false;
		while (start->next) {
			if (start->next == pkey) {
				found = true;
				break;
			}
			start = start->next;
		}
		// start - предыдущий для удаляемого start->next удаляемый //
		if (found) {
			start->next = (pkey)->next;
			delete pkey;
		}
	}
}

Word *same(Word *&first, char s []) {
	Word *help = first;
	while (help) {
		bool correct = true;
		int i = 0;
		while (s[i] != '\0') {
			if (help->word[i] != s[i]) {
				correct = false;
				break;
			}
			i++;
		}
		if (correct) {
			return help;
		}
		help = help->next;
	}
	return nullptr;
}

using namespace std;

int main() {
	cout << "using:\n1.txt\n2.txt\nout.txt\n";
	ifstream inFile1;
	ifstream inFile2;
	ofstream outFile;
	outFile.open("out.txt", ios::out);
	inFile1.open("1.txt", ios::in);
	if (!(inFile1.is_open())) {
		cout << "Where is your file ???" << endl;
		return 0;
	}

	inFile2.open("2.txt", ios::in);
	if (!(inFile2.is_open())) {
		cout << "Where is your file ???" << endl;
		return 0;
	}

	Word *hashRange[amount];
	for (int i = 0; i < amount; i++) {
		hashRange[i] = nullptr;
	}

	char *line = new char[100];
	Word *slot = nullptr;
	int valueHash = 0;

	// записали в хэш таблицу //
	while (inFile1.good()) {
		inFile1.getline(line, 100);
		valueHash = hashCount(line);
		if (hashRange[valueHash] == nullptr) {
			hashRange[valueHash] = create(line);
		}
		else {
				slot = findLast(hashRange[valueHash]);
				addEnd(slot, line);
		}
	}

	slot = nullptr;
	while (inFile2.good()) {
		inFile2.getline(line, 100);
		valueHash = hashCount(line);
		slot = same(hashRange[valueHash], line);
		if (slot != nullptr) {
			outFile << line << "\n";
			del(&hashRange[valueHash], slot);
		}
	}
	
	inFile1.close();
	inFile2.close();
	outFile.close();
	delete line;

	return 0;
}