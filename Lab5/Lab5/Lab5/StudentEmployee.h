#ifndef StudentEmployee_h
#define StudentEmployee_h

#include "Employee.h"

#include <string>

using namespace std;

class StudentEmployee : public Employee

{
private:
		int _hrsWorked;
		bool _workStudy;
		double _wage;

public:
	StudentEmployee();
	StudentEmployee(string name, int id, bool isWorking, int hrsWorked, bool workStudy, double wage);
	
	double getWage() const;
	void setWage(double wage);

	int getHrsWorked() const;
	void setHrsWorked(int hrs);

	double getWeeklyPay() const;

	bool isWorkStudy() const;
	void setWorkStudy(bool ws);

	string toString();

};





#endif