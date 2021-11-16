#include "Employee.h"
#include <string>

#ifndef HOURLY_H
#define HOURLY_H

class Hourly : public virtual Employee
{
private:
    double payRate;
    int hours;

public:
    Hourly(int, double, string);
    ~Hourly();

    void calculatePayroll();
};

#endif // HOURLY_H
