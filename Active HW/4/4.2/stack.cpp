#include <iostream>
#include <cstdlib>
#include <string.h>
#include "stackFunction.h"

using namespace std;
using namespace stack;

int main()
{
	//считали строку и нашли ее длину //
	char *stringIn = new char[100];
	cout << "Enter the sring" << endl;
	cin.getline(stringIn, 100);
	int length = strlen(stringIn);
	char *stringOut = new char[100];

	for (int i = 0; i < infix(stringOut, stringIn); i++)
		cout << stringOut[i];
	delete []stringOut;
	delete []stringIn;
	cout << endl;
	return 0;
}