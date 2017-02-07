/*
Assignment: 3

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 8hrs

In completing this program, I received help from the following people:
myself

version 1.0 I am happy with this version!
*/



#ifndef Faculty_h
#define Faculty_h

#include "Employee.h"
#include <string>


//the Faculty class extends the Employee class

class Faculty : public Employee
{
private:
	double _annual_salary;
	string _department;
	int _weeksPerYear;


public:
	Faculty(string name, int id, bool isWorking, double salary, int weeksPerYear, string department);
	double getAnnualSalary(void) const;
	void setAnnualSalary(double salary);
	int getWeeksPerYear(void) const;
	void setWeeksPerYear(int weeks);
	string getDepartment(void) const;
	void setDepartment(string department);
	virtual double getWeeklyPay(void) const;
	virtual string toString(void) const;




};




#endif