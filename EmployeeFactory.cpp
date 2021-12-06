#include "Employee.h"
#include "EmployeeFactory.h"
#include <string>
#include <iostream>
#include "Hourly.h"
#include "Piecework.h"
#include "Salary.h"
#include "Commission.h"

using namespace std;

int parseInt(string delimiter)
{
	int a = stoi(myStr.substr(0, myStr.find(delimiter)));
	advance(delimiter);
	return a;
}

double parseDouble(string delimiter)
{
	double a = stod(myStr.substr(0, myStr.find(delimiter)));
	advance(delimiter);
	return a;
}

string parseString(string delimiter)
{
	string a = myStr.substr(0, myStr.find(delimiter));
	advance(delimiter);
	return a;
}

void advance(delimiter)
{
	myStr = myStr.substr(myStr.find(delimiter) + 1);
}


Employee* constructEmployee(int id, string name, string type, double payRate, double payAmount, bool terminated, int numConsecutive, int date)
{
	Employee* e;
	int exception = 10;

	switch (empType)
	{
		case "hourly":
			if (payRate < 10 || payRate > 26)
			{
				throw exception;
			}

        	e = new Hourly(empType, id, payRate, name, date, numConsecutive);

			break;

		case "piecework":
			if (payRate < 0 || payRate > 1)
			{
				throw 10;
			}

		    e = new Piecework(empType, id, payRate, name);

			break;

		case "salary":
			if(!(payRate >= 4000))
			{
				throw 10;
			}
		    e = new Salary(empType, id, payRate, name, date, -1);

			if (!terminated) e->calculatePayroll(date, -1);

		    break;

		case "commission":

			if (payRate < .03 || payRate > .05)
			{
				throw 10;
			}
		    e = new Commission(empType, id, payRate, name);

			break;
		
		case default:
			throw 11;
	}

	e->setTerminated(terminated);
	if (payAmount != -1) e->setPayAmount(payAmount);

	return e;
}


Employee* EmployeeFactory::buildEmployeeFromDaily(string str, int date)
{
    // comma delimited
    // line format: id, name, type, payRate
    // todo : add DailyTransaction files as dependencies in makefile

	myStr = str;

    int id = parseInt(",");
	string name = parseString(",");
    string empType = parseString(",");
    double payRate = stod(myStr)

	return constructEmployee(id, name, emptype, payRate, -1, 0, 1, date);
}


Employee* EmployeeFactory::buildEmployeeFromMaster(string str)
{
    // space delimited
    // line format: TYPE id payRate payAmount terminated [numDaysWOrked] name

    // Declare dfields
	myStr = str;
    int numConsecutive = 1;

    string empType = parseString(" ");
    int id = parseInt(" ");
    double payRate = parseDouble(" ");
    double payAmount = parseDouble(" ");
    int terminated = parseInt(" ");

    if (empType == "hourly")
    {
        numConsecutive = parseInt(" ");
    }
    
    name = myStr;

    return constructEmployee(id, name, emptype, payRate, payAmount, terminated, numConsecutive, 1);

}


