#include "Header.h"


void txtColor(int color) // khai bao bang mau
{
	HANDLE hConsoleColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

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
	txtColor(7);
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
		/*if (username[1] >= 48 && username[1] <= 57)
		{
			int x = ((int)username[0] - 48) * 10 + (int)username[1] - 48;
			while (YearCur != nullptr && x != ((((int)YearCur->NumOfYear[2]) - 48) * 10 + ((int)YearCur->NumOfYear[3] - 48)))
				YearCur = YearCur->YearNext;
			if (YearCur == nullptr) return 0;
			else
			{
				for (int i = 0; i < YearCur->NumOfClass; i++)
					for (int j = 0; j < YearCur->CLass[i].NumOfStudent; j++)
						if (username == YearCur->CLass[i].Stu[j].StudentID && YearCur->CLass[i].Stu[j].PassWord == password)
							return (i + 1) * 100 + j + 1;
				return 0;
			}
		}
		else return 0;*/
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

void ViewInfo(int x, Student* Stu, teacher* Staff)
{
	if (x < 100)
	{
		gotoxy(40, 13);
		cout << "Fullname: " << Staff[x - 1].Surname << " " << Staff[x - 1].Name;
		gotoxy(40, 14);
		cout << "Gender: " << Staff[x - 1].Gender;
		gotoxy(40, 15);
		cout << "Email: " << Staff[x - 1].Email << endl;
	}
	else
	{
		// getline(in, St[i].Surname, ',');
		// getline(in, St[i].Name, ',');
		// getline(in, St[i].Gender, ',');
		// getline(in, St[i].ID, ',');
		// getline(in, St[i].StudentID, ',');
		// getline(in, St[i].PassWord);
		gotoxy(40, 10);
		cout << "Fullname: " << Stu[x / 100 - 1].Surname << " " << Stu[x / 100 - 1].Name << endl;
		// gotoxy(40, 11);
		// cout << "Class: " << YearCur->CLass[x / 100 - 1].NameOfClass << endl;
		// gotoxy(40, 12);
		// cout << "Student ID: " << YearCur->CLass[x / 100 - 1].Stu[x % 100 - 1].StudentID << endl;
		// gotoxy(40, 13);
		// cout << "date of Birth: " << YearCur->CLass[x / 100 - 1].Stu[x % 100 - 1].DOB << endl;
		gotoxy(40, 14);
		cout << "Gender: " << Stu[x / 100 - 1].Gender << endl;
		gotoxy(40, 15);
		cout << "Social ID: " << Stu[x / 100 - 1].ID << endl;
		gotoxy(40, 16);
		cout << "Student ID: " << Stu[x / 100 - 1].StudentID << endl;
		gotoxy(40, 17);
		cout << "Password: " << Stu[x / 100 - 1].PassWord << endl;
	}
}
//gotoxy xong
void ChangePassword(Student* Stu, teacher* Staff, int x, int NumOfStaff, int NumOfStu)
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
			txtColor(4);
			cout << "Password does not match!";
			txtColor(7);
			password = "";
		}
		else break;
	}
	if (x < 100) Staff[x - 1].PassWord = password;
	else Stu[x / 100 - 1].PassWord = password;
	// YearCur->CLass[x / 100 - 1].Stu[i].PassWord = password; 
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
		// ofstream out(YearCur->CLass[x / 100 - 1].NameOfClass + ".csv", ios::trunc);
		// out << YearCur->CLass[x / 100 - 1].NumOfStudent << ",,,,,,," << endl;
		// for (int i = 0; i < YearCur->CLass[x / 100 - 1].NumOfStudent; i++)
		// {
		// 	out << YearCur->CLass[x / 100 - 1].Stu[i].Num << "," << YearCur->CLass[x / 100 - 1].Stu[i].StudentID << "," << YearCur->CLass[x / 100 - 1].Stu[i].Surname << ","
		// 		<< YearCur->CLass[x / 100 - 1].Stu[i].Name << "," << YearCur->CLass[x / 100 - 1].Stu[i].Gender << "," << YearCur->CLass[x / 100 - 1].Stu[i].DOB << ","
		// 		<< YearCur->CLass[x / 100 - 1].Stu[i].ID << "," << YearCur->CLass[x / 100 - 1].Stu[i].PassWord << endl;
		// }
		ofstream out("StudentData.csv", ios::trunc);
		// out << YearCur->CLass[x / 100 - 1].NumOfStudent << ",,,,,,," << endl;
		out << NumOfStu << ",,,,," << endl;
		for (int i = 0; i < NumOfStu; i++)
		{
			out << Stu[i].Surname << ","
				<< Stu[i].Name << "," << Stu[i].Gender << "," 
				<< Stu[i].ID << "," << Stu[i].StudentID << "," << Stu[i].PassWord << endl;
		}
	
	}
	gotoxy(51, 17);
	txtColor(2);
	cout << "Your password was changed successfully." << endl;
	txtColor(7);
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

