#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;
int main() {
	char strng1[100];
	cout << "Enter the string" << endl;
	cin.getline(strng1, 100);
	char strng2[100];
	cout << "Enter the other string" << endl;
	cin.getline(strng2, 100);
	int length1 = strlen(strng1);
	int length2 = strlen(strng2); 
	// считали строки и нашли их длины //
	int maxACF = 0;
	int amountCombinationsFound = 0;
	int amountElementsFound = 0;

	for (int i = 0; i < (length1 - length2); i++) {
		if (amountCombinationsFound> maxACF)
			maxACF = amountCombinationsFound;
		amountElementsFound = 0;
		amountCombinationsFound = 0;

		for (int j = i; j < length1; j++) {
			if (strng1[j] != strng2[amountElementsFound])
				amountElementsFound = 0;
			if (strng1[j] == strng2[amountElementsFound])
				amountElementsFound++;
			if (amountElementsFound == length2) {
				amountCombinationsFound++;
				amountElementsFound = 0;
			}
		}

		if (amountCombinationsFound > maxACF)
			maxACF = amountCombinationsFound;
	}

	cout << "Answer: " << maxACF << endl;
	return 0;
}