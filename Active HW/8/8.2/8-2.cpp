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
	int amountTowns = 0;
	int amountRoads = 0;
	inFile >> amountTowns >> amountRoads;
	for (int i = 0; i < amountTowns; i++) {
		for (int j = 0; j < amountTowns; j++) {
			matrix[i][j] = 0;
		}
	}

	int from = 0;
	int to = 0;
	int distance = 0;
	for (int i = 0; i < amountRoads; i++) {
		inFile >> from >> to >> distance;
		matrix[from - 1][to - 1] = distance;
		matrix[to - 1][from - 1] = distance;
	}
	
	//Алгоритм Флойда-Уоршелла
	for (int k = 0; k < amountTowns; k++)
		for (int i = 0; i < amountTowns; i++)
			for (int j = 0; j < amountTowns; j++)
				if (matrix[i][k] && matrix[k][j] && i != j)
					if (matrix[i][k] + matrix[k][j] < matrix[i][j] || matrix[i][j] == 0)
						matrix[i][j] = matrix[i][k] + matrix[k][j];

	cout << endl << "Min distances" << endl;
	for (int i = 0; i < amountTowns; ++i, printf("\n"))
		for (int j = 0; j < amountTowns; ++j)
			printf("%d ", matrix[i][j]);

	int leftList[10];
	int weWere[10];
	for (int i = 0; i < amountTowns; i++) {
		leftList[i] = 0;
		weWere[i] = 0;
	}

	int amountamountTownsisited = 1;
	leftList[0] = 1;
	int currentString = 0;
	weWere[0] = 1;



	while (amountamountTownsisited < amountTowns) {
		int min = 10000;
		int minNumber = 777;

		for (int i = 0; i < amountTowns; i++) {
			if ((matrix[currentString][i] < min) && (matrix[currentString][i] != 0) && (weWere[i] == 0)) {
				min = matrix[currentString][i];
				minNumber = i;
			}
		}
		leftList[amountamountTownsisited] = minNumber + 1;
		weWere[minNumber] = 1;
		amountamountTownsisited++;
		currentString = minNumber;
	}

	cout << "Our army has visited" << endl;
	for (int i = 0; i < amountTowns; i++) {
		cout << i + 1 << ". " << leftList[i] << endl;
	}
	inFile.close();
	return 0;
}