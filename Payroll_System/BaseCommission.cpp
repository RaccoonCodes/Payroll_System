#include <iostream>
#include <iomanip>
#include "BaseCommission.h"

using namespace std;

BaseCommission::BaseCommission(const string& first, const string& last, const int& age, const int& id, const double& rate, const double& sales, const double& salaryBase)
	:Commission(first, last, age, id, rate, sales) {
	setBase(salaryBase);
	printBC();
}

void BaseCommission::setBase(const double& sal) {
	baseWCommission = sal;
}

double BaseCommission::getBase()const {
	return baseWCommission;
}

double BaseCommission::earning() const {
	return baseWCommission + Commission::earning();
}

void BaseCommission::printBC() {
	cout << fixed << setprecision(2) << "\nBase pay: " << getBase() << endl;
	cout << fixed << setprecision(2) << "Total Earning (Base + Commission): " << earning() <<endl;
}