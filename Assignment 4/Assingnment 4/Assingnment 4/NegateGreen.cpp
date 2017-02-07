/*
Assignment: 4

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 4hrs

In completing this program, I received help from the following people:
myself

version 1.0 (major relese) I am happy with this version!
*/


#include "NegateGreen.h"

using namespace std;


//image processor to negate green
void NegateGreen::processImage(vector<Point>& points)
{
	//pretty stright forward just set the green value of each pixle to 255 - green value
	for (int i = 0; i < points.size(); i++)
	{
		points[i].setGreen(255 - points[i].getGreen());
	}

	return;
}