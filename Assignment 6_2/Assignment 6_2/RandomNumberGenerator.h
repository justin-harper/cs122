#pragma once


/*
Justin Harper
10696738

version 1.0
*/


#include <cstdlib>
#include <ctime>


using namespace std;
class RandomNumberGenerator
{
public:
	RandomNumberGenerator(int seed = NULL)
	{
		//use time to randomize seed
		if (seed == NULL)
		{
			srand(time(NULL));
		}
		else
		{
			//else, use the supplied seed
			srand(seed);
		}
	}
	int getRandomNumber(int min_value = 0, int max_value = RAND_MAX) const
	{
		if (max_value == 0)
		{
			getRandomNumber(0, 1);
		}
		else
		{

			int next_number = (rand() % max_value) + min_value;
			return next_number;
		}
	}
};

