#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
	int devident = 0;
	int divisor = 0;
	cout << "Enter  dividend" << endl;
	cin >> devident;
	cout << "Enter divisor" << endl;
	cin >> divisor;
	int quotient = 0;
	while (devident >= divisor) {
		devident = devident - divisor;
		quotient++;
	}
	cout << "Answer: " << quotient << endl;
	return 0;
}