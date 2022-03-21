#include "Header.h"

void RemoveCourseEnrolled(Schoolyear* YearCur, Course* CourseHead, int x)
{
	if (x==0) return;
	string ClassID;
	int i;
	cout << "Enter the course you want to remove: ";
	getline(cin, ClassID);
	cout << "Which semester? ";
	cin >> i;
	do{
		cout << "Enter the course you want to remove: ";
		getline(cin, ClassID);
		cout << "Which semester? ";
		cin >> i;
		while (YearCur->Sem[i-1].pCourse!=nullptr){
			YearCur->Sem[i-1].pCourse=YearCur->Sem[i-1].pCourse->pNext;
		}	
		cout << "No classID available. Please try again." << endl;
		
	}
	while (YearCur->Sem[i-1].pCourse->CourseID!=ClassID);
	
	CourseHead=YearCur->Sem[i-1].pCourse;
	
	do{
		cout << "Class found!" << endl;
		cout << "Before we remove your course"
		string Student, StudentID, gender, ID;
		cout << "Input your student name: ";
		getline(cin, Student);
		cout << "Input your ID: ";
		getline(cin, ID);
		cout << "Input your student ID: ";
		getline(cin, StudentID);
		cout << "Input your gender: ";
		getline(cin, gender);
		
		
	}
}
