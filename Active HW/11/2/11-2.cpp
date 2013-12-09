#include <iostream>
#include <cstdlib>

using namespace std;

bool isSign(char a) {
	return (a == '+' || a == '-' || a == '*' || a == '/');
}

bool isDigit(char a) {
	return (a >= '0' && a <= '9');
}

bool isEnd(char a) {
	return a == '\0';
}

bool isExp(char a) {
	return a == 'E' || a == 'e';
}

bool isDot(char a) {
	return a == '.';
}

bool checkFloat_S(const char* str)
{
	cout << "process:" << endl;
	enum State { m1, m2, m3, m4, e1, e2, e3 } state = m1;
	while (true)
	{
		char c = *(str++);
		switch (state)
		{
		case m1:
			if (isSign(c)) {
				cout << "found out sign " << c << endl;
				state = m2;
			}
			else if (isDigit(c)) {
				cout << "found out digit " << c << endl;
				state = m3;
			}
			else {
				cout << "found out wrong char \n";
				return false;
			}
			break;

		case m2:
			if (isDigit(c)) {
				cout << "found out digit " << c << endl;
				state = m3;
			}
			else {
				return false;
				cout << "found out wrong char \n";
			}
			break;

		case m3:
			if (isDigit(c)) {
				cout << "found out digit " << c << endl;
				state = m3;
			}
			else if (isDot(c)) {
				cout << "found out dot .\n";
				state = m4;
			}
			else if (isExp(c)) {
				cout << "found out exponent " << c << endl;
				state = e1;
			}
			else if (isEnd(c))  { 
				cout << "found out end\n";
				return true; 
			}
			else {
				cout << "found out wrong char \n";
				return false;
			}
			break;

		case m4:
			if (isDigit(c)) {
				cout << "found out digit " << c << endl;
				state = m4;
			}
			else if (isExp(c)) {
				cout << "found out exponent " << c << endl;
				state = e1;
			}
			else if (isEnd(c)) {
				cout << "found out end\n";
				return true;
			}	
			else {
				cout << "found out wrong char \n";
				return false;
			}
			break;

		case e1:
			if (isSign(c)) {
				cout << "found out sign " << c << endl;
				state = e2;
			}
			else if (isDigit(c)) {
				cout << "found out digit " << c << endl;
				state = e3;
			}
			else {
				cout << "found out wrong char \n";
				return false;
			}
			break;

		case e2:
			if (isDigit(c)) {
				cout << "found out digit " << c << endl;
				state = e3;
			}
			else {
				cout << "found out wrong char \n";
				return false;
			}
			break;

		case e3:
			if (isDigit(c)) {
				cout << "found out digit " << c << endl;
				state = m3;
			}
			else if (isEnd(c)) {
				cout << "found out end\n";
				return true;
			}
			else {
				cout << "found out wrong char \n";
				return false;
			}
			break;
			return false;
		}
	}
}

int main() {
	char  arr [] = "-1.25e+1";
	// Warning!
	// 8 = float 7.62=float too // 
	cout << "test number:\n" << arr << endl << endl;
	if (checkFloat_S(arr))
		cout << "it may be float \n";
	else
		cout << "it is not float\n";
	return 0;
}