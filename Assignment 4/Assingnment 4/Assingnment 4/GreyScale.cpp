/*
Assignment: 4

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 4hrs

In completing this program, I received help from the following people:
myself

version 1.0 (major relese) I am happy with this version!
*/


#include "GreyScale.h"

using namespace std;

//convert image to grey scale
void GreyScale::processImage(vector<Point>& points)
{
	for (int i = 0; i < points.size(); i++)
	{

		int red		= points[i].getRed();
		int green	= points[i].getGreen();
		int blue	= points[i].getBlue();

		int average = ((red + green + blue) / (3)); //integer division
		//follows the algorythm provided in the description
		points[i].setRed(average);
		points[i].setGreen(average);
		points[i].setBlue(average);

	}

	return;
}