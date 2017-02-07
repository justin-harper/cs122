#ifndef device_h
#define device_h
#include "widget.h"
#include "gear.h"
#include <iostream>


class device
{
private:
	
	//widget** _components;

	widget* _components [100];
	int _componentCounter = 0;


public:

	device()
	{


	}

	~device()
	{
		//delete _components;
	}

	void addWidget(widget* w)
	{
		if (w != NULL)
		{

			_components[_componentCounter] = w;
			_componentCounter++;
		}
		return;
	}

	double getTotalPrice() const
	{
		double price = 0.0;

		

		

		for (int i = 0; i < _componentCounter; i++)
		{
			price += _components[i]->getPrice();
		}

		return price;

	}



};

#endif