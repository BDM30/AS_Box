#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string.h>

using namespace std;

struct elements{
	elements *next;
	int exponent;
	int coefficient;

};

enum Change { exitP, same, calc, sum };

Change intToChange(int one) {
	return static_cast<Change>(one);
}

void addSort(elements **beginNode, elements **endNode, int exponent, int coefficient){
	elements *end = *endNode;
	elements *newNode = new elements;
	newNode->exponent = exponent;
	newNode->coefficient = coefficient;
	elements * currentNode = *beginNode;
	if (*beginNode == nullptr) {
		newNode->next = nullptr;
		*beginNode = newNode;
		*endNode = newNode;
	}
	else {
		if (exponent < currentNode->exponent) {
			newNode->next = currentNode;
			*beginNode = newNode;
			if (currentNode == *endNode) {
				*endNode = currentNode;
			}
		}
		else {
			bool found = false;
			while (currentNode->next) {
				if ((currentNode->next)->exponent > newNode->exponent) {
					found = true;
					break;
				}
				currentNode = currentNode->next;
			}
			if (found) {
				newNode->next = currentNode->next;
				currentNode->next = newNode;
				if (currentNode->next == end) {
					*endNode = currentNode->next;
				}
			}
		}
		if ((*endNode)->exponent <= exponent) {
			newNode->exponent = exponent;
			newNode->next = nullptr;
			(*endNode)->next = newNode;
			*endNode = newNode;
		}
	}
}

bool isDigit(char a) {
	return ((int(a) >= int('0')) && (int(a) <= int('9')));
}

bool isFunction(char a) {
	return ((a == '-') || (a == '+'));
}

int getInt(char s [], int begin, int end) {
	int answer = 0;
	for (int i = begin; i <= end; i++) {
		answer = answer + (int(s[i]) - int('0')) * pow(10, end - i);
	}
	return answer;
}

void makePQR(char s1 [], elements **beginE, elements **endE) {
	int begin = 0;
	int end = 0;
	for (int i = 0; i < strlen(s1); i++) {
		if (isFunction(s1[i]) && i != 0 && s1[i - 1] != '^' || i == strlen(s1) - 1) {
			int posX = -1;
			int posT = -1;
			int currentExp = 0;
			int currentCoe = 0;
			if (i == strlen(s1) - 1)
				end = strlen(s1);
			else
				end = i;
			for (int j = begin; j < end; j++) {
				if (s1[j] == 'x')
					posX = j;
				if (s1[j] == '^')
					posT = j;
			}
			if (posX == -1){
				currentCoe = getInt(s1, begin + 1, end - 1);
				if (s1[begin] == '-')
					currentCoe *= -1;
				currentExp = 0;
			}
			if (posX != -1 && isFunction(s1[begin]) && posX == begin + 1){
				if (s1[begin] == '-')
					currentCoe = -1;
				else
					currentCoe = 1;
			}

			if (posX != -1 && posX != begin + 1) {
				currentCoe = getInt(s1, begin + 1, posX - 1);
				if (s1[begin] == '-')
					currentCoe *= -1;
			}
			if (posX != -1 && posT == -1) {
				currentExp = 1;
			}
			if (posX != -1 && posT != -1) {
				if (isDigit(s1[posT + 1])){
					currentExp = getInt(s1, posT + 1, end - 1);
				}
				else {
					currentExp = -getInt(s1, posT + 2, end - 1);
				}
			}
			addSort(&*beginE, &*endE, currentExp, currentCoe);
			begin = i;
		}
	}
}

bool equals(elements *&b1, elements *&b2) {
	elements *begin1 = b1;
	elements *begin2 = b2;
	while (begin1 && begin2) {
		if (begin1->coefficient != begin2->coefficient || begin1->exponent != begin2->exponent)
			return false;
		begin1 = begin1->next;
		begin2 = begin2->next;
	}
	if (begin1 != nullptr || begin2 != nullptr)
		return false;
	return true;
}

int value(elements *&b, int x) {
	elements *beginP = b;
	int answer = 0;
	while (beginP) {
		answer = answer + beginP->coefficient*pow(x, beginP->exponent);
		beginP = beginP->next;
	}
	return answer;
}

elements *findExp(elements *&begin, int exp) {
	elements *slot = begin;
	while (slot) {
		if (slot->exponent == exp) {
			return slot;
		}
		slot = slot->next;
	}
	return nullptr;
}

void include(elements *&beginP, elements *&endP, elements **beginQ, elements **endQ) {
	elements *slot = nullptr;
	elements *slot2 = nullptr;
	while (beginP) {
		slot = findExp(*beginQ, beginP->exponent);
		if (slot != nullptr) {
			slot->coefficient = slot->coefficient + beginP->coefficient;
			slot2 = beginP;
		}
		else {
			addSort(&*beginQ, &*endQ, beginP->exponent, beginP->coefficient);
			slot2 = beginP;
		}
		beginP = beginP->next;
		delete slot2;
	}
}

void print(elements *begin) {
	elements *slot = nullptr;
	while (begin) {
		if (begin->coefficient != 0) {
			if (begin->exponent == 0) {
				if (begin->coefficient > 0)
					cout << begin->coefficient;
			}
			else {
				if (begin->coefficient > 0)
					cout << "+";
				if (abs(begin->coefficient) > 1)
					cout << begin->coefficient;
				cout << "x";
				if (begin->exponent > 1) {
					cout << "^" << begin->exponent;
				}
			}
		}
		slot = begin;
		begin = begin->next;
		delete slot;
	}
}

int main() {
	cout << "For example:\n x^5+x-7\n";
	char string01[100] = { -1 };
	cout << "Enter the first string(P)\n";
	cin.getline(string01, 100);
	char string02[100] = { -1 };
	cout << "Enter the second string(Q)\n";
	cin.getline(string02, 100);

	char string1[100] = { -1 };
	if (!isFunction(string01[0])) {
		string1[0] = '+';
		for (int i = 0; i < strlen(string01); i++) {
			string1[i + 1] = string01[i];
		}
	}

	char string2[100] = { -1 };
	if (!isFunction(string02[0])) {
		string2[0] = '+';
		for (int i = 0; i < strlen(string02); i++) {
			string2[i + 1] = string02[i];
		}
	}

	elements *beginP = nullptr;
	elements *beginQ = nullptr;
	elements *beginR = nullptr;
	elements *endP = nullptr;
	elements *endQ = nullptr;
	elements *endR = nullptr;
	makePQR(string1, &beginP, &endP);
	makePQR(string2, &beginQ, &endQ);

	cout << " Welcome!\n 0 = exit \n 1 = equals(p,q) \n 2 = value(p,x) \n 3 = add(p+q=r)\n";
	for (;;) {
		cout << "Enter number of state" << endl;
		int changeTemp = 0;
		Change c;
		cin >> changeTemp;

		if (!((changeTemp >= 0) && (changeTemp <= 3))) {
			cout << "Wrong command!" << endl;
			return 0;
		}

		c = intToChange(changeTemp);

		if (c == exitP) {
			cout << "L.A.Goodbay" << endl;
			return 0;
		}
		if (c == same) {
			if (equals(beginP, beginQ))
				cout << "equals!\n";
			else
				cout << "not equals!\n";
		}
		if (c == calc) {
			cout << "enter the x\n";
			int x = 0;
			cin >> x;
			cout << "result is " << value(beginP, x) << endl;
		}
		if (c == sum) {
			include(beginP, endP, &beginQ, &endQ);
			print(beginQ);
			cout << "\n";
		}
	}
	return 0;
}