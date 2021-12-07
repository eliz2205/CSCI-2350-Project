#include "Commission.h"
#include <string>

// todo : delete these
#include <iostream>
using namespace std;

Commission::Commission(string employeeType, int id, double payRate, string name)
{
	this->employeeType = employeeType;
	this->id = id;
	this->payRate = payRate;
	this->name = name;

	this->payAmount = 0;
	this->terminated = false;

	this->sales = 0;
}

Commission::~Commission()
{

}

/*
totalSales * commissionRate
1% bonus on sales over 10,000
for sales over 100,000: 1.5% bonus
*/

void Commission::calculatePayroll(int day, double lastDay)
{
	payAmount = sales * payRate;

    if (sales > 100000)
    {
        payAmount += (sales - 100000) * .005;
    }

    if (sales > 10000)
    {
        payAmount += (sales - 10000) * .01;
    }
}

//SALARY  [id] [payRate] [payAmount] [terminated] [name]
string Commission::toString()
{
	string fields = "";
	fields += "commission " + to_string(id) + " " + to_string(payRate) + " " + to_string(payAmount) + " ";

	if(terminated)
	{
		fields += "1 ";
	}
	else
	{
		fields += "0 ";	
	}

	fields += name;

	return fields;
}
