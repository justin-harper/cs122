/*
Assignment: 4

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 4hrs

In completing this program, I received help from the following people:
myself

version 1.0 (major relese) I am happy with this version!
*/


#ifndef SimpleImageEffect_h
#define SimpleImageEffect_h

#include <vector>
#include "Point.h"

using namespace std;

class SimpleImageEffect
{
public:
	
	

	virtual ~SimpleImageEffect() {};

	virtual void processImage(vector<Point>& points) = 0;


};




#endif