#include <iostream>
#include <string>

#include "Employee.h"
#include "Salary.h"
#include "Hourly.h"
#include "Commission.h"
#include "Piecework.h"
#include <fstream>

using namespace std;

int main()
{
	string filename;
    string nextline;
    int day;

	//read line by line
	//look for keywords: hire, terminate, hourly, commission, pieces, sales
	fstream infile = new fstream();
    cin>>filename;

    infile.open (filename);
    while(infile.is_open)
    {
        infile.getline(infile, nextline); //stores first line into nextline

    if(nextline.find("hire") != string::npos) //if line begins with hire, add new employee object
    {
        //add employee to the BST

    }

    else if(nextline.find("termination") != string::npos) //if line begins with terminate, remove employee
    {
        //get the employee id
        //remove that id from the BST
    }

    else if(nextline.find("hours") != string::npos)
    {

    }

    else if(nextline.find("pieces") != string::npos)
    {


    }

    else if(nextline.find("sales") != string::npos)
    {


    }

    }



    infile.close();

	//type, id, payRate, name
	Employee* e1 = new Salary("SALARY", 1, 5000, "Ryan Lueder", 0, -1);
	e1->calculatePayroll(15, 15);
	cout << e1->toString() << endl;


}


