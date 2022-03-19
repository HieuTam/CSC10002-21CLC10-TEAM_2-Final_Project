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






