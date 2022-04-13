#include "Header.h"

void ViewScoreboardCourse(Course* CourseHead){
	string CourseID;
	cout << "Enter the CourseID: ";
	cin >> CourseID;
	Course *CourseCur=CourseHead;
	while (CourseCur && CourseCur->CourseID!=CourseID)
		CourseCur=CourseCur->pNext;
	if (CourseCur){
		cout << "Course ID: " << CourseCur->CourseID << endl;
			cout << "Scoreboard: " << endl;
			Data *InfoCur=CourseCur->DataOfStu;
			while (InfoCur){
				cout << "Student name: " << InfoCur->Surname << " " << InfoCur->Name << endl;
				cout << "Mid: " << InfoCur->Score.Midterm << endl;
				cout << "Final: " << InfoCur->Score.Final << endl;
				
				InfoCur=InfoCur->pNext;
			}
	}
}

int main(){
	Course *CourseHead=nullptr;
	int choice, choice1;
	
	cout << "Enter a course? ";
	cin >> choice;
	while (choice){
		Course *tmp=new Course;
		cout << "Course name: ";
		cin >> tmp->CourseID;
		cout << "Enter Student? ";
		cin >> choice1;
		
		while (choice1){
			Data *Info=new Data;
			cout << "Student Info: " << endl;
			cout << "Student ID: " << endl;
			cin >> Info->StudentID;
			cout << "Name: " << endl;
			cin >> Info->Name;
			cout << "Surname: " << endl;
			cin.ignore();
			getline(cin, Info->Surname);
			Info->pNext=tmp->DataOfStu;
			cout << "Score: " << endl;
			cout << "Midterm: ";
			cin >> Info->Score.Midterm;
			cout << "Final: ";
			cin >> Info->Score.Final;
			cout << "Other: ";
			cin >> Info->Score.Other;
			cout << "Total: ";
			cin >> Info->Score.Total;
			
			tmp->DataOfStu=Info;
			cout << "Enter again? ";
			cin >> choice1;
			
		}
		
		tmp->pNext=CourseHead;
		
		CourseHead=tmp;
		
		cout << "Enter again? ";
		cin >> choice;	
	}
	
	ViewScoreboardCourse(CourseHead);
}
