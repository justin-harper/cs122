#ifndef Employee_h
#define Employee_h

#include <string>

using namespace std;


class Employee
{
public:
	Employee();
	Employee(string name, int id, bool isWorking);

	string getName() const;
	void setName(string name);

	int getEID() const;
	void setEID(int id);

	bool isWorking() const;
	void setStatus(bool employed);
	string toString();


private:
	string _employeeName;
	int _employeeId;
	bool _isWorking;

protected:
	string boolstring(bool x);


};




#endif