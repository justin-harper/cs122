/*
Assignment: 3

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 8hrs

In completing this program, I received help from the following people:
myself

version 1.0 I am happy with this version!
*/


#include "Faculty.h"
#include <string>
#include<math.h>

using namespace std;




//constructor for the Faculty class

Faculty::Faculty(string name, int id, bool isWorking, double salary, int weeksPerYear, string department)
{

	setName(name);
	setEID(id);
	setStatus(isWorking);
	setAnnualSalary(salary);
	setWeeksPerYear(weeksPerYear);
	setDepartment(department);
}


//Faculties function to get the annual salary
double Faculty::getAnnualSalary(void) const
{
	double sal = _annual_salary;
	sal = floor(sal);

	return _annual_salary;
}


//Faculties function to set the annual salary
void Faculty::setAnnualSalary(double salary)
{
	_annual_salary = salary;
	return;
}

//Faculties function to get the number of weeks per year
int Faculty::getWeeksPerYear(void) const
{
	return _weeksPerYear;
}

//Faculties function to set the number of weeks per year
void Faculty::setWeeksPerYear(int weeks)
{
	_weeksPerYear = weeks;
	return;
}

//Faculties function to get the department
string Faculty::getDepartment(void) const
{
	return _department;
}

//Faculties function to set the department
void Faculty::setDepartment(string department)
{
	_department = department;
	return;
}

//Faculties function to get the weekly pay
double Faculty::getWeeklyPay(void) const
{
	return (_annual_salary / (double)_weeksPerYear);
}

//returns the string representaiton of a Faculty object
string Faculty::toString(void) const
{
	//fancy string manipulation to eliminate unneeded decimals
	double pay = getAnnualSalary();

	string p = to_string(pay);
	int decimal = p.find(".");
	while (p.length() > decimal + 3)
	{
		p.pop_back();
	}


	string x = Employee::toString() + "\t" + p + "  " + to_string(getWeeksPerYear()) + "\t" + getDepartment();

	return x;
}