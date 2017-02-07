#ifndef widgetFactory_h
#define widgetFactory_h
#include "widget.h"
#include "spring.h"
#include "actuator.h"
#include "gear.h"
#include "cog.h"
#include "device.h"
#include <iostream>

class widgetFactory
{
public:

	widgetFactory()
	{

	}
	

	widget* fromString(string text)
	{
		widget* x = NULL;
		
		if (text == "spring")
		{
			cout << "adding \"spring\" to device" << endl;
			spring* s = new spring();
			x = s;
		}

		else if (text == "actuator")
		{
			cout << "adding \"actuator\" to device" << endl;
			actuator* a = new actuator();
			x = a;
		}

		else if (text == "gear")
		{
			cout << "adding \"gear\" to device" << endl;
			gear * g = new gear();
			x = g;

		}
		else if (text == "cog")
		{
			cout << "adding \"cog\" to device" << endl;
			cog* c = new cog();
			x = c;
		}

		else
		{

			cout << "unregocnized widget " << text << " in parts list. Skipping" << endl;
			

		}

		

		return x;
	}


};



#endif