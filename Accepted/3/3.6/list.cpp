#include <iostream>
#include <cstdlib>
#include "listFunction.h"

using namespace std;
using namespace list;


int main() {
	Node *beginNode = nullptr;
	Node *endNode = nullptr;
	int value = 0;
	int amount = 0;
	cout << "Enter amount of elements " << endl;
	cin >> amount;
	//добавили в конец списка элементы равные i //
	cout << "enter the elements " << endl;
	for (int i = 0; i < amount; i++) {
		cin >> value;
		if (i == 0) {
			beginNode = first(value);
			endNode = beginNode;
		}
		else
			add(&endNode, value);
	}

	if (amount > 1) {
		sortInsert(beginNode, amount);
	}

	// вывод списка//
	Node *helpNode = nullptr;
	while (beginNode) {
		helpNode = beginNode;
		cout << beginNode->value << ' ';
		beginNode = beginNode->next;
		delete helpNode;
	}
	delete beginNode;

	return 0;
}