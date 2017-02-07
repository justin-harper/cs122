#include <string>

#include <iostream>


using namespace std;

int main(void)
{

	double t = 0.0;

	string x = "thre";

	try
	{

		t = stod(x);
	}
	catch (...)
	{
		cout << "error" << endl;
	}

	cout << t << endl;


	return 0;
}