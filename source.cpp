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
const string STUDENT_DATA_EMAIL_FILE = "StudentData_Emails.txt";

struct STUDENT_DATA {
	string firstName;
	string lastName;

	// Only include email data in pre-release version
	#ifdef PRE_RELEASE
		string email;
	#endif
};

int main(void) {
	// Choose which student data file to use based on the build version
	#ifdef PRE_RELEASE
		cout << "Program running pre-release source code" << endl;
		const string fileName = STUDENT_DATA_EMAIL_FILE;
	#else
		cout << "Program running standard source code" << endl;
		const string fileName = STUDENT_DATA_FILE;
	#endif

	// Open the student data file and return early if it failed to open
	ifstream file(fileName);
	if (!file) {
		cerr << "Error opening file!" << endl;
		return -1;
	}

	vector<STUDENT_DATA> studentNames;
	string line;

	// Read and parse each student from the file
	while (getline(file, line)) {
		stringstream ss(line);
		STUDENT_DATA student;

		getline(ss, student.firstName, ',');
		// Clear the whitespace after the comma before the lastname
		ss >> ws;
		getline(ss, student.lastName, ',');

		// Read the student's email only in the pre-release version
		#ifdef PRE_RELEASE
			getline(ss, student.email);
		#endif
		studentNames.push_back(student);
	}

	// Only display student data when compiled in debug mode
	#ifdef _DEBUG
		for (int i = 0; i < studentNames.size(); i++) {
			#ifdef PRE_RELEASE
				cout << studentNames[i].firstName << " " << studentNames[i].lastName << " " << studentNames[i].email << endl;
			#else
				cout << studentNames[i].firstName << " " << studentNames[i].lastName << endl;
			#endif
		}
	#endif
	return 1;
}