/*
Assignment: 3

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 8hrs

In completing this program, I received help from the following people:
myself

version 1.0 I am happy with this version!
*/


#include "EmployeeFactory.h"

EmployeeFactory::EmployeeFactory()
{

}

//takes the line "text" from the csv file and returns a pointer to an employee of the required type
Employee* EmployeeFactory::fromString(string text)
{
	Employee* toReturn = nullptr;
	StringSplitter split{};
	vector<string> splitText;
	splitText = split.split(text, ",");
	int id = getInt(splitText[1]);
	bool isWorking = isbool(splitText[2]);


	
	if (splitText.size() == 5)
	{
		//Classified Staff
		

		double weekSalary = getDouble(splitText[3]);

		ClassifiedStaff* cs = new ClassifiedStaff(splitText[0], id, isWorking, weekSalary, splitText[4]);
		toReturn = cs;
	}
	else if (splitText[5][0] >= 'A' && splitText[5][0] <= 'Z')
	{
		//faculty
		

		double annualSalary = getDouble(splitText[3]);
		int weeksYear = getInt(splitText[4]);
		
		Faculty* f = new Faculty(splitText[0], id, isWorking, annualSalary, weeksYear, splitText[5]);
		toReturn = f;

	}
	else
	{
		//student employee
		

		int hrsWorked = getInt(splitText[3]);
		bool workStudy = isbool(splitText[4]);
		double wage = getDouble(splitText[5]);
		
		StudentEmployee* se = new StudentEmployee(splitText[0], id, isWorking, hrsWorked, workStudy, wage);
		toReturn = se;


	}
	
	return toReturn;

}

//returns the string represntaion of a bool
string EmployeeFactory::boolstring(bool x)
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

// returns the bool representation of a string
bool EmployeeFactory::isbool(string x)
{
	bool t = false;
	if (x == "TRUE")
	{
		t = true;
	}

	return t;
}

//attempts to convert a string to a decimal
double EmployeeFactory::getDouble(string x)
{
	double d = -1.0;
	try
	{
		d = stod(x);
	}
	catch (...)
	{
		cout << "error converting string to double" << endl;
	}

	return d;

}

//attempts to convert a string to an int
int EmployeeFactory::getInt(string x)
{
	int d = -1.0;
	try
	{
		d = stoi(x);
	}
	catch (...)
	{
		cout << "error converting string to int" << endl;
	}

	return d;

}