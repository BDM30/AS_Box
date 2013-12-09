#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

int main() {
	char strng[100];
	cout << "Enter the string " << endl;
	cin.getline(strng, 100);
	int length = strlen(strng);
	int shiftLeft = 0;
	int shiftRight = 0;
	int amountSpaces = 0;

	for (int i = 0; i < length; i++) {
		if (strng[i] == ' ')
			amountSpaces++;
	}

	bool right = true;

	for (int i = 0; i < ((length - amountSpaces) / 2); i++) {
		while (strng[i + shiftLeft] == ' ') {
			shiftLeft++;
		}
		while (strng[length - i - 1 - shiftRight] == ' ') {
			shiftRight++;
		}
		if (toupper(strng[i + shiftLeft]) != toupper(strng[length - i - 1 - shiftRight])) {
			right = false;
			break;
		}
	}

	if (right)
		cout << "Palindrome! " << endl;
	else
		cout << "Oh,NO!!!" << endl;

	return 0;
}