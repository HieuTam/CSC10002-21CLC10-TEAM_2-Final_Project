#include "Header.h"

void RemoveCourseEnrolled(Schoolyear* YearCur, Course* CourseHead, int x)
{
	if (x==0) return;
	string CourseID, name, surname, StudentID, ClassID;
	cout << "Enter student's class: ";
	getiline(cin, ClassID)
	cout << "Enter student's surname: ";
	getline(cin, surname);
	cout << "Enter student's name: ";
	getline(cin, name);
	cout << "Enter student's id";
	getline(cin, StudentID);
	for (int i=0; i<YearCur->NumOfClass; i++){
		if (YearCur->CLass[i].NameOfClass==ClassID){
			for (int j=0; j<YearCur->CLass[i].NumOfStudent; j++){
				if (YearCur->CLass[i].Stu[j].Surname==surname && YearCur->CLass[i].Stu[j].Name==name && YearCur->CLass[i].Stu[j].StudentID==StudentID){
					cout << "Student found. Please enter the course you want to remove ";
					getline(cin, CourseID);
					while (pCur!=nullptr)
					
				}
			}
			
			
		}
	}
}

int main(){
	
}
