#include "Header.h"



int main()
{
	teacher* Staff;
	Student* Stu;

	Schoolyear* YearHead = nullptr, * YearCur1 = nullptr, * YearCur2 = nullptr;
	string username, password;
	int NumOfStaff, sem = 0,NumOfStu;
	
	InputStaff(Staff, NumOfStaff);
	InputStudents(Stu, NumOfStu);
	clear(); 
	do
	{
		clear();
		InputUserAndPW(username, password);
		int x = CheckLogin(username, password, YearCur1, Staff, NumOfStaff, Stu, NumOfStu);
		if (x == 0)
		{
			
			cout << "YOUR USERNAME OR PASSWORD IS INCORRECT !!" << endl;
		
			password = "";
			YearCur1 = YearHead;
			continue;
		}
		else if(x>=100) {
			clear();
		}
		else
		{
			
			cout << "LOGIN SUCCESSFULLY." << endl;

		}
		string* str;
		int k;
		if (x < 100)k = 9; 
		else
		{
			k = 8; // day la so luog chuc nang cua student
		}
		str = new string[k];
		str[0] = "Log out";
		str[1] = "View info";
		str[2] = "Change password";
		if (x < 100) // x < 100 la chuyen qua phan staff x>= 100 la phan cua stud
		{
			str[3] = "Add new year";
			str[4] = "Add new semester";
			str[5] = "Course";
			str[6] = "View classes in a year";
			str[7] = "View students in a class";
			str[8] = "View students in a course";
		}
		else // DDAAY LA PHAN CUA STUDENT
		{
			str[3] = "Enroll in a course"; // thay the bang cac ham cua student
			str[4] = "View a list of enrolled courses";
			str[5] = "View a list of enrolled courses";
			str[6] = "View a list of his/her courses";
			str[7] = "View a list of classes";
			
		}
		int option = 1;
		while (option != 0)
		{
			while (true)
			{
				clear();
				for (int j = 0; j < 3; j++)
				{
					for (int i = 1; i < k; i++)
					{
						if (i == option)
						{
							gotoxy(60 - (str[i].length() / 2) - 4, i + 11);
							cout << " -->" << str[i] << "<-- " << endl;
						}
						else
						{
							gotoxy(60 - (str[i].length() / 2) - 4, i + 11);
							cout << "    " << str[i] << "    " << endl;
						}
					}
					if (option == 0)
					{
						gotoxy(60 - (str[0].length() / 2) - 4, k + 11);
						cout << "--> " << str[0] << " <--" << endl;
					}
					else
					{
						gotoxy(60 - (str[0].length() / 2), k + 11);
						cout << str[0] << "    " << endl;
					}
					for (int i = 1; i < k; i++)
					{
						if (i == option)
						{
							gotoxy(60 - (str[i].length() / 2) - 4, i + 11);
							cout << "--> " << str[i] << " <--" << endl;
						}
						else
						{
							gotoxy(60 - (str[i].length() / 2) - 4, i + 11);
							cout << "    " << str[i] << endl;
						}
					}
					if (option == 0)
					{
						gotoxy(60 - (str[0].length() / 2) - 4, k + 11);
						cout << " -->" << str[0] << "<-- " << endl;
					}
					else
					{
						gotoxy(60 - (str[0].length() / 2) - 4, k + 11);
						cout << "    " << str[0] << "    " << endl;
					}

				}
				char keycap = getch();
				if (keycap == -32) keycap = getch();
				else if (keycap == 13)
				{
					break;
				}
				if (keycap == 72) {
					if (option == 0) option = k - 1;
					else option--;
				}
				if (keycap == 80) {
					if (option == k - 1) option = 0;
					else option++;
				}
			}
			clear();
			switch (option)
			{
			case 1:
			{
				Back();
				break;
			}
			case 2:
			{
				ChangePassword(YearCur1, Staff, x, NumOfStaff);
				Back();
				break;
			}
			case 3:
			{
				
				break;
			}
			case 5:
			{
						
				break;
			}
			case 6:
			{

				
				break;
			}
			
			case 0:
			{
				break;
			}
			}
			password = "";
		}
		delete[]str;
	} while (true);
	delete[]Staff;
	return 0;
}







