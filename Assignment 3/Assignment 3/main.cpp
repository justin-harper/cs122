
/*
Assignment: 3

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 8hrs

In completing this program, I received help from the following people:
myself

version 1.0 I am happy with this version!
*/

#include "StringSplitter.h"

#include "Employee.h"
#include "ClassifiedStaff.h"
#include "StudentEmployee.h"
#include "Faculty.h"


#include "EmployeeFactory.h"



#include <string>
#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
#include <iomanip>


using namespace std;

ifstream openFile(void)
{

	//cute function to check if the string supplied by the user can be used to open the file
	string name = "";
	bool success = false;
	while (!success)
	{

		cout << "Enter an input file:" << endl;
		cin >> name;

		ifstream myfile(name);
		
		if (myfile)
		{
			system("cls");
			return myfile;
			
		}
	}
	
}


int main(void)
{

	string line = "";
	
	string dividor = "===============================================================================";
	int count = 0;
	
	//open the csv file
	ifstream myfile = openFile();
	
	


	//used to make debuging easier
	//ifstream myfile("allemployees.csv");
	
	StringSplitter split{};
		
	//vector of Employee pointers that will contain pointers to the objects that are created from the file
	vector<Employee*> objects{}; 

	//factory is used to create the objects to fill the vector of employees
	EmployeeFactory factory{};
	



	

	

#pragma region fill_vector

	//while there are lines to get put them into the vector
	while (getline(myfile, line))
	{
		objects.push_back(factory.fromString(line));

		count++;
	}


	

#pragma endregion
	
#pragma region raw_output

	//print the raw output to the console
	cout << "*** Raw output ***" << endl;
	cout << dividor << endl;

	//use dynamic casts to access the polymorphic functions of each object
	// there has to be a better way to do this ;)
	for (int i = 0; i < count; i++)
	{

		StudentEmployee* se = dynamic_cast<StudentEmployee*>(objects[i]);
		if (se != nullptr)
		{

			cout << se->toString() << endl;
		}
		else
		{
			ClassifiedStaff* cs = dynamic_cast<ClassifiedStaff*>(objects[i]);
			if (cs != nullptr)
			{
				cout << cs->toString() << endl;
			}
			else
			{
				Faculty* f = dynamic_cast<Faculty*>(objects[i]);
				if (f != nullptr)
				{
					cout << f->toString() << endl;
				}
			}
		}
	}

#pragma endregion


#pragma region next_paycheck

	//calculate the next paycheck if the employee is working
	cout << endl << endl;
	cout << "*** Next Paycheck ***" << endl;
	cout << dividor << endl;


	//and again dynamic casts to access polymorphic functions to calculate the next paycheck

	for (int i = 0; i < count; i++)
	{

		StudentEmployee* se = dynamic_cast<StudentEmployee*>(objects[i]);
		if (se != nullptr)
		{
			if (se->isWorking()) //only print if they are working
			{

				//fancy string manipulation to get rid of unneed decimals
				double pay = se->getWeeklyPay();

				string p = to_string(pay);
				int decimal = p.find(".");
				while (p.length() > decimal + 3)
				{
					p.pop_back();
				}


				cout << se->getName() + "\t\t\t$" + p << endl;
			}
		}
		else
		{
			ClassifiedStaff* cs = dynamic_cast<ClassifiedStaff*>(objects[i]);
			if (cs != nullptr)
			{
				if (cs->isWorking()) //only print if they are working
				{

					//fancy string manipulation to get rid of unneed decimals
					double pay = cs->getWeeklyPay();

					string p = to_string(pay);
					int decimal = p.find(".");
					while (p.length() > decimal + 3)
					{
						p.pop_back();
					}


					cout << cs->getName() + "\t\t\t$" + p << endl;

				}
			}
			else
			{
				Faculty* f = dynamic_cast<Faculty*>(objects[i]);
				if (f != nullptr)
				{
					if (f->isWorking()) //only print if they are working
					{

						//fancy string manipulation to get rid of unneed decimals
						double pay = f->getWeeklyPay();

						string p = to_string(pay);
						int decimal = p.find(".");
						while (p.length() > decimal + 3)
						{
							p.pop_back();
						}
						
						cout << f->getName() + "\t\t\t$" + p << endl;
					}
				}
			}
		}
	}
	
#pragma endregion


	//thats all folks
	return 0;
}