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
