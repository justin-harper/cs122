#include "CheckoutSimFunctions.h"

/*
Justin Harper
10696738

version 1.0
*/



int getCheckLanes()
{
		int userInput = 0;
		std::string input = "";
		bool Valid = false;


		while (!Valid)
		{
			std::system("cls");
			std::cout << "*****[ WELCOME TO COUGAR MART SIMULATOR ]*****" << std::endl
				<< "How many checkstands would you like to simulate: " << std::endl;

			std::getline(std::cin, input);
			std::stringstream stream{ input };

			if (stream >> userInput)
			{
				if (userInput >= 1)
				{
					Valid = !Valid;
				}
				else
				{
					std::cout << "Input must be greater than 0" << std::endl;
					std::system("pause");
				}
			}
			else
			{
				std::cout << "invalid input please try again ;(" << std::endl;
			}




		}
		std::cout << "You entered: " << userInput << std::endl;
		std::system("pause");
	
	
	return userInput;
}

int getRandBound()
{
	int userInput;

	std::string input = "";

	bool Valid = false;


	while (!Valid)
	{
		std::system("cls");
		std::cout << "Please enter the max service time (rand upper bound)" << std::endl;

		std::getline(std::cin, input);
		std::stringstream stream{ input };

		if (stream >> userInput)
		{
			if (userInput >= 1)
			{
				Valid = !Valid;
			}
			else
			{
				std::cout << "Input must be greater than 0" << std::endl;
				std::system("pause");
			}
		}
		else
		{
			std::cout << "invalid input please try again ;(" << std::endl;
		}




	}
	std::cout << "You entered: " << userInput << std::endl;
	std::system("pause");
	return userInput;

}





