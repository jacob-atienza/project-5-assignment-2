/**
* Project: Assignment 2
* Developer: Jacob Atienza
* Date: 9/26/2026
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const string STUDENT_DATA_FILE = "StudentData.txt";

struct STUDENT_DATA {
	string firstName;
	string lastName;
};

int main(void) {
	ifstream file(STUDENT_DATA_FILE);
	if (!file) {
		cerr << "Error opening file!" << endl;
		return -1;
	}

	vector<STUDENT_DATA> studentNames;
	string line;
	while (getline(file, line)) {
		stringstream ss(line);
		STUDENT_DATA student;

		getline(ss, student.firstName, ',');
		// Clear the whitespace after the comma before the lastname
		ss >> ws;
		getline(ss, student.lastName);

		studentNames.push_back(student);
	}
	return 1;
}