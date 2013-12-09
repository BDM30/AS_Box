#pragma once

namespace stack {
	struct Stack {
		char value;
		Stack *prev;
	};

	void push(char value, Stack *&top);
	void pop(Stack *&top, char pointer [], int &current);
	int infix(char string [], char stringIn []);
	void del(Stack *&top);
	bool firstPriority(Stack *&top);
}