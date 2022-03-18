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
			k = 8; 
		}
		str = new string[k];
		str[0] = "Log out";
		str[1] = "View info";
		str[2] = "Change password";
	
		}


	return 0;
}







