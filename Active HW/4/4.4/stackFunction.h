#pragma once

namespace stackName {
	struct Stack {
		double value;
		Stack *prev;
	};

	void push(double value, Stack *&top);
	void pop(Stack *&top, char pointer [], int &current);
	int infix(char stringOut [], char stringIn []);
	void del(Stack *&top);
	double calculateStack(int length, char stringOut []);
	bool firstPriority(Stack *&top);
}