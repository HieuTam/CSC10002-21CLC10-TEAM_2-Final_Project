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
	
	string name, StudentID, surname;
	do{
	
		cout << "Input your name: ";
		getline(cin, Student);
		cout << "Input your surname: ";
		getline(cin, surname);
		cout << "Input your student ID: ";
		getline(cin, StudentID);
		
		while (pCur1!=nullptr){
			pCur1=pCur1->pNext;
		}
		
		cout << "Your information is unavailable. Try again" << endl;
		
	}while(pCur1->Name!=Student || pCur1->StudentID!=StudentID || pCur1->StudentID!=surname)
	
	Data *tmp=pCur1;
	pCur1=pCur1->pNext;
	delete tmp;
	
	cout << "Success! You have deleted a course you enrolled!";
}
