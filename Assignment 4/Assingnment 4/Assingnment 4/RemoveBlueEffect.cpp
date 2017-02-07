/*
Assignment: 4

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 4hrs

In completing this program, I received help from the following people:
myself

version 1.0 (major relese) I am happy with this version!
*/

#include "RemoveBlueEffect.h"

using namespace std;

//class to remove blue from the image
void RemoveBlueEffect::processImage(vector<Point>& points)
{

	//pretty stright forward just set the blue value of each pixle to 0
	for (int i = 0; i < points.size(); i++)
	{
		points[i].setBlue(0);
	}

	return;
}