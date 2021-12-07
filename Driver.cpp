#include <iostream>
#include <string>
#include <fstream>
#include <exception>

#include "Employee.h"
#include "Salary.h"
#include "Hourly.h"
#include "Piecework.h"
#include "EmployeeFactory.h"
#include "EmployeeFile.h"

using namespace std;

int main()
{
    // fields
    Employee* e;
    string userInput;
    ifstream fileIn;
	ofstream errorLog("errorlog.txt");
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
				lineNumber = 0;

                // Find relevant file for today's date
                filename = "DailyTransaction/" + to_string(date) + "DailyTransaction.txt";

                // Open file
			
                fileIn.open(filename);

                // Read in date of file
				// TODO : fix this
                fileIn >> junk;

                // Read file line by line
                while (getline(fileIn, line))
                {
					lineNumber++;
                    firstWord = line.substr(0, line.find(","));
                    line = line.substr(line.find(",") +1);

                    //cout << line << endl;

                    if (firstWord == "hire")
                    {

						try 
						{ 
							e = EmployeeFactory::buildEmployeeFromDaily(line, date);
						}
						catch (int& e)
						{
							errorLog << "Invalid input on line " << lineNumber << " In File " << filename << endl;
							continue;
						}

						catch (exception& e)
						{
							errorLog << "General exception on line " << lineNumber << " In File " << filename << endl;
							continue;
						}

						try
						{
							bst->insert(e);
						}
						catch (int& e)
						{
							errorLog << "duplicate employee on line " << lineNumber << " In File " << filename << endl;
						}
                        
                        
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
                        e->setTerminated(1);

                        if (e->getType() == "salary")
                        {
                            e->calculatePayroll(date, date);
                        }
                    }
                }

				// Close file
				fileIn.close();
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

