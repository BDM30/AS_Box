#include <iostream>
#include <cstdlib>
#include "listFunction.h"

using namespace std;
using namespace list;

enum Change { exitProgramm, add, deleteElements, show };

Change intToChange(int one) {
	return static_cast<Change>(one);
}

int main() {

	int value = 0;
	int amount = 0;
	Node *beginNode = nullptr;
	Node *endNode = nullptr;
	Node *helpDelete = nullptr;
	cout << " Lets do it! (0= exitProgramm 1=add 2=deleteElements 3=show all) " << endl;

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

		if (c == exitProgramm) {
			cout << "L.A.Goodbay" << endl;
			break;
		}

		// удаление 
		if (c == deleteElements) {
			if (amount == 0) {
			cout << "Error with null list!" << endl;
			break;
			}
			else {
				cout << "enter value" << endl;
				cin >> value;
				if (!exist(beginNode, value)) {
					cout << "Not found" << endl;
				}
				else
				{
					while (exist(beginNode, value)) {
						del(&beginNode, &endNode, value);
						amount--;
					}
				}
				if (amount == 0) {
					cout << endl << "You have deleted all elements" << endl;
				}
			}
		}

		if (c == add) {
			cout << "enter value" << endl;
			cin >> value;
			if (amount != 0) {
					addSort(&beginNode, &endNode, value);
					amount++;
			}
			else {
				beginNode = first(value);
				endNode = beginNode;
				amount++;
			}
		}

		if (c == show) {
			if (amount > 0) {
				cout << endl;
				Node * helper = beginNode;
				while (helper) {
					cout << helper->valueNode << " ";
					helper = helper->next;
				}
				cout << endl << endl;
			}
			else {
				cout << "list is null" << endl;
			}
		}


	}

	// освободили память //
	while (beginNode) {
		helpDelete = beginNode;
		beginNode = beginNode->next;
		delete helpDelete;
	}
	delete beginNode;
	return 0;
}

