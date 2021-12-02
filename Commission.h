

#ifndef COMMISSION_H
#define COMMISSION_H

#include "Employee.h"

class Commission : public virtual Employee
{
private:
    double sales;

public:
    Commission(string, int, double, string);
    ~Commission();

    void calculatePayroll(int, double);

    string toString();
};

#endif

