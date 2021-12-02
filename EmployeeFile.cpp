#include "EmployeeFile.h"
#include "EmployeeFactory.h"
//delete
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

EmployeeFile::EmployeeFile() : dataTree(new EmployeeTree)
{
	open("EmployeeFile.txt", ios_base::in);
    
	if (!fail())
	{
		loadTree();
		close();
	}
}

EmployeeFile::~EmployeeFile()
{
	open("EmployeeFile.txt", ios_base::trunc);
	dataTree->preOrderWrite(this);
	close();
	delete dataTree;
}

void EmployeeFile::write()
{
    open("EmployeeFile.txt", ios::out);
    dataTree->preOrderWrite(this);
    close();
}

void EmployeeFile::insert(Employee* e)
{
	dataTree->insert(e);
}

Employee* EmployeeFile::getEmployee(int id)
{
	return dataTree->getEmployee(id);
}


void EmployeeFile::loadTree()
{
	string employeeData = "";

    if (peek() == EOF) insert(nullptr);

	while (peek() != EOF)
	{
		std::getline(*this, employeeData);
		Employee* item = EmployeeFactory::insertEmployee(employeeData);
		insert(item);
	}
}
