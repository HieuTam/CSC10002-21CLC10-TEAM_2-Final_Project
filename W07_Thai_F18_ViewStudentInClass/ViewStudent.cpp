#include "header.h"

void ViewListStudentInClass(Schoolyear* YearCur){
	string ClassID;
	cout << "Enter the class you want to show the student: ";
	getline(cin, ClassID);
			
	for (int i=0; i<YearCur->NumOfClass; i++){
			if (YearCur->CLass[i].NameOfClass==ClassID){
				for (int j=0; j<YearCur->CLass[i].NumOfStudent; j++){
					cout << YearCur->CLass[i].Stu[j].Num << "    ";
					cout << YearCur->CLass[i].Stu[j].Surname << "    ";
					cout << YearCur->CLass[i].Stu[j].Name << "    ";
					cout << YearCur->CLass[i].Stu[j].DOB << "    ";
					cout << YearCur->CLass[i].Stu[j].Gender << "    ";
					cout << YearCur->CLass[i].Stu[j].StudentID << "    " << endl;					
				}
					
				break;
			}
		}
	
	if (YearCur==nullptr){
		cout << "Schoolyear not found!";
	}
	
}

int main(){
	Schoolyear *YearCur=new Schoolyear;
	ifstream input;
	input.open("2021-2022.txt");
	input >> YearCur->NumOfClass;
	YearCur->CLass=new Class[YearCur->NumOfClass];
	for (int i=0; i<YearCur->NumOfClass; i++){
		input >> YearCur->CLass[i].NameOfClass;
		input >> YearCur->CLass[i].NumOfStudent;
		YearCur->CLass[i].Stu=new Student[YearCur->CLass[i].NumOfStudent];
		input.ignore(100, '\n');
		for (int j=0; j<YearCur->CLass[i].NumOfStudent; j++){
			getline(input, YearCur->CLass[i].Stu[j].Num);
			getline(input, YearCur->CLass[i].Stu[j].Surname);
			getline(input, YearCur->CLass[i].Stu[j].Name);
			getline(input, YearCur->CLass[i].Stu[j].DOB);
			getline(input, YearCur->CLass[i].Stu[j].Gender);
			getline(input, YearCur->CLass[i].Stu[j].StudentID);	
		}
	}
	input.close();
	ViewListStudentInClass(YearCur);
	delete YearCur;
}

