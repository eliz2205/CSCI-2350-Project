#include "Employee.h"
#include "EmployeeFactory.h"
#include <string>
#include <iostream>
#include "Hourly.h"
#include "Piecework.h"
#include "Salary.h"
#include "Commission.h"

using namespace std;

int EmployeeFactory::parseInt(string delimiter, string myStr)
{
	int a = stoi(myStr.substr(0, myStr.find(delimiter)));

	return a;
}

double EmployeeFactory::parseDouble(string delimiter, string myStr)
{
	double a = stod(myStr.substr(0, myStr.find(delimiter)));

	return a;
}

string EmployeeFactory::parseString(string delimiter, string myStr)
{
	string a = myStr.substr(0, myStr.find(delimiter));

	return a;
}

string EmployeeFactory::advance(string delimiter, string myStr)
{
	return myStr.substr(myStr.find(delimiter) + 1);
}


Employee* EmployeeFactory::constructEmployee(int id, string name, string empType, double payRate, double payAmount, bool terminated, int numConsecutive, int date)
{
	Employee* e;

	if (empType == "hourly")
	{
		if (payRate < 10 || payRate > 26) throw 10;

        e = new Hourly(empType, id, payRate, name, date, numConsecutive);
	}

	else if (empType == "piecework")
	{
		if (payRate < 0 || payRate > 1) throw 10;

		e = new Piecework(empType, id, payRate, name);
	}

	else if (empType == "salary")
	{
		if(!(payRate >= 4000)) throw 10;

		e = new Salary(empType, id, payRate, name, date, -1);
		

		if (!terminated) e->calculatePayroll(date, -1);
	}

	else if (empType == "commission")
	{
		if (payRate < .03 || payRate > .05) throw 10;

		e = new Commission(empType, id, payRate, name);
	}
		
	else
	{
		throw 10;
	}

	e->setTerminated(terminated);
	if (payAmount != -1) e->setPayAmount(payAmount);

	return e;
}


Employee* EmployeeFactory::buildEmployeeFromDaily(string str, int date)
{
    // comma delimited
    // line format: id, name, type, payRate

    int id = parseInt(",", str);
	str = advance(",", str);
	string name = parseString(",", str);
	str = advance(",", str);
    string empType = parseString(",", str);
	str = advance(",", str);
    double payRate = stod(str);

	return constructEmployee(id, name, empType, payRate, -1, 0, 1, date);
}


Employee* EmployeeFactory::buildEmployeeFromMaster(string str)
{
    // space delimited
    // line format: TYPE id payRate payAmount terminated [numDaysWOrked] name

    // Declare dfields
    int numConsecutive = 1;

    string empType = parseString(" ", str);
	str = advance(" ", str);
    int id = parseInt(" ", str);
	str = advance(" ", str);
    double payRate = parseDouble(" ", str);
	str = advance(" ", str);
    double payAmount = parseDouble(" ", str);
	str = advance(" ", str);
    int terminated = parseInt(" ", str);
	str = advance(" ", str);

    if (empType == "hourly")
    {
        numConsecutive = parseInt(" ", str);
		str = advance(" ", str);
    }
    
    string name = str;

    return constructEmployee(id, name, empType, payRate, payAmount, terminated, numConsecutive, 1);

}