void ViewCourse(Course* CourseHead, int& t, int& i)
{
	clear();
	int k = 1;
	int y = 11, a = 20;
	Course* Cur = CourseHead;
	gotoxy(8, 10);
	cout << "Course ID";
	gotoxy(a, 10);
	a = a + 30;
	cout << "Name of course";
	gotoxy(a, 10);
	a = a + 10;
	cout << "teacher";
	gotoxy(a, 10);
	a = a + 10;
	cout << "Credits";
	gotoxy(a, 10);
	a = a + 22;
	cout << "Number of Students";
	gotoxy(a, 10);
	cout << "Session";
	while (Cur)
	{
		int x = 20;
		gotoxy(6, y);
		cout << k;
		gotoxy(8, y);
		cout << Cur->CourseID;
		gotoxy(x, y);
		x = x + 30;
		cout << Cur->NameOfCourse;
		gotoxy(x, y);
		x = x + 13;
		cout << Cur->NameOfteacher;
		gotoxy(x, y);
		x = x + 14;
		cout << Cur->NumOfCredit;
		gotoxy(x, y);
		x = x + 15;
		cout << Cur->NumOfStu << "/" << 50;
		gotoxy(x, y);
		cout << "Thu " << Cur->Day1 << " Ca " << Cur->Session1 << " Thu " << Cur->Day2 << " Ca " << Cur->Session2;
		y = y + 1;
		Cur = Cur->pNext;
		k++;
	}
	t = y;
	i = k;
}

void UpdateCourse(Schoolyear* YearCur, int sem)
{
	Course* Cur = YearCur->Sem[sem].pCourse;
	int count = 1, t, option;
	ViewCourse(YearCur->Sem[sem].pCourse, t, count);
	t++;
	gotoxy(12, t);
	cout << "Enter the course you want to update:";
	Draw(t - 1);
	gotoxy(51, t);
	cin >> option;
	cin.ignore();
	Cur = YearCur->Sem[sem].pCourse;
	for (int i = 1; i < option; i++)
	{
		Cur = Cur->pNext;
	}
	clear();
	gotoxy(20, 13);
	cout << "You are choosing:" << Cur->NameOfCourse;
	gotoxy(20, 14);
	cout << "1. Name of teacher. ";
	gotoxy(20, 15);
	cout << "2. Number of Credits. ";
	gotoxy(20, 16);
	cout << "3. Present students enrolled. ";
	gotoxy(20, 17);
	cout << "4. Day 1. ";
	gotoxy(20, 18);
	cout << "5. Session 1. ";
	gotoxy(20, 19);
	cout << "6. Day 2. ";
	gotoxy(20, 20);
	cout << "7. Session 2. ";
	gotoxy(20, 21);
	cout << "Enter your option: ";
	cin >> option;
	cin.ignore();
	gotoxy(20, 22);
	switch (option)
	{
	case 1:
		cout << "Change the name of teacher: ";
		getline(cin, Cur->NameOfteacher);
		break;
	case 2:
		cout << "Change the number of credits: ";
		getline(cin, Cur->NumOfCredit);
		break;
	case 3:
		cout << "Change the student enrolled: ";
		cin >> Cur->NumOfStu;
		break;
	case 4:
		cout << "Change the day 1: ";
		getline(cin, Cur->Day1);
		break;
	case 5:
		cout << "Change the session 1: ";
		getline(cin, Cur->Session1);
		break;
	case 6:
		cout << "Change the day 2: ";
		getline(cin, Cur->Day2);
		break;
	case 7:
		cout << "Change the session 2: ";
		getline(cin, Cur->Session2);
		break;
	default:
		break;
	}
	txtColor(4);
	cout << "Update course successfully";
	txtColor(7);
}

