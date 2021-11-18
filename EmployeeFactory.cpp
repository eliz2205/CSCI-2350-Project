#include <string>
​
using namespace std;
​
Employee* buildEmployee(string str)
{
​
	string rem = str.substring(str.find(" "));
	int id = 0; 
	// first space to second space = id
	rem >> id;
​
	rem = rem.substring(rem.find(" "));
	int payAmount = 0;
	// second space to the third space = payAmount
	rem >> payAmount;
​
	rem = rem.substring(rem.find(" "));
	string name = rem;
	
	if(str.find("salary") != string::npos)
	{
		return new Salary(id, payAmount, name);
	}
	else if(str.find("hourly") != string::npos)
	{
		return new Hourly(id, payAmount, name);
	}
	else if(str.find("piecework") != string::npos)
	{
		return new Piecework(id, payAmount, name);
	}
	else if(str.find("commission") != string::npos)
	{
		return new Commision(id, payAmount, name);
	}
	
	throw invalid_argument;
}
