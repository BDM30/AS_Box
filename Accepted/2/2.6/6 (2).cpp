#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

// Находим кол-во символов в числе //
int amountSymbol(int number){
	int c = 0;
	while (number > 0) {
		number = number / 10;
		c++;
	}
	return c;
}

// Добавить число в строку //
void add(char left [], int positionString, int number) {
	int number1 = number;
	// сделали массив из цифр числа //
	int currentSymbol = 0;
	int helper = 0;
	int exponentTen = 0;
	int array[10];
	while (currentSymbol < amountSymbol(number)) {
		helper = amountSymbol(number) - currentSymbol - 1;
		exponentTen = pow(10, helper);
		array[currentSymbol] = number1 / exponentTen;
		number1 = number1 - array[currentSymbol] * exponentTen;
		currentSymbol++;
	}
	for (int i = 0; i < currentSymbol; i++) {
		left[positionString] = array[i] + 48;
		positionString++;
	}
}

int main() {
	char botton[100];
	int amountCoef = 0;
	cout << " Enter amount of Coefficients " << endl;
	cin >> amountCoef;

	int positionString = 0;
	cout << " Enter the Coefficients " << endl;
	int valueCoef = 0;
	int expCoef = amountCoef - 1;

	int currentCoef = 0;
	for (int i = 0; i < amountCoef; i++) {
		cin >> valueCoef;
		bool plus = true;
		if (valueCoef < 0) {
			botton[positionString] = '-';
			positionString++;
			plus = false;
		}
		if (valueCoef != 0) {
			valueCoef = abs(valueCoef);
			if (((plus)) && (expCoef != amountCoef - 1) && (valueCoef != 0) && (currentCoef != 0)) {
				botton[positionString] = '+';
				positionString++;
			}
			if (!((valueCoef == 1) && (expCoef > 0))) {
				add(botton, positionString, valueCoef);
				positionString = positionString + amountSymbol(valueCoef);
				currentCoef++;
			}
			else {
				currentCoef++;
			}
		}
		if ((expCoef > 0) && (valueCoef != 0)) {
			botton[positionString] = 'x';
			positionString++;
		}
		if ((expCoef > 1) && (valueCoef != 0)) {
			add(botton, positionString, expCoef);
			positionString = positionString + amountSymbol(expCoef);
		}
		expCoef--;
	}

	char upper[100];
	for (int i = 0; i < positionString; i++) {
		upper[i] = botton[i];
	}

	// чистим Upper для вывода //
	bool findExp = false;
	for (int i = 0; i < positionString; i++) {
		if (upper[i] == 'x') {
			findExp = true;
			upper[i] = ' ';
		}
		if ((upper[i] == '+') || (upper[i] == '-'))
			findExp = false;
		if ((upper[i] != 'x') && (!findExp))
			upper[i] = ' ';


	}
	// чистим botton для вывода //
	for (int i = 0; i < positionString; i++) {
		if (upper[i] != ' ')
			botton[i] = ' ';
	}

	//вывод
	for (int i = 0; i < positionString; i++) {
		cout << upper[i];
	}
	cout << endl;
	for (int i = 0; i < positionString; i++) {
		cout << botton[i];
	}

	cout << endl;

	return 0;
}