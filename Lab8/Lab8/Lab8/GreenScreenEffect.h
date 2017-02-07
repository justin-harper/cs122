#ifndef GreenScreenEffect_h
#define GreenScreenEffect_h

#include "SimpleImageEffect.h"
#include "Point.h"

#include <vector>

class GreenScreenEffect : public SimpleImageEffect 
{
public:

	GreenScreenEffect()
	{

	}

	~GreenScreenEffect() {};

	virtual void processImage(vector<Point>& targetFile, vector<Point>& keyFile, Point key);
	virtual void processImage(vector<Point>& points)
	{

	}


};




#endif