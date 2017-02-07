/*
Assignment: 3

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 8hrs

In completing this program, I received help from the following people:
myself

version 1.0 I am happy with this version!
*/


#ifndef Employee_h
#define Employee_h

#include <string>

using namespace std;

//parrent class used for this assignment...note an instance of Employee should never be
//created however ponters to Employees can be used.

class Employee
{
public:
	
	
	
	Employee();
	Employee(string name, int id, bool isWorking);

	string getName() const;
	void setName(string name);

	int getEID() const;
	void setEID(int id);

	bool isWorking() const;
	void setStatus(bool employed);
	virtual	string toString() const;
	virtual double getWeeklyPay() const;


private:
	string _employeeName;
	int _employeeId;
	bool _isWorking;

protected:
	string boolstring(bool x) const;


};




#endif