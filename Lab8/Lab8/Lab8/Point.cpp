#include "Point.h"

Point::Point(int red = 0, int green = 0, int blue = 0)
{
	_red = red;
	_green = green;
	_blue = blue;

	return;
}

#pragma region Getters
int Point::getRed() const
{
	return _red;

}

int Point::getGreen() const
{
	return _green;

}

int Point::getBlue() const
{

	return _blue;
}

#pragma endregion

#pragma region Setters
void Point::setRed(int red)
{
	_red = red;
	
	return;
}
void Point::setGreen(int green)
{
	_green = green;

	return;
}
void Point::setBlue(int blue)
{
	_blue = blue;

	return;
}

#pragma endregion


string Point::toString(void)
{

	return to_string(getRed()) + " " + to_string(getGreen()) + " " + to_string(getBlue());

}