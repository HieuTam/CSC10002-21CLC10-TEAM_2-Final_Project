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
				gotoxy(51, 14);
				cout << "Can not open files to input data!!!";
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
		gotoxy(51, 14);
		cout << "Input data of class " << NewYear->CLass[i].NameOfClass << endl;
	}
	NewYear->YearNext = nullptr;
}
