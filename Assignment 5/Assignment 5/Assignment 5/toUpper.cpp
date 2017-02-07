#include "toUpper.h"

std::string toUpper(std::string toChange)
{
	std::string up = "";
	for (unsigned int i = 0; i < toChange.size(); i++)
	{
		char temp = toChange[i];

		if (temp >= 'a' && temp <= 'z')
		{
			temp = temp - 'a' + 'A';
		}

		up.push_back(temp);
	}

	return up;
}
