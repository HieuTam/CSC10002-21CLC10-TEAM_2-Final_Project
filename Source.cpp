#include "Header.h"




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







