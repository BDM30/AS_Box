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

void list::sortInsert(Node *beginNode, int amount) {
	Node *start2 = nullptr;
	int tmp = 0;
	int control = 0;

	for (int i = amount - 1; i > 0; i--) {
		start2 = beginNode;
		control = 0;
		while ((start2->next) && (control < i)) {
			control++;
			if (start2->value > (start2->next)->value) {
				tmp = start2->value;
				start2->value = (start2->next)->value;
				(start2->next)->value = tmp;
			}
			start2 = start2->next;
		}
	}

}