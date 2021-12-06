#include <iostream>
#include <string>
#include <fstream>

#include "Employee.h"
#include "Salary.h"
#include "Hourly.h"
#include "Piecework.h"
#include "EmployeeFactory.h"
#include "EmployeeFile.h"

// todo : make sure you can't hire duplicates?
// todo : employeefile can't have extra line at end or else a runtime error occurs - fix this in employeefile.cpp
// todo check for memory leaks or dangling pointers 

using namespace std;

int main()
{
    // fields
    Employee* e;
    string userInput;
    ifstream fileIn;
    string filename;
    string line;
    string firstWord;
    int junk;
    int id;
    double quantity;
	int lineNumber = 0;

    // create the empty bst from masterfile
    EmployeeFile* bst = new EmployeeFile();

	// TODO : change do while?

    do 
    {
        // print options to terminal
        cout << "Option 1: Generate Payroll" << endl << "Option 2: Read in Daily Transaction File" << endl << "Input 1 or 2. To end, type e." << endl;
        
        cin >> userInput;

        if (userInput == "1")
        {
            // write to masterfile
            bst->write();
        }

        else if (userInput == "2")
        {
            //todo: change range
            for (int date = 1; date < 2; ++date)
            {
				lineNumber++; 

                // Find relevant file for today's date
                filename = "DailyTransaction/" + to_string(date) + ".txt";

                // Open file
                fileIn.open(filename);

                // Read in date of file
				// TODO : fix this
                fileIn >> junk;

                // Read file line by line
                while (getline(fileIn, line))
                {
                    firstWord = line.substr(0, line.find(","));
                    line = line.substr(line.find(",") +1);

                    //cout << line << endl;

                    if (firstWord == "hire")
                    {

						try 
						{ 
							e = EmployeeFactory::buildEmployee(line, date);
						}
						catch (int e)
						{
							// WRITE TO ERROR LOG W/ LINE NUMBER -> Can also check int e for type of error
							// TODO : add general exception?
							continue;
						}
                        
                        // put employee into binary search tree
                        bst->insert(e);
                        
                    }
                    else if (firstWord == "hours" || firstWord == "commission" || firstWord == "pieces")
                    {
                        // extract relevant info
                        id = stoi(line.substr(0, line.find(",")));
                        quantity = stod(line.substr(line.find(",") + 1));

                        e = bst->getEmployee(id);

                        // add hours
                        e->calculatePayroll(date, quantity);
                    }

                    else if (firstWord == "termination")
                    {
                        id = stoi(line.substr(line.find(",") + 1));
                        e = bst->getEmployee(id);
                        cout << "fired: " << id << endl;
                        e->setTerminated(1);

                        if (e->getType() == "salary")
                        {
                            e->calculatePayroll(date, date); // todo : redundant
                        }
                    }

                    else
                    {
                        // make an error log
                    }
                }
            }
        }

        else if (userInput != "e")
        {
            cout << "Invalid Input. Please try again." << endl;
        }

    } while (userInput != "e");

    delete bst;

    return 0;
}


/**
 * Returns true if valid input for building employee.
 * False otherwise.
**/
/*
bool isValidInput(string line)
{

	bool isValid = true;
    // get id
    id = stoi(str.substr(0, str.find(",")));
    remainder = str.substr(str.find(",") + 1);

	// get name
	name = remainder.substr(0, remainder.find(","));
    remainder = remainder.substr(remainder.find(",") + 1);
 
    // get empType
    empType = remainder.substr(0, remainder.find(","));
    remainder = remainder.substr(remainder.find(",") + 1);
    
    // get payrate
    payRate = stod(remainder);

	//write to error log
	if(empType == "salary")
	{
		if(!(payRate >= 4000))
		{
			isValid = false;
			//write to errorlog
		}
	}
	else if(empType == "hourly")
	{
		return (payRate >= 10 && payRate <= 26);
	}
	else if(empType == "piecework")
	{
		return (payRate >= 0 && payRate <= 1);
	}
	else if(empType == "commission")
	{
		return (payRate >= .03 && payRate <= .05);
	}

	return false;

}
*/
