#include "StringSplitter.h"
#include "Employee.h"
#include "StudentEmployee.h"
#include <string>
#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

bool isbool(string x)
{
	bool t = false;
	if (x == "TRUE")
	{
		t = true;
	}

	return t;
}





int main(void)
{
	
	
	string line, text = "";
	ifstream myfile("employees.csv");
	StringSplitter split{};

	while (getline(myfile, line))
	{
		text+= line;
		
	}

	vector <string> employees = split.split(text, ",");
	
	vector <StudentEmployee> actual;

	
	cout << left << setw(16) << "Name";
	cout << left << setw(16) << "ID";
	cout << left << setw(8) << "Working";
	cout << left << setw(8) << "Hours";
	cout << left << setw(8) << "WS";
	cout << left << setw(15) << "Pay Rate" << endl;
	
	int z = -1;

	for (int i = 0; i < employees.size() / 6; i++)
	{
		string name = employees[++z];
		int id = stoi(employees[++z]);
		bool one = isbool(employees[++z]);
		int hrs = stoi(employees[++z]);
		bool two = isbool(employees[++z]);
		double wage = stod(employees[++z]);

		actual.push_back(StudentEmployee{ name, id, one, hrs, two, wage });


		cout << actual[i].toString() << endl;
	}


	return 0;
}