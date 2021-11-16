#include "Employee.h"
#include <string>

#ifndef SALARY_H
#define SALARY_H

class Salary : public virtual Employee
{
private:
    int basePay;

public:
    Salary(string, int, int);
    ~Salary();

    void calculatePayroll();
};

#endif // SALARY_H
