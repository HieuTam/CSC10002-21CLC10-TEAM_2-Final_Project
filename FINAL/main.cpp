#include "Header.h"
#include "Source.cpp"


int main()
{
	teacher* Staff;
	Student* Stu;

	Schoolyear* YearHead = nullptr, * YearCur1 = nullptr, * YearCur2 = nullptr;
	date Today;
	string username, password;
	int NumOfStaff, sem = 0,NumOfStu;
	Now(Today);
	
	InputStaff(Staff, NumOfStaff);
	InputStudents(Stu, NumOfStu);
	clear(); // ham xoa man hinh
	do
	{
		clear();
		Now(Today);
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
			cout << "This is student" << endl;
		}
		else
		{
			
			cout << "LOGIN SUCCESSFULLY." << endl;

		}
		string* str;
		int k;
		if (x < 100)k = 9; // khi k=9 la chuc nang cua staff
		else
		{
			k = 6; // day la so luog chuc nang cua student
			/*if (CheckdateRegister(Today, YearCur2->Sem[sem].StartReg, YearCur2->Sem[sem].EndReg)) k = 6;
			else k = 4;
			if (CheckImport(YearCur1, x)) k = 5;*/
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
			str[3] = "Add new year"; // thay the bang cac ham cua student
			str[4] = "Add new semester";
			str[5] = "Course";
			
			//
			/*if (CheckdateRegister(Today, YearCur2->Sem[sem].StartReg, YearCur2->Sem[sem].EndReg))
			{
				str[3] = "Register course";
				str[4] = "View list of enrolled courses";
				str[5] = "Remove a course from the enrolled list";
			}
			else str[3] = "View course registered";
			if (CheckImport(YearCur1, x)) str[4] = "View your scoreboard";*/
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
					Sleep(200);
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
					Sleep(200);

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
				ViewInfo(x, YearCur1, Staff);
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
				if (x < 100)
				{
					if (YearHead == nullptr)
					{
						AddNewYear(YearHead);
						YearCur1 = YearHead;
					}
					else
					{
						AddNewYear(YearCur1->YearNext);
						YearCur1 = YearCur1->YearNext;
					}
				}
				else
				{
					if (CheckdateRegister(Today, YearCur2->Sem[sem].StartReg, YearCur2->Sem[sem].EndReg))
						CourseEnroll(YearCur1, YearCur2->Sem[sem].pCourse, x, YearCur1->CLass[x / 100 - 1].Stu[x % 100 - 1].NumOfOpt);
					else
					{
						int t, i;
						ViewCourse(YearCur1->CLass[x / 100 - 1].Stu[x % 100 - 1].Registered, t, i);
						Back();
					}
				}
				break;
			}
			case 4:
			{
				if (x < 100)
				{
					clear();
					YearCur2 = YearHead;
					AddNewSemester(YearCur2, sem);
				}
				else
				{
					int t, i;
					ViewCourse(YearCur1->CLass[x / 100 - 1].Stu[x % 100 - 1].Registered, t, i);
					Back();
				}
				break;
			}
			case 5:
			{
				if (x < 100) 
				{
					clear();
					int t;
					string* str1;
					if (CheckdateEndSemester(Today, YearCur2->Sem[sem].EndSem))
						t = 10;
					else
						t = 5;
					str1 = new string[t];
					str1[0] = "Back";
					str1[1] = "Add new course";
					str1[2] = "View list of course";
					str1[3] = "Update course information";
					str1[4] = "Delete a course";
					if (CheckdateEndSemester(Today, YearCur2->Sem[sem].EndSem))
					{
						str1[5] = "Export list of students  in a course";
						str1[6] = "Import the scoreboard of a course";
						str1[7] = "View the scoreboard of a course";
						str1[8] = "Update a student result";
						str1[9] = "View the scoreboard of a class";
					}
					int option2 = 1;
					while (option2 != 0)
					{
						while (true)
						{
							clear();
							for (int j = 0; j < 3; j++)
							{
								for (int i = 1; i < t; i++)
								{
									if (i == option2)
									{
										gotoxy(60 - (str1[i].length() / 2) - 4, i + 11);
										cout << " -->" << str1[i] << "<-- " << endl;
									}
									else
									{
										gotoxy(60 - (str1[i].length() / 2) - 4, i + 11);
										cout << "    " << str1[i] << "    " << endl;
									}
								}
								if (option2 == 0)
								{
									gotoxy(60 - (str1[0].length() / 2) - 4, t + 11);
									cout << "--> " << str1[0] << " <--" << endl;
								}
								else
								{
									gotoxy(60 - (str1[0].length() / 2), t + 11);
									cout << str1[0] << "    " << endl;
								}
								for (int i = 1; i < t; i++)
								{
									if (i == option2)
									{
										gotoxy(60 - (str1[i].length() / 2) - 4, i + 11);
										cout << "--> " << str1[i] << " <--" << endl;
									}
									else
									{
										gotoxy(60 - (str1[i].length() / 2) - 4, i + 11);
										cout << "    " << str1[i] << endl;
									}
								}
								if (option2 == 0)
								{
									gotoxy(60 - (str1[0].length() / 2) - 4, t + 11);
									cout << " -->" << str1[0] << "<-- " << endl;
								}
								else
								{
									gotoxy(60 - (str1[0].length() / 2) - 4, t + 11);
									cout << "    " << str1[0] << "    " << endl;
								}

							}
							char keycap = getch();
							if (keycap == -32) keycap = getch();
							else if (keycap == 13)
							{
								break;
							}
							if (keycap == 72) {
								if (option2 == 0) option2 = t - 1;
								else option2--;
							}
							if (keycap == 80) {
								if (option2 == t - 1) option2 = 0;
								else option2++;
							}
						}
						switch (option2)
						{
						case 1:
						{
							AddNewCourse(YearCur2->Sem[sem].pCourse);
							Back();
							break;
						}
						case 2:
						{
							int t;
							ViewCourse(YearCur2->Sem[sem].pCourse, t, t);
							Back();
							break;
						}
						case 3:
						{
							UpdateCourse(YearCur2, sem);
							break;
						}
						case 4:
						{
							DeleteCourse(YearCur2, sem);
							Back();
							break;
						}
						//case 5:
						//{
						//	ExportListStudentCourse(YearCur2->Sem[sem].pCourse);
						//	break;
						//}
						//case 6:
						//{
						//	LoadScoreboard(YearCur2->Sem[sem].pCourse, YearHead);
						//	Back();
						//	break;
						//}
						//case 7:
						//{
						//	ViewScoreboardCourse(YearCur2->Sem[sem].pCourse);
						//	Back();
						//	break;
						//}
						//case 8:
						//{
						//	//Export list � students in a course
						//	break;
						//}
						//case 9:
						//{
						//	//Import the scoreboard
						//	break;
						//}
						}
					}
					delete[]str1;
				}
				else
				{
					//Student
					Back();
				}
				break;
			}
			case 6:
			{

				ViewListClasses(YearHead);
				Back();
				break;
			}
			/*case 7:
			{
				ViewListStudentInClass(YearHead);
				Back();
				break;
			}
			case 8:
			{
				ViewListStudentInCourse(YearCur2, sem);
				Back();

				break;
			}*/
			case 0:
			{
				YearCur1 = YearHead;
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







