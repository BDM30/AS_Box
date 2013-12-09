#include <iostream>
#include <cstdlib>
#include <fstream>

#define infinity 1000;
#define defaultSize 36
using namespace std;

struct turn
{
	turn *next;
	int numberTown;
	int min;
};

turn* firstVertex()
{
	turn* newVertex = new turn;
	newVertex->min = 0;
	newVertex->numberTown = 1;
	newVertex->next = nullptr;
	return newVertex;
}

turn* createVertex(turn *end, int numberTown)
{
	turn *newVertex = new turn;
	newVertex->min = infinity;
	newVertex->numberTown = numberTown;
	end->next = newVertex;
	newVertex->next = nullptr;
	return newVertex;
}

void createNullMatrix(int matrix [][defaultSize], int sizeN)
{
	for (int i = 1; i <= sizeN; ++i)
		for (int j = 1; j <= sizeN; ++j)
			matrix[i][j] = 0;

	matrix[0][0] = 0;

	for (int i = 1; i <= sizeN; ++i)
	{
		matrix[0][i] = i;
		matrix[i][0] = i;
	}
}

void printMap(int map [][defaultSize], int sizeN)
{
	for (int i = 0; i <= sizeN; ++i)
	{
		cout << endl;
		for (int j = 0; j <= sizeN; ++j)
			cout << map[i][j] << ' ';
	}

	cout << endl;
}

void recordMap(int map [][defaultSize], int &sizeN)
{
	ifstream inFile;
	inFile.open("myFile.txt", ios::in);

	if (!inFile.is_open()) cout << "File not found!" << endl;
	else
	{
		int sizeM = 0;
		inFile >> sizeN;
		inFile >> sizeM;
		createNullMatrix(map, sizeN);
		for (int z = 0; z < sizeM; ++z)
		{
			int i = 0;
			int j = 0;
			int len = 0;
			inFile >> i;
			inFile >> j;
			inFile >> len;
			map[i][j] = len;
			map[j][i] = len;
		}
	}
	inFile.close();
}

int deleteVertex(turn *&begin)
{
	int min = begin->min;
	turn *deleter = begin;
	begin = begin->next;
	delete deleter;
	return min;
}

turn* searchTown(turn *begin, int key)
{
	while (begin)
	{
		if (key == (begin->numberTown)) return begin;
		begin = begin->next;
	}
	return nullptr;
}

void valkiriya(int map [][defaultSize], int helpArray [], int sizeN, int vertex, turn *&begin, turn *&end)
{
	int j = 1;
	while (j <= sizeN)
	{
		if (map[vertex][j] && (!helpArray[j]))
		{
			if (!searchTown(begin, j)) end = createVertex(end, j);
			turn *findTown = searchTown(begin, j);
			if ((findTown->min) > (map[vertex][j] + begin->min))
				(findTown->min) = (map[vertex][j] + begin->min);
		}
		++j;
	}

	helpArray[vertex] = deleteVertex(begin);
	if (!begin) return;
	if (vertex == 1) ++helpArray[vertex];
	vertex = begin->numberTown;
	valkiriya(map, helpArray, sizeN, vertex, begin, end);
}

int main()
{
	turn *begin = firstVertex();
	turn *end = begin;

	int map[defaultSize][defaultSize];
	int helpArray[defaultSize];
	int sizeN = 0;
	int sizeM = 0;
	recordMap(map, sizeN);
	printMap(map, sizeN);
	cout << endl;
	for (int i = 1; i <= sizeN; ++i)
		helpArray[i] = 0;
	helpArray[1] = 1;
	valkiriya(map, helpArray, sizeN, 1,begin, end);
	int min = infinity;
	int mini = 0;
	
	for (int i = 2; i <= sizeN; ++i)
	{
		for (int j = 2; j <= sizeN; ++j)
		{
			if (helpArray[j] < min)
			{
				min = helpArray[j];
				mini = j;
			}
		}
		cout << "Zahvat " << mini << " Town " << "za " << min << endl;
		helpArray[mini] = infinity;
		min = infinity;
	}
	cout << endl;
	return 0;
}