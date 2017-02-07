#pragma region Includes

#include "SimpleImageEffect.h"
#include "Point.h"
#include "StringSplitter.h"

#include "RemoveRedEffect.h"
#include "RemoveGreenEffect.h"
#include "RemoveBlueEffect.h"

#include "NegateRed.h"
#include "NegateGreen.h"
#include "NegateBlue.h"

#include "AddRandomNoise.h"
#include "HighContrast.h"
#include "GreyScale.h"

#include "userInterface.h"



#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#pragma endregion


using namespace std;
//just a simple user interface function that returns an int "userChoice"
int userInterface(void)
{
	string choice = "";
	int userChoice = 0;
	bool invalidInput = true;

	while (invalidInput)
	{


		std::cout << "Please chose from the following list of image options:" << endl;
		std::cout << "1.  Remove red effect" << endl;
		std::cout << "2.  Remove green effect" << endl;
		std::cout << "3.  Remove blue effect" << endl;
		std::cout << "4.  Negate red effect" << endl;
		std::cout << "5.  Negate green effect" << endl;
		std::cout << "6.  Negate blue effect" << endl;
		std::cout << "7.  Add random noise" << endl;
		std::cout << "8.  Convert to greyscale" << endl;
		std::cout << "9.  Convert to high contrast" << endl;
		std::cout << "10. Flip image horizanatly" << endl;
		std::cout << "11. Flip image vertically" << endl;
		std::cout << "12. Exit" << endl;

		getline(cin, choice);

		
		//found a "better" way to parse the string into an int
		stringstream stream(choice);

		if (stream >> userChoice)
		{
			
			break;
		}
		std::cout << "Invalid input please try again" << endl;
		invalidInput = false;
	}

	std::cout << "You enterd: " << userChoice << endl;
	std::cout << endl;

	if (userChoice == 0)
	{
		//just in case the value is not actually set
		throw invalid_argument("invalid userinput");
	}
	
	return userChoice;
}


