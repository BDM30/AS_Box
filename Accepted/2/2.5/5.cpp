#include <iostream>
#include <cstdlib>

using namespace std;

// меняем элементы массива местами //
void change(int first, int second, int mas[]){
	int tmp = mas[first];
	mas[first] = mas[second];
	mas[second] = tmp;
}
//Heapsort//
void heapSort(int array[], int amount) {
	int shift = 0;
	bool useful = false;

	while (shift + 2 < amount) {
		useful = false;
		for (int i = 0; i < amount; i++){
			int first = i * 2 + 1;
			int second = i * 2 + 2;
			if (second + shift < amount){
				if ((array[i + shift] > array[first + shift]) || (array[i + shift] > array[second + shift])){
					if (array[first + shift] < array[second + shift]){
						change(i + shift, first + shift, array);
						useful = true;
					}
					else if (array[second + shift] < array[first + shift]){
						change(i + shift, second + shift, array);
						useful = true;
					}
				}
			}
			else 
				if (first + shift < amount){
					if (array[i + shift] > array[first + shift]){
					change(i + shift, first + shift, array);
					useful = true;
					}
				}
		}
		if (!useful)
			shift++;
	}

}
int main() {
	int length = 0;
	int array[100];
	cout << "Enter the length of the array" << endl;
	cin >> length;
	cout << "Enter the elements of this array" << endl;
	for (int i = 0; i < length; ++i)
		cin >> array[i];
	heapSort(array, length);
	cout << endl;
	for (int i = 0; i < length; ++i)
		cout << array[i] << " ";
	cout << endl;
	return 0;
}