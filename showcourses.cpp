void showCourses(Student s, Course c){
	Course pCur=c;
	while(pCur!=nullptr){
		if(s->CoursesID1==pCur->CoursesID) cout<<pCur->NameOfCourse<<endl;
		else if(s->CoursesID2==pCur->CoursesID) cout<<pCur->NameOfCourse<<endl;
		else if(s->CoursesID3==pCur->CoursesID) cout<<pCur->NameOfCourse<<endl;
		else if(s->CoursesID4==pCur->CoursesID) cout<<pCur->NameOfCourse<<endl;
		else (s->CoursesID5==pCur->CoursesID) cout<<pCur->NameOfCourse<<endl;
		pCur=pCur->pNext;
	}
}
		
	