void SaveInfoCourse(Schoolyear* YearCur, int sem)
{
	Course* Cur = YearCur->Sem[sem].pCourse;
	ofstream course;
	course.open(YearCur->NumOfYear + "_" + (char)(sem + 49) + ".csv", ios::trunc);
	while (Cur != nullptr)
	{
		course << Cur->NameOfteacher << "," << Cur->NumOfCredit << "," << Cur->NumOfStu << "," << Cur->Day1 << "," << Cur->Session1 << "," << Cur->Day2 << "," << Cur->Session2 << "\n";
		Cur = Cur->pNext;
	}
	course.close();
}

void DeleteCourse(Schoolyear*& YearCur, int sem)
{
	Course* Cur = YearCur->Sem[sem].pCourse;
	int count = 1, t, option;
	ViewCourse(YearCur->Sem[sem].pCourse, t, count);
	t++;
	gotoxy(12, t);
	cout << "Enter the course you want to update:";
	Draw(t - 1);
	gotoxy(51, t);
	cin >> option;
	cin.ignore();
	Cur = YearCur->Sem[sem].pCourse;
	if (option <= count)
	{
		if (option == 1)
		{
			YearCur->Sem[sem].pCourse = YearCur->Sem[sem].pCourse->pNext;
			delete Cur;
		}
		else
		{
			for (int i = 2; i < option; i++)
			{
				Cur = Cur->pNext;
			}

			Course* temp = Cur->pNext;
			Cur->pNext = Cur->pNext->pNext;
			delete temp;
			txtColor(2);
			gotoxy(51, t + 2);
			cout << "Delete course successfully.";
			txtColor(7);
		}
	}
	else
	{
		txtColor(4);
		gotoxy(51, t + 2);
		cout << "This course is not existed!";
		txtColor(7);
	}
}

void Now_real(date& Today)
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	Today.year = 1900 + ltm->tm_year;
	Today.month = 1 + ltm->tm_mon;
	Today.day = ltm->tm_mday;
}

void Now(date& Today)
{
	string date; 
	//01 2 34 5 6789
	cout << "Today date (dd/mm/yyyy): "; 
	cin >> date; 


	Today.year = (int)date[6] * 1000 + (int)date[7] * 100 + (int)date[8] * 10 + (int)date[9] - 53328; 
	Today.month = (int)date[3] * 10 + (int)date[4] - 528; 
	Today.day = (int)date[0] * 10 + date[1] - 528; 
}

bool CheckdateRegister(date Today, date StartReg, date EndReg)// tham chiếu yearcur là yearcur2 
{
	if (Today.year >= StartReg.year && Today.year <= EndReg.year)
		if (Today.month >= StartReg.month && Today.month <= EndReg.month)
			if (Today.day >= StartReg.day && Today.day <= EndReg.day)
				return true;
			else return false;
		else return false;
	else return false;
}

bool CheckdateEndSemester(date Today, date EndSem){



	if (Today.year == EndSem.year)
	{
		if (Today.month > EndSem.month)
			return true;
		else if (Today.month == EndSem.month)
			if (Today.day > EndSem.day)
				return true;
	}

	else if (Today.year > EndSem.year)
		return true;

	return false;
}

bool CheckImport(Schoolyear* YearCur, int x)
{
	if (!YearCur->CLass[x / 100 - 1].Stu[x % 100 - 1].Registered) return false;
	if (YearCur->CLass[x / 100 - 1].Stu[x % 100 - 1].Registered->Score.Final == "") return false;
	return true;
}

