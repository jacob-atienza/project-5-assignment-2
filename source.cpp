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
	#ifdef PRE_RELEASE
		string email;
	#endif
};

int main(void) {
	#ifdef PRE_RELEASE
		cout << "Program running pre-release source code" << endl;
		const string fileName = STUDENT_DATA_EMAIL_FILE;
	#else
		cout << "Program running standard source code" << endl;
		const string fileName = STUDENT_DATA_FILE;
	#endif

	ifstream file(fileName);
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
		getline(ss, student.lastName, ',');
		#ifdef PRE_RELEASE
			getline(ss, student.email);
		#endif
		studentNames.push_back(student);
	}
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