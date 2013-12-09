#include <cstdlib>
#include <iostream>
#include <string.h>
#include "stackFunction.h"

using namespace std;
using stackName::Stack;

void stackName::push(double value, Stack *&top) {
	Stack* helpPointer = new Stack;
	helpPointer->value = value;
	helpPointer->prev = top;
	top = helpPointer;
}

void stackName::pop(Stack *&top, char pointer [], int &current) {
	Stack *helpPointer = top;
	top = (top->prev);
	pointer[current] = helpPointer->value;
	current++;
	delete helpPointer;
}

void stackName::del(Stack *&top) {
	Stack *helpPointer = top;
	top = top->prev;
	delete helpPointer;
}

int stackName::infix(char stringOut [], char stringIn []){
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
				if ((top) && (firstPriority(top))) {
					while ((top) && (firstPriority(top))) {
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

// посчитать стек //
double stackName::calculateStack(int length, char stringOut []) {
	int const digitIntoSymbol = 48;

	Stack *top = nullptr;
	Stack *helper = nullptr;
	double tempValue = 0;

	for (int i = 0; i < length; i++) {
		if (isdigit(stringOut[i]))
			push(stringOut[i],top);
		else
		{
			tempValue = top->value;
			helper = top;
			top = top->prev;
			delete helper;


			if (stringOut[i] == '+')
			{

				top->value = top->value - digitIntoSymbol + tempValue;
			}

			if (stringOut[i] == '-')
			{

				(top->value) = top->value - tempValue + digitIntoSymbol;
			}

			if (stringOut[i] == '*')
			{

				(top->value) = ((top->value - digitIntoSymbol)*(tempValue - digitIntoSymbol) + digitIntoSymbol);
			}

			if (stringOut[i] == '/')
			{

				(top->value) = (top->value - digitIntoSymbol) / (tempValue - digitIntoSymbol) + digitIntoSymbol;
			}
		}
	}
	double answer = double(top->value) - digitIntoSymbol;
	delete top;
	return answer;
	
}

bool stackName::firstPriority(Stack *&top) {
	if ((top->value == '*') || (top->value == '/')) {
		return 1;
	}
	else
		return 0;
}