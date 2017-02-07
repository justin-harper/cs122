#ifndef gear_h
#define gear_h
#include "widget.h"

class gear : public widget
{
public:
	gear()
	{
		_price = 1.25;
		_name = "gear";

	}

	virtual string getName() const override
	{
		return _name;
	}

	virtual double getPrice() const override
	{
		return _price;
	}


};




#endif