#include <iostream>
#include <string>
#include <fstream>

#include "Employee.h"
#include "Salary.h"
#include "Hourly.h"
#include "Piecework.h"
#include "EmployeeFactory.h"


using namespace std;

int main()
{
    /*
	//type, id, payRate, name
	Employee* e1 = new Salary("SALARY", 1, 5000, "Ryan Lueder", 0, -1);
	e1->calculatePayroll(15, 15);
	cout << e1->toString() << endl;
    */

    // DATA
    string userInput;
    ifstream fileIn;
    string filename;
    string line;
    string firstWord;
    int date = 0; // todo : should date be a pointer?
    
    
    do 
    {
        // print options to terminal
        cout << "Option 1: Generate Payroll" << endl << "Option 2: Read in Daily Transaction File" << endl << "Input 1 or 2. To end, type e." << endl;
        
        cin >> userInput;

        if (userInput == "1")
        {
            
        }

        else if (userInput == "2")
        {
            // Increment date
            date++;
            
            // Find relevant file for today's date
            filename = "DailyTransaction/" + to_string(date) + "DailyTransaction.txt";

            // Open file
            fileIn.open(filename);

            // Read in date of file
            // todo : this is redundant, how will we know which file to open? / how does he want us to format the terminal?
            fileIn >> date;

            // Read file line by line
            while (getline(fileIn, line))
            {
                firstWord = line.substr(0, line.find(","));

                //cout << line << endl;

                if (firstWord == "hire")
                {
                    // call buildEmployee
                    Employee* e = EmployeeFactory::buildEmployee(line.substr(line.find(",") + 1), date);

                    
                    // put employee into binary search tree
                    
                    
                }
                else if (firstWord == "hours")
                {
                    // 
                }

                else if (firstWord == "pieces")
                {}

                else if (firstWord == "sales")
                {}

                else if (firstWord == "terminated")
                {
                    // locate the employee in the BST and set terminated = 1
                }

                else
                {
                    continue; 
                }
            }
        }

        else if (userInput != "e")
        {
            cout << "Invalid Input. Please try again." << endl;
        }

    } while (userInput != "e");


    return 0;


}
