#include <iostream>

#include <cstdlib>

using namespace std;

// меняем элементы массива местами //
void change(int first, int second, int mas[]){
	int tmp = mas[first];
	mas[first] = mas[second];
	mas[second] = tmp;
}

void Quicksort(int begin, int end, int s[]){
	int middle = s[(begin + end) / 2];
	int i = begin;
	int j = end;

	while (i < j){
		while (s[i] < middle)
			++i;
		while (s[j] > middle)
			--j;
		if (i <= j)
		{
			if (i < j)
				change(i, j, s);
			++i;
			--j;
		}
	}

	if (i < end)
		Quicksort(i, end, s);
	if (j > begin)
		Quicksort(begin, j, s);
}

int main(){
	int length = 0;
	int array[100];
	cout << "Enter the length of the array" << endl;
	cin >> length;
	cout << "Enter the elements of this array" << endl;
	for (int i = 0; i < length; ++i)
		cin >> array[i];
	Quicksort(0, length - 1, array);
	cout << endl;
	for (int i = 0; i < length; ++i)
		cout << array[i] << ' ';
	return 0;
}