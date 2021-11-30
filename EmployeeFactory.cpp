// RUNTIME ERROR

#include "Employee.h"
#include "EmployeeFactory.h"
#include <string>
#include <iostream>
#include "Hourly.h"
#include "Piecework.h"
#include "Salary.h"

using namespace std;

// todo : if time, make less repetetive

// todo : switch order to match his order

Employee* EmployeeFactory::buildEmployee(string str, int date)
{
    // comma delimited
    // line format: type,id,payRate,payAmount,name
    // todo : add DailyTransaction files as dependencies in makefile

    // Declare dfields
    int id;
    string empType;
    double payRate;
    string name;
    string remainder;

    // todo : make less repetitive ? 

    // get EmpType
    empType = str.substr(0, str.find(","));
    remainder = str.substr(str.find(",") + 1);
 
    // get ID
    id = stoi(remainder.substr(0, str.find(",")));
    remainder = remainder.substr(remainder.find(",") + 1);
    
    cout << "ID: " << id << endl;
    
    // get payrate
    payRate = stod(remainder.substr(0, remainder.find(",")));
    remainder = remainder.substr(remainder.find(",") + 1);
    
    // get name
    
    name = remainder;

    if (empType == "hourly")
    {
        //type, id, payRate, name, lastDayWOrked, numConsecutive
        return new Hourly(empType, id, payRate, name, date, 1);
    }

    else if (empType == "piecework")
    {
        // string employeeType, int id, double payRate, string name
        return new Piecework(empType, id, payRate, name);
    }

    else if (empType == "salary")
    {
        // string employeeType, int id, double payRate, string name, int firstDay, int lastDay
        return new Salary(empType, id, payRate, name, date, -1);
    }

    else if (empType == "commission")
    {
        // todo : write commission and return new commission employee
        return nullptr;
    }

    else
    {
        return nullptr;
    }
}



Employee* EmployeeFactory::insertEmployee(string str)
{
    // space delimited
    // line format: TYPE id payRate payAmount terminated [numDaysWOrked] name

    // Declare dfields
    int id, terminated, date;
    string empType;
    double payRate;
    double payAmount;
    string name;
    string remainder;
    int numConsecutive = -1;

    // get EmpType
    empType = str.substr(0, str.find(" "));
    remainder = str.substr(str.find(" ") + 1);
    
    // get id
    id = stoi(remainder.substr(0, str.find(" ")));
    remainder = remainder.substr(str.find(" ") + 1);
    
    // get payrate
    payRate = stod(remainder.substr(0, remainder.find(" ")));
    remainder = remainder.substr(remainder.find(" ") + 1);

    // get payAmount
    payAmount = stod(remainder.substr(0, remainder.find(" ")));
    remainder = remainder.substr(remainder.find(" ") + 1);
    
    // get terminated
    terminated = stoi(remainder.substr(0, remainder.find(" ")));
    remainder = remainder.substr(remainder.find(" ") + 1);

    if (empType == "hourly")
    {
        numConsecutive = stoi(remainder.substr(0, remainder.find(" ")));
        remainder = remainder.substr(remainder.find(" ") + 1);
    }
    
    name = remainder;
    
    if (empType == "hourly")
    {
       //type, id, payRate, name, lastDayWOrked, numConsecutive
        return new Hourly(empType, id, payRate, name, -1, numConsecutive);
    }

    else if (empType == "piecework")
    {
        // string employeeType, int id, double payRate, string name
        return new Piecework(empType, id, payRate, name);
    }

    else if (empType == "commission")
    {
        return nullptr;
    }

    else if (empType == "salary")
    {
        // string employeeType, int id, double payRate, string name, int firstDay, int lastDay
        return new Salary(empType, id, payRate, name, date, -1);
    }

}




