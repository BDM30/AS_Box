#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

#define amountWords 28
#define lengthWord 20

struct Digits {
	Digits *next;
	char string[lengthWord];
};

Digits *add(char str []){
	Digits *newE = new Digits;
	newE->next = nullptr;
	for (int i = 0; i < strlen(str); i++) {
		newE->string[i] = str[i];
	}
	for (int i = strlen(str); i < lengthWord; i++) {
		newE->string[i] = '\0';
	}
	return newE;
}

void print(int number, Digits *words []) {
	int divisor = 100;

	if (number / divisor != 0) {
		cout << words[number / 100]->string << " hundred ";
		number %= divisor;
		if (number) {
			cout << "and ";
		}
	}
	divisor = 10;
	if (number / divisor != 0) {
		if (number / divisor == 1) {
			cout << words[10 + number % divisor]->string << " ";
			return;
		}
		else {
			cout << words[18 + number / divisor]->string << " ";
		}

		if (number % divisor != 0) {
			cout << "- ";
		}

	}
	if (number % divisor != 0) {
		cout << words[number % divisor]->string << " ";
	}
}

int main() {

	Digits *words[amountWords] = { nullptr };

	cout << "enter the number" << endl;
	int number;
	cin >> number;
		if (number < 0) {
			cout << "minus ";
			number = number * (-1);
		}

		// создали массив слов //
		words[0] = add("zero");
		words[1] = add("one");
		words[2] = add("two");
		words[3] = add("three");
		words[4] = add("four");
		words[5] = add("five");
		words[6] = add("six");
		words[7] = add("seven");
		words[8] = add("eight");
		words[9] = add("nine");
		words[10] = add("ten");
		words[11] = add("eleven");
		words[12] = add("twelve");
		words[13] = add("thirteen");
		words[14] = add("fourteen");
		words[15] = add("fifteen");
		words[16] = add("sixteen");
		words[17] = add("seventeen");
		words[18] = add("eighteen");
		words[19] = add("nineteen");
		words[20] = add("twenty");
		words[21] = add("thirty");
		words[22] = add("forty");
		words[23] = add("fifty");
		words[24] = add("sixty");
		words[25] = add("seventy");
		words[26] = add("eighty");
		words[27] = add("ninety");
	
		int firstPart = number / 1000;
		int secondPart = number % 1000;

		if (firstPart != 0) {
			print(firstPart, words);
			cout << "thousand ";
		}
		print(secondPart, words);
		cout << endl;

		for (int i = 0; i < amountWords; i++) {
			delete words[i];
		}

	return 0;
}