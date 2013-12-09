#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int const maxStudents = 10;

struct Students {
	int students[maxStudents];
	int original;
};

Students *create(int value) {
	Students  *newP = new Students;
	newP->students[0] = value;
	for (int i = 1; i < maxStudents; i++)
		newP->students[i] = -1;
	newP->original = -1;
	return newP;
}

void addNote(Students *&where, Students *&what) {
	int i = 1;
	while (where->students[i] != -1) {
		i++;
	} // нашли позицию для записи //

	int j = 0;
	while (what->students[j] != -1) {
		where->students[i] = what->students[j];
		i++;
		j++;
	} // записали

	for (int m = 0; m < j; m++) {
		what->students[m] = -1;
	} // удалили лишнее
}

int FindOutOriginals() {
	ifstream inFile;
	inFile.open("in.txt", ios::in);
	if (!(inFile.is_open())) {
		cout << "Where is your file ???" << endl;
		return 0;
	}
	int amount = 0;
	inFile >> amount;

	// создал список стуркур в которых 1 эл-ту 
	Students *points[maxStudents] = { nullptr };
	for (int i = 0; i < amount; i++) {
		points[i] = create(i);
	}

	int who = -1;
	int from = -1;
	while (inFile.good()) {
		inFile >> who >> from;
		who--;
		from--;
		if (who > 1) {
			if (from < 3) {
				points[who]->original = from;
			}
			else {
				addNote(points[from], points[who]);
			}
		}
	}
	inFile.close();

	for (int i = 3; i < amount; i++) {
		if (points[i]->students[0] != -1)
			addNote(points[points[i]->original], points[i]);
	}

	for (int i = 0; i < 3; i++) {
		int j = 0;
		while (points[i]->students[j] != -1) {
			cout << points[i]->students[j] + 1 << " " << i + 1 << "\n";
			j++;
		}
	}

	// освободили память
	for (int i = 0; i < amount; i++) {
		delete points[i];
	}
	
	return 0;
}

int main() {
	FindOutOriginals();
	return 0;
}
