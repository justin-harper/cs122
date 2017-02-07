/*
Assignment: 4

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 4hrs

In completing this program, I received help from the following people:
myself

version 1.0 (major relese) I am happy with this version!
*/

#ifndef NegateRed_h
#define NegateRed_h

#include "SimpleImageEffect.h"
#include "Point.h"

#include <vector>

class NegateRed : public SimpleImageEffect
{
public:

	NegateRed()
	{

	}

	~NegateRed() {};

	virtual void processImage(vector<Point>& points);


};






#endif