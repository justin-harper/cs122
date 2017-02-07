#include "widget.h"
#include "cog.h"
#include "gear.h"
#include "actuator.h"
#include "spring.h"
#include "device.h"
#include "widgetFactory.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>


using namespace std;

int main(void)
{
	
	string line = "";
	ifstream myfile("text.txt");
	widgetFactory wf{};
	device myDevice{};
	double price = 0.0;


	while (getline(myfile, line))
	{
		myDevice.addWidget( wf.fromString(line));
	}

	cout << endl << "Device creation complete" << endl;

	price = myDevice.getTotalPrice();

	cout << "Total cost: " << price << endl;


	

	



	return 0;
}