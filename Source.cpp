#include "Header.h"




void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}


void Draw(int x) // ham dung de ke o vuong phan dang nhap
{
	gotoxy(49, x);
	cout << char(218);
	for (int i = 0; i < 30; i++)
		cout << char(196);
	cout << char(191);
	gotoxy(49, x + 1); cout << char(179);
	gotoxy(80, x + 1); cout << char(179);
	gotoxy(49, x + 2);
	cout << char(192);
	for (int i = 0; i < 30; i++)
		cout << char(196);
	cout << char(217);
}

void clear()
{
	for (int i = 2; i < 118; ++i)    // lap day khung menu = khoang trang
		for (int j = 6; j < 39; ++j)
		{
			gotoxy(i, j);
			cout << char(32);
		}
}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}

void Back() // nut tro lai
{
	gotoxy(4, 6);
	cout << "Back";
	char keycap = 0;
	while (keycap != 13)
	{
		ShowCur(0);
		keycap = getch();
	}
	ShowCur(1);
}

void DisableCtrButton(bool Max)
{
	HWND hWnd = GetConsoleWindow();
	HMENU hMenu = GetSystemMenu(hWnd, false);

	if (Max == 1)
	{
		DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
	}
}

void DisableResizeWindow()
{
	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

void SetWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT WindowSize;
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Right = width;
	WindowSize.Bottom = height;

	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void SetScreenBufferSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD NewSize;
	NewSize.X = width;
	NewSize.Y = height;

	SetConsoleScreenBufferSize(hStdout, NewSize);
}

void FillPassword(string& password, int k)
{
	char keycap;
	int i = 51;
	while (true)
	{
		gotoxy(51, k);
		for (int i = 0; i < password.length(); i++) cout << "*";
		gotoxy(i, k);
		keycap = getch();
		if (keycap == 13) break;
		if (keycap == -32)
		{
			keycap = getch();
			if (keycap == 75 && i > 51) i--;
			else if (keycap == 77 && i - 51 < password.length()) i++;
		}
		else if (keycap == 8)
		{
			if (i == 51) continue;
			gotoxy(51 + password.length() - 1, k);
			cout << " ";
			password.erase(i - 52, 1);
			i--;
		}
		else
		{
			cout << keycap;
			password += keycap;
			int k = i - 51;
			while (k != password.length())
			{
				swap(password[k], password[password.length() - 1]);
				k++;
			}
			i++;
		}
	}
}

void InputUserAndPW(string& username, string& password)
{
	gotoxy(38, 12); cout << "Username:";
	gotoxy(38, 15); cout << "Password:";
	Draw(11);
	Draw(14);
	gotoxy(51, 12);
	getline(cin, username);
	FillPassword(password, 15);

}

<<<<<<< HEAD

=======
>>>>>>> 98119b95eaaf68f1acabc7c3febe4c0c625f68ff
int CheckLogin(string username, string password, Schoolyear*& YearCur, teacher* Staff, int NumOfStaff, Student* stu, int NumOfStu)
{ // ham kiem tra phan dang nhap
	if (username[0] >= 'a' && username[0] <= 'z')
	{
		int i = 0;
		for (i; i < NumOfStaff; i++)
		{
			if (username == Staff[i].Account && password == Staff[i].PassWord)
				return i + 1;
		}
		return 0;
	}
	else if (username[0] >= 'A' && username[0] <= 'Z')
		return 0; //Vì username mình cấp không có chữ in hoa
	else if (username[0] >= 48 && username[0] <= 57 && username.length() == 8)
	{
		int i = 0;
		for (i; i < NumOfStu; i++)
		{
			if (username == stu[i].StudentID && password == stu[i].PassWord)
				return (i + 1)*100;
		}
		return 0;
	}
	else return 0;
}

void InputStaff(teacher*& Staff, int& NumOfStaff)
{
	ifstream in("StaffData.csv");
	string temp;
	getline(in, temp, ',');
	NumOfStaff = stoi(temp);
	Staff = new teacher[stoi(temp)];
	getline(in, temp);
	for (int i = 0; i < NumOfStaff; i++)
	{
		getline(in, Staff[i].Surname, ',');
		getline(in, Staff[i].Name, ',');
		getline(in, Staff[i].Gender, ',');
		getline(in, Staff[i].Email, ',');
		getline(in, Staff[i].Account, ',');
		getline(in, Staff[i].PassWord);
	}

}
void InputStudents(Student*& St, int& NumOfStu)
{
	ifstream in("StudentData.csv");
	string temp;
	getline(in, temp, ',');
	NumOfStu = stoi(temp);
	St = new Student[stoi(temp)];
	getline(in, temp);
	for (int i = 0; i < NumOfStu; i++)
	{
		getline(in, St[i].Surname, ',');
		getline(in, St[i].Name, ',');
		getline(in, St[i].Gender, ',');
		getline(in, St[i].ID, ',');
		getline(in, St[i].StudentID, ',');
		getline(in, St[i].PassWord);
	}

}

