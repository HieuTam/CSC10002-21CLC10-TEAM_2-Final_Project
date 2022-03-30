#include "header.h"

void ViewListStudentInClass(Schoolyear* YearCur){
	string year, ClassID;
	
	cout << "Enter the year you want to search: ";
	getline(cin, year);
	while (YearCur!=nullptr){
		YearCur=YearCur->YearNext;
		
		if (YearCur->NumOfYear==year){
			cout << "Enter the class you want to show the student: ";
			getline(cin, ClassID);
			
			for (int i=0; i<YearCur->NumOfClass; i++){
				if (YearCur->CLass[i]->NameOfClass==ClassID){
					for (int j=0; j<YearCur->CLass[i]->NumOfStudent; j++){
						cout << YearCur->CLass[i]->Stu[j]->Num << "    ";
						cout << YearCur->CLass[i]->Stu[j]->Surname << "    ";
						cout << YearCur->CLass[i]->Stu[j]->Name << "    ";
						cout << YearCur->CLass[i]->Stu[j]->DOB << "    ";
						cout << YearCur->CLass[i]->Stu[j]->Gender << "    ";
						cout << YearCur->CLass[i]->Stu[j]->StudentID << "    " << endl;
						
					}
					
					break;
				}
			}
			
			break;
		}
	}
	
	if (YearCur==nullptr){
		cout << "Schoolyear not found!";
	}
	
}

int main(){
	Schoolyear *YearCur=nullptr;
	ofstream output;
	output.open(CourseID + ".csv", ofstream::out);
}
