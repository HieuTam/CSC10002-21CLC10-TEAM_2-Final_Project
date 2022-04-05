#include "Header_Test2.h"
void LoadScoreboard(Course* CourseHead, Schoolyear* YearCur)
{
	ifstream input;
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
			if (CourseCur == nullptr)
			{
				cout << "Cannot find this course! Please enter again ";
				return;
			}

			if (CourseCur->DataOfStu = nullptr)
			{
				cout << "Somehow there is no student in this course?";
				return;
			}
			InfoCur = CourseCur->DataOfStu;
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


				Course* EnrollList = YearCur->CLass[InfoCur->StuClass].Stu[InfoCur->IDInClass].Registered;

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
			if (InfoCur == nullptr) cout << "Imported successfully";
			else cout << "Imported fail";
		}

	}
	input.close();
}