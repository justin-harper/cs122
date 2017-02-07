/*
Assignment: 3

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 8hrs

In completing this program, I received help from the following people:
myself

version 1.0 I am happy with this version!
*/



#include "Employee.h"



//Employee only needs the defult construtor because it is never created directly
Employee::Employee()
{


}

//Employee still needs these functions to achive polomorphic behavior of child classes

string Employee::getName() const
{
	return _employeeName;

}

void Employee::setName(string name)
{
	_employeeName = name;

	return;

}

int Employee::getEID() const
{

	return _employeeId;
}

void Employee::setEID(int id)
{
	_employeeId = id;
	return;
}

bool Employee::isWorking() const
{
	return _isWorking;

}

void Employee::setStatus(bool employed)
{
	_isWorking = employed;
	return;
}

 string Employee::toString() const
{
	string x = getName() + "\t" + to_string(_employeeId) + "\t" + boolstring(_isWorking);

	return x;

}

string Employee::boolstring(bool x) const
{
	string ret = "";
	if (x == true)
	{
		ret = "TRUE";
	}
	else
	{
		ret = "FALSE";
	}

	return ret;
}

double Employee::getWeeklyPay() const
{

	return 0.0;
}
