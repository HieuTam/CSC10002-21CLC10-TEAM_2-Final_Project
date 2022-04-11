#include "Header_Test2.h"
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
void txtColor(int color)
{
	HANDLE hConsoleColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void Draw(int x)
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
	for (int i = 0; i < 125; ++i)    // lap day khung menu = khoang trang
		for (int j = 0; j < 60; ++j)
		{
			gotoxy(i, j);
			cout << char(32);
		}
	txtColor(7);
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
void AddNewYear(Schoolyear*& NewYear)
{
	ifstream in;
	string name = "";
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
		clear();
		gotoxy(24, 12);
		cout << "Input name of the class: ";
		Draw(11);
		gotoxy(51, 12);
		getline(cin, name,'\n');
		name  += ".csv";	
		in.open(name, ios::in);
		while (!in.is_open())
		{
			cout << "Press enter to continue...";
			cin.ignore(1000, '\n');
			txtColor(4);
			gotoxy(51, 14);
			cout << "Can not open files to input data. Please enter name of class again:";
			Draw(11);
			gotoxy(51, 12);
			getline(cin, name,'\n');
			txtColor(7);
		}
		NewYear->CLass->NameOfClass = name;
		string temp="",tempN="";
		getline(in, temp, ',');
		for (int i = 0; i < temp.length(); i++)
			if ((temp[i])>='0'&&temp[i]<='9')
				tempN += temp[i];
		int num = stoi(tempN);
		NewYear->CLass[i].NumOfStudent = num;
		NewYear->CLass[i].Stu = new Student[num];
		getline(in, temp,'\n');
		for (int j = 0; j < num; j++)
		{
			getline(in, NewYear->CLass[i].Stu[j].Num,',');
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
		system("pause");
		txtColor(7);
		in.close();
	}
	NewYear->YearNext = nullptr;
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
	cin.ignore(1000, '\n');
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
int CheckLogin(string username, string password, Schoolyear*& YearCur, Student* stu, int NumOfStu)
{
	
	if (username[0] >= 48 && username[0] <= 57 && username.size() == 8)
	{
		if (username[1] >= 48 && username[1] <= 57)
		{
			int x = (username[0] - 48) * 10 + username[1] - 48;//x is 2 last num of the student year (Ex 2021, 2022... ->21,22...)
			while (YearCur != nullptr && x != (((YearCur->NumOfYear[2]) - 48) * 10 + (YearCur->NumOfYear[3] - 48)))
				YearCur = YearCur->YearNext;
			if (YearCur == nullptr) return 0;
			else
			{
				for (int i = 0; i < YearCur->NumOfClass; i++)
					for (int j = 0; j < YearCur->CLass[i].NumOfStudent; j++)
						if (username == YearCur->CLass[i].Stu[j].StudentID && YearCur->CLass[i].Stu[j].PassWord == password)
							return (i + 1) * 100 + j + 1;//return class+student ID (Ex class 1, ID 5->return 105)
				return 0;
			}
		}
		else return 0;
	}
	else return 0;
}

void InputUserAndPW(string& username, string& password)
{
	gotoxy(38, 12); cout << "Username:";
	gotoxy(38, 15); cout << "Password:";
	Draw(11);
	Draw(14);
	gotoxy(51, 12);
	cin.ignore(1000, '\n');
	getline(cin, username);
	FillPassword(password, 15);
}
void InputStudents(Student*& St, int& NumOfStu)
{
	ifstream in("StudentData.csv");
	string temp;
	getline(in, temp, ',');
	NumOfStu = stoi(temp);
	St = new Student[stoi(temp)];
	getline(in, temp,'\n');
	for (int i = 0; i < NumOfStu; i++)
	{
		getline(in, St[i].Surname, ',');
		getline(in, St[i].Name, ',');
		getline(in, St[i].Gender, ',');
		getline(in, St[i].ID, ',');
		getline(in, St[i].StudentID, ',');
		getline(in, St[i].PassWord);
	}
	in.close();
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
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}

void Back()
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
void CourseEnroll(Schoolyear* YearCur, Course* CourseHead, int x, int& NumOfOpt)
{
	int opt;
	int j = (x / 100) - 1;
	int k = (x % 100) - 1;
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
			gotoxy(25, t);
			cout << "Error. Register again: ";
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
						cout << "Conflicted with another course. Register again: " << endl;
						Back();
						goto Enroll;
					}
				}
				if (EnrollMove->Day2 == CourseCur->Day2)
				{
					if (EnrollMove->Session2 == CourseCur->Session2)
					{
						gotoxy(51, t + 2);
						cout << "Conflicted with another course. Register again:" << endl;
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
					cout << "Course is full. Register again: " << endl;
					Back();
					goto Enroll;
				}

			}
			else
			{
				gotoxy(51, t + 2);
				cout << "You have registered this course. Register again: " << endl;
				Back();
				goto Enroll;
			}

		}

	}
}
