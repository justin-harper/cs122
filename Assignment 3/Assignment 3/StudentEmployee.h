/*
Assignment: 3

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 8hrs

In completing this program, I received help from the following people:
myself

version 1.0 I am happy with this version!
*/



#ifndef StudentEmployee_h
#define StudentEmployee_h

#include "Employee.h"

#include <string>

using namespace std;

//the StudentEmployee class extends the Employee class

class StudentEmployee : public Employee

{
private:
		int _hrsWorked;
		bool _workStudy;
		double _wage;

public:
	
	StudentEmployee(string name, int id, bool isWorking, int hrsWorked, bool workStudy, double wage);
	
	double getWage() const;
	void setWage(double wage);

	int getHrsWorked() const;
	void setHrsWorked(int hrs);

	bool isWorkStudy() const;
	void setWorkStudy(bool ws);

	virtual	string toString();
	virtual double getWeeklyPay() const;

};





#endif