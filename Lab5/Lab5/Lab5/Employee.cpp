#include "Employee.h"


Employee::Employee()
{


}

Employee::Employee(string name, int id, bool isWorking)
{
	_employeeName = name;
	_employeeId = id;
	_isWorking = isWorking;

}

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

string Employee::toString()
{
	string x = getName() + "\t" + to_string(_employeeId) + "\t" + boolstring(_isWorking);

	return x;

}

string Employee::boolstring(bool x)
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
