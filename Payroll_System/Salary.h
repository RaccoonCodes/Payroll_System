
#ifndef SALARY_H
#define SALARY_H

#include"Employee.h"
#include<string>

using namespace std;

class Salary :public Employee {
private:
	double totalEarn = 0.0;


public:
	Salary(const string& fName, const string& lname, const int& age, const int& in_id,double& wage);
	virtual ~Salary() = default;

	void setSalary(const double& money);
	double getSalary()const;
	void printS();

	virtual double earning() const override;
};




#endif // !SALARY_H

