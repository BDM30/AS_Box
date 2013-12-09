#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int binaryExponent = 0;
	cout << "Enter the number" << endl;
	cin >> binaryExponent;
	int expnt = 0;
	cout << "Enter the exponent" << endl;
	cin >> expnt;
	int answer = 1;

	while (expnt > 0) {
		if (expnt % 2 == 1) {
			answer = answer * binaryExponent;
		}
		binaryExponent = binaryExponent * binaryExponent;
		expnt = expnt / 2;
	}

	cout << "Answer : " << answer << endl;
	return 0;
}