void CourseEnroll(Schoolyear* YearCur, Course* CourseHead, int x, int& NumOfOpt, string username)
{
	Schoolyear* yearTemp = YearCur;
	int m = 0, n = 0;  
	while(yearTemp->CLass[m].Stu[n].StudentID != username){
		n++; 
		if(yearTemp->CLass[m].NumOfStudent == n){
			n = 0; 
			m++; 
		}
		if(yearTemp->NumOfClass == m)
			yearTemp = yearTemp->YearNext; 
	}

	int opt;
	// int j = (x / 100) - 1;
	// int k = (x % 100) - 1;
	int j = m; 
	int k = n;
	Course* ListEnroll = YearCur->CLass[j].Stu[k].Registered;
	while (ListEnroll != nullptr && ListEnroll->pNext != nullptr)
	{
		ListEnroll = ListEnroll->pNext;
	}
	while (NumOfOpt != 5)
	{
	Enroll:
		Data* InfoCur = nullptr;
		int i = 1;
		Course* CourseCur = CourseHead;
		int t = 0;
		ViewCourse(CourseCur, t, i);
		t++;
		i--;
		gotoxy(30, t);
		cout << "Register(0.stop): ";
		Draw(t - 1);
		gotoxy(51, t);
		cin >> opt;

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
			if (opt == 0)return;
		}

		if (opt == 0) return;


		int count = 1;
		while (CourseCur != nullptr && count != opt)
		{

			CourseCur = CourseCur->pNext;
			count++;

		}

		if (CourseCur != nullptr)
		{
			Course* EnrollMove = YearCur->CLass[j].Stu[k].Registered;
			while (EnrollMove != nullptr)
			{
				if (EnrollMove->Day1 == CourseCur->Day1)
				{
					if (EnrollMove->Session1 == CourseCur->Session1)
					{
						gotoxy(51, t + 2);
						txtColor(4);
						cout << "Conflicted with another course. Register again: " << endl;
						txtColor(7);
						Back();
						goto Enroll;
					}
				}
				if (EnrollMove->Day2 == CourseCur->Day2)
				{
					if (EnrollMove->Session2 == CourseCur->Session2)
					{
						gotoxy(51, t + 2);
						txtColor(4);
						cout << "Conflicted with another course. Register again:" << endl;
						txtColor(7);
						Back();
						goto Enroll;
					}
				}

				EnrollMove = EnrollMove->pNext;

			}
			Data* InfoMove = CourseCur->DataOfStu;
			while (InfoMove != nullptr && InfoMove->StudentID != YearCur->CLass[j].Stu[k].StudentID)
			{
				InfoMove = InfoMove->pNext;
			}

			if (InfoMove == nullptr && EnrollMove == nullptr)
			{
				if (CourseCur->NumOfStu < CourseCur->MaxStu)
				{

					Data* temp = new Data;
					temp->j = j;
					temp->k = k;
					temp->StudentID = YearCur->CLass[j].Stu[k].StudentID;
					temp->Surname = YearCur->CLass[j].Stu[k].Surname;
					temp->Name = YearCur->CLass[j].Stu[k].Name;
					temp->pNext = nullptr;


					if (CourseCur->DataOfStu == nullptr || CourseCur->DataOfStu->StudentID > temp->StudentID)
					{
						temp->pNext = CourseCur->DataOfStu;
						CourseCur->DataOfStu = temp;
					}
					else
					{
						InfoCur = CourseCur->DataOfStu;

						while (InfoCur->pNext != nullptr && InfoCur->pNext->StudentID < temp->StudentID)
						{
							InfoCur = InfoCur->pNext;
						}


						temp->pNext = InfoCur->pNext;
						InfoCur->pNext = temp;
					}


					if (ListEnroll != nullptr)
					{
						ListEnroll->pNext = new Course;
						ListEnroll = ListEnroll->pNext;
					}

					else
					{

						YearCur->CLass[j].Stu[k].Registered = new Course;
						ListEnroll = YearCur->CLass[j].Stu[k].Registered;
					}

					ListEnroll->CourseID = CourseCur->CourseID;
					ListEnroll->NameOfCourse = CourseCur->NameOfCourse;
					ListEnroll->NameOfteacher = CourseCur->NameOfteacher;
					ListEnroll->NumOfCredit = CourseCur->NumOfCredit;
					ListEnroll->Day1 = CourseCur->Day1;
					ListEnroll->Session1 = CourseCur->Session1;
					ListEnroll->Day2 = CourseCur->Day2;
					ListEnroll->Session2 = CourseCur->Session2;

					NumOfOpt++;
					CourseCur->NumOfStu++;
					ListEnroll->NumOfStu = CourseCur->NumOfStu;

					ListEnroll->pNext = nullptr;

				}

				else
				{
					gotoxy(51, t + 2);
					txtColor(4);
					cout << "Course is full. Register again: " << endl;
					txtColor(7);
					Back();
					goto Enroll;
				}

			}
			else
			{
				gotoxy(51, t + 2);
				txtColor(4);
				cout << "You have registered this course. Register again: " << endl;
				txtColor(7);
				Back();
				goto Enroll;
			}

		}

	}
}

