#include "Header.h"



void Now_real(date& Today)
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	Today.year = 1900 + ltm->tm_year;
	Today.month = 1 + ltm->tm_mon;
	Today.day = ltm->tm_mday;
}

void Now(date& Today)
{
	string date; 
	//01 2 34 5 6789
	cout << "Today date (dd/mm/yyyy): "; 
	cin >> date; 


	Today.year = (int)date[6] * 1000 + (int)date[7] * 100 + (int)date[8] * 10 + (int)date[9] - 53328; 
	Today.month = (int)date[3] * 10 + (int)date[4] - 528; 
	Today.day = (int)date[0] * 10 + date[1] - 528; 
}
