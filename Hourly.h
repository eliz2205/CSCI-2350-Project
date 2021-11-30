

#ifndef HOURLY_H
#define HOURLY_H

#include "Employee.h"
#include <string>
#include <iostream>

using namespace std;

class Hourly : public Employee
{
private:
	int lastDayWorked;
	int numConsecutive;
public:
	//type, id, payRate, name, lastDayWOrked, numConsecutive
	Hourly(string, int, double, string, int, int);
	~Hourly();

	void calculatePayroll(int, double);
	string toString();
};

#endif
