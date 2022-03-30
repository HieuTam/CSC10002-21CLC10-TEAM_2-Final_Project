#include "header.h"

void ViewListStudentInClass(Schoolyear* YearCur){
	string year, ClassID;
	
	cout << "Enter the year you want to search: ";
	getline(cin, year);
	while (YearCur!=nullptr){
		YearCur=YearCur->YearNext;
		
		if (YearCur->NumOfYear==year){
			cout 
			for (int i=0; i<YearCur->NumOfClass; i++){
				if ()
			}
			
		}
		
		break;
	}
	
	if (YearCur==nullptr){
		cout << "Schoolyear not found!";
	}
	
}
