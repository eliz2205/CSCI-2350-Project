#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;

class Employee
{
private:
    int id;
    string name;
    string payType;
    double payAmount;

public:
    virtual void calculatePayroll() = 0;
    
    void printPaycheck() { cout << payAmount << endl; }
    
};

#endif
