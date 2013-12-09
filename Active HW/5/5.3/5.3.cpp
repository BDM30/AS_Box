#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>
using namespace std;

int main() {

	char str[100];
	ifstream read;
	read.open("q.txt", ios::in);
	if (read.is_open()) {
		int numberSC = 0;
		bool simpleComment = true;
		int quotes = 0;
		// считали строку и нашли ее длину //
		bool hardComment = false;
		while (read.getline(str, 100)) {
			simpleComment = false;
			quotes = 0;
			// не берем строки меньше 2х символов //
			for (int i = 0; ((strlen(str) > 1) && (i < strlen(str) - 1)); i++) {
				if (str[i] == '"') {
					quotes++;
				}
				if ((str[i] == '/') && (str[i + 1] == '/') && (!hardComment) && (quotes %2 != 1)) {
					simpleComment = true;
					numberSC = i + 1;
					break;
				}
				if ((str[i] == '/') && (str[i + 1] == '*') && (quotes % 2 != 1)) {
					hardComment = true;
				}
				if ((str[i] == '*') && (str[i + 1] == '/')) {
					hardComment = false;
				}
			}
			if ((simpleComment)) {
				for (int i = numberSC + 1; i < strlen(str); i++) {
					cout << str[i];
				}
				cout << endl;
			}
		}
	}
	else {
		cout << "Cant find your file" << endl;
	}
	return 0;
}