#include <iostream>
#include <cstdlib>
using namespace std;
int const am = 28;
int main() {
	int tic[am]; // массив с 1 по 27 = возможная сумма цифр//
	for (int i = 0; i < am; i++) {
		tic[i] = 0;
	}
	for (int i = 0; i < 10; i++)
		tic[i]++; // смотрим числа с 0 по 9 //
	for (int i = 10; i < 100; i++)
		tic[(i / 10 + i % 10)]++; // смотрим числа с 10 по 99 //
	for (int i = 100; i < 1000; i++)
		tic[i / 100 + (i - (i / 100) * 100) / 10 + i % 10]++; // смотрим числа с 100 по 999 //
	int ans = 0;
	for (int i = 0; i < am; i++)
		ans = ans + tic[i] * tic[i]; // складываем квадраты сумм //
	cout << " Answer: " << ans << endl;
	return 0;
}