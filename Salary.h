

#ifndef SALARY_H
#define SALARY_H

#include "Employee.h"
#include <string>
#include <iostream>

using namespace std;

class Salary : public Employee
{
private:
	int firstDay;
	int lastDay;
public:
	//type, id, payRate, name
	Salary(string, int, double, string, int, int);
	~Salary();

	void calculatePayroll(int, double);
	string toString();
};

#endif
