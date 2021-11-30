#include "EmployeeFile.h"
#include "EmployeeFactory.h"

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

	while (!eof())
	{
		std::getline(*this, employeeData);
		Employee* item = EmployeeFactory::buildEmployee(employeeData);
		insert(item);
	}
}
