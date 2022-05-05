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
