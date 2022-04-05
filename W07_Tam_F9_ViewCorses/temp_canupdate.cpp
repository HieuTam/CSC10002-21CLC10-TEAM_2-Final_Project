#include "header.h"

void ViewCourse(Course* CourseHead, int& t, int& i)
{
	int k = 1;
	int y = 11, a = 20;
	Course* Cur = CourseHead;
	cout << "Course ID";
	cout << "Name of course";
	cout << "teacher";
	cout << "Credits";
	cout << "Number of Students";
	cout << "Session";
	while (Cur)
	{
		int x = 20;
		cout << k;
		cout << Cur->CourseID;
		cout << Cur->NameOfCourse;
		cout << Cur->NameOfteacher;
		cout << Cur->NumOfCredit;
		cout << Cur->NumOfStu << "/" << 50;
		cout << "Thu " << Cur->Day1 << " Ca " << Cur->Session1 << " Thu " << Cur->Day2 << " Ca " << Cur->Session2;
		y = y + 1;
		Cur = Cur->pNext;
		k++;
	}
	t = y;
	i = k;
}