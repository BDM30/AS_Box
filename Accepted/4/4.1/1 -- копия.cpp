#include <iostream>
#include <cstdlib>

using namespace std;

// меняем элементы массива местами //
void change(int first, int second, int mas []){
	int tmp = mas[first];
	mas[first] = mas[second];
	mas[second] = tmp;
}

void quickSort(int begin, int end, int s []){
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
		quickSort(i, end, s);
	if (j > begin)
		quickSort(begin, j, s);
}

int main(){
	int length = 0;
	//int array[100];
	cout << "Enter the length of the array" << endl;
	cin >> length;
	int *array = new int[length];
	cout << "Enter the elements of this array" << endl;
	for (int i = 0; i < length; ++i)
		cin >> array[i];

	quickSort(0, length - 1, array);
	int answer = 0;
	bool found = false;
	if ((length == 2) && (array[1] == array[0])) {
		answer = array[1];
		found = true;
	}
	if (length > 2) {
		for (int i = length - 1; i > 0; i--) {
			if (array[i] == array[i - 1]) {
				answer = array[i];
				found = true;
				break;
			}
		}
	}

	if (found)
		cout << endl << endl << answer << endl;
	else
		cout << endl << "Not Found" << endl;

	delete [] array;
	return 0;
}