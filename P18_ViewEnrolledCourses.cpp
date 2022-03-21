void ViewListEnrolled(Schoolyear* YearCur, int x)
{
	clear();
	int curClass = x / 100 - 1;
	int curID = x % 100 - 1;
	int i = 1;
	Course* CurRegistered = YearCur->CLass[curClass].Stu[curID].Registered;
	if (CurRegistered==nullptr) cout << "No course registered ";
	else
	{
		int y = 10;
		gotoxy(1, y);
		cout << '#';
		gotoxy(7, y);
		cout << "Course ID";
		gotoxy(26, y);
		cout << "Name of course";
		gotoxy(54, y);
		cout << "Teacher";
		gotoxy(69, y);
		cout << "Credits";
		gotoxy(81, y);
		cout << "Session";

		while (CurRegistered)
		{
			int a = 1; y++;
			gotoxy(a, y);
			cout << i;
			a += 7;
			gotoxy(a, y);
			a += 12;
			cout << CurRegistered->CourseID;
			gotoxy(a, y);
			a = a + 30;
			cout << CurRegistered->NameOfCourse;
			gotoxy(a, y);
			a = a + 10;
			cout << CurRegistered->NameOfteacher;
			gotoxy(a, y);
			a = a + 22;
			cout << CurRegistered->NumOfCredit;
			gotoxy(a, y);
			cout << "Thu " << CurRegistered->Day1 << "Thoi gian: " << CurRegistered->Session1 << endl;
			cout << "Thu " << CurRegistered->Day2 << "Thoi gian: " << CurRegistered->Session2;
			i++; y++;
			CurRegistered = CurRegistered->pNext;
		}
	}
}
