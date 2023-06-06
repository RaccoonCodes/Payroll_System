#ifndef COMMISSION_H
#define COMMISSION_H
#include "Employee.h"

using namespace std;

class Commission : public Employee {
private:
	double grossSales = 0;
	double commissionRate = 0;

public:
	Commission(const string& first, const string last, const int& age, const int& id, double rate, double sales);
	virtual ~Commission() = default;

	void setRate(double r);
	void setSales(double s);
	void printC();

	double getRate()const;
	double getSales()const;

	virtual double earning() const override;


};

#endif // !COMMISSION_H

