#include "Customer.h"

Customer::Customer()
{
	_customerID = 0;
	_arrivalTime = 0;
	_serviceTime = 0;
	_departureTime = 0;

}

Customer::Customer(int arrivalTime, std::string lineName, int id)
{
	_arrivalTime = arrivalTime;
	_lineName = lineName;
	_customerID = id;


}

Customer* Customer::generateCustomer(int arrivalTime, std::string lineName)
{
	Customer j{arrivalTime, lineName}
}