void ViewListEnrolled(Schoolyear* YearCur, int x, string username)
{
	clear();
	Schoolyear* yearTemp = YearCur;
	int m = 0, n = 0;  
	while(yearTemp->CLass[m].Stu[n].StudentID != username){
		n++; 
		if(yearTemp->CLass[m].NumOfStudent == n){
			n = 0; 
			m++; 
		}
		if(yearTemp->NumOfClass == m)
			yearTemp = yearTemp->YearNext; 
	}

	int curClass = m;
	int curID = n;
	int i = 1;
	Course* CurRegistered = YearCur->CLass[curClass].Stu[curID].Registered;
	if (CurRegistered == nullptr) cout << "No course registered ";
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
			cout << "Thu " << CurRegistered->Day1 << "Thoi gian: " << CurRegistered->Session1;
			y++;
			gotoxy(a, y);
			cout << "Thu " << CurRegistered->Day2 << "Thoi gian: " << CurRegistered->Session2;
			i++; y++;
			CurRegistered = CurRegistered->pNext;
		}
	}
}

void RemoveCourseEnrolled(Schoolyear* YearCur, Course* CourseHead, int x, string username)
{
	// if (x==0) return;
	string CourseID;
	// name, surname, StudentID, ClassID;
	int choice;
	// cout << "Enter student's surname: ";
	// getline(cin, surname);
	// cout << "Enter student's name: ";
	// getline(cin, name);
	// cout << "Enter student's id";
	// getline(cin, StudentID);
	// for (int i=0; i<YearCur->NumOfClass; i++){
	// 	for (int j=0; j<YearCur->CLass[i].NumOfStudent; j++){
	Schoolyear* yearTemp = YearCur;
	int m = 0, n = 0;  
	while(yearTemp->CLass[m].Stu[n].StudentID != username){
		n++; 
		if(yearTemp->CLass[m].NumOfStudent == n){
			n = 0; 
			m++; 
		}
		if(yearTemp->NumOfClass == m)
			yearTemp = yearTemp->YearNext; 
	}
	int i = m; 
	int j = n; 

	{
		cout << endl << "Please enter the course you want to remove " << endl;
		getline(cin, CourseID);
		Course *pCur=YearCur->CLass[i].Stu[j].Registered;
		while (pCur && pCur->CourseID != CourseID){
			pCur=pCur->pNext;
		}
		
		if (pCur){
			cout << endl << "Are you really sure you want to remove this course? (YES - 1, NO - 0): " ;
			cin >> choice;
			if (choice == 1){
				Course *tmp=pCur;
				pCur = pCur->pNext;
				delete tmp;
				// break;
			}
			
			else{
				cout << endl << "You didn't remove the enrolled course" << endl;
				return;
			}
		}
		else {
			cout << endl << "No courses found!!" << endl;
			return;
		}
	}	
	Course *CourseCur=CourseHead;
	while (CourseCur && CourseCur->CourseID!=CourseID){
		CourseCur=CourseCur->pNext;
	}
	
	if (CourseCur){
		Data *InfoCur=CourseCur->DataOfStu;
		// while (InfoCur && (InfoCur->StudentID!=StudentID || InfoCur->Name!=name || InfoCur->Surname!=surname)){
		// 	InfoCur=InfoCur->pNext;
		// }
		{
			Data *tmp=InfoCur;
			InfoCur=InfoCur->pNext;
			delete tmp;
			cout << "Remove from course successfully!!!" << endl;
		}
	
	}
}

void ViewListClasses(Schoolyear* YearCur)
{
	string year = "";
	gotoxy(10, 11);
	cout << "Enter the year you want to view class: ";
	Draw(10);
	gotoxy(51, 11);
	getline(cin, year);
	char keycap;

	while (YearCur != nullptr)
	{
		if (year == YearCur->NumOfYear)
		{
			for (int i = 0; i < YearCur->NumOfClass; i++)
			{
				gotoxy(51, i + 14);
				cout << i + 1 << "." << YearCur->CLass[i].NameOfClass;
			}

			break;
		}
		YearCur = YearCur->YearNext;
	}
	if (YearCur == nullptr)
	{
		txtColor(4);
		gotoxy(51, 13);
		cout << "The entered year is not available" << endl;
		txtColor(7);
	}

}

