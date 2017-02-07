#include "RemoveGreenEffect.h"

using namespace std;

void RemoveGreenEffect::processImage(vector<Point>& points)
{
	for (int i = 0; i < points.size(); i++)
	{
		points[i].setGreen(0);
	}

	return;
}