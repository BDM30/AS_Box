#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include "listFunction.h"


using namespace std;
using namespace list;

enum Change { exitProgramm, adding, findingName, findingNumber, saveInFile };

Change intToChange(int one) {
	return static_cast<Change>(one);
}

int main() {
	int amountRecords = 0;
	PhoneBook *begin = nullptr;
	PhoneBook *end = nullptr;

	ofstream outFile;
	outFile.open("out.txt", ios::out);

	ifstream inFile;
	inFile.open("in.txt", ios::in);
	if (!(inFile.is_open())) {
		cout << "Where is in file ???" << endl;
		return 0;
	}
	char memory1[20];
	char memory2[20];

	while (!inFile.eof()) {
		inFile >> memory1;
		inFile >> memory2;
		if (amountRecords == 0) {
			begin = first(memory1, memory2);
			end = begin;
			amountRecords++;
		}
		else {
			add(&end, memory1, memory2);
			amountRecords++;
		}
	}

	int menu = 5;

	for (;;) {
		cout << "Enter number of state" << endl;
		cin >> menu;
		Change c;
		c = intToChange(menu);
		// выйти //
		if (c == exitProgramm) {
			cout << "L.A. Goodbye " << endl;
			break;
		}

		// добавить запись //
		if (c == adding) {
			cout << "Enter the number" << endl;
			cin >> memory1;
			cout << "Enter the name" << endl;
			cin >> memory2;

			if (amountRecords == 0) {
				begin = first(memory1, memory2);
				end = begin;
				amountRecords++;
			}

			else {
				add(&end, memory1, memory2);
				amountRecords++;
			}
		}

		// Поиск имени по номеру //
		if (c == findingNumber) {
			cout << "Enter the number" << endl;
			cin >> memory2;
			existNumber(begin, memory2);
		}


		// Поиск номера по имени //
		if (c == findingName) {
			cout << "Enter the name" << endl;
			cin >> memory2;
			existName(begin, memory2);
		}

		if (c == saveInFile) {
			PhoneBook * helper = begin;
			while (helper) {

				for (int i = 0; i < helper->numberLength; i++) {
					outFile << helper->number[i];
				}
				outFile << " ";

				for (int i = 0; i < helper->nameLength; i++) {
					outFile << helper->name[i];
				}
				outFile << endl;

				helper = helper->next;
			}
			cout << "all recods saved in out.txt" << endl;
		}
	}

	PhoneBook *deleter = nullptr;
	while (begin->next) {
		deleter = begin;
		begin = begin->next;
		delete deleter;
	}
	delete begin;
	return 0;
}