void ViewListStudentInClass(Schoolyear* YearCur)
{
	string NameClass = "";
	gotoxy(10, 10);
	cout << "Enter the name class you want to view: ";
	Draw(9);
	gotoxy(51, 10);
	getline(cin, NameClass);
	char keycap = 75;
	while (YearCur != nullptr)
	{
		for (int i = 0; i < YearCur->NumOfClass; i++)
		{
			if (NameClass == YearCur->CLass[i].NameOfClass)
			{
				while (keycap != 13)
				{
					if (keycap == 75)
					{
						clear();
						gotoxy(51, 9);
						cout << NameClass;
						for (int j = 0; j < YearCur->CLass[i].NumOfStudent / 2; j++)
						{
							gotoxy(15, j + 10);
							cout << YearCur->CLass[i].Stu[j].Num;
							gotoxy(19, j + 10);
							cout << YearCur->CLass[i].Stu[j].StudentID;
							gotoxy(30, j + 10);
							cout << YearCur->CLass[i].Stu[j].Surname;
							gotoxy(31 + YearCur->CLass[i].Stu[j].Surname.length(), j + 10);
							cout << YearCur->CLass[i].Stu[j].Name;
							gotoxy(57, j + 10);
							cout << YearCur->CLass[i].Stu[j].Gender;
							gotoxy(65, j + 10);
							cout << YearCur->CLass[i].Stu[j].DOB;
							gotoxy(79, j + 10);
							cout << YearCur->CLass[i].Stu[j].ID;

						}
						keycap = getch();
						if (keycap == -32) keycap = getch();
					}
					if (keycap == 77)
					{
						clear();
						gotoxy(51, 9);
						cout << NameClass;
						int j = YearCur->CLass[i].NumOfStudent / 2;
						int k = 0;

						while (j < YearCur->CLass[i].NumOfStudent)
						{
							gotoxy(15, k + 10);
							cout << YearCur->CLass[i].Stu[j].Num;
							gotoxy(19, k + 10);
							cout << YearCur->CLass[i].Stu[j].StudentID;
							gotoxy(30, k + 10);
							cout << YearCur->CLass[i].Stu[j].Surname;
							gotoxy(31 + YearCur->CLass[i].Stu[j].Surname.length(), k + 10);
							cout << YearCur->CLass[i].Stu[j].Name;
							gotoxy(57, k + 10);
							cout << YearCur->CLass[i].Stu[j].Gender;
							gotoxy(65, k + 10);
							cout << YearCur->CLass[i].Stu[j].DOB;
							gotoxy(79, k + 10);
							cout << YearCur->CLass[i].Stu[j].ID;
							j++;
							k++;
						}
						keycap = getch();
						if (keycap == -32) keycap = getch();
					}
				}
				return;
			}
		}
		YearCur = YearCur->YearNext;
	}
	if (YearCur == nullptr)
	{
		txtColor(4);
		gotoxy(51, 13);
		cout << "The entered name of is not available" << endl;
		txtColor(7);
	}
}

void ViewListStudentInCourse(Schoolyear* YearCur, int sem)
{
	string CourseID = "";
	gotoxy(12, 10);
	cout << "Enter the course ID you want to view:";
	Draw(9);
	gotoxy(51, 10);
	getline(cin, CourseID);
	Course* CourseCur = YearCur->Sem[sem].pCourse;
	while (CourseCur != nullptr)
	{
		if (CourseID == CourseCur->CourseID)
		{
			Data* Cur;
			char keycap = 75;
			while (keycap != 13)
			{
				Cur = CourseCur->DataOfStu;
				if (keycap == 75)
				{
					clear();
					int k = 1;
					gotoxy(40, 9);
					cout << "NUM STUDENT ID\tNAME";
					while (k <= CourseCur->NumOfStu / 2)
					{
						gotoxy(40, k + 10);
						cout << k << " " << Cur->StudentID << "\t" << Cur->Surname << " " << Cur->Name;
						Cur = Cur->pNext;
						k++;
					}
				}
				keycap = getch();
				if (keycap == -32) keycap = getch();
				if (keycap == 77)
				{
					clear();
					int k = CourseCur->NumOfStu / 2 + 1;
					gotoxy(40, 9);
					cout << "NUM STUDENT ID\tNAME";
					while (k <= CourseCur->NumOfStu)
					{
						gotoxy(40, k + 10 - CourseCur->NumOfStu / 2 - 1);
						cout << k << " " << Cur->StudentID << "\t" << Cur->Surname << " " << Cur->Name;
						Cur = Cur->pNext;
						k++;
					}
				}
				do {
					keycap = getch();
					if (keycap == -32) keycap = getch();
				} while (keycap != 75 && keycap != 13);
			}
			return;
		}
		CourseCur = CourseCur->pNext;
	}
	if (CourseCur == nullptr)
	{
		txtColor(4);
		gotoxy(51, 12);
		cout << "The entered course is not available" << endl;
		txtColor(7);
	}
}

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

	if (CourseCur != nullptr)
	{
		Data* InfoCur = CourseCur->DataOfStu;
		int i = 1;
		while (InfoCur != nullptr)
		{
			output << i << ',' << InfoCur->StudentID << ',' << InfoCur->Surname << ',' << InfoCur->Name << endl;
			InfoCur = InfoCur->pNext;
		}

		if (InfoCur == nullptr) cout << "Export successfully!";
		else cout << "Export fail";
	}

}

