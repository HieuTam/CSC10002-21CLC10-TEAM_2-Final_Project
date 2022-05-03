#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include<iomanip>
#include <string>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <conio.h>
#pragma warning(disable : 4996)
using namespace std;


struct teacher
{
	string Name, Surname, PassWord, Account, Email, Gender;
};


struct date
{
	int day, month, year;
};


struct Mark
{
	string Total = "", Midterm = "", Final = "", Other = "";
};

struct Data
{
	string StudentID, Surname, Name;
	int j, k;
	Data* pNext;
	Mark Score;
};



struct Course
{
	string NameOfCourse, CourseID, NameOfteacher, NumOfCredit, Day1, Day2, Session1, Session2;
	Course* pNext;
	Data* DataOfStu = nullptr;
	int NumOfStu = 0, MaxStu = 50;
	Mark Score;
};


struct Student
{
	int* Mark, NumOfOpt; //Mark la diem cac mon
	string Name, Surname, StudentID, PassWord, Gender, DOB, ID, Num; //StudentID la MSSV, ID la CCCD
	Course* Registered = nullptr;
};


struct Class
{
	string NameOfClass = "";
	Student* Stu;
	int NumOfStudent;
};


struct Semester
{
	Course* pCourse = nullptr;
	string StartSem;
	date StartReg, EndReg, EndSem;;
};


struct Schoolyear
{
	Semester Sem[3];
	string NumOfYear = ""; 
	Class* CLass;
	Schoolyear* YearNext;
	int NumOfClass;
};

void gotoxy(int x, int y);

void txtColor(int color);

void clear();

void ShowCur(bool CursorVisibility);

void Back();

void DisableCtrButton(bool Max);

void DisableResizeWindow();

void SetWindowSize(SHORT width, SHORT height);

void SetScreenBufferSize(SHORT width, SHORT height);

void FillPassword(string& password);

void InputUserAndPW(string& username, string& password);

void AddNewYear(Schoolyear*& NewYear);

void InputStaff(teacher*& Staff, int& NumOfStaff);

void InputStudents(Student*& St, int& NumOfStu);

int CheckLogin(string username, string password, Schoolyear*& YearCur, teacher* Staff, int NumOfStaff, Student* stu, int NumOfStu);

void ViewInfo(int x, Schoolyear* YearCur, teacher* Staff);

void ChangePassword(Schoolyear* YearCur, teacher* Staff, int x, int NumOfStaff);

void AddNewSemester(Schoolyear*& YearCur, int& x);

void AddNewCourse(Course*& CourseHead);

void ViewCourse(Course* CourseHead, int& t, int& i);

void UpdateCourse(Schoolyear* YearCur, int sem);

void SaveInfoCourse(Schoolyear* YearCur, int sem);

void DeleteCourse(Schoolyear*& YearCur, int sem);

void Now(date& Today);

bool CheckdateRegister(date Today, date StartReg, date EndReg);

bool CheckdateEndSemester(date Today, date EndSem);

bool CheckImport(Schoolyear* YearCur, int x);

void CourseEnroll(Schoolyear* YearCur, Course* CourseHead, int x, int& NumOfOpt);
//
//void ViewListEnrolled(Schoolyear* YearCur, int x);
//
//void RemoveCourseEnrolled(Schoolyear* YearCur, Course* CourseHead, int x);
//
void ViewListClasses(Schoolyear* YearCur);
//
//void ViewListStudentInClass(Schoolyear* YearCur);
//
//void ViewListStudentInCourse(Schoolyear* YearCur, int sem);
//
//void ExportListStudentCourse(Course* CourseHead);
//
//void LoadScoreboard(Course*& CourseHead, Schoolyear*& YearCur);
//
//void ViewScoreboardCourse(Course* CourseHead);
//
//void ViewScoreboardClass(Schoolyear* YearCur, int x);
//
//void ViewScoreboardStu(Schoolyear* YearCur, int x);
//
//void UpdateStudentResult(Schoolyear*& YearCur, Course*& CourseHead);

#endif