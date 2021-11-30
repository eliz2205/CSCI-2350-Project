#include "Employee.h"
#include "EmployeeFactory.cpp"
#include <string>
#include <iostream>
#include "Hourly.h"
#include "Piecework.h"
#include "Commission.h"
#include "Salary.h"

using namespace std;


static Employee* EmployeeFactory::buildEmployee(string str, int date)
{
    // comma delimited
    // line format: TYPE,id,payRate,payAmount, terminated,[numDaysWorked],name

    // Declare dfields
    int id;
    string empType;
    double payRate;
    string name;
    string remainder;
    int daysWorked = 0;

    // get EmpType
    empType = str.substr(0, remainder.find(","));
    remainder = remainder.substr(remainder.find(",") + 1);
    
    // get ID
    id = stoi(remainder.substr(0, str.find(",")));
    remainder = remainder.substr(str.find(",") + 1);
    
    // get payrate
    payRate = stod(remainder.substr(0, remainder.find(",")));
    remainder = remainder.substr(remainder.find(",") + 1);

    // skip payAmount
    remainder = remainder.substr(remainder.find(",") + 1);
    
    // skip terminated
    remainder = remainder.substr(remainder.find(",") + 1);

    // get numdaysworked if hourly
    if (empType.compare("hourly"))
    {
        daysWorked = stoi(remainder.substr(0, remainder.find(",")));
        remainder = remainder.substr(remainder.find(",") + 1);
    }
    
    // get name
    name = remainder;

    if (empType.compare("hourly"))
    {
        //type, id, payRate, name, lastDayWOrked, numDaysWorked
        return new Hourly(empType, id, payRate, name, date, daysWorked);
    }

    else if (empType.compare("piecework"))
    {
        return new Piecework(empType, id, payRate, name);
    }

    else if (empType.compare("commission"))
    {
        return new Commission(empType, id, payRate, name);
    }

    else if (empType.compare("salary"))
    {
        // string employeeType, int id, double payRate, string name, int firstDay, int lastDay
        return new Salary(empType, id, payRate, name, date, -1);
    }
}
static Employee* EmployeeFactory::insertEmployee(string str)
{
// space delimited
    // line format: TYPE name payRate payAmount terminated [numDaysWorked] id

    // Declare dfields
    int id;
    string empType;
    double payRate;
    string name;
    string remainder;
    int daysWorked = 0;

    // get EmpType
    empType = str.substr(0, remainder.find(" "));
    remainder = remainder.substr(remainder.find(" ") + 1);
    
    // get id
    id = stoi(remainder.substr(0, str.find(" ")));
    remainder = remainder.substr(str.find(" ") + 1);
    
    // get payrate
    payRate = stod(remainder.substr(0, remainder.find(" ")));
    remainder = remainder.substr(remainder.find(" ") + 1);

    // skip payAmount
    remainder = remainder.substr(remainder.find(" ") + 1);
    
    // skip terminated
    remainder = remainder.substr(remainder.find(" ") + 1);

    if (empType.compare("hourly"))
    {
        daysWorked = stoi(remainder.substr(0, remainder.find(",")));
        remainder = remainder.substr(remainder.find(",") + 1);
    }
    
    name = remainder;
    
    if (empType.compare("hourly"))
    {
        //type, id, payRate, name, lastDayWOrked, numDaysWorked
        return new Hourly(empType, id, payRate, name, date, daysWorked);
    }

    else if (empType.compare("piecework"))
    {
        return new Piecework(empType, id, payRate, name);
    }

    else if (empType.compare("commission"))
    {
        return new Commission(empType, id, payRate, name);
    }

    else if (empType.compare("salary"))
    {
        // string employeeType, int id, double payRate, string name, int firstDay, int lastDay
        return new Salary(empType, id, payRate, name, date, -1);
    }

}


