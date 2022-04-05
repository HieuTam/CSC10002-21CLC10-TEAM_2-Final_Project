#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
void showStudentsInCourse(){
	fstream input;
	string CourseID,theWholeName;
	cout << "Input course ID: ";
	getline(cin, CourseID);
	input.open(CourseID + ".csv", ios::in);
	while(input.peek()!=EOF){
		string stuID,stuName,stuSurName;
		getline(input,stuID,',');
		getline(input,stuName,',');
		getline(input,stuSurName);
		
		cout<<stuID<<"\t"<<stuName<<"\t"<<stuSurName<<endl;
	}
	input.close();
}
int main(){
	showStudentsInCourse();
	return 0;	
}
