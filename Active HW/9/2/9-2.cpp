#include<iostream>
#include<cstdlib>
#include<string.h>

#define dictionary 256

using namespace std;

void algorithmRK(char *fullString, char *subString, int primeNumber){
	int lengthSubString = strlen(subString);
	int lengthFullString = strlen(fullString);

	int hashSubString = 0;
	int hashFullString = 0;
	int hash = 1;

	for (int i = 0; i < lengthSubString - 1; i++){
		hash = (dictionary*hash)%primeNumber;
	}

	for (int i = 0; i < lengthSubString; i++){
		hashSubString = (dictionary*hashSubString + subString[i])%primeNumber;

		hashFullString = (dictionary*hashFullString + fullString[i])%primeNumber;

	}

	for (int i = 0; i <= lengthFullString - lengthSubString; i++){

		if (hashFullString == hashSubString){
			int j = 0;
			for (0; j < lengthSubString; j++){
				if (fullString[i + j] != subString[j]) {
					break;
				}
			}
			if (j == lengthSubString) cout << "Pattern matched at index " << i << endl;
		}

		if (i < lengthFullString - lengthSubString){
			hashFullString = (dictionary*(hashFullString - fullString[i] * hash) + fullString[i + lengthSubString])%primeNumber;

			if (hashFullString < 0)
				hashFullString = (hashFullString + primeNumber);
		}
	}
}

int main(){
	char fullString[500];
	char subString[500];
	cout << "Enter the string" << endl;
	gets_s(fullString);
	cout << "Enter the sub-string you wish to search for" << endl;
	gets_s(subString);
	int primeNumber = 7;
	algorithmRK(fullString, subString, primeNumber);
	return 0;
}