#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<string>

using namespace std;

class Employee {
private:
	string name;
	string lastName;
	int age;
	int id;

public:
	Employee(const string& inName,const string& inLast, const int& inAge,const int& id);
	virtual ~Employee() = default;

	void setName(const string&);
	void setLastName(const string&);
	void setAge(const int&);
	void setId(const int&);

	string getName();
	string getLastName();
	int getAge();
	int getId();

	void printE();
	virtual double earning() const = 0;

};
#endif // !EMPLOYEE_H

