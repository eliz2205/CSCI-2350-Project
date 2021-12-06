

#ifndef EMPLOYEEFACTORY_H
#define EMPLOYEEFACTORY_H

#include "Employee.h"
#include <string>

class EmployeeFactory
{
private:
	string myStr;

public:
    // line: ID, type, payRate, name
    static Employee* buildEmployee(string, int);

    static Employee* insertEmployee(string);
};

#endif
