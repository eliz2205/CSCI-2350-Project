#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;

class Employee
{	
protected:
	string employeeType;
	int id;
	double payRate;
	string name;
	double payAmount;
	bool terminated;

public:
	virtual void calculatePayroll(int, double) = 0;

	virtual string toString() = 0;

	int getId()
	{
		return id;
	}
};

#endif
