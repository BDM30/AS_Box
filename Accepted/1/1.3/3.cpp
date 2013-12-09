#include <iostream>

#include <cstdlib>

using namespace std;

void turnArray(int begin, int end, int array[]){
	int finish = end;
	if (begin != 0)
		finish = end + 2;

	for (int i = begin; i < finish / 2; i++){
		int tmp = array[i];
		array[i] = array[end - (i - begin) - 1];
		array[end - (i - begin) - 1] = tmp;
	}
}

int main(){
	int length = 0;
	cout << "Enter the length of the array" << endl;
	cin >> length;
	int arr[10];
	cout << "Enter the array" << endl;
	for (int i = 0; i < length; i++) {
		cin >> arr[i];
	}
	cout << "Enter the length of the first part" << endl;
	int lengthFirstPart = 0;
	cin >> lengthFirstPart;
	if (lengthFirstPart >= length) {
		return 1;
	}

	// Turn first part //
	turnArray(0, lengthFirstPart, arr);
	int c = 0;
	// Turn second part //
	turnArray(lengthFirstPart, length, arr);
	//Turn all array//
	turnArray(0, length, arr);
	cout << endl;
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}