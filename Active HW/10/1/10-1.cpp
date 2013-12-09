#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>

using namespace std;

void sortBubble(int popular [], int chars [], int amount) {
	int t = 0;
	int tmp = 0;
	int i = 0;
	while (t < amount - 1) {
		t = 0;
		for (i = 0; i < amount - 1; i++) {
			if (popular[chars[i]] > popular[chars[i + 1]]) {
				tmp = chars[i];
				chars[i] = chars[i + 1];
				chars[i + 1] = tmp;
			}
			else
				t++;
		}
	}
}

struct tree {
	tree *left;
	tree *right;
	tree *next;
	tree *parent;
	int priory;
	char symbol;
	char code;
};

struct codes{
	char s[20];
};

codes *createCodes(){
	codes *p = new codes;
	for (int i = 0; i < 20; i++) {
		p->s[i] = -1;
	}
	return p;
}

void addEnd(int code, int polular, tree ** begin, tree ** end) {
	if (*begin == nullptr) {
		tree *newT = new tree;
		newT->left = nullptr;
		newT->right = nullptr;
		newT->next = nullptr;
		newT->parent = nullptr;
		newT->code = 3;
		newT->priory = polular;
		newT->symbol = char(code);
		*begin = newT;
		*end = *begin;
	}
	else {
		tree *newT = new tree;
		newT->left = nullptr;
		newT->right = nullptr;
		newT->next = nullptr;
		newT->parent = nullptr;
		newT->code = 3;
		newT->priory = polular;
		newT->symbol = char(code);
		(*end)->next = newT;
		*end = newT;
	}
}


tree *create(int code, int polular) {
	tree *newT = new tree;
	newT->left = nullptr;
	newT->right = nullptr;
	newT->next = nullptr;
	newT->parent = nullptr;
	newT->code = 3;
	newT->priory = polular;
	newT->symbol = char(code);
	return newT;

}

tree *addBefore(tree **beginNode, tree **endNode, int number, int symbol){
	tree *slot = *beginNode;
	tree *newNode = new tree;
	newNode->priory = number;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->next = nullptr;
	newNode->parent = nullptr;
	newNode->code = 3;
	newNode->symbol = char(symbol);
	while (slot) {
		if (slot->priory >= number)
			break;
		slot = slot->next;
	}
	if (slot != *beginNode) {
		tree *rightList = *beginNode;
		while (rightList) {
			if (rightList->next == slot)
				break;
			rightList = rightList->next;
		}
		rightList->next = newNode;
	}
	newNode->next = slot;
	if (slot == *beginNode)
		*beginNode = newNode;
	if (slot == *endNode)
		*endNode = newNode;
	return newNode;
}

void printInc(tree *root, char out[]) {
	int static position = 0;
	if (!root)
		return;
	printInc(root->left, out);
	out[position] = root->symbol;
	position++;
	out[position] = ' ';
	position++;
	printInc(root->right, out);
}

void findC(tree *root, char symbol, tree **result) {
	if (!root)
		return;
	findC(root->left, symbol, &(*result));
	if (symbol == root->symbol) {
		*result = root;
	}
	findC(root->right, symbol, &(*result));
}

tree *printAbc(tree *root, char out[])
{
	int static position = 0;
	if (!root) {
		out[position] = ' ';
		position++;
		out[position] = 'n';
		position++;
		out[position] = 'u';
		position++;
		out[position] = 'l';
		position++;
		out[position] = 'l';
		position++;
		return root;
	}
	else{
		out[position] = '(';
		position++;
		out[position] = root->symbol;
		position++;
	}
	printAbc(root->left, out);
	printAbc(root->right, out);
	out[position] = ')';
	position++;
	return root;
}

tree* freeMemory(tree *root) {
	if (!root)
		return root;
	if (root->left == root->right)
	{
		delete root;
		return nullptr;
	}
	root->left = freeMemory(root->left);
	root->right = freeMemory(root->right);
	delete root;
	return nullptr;
}

int makeHuffman() {
	ifstream inFile;
	ofstream outFile;
	inFile.open("in.txt", ios::in);
	outFile.open("out.txt", ios::out);
	if (!(inFile.is_open())) {
		cout << "Where is your file ???" << endl;
		return 0;
	}

	char string[100];
	int length = 0;
	while (!inFile.eof()) {
		inFile >> string[length];
		length++;
	}
	inFile.close();
	length--; // символ перехода //

	// chars массив с кодом всех символов из строки
	// popular массив частоты встречаемости символов
	int popular[200] = { 0 };
	int chars[100] = { 0 };
	int amountChars = 0;
	for (int i = 0; i < length; i++) {
		if (popular[string[i]] == 0) {
			chars[amountChars] = string[i];
			amountChars++;
		}
		popular[string[i]]++;

	}

	// сортируем chars в порядке позрастания //
	sortBubble(popular, chars, amountChars);
	cout << "frequency (increase):\n";
	for (int i = 0; i < amountChars; i++) {
		cout << char(chars[i]) << " " << popular[chars[i]] << endl;
	}

	// создали список для формирования из него дерева //
	tree *begin = nullptr;
	tree *end = nullptr;
	for (int i = 0; i < amountChars; i++) {
		addEnd(chars[i], popular[chars[i]], &begin, &end);
	}

	int amountPoints = amountChars;
	tree *leftList = nullptr;
	tree *rightList = nullptr;
	tree *rootTree = nullptr;
	int memory = 0;
	while (amountPoints != 1) {
		memory = begin->priory + (begin->next)->priory;
		leftList = begin;
		begin = begin->next;
		rightList = begin;
		begin = begin->next;
		rootTree = addBefore(&begin, &end, memory, '0');
		rootTree->left = leftList;
		leftList->code = '0';
		leftList->parent = rootTree;
		rootTree->right = rightList;
		rightList->code = '1';
		rightList->parent = rootTree;
		amountPoints--;
	}
	// построили дереве rootTree - вершина //

	tree *answer = nullptr;
	tree *help = nullptr;
	codes *pointersCodes[200] = { nullptr };
	for (int i = 0; i < amountChars; i++) {
		help = rootTree;
		answer = nullptr;
		pointersCodes[chars[i]] = createCodes();
		findC(help, char(chars[i]), &answer); // находим лист равный символу и получаем его код в обратном порядке //
		help = answer;
		int m = 0;
		while (help->parent) {
			pointersCodes[chars[i]]->s[m] = help->code;
			help = help->parent;
			m++;
		}
	}
	cout << endl;

	for (int i = 0; i < length; i++) {
		int lengthCode = 0;

		for (int j = 0; j < 20; j++) {
			if (pointersCodes[int(string[i])]->s[j] == -1){
				lengthCode = j;
				break;
			}
		}
		for (int m = 0; m < lengthCode; m++) {
			cout << pointersCodes[int(string[i])]->s[lengthCode - 1 - m];
			outFile << (pointersCodes[int(string[i])]->s[lengthCode - 1 - m]);
		}
		outFile << " ";
		cout << endl;
	}
	
	char out[1000] = { -1 };
	printAbc(rootTree,out);
	
	outFile << endl;
	for (int i = 0; i < strlen(out); i++) {
		outFile << out[i];
	}
	outFile.close();
	freeMemory(rootTree);
	for (int i = 0; i < 200; i++) {
		if (pointersCodes[i] != nullptr) {
			delete pointersCodes[i];
		}
	}
	return 0;
}

int main() {
	cout << "using\nin.txt\nout.txt\n";
	makeHuffman();
	return 0;
}