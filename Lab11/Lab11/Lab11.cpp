#include "Lab11.h"

#include <iostream>


std::string getInput()
{
	std::string in = "";

	std::cout << "Please enter an expression to validate: ";
	std::getline(std::cin, in);

	return in;
}