<<<<<<< HEAD

=======
<<<<<<< HEAD







=======
//gotoxy xong
>>>>>>> 98119b95eaaf68f1acabc7c3febe4c0c625f68ff
void ChangePassword(Schoolyear* YearCur, teacher* Staff, int x, int NumOfStaff)
{
	string password;
	while (true)
	{
		clear();
		gotoxy(24, 12); cout << "Enter your new password:";
		gotoxy(22, 15); cout << "Reenter your new password:";
		Draw(11);
		Draw(14);
		FillPassword(password, 12);
		string temp;
		FillPassword(temp, 15);
		if (temp != password)
		{
			gotoxy(51, 17);
			cout << "Password does not match!";
			password = "";
		}
		else break;
	}
	if (x < 100) Staff[x - 1].PassWord = password;
	else YearCur->CLass[x / 100 - 1].Stu[x % 100 - 1].PassWord = password;
	if (x < 100)
	{
		ofstream out("StaffData.csv", ios::trunc);
		out << NumOfStaff << ",,,,," << endl;
		for (int i = 0; i < NumOfStaff; i++)
		{
			out << Staff[i].Surname << "," << Staff[i].Name << "," << Staff[i].Gender << "," << Staff[i].Email << "," << Staff[i].Account << "," << Staff[i].PassWord << endl;
		}
	}
	else
	{
		ofstream out(YearCur->CLass[x / 100 - 1].NameOfClass + ".csv", ios::trunc);
		out << YearCur->CLass[x / 100 - 1].NumOfStudent << ",,,,,,," << endl;
		for (int i = 0; i < YearCur->CLass[x / 100 - 1].NumOfStudent; i++)
		{
			out << YearCur->CLass[x / 100 - 1].Stu[i].Num << "," << YearCur->CLass[x / 100 - 1].Stu[i].StudentID << "," << YearCur->CLass[x / 100 - 1].Stu[i].Surname << ","
				<< YearCur->CLass[x / 100 - 1].Stu[i].Name << "," << YearCur->CLass[x / 100 - 1].Stu[i].Gender << "," << YearCur->CLass[x / 100 - 1].Stu[i].DOB << ","
				<< YearCur->CLass[x / 100 - 1].Stu[i].ID << "," << YearCur->CLass[x / 100 - 1].Stu[i].PassWord << endl;
		}
	}
	gotoxy(51, 17);
}
<<<<<<< HEAD

	void AddNewYear(Schoolyear*& NewYear)
{
	if (!NewYear) NewYear = new Schoolyear;
	gotoxy(30, 12);
	cout << "Input school year: ";
	Draw(11);
	gotoxy(51, 12);
	getline(cin, NewYear->NumOfYear);
	gotoxy(24, 15);
	cout << "Input number of classes: ";
	Draw(14);
	gotoxy(51, 15);
	cin >> NewYear->NumOfClass;
	cin.ignore();
	NewYear->CLass = new Class[NewYear->NumOfClass];
	for (int i = 0; i < NewYear->NumOfClass; i++)
	{
		while (true)
		{
			clear();
			gotoxy(24, 12);
			cout << "Input name of the class: ";
			Draw(11);
			gotoxy(51, 12);
			getline(cin, NewYear->CLass[i].NameOfClass);
			ifstream in(NewYear->CLass[i].NameOfClass + ".csv");
			if (in.is_open()) break;
			else
			{
				txtColor(4);
				gotoxy(51, 14);
				cout << "Can not open files to input data!!!";
				txtColor(7);
			}
		}
		string temp;
		ifstream in(NewYear->CLass[i].NameOfClass + ".csv");
		getline(in, temp, ',');
		NewYear->CLass[i].NumOfStudent = stoi(temp);
		NewYear->CLass[i].Stu = new Student[stoi(temp)];
		getline(in, temp);
		for (int j = 0; j < NewYear->CLass[i].NumOfStudent; j++)
		{
			getline(in, NewYear->CLass[i].Stu[j].Num, ',');
			getline(in, NewYear->CLass[i].Stu[j].StudentID, ',');
			getline(in, NewYear->CLass[i].Stu[j].Surname, ',');
			getline(in, NewYear->CLass[i].Stu[j].Name, ',');
			getline(in, NewYear->CLass[i].Stu[j].Gender, ',');
			getline(in, NewYear->CLass[i].Stu[j].DOB, ',');
			getline(in, NewYear->CLass[i].Stu[j].ID, ',');
			getline(in, NewYear->CLass[i].Stu[j].PassWord);
			NewYear->CLass[i].Stu[j].Registered = nullptr;
		}
		txtColor(2);
		gotoxy(51, 14);
		cout << "Input data of class " << NewYear->CLass[i].NameOfClass << " successfully" << endl;
		txtColor(7);
	}
	NewYear->YearNext = nullptr;
}
void AddNewSemester(Schoolyear*& YearCur, int& x)
{
	string temp;
	gotoxy(30, 10);
	cout << "Input school year: ";
	Draw(9);
	gotoxy(51, 10);
	getline(cin, temp);
	while (YearCur && temp != YearCur->NumOfYear)
	{
		YearCur = YearCur->YearNext;
	}
	if (!YearCur)
	{
		txtColor(4);
		gotoxy(51, 12);
		cout << "This year is not valid." << endl;
		txtColor(7);
		return;
	}
	gotoxy(33, 13);
	cout << "Input semester: ";
	Draw(12);
	gotoxy(51, 13);
	cin >> x;
	cin.ignore();
	x = x - 1;
	gotoxy(51, 15);
	cout << "The dates have form dd/mm/yyyy." << endl;
	gotoxy(14, 17);
	cout << "Input start date of this semester: ";
	Draw(16);
	gotoxy(51, 17);
	getline(cin, YearCur->Sem[x].StartSem);
	gotoxy(16, 20);
	cout << "Input end date of this semester: ";
	Draw(19);
	gotoxy(51, 20);
	getline(cin, temp);
	YearCur->Sem[x].EndSem.day = (int)temp[0] * 10 + (int)temp[1] - 528;
	YearCur->Sem[x].EndSem.month = (int)temp[3] * 10 + (int)temp[4] - 528;
	YearCur->Sem[x].EndSem.year = (int)temp[6] * 1000 + (int)temp[7] * 100 + (int)temp[8] * 10 + (int)temp[9] - 53328;
	gotoxy(8, 23);
	cout << "Input the date start to register course: ";
	Draw(22);
	gotoxy(51, 23);
	getline(cin, temp);
	YearCur->Sem[x].StartReg.day = (int)temp[0] * 10 + (int)temp[1] - 528;
	YearCur->Sem[x].StartReg.month = (int)temp[3] * 10 + (int)temp[4] - 528;
	YearCur->Sem[x].StartReg.year = (int)temp[6] * 1000 + (int)temp[7] * 100 + (int)temp[8] * 10 + (int)temp[9] - 53328;
	gotoxy(10, 26);
	cout << "Input the date end to register course: ";
	Draw(25);
	gotoxy(51, 26);
	getline(cin, temp);
	YearCur->Sem[x].EndReg.day = (int)temp[0] * 10 + (int)temp[1] - 528;
	YearCur->Sem[x].EndReg.month = (int)temp[3] * 10 + (int)temp[4] - 528;
	YearCur->Sem[x].EndReg.year = (int)temp[6] * 1000 + (int)temp[7] * 100 + (int)temp[8] * 10 + (int)temp[9] - 53328;
	ifstream in(YearCur->NumOfYear + "_" + to_string(x + 1) + ".csv");
	if (!in.is_open())
	{
		gotoxy(50, 28);
		txtColor(4);
		cout << "Input fail.";
		txtColor(7);
	}
	else
	{
		Course* Cur = nullptr;
		while (!in.eof())
		{
			if (!YearCur->Sem[x].pCourse)
			{
				YearCur->Sem[x].pCourse = new Course;
				Cur = YearCur->Sem[x].pCourse;
			}
			else
			{
				Cur->pNext = new Course;
				Cur = Cur->pNext;
			}
			getline(in, Cur->CourseID, ',');
			getline(in, Cur->NameOfCourse, ',');
			getline(in, Cur->NameOfteacher, ',');
			getline(in, Cur->NumOfCredit, ',');
			getline(in, Cur->Day1, ',');
			getline(in, Cur->Session1, ',');
			getline(in, Cur->Day2, ',');
			getline(in, Cur->Session2);
			Cur->NumOfStu = 0;
			Cur->pNext = nullptr;
		}
		txtColor(2);
		gotoxy(50, 28);
		cout << "Input successfully.";
		txtColor(7);
	}

}
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






=======
void ExportListStudentCourse(Course* CourseHead)
{
	string CourseID;
	ofstream output;
	Course* CourseCur = CourseHead;
	cout << "Input course ID: ";
	getline(cin, CourseID);
	output.open(CourseID + ".csv", ofstream::out);
	while (CourseCur != nullptr && CourseCur->CourseID != CourseID)
	{
		CourseCur = CourseCur->pNext;
	}
}
>>>>>>> 3fc58b20fa6f8cf1c607a935dfb0a7ad8eb1f370
>>>>>>> 98119b95eaaf68f1acabc7c3febe4c0c625f68ff
