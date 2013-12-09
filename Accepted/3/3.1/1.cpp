#include <iostream> 
#include <cstdlib> 
#include <string.h> 

using namespace std;

void change(int a, int b, char array []){
	char tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

void sort(int begin, int end, char array [])
{
	char middle = array[(begin + end) / 2];
	int i = begin;
	int j = end;
	while (i < j)
	{
		while (array[i] < middle)
			++i;
		while (array[j] > middle)
			--j;
		if (i <= j)
		{
			if (i < j)
				change(i, j, array);
			++i;
			--j;
		}
	}
	if (i < end)
		sort(i, end, array);
	if (j > begin)
		sort(begin, j, array);
}

int main(){

	char *stringFirst = new char[10];
	cout << "Enter the sring1" << endl;
	cin >> stringFirst;

	cout << "Enter the string2" << endl;
	char *stringSecond = new char[10];
	cin >> stringSecond;

	int length1 = strlen(stringFirst);
	int length2 = strlen(stringSecond); // считали строки и нашли их длины //
	if (length1 != length2)
		cout << "Error length of strings" << endl;

	else {
		sort(0, length1 - 1, stringFirst);
		sort(0, length1 - 1, stringSecond);
		bool work = true;
		for (int i = 0; i < length1; i++) {
			if (stringFirst[i] != stringSecond[i]) {
				work = false;
				break;
			}
		}
		if (work)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	delete []stringFirst;
	stringFirst = nullptr;
	delete []stringSecond;
	stringSecond = nullptr;

	return 0;

}