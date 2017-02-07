/*
Assignment: 4

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 4hrs

In completing this program, I received help from the following people:
myself

version 1.0 (major relese) I am happy with this version!
*/

#include "FlipHorzantal.h"
#include <iostream>


void FlipHorzantal::processImage(vector<Point>& points)
{
	//just some notes to remember what the parameters of the file are
	//pix1 = width
	//pix2 = height

	vector<Point> flipped;

	
	system("pause");

	//just print pixles in reverese
	for (int i = points.size()-1; i > 0; i--)
	{
		flipped.push_back(points[i]);
	}

	points = flipped;

}

