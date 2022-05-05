#include "Header.h"

void RemoveCourseEnrolled(Schoolyear* YearCur, Course* CourseHead, int x)
{
	// if (x==0) return;
	// string CourseID, name, surname, StudentID, ClassID;
	// int choice;
	// cout << "Enter student's surname: ";
	// getline(cin, surname);
	// cout << "Enter student's name: ";
	// getline(cin, name);
	// cout << "Enter student's id";
	// getline(cin, StudentID);
	for (int i=0; i<YearCur->NumOfClass; i++){
			for (int j=0; j<YearCur->CLass[i].NumOfStudent; j++){
				if (YearCur->CLass[i].Stu[j].Surname==surname && YearCur->CLass[i].Stu[j].Name==name && YearCur->CLass[i].Stu[j].StudentID==StudentID){
					cout << "Student found. Please enter the course you want to remove ";
					getline(cin, CourseID);
					Course *pCur=YearCur->CLass[i].Stu[j].Registered;
					while (pCur && pCur->CourseID==CourseID){
						pCur=pCur->pNext;
					}
					
					if (pCur){
						cout << "Are you really sure you want to remove this course?";
						cin >> choice;
						if (choice==1){
							Course *tmp=pCur;
							pCur=pCur->pNext;
							delete tmp;
							break;
						}
						
						else{
							cout << "You didn't remove the enrolled course";
							return;
						}
					}
					else {
						cout << "No courses found!!";
						return;
					}
				}
				
				else{
					cout << "No students found!!";
					return;
				}
				
				break;
			}
		
		}
	Course *CourseCur=CourseHead;
	while (CourseCur && CourseCur->CourseID!=CourseID){
		CourseCur=CourseCur->pNext;
	}
	
	if (CourseCur){
		Data *InfoCur=CourseCur->DataOfStu;
		while (InfoCur && (InfoCur->StudentID!=StudentID || InfoCur->Name!=name || InfoCur->Surname!=surname)){
			InfoCur=InfoCur->pNext;
		}
		
		if (InfoCur){
			Data *tmp=InfoCur;
			InfoCur=InfoCur->pNext;
			delete tmp;
			cout << "Remove from course successfully!!!";
		}
		
		else
			cout << "Student not found";
	}
	else
		cout << "Course not found!!";
}

int main(){
	
	Schoolyear *YearCur=new Schoolyear;
	cout << "Year Name: ";
	getline(cin, YearCur->NumOfYear);
	cout << "Number of classes: ";
	cin >> YearCur->NumOfClass;
	YearCur->CLass=new Class[YearCur->NumOfClass];
	for (int i=0; i<YearCur->NumOfClass; i++){
		cout << "Number of students: ";
		cin >> YearCur->CLass[i].NumOfStudent;
		YearCur->CLass[i].Stu=new Student[YearCur->CLass[i].NumOfStudent];
		for (int j=0; j<YearCur->CLass[i].NumOfStudent; j++){
			cout << "Student " << j+1 << endl;
			cout << "ID: ";
			cin >> YearCur->CLass[i].Stu[j].StudentID;
			cout << "Name: ";
			cin >> YearCur->CLass[i].Stu[j].Name;
			cout << "Surname: ";
			cin.ignore();
			getline(cin, YearCur->CLass[i].Stu[j].Surname);
		}
	}
	
	int choice, choice1;
	Course *CourseHead=nullptr;
	
	cout << "Enter a course? ";
	cin >> choice;
	while (choice){
		Course *tmp=new Course;
		cout << "Course name: ";
		cin >> tmp->CourseID;
		cout << "Enter Student? ";
		cin >> choice1;
		
		while (choice1){
			Data *Info=new Data;
			cout << "Student Info: " << endl;
			cout << "Student ID: " << endl;
			cin >> Info->StudentID;
			cout << "Name: " << endl;
			cin >> Info->Name;
			cout << "Surname: " << endl;
			cin.ignore();
			getline(cin, Info->Surname);
			Info->pNext=tmp->DataOfStu;
			
			tmp->DataOfStu=Info;
			cout << "Enter again? ";
			cin >> choice1;
			
		}
		
		tmp->pNext=CourseHead;
		
		CourseHead=tmp;
		
		cout << "Enter again? ";
		cin >> choice;	
	}
	
	Course *CourseCur=CourseHead;
	while (CourseCur){
		Data *InfoCur=CourseCur->DataOfStu;
		while (InfoCur){
			for (int i=0; i<YearCur->NumOfClass; i++)
				for (int j=0; j<YearCur->CLass[i].NumOfStudent; j++){
					if (InfoCur->StudentID==YearCur->CLass[i].Stu[j].StudentID && InfoCur->Name==YearCur->CLass[i].Stu[j].Name && InfoCur->Surname==YearCur->CLass[i].Stu[j].Surname){
						Data *tmp=CourseCur;
						
						tmp->pNext=YearCur->CLass[i].Stu[j].Registered;
						
						YearCur->CLass[i].Stu[j].Registered=tmp;
					}
				}
			
			InfoCur=InfoCur->pNext;
		}
	}
	
	RemoveCourseEnrolled(YearCur, CourseHead, 1);
}
