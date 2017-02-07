#include "StudentEmployee.h"
#include "Employee.h"

using namespace std;

StudentEmployee::StudentEmployee()
{

}


StudentEmployee::StudentEmployee(string name, int id, bool isWorking, int hrsWorked, bool workStudy, double wage)
{
	//::Employee(name, id, isWorking);
	setName(name);
	setEID(id);
	setStatus(isWorking);


	_hrsWorked = hrsWorked;
	_workStudy = workStudy;
	_wage = wage;

}

double StudentEmployee::getWage() const
{
	return _wage;
}

void StudentEmployee::setWage(double wage)
{
	_wage = wage;
	return;
}

int StudentEmployee::getHrsWorked() const
{
	return _hrsWorked;
}

void StudentEmployee::setHrsWorked(int hrs)
{

	_hrsWorked = hrs;
	return;
}

double StudentEmployee::getWeeklyPay() const
{
	return (_hrsWorked * _wage);
}

bool StudentEmployee::isWorkStudy() const
{
	return _workStudy;
}

void StudentEmployee::setWorkStudy(bool ws)
{
	_workStudy = ws;
	return;
}

string StudentEmployee::toString()
{
	

	string x = Employee::toString() + "\t" + to_string(_hrsWorked) + "\t" + boolstring(_workStudy) + "\t" + to_string(_wage);
	//string x = getName()  + "\t" + to_string(_hrsWorked) + "\t" + ;
	return x;
}