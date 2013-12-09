#include <iostream>
#include <cstdlib>

using namespace std;
long long fibs[100];

// Функция Фиббоначи//
long long fib(int num){
	if (num == 1)
		return 1;
	if (num == 2)
		return 2;
	if (fibs[num] == 0){
		fibs[num] = fib(num - 1) + fib(num - 2);
	}
	return fibs[num];
}

int main() {
	for (int i = 0; i < 100; i++) {
		fibs[i] = 0;
	}
	cout << "Enter the number ( <=100)" << endl;
	int number = 0;
	cin >> number;
	// рекурсивно //
	cout << "Answer: " << fib(number) << endl;
	// итеративно //
	long long last = 1;
	long long next = 2;
	for (int i = 3; i <= number; i++) {
		long long temp = next;
		next = next + last;
		last = temp;
	}
	cout << "Answer: " << next << endl;
	return 0;
}