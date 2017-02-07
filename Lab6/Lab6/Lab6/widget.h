#ifndef widget_h
#define widget_h

#include <string>

using namespace std;

class widget
{
public:

	virtual double getPrice() const = 0;
	virtual string getName() const = 0;


protected:
	double _price;
	string _name;
};


#endif