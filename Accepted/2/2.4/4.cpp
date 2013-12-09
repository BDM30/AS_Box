#include <iostream>
#include <cstdlib>

using namespace std;

// numerator-числитель denominator-знаменатель//
bool simplification(int numerator, int denominator){
	bool right = true;

	if (numerator > 1) {
		for (int i = 2; i <= numerator; i++) {
			if ((numerator % i == 0) && (denominator % i == 0))
			{
				right = false;
				break;
			}
		}
	}

	// возврат//
	return ((numerator >= denominator) || !right);
}

int main() {
	cout << "Enter the number " << endl;
	int number = 0;
	cin >> number;
	int amountIrreducible = 0; // кол-во несокр. дробей //
	float numerator[100];
	float denominator[100];
	float value[100];

	// i - знаменатель j - числитель //
	for (int i = 2; i <= number; i++) {
		for (int j = 1; j < i; j++) {
			if (!simplification(j, i)) {
				numerator[amountIrreducible] = j;
				denominator[amountIrreducible] = i;
				value[amountIrreducible] = ((numerator[amountIrreducible]) / (denominator[amountIrreducible]));
				amountIrreducible++;
			}
		}
	}

	float min = 1;
	int presentValue = 0;
	int numerMin = 0;

	// вывод в порядке возрастания //
	while (presentValue < amountIrreducible) {
		presentValue++;
		for (int i = 0; i < amountIrreducible; i++){
			if (value[i] < min) {
				min = value[i];
				numerMin = i;
			}
		}
		cout << numerator[numerMin] << "/" << denominator[numerMin] << endl;
		value[numerMin] = 1;
		min = 1;
	}

	return 0;
}