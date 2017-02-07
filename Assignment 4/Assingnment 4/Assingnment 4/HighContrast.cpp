/*
Assignment: 4

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 4hrs

In completing this program, I received help from the following people:
myself

version 1.0 (major relese) I am happy with this version!
*/

#include "HighContrast.h"

using namespace std;

//class to convert image to highcontrast
void HighContrast::processImage(vector<Point>& points)
{

	//follows algorthym oovided in descrpiton
	for (int i = 0; i < points.size(); i++)
	{
		
		if (points[i].getRed() > (255 / 2))
		{
			points[i].setRed(255);
		}

		if (points[i].getGreen() > (255 / 2))
		{
			points[i].setGreen(255);
		}

		if (points[i].getBlue() > (255 / 2))
		{
			points[i].setBlue(255);
		}


	}

	return;
}