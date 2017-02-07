#include "Point.h"

//class describing the pixles of an image
Point::Point(int red = 0, int green = 0, int blue = 0)
{
	_red = red;
	_green = green;
	_blue = blue;

	return;
}

#pragma region Getters
//returns the red value of the pixle
int Point::getRed() const
{
	return _red;

}
//returns the green value of the pixle
int Point::getGreen() const
{
	return _green;

}
//returns the blue value of the pixle
int Point::getBlue() const
{

	return _blue;
}

#pragma endregion

#pragma region Setters
//set the red value of the pixle
void Point::setRed(int red)
{
	_red = red;
	
	return;
}
//set the green value of the pixle
void Point::setGreen(int green)
{
	_green = green;

	return;
}
//set the blue value of the pixle
void Point::setBlue(int blue)
{
	_blue = blue;

	return;
}

#pragma endregion

//convert the pixle data to a string for output file
string Point::toString(void)
{

	return to_string(getRed()) + " " + to_string(getGreen()) + " " + to_string(getBlue());

}