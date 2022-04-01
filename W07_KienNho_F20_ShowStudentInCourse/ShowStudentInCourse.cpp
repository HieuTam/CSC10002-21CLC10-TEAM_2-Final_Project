#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
using namespace std;
void showStudentsInCourse(){
	fstream input;
	string CourseID,theWholeName;
	cout << "Input course ID: ";
	getline(cin, CourseID);
	input.open(CourseID + ".csv", ios::in);
	char *pTemp =new char[200];
	while(input>>theWholeName){
		istringstream buffer( theWholeName );
		string stuID,stuName,stuSurName;
		getline(buffer,stuID,',');
		getline(buffer,stuName,',');
		getline(buffer,stuSurName,' ');
		
		cout<<stuID<<"\t"<<stuName<<"\t"<<stuSurName<<endl;
	}
	input.close();
}
int main(){
	showStudentsInCourse();
	return 0;	
}
