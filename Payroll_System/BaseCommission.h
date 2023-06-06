#ifndef BASECOMMISSION_H
#define BASECOMMISSION_H
#include "Commission.h"

using namespace std;

class BaseCommission :public Commission {
private:
	double baseWCommission = 0;

public:
	BaseCommission(const string& first, const string& last, const int& age, const int& id, const double& rate, const double& sales, const double& salaryBase);
	virtual ~BaseCommission() = default;

	void setBase(const double& sal);
	void printBC();
	double getBase()const;

	virtual double earning() const override;

};

#endif // !BASECOMMISSION_H

