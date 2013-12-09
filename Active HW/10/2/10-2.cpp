#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>

using namespace std;

struct tree {
	tree *left;
	tree *right;
	tree *next;
	tree *parent;
	char symbol;
};

tree *create(char symbol) {
	tree *newT = new tree;
	newT->left = nullptr;
	newT->right = nullptr;
	newT->next = nullptr;
	newT->parent = nullptr;
	newT->symbol = symbol;
	return newT;
}

int reverseHuffman() {
	ifstream inFile;
	ofstream outFile;
	inFile.open("in.txt", ios::in);
	outFile.open("out.txt", ios::out);
	if (!(inFile.is_open())) {
		cout << "Where is your file ???" << endl;
		return 0;
	}

	char treeString[100] = { -1 };
	inFile.getline(treeString, 100);
	for (int i = 0; i < strlen(treeString); i++) {
		cout << treeString[i];
	}
	cout << endl;

	char codeString[100] = { -1 };
	inFile.getline(codeString, 100);
	codeString[strlen(codeString)] = '.';
	for (int i = 0; i < strlen(codeString); i++) {
		cout << codeString[i];
	}
	cout << endl;
	inFile.close();

	int currentPoint = 0;
	tree *currentNode = nullptr;
	tree *points[100] = { nullptr };
	for (int i = 0; i < strlen(treeString); i++) {
		if ((i > 0) && (treeString[i - 1] == '(')) {
			if (currentPoint == 0) {
				points[0] = create(treeString[i]);
				currentPoint++;
				currentNode = points[0];
			}
			else {
				if (currentNode->left == nullptr) {
					points[currentPoint] = create(treeString[i]);
					currentNode->left = points[currentPoint];
					points[currentPoint]->parent = currentNode;
					currentNode = points[currentPoint];
					currentPoint++;
				}
				else {
					points[currentPoint] = create(treeString[i]);
					currentNode->right = points[currentPoint];
					points[currentPoint]->parent = currentNode;
					currentNode = points[currentPoint];
					currentPoint++;
				}
			}
		}

		if (treeString[i] == ')') {
			currentNode = currentNode->parent;
		}
	}
	
	char code[10] = { -1 };
	int position = 0;
	for (int i = 0; i < strlen(codeString); i++) {
		if ((codeString[i] != ' ') && (codeString[i] != '.')) {
			code[position] = codeString[i];
			position++;
		}
		else {
			tree *help = points[0];
			for (int j = 0; j < position; j++) {
				if (code[j] == '0')
					help = help->left;
				else
					help = help->right;
			}
			outFile << help->symbol;
			cout << help->symbol;
			position = 0;
		}
	}
	cout << endl;

	outFile.close();
	for (int i = 0; i < currentPoint; i++) {
		delete points[i];
	}

	return 0;
}

int main() {
	reverseHuffman();
	return 0;
}