#include "Piecework.h"
#include <string>

// todo : delete these
#include <iostream>
using namespace std;

//type, id, payRate, name
Piecework::Piecework(string employeeType, int id, double payRate, string name)
{
	this->employeeType = employeeType;
	this->id = id;
	this->payRate = payRate;
	this->name = name;

	this->payAmount = 0;
	this->terminated = false;

    cout << "In piecework" << endl;
}

Piecework::~Piecework()
{

}

void Piecework::calculatePayroll(int day, double pieces)
{
	payAmount += pieces * payRate;
}

//PIECES  [id] [payRate] [payAmount] [terminated] [name]
string Piecework::toString()
{
	string fields = "";
	fields += "SALES " + to_string(id) + " " + to_string(payRate) + " " + to_string(payAmount) + " ";

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
