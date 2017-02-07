/*
Assignment: 4

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 4hrs

In completing this program, I received help from the following people:
myself

version 1.0 (major relese) I am happy with this version!
*/

#ifndef FlipHorzantal_h
#define FlipHorzantal_h

#include "SimpleImageEffect.h"
#include <vector>
#include "Point.h"




class FlipHorzantal : public SimpleImageEffect
{

public:

	virtual ~FlipHorzantal()
	{

	};

	FlipHorzantal()
	{

	}

	virtual void processImage(vector<Point>& points);

	

};



#endif