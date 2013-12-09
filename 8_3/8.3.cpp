#include <iostream>
#include <cstdlib>
#include <fstream>

#define defaultSize 36
#define mark 1

using namespace std;

bool generate(int matrix [][defaultSize], int matrixMarks [][defaultSize], int size, int vertex)
{
	int j = 0;
	bool checkMark = false;
	bool emptyPassage = true;

	while (j < size)
	{
		if (matrix[vertex][j])
		{
			if (matrixMarks[1][j]) return true;
			if (matrixMarks[0][j]) return false;

			emptyPassage = false;
			matrixMarks[0][j] = mark;
			checkMark = generate(matrix, matrixMarks, size, j);
		}
		if (checkMark) break;
		++j;
	}

	if (emptyPassage) checkMark = true;
	return checkMark;
}

int recordArray(int matrix [][defaultSize], int matrixMarks [][defaultSize])
{
	int size = 0;
	ifstream inFile;
	inFile.open("myFile.txt", ios::in);

	if (!inFile.is_open()) cout << "File not found!" << endl;
	else
	{
		inFile >> size;
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				inFile >> matrix[i][j];
				if (i < 2) matrixMarks[i][j] = 0;
				cout << matrix[i][j] << ' ';
			}
			cout << endl;
		}
			inFile.close();
	}
	return size;
}

int main()
{
	int matrix[defaultSize][defaultSize];
	int matrixMarks[2][defaultSize];
	int size = recordArray(matrix, matrixMarks);

	int components = 0;
	int i = 0;
	while (i < size)
	{
		if (!matrixMarks[1][i])
		{
			if (!generate(matrix, matrixMarks, size, i)) ++components;
			for (int i = 0; i < size; ++i)
				if (matrixMarks[0][i]) matrixMarks[1][i] = mark;
		}
		++i;
	}

	cout << endl << "Amount of components is " << components << endl;
	return 0;
}