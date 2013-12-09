#include <iostream>
#include <cstdlib>
#include <string.h>
#include "listFunction.h"

using namespace std;
using list::PhoneBook;

PhoneBook *list::first(char number [], char name []) {
	PhoneBook *newRecord = new PhoneBook;
	newRecord->nameLength = strlen(name);
	newRecord->numberLength = strlen(number);

	for (int i = 0; i < strlen(number); i++) {
		newRecord->number[i] = number[i];
	}

	for (int i = 0; i < strlen(name); i++) {
		newRecord->name[i] = name[i];
	}

	newRecord->next = nullptr;

	return newRecord;
}


// Добавить в конец списка //
void list::add(PhoneBook **end, char number [], char name []){
	PhoneBook *newRecord = new PhoneBook;
	newRecord->nameLength = strlen(name);
	newRecord->numberLength = strlen(number);

	for (int i = 0; i < strlen(number); i++) {
		newRecord->number[i] = number[i];
	}

	for (int i = 0; i < strlen(name); i++) {
		newRecord->name[i] = name[i];
	}

	newRecord->next = nullptr;
	(*end)->next = newRecord;
	*end = newRecord;
}

void list::existNumber(PhoneBook *begin, char number []) {
	bool right = false;
	bool rightGlobal = false;
	PhoneBook *helpPhoneBook = begin;
	while (helpPhoneBook) {
		right = true;
		if (strlen(number) == (helpPhoneBook->numberLength)) {
			for (int i = 0; i < strlen(number); i++) {
				if (number[i] != helpPhoneBook->number[i]) {
					right = false;
					break;
				}
			}
		}
		else
			right = false;
		if (right) {
			rightGlobal = true;
			break;
		}
		helpPhoneBook = helpPhoneBook->next;
	}

	if (!rightGlobal)
		cout << "NOT FOUND" << endl;
	else {
		cout << "This is " << endl;
		for (int i = 0; i < helpPhoneBook->nameLength; i++) {
			cout << helpPhoneBook->name[i];
		}
		cout << endl;
	}
}


void list::existName(PhoneBook *begin, char name []) {
	bool right = false;
	bool rightGlobal = false;
	PhoneBook *helpPhoneBook = begin;
	while (helpPhoneBook) {
		right = true;
		if (strlen(name) == (helpPhoneBook->nameLength)) {
			for (int i = 0; i < strlen(name); i++) {
				if (name[i] != helpPhoneBook->name[i]) {
					right = false;
					break;
				}
			}
		}
		else
			right = false;
		if (right) {
			rightGlobal = true;
			break;
		}
		helpPhoneBook = helpPhoneBook->next;
	}

	if (!rightGlobal)
		cout << "NOT FOUND" << endl;
	else {
		cout << "This is " << endl;
		for (int i = 0; i < helpPhoneBook->numberLength; i++) {
			cout << helpPhoneBook->number[i];
		}
		cout << endl;
	}
}