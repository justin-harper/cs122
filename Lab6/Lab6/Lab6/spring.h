#ifndef spring_h
#define spring_h
#include "widget.h"

class spring : public widget
{
public:

	spring()
	{
		_price = 0.99;
		_name = "spring";

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