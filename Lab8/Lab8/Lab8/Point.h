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