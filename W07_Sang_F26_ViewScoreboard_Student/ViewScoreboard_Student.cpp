#include "Header_Test2.h"
void ViewScoreboardForStudent(Schoolyear* YearCur, int x)
{
	clear();
	int CurClass = (x / 100) + 1;
	int CurID = (x % 100) - 1;
	Course* Cur = YearCur->CLass[CurClass].Stu[CurID].Registered;
	gotoxy(1, 2);
	cout << "Scoreboard of ";
	cout << YearCur->CLass[CurClass].Stu[CurID].Name << " - " << YearCur->CLass[CurClass].Stu[CurID].ID << endl;
	int i = 0, l = 4;
	gotoxy(1, l);
	cout << "#";
	gotoxy(4, l);
	cout << "Course ID";
	gotoxy(15, l);
	cout << "Name of Course";
	gotoxy(40, l);
	cout << "Credits";
	gotoxy(50, l);
	cout << "Midterm";
	gotoxy(60, l);
	cout << "Final term";
	gotoxy(73, l);
	cout << "Other";
	gotoxy(80, l);
	cout << "Total";
	gotoxy(88, l);
	cout << "GPA";
	while (Cur)
	{
		i++; l++;
		gotoxy(1, l);
		cout << i;
		gotoxy(4, l);
		cout << Cur->CourseID;
		gotoxy(15, l);
		cout << Cur->NameOfCourse;
		gotoxy(40, l);
		cout << Cur->NumOfCredit;
		gotoxy(50, l);
		cout << Cur->Score.Midterm;
		gotoxy(60, l);
		cout << Cur->Score.Final;
		gotoxy(73, l);
		cout << Cur->Score.Other;
		gotoxy(80, l);
		cout << Cur->Score.Total;
		gotoxy(88, l);
		cout << "GPA";//no GPA :>
		Cur = Cur->pNext;
	}

}
