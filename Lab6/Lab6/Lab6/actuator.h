#ifndef actuator_h
#define actuator_h
#include "widget.h"

class actuator : public widget
{
public:

	actuator()
	{
		_price = 3.50;
		_name = "actuator";

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