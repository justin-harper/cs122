/*
Assignment: 4

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 4hrs

In completing this program, I received help from the following people:
myself

version 1.0 (major relese) I am happy with this version!
*/

#ifndef RemoveRedEffect_h
#define RemoveRedEffect_h

#include "SimpleImageEffect.h"
#include "Point.h"

#include <vector>

class RemoveRedEffect : public SimpleImageEffect
{
public:

	RemoveRedEffect()
	{

	}

	~RemoveRedEffect() {};

	virtual void processImage(vector<Point>& points);


};




#endif