void LoadScoreboard(Course*& CourseHead, Schoolyear*& YearCur)
{	ifstream input;
	string CourseID;
	Course* CourseCur = CourseHead;
	Data* InfoCur = nullptr;
	cout << "Input course ID: ";
	getline(cin, CourseID);
	input.open(CourseID + ".csv", ifstream::in);
	if (!input.is_open())
	{
		cout << "Cannot open this file!";
	}
	else
	{
		while (!input.eof())
		{
			while (CourseCur != nullptr && CourseCur->CourseID != CourseID)
			{
				CourseCur = CourseCur->pNext;
			}

			InfoCur = CourseCur->DataOfStu;

			if (InfoCur == nullptr) return;
			while (InfoCur != nullptr)
			{
				input.ignore(1000, ',');
				input.ignore(1000, ',');
				input.ignore(1000, ',');
				input.ignore(1000, ',');
				getline(input, InfoCur->Score.Total, ',');
				getline(input, InfoCur->Score.Final, ',');
				getline(input, InfoCur->Score.Midterm, ',');
				getline(input, InfoCur->Score.Other);


				Course* EnrollList = YearCur->CLass[InfoCur->j].Stu[InfoCur->k].Registered;

				while (EnrollList != nullptr && EnrollList->CourseID != CourseCur->CourseID)
				{
					EnrollList = EnrollList->pNext;
				}

				if (EnrollList != nullptr)
				{
					EnrollList->Score.Total = InfoCur->Score.Total;
					EnrollList->Score.Final = InfoCur->Score.Final;
					EnrollList->Score.Midterm = InfoCur->Score.Midterm;
					EnrollList->Score.Other = InfoCur->Score.Other;
				}

				InfoCur = InfoCur->pNext;

			}
			if (InfoCur == nullptr) cout << "Export successfully";
			else cout << "Export fail";
		}

	}
	input.close();
}

void ViewScoreboardCourse(Course* CourseHead)
{
	string NameOfCourse;
	Course* CourseCur = CourseHead;
	Data* InfoCur = nullptr;
	cout << "Input name of course: ";
	cin.ignore();
	getline(cin, NameOfCourse);
	while (CourseCur != nullptr && CourseCur->NameOfCourse != NameOfCourse)
	{
		CourseCur = CourseCur->pNext;
	}
	InfoCur = CourseCur->DataOfStu;
	if (InfoCur == nullptr) return;
	int i = 1;
	cout << left << setw(4) << "No" << left << setw(12) << "StudentID" << left << setw(25) << "Surname" << left << setw(10) << "Name" << right << setw(12) << "Total Mark" << right << setw(12) << "Final Mark" << right << setw(14) << "Midterm Mark" << right << setw(12) << "Other Mark" << endl;
	while (InfoCur != nullptr)
	{

		cout << left << setw(4) << i << left << setw(12) << InfoCur->StudentID << left << setw(25) << InfoCur->Surname << left << setw(10) << InfoCur->Name << right << setw(12) << InfoCur->Score.Total << right << setw(12) << InfoCur->Score.Final << right << setw(14) << InfoCur->Score.Midterm << right << setw(12) << InfoCur->Score.Other << endl;
		InfoCur = InfoCur->pNext;
		i++;
	}

}

