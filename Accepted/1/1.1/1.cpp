#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	int x = 0;
	cout << "Enter x" << endl;
	cin >> x;
	cout << "Formula: õ^4+x^3+x^2+x=X^2(x^2+1)+x(x^2+1)=(x^2+x)*(x^2+1)" << endl;
	cout << "First multiplication x*x ; Second (x^2+x) by (x^2+1) " << endl;
	int fir = x * x;
	int sec = (fir + x) * (fir + 1);
	cout << "Answer: " << sec << endl;
	return 0;
}