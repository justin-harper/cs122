/*
Assignment: 3

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 8hrs

In completing this program, I received help from the following people:
myself

version 1.0 I am happy with this version!
*/


#ifndef ClassifiedStaff_h
#define ClassifiedStaff_h

#include "Employee.h"


#include <string>

//the ClassifiedStaff class extends the Employee class

class ClassifiedStaff : public Employee
{

private:

	double _weeklySalary;
	string _division;



public:

	ClassifiedStaff(string name, int id, bool isWorking, double salary, string division);

	void setWeeklySalary(double salary);

	string getDivision(void) const;
	void setDivision(string division);

	virtual double getWeeklyPay() const;

	virtual string toString() const;




};





#endif