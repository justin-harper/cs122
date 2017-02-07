/*
Assignment: 4

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 4hrs

In completing this program, I received help from the following people:
myself

version 1.0 (major relese) I am happy with this version!
*/


#include "AddRandomNoise.h"
#include <time.h>

using namespace std;

//class to add random noise proccesor
void AddRandomNoise::processImage(vector<Point>& points)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < points.size(); i++)
	{
		//follows algorythym described in assignment description

		int noise = rand() % 20 - 10;
		int red = points[i].getRed();
		int green = points[i].getGreen();
		int blue = points[i].getBlue();

		red += noise;
		green += noise;
		blue += noise;

		if (red <= 0)
		{
			red = 0;
		}
		if (green <= 0)
		{
			green = 0;
		}
		if (blue <= 0)
		{
			blue = 0;
		}

		if (red > 255)
		{
			red = 255;
		}
		if (green > 255)
		{
			green = 255;
		}
		if (blue > 255)
		{
			blue = 255;
		}


		//after checking the values assinge them to the vector
		points[i].setRed(red);
		points[i].setGreen(green);
		points[i].setBlue(blue);


	}

	return;
}