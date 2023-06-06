#include <iostream>
#include "Commission.h"
#include <iomanip>

using namespace std;

Commission::Commission(const string& first, const string last,const int& age,const int& id, double rate, double sales)
	:Employee(first,last,age,id){
	setRate(rate);
	setSales(sales);
	printC();

}

void Commission::setRate(double r) {
	commissionRate = r;
}

void Commission::setSales(double s) {
	grossSales = s;
}

double Commission::getRate()const {
	return commissionRate;
}

double Commission::getSales()const {
	return grossSales;
}

double Commission::earning() const {
	return getRate() * getSales();
}

void Commission::printC() {
	cout << fixed << setprecision(2) << "Gross Sales: " << getSales() << endl;
	cout << fixed << setprecision(2) << "Commission Rate: " << getRate() << endl;
	cout << fixed << setprecision(2) << "Overall Earnings: " << earning() << endl;
}