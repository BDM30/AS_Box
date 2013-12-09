#include <iostream>
#include "listFunction.h"

using namespace std;

using list::Node;

// Создать первый эелемент //
Node* list::first(int number) {
	Node *newNode = new Node;
	newNode->value = number;
	newNode->next = nullptr;
	return newNode;
}

// Добавить в конец списка //
void list::add(Node **endNode, int number){
	Node *newNode = new Node;
	newNode->value = number;
	newNode->next = nullptr;
	(*endNode)->next = newNode;
	*endNode = newNode;
}

// Поиск элемента по ключу //
Node* list::find(Node * const beginNode, int number) {
	Node *helpNode = beginNode;
	while (helpNode) {
		if (helpNode->value == number)
			break;
		helpNode = helpNode->next;
	}
	return helpNode;
}
// Удаление //
bool list::remove(Node **beginNode, Node **endNode, int key) {
	Node *start = *beginNode;
	Node *Pred = nullptr;

	while (start) {
		if ((start->next)->value == key) {
			Pred = start;
			break;
		}
		start = start->next;
	}

	if (Node *pkey = find(*beginNode, key)) {
		if (pkey == *beginNode) {
			*beginNode = (*beginNode)->next;
		}
		else
			if (pkey == *endNode) {
				*endNode = Pred;
				(*endNode)->next = nullptr;
			}
			else {
				(Pred)->next = pkey->next;

			}
			delete pkey;
			(*endNode)->next = *beginNode;
			return true;
	}
	return false;
}