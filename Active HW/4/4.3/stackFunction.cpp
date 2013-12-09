#include <iostream>
#include <cstdlib>
#include <string.h>
#include "stackFunction.h"

using namespace std;
using Stack::stack;

void Stack::push(stack *&top, char value) {
	stack *helpPointer = new stack;
	helpPointer->value = value;
	helpPointer->prev = top;
	top = helpPointer;
}

void Stack::calc(char string [], int length) {
	int const digitIntoSymbol = 48;

	stack *top = nullptr;
	stack *helper = nullptr;
	double tempValue = 0;

	for (int i = 0; i < length; i++) {
		if (isdigit(string[i]))
			push(top, string[i]);
		else
		{
			tempValue = top->value;
			helper = top;
			top = top->prev;
			delete helper;


			if (string[i] == '+')
			{

				top->value = top->value - digitIntoSymbol + tempValue;
			}

			if (string[i] == '-')
			{

				(top->value) = top->value - tempValue + digitIntoSymbol;
			}

			if (string[i] == '*')
			{

				(top->value) = ((top->value - digitIntoSymbol)*(tempValue - digitIntoSymbol) + digitIntoSymbol);
			}

			if (string[i] == '/')
			{

				(top->value) = (top->value - digitIntoSymbol) / (tempValue - digitIntoSymbol) + digitIntoSymbol;
			}
		}
	}

	cout << endl;
	cout << double(top->value) - digitIntoSymbol << endl;
	delete top;
}