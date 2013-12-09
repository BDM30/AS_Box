#include <iostream>

#include <cstdlib>

using namespace std;

long fact(int number){
	if (number == 0)
		return 1;
	else
		return number * fact(number - 1);
}

int main(){
	int number = 0;
	cout << "Enter the number" << endl;
	cin >> number;
	// итеративно //
	long answerF = 1;
	for (int i = 2; i <= number; i++)
		answerF = answerF * i;
	cout << "Answer1 : " << answerF << endl;
	// рекурсивно //
	cout << "Answer2 : " << fact(number) << endl;
	return 0;
}