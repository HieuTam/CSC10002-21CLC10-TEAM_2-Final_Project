#include "Header_Test2.h"
int main()
{
	Student* Stu = nullptr;
	int temp = 0, n = 0;
	Schoolyear* YearHead = nullptr, * YearCur1 = nullptr, * YearCur2 = nullptr;
	Course* CourseHead = nullptr;
	string username, password;
	int NumOfStaff = 0, sem = 0, NumOfStu = 0;
	AddNewYear(YearHead);
	cout << YearHead->NumOfYear;
	cout << "Enter 0 to stop input course: ";
	cin >> temp;
	while (temp)
	{
		AddNewCourse(CourseHead);
		cout << "\nEnter 0 to stop input course: ";
		cin >> temp;
	}
	InputStudents(Stu, NumOfStu);
	clear();
	InputUserAndPW(username, password);
	int x = CheckLogin(username, password, YearHead, Stu, NumOfStu);
	cout << x;
	int choice=0;
	cout << "\n1.Load scb";
	cout << "\n2.Enroll";
	cout << "\n3.View Enroll";
	cout << "\n4.View scb";
	if (x != 0)
	cin >> choice;
	while (choice)
	{
		if (choice == 1)
		{
			for (int i=0;i<YearHead->NumOfClass;i++)
			LoadScoreboard(CourseHead, YearHead);
			ViewScoreboardForStudent(YearHead, x);
		}
		else if (choice == 2)
		{
			CourseEnroll(YearHead, CourseHead, x, n);
		}
		else if (choice==3)
		{
			ViewListEnrolled(YearHead, x);
		}
		cin >> choice;
	}
	delete[]Stu;
	delete[]YearHead;
	return 0;
}