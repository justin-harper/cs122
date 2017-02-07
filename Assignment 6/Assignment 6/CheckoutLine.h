#pragma once

#include <vector>
#include <queue>
#include <string>

#include "Customer.h"



class CheckoutLine
{
private:

	std::string _lineName;
	int _tickCount;
	std::queue<Customer> _line;

	std::queue<Customer> _servedCustomers;

public:

	std::string getLineName();
	bool isEmpty();
	void addCustomer(Customer aCustomer);
	std::vector<Customer>& getServicedCustomers();

	void tick();




};