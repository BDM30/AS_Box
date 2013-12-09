#include <cstdlib>
#include <iostream>
#include <string.h>
#include "stackFunction.h"

using namespace std;
using stack::Stack;

void stack::push(char value, Stack *&top) {
	Stack* helpPointer = new Stack;
	helpPointer->value = value;
	helpPointer->prev = top;
	top = helpPointer;
}

bool stack::firstPriority(Stack *&top) {
	if ((top->value == '*') || (top->value == '/')) {
		return 1;
	}
	else
		return 0;
}

void stack::pop(Stack *&top, char pointer [], int &current) {
	Stack *helpPointer = top;
	top = (top->prev);
	pointer[current] = helpPointer->value;
	current++;
	delete helpPointer;
}

void stack::del(Stack *&top) {
	Stack *helpPointer = top;
	top = top->prev;
	delete helpPointer;
}

int stack::infix(char stringOut [], char stringIn []){
	int size = strlen(stringIn);
	Stack *top = nullptr;
	int current = 0;
	int i = 0;
	for (int i = 0; i < size; i++) {
		if (stringIn[i] == '(')
			push(stringIn[i], top);
		if (stringIn[i] == ')') {
			while (top->value != '(') {
				pop(top, stringOut, current);
			}
			del(top);
		}
		else {
			if (isdigit(stringIn[i])) {
				stringOut[current] = stringIn[i];
				++current;
			}
			if ((stringIn[i] == '+') || (stringIn[i] == '-')) {
				if ( (top) && (firstPriority(top)) ) {
					while ( (top) && (firstPriority(top)) ) {
						pop(top, stringOut, current);
					}
					push(stringIn[i], top);
				}
				else {
					if ((top) && ((top->value == '+') || (top->value == '-')))
						pop(top, stringOut, current);
					push(stringIn[i], top);
				}
			}
			if ((stringIn[i] == '*') || (stringIn[i] == '/')) {
				push(stringIn[i], top);
			}
		}
	}
	// адрес указателя &top //
	// адрес переменной top 
	while (top) {
		pop(top, stringOut, current);
	}

	delete top;
	return current;
}
