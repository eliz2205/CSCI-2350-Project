

#ifndef EMPLOYEEFACTORY_H
#define EMPLOYEEFACTORY_H

#include "Employee.h"
#include <string>

class EmployeeFactory
{
private:

	// Helper methods
	static int parseInt(string, string);
	static double parseDouble(string,string);
	static string parseString(string,string);
	static string advance(string,string);
	static Employee* constructEmployee(int,string,string,double,double,bool,int,int);

public:
    // line: ID, type, payRate, name
    static Employee* buildEmployeeFromDaily(string, int);

    static Employee* buildEmployeeFromMaster(string);

};

#endif
