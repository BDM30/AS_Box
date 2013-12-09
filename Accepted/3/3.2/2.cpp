#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

// расстояние от (Х;Y) до середины //
float dist(int Xa, int Ya, int mid){
	float midDistance = 0;
	midDistance = sqrt((mid - Xa) * (mid - Xa) + (mid - Ya) * (mid - Ya));
	return midDistance;
}

void circle(int Xc, int Yc, int raz, float array[10][10], float maxDistCentr [], int mid) {
	Yc--;
	cout << array[Xc][Yc] << " ";
	while (dist(Xc, Yc, mid) < maxDistCentr[raz]) {
		Xc--;
		cout << array[Xc][Yc] << " ";
	}
	Yc++;
	cout << array[Xc][Yc] << " ";
	while (dist(Xc, Yc, mid) < maxDistCentr[raz]) {
		Yc++;
		cout << array[Xc][Yc] << " ";
	}
	Xc++;
	cout << array[Xc][Yc] << " ";
	while (dist(Xc, Yc, mid) < maxDistCentr[raz]) {
		Xc++;
		cout << array[Xc][Yc] << " ";
	}
	Yc--;
	cout << array[Xc][Yc] << " ";
	while (dist(Xc, Yc, mid) < maxDistCentr[raz]) {
		Yc--;
		cout << array[Xc][Yc] << " ";
	}
}

int main() {
	int amount = 0;
	cout << "Enter amout ";
	cin >> amount;
	// координаты середины //
	int mid = 0;
	mid = amount / 2;
	// В maxDistCentr записываем максимальное расстояние от цетра до круга //
	float maxDistCentr[10];
	for (int i = mid; i >= 0; i--) {
		maxDistCentr[mid - i] = dist(i, i, mid);
	}

	// массив для примера //
	float array[10][10];
	for (int i = 0; i < amount; i++) {
		cout << endl;
		for (int j = 0; j < amount; j++) {
			array[i][j] = rand() % 10;
			cout << array[i][j] << " ";
		}
	}

	cout << endl << "Answer " << endl;
	int x = mid;
	int y = mid;
	cout << array[x][y] << " ";
	for (int i = 1; i <= mid; i++) {
		circle(x, y, i, array, maxDistCentr, mid);
		x++;
		y--;
	}

	cout << endl;
	return 0;
}
