#include <iostream>
#include <cstdlib>
#include "treeFunction.h"

using namespace std;
using namespace treeName;

enum Change { exitProgramm, add, del, exist, showInc, showDec, showABC };

Change intToChange(int one) {
	return static_cast<Change>(one);
}

int main() {

	cout << "Welcome!" << endl << "Enter the number of state" << endl;
	cout << "0 = exit" << endl;
	cout << "1 = add" << endl;
	cout << "2 = delete" << endl;
	cout << "3 = exists?" << endl;
	cout << "4 = show increase" << endl;
	cout << "5 = show decrease" << endl;
	cout << "6 = show (a b c)" << endl;

	tree *root = nullptr;
	int value = 0;
	int amount = 0;

	for (;;) {
		cout << "Enter number of state" << endl;
		int changeTemp = 0;
		Change c;
		cin >> changeTemp;

		if (!((changeTemp >= 0) && (changeTemp <= 6))) {
			cout << "Wrong command!" << endl;
			return 0;
		}

		c = intToChange(changeTemp);

		if (c == exitProgramm) {
			cout << "L.A.Goodbay" << endl;
			break;
		}

		if (c == add) {
			cout << "Enter the value" << endl;
			cin >> value;
			if (exists(root, value)) {
				cout << "sorry we already have this one" << endl;
			}
			else {
				root = insert(root, value);
				amount++;
			}
		}

		if (c == del) {
			if (amount == 0) {
				cout << "Empty tree!" << endl;
				break;
			}
			cout << "Enter the value" << endl;
			cin >> value;
			if (!exists(root, value)) {
				cout << "Not found" << endl;
			}
			else {
				while (exists(root, value)) {
					root = remove(root, value);
					amount--;
				}
			}
			if (amount == 0) {
				cout << "I have deleted all " << endl;
			}
		}

		if (c == exist) {
			if (amount == 0) {
				cout << "Empty tree!" << endl;
				break;
			}
			cout << "Enter the value" << endl;
			cin >> value;
			if ((amount > 0) && (exists(root, value))) {
				cout << "It is here" << endl;
			}
			else {
				cout << "It is NOT here" << endl;
			}
		}

		if (c == showInc) {
			if (amount == 0) {
				cout << "Tree is null" << endl;
				break;
			}
			else {
				printInc(root);
				cout << endl;
			}
		}

		if (c == showDec) {
			if (amount == 0) {
				cout << "Tree is null" << endl;
				break;
			}
			else {
				printDec(root);
				cout << endl;
			}
		}

		if (c == showABC) {
			if (amount == 0) {
				cout << "Tree is null" << endl;
				break;
			}
			else {
				printAbc(root);
				cout << endl;
			}
		}
	}
	root = freeMemory(root);
	return 0;
}