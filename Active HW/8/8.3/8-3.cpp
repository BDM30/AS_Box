#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>

using namespace std;

int main() {
	int matrix[100][100];
	ifstream inFile;
	char nameFile[100];
	cout << "enter name of file" << endl;
	cin.getline(nameFile, 100);
	inFile.open(nameFile, ios::in);
	if (!(inFile.is_open())) {
		cout << "Where is your file ???" << endl;
		return 0;
	}
	// кол-во вершин и кол-во ребер //
	int amountPoints = 0;
	int amountEdges = 0;
	inFile >> amountPoints >> amountEdges;

	for (int i = 0; i < amountPoints; i++) {
		for (int j = 0; j < amountPoints; j++) {
			matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < amountEdges; i++){
		int from = 0;
		int to = 0;
		inFile >> from >> to;
		matrix[from - 1][to - 1] = 1;
		matrix[to - 1][from - 1] = 1;
	}

	cout << "relationships: ";

	int showded[100];
	for (int i = 0; i < amountPoints; i++) {
		showded[i] = 0;
	}

	int amountShowded = 0;
	int currentString = 0;

	while (amountShowded < amountPoints) {
		int i = 0;
		if (showded[currentString] == 0) {
			cout << endl;
			cout << currentString+1 << " ";
			showded[currentString] = 1;
			amountShowded++;
		}
		for (i = currentString+1; i < amountPoints; i++) {
			if ( (matrix[currentString][i] != 0) && (showded[i] ==0 ) ) {
				cout << i+1 << " ";
				showded[i] = 1;
				amountShowded++;
			}
		}
		currentString++;
	}

	cout << endl;
	inFile.close();
		return 0;
}