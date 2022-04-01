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
	ifstream output;
	output.open("2021-2022.txt");
	output >> YearCur->NumOfClass;
	YearCur->CLass=new Class[YearCur->NumOfClass];
	for (int i=0; i<YearCur->NumOfClass; i++){
		output >> YearCur->CLass[i].NameOfClass;
		output >> YearCur->CLass[i].NumOfStudent;
		YearCur->CLass[i].Stu=new Student[YearCur->CLass[i].NumOfStudent];
		for (int j=0; j<YearCur->CLass[i].NumOfStudent; j++){
			output >> YearCur->CLass[i].Stu[j].Num;
			output >> YearCur->CLass[i].Stu[j].Surname;
			output >> YearCur->CLass[i].Stu[j].Name;
			output >> YearCur->CLass[i].Stu[j].DOB;
			output >> YearCur->CLass[i].Stu[j].Gender;
			output >> YearCur->CLass[i].Stu[j].StudentID;	
		}
	}

	output.close();
	ViewListStudentInClass(YearCur);
}
