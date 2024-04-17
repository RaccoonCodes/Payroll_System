# Payroll System

## Overview
This Payroll System project is designed to manage employee payroll information, including weekly salaries, commissions, and commissions with base pay. The system allows users to input employee data and calculate earnings based on different compensation structures. This is all in C++.

# Table of Contents

1. [Overview](#overview)
2. [Features](#features)
3. [Use](#use)
4. [Main.cpp](#maincpp)
5. [Employee.h and Employee.cpp](#employeeh-and-employeecpp)
6. [Salary.cpp and Salary.h](#salarycpp-and-salaryh)
7. [Commission.cpp and Commission.h](#commissioncpp-and-commissionh)
8. [BaseCommission.cpp and BaseCommission.h](#basecommissioncpp-and-basecommissionh)
9. [Summary](#summary)


## Features

- Input Weekly Salary: Enter employee details and their weekly salary.
- Input Commission: Enter employee details, commission rate, and gross sales to calculate earnings.
- Input Commission + Base pay: Enter employee details, commission rate, gross sales, and base salary to calculate total earnings.

## Use
1. Clone the repository to your local machine.
2. Compile in Visual Studio or use your own C++ compiler.
3. Run the compiled executable file.
4. Follow the on-screen prompts to input employee data and calculate earnings.

## Main.cpp
This file contains the main function, which serves as the entry point for the application.
```cpp
void decision(const int& value);
void valueCheck(string& init, bool& check);
bool isnumber(const string& value);

int main() {
    string name = " ";
    string last = " ";
    string input = "";

    int age = 0;
    int id = 0;
    int input_num = 0;

    double income = 0;
    double rates = 0;
    double sales_in = 0;
    double basePay = 0;


    bool flag = true;

    cout << "Welcome to Payroll System" << endl;
    cout << "\nWhat would you like to do? (Enter a number between 1 and 3): "<< endl;
    cout << "1. Input Weekly Salary\n2. Input Commission\n3. Input Commission + Base pay" << endl;
    cout << "Input: ";
    getline(cin, input);

    flag = isnumber(input);

    while (flag == false || stoi(input) < 1 || stoi(input) > 3) {
        valueCheck(input, flag);
        flag = isnumber(input);
    }

    input_num = stoi(input);
    decision(input_num);

    

}
```
- Predefined functions "decision", "valueCheck", and "isnumber".
- Implements the main function, which:
   - Declares variables for employee information (name, last, age, id, input_num).
   - Displays a welcome message and prompts the user to choose between three options: input weekly salary, input commission, or input commission with base pay.
   - Validates user input and calls the decision function to handle the selected option.
     
 
  ```cpp
  void decision(const int& value) {
  /*rest of the code in Main.cpp*/
  while (checkIn == true) {
    cout << "\nPlease Enter first Name of the employee: ";
    cin >> first_name;
    cout << "\nPlease Enter " << first_name << "'s last name: ";
    cin >> last_name;
    cout << "\nEnter " << first_name << "'s age: ";
    cin >> age_value;
    cout << "\nEnter " << first_name << "'s ID Number: ";
    cin >> id_value;

    if (value == 1) {
        cout << "\nWhat is " << first_name << "'s weekly pay? ";
        cin >> wage;
        cout << "\nInformation Recieved: " << endl;

        Salary employee{ first_name,last_name,age_value,id_value,wage };
        my_file << "\nName: " << employee.getName() << " " << employee.getLastName()
            << "\nAge: " << employee.getAge() << "\nID: " << employee.getId()
            << "\nWeekly Salary: $" << employee.earning() << "\n ";

    }
  
   /*rest of the code in Main.cpp*/
   cout << "\nWhat is the base salary? "
                  cin >> salaryBase;
                cout << "\nInformation Recieved: " << endl;
                BaseCommission employee{ first_name,last_name,age_value,id_value,rate,sales, salaryBase };
                my_file << "Name: " << employee.getName() << " " << employee.getLastName()
  << "\nAge: " << employee.getAge() << "\nID: " << employee.getId()
  << "\nCommission Rate: " << employee.getRate()
  << "\nCommission Sales: " << employee.getSales()
  << "\nSalary Base: $" << employee.getBase()
  << "\nTotal Earnings: $" << employee.earning() << "\n ";
  /*rest of the code in Main.cpp*/

  
- In this method, it will take in information such as name, age, etc and depending on what the user has selected, it will follow the type of pay system to evaluate and return a proper formated paystub of an employee paycheck.

## Employee.h and Employee.cpp
These files define the Employee class, which represents basic attributes of an employee.

#### Employee.h
```cpp
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
```
- Defines the Employee class with private member variables (name, lastName, age, id) and public member functions to set and get these variables.
- Declares a virtual earning function, which is overridden in derived classes.
- Provides a printE function to display employee information.

#### Employee.cpp
```cpp
#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

Employee::Employee(const string& inName, const string& inLast, const int& inAge, const int& id) {
	setName(inName);
	setLastName(inLast);
	setAge(inAge);
	setId(id);
	printE();
}

void Employee::setName(const string& n) {
	name = n;
}
void Employee::setLastName(const string& ln) {
	lastName = ln;
}
void Employee::setAge(const int& a) {
	age = a;
}
void Employee::setId(const int& i) {
	id = i;
}

string Employee::getName() {
	return name;
}
string Employee::getLastName() {
	return lastName;
}
int Employee::getAge() {
	return age;
}
int Employee::getId() {
	return id;
}
void Employee::printE() {

	cout << "First name: " << getName() << endl;
	cout << "Last name: " << getLastName() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "id: " << getId() << endl;
}
```
- Implements the member functions declared in Employee.h.
- Defines constructor to initialize employee attributes and printE function to display employee information.

## Salary.cpp and Salary.h
These files define the Salary class, which represents an employee's earnings based on weekly salary. 

### Salary.h
```cpp
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
```
- Defines the Salary class, which inherits from Employee.
- Includes a private member variable totalEarn representing the weekly salary.
- Provides member functions to set and get the salary and override the earning function.
- Declares a printS function to display salary information.
- 
### Salary.cpp
```cpp
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
```
- Implements the member functions declared in Salary.h.
- Defines constructor to initialize salary attribute and printS function to display salary information.

## Commission.cpp and Commission.h
These files define the Commission class, which represents an employee's earnings based on commission. 

### Commission.h
```cpp
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
```
- Defines the Commission class, which inherits from Employee.
- Includes private member variables grossSales and commissionRate representing the gross sales and commission rate.
- Provides member functions to set and get these variables and override the earning function.
- Declares a printC function to display commission information.

### Commission.cpp

```cpp
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
```
- Implements the member functions declared in Commission.h.
- Defines constructor to initialize commission attributes and printC function to display commission information.

## BaseCommission.cpp and BaseCommission.h
These files define the BaseCommission class, which represents an employee's earnings based on commission with base pay.

### BaseCommission.h
```cpp
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


```
- Defines the BaseCommission class, which inherits from Commission.
- Includes a private member variable baseWCommission representing the base salary.
- Provides member functions to set and get the base salary and override the earning function.
- Declares a printBC function to display base commission information.

### BaseCommission.cpp
```cpp
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
```
- Implements the member functions declared in BaseCommission.h.
- Defines constructor to initialize base commission attributes and printBC function to display base commission information.

## Summary
Overall, the project consists of classes representing different compensation structures for employees. Each class handles specific calculations and provides functions to display employee earnings based on the chosen compensation model. The "main" function serves as the entry point, allowing users to interactively input employee data and choose the compensation option.

