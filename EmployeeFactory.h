

#ifndef EMPLOYEEFACTORY_H
#define EMPLOYEEFACTORY_H

#include "Employee.h"
#include <string>

class EmployeeFactory
{
public:
    // line: ID, type, payRate, name
    static Employee* buildEmployee(string, int);

    static Employee* insertEmployee(string);
};

#endif
