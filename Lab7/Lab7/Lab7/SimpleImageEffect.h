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