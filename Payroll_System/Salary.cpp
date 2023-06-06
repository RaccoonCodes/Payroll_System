#include "Salary.h"
#include <iostream>
#include <iomanip>

using namespace std;

Salary::Salary(const string& fName, const string& lname, const int& age, const int& in_id, double& wage)
	:Employee(fName, lname, age, in_id){
	setSalary(wage);
	printS();
}

void Salary::setSalary(const double& money) {
	totalEarn = money;
}

double Salary::getSalary() const{
	return totalEarn;
}

double Salary::earning() const {
	return getSalary();
}

void Salary::printS() {
	cout <<fixed << setprecision(2)<<"Weekly salary: $" << earning() <<endl;
}
