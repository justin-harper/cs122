/*
Assignment: 4

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 4hrs

In completing this program, I received help from the following people:
myself

version 1.0 (major relese) I am happy with this version!
*/


#ifndef Point_h
#define Point_h

#include <string>

using namespace std;

class Point
{
private:
	int _red;
	int _green;
	int _blue;


public:
	Point(int red, int green, int blue);
	
	int getRed() const;
	int getGreen() const;
	int getBlue() const;

	void setRed(int red);
	void setGreen(int green);
	void setBlue(int blue);


	string toString(void);


};





#endif