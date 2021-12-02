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

    // create the empty bst from masterfile
    EmployeeFile* bst = new EmployeeFile();

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
            for (int date = 1; date < 2; ++date)
            {
                // Find relevant file for today's date
                filename = "DailyTransaction/" + to_string(date) + "DailyTransaction.txt";

                // Open file
                fileIn.open(filename);

                // Read in date of file
                fileIn >> junk;

                // Read file line by line
                while (getline(fileIn, line))
                {
                    firstWord = line.substr(0, line.find(","));
                    line = line.substr(line.find(",") +1);

                    //cout << line << endl;

                    if (firstWord == "hire")
                    {
                        // call buildEmployee
                        e = EmployeeFactory::buildEmployee(line, date);

                        if (e->getType() == "salary")
                        {
                            e->calculatePayroll(date, -1);
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
                            e->calculatePayroll(date, date);
                        }
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
