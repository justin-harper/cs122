#ifndef RemoveGreenEffect_h
#define RemoveGreenEffect_h

#include "SimpleImageEffect.h"
#include "Point.h"

#include <vector>

class RemoveGreenEffect : public SimpleImageEffect 
{
public:

	RemoveGreenEffect()
	{

	}

	~RemoveGreenEffect() {};

	virtual void processImage(vector<Point>& points);


};




#endif