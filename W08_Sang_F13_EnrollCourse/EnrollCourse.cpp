#include "Header_Test2.h"
void EnrollCourse (Schoolyear* YearCur, Course* CourseHead, int x, int& NumOfOpt)//pass yearCur->Semester[curSemester].pCourse to CourseHead
{
	int CurID = (x / 100)-1;
	int CurClass = (x % 100)-1;
	Data* temp = nullptr, *Student = nullptr,* CourseInfo=nullptr;
	Course* EnrollCourse = nullptr,*CurCourse=nullptr;
	while (NumOfOpt < 5)
	{
	Enrolling:
		int t = 0, i = 1, opt = 0;
		CurCourse = CourseHead;
		ViewCourse(CurCourse, t, i);
		t++; i--;
		gotoxy(30, t);
		cout << "Register(Enter 0 to stop): ";
		Draw(t - 1);
		gotoxy(51, t);
		cin >> opt;
		if (opt == 0) return;
		while (opt > i || opt < 0)
		{
			txtColor(2);
			gotoxy(25, t);
			cout << "Error. Register again: ";
			txtColor(7);
			Draw(t - 1);
			gotoxy(51, t);
			cout << "     ";
			gotoxy(51, t);
			cin >> opt;
		}
		int count = 1;
		while (CurCourse && count < opt)
		{
			CurCourse = CurCourse->pNext;
			count++;
		}
		if (CurCourse)
		{
			//check if conflicted with other enrolled course
			EnrollCourse = YearCur->CLass[CurClass].Stu[CurID].Registered;
			while (EnrollCourse)
			{
				if (EnrollCourse->Day1==CurCourse->Day1)
					if (EnrollCourse->Session1 == CurCourse->Session1)
					{
						gotoxy(51, t + 2);
						txtColor(4);
						cout << "Conflicted with "<<EnrollCourse->CourseID<<" - "<<EnrollCourse->NameOfCourse<<".Register again : " << endl;
						txtColor(7);
						Back();
						goto Enrolling;
					}
				if (EnrollCourse->Day2 == CurCourse->Day2)
					if (EnrollCourse->Session2 == CurCourse->Session2)
					{
						gotoxy(51, t + 2);
						txtColor(4);
						cout << "Conflicted with " << EnrollCourse->CourseID << " - " << EnrollCourse->NameOfCourse << ".Register again : " << endl;
						txtColor(7);
						Back();
						goto Enrolling;
					}
				EnrollCourse = EnrollCourse->pNext;
			}
			//Check if already registered
			Student = CurCourse->DataOfStu;
			while (Student && Student->StudentID != YearCur->CLass[CurClass].Stu[CurID].StudentID)
			{
				Student = Student->pNext;
			}
			if (Student == nullptr)//haven't registered
			{
				if (CurCourse->MaxStu < CurCourse->NumOfStu)//if course still has slots
				{
					temp = new Data;
					temp->StuClass = CurClass;
					temp->IDInClass = CurID;
					temp->StudentID = YearCur->CLass[CurClass].Stu[CurID].StudentID;
					temp->Surname = YearCur->CLass[CurClass].Stu[CurID].Surname;
					temp->Name = YearCur->CLass[CurClass].Stu[CurID].Name;
				}
				else
				{
					gotoxy(51, t + 2);
					txtColor(4);
					cout << "Course is full. Register again: " << endl;
					txtColor(7);
					Back();
					goto Enrolling;
				}
			}
			else
			{
				gotoxy(51, t + 2);
				txtColor(4);
				cout << "You have registered this course. Register again: " << endl;
				txtColor(7);
				Back();
				goto Enrolling;
			}
			if (CurCourse->DataOfStu==nullptr||CurCourse->DataOfStu->StudentID > temp->StudentID)//sorting in first
			{
				temp->pNext = CurCourse->DataOfStu;
				CurCourse->DataOfStu = temp;
			}
			else
			{
				CourseInfo = CurCourse->DataOfStu;
				while (CourseInfo->pNext && CourseInfo->pNext->StudentID < temp->StudentID)
					CourseInfo = CourseInfo->pNext;
				temp->pNext = CourseInfo->pNext;
				CourseInfo->pNext = temp;
			}
			EnrollCourse = YearCur->CLass[CurClass].Stu[CurID].Registered;
			if (EnrollCourse == nullptr)
			{
				YearCur->CLass[CurClass].Stu[CurID].Registered = new Course;
				EnrollCourse = YearCur->CLass[CurClass].Stu[CurID].Registered;
			}
			else
			{
				while (EnrollCourse->pNext)
					EnrollCourse = EnrollCourse->pNext;
				EnrollCourse->pNext = new Course;
				EnrollCourse = EnrollCourse->pNext;
			}
			EnrollCourse->CourseID = CurCourse->CourseID;
			EnrollCourse->NameOfCourse = CurCourse->NameOfCourse;
			EnrollCourse->NameOfteacher = CurCourse->NameOfteacher;
			EnrollCourse->NumOfCredit = CurCourse->NumOfCredit;
			EnrollCourse->Day1 = CurCourse->Day1;
			EnrollCourse->Session1 = CurCourse->Session1;
			EnrollCourse->Day2 = CurCourse->Day2;
			EnrollCourse->Session2 = CurCourse->Session2;

			NumOfOpt++;
			CurCourse->NumOfStu++;
			EnrollCourse->NumOfStu = CurCourse->NumOfStu;
		}
	}
}