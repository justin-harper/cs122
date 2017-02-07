#include "GreenScreenEffect.h"
#include <iostream>

using namespace std;





void GreenScreenEffect::processImage(vector<Point>& targetFile, vector<Point>& keyFile, Point key)
{
	for (int i = 0; i < targetFile.size(); i++)
	{
		if (keyFile[i].getRed() == key.getRed() && keyFile[i].getGreen() == key.getGreen() && keyFile[i].getBlue() == key.getBlue())
		{
			
			targetFile[i] = targetFile[i];
		}
		else
		{	
			cout << "switching" << endl;
			targetFile[i] = keyFile[i];
		}
		
	}

	return;
}