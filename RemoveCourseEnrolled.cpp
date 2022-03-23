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
	Course *pCur=YearCur->Sem[i-1].pCourse;
	do{
		cout << "Enter the course you want to remove: ";
		getline(cin, ClassID);
		cout << "Which semester? ";
		cin >> i;
		while (pCur!=nullptr){
			pCur=pCur->pNext;
		}	
		cout << "No classID available. Please try again." << endl;
		
		pCur=YearCur->Sem[i-1].pCourse;
	}
	while (pCur->CourseID!=ClassID);
	
	CourseHead=YearCur->Sem[i-1].pCourse;
	cout << "Class found!" << endl;
	cout << "Before we remove your course, enter your information" << endl;
	Data *pCur1=CourseHead->DataOfStu;
	do{
		string name, StudentID, surname;
		cout << "Input your name: ";
		getline(cin, Student);
		cout << "Input your ID: ";
		getline(cin, ID);
		cout << "Input your student ID: ";
		getline(cin, StudentID);
		cout << "Input your gender: ";
		getline(cin, gender);
		
		while (pCur1!=nullptr){
			
		}
		
	}
}
