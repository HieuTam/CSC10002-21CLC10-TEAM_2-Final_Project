#include <iostream> 
#include ""


void ViewListClasses(Schoolyear* YearCur) {
	cout << "Enter the year you want to view class: ";
	getline(cin, year);

	while (YearCur != nullptr) {
		if (year == YearCur->NumOfYear) {
			for (int i = 0; i < YearCur->NumOfClass; i++) {
				cout << i + 1 << "." << YearCur->CLass[i]->NameOfClass;
			}
			break;
		}
		YearCur = YearCur->YearNext;
	}
	if (YearCur == nullptr) {
		cout << "The entered year is not available" << endl;
	}
}
