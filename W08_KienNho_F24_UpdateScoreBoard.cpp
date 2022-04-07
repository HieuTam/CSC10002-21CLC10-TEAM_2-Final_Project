void updateStudentResult(Course *CourseHead, Schoolyear* YearCur){
	LoadScoreboard(CourseHead,YearCur);
	int opt;
	Course* CourseCur = CourseHead;
	Data* InfoCur = nullptr;
	string studentID;
	cout<<"Enter the option: ";
	cout<<"1.Final point"<<endl;
	cout<<"2.Mid term point"<<endl;
	cout<<"3.Other point"<<endl;
	cin>>opt;
	InfoCur = CourseCur->DataOfStu;
	while (InfoCur != nullptr){
		Course* EnrollList = YearCur->CLass[InfoCur->StuClass].Stu[InfoCur->IDInClass].Registered;
		while (EnrollList != nullptr && EnrollList->CourseID != CourseCur->CourseID){
			EnrollList = EnrollList->pNext;
		}
		if (EnrollList != nullptr){
			if(opt==1) cin>>EnrollList->Score.Final;
			else if(opt==2)cin>>EnrollList->Score.Midterm;
			else if(opt==3)cin>>EnrollList->Score.Other;
			EnrollList->Score.Total = >EnrollList->Score.Final*40%+EnrollList->Score.Midterm*40%+EnrollList->Score.Other*20%;
		}
		InfoCur = InfoCur->pNext;
	}
}
	
	
