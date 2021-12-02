#include "Salary.h"
#include <string>

// todo : delete these
#include <iostream>
using namespace std;

//type, id, payRate, name
Salary::Salary(string employeeType, int id, double payRate, string name, int firstDay, int lastDay)
{
	this->employeeType = employeeType;
	this->id = id;
	this->payRate = payRate;
	this->name = name;

	this->payAmount = 0;
	this->terminated = false;

	this->firstDay = firstDay;
	this->lastDay = lastDay;

    cout << "In salary" << endl;
}

Salary::~Salary()
{

}

// todo : check this calculation*** - should it be inclusive or exclusive? ie if soome1 hired then fired, what should it be
void Salary::calculatePayroll(int day, double lastDay)
{
    this->lastDay = lastDay;
    if (lastDay == -1)
    {
        this->firstDay = day;
        payAmount = payRate * (30 - day + 1) / 30;
    }

    else
    {
        payAmount = payRate * (lastDay - firstDay + 1) / 30;
    }
}

//SALARY  [id] [payRate] [payAmount] [terminated] [name]
string Salary::toString()
{
	string fields = "";
	fields += "salary " + to_string(id) + " " + to_string(payRate) + " " + to_string(payAmount) + " ";

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
