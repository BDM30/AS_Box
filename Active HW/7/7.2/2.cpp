#include <iostream>
#include <cstdlib>
#include <string.h>

#define siseBlocks 5

using namespace std;

enum Change { exitS, createS, printS, delS, sumS, copyS, sameS, lenghtS, emptyS, partS, charS };
Change intToChange(int one) {
	return static_cast<Change>(one);
}

struct strings{
	char string[siseBlocks];
	strings *next;
};

int strlen(char *s) {
	int length = 0;
	while (*s != '\0'){
		s = s + 1;
		length++;
	}
	return length;
}

void create(char s [], strings **begin, strings **end) {
	for (int i = 0; i < strlen(s); i++) {
		if (i % 4 == 0) {
			if (*begin == nullptr) {
				strings *newS = new strings;
				for (int j = 0; j < siseBlocks; j++) {
					newS->string[j] = -1;
				}
				newS->next = nullptr;
				*begin = newS;
				*end = newS;
			}
			else {
				strings *newS = new strings;
				newS->next = nullptr;
				for (int j = 0; j < siseBlocks; j++) {
					newS->string[j] = -1;
				}
				(*end)->next = newS;
				*end = newS;
			}
		}
		(*end)->string[i % 4] = s[i];
	}
}

bool same(char string [], strings *&begin, strings *&end) {
	strings *slot = begin;
	int position = 0;
	while (slot) {
		for (int i = 0; i < siseBlocks; i++) {
			if (slot->string[i] != -1) {
				if (slot->string[i] != string[position])
					return false;
				position++;
			}
		}
		slot = slot->next;
	}
	return true;
}

char *transform(strings *&begin, int const length) {
	char *s = new char[length];
	strings *slot = begin;
	int position = 0;
	while (slot) {
		for (int i = 0; i < siseBlocks; i++) {
			if (slot->string[i] != -1) {
				s[position] = slot->string[i];
				position++;
			}
		}
		slot = slot->next;
	}
	s[position] = '\0';
	return s;
}

char *halfString(char m [], int  start, int finish) {
	char *s = new char[finish - start + 1];
	for (int i = start; i <= finish; i++) {
		s[i - start] = m[i];
		if (i == finish) {
			s[i - start + 1] = '\0';
		}
	}
	return s;
}

void addChar(strings **end, int length, char symbol) {
	if (length % siseBlocks == 0) {
		strings *newS = new strings;
		for (int j = 0; j < siseBlocks; j++) {
			newS->string[j] = -1;
		}
		newS->next = nullptr;
		(*end)->next = newS;
		*end = newS;
	}
	(*end)->string[length % siseBlocks] = symbol;
}

void clone(strings *& begin, strings ** end, int length) {
	int oldLength = length;
	int position = 0;

	strings *slot = begin;
	bool stop = false;
	while (position < oldLength) {
		for (int i = 0; i < siseBlocks && position < oldLength; i++) {
			if (slot->string[i] != -1) {
				addChar(&*end, length, slot->string[i]);
				length++;
				position++;
			}
			else {
				stop = true;
				break;
			}
		}
		if (stop)
			break;
		slot = slot->next;
	}
}

int plusS(strings **end, int length) {
	char buffer[100] = { -1 };
	cout << "enter the string\n";
	cin >> buffer;
	for (int i = 0; i < strlen(buffer); i++) {
		addChar(&*end, length, buffer[i]);
		length++;
	}
	return length;
}

void print(strings *&begin) {
	strings *begin1 = begin;
	while (begin1) {
		for (int i = 0; i < siseBlocks; i++) {
			if (begin1->string[i] != -1)
				cout << begin1->string[i];
		}
		begin1 = begin1->next;
	}
	cout << endl;
}

int main() {
	strings *begin = nullptr;
	strings *end = nullptr;
	int length = 0;
	cout << "/n do not use space-symbol\n";
	cout << "Welcome!\n 0=exit\n 1=create\n 2=print\n 3=delete\n 4=sum\n siseBlocks=clone\n 6=same \n 7=length \n 8=empty \n 9=make part \n 10=to char*\n";
	for (;;) {
		cout << "enter the state\n";
		int changeTemp = 0;
		Change state;
		cin >> changeTemp;
		state = intToChange(changeTemp);

		if (state == exitS) {
			cout << "L.A. GoodBay\n";
			break;
		}

		if (state == createS) {
			if (length != 0) {
				cout << "we have already one\n";
			}
			else {
				char buffer[100] = { -1 };
				cout << "enter the string\n";
				cin >> buffer;
				create(buffer, &begin, &end);
				length = strlen(buffer);
			}
		}

		if (state == printS) {
			if (length == 0) {
				cout << "nothing to print\n";
			}
			else {
				print(begin);
			}
		}

		if (state == delS) {
			if (length == 0) {
				cout << "nothing to delete\n";
			}
			else {
				strings *slot = nullptr;
				while (begin) {
					slot = begin;
					begin = begin->next;
					delete slot;
				}
				begin = nullptr;
				end = nullptr;
				length = 0;
			}
		}

		if (state == sumS) {
			if (length == 0) {
				cout << "nothing to sum \n";
			}
			else {
				length = plusS(&end, length);
			}
		}

		if (state == copyS) {
			if (length == 0) {
				cout << "nothing to clone \n";
			}
			else {
				clone(begin, &end, length);
				length *= 2;
			}
		}

		if (state == sameS) {
			if (length == 0) {
				cout << "firstly enter the string\n";
			}
			else {
				char buf2[100] = { -1 };
				cout << "enter the string\n";
				cin >> buf2;
				if (same(buf2, begin, end))
					cout << "same\n";
				else
					cout << "not same\n";
			}
		}

		if (state == lenghtS) {
			char buffer[100] = { -1 };
			cout << "enter the string\n";
			cin >> buffer;
			cout << "length  is " << strlen(buffer) << endl;
		}

		if (state == emptyS) {
			char buf2[100] = { -1 };
			cout << "enter the string\n";
			cin >> buf2;
			if (strlen(buf2) == 0) {
				cout << "empty\n";
			}
			else
				cout << "not empty\n";
		}

		if (state == partS) {
			if (length == 0) {
				cout << "error!\n";
			}
			else {
				cout << "enter start\n";
				int start = 0;
				cin >> start;
				cout << "enter finish\n";
				int finish = 0;
				cin >> finish;
				char *m = transform(begin, length);
				char *n = halfString(m, start, finish);
				cout << n << endl;
			}
		}

		if (state == charS) {
			if (length == 0) {
				cout << "error!";
			}
			else {
				char *p = &begin->string[0];
				char *m = transform(begin, length);
				cout << "cheking\n";
				cout << m << endl;
			}
		}

	}

	strings *slot = begin;
	while (begin) {
		slot = begin;
		begin = begin->next;
		delete slot;
	}
		delete begin;
	
	return 0;
}