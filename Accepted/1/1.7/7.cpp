#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
	cout << "Enter the number" << endl;
	int number = 0;
	cin >> number;
	if (number >= 3) {
		cout << "2" << endl;
		int work = 0;
		for (int i = 3; i < number + 1; i++) {
			work = 0;
			for (int j = 2; j < i; j++)
				if (i % j == 0) {
					work = 1;
					break;
				};
				if (work == 0)
					cout << i << endl;
		}
	}
	if (number < 2)
		cout << "Too small(-" << endl;
	if (number == 2)
		cout << "2" << endl;
	return 0;
}