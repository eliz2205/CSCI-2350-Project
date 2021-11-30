

#ifndef PIECEWORK_H
#define PIECEWORK_H

#include "Employee.h"
#include <string>
#include <iostream>

using namespace std;

class Piecework : public Employee
{
public:
	//type, id, payRate, name
	Piecework(string, int, double, string);
	~Piecework();

	void calculatePayroll(int, double);
	string toString();
};

#endif
