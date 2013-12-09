#include <iostream>
#include <cstdlib>
#include <string.h>
#include "stackFunction.h"

using namespace std;
using namespace Stack;

int main() {
	char string[20];
	cin.getline(string, 20);
	calc(string, strlen(string));
	return 0;
}