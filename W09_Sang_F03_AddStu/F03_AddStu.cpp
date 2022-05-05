#include "Header.h"
void InputStudents(Student*& St, int& NumOfStu)
{
	ifstream in("StudentData.csv");
	string temp;
	getline(in, temp, ',');
	NumOfStu = stoi(temp);
	Stu = new Student[stoi(temp)];
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