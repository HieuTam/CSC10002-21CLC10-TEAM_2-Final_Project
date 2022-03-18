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
	date StartReg, EndReg, EndSem;
};


struct Schoolyear
{
	Semester Sem[3];
	string NumOfYear = ""; 
	Class* CLass;
	Schoolyear* YearNext;
	int NumOfClass;
};



void FillPassword(string& password);

void InputUserAndPW(string& username, string& password);

void InputStaff(teacher*& Staff, int& NumOfStaff);

void InputStudents(Student*& St, int& NumOfStu);

int CheckLogin(string username, string password, Schoolyear*& YearCur, teacher* Staff, int NumOfStaff, Student* stu, int NumOfStu);

void ChangePassword(Schoolyear* YearCur, teacher* Staff, int x, int NumOfStaff);

void inputSchoolYear(Schoolyear* &YearCur);

void SchoolYearInfo(Schoolyear* YearCur);

