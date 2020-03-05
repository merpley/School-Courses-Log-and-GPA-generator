
#ifndef COURSE_H
#define COURSE_H

using namespace std;

class Course
{
private:
	char title[25];
	int num_units;
	char grade;

public:
	Course()
	{
		title[0] = '\0';
		num_units = 0;
		grade = 'A';
	}
	
	~Course();

	char *gettitle();
	void settitle(char*);
	
	int getnum_units();
	void setnum_units(int);
	
	char getgrade();
	void setgrade(char);

	void Course::displayCourse();

	void edit()
	{
		cout << "Enter course name: " << endl;
		cin.getline(title, 25);
		cout << "Enter course units: " << endl;
		cin >> num_units;
		cout << "Enter course grade: " << endl;
		cin >> grade;
	}

	void displayGPA(Course *courseptr[], int count);


};

#endif 
