#pragma once
/*
Justin Harper
10696738

version 1.0
*/


#include <string>
#include <iostream>

//using namespace std;
class Customer
{
private:

	int _customerId = 0;
	int _arrivalTime = 0;
	int _serviceTime = 0;
	int _departureTime = -5;
	int _lName;
	int _Depart = -5;
	int _lineNumber = -1;



	//static int _idCounter;
	//std::string _lineName;

public:

	


	Customer()
	{

	}


	Customer(int customerID, int arrivalTime, int serviceTime)
	{
		_customerId = customerID;
		_arrivalTime = arrivalTime;
		_serviceTime = serviceTime;	
	}

	

	void setLineNumber(int line)
	{
		_lineNumber = line;
		
	}

	int getLineNumber(void)
	{
		return _lineNumber;
	}


	int getTotalWaitTime()
	{
		return _Depart - _arrivalTime;
	}

	void SetCustomerId(int customerId)
	{
		_customerId = customerId;
	}
	int getCustomerId()
	{
		return _customerId;
	}

	void setArrivalTime(int time)
	{
		_arrivalTime = time;
	}
	void setServiceTime(int time)
	{
		_serviceTime = time;
	}
	int getServiceTime()
	{
		return _serviceTime;
	}
	


	int getDepartTime()
	{
		return _Depart;
	}


	void setDepartTime(int x)
	{
		_Depart = x;
		return;
	}

	int getArrivalTime()
	{
		return _arrivalTime;
	}

	void setSomeLine(int a)
	{
		_lName = a;
	}

	int getSomeLine()
	{
		return _lName;
	}
};





