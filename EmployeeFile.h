#ifndef EMPLOYEEFILE_H
#define EMPLOYEEFILE_H

#include "Employee.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class EmployeeFile : public fstream
{
private:
	class EmployeeTree
	{
	public:
		Employee* data;
		EmployeeTree* left;
		EmployeeTree* right;
	public:
		EmployeeTree() : data(nullptr), left(nullptr), right(nullptr) { }
		~EmployeeTree()
		{
			delete data;
			delete left;
			delete right;
		}
		void insert(Employee* e)
		{
			if (data == nullptr)
			{
				data = e;
				left = new EmployeeTree;
				right = new EmployeeTree;
			}
			else if (e->getId() < data->getId())
			{
				left->insert(e);
			}
			else if (e->getId() > data->getId())
			{
				right->insert(e);
			}
			else
			{
				throw (-901);
			}
		}
		Employee* getEmployee(int id)
		{
			if (data == nullptr)
			{
				throw (-902);
			}
			else if (id < data->getId())
			{
				return left->getEmployee(id);
			}
			else if (id > data->getId())
			{
				return right->getEmployee(id);
			}
			else
			{
				return data;
			}
		}
		void preOrderWrite(fstream* f)
		{
			*f << data->toString() << endl;
			if (left != nullptr)
			{
				left->preOrderWrite(f);
			}
			if (right != nullptr)
			{
				right->preOrderWrite(f);
			}
		}
	};
	
	EmployeeTree* dataTree;

public:
	EmployeeFile();
	~EmployeeFile();
	void insert(Employee*);
	Employee* getEmployee(int);

private:
	void loadTree();
};
#endif
