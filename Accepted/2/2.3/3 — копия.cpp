#include <iostream>
#include <cstdlib>

using namespace std;

// вывод  ряда таблицы таблицы //
void left(int array[100][100], int number, int strng) {
	const int volume = 100;
	int static unique[volume][volume];
	int cur[volume];
	for (int i = 0; i < number; i++)
		cur[i] = 0;
	int sum = 0;
	int max = 0;
	int amountTerms = -1;

	for (int i = 0; i < number; i++){
		sum = sum + array[i][strng];
		if (array[i][strng] > max)
			max = array[i][strng];
		if (sum <= number) {
			amountTerms++;
			cur[amountTerms] = array[i][strng];
		}
		if ((sum == number) && (unique[amountTerms][max] == 0)) {
			cout << endl;
			unique[amountTerms][max]++;
			for (int m1 = 0; m1 <= amountTerms; m1++) {
				cout << cur[m1];
				if (m1 != amountTerms)
					cout << "+";
			}
		}
	}

}

int main() {
	const int volume = 100;
	int number = 0;
	cout << "Enter Number " << endl;
	cin >> number;
	if (number == 1)
		cout << "1" << endl;
	int arrayTerms[volume][volume];

	//создал таблицу i-строка j-ряд //
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number - 1; j++) {
			if (i >0)
				arrayTerms[i][j] = 1;
			else
				arrayTerms[i][j] = j + 1;
		}
	}

	for (int i = 0; i < number - 1; i++) {
		left(arrayTerms, number, i);
	}
	for (int j = 0; j < number - 1; j++) {
		int passage = 0;
		while (passage <= number / 2 + 1) {
			passage++;
			for (int i = 1; i < number - 1; i++) {
				arrayTerms[i][j]++;
				left(arrayTerms, number, j);
			}
		}
	}

	cout << endl;
	return 0;
}