#include <iostream>
#include <cstdlib>
#include "listFunction.h"

using namespace std;
using namespace list;


int main() {
	int number = 0;
	Node *beginNode = nullptr;
	Node *endNode = nullptr;
	beginNode = first(0); // первый элемент будет с нулевым значением //
	endNode = beginNode;
	int amount = 0;
	cout << "Enter the amount " << endl;
	cin >> amount;
	int step = 0;
	cout << "Enter the step " << endl;
	cin >> step;

	for (int i = 1; i < amount; i++) {
		add(&endNode, i);
		number++;
	}
	int helper = 0;
	Node *pk = beginNode;
	int memory = 0;
	(endNode)->next = beginNode;
	for (;;) {
		helper++;
		pk = pk->next;
		if (helper == step) {
			memory = pk->value;
			pk = pk->next;
			remove(&beginNode, &endNode, memory);
			helper = 0;
			amount--;
		}

		if (amount == 1)
			break;
	}

	
	cout << " Warning! First element is 0!" << endl;
	cout << endl << "LIST:" << endl;
		cout << beginNode->value << endl;
	delete beginNode;
	
	return 0;
}