#include "Hourly.h"
#include <string>

// todo : delete these lines
#include <iostream>
using namespace std;
//type, id, payRate, name
Hourly::Hourly(string employeeType, int id, double payRate, string name, int lastDayWorked, int numConsecutive)
{
	this->employeeType = employeeType;
	this->id = id;
	this->payRate = payRate;
	this->name = name;

	this->payAmount = 0;
	this->terminated = false;

	this->lastDayWorked = lastDayWorked;
	this->numConsecutive = numConsecutive;

    cout << "In hourly" << endl;
}

Hourly::~Hourly()
{
	
}

void Hourly::calculatePayroll(int day, double hours)
{
	if(lastDayWorked == day - 1)
	{
		numConsecutive++;
	}
	else
	{
		numConsecutive = 1;	
	}
    lastDayWorked = day;

	int multiplier = 1;
	if(numConsecutive >= 6)
	{
		multiplier = 2;
	}	

	if(hours >= 8)
	{
		payAmount += (hours - 8) * multiplier * .5 * payRate;
	}
	payAmount += hours * payRate * multiplier;
}

//HOURLY [id] [payRate] [payAmount] [terminated] [numDaysWorked] [name]
string Hourly::toString()
{
	string fields = "";
	fields += "hourly " + to_string(id) + " " + to_string(payRate) + " " + to_string(payAmount) + " ";

	if(terminated)
	{
		fields += "1 ";
	}
	else
	{
		fields += "0 ";	
	}

	if(lastDayWorked != 30)
	{
		numConsecutive = 0;
	}

	fields += to_string(numConsecutive) + " ";

	fields += name;

	return fields;
}
