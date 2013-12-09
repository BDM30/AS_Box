#include <iostream>
#include "listFunction.h"

using namespace std;

using list::Node;
// Создать первый эелемент //
Node* list::first(int number) {
	Node *newNode = new Node;
	newNode->valueNode = number;
	newNode->next = nullptr;
	return newNode;
}

// Добавить в список по порядку не в конец //
void list::addSort(Node **beginNode, Node **endNode, int number){
	Node *end = *endNode;
	Node *newNode = new Node;
	newNode->valueNode = number;
	Node * currentNode = *beginNode;

	// если элемент меньше первого, то он будет новым первым//
	if (number < currentNode->valueNode) {
		newNode->next = currentNode;
		*beginNode = newNode;
		if (currentNode == *endNode) {
			*endNode = currentNode;
		}
	}
	else {
		// Если новый больше первого //
		bool found = false; // результат поиска фолс //
		while (currentNode->next) {
			if ((currentNode->next)->valueNode > newNode->valueNode) {
				found = true;
				break;
			}
			// currentNode - предыдущий , а currentNode->next больше чем newNode //
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
	if ((*endNode)->valueNode <= number) {
		newNode->valueNode = number;
		newNode->next = nullptr;
		(*endNode)->next = newNode;
		*endNode = newNode;
	}
}

// Поиск элемента по ключу //
Node* list::find(Node * const beginNode, int number) {
	Node *helpNode = beginNode;
	while (helpNode) {
		if (helpNode->valueNode == number)
			break;
		helpNode = helpNode->next;
	}
	return helpNode;
}

// Существует ли элемент?? //
bool list::exist(Node *beginNode, int key) {
	bool right = false;
	Node *helpNode = beginNode;
	while (helpNode) {
		if (helpNode->valueNode == key) {
			right = true;
		}
		helpNode = helpNode->next;
	}
	return right;
}

// Удаление //
void list::del(Node **beginNode, Node **endNode, int key) {
	Node *pkey = find(*beginNode, key);
	Node *start = *beginNode;

	// удалили первый //
	if (start == pkey) {
		*beginNode = start->next;
		delete start;
	}
	else {
		bool found = false;
		while (start->next) {
			if (start->next == pkey) {
				found = true;
				break;
			}
			start = start->next;
		}
		// start - предыдущий для удаляемого start->next удаляемый //
		if (found) {
			start->next = (pkey)->next;
			delete pkey;
		}
	}
}