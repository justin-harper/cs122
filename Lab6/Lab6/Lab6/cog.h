#ifndef cog_h
#define cog_h
#include "widget.h"

class cog : public widget
{
public:

	cog()
	{
		_price = 1.35;
		_name = "cog";

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