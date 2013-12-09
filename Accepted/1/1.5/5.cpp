#include <iostream>

#include <cstdlib>

#include <string.h>

using namespace std;
int main(){
	char srng[100];
	cout << "Enter the string " << endl;
	cin.getline(srng, 100);
	int length = strlen(srng);;
	bool right = true;
	int open = 0;
	int close = 0;

	for (int i = 0; i < length; i++) {
		if (srng[i] == '(')
			open++;
		if (srng[i] == ')')
			close++;
		if (close > open)
			right = false;
	}

	if ((open == close) && (right == true))
		cout << "All is well!" << endl;
	else
		cout << "Everything is bad!" << endl;

	return 0;
}