#include "header.h"

void inputSchoolYear(Schoolyear* &YearHead)
{
	Schoolyear YearCur=YearHead;
	cout << "Schoolyear section" << endl;
	Schoolyear newyear=new Schoolyear;
	getline(cin, newyear->NumOfYear);
	cin >> newyear->NumOfYear;
	newyear->YearNext=nullptr;
	
	if (!YearHead)
	YearHead=newyear;
	
	else{
		while (YearCur->YearNext)
		YearCur=YearCur->YearNext;
		
		YearCur->YearNext=newyear;
		
		cout << "Input year complete!!!" << endl;
	}
	
	cout << "Year info: " << endl;
	SchoolYearInfo(YearCur->YearNext);
}

void SchoolYearInfo(Schoolyear* YearCur){
	for (int i=0; i<3; i++){
		cout << "Enter the beginning date of the registeration of semester " << i+1 << ": ";
		cin >> YearCur->Sem[i].StartReg.day >> YearCur->Sem[i].StartReg.month >> YearCur->Sem[i].StartReg.year;
		cout << "Enter the end date of the registeration of semester " << i+1 << ": ";
		cin >> YearCur->Sem[i].EndReg.day >> YearCur->Sem[i].EndReg.month >> YearCur->Sem[i].EndReg.year;
	}
}

