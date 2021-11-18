#include <string>
#include <iostream>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

using namespace std;

class Employee
{
protected:
    int id;
    string name;
    string payType;
    double payAmount;
    int startDate = -1;
    int endDate = -1;

public:
    Employee();
    ~Employee();
    
    virtual void calculatePayroll() = 0;
    
    virtual void toString() = 0;
    
};

#endif
