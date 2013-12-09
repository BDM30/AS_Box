#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

void change(int a, int b, int array []){
	int tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

void sort(int begin, int end, int s [])
{
	int middle = s[(begin + end) / 2];
	int i = begin;
	int j = end;
	while (i < j)
	{
		while (s[i] < middle)
			++i;
		while (s[j] > middle)
			--j;
		if (i <= j)
		{
			if (i < j)
				change(i, j, s);
			++i;
			--j;
		}
	}
	if (i < end)
		sort(i, end, s);
	if (j > begin)
		sort(begin, j, s);
}

int amountSymbol(int number){
	int c = 0;
	while (number > 0) {
		number = number / 10;
		c++;
	}
	return c;
}

int main() {
	cout << "Enter the number" << endl;
	int number = 0;
	cin >> number;
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

	sort(0, amountSymbol(number) - 1, array);
	cout << endl;

	// убираем ноль с первой позиции //
	int shift = 1;
	int tmp = 0;
	if ((array[0] == 0) && (amountSymbol(number) > 1)) {
		for (int shift = 1; shift < amountSymbol(number); shift++) {
			if (array[shift] != 0) {
				tmp = array[0];
				array[0] = array[shift];
				array[shift] = tmp;
				break;
			}
		}
	}

	for (int i = 0; i < amountSymbol(number); ++i)
		cout << array[i];

	cout << endl;
	return 0;
}