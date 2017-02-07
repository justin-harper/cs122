/*
Assignment: 3

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 8hrs

In completing this program, I received help from the following people:
myself

version 1.0 I am happy with this version!
*/


#include "StudentEmployee.h"
#include "Employee.h"
#include <iostream>

using namespace std;



//constructor for the StudentEmployee class
StudentEmployee::StudentEmployee(string name, int id, bool isWorking, int hrsWorked, bool workStudy, double wage)
{
	
	setName(name);
	setEID(id);
	setStatus(isWorking);


	_hrsWorked = hrsWorked;
	_workStudy = workStudy;
	_wage = wage;

}
//StudentEmployee function to get the wage
double StudentEmployee::getWage() const
{
	return _wage;
}

//StudentEmployee function to set the wage
void StudentEmployee::setWage(double wage)
{
	_wage = wage;
	return;
}

//StudentEmployee function to get the hours worked
int StudentEmployee::getHrsWorked() const
{
	return _hrsWorked;
}

//StudentEmployee function to set the hours worked
void StudentEmployee::setHrsWorked(int hrs)
{

	_hrsWorked = hrs;
	return;
}

//StudentEmployee function to get the weekly pay
double StudentEmployee::getWeeklyPay() const
{
	return (_hrsWorked * _wage);
}

//StudentEmployee function to get the work study status
bool StudentEmployee::isWorkStudy() const
{
	return _workStudy;
}

//StudentEmployee function to set the work study status
void StudentEmployee::setWorkStudy(bool ws)
{
	_workStudy = ws;
	return;
}


//returns the string representaiton of a StudentEmployee object
string StudentEmployee::toString()
{
	

	string x = Employee::toString() + "\t" + to_string(_hrsWorked) + "\t" + boolstring(_workStudy) + "\t" + to_string(_wage);
	
	return x;
}