#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>

using namespace std;

int main() {
	
	int adjacencyMatrix[26][26];
	char names[26];
	for (int i = 0; i < 26; i++) {
		names[i] = 0;
	}

	ifstream inFile;
	char nameFile[100];
	cout << "enter name of file" << endl;
	cin.getline(nameFile, 100);
	inFile.open(nameFile, ios::in);
	if (!(inFile.is_open())) {
		cout << "Where is your file ???" << endl;
		return 0;
	}
	
	cout << "enter start point" << endl;
	int currentString;
	cin >> currentString;
	int amountPoints = 0; // вершины
	inFile >> amountPoints;
	for (int i = 0; i < amountPoints; i++) {
		for (int j = 0; j < amountPoints; j++) {
			inFile >> adjacencyMatrix[i][j];
		}
	}

	int int2Char = 'A';
	int current = 1;
	names[currentString] ='A';
		
	while (current != (amountPoints - 1)) {
		for (int i = 0; i < amountPoints; i++) {
			if ((adjacencyMatrix[currentString][i] == 1) && (names[i] == 0)) {
				currentString = i;
				names[i] = current + int2Char;
				current++;
				break;
			}
		}
	}

	for (int i = 0; i < amountPoints; i++) {
		if (names[i] == 0) {
			names[i] = current + int2Char;
			break;
		}
	}

	for (int i = 0; i < amountPoints; i++) {
		cout << names[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < amountPoints; i++) {
		for (int j = 0; j < amountPoints; j++) {
			cout << adjacencyMatrix[i][j] << " ";
		}
		cout << endl;
	}
	inFile.close();
	return 0;
}