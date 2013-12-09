#pragma once

namespace Stack {
	struct stack {
		stack *prev;
		double value;
	};

	void push(stack *&top, char value);
	void calc(char string [], int length);
}