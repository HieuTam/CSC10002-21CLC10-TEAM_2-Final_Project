#include "header.h"

void AddNewCourse(Course*& CourseHead)
{
	Course* temp = new Course;
	temp->NumOfStu = 0;
	clear();
	gotoxy(32, 11);
	cout << "Input course ID:";
	Draw(10);
	gotoxy(51, 11);
	getline(cin, temp->CourseID);
	gotoxy(27, 14);
	cout << "Input name of course:";
	Draw(13);
	gotoxy(51, 14);
	getline(cin, temp->NameOfCourse);
	gotoxy(28, 17);
	cout << "Input teacher name:";
	Draw(16);
	gotoxy(51, 17);
	getline(cin, temp->NameOfteacher);
	gotoxy(24, 20);
	cout << "Input number of credits:";
	Draw(19);
	gotoxy(51, 20);
	getline(cin, temp->NumOfCredit);
	gotoxy(36, 23);
	cout << "Input day 1:";
	Draw(22);
	gotoxy(51, 23);
	getline(cin, temp->Day1);
	gotoxy(32, 26);
	cout << "Input session 1:";
	Draw(25);
	gotoxy(51, 26);
	getline(cin, temp->Session1);
	gotoxy(36, 29);
	cout << "Input day 2:";
	Draw(28);
	gotoxy(51, 29);
	getline(cin, temp->Day2);
	gotoxy(32, 32);
	cout << "Input session 2:";
	Draw(31);
	gotoxy(51, 32);
	getline(cin, temp->Session2);
	temp->pNext = CourseHead;
	CourseHead = temp;
	txtColor(2);
	gotoxy(51, 34);
	cout << "Add new course successfully";
	txtColor(7);
}