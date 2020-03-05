

#include <iostream>
#include <conio.h>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "courses.h"

using namespace std;

Course::~Course()
{

}
char* Course::gettitle()
{
	return title;
}

void Course::settitle(char* title1)
{
	strcpy_s(title, title1); //title=title1
}

int Course::getnum_units()
{
	return num_units;
}

void Course::setnum_units(int num_units1)
{
	num_units = num_units1;
}

char Course::getgrade()
{
	return grade;
}

void Course::setgrade(char grade1)
{
	grade = grade1;
}


