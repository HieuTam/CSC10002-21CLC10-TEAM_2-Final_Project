#include "Header.h"

void push(Course *&CourseHead, string Final, string Total, string CourseID){
	Course *tmp=new Course;
	
	tmp->CourseID=CourseID;
	tmp->Score.Final=Final;
	tmp->Score.Total=Total;
	
	tmp->pNext=CourseHead;
	
	CourseHead=tmp;
}

void ViewScoreBoardStu(Schoolyear *YearCur, int x, int i){
	if (x==0) return;
	int z;
	cout << "Nhap hoc ky can tim: ";
	cin >> z;
	cout << "Lop " << YearCur->CLass[i].NameOfClass << ":" << endl;
	for (int j=0; j<YearCur->CLass[i].NumOfStudent; j++){
		cout << YearCur->CLass[i].Stu[j].StudentID << "   ";
		cout << YearCur->CLass[i].Stu[j].Surname << "   ";
		cout << YearCur->CLass[i].Stu[j].Name << "   " << endl;
		Course *pCur=YearCur->CLass[i].Stu[j].Registered;		
		while (pCur!=nullptr){
			cout << "Course: " << pCur->CourseID << endl;
			cout << "Final: " << pCur->Score.Final << endl;
			cout << "GPA: " << pCur->Score.Total << endl;
			pCur=pCur->pNext;
		}
		
		
		
		cout << "Total GPA: " << YearCur->CLass[i].Stu[j].Mark[z-1] << endl;
		
	}
}

int main(){
	int NumOfCourse;
	string CourseID, Final, Total;
	Schoolyear *YearCur=new Schoolyear;
	ifstream in;
	in.open("2021-2022.txt", ios::in);
	in >> YearCur->NumOfClass;
	YearCur->CLass=new Class[YearCur->NumOfClass]; //check
	for (int i=0; i<YearCur->NumOfClass; i++){
		in.ignore(100, '\n');
		getline(in, YearCur->CLass[i].NameOfClass); //check
		in >> YearCur->CLass[i].NumOfStudent;
		YearCur->CLass[i].Stu=new Student[YearCur->CLass[i].NumOfStudent];
		for (int j=0; j<YearCur->CLass[i].NumOfStudent; j++){
			in.ignore(100, '\n');
			getline(in, YearCur->CLass[i].Stu[j].StudentID);
			getline(in, YearCur->CLass[i].Stu[j].Surname);
			getline(in, YearCur->CLass[i].Stu[j].Name);
			
			YearCur->CLass[i].Stu[j].Mark=new int[3];
			for (int z=0; z<3; z++){
				in >> YearCur->CLass[i].Stu[j].Mark[z];
			}
			
			in >> NumOfCourse;
			in.ignore(100, '\n');
			for (int z=0; z<NumOfCourse; z++){
				getline(in, CourseID);
				getline(in, Final);
				getline(in, Total);
				push(YearCur->CLass[i].Stu[j].Registered, Final, Total, CourseID);
			
			}
		}
	}
	string ClassID;
	
	cout << "Nhap ten lop: ";
	getline(cin, ClassID);
	for (int i=0; i<YearCur->NumOfClass; i++){
		if (YearCur->CLass[i].NameOfClass==ClassID){
			ViewScoreBoardStu(YearCur, 1, i);
			return 0;
		}
	}
	
	in.close();
	
	
}
