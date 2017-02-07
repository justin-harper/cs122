#pragma once

#include <string>

class Customer
{
private:
	
	int _customerID;
	int _arrivalTime;
	int _serviceTime;
	int _departureTime;

	static int idCounter;

	std::string _lineName;

public:
	Customer();
	Customer(int arrivalTime, std::string lineName, int id);

	Customer* generateCustomer(int arrivalTime, std::string lineName);

	int getTotalWaitTime();




};