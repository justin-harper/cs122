#pragma once


/*
Justin Harper
10696738

version 1.0
*/

#include <string>
#include <iostream>
#include <queue>
#include "Customer.h"
#include<vector>


class CheckoutLine
{


private:

	int _lineNumber;
	
	std::queue<Customer> _line;
	std::vector<Customer> _servedCustomers;


public:
	CheckoutLine()
	{
		_lineNumber = 0;
	}
	
	CheckoutLine(int lineNumber)
	{
		_lineNumber = lineNumber;
	}
	
	
	std::string getLineName()
	{
		return std::to_string(_lineNumber);
	}

	bool isEmpty()
	{
		if (_line.empty() == 1)
		{
			return true;
		}
		else
			return false;
	}

	void addCustomer(Customer someCustomer)
	{
		_line.push(someCustomer);
	}

	std::vector<Customer> getServiceCustomer()
	{
		return _servedCustomers;
	}

	void serviceCustomer()
	{
		//_servedCustomers.push_back(_line.front());
		Customer j = _line.front();
		//std::cout << j.getDepartureTime() << " " << j._test << std::endl;
		_servedCustomers.push_back(j);

		_line.pop();
		
	}

	Customer& getFirstCustomer()
	{
		
		return _line.front();
	}


};


