#ifndef COMMISSION_H
#define COMMISSION_H

#include "Employee.h"

class Commission : public virtual Employee
{
private:
    double salesPct;
    double sales;

public:
    Commission(string, double, double);
    ~Commission();

    void calculatePayroll();
};

#endif
// toString: type id name, need constructor for each type that takes string as parameter
// handle names with multiple spaces/middle names
// need getID function in each object to return ID
