/*
Assignment: 3

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 8hrs

In completing this program, I received help from the following people:
myself

version 1.0 I am happy with this version!
*/



#ifndef EmployeeFactory_h
#define EmployeeFactory_h

#include "Employee.h"
#include "StudentEmployee.h"
#include "ClassifiedStaff.h"
#include "Faculty.h"
#include "StringSplitter.h"

#include <string>
#include <iostream>

//the EmployeeFactory class returns a generic Employee pointer to a dynamicly created child object 
//based on the contents of the Text string

class EmployeeFactory
{
public:
	EmployeeFactory();

	Employee* fromString(string Text);
	
	
	
	
private:
	int getInt(string x);
	double getDouble(string x);
	string boolstring(bool x);
	bool isbool(string x);





};




#endif