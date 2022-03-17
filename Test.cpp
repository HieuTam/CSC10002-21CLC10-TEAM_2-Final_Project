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
