#include "Employee.h"
#include <string>

#ifndef HOURLY_H
#define HOURLY_H

class Hourly : public virtual Employee
{
private:
    double payRate;
    int hours;
    int lastDayWorked;

public:
    // ID, payRate, name, hireDate, endDate
    Hourly(int, double, string, int, int);
    ~Hourly();
    
    void addHours(int);

    void calculatePayroll();
};

#endif // HOURLY_H
