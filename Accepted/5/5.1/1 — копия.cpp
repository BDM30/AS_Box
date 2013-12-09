#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>

// преобразовать строку по заданию //
int transform(char string [], char stringLeft []) {
	int letter[26];
	for (int i = 0; i < 26; i++) {
		letter[i] = 0;
	}

	int current = 0;
	for (int i = 0; i < strlen(string); i++) {
		letter[int(toupper(string[i])) - int('A')]++;
		if (letter[int(toupper(string[i])) - int('A')] < 2) {
			stringLeft[current] = string[i];
			current++;
		}
	}
	return current;
}

using namespace std;

int main() {
	char *string = new char[100];
	// открыли файл read //
	ifstream read;
	read.open("2.txt", ios::in);

	if (read.is_open()) {
		// считали слова и вывели их //
		while (!read.eof()) {
			read >> string;
			char *stringLeft = new char[strlen(string)];
			for (int i = 0; i < transform(string, stringLeft); i++) {
				cout << stringLeft[i];
			}
			delete [] stringLeft;
			cout << endl;
		}

		// закрыли файл read //
		read.close();
	}

	else {
		cout << "Cant find your file" << endl;
	}

	delete [] string;
	return 0;
}