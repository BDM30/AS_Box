#include <iostream>
#include <cstdlib>
#include <string.h>
#include "stackFunction.h"

using namespace std;
using namespace stackName;

int main()
{
	//считали строку и нашли ее длину //
	char *stringIn = new char[100];
	cout << "Enter the sring" << endl;
	cin.getline(stringIn, 100);
	char *stringOut = new char[100];
	cout << "In Reverse Polish notation :" << endl;
	for (int i = 0; i < infix(stringOut, stringIn); i++)
		cout << stringOut[i];
	cout << endl;
	// считаем //
	cout << "Result is:";
	cout << endl << calculateStack(infix(stringOut, stringIn), stringOut) << endl;

	delete []stringOut;
	delete []stringIn;

	return 0;
}