void ViewScoreboardClass(Schoolyear* YearCur, int x)
{
	string NameOfCourse;
	int j = (x / 100) - 1;
	cout << "Input name of course: ";
	cin.ignore();
	getline(cin, NameOfCourse);


	cout << left << setw(4) << "Num" << left << setw(12) << "Student ID" << left << setw(25) << "Surname" << left << setw(10) << "Name" << right << setw(12) << "GPA Total" << right << setw(12) << "GPA Final" << endl;
	for (int i = 0; i < YearCur->CLass[x].NumOfStudent; i++)
	{
		Course* EnrollList = YearCur->CLass[j].Stu[i].Registered;

		while (EnrollList != nullptr && EnrollList->NameOfCourse != NameOfCourse)
		{
			EnrollList = EnrollList->pNext;
		}

		if (EnrollList != nullptr)
			cout << left << setw(4) << i + 1 << left << setw(12) << YearCur->CLass[j].Stu[i].StudentID << left << setw(25) << YearCur->CLass[j].Stu[i].Surname << left << setw(10) << YearCur->CLass[j].Stu[i].Name << right << setw(12) << EnrollList->Score.Total << right << setw(12) << EnrollList->Score.Final << endl;

	}


}

void ViewScoreboardStu(Schoolyear* YearCur, int x)
{
	int j = (x / 100) - 1;
	int k = (x % 100) - 1;
	Course* EnrollList = YearCur->CLass[j].Stu[k].Registered;
	cout << left << setw(4) << "No" << left << setw(12) << "StudentID" << left << setw(25) << "Surname" << left << setw(10) << "Name" << right << setw(12) << "Total Mark" << right << setw(12) << "Final Mark" << right << setw(14) << "Midterm Mark" << right << setw(12) << "Other Mark" << endl;
	while (EnrollList != nullptr)
	{
		cout << left << setw(4) << YearCur->CLass[j].Stu[k].Num << left << setw(12) << YearCur->CLass[j].Stu[k].StudentID << left << setw(25) << YearCur->CLass[j].Stu[k].Surname << left << setw(10) << YearCur->CLass[j].Stu[k].Name << right << setw(12) << EnrollList->Score.Total << right << setw(12) << EnrollList->Score.Final << right << setw(14) << EnrollList->Score.Midterm << right << setw(12) << EnrollList->Score.Other << endl;
		EnrollList = EnrollList->pNext;
	}
}

void UpdateStudentResult(Schoolyear*& YearCur, Course*& CourseHead)
{
	int opt;
	string StudentID;
	string NameOfCourse;

	cout << "Input Name of Course: ";
	cin.ignore();
	getline(cin, NameOfCourse);

	cout << "Input Student ID: ";
	cin.ignore();
	getline(cin, StudentID);
	do
	{


		cout << "UPdate STUDENT RESULT" << endl;
		cout << "1.Other Mark" << endl;
		cout << "2.Midterm Mark" << endl;
		cout << "3.Final Mark" << endl;
		cout << "4.Total Mark" << endl;
		cout << "0 to stop." << endl;
		cout << "Input your option: ";
		cin >> opt;

		Course* CourseCur = CourseHead;
		Data* InfoCur = nullptr;
		Course* EnrollList = nullptr;
		while (CourseCur != nullptr && CourseCur->NameOfCourse != NameOfCourse)
		{
			CourseCur = CourseCur->pNext;
		}
		if (CourseCur != nullptr)
		{
			InfoCur = CourseCur->DataOfStu;
			while (InfoCur != nullptr && InfoCur->StudentID != StudentID)
			{
				InfoCur = InfoCur->pNext;
			}

			EnrollList = YearCur->CLass[InfoCur->j].Stu[InfoCur->k].Registered;
			while (EnrollList != nullptr && EnrollList->NameOfCourse != NameOfCourse)
			{
				EnrollList = EnrollList->pNext;
			}
		}

		string change;
		switch (opt)
		{
		case 1:


			cout << "Input your change: ";
			cin >> change;
			if (InfoCur != nullptr && EnrollList != nullptr)
			{
				InfoCur->Score.Other = change;
				EnrollList->Score.Other = change;
			}
			break;
		case 2:

			cout << "Input your change: ";
			cin >> change;
			if (InfoCur != nullptr && EnrollList != nullptr)
			{
				InfoCur->Score.Midterm = change;
				EnrollList->Score.Midterm = change;
			}
			break;
		case 3:

			cout << "Input your change: ";
			cin >> change;
			if (InfoCur != nullptr && EnrollList != nullptr)
			{
				InfoCur->Score.Final = change;
				EnrollList->Score.Final = change;
			}
			break;
		case 4:

			cout << "Input your change: ";
			cin >> change;
			if (InfoCur != nullptr && EnrollList != nullptr)
			{
				InfoCur->Score.Total = change;
				EnrollList->Score.Total = change;
			}
			break;


		}
	} while (opt != 0);
}

