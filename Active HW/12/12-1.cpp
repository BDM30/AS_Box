#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cmath>

using namespace std;

// this is the calcucalor. Because in my original lessons we did it. analyzer is a part of calculator.

enum LexType { add, take, multiplication, division, open, close, number, finish, start };
const char functionSymbols [] = "+-*/()";
const char originalString [] = "(1+2)*3.14";
const int length = strlen(originalString);

bool calcExp(double &result, LexType &curLex, char lexemeString []);

int findNumberFunction(char symbol) {
	for (int i = 0; i < strlen(functionSymbols); i++) {
		if (symbol == functionSymbols[i]) {
			return i;
		}
	}
	return -1;
}

void clear(char str []) {
	for (int i = 0; i < strlen(str); i++) {
		str[i] = '\0';
	}
}

bool isSep(const char str) {
	return findNumberFunction(str) != -1 || str == ' ';
}

int count(const char str [], char symbol) {
	int answer = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == symbol)
			answer++;
	}
	return answer;
}

bool isNumber(const char str[]) {
	for (int i = 0; i < strlen(str); i++) {
		if (!isdigit(str[i]) && str[i] != '.') {
			return false;
		}
	}
	return count(str,'.') <= 1 && str[0] != '.';
}

void nextLexeme(LexType &curLex, char lexemeString[]) {
	int static expPos = 0;
	// �������
	while (expPos < length && originalString[expPos] == ' ')
		expPos++;
	if (expPos == length)
		curLex = finish;
	else {
		char c = originalString[expPos];
		int pos = findNumberFunction(c);
		if (pos != -1) {
			curLex = (LexType) pos;
			expPos++;
		}

		else {
			// ���� �������, ���� �����
			clear(lexemeString);

			int pos = 0;
			while (expPos < length && !isSep(originalString[expPos])) {
				lexemeString[pos] = originalString[expPos++];
				pos++;
			}
			if (isNumber(lexemeString))
				curLex = number;
			else
				curLex = start;
		}
	}
}

double toNum(char str[]) {
	double result;
	sscanf_s(str, "%lf", &result);
	return result;
}

bool calcMul(double &result, LexType &curLex, char lexemeString []) {
	bool isNegative = false;
	if (curLex == add || curLex == take) {
		isNegative = curLex == take;
		nextLexeme(curLex, lexemeString);
	}
	switch (curLex) {
		case number: {
			result = toNum(lexemeString);
			nextLexeme(curLex, lexemeString);
			break;
		}
		case open:{
			nextLexeme(curLex, lexemeString);
			if (!calcExp(result, curLex, lexemeString))
				return false;
			if (curLex != close)
				return false;
			nextLexeme(curLex, lexemeString);
			break;
		}
	}
	result *= isNegative ? -1 : 1;
	return true;
}

bool calcTerm(double &result, LexType &curLex, char lexemeString []) {
	if (!calcMul(result, curLex, lexemeString))
		return false;
	while (curLex == multiplication || curLex == division) {
		LexType operation = curLex;
		double next = 0.0;
		nextLexeme(curLex, lexemeString);
		if (!calcMul(next, curLex, lexemeString))
			return false;
		switch (operation) {
			case multiplication: { 
				result *= next;
				break;
			}
			case division:{ 
				result /= next;
				break;
			}
		}
	}
	return true;
}

bool calcExp(double &result, LexType &curLex, char lexemeString[]) {
	if (!calcTerm(result, curLex,lexemeString))
		return false;
	while (curLex == add || curLex == take) {
		LexType operation = curLex;
		nextLexeme(curLex, lexemeString);
		double next = 0.0;
		if (!calcTerm(next, curLex, lexemeString))
			return false;
		switch (operation) {
			case add: {
				result += next;
				break;
			}
			case take: { 
				result -= next;
				break;
			}
		}
	}
	return curLex == finish || curLex == close;
}

int main() {
	LexType curLex = start;
	char lexemeString[10] = { '/0' };
	double result = 0.0;
	nextLexeme(curLex, lexemeString);

	if (calcExp(result,curLex, lexemeString))
		printf("%0.3f\n", result);
	else
		printf("wrong expression\n");
	return 0;
}
