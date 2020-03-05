
#include <iostream>
#include <conio.h>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "courses.h"

using namespace std;

void add(Course *courseptr[], int count);
void edit(Course *courseptr[], int count);
void sort(Course *courseptr[], int count);
void swap(Course subject1, Course subject2);
int bin_search(Course *courseptr[], char *title, int count);
void deleteall(Course *courseptr[], int &count);
void menu();
void displayGPA(Course *courseptr[], int count);
void displayCourse(Course *courseptr[], int count);

int main()
{
	Course *courseptr[10] = {};

	int count = 0;
	int choice;
	char title[50];

	do
	{
		menu();
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
		{
			add(courseptr, count);
			count++;
			break;
		}
		case 2:
		{
			edit(courseptr, count);
			break;
		}
		case 3:
		{
			sort(courseptr, count);
			displayCourse(courseptr, count);
			break;
		}
		case 4:
		{
			for (int i = 0; i < count; i++)
			{
				courseptr[i]->displayCourse();
			}
			break;
		}
		case 5:
		{
			displayGPA(courseptr, count);
			break;
		}
		case 6:
		{
			deleteall(courseptr, count);
			break;
		}

		}

	} while (choice != 7);
	
	cout << "\nPress any key to continue... " << endl;
	_getch;
	return 0;
}

	void menu()
	{
		cout << endl;
		cout << "1. Add new course" << endl;
		cout << "2. Edit an existing course" << endl;
		cout << "3. Display a course" << endl;
		cout << "4. List all courses" << endl;
		cout << "5. Display GPA" << endl;
		cout << "6. Delete all courses" << endl;
		cout << "7. Quit" << endl;

		cout << endl << "Enter your selection: " << endl;
	}

	void Course::displayCourse() 
	{
		cout << "Course Info: " << title << ", units: " << num_units << ", grade: " << grade << endl;
	}

	void add(Course *courseptr[], int count)
	{
		char title[50];
		int num_units;
		char temp[50];
		int temp2;
		char grade;
		for (int i = 0; i < 10; i++) {

		if (courseptr[i] == NULL) 
		{
			courseptr[i] = new Course;
				cout << "Enter course name: ";
				cin >> temp;
					courseptr[i]->settitle(temp);
				cout << "Enter number of units: ";
				cin >> temp2;
					courseptr[i]->setnum_units(temp2);
				cout << "Enter grade: ";
				cin >> grade;
					courseptr[i]->setgrade(grade);
				break;
			}
		}
	}
		
	void edit(Course *courseptr[10], int count)
	{
		cout << "Select the course to edit: ";
		for (int i = 0; i < count; i++)
		{
			cout << i + 1 << ". " << courseptr[i]->gettitle() << endl;
		}
		int num;
		char title[50];
		char grade='A';
		int units;

			cout << "Enter selection: ";
			cin >> num;
			char name[50];
			cin.ignore();
			cout << "Enter course name: ";
			cin.getline(name, 50);

			cout << "Enter units: ";
			cin >> units;

			cout << "Enter grade: ";
			cin >> grade;

			courseptr[num - 1]->settitle(name);
			courseptr[num - 1]->setgrade(grade);
			courseptr[num - 1]->setnum_units(units);
		}
		void sort(Course *courseptr[], int count)
		{
			int i, j;
				Course *tmp;

			for (i = 0; i < count - 1; i++)
			{
				for (j = 0; j < count; j++)
				{
					if (courseptr[j]->gettitle() < courseptr[i]->gettitle())
					{
						tmp = courseptr[i];
						courseptr[i] = courseptr[j];
						courseptr[j] = tmp;
					}
				}
			}
		
		}

		void swap(Course subj1, Course subj2)
		{
			Course tmp = subj1;
				subj1 = subj2;
				subj2 = tmp;
		}
		int bin_search(Course *courseptr[], char* title, int count)
		{
			int first=0, middle, last=count;
			int index=0;
			
			bool found = false;

			while (!found && first <= last)
			{
				middle = (first + last) / 2;
				if (strcmp(courseptr[middle]->gettitle(),  title))
				{
					found = true;
					index = middle;
				}
				else if (courseptr[middle]->gettitle() > title)
				{
					last = middle - 1;
				}
				else
				{
					first = middle + 1;
				}

			}
			return index+1;
		}

		void deleteall(Course *courseptr[], int &count)
		{
			for (int i = 0; i < count; i++)
			{
				delete courseptr[i];
				courseptr[i] = NULL;
			}
			count=0;
			cout << "All courses deleted!" << endl;
		}

		void displayGPA(Course *courseptr[], int count)
		{
			double total = 0.0;
			double units = 0.0;
			char grade;
			int points = 0;
			int totalunits = 0;

			for (int i = 0; i < count; i++)
			{
				units = courseptr[i]->getnum_units();
				grade = courseptr[i]->getgrade();

				switch (toupper(grade))
				{
				case 'A':
					points = 4;
					break;
				case 'B':
					points = 3;
					break;
				case 'C':
					points = 2;
					break;
				case 'D':
					points = 1;
					break;
				case 'F':
					points = 0;
					break;
					}
					total += (points * units);
					totalunits += units;
					}
					cout << "GPA: " << fixed << showpoint << setprecision(2) << total / totalunits << endl;
		
}

void displayCourse(Course *courseptr[], int count)
{
	char title[50];
	cout << "Enter course name: ";
	cin.ignore();
	cin.getline(title, 50);
	cout << endl;

	int index = bin_search(courseptr, title, count);
	if (index == 0)
	{
		cout << "Course not found. ";
	}
	else
	{
		for (int i = 0; i < count; i++)
		{
			if (index == i)
			{
				cout << endl << courseptr[index]->gettitle() << ", Units: "
					<< courseptr[index]->getnum_units()
					<< ", Grade: " << courseptr[index]->getgrade() << endl;
			}
		}
	}
}