#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <cmath>

struct tree {
	tree *left;
	tree *right;
	tree *previous;
	int value;
	char function;
};

using namespace std;

void calc(tree *&node) {
	int answer = 0;
	if (node->function != '\0' && node->left && node->right && node->left->function == '\0' && node->right->function == '\0') {
		if (node->function == '+') {
			answer += node->left->value + node->right->value;
		}
		if (node->function == '-') {
			answer += node->left->value - node->right->value;
		}
		if (node->function == '*') {
			answer += node->left->value * node->right->value;
		}
		if (node->function == '/') {
			answer += node->left->value / node->right->value;
		}
		node->function = '\0';
		node->value = answer;
		delete node->left;
		delete node->right;
		node->left = nullptr;
		node->right = nullptr;
	}
}

void printAbc(tree *root) {
	if (!root) {
		return;
	}
	else
		cout << "(";
	if (root->function != '\0')
		cout << root->function;
	else
		cout << root->value;
	printAbc(root->left);
	printAbc(root->right);
	cout << ")";
	return;
}

void calcHelp(tree *root) {
	if (!root)
		return;
	calcHelp(root->left);
	calc(root);
	calcHelp(root->right);
}

tree *newTree(int value, char symbol) {
	tree *newT = new tree;
	newT->left = nullptr;
	newT->right = nullptr;
	newT->previous = nullptr;
	newT->value = value;
	newT->function = symbol;
	return newT;
}

int getInt(int &position, const char s[]) {
	int asw = 0;
	char number[10] = { '\0' };
	int i = 0;
	while (s[position] != ')'){
		number[i] = s[position];
		position++;
		i++;
	}
	for (i = 0; i < strlen(number); i++) {
		asw += (number[i] - '0')*pow(10, strlen(number) - 1 - i);
	}
	position++;
	return asw;
}

bool isFunction(char c) {
	return c == '+' || c == '*' || c == '-' || c == '/';
}

bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

void addTree(const char s[]) {
	static tree *root = nullptr;
	static tree *currentNode = nullptr;
	static int position = 0;
	(s[position] =='(' && position == 0) ? position++ : 0;
	static int first = 0;
	if (isFunction(s[position])) {
		if (first == 0) {
			root = newTree(0,s[position]);
			currentNode = root;
			first++;
			position++;
		}
		else {
			bool was = false;
			if (currentNode->left != nullptr && currentNode->right == nullptr && !was) {
				tree *newT = newTree(0, s[position]);
				currentNode->right = newT;
				newT->previous = currentNode;
				currentNode = newT;
				was = true;
			}
			if (currentNode->left == nullptr && !was) {
				tree *newT = newTree(0, s[position]);
				currentNode->left = newT;
				newT->previous = currentNode;
				currentNode = newT;
			}
			position++;
		}
	}
	if (s[position] == '(') {
		if (!isDigit(s[position + 1]))
			position++;
		else {
			position++;
			int val = getInt(position,s);
			if (currentNode->left != nullptr && currentNode->right == nullptr) {
				tree *newT = newTree(val, '\0');
				currentNode->right = newT;
				newT->previous = currentNode;
			}
			if (currentNode->left == nullptr) {
				tree *newT = newTree(val, '\0');
				currentNode->left = newT;
				newT->previous = currentNode;
			}
		}
	}

	if (s[position] == ')') {
		if (currentNode->previous)
			currentNode = currentNode->previous;
		position++;
	}

	if (position < strlen(s)) {
		addTree(s);
	}
	else {
		cout << "we read is so \n";
		printAbc(root);
		cout << endl << endl;
		while (root->left != nullptr && root->right != nullptr) {
			calcHelp(root);
		}
		cout << "aswer: \n" << root->value << endl;
		delete root;
	}
}

int main() {
	cout << "Warning! For supporting numbers over 9 I used extra()\nso u need write like this\n";
	cout << "(/(+(2)(-(1)(0)))(3))\n";
	cout << "\nuse:\nin.txt\n\n";
	ifstream inFile1;
	inFile1.open("in.txt", ios::in);
	if (!(inFile1.is_open())) {
		cout << "Where is your file ???" << endl;
		return 0;
	}
	char str[100] = { '\0' };
	inFile1.getline(str, 100);
	addTree(str);
	inFile1.close();
	return 0;
}