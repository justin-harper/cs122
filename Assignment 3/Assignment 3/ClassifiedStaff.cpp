/*
Assignment: 3

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 8hrs

In completing this program, I received help from the following people:
myself

version 1.0 I am happy with this version!
*/




#include "ClassifiedStaff.h"
#include <math.h>


//constructor for the ClassifiedStaff class
ClassifiedStaff::ClassifiedStaff(string name, int id, bool isWorking, double salary, string division)
{
	
	setName(name);
	setEID(id);
	setStatus(isWorking);
	setWeeklySalary(salary);
	setDivision(division);


}

//ClassfiedStaff function to set the weekly salary
void ClassifiedStaff::setWeeklySalary(double salary)
{
	_weeklySalary = salary;
	return;
}

//ClassfiedStaff function to get the division
string ClassifiedStaff::getDivision() const
{
	return _division;
}

//ClassfiedStaff function to set the division
void ClassifiedStaff::setDivision(string division)
{
	_division = division;
}

//ClassfiedStaff function to get the weekly pay
double ClassifiedStaff::getWeeklyPay() const
{
	return _weeklySalary;
}

//returns the string representaion of the ClassfiedStaff class
string ClassifiedStaff::toString() const
{
	double pay = getWeeklyPay();
	
	string p = to_string(pay);
	int decimal = p.find(".");
	while (p.length() > decimal + 3)
	{
		p.pop_back();
	}


	
	string t = Employee::toString() + "\t" + p + "\t" + getDivision();
	